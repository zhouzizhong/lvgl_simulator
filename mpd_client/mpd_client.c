#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mpd_client.h"

#ifdef _WIN32
    #include <winsock2.h>
    #include <ws2tcpip.h>
    #pragma comment(lib, "ws2_32.lib")
    typedef SOCKET socket_t;
    #define INVALID_SOCKET_VALUE INVALID_SOCKET
    #define CLOSE_SOCKET(s) closesocket(s)
    #define SOCKET_ERROR_VALUE SOCKET_ERROR
    #define GET_SOCKET_ERROR() WSAGetLastError()
#else
    #include <unistd.h>
    #include <sys/socket.h>
    #include <netinet/in.h>
    #include <arpa/inet.h>
    #include <netdb.h>
    #include <errno.h>
    typedef int socket_t;
    #define INVALID_SOCKET_VALUE -1
    #define CLOSE_SOCKET(s) close(s)
    #define SOCKET_ERROR_VALUE -1
    #define GET_SOCKET_ERROR() errno
#endif

static mpd_conn_state_t conn_state = MPD_CONN_DISCONNECTED;
static char mpd_host[64] = MPD_DEFAULT_HOST;
static int mpd_port = MPD_DEFAULT_PORT;
static socket_t sockfd = INVALID_SOCKET_VALUE;

static bool mpd_send_command(const char* cmd)
{
    int len = strlen(cmd);
    int sent = 0;
    int ret;

    while (sent < len) {
        #ifdef _WIN32
            ret = send(sockfd, cmd + sent, len - sent, 0);
        #else
            ret = write(sockfd, cmd + sent, len - sent);
        #endif
        if (ret == SOCKET_ERROR_VALUE) {
            conn_state = MPD_CONN_ERROR;
            return false;
        }
        sent += ret;
    }
    return true;
}

static bool mpd_recv_response(char* response, int max_len)
{
    memset(response, 0, max_len);
    int total = 0;
    char buffer[256];
    int timeout_count = 0;
    const int max_timeouts = 50;

    while (total < max_len - 1 && timeout_count < max_timeouts) {
        #ifdef _WIN32
            fd_set read_fds;
            struct timeval tv;
            FD_ZERO(&read_fds);
            FD_SET(sockfd, &read_fds);
            tv.tv_sec = 0;
            tv.tv_usec = 100000;
            int select_result = select(0, &read_fds, NULL, NULL, &tv);
            if (select_result <= 0) {
                timeout_count++;
                continue;
            }
            int ret = recv(sockfd, buffer, sizeof(buffer) - 1, 0);
        #else
            int ret = read(sockfd, buffer, sizeof(buffer) - 1);
        #endif
        
        if (ret == SOCKET_ERROR_VALUE || ret == 0) {
            conn_state = (ret == 0) ? MPD_CONN_DISCONNECTED : MPD_CONN_ERROR;
            return -1;
        }
        
        strncat(response, buffer, max_len - total - 1);
        total += ret;
        
        if (strstr(response, "OK\n") != NULL || strstr(response, "ACK") != NULL) {
            break;
        }
    }
    
    if (timeout_count >= max_timeouts) {
        return -1;
    }
    
    return total;
}

bool mpd_client_init(void)
{
    #ifdef _WIN32
        WSADATA wsaData;
        return WSAStartup(MAKEWORD(2, 2), &wsaData) == 0;
    #endif
    return true;
}

bool mpd_client_connect(const char* host, int port)
{
    struct sockaddr_in serv_addr;
    int pton_result;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == INVALID_SOCKET_VALUE) {
        conn_state = MPD_CONN_ERROR;
        return false;
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(mpd_port);

    pton_result = inet_pton(AF_INET, mpd_host, &serv_addr.sin_addr);
    if (pton_result <= 0) {
        #ifdef _WIN32
            struct hostent* he = gethostbyname(mpd_host);
            if (he == NULL) {
                CLOSE_SOCKET(sockfd);
                sockfd = INVALID_SOCKET_VALUE;
                conn_state = MPD_CONN_ERROR;
                return false;
            }
            memcpy(&serv_addr.sin_addr, he->h_addr_list[0], he->h_length);
        #else
            struct hostent* he = gethostbyname(mpd_host);
            if (he == NULL) {
                CLOSE_SOCKET(sockfd);
                sockfd = INVALID_SOCKET_VALUE;
                conn_state = MPD_CONN_ERROR;
                return false;
            }
            memcpy(&serv_addr.sin_addr, he->h_addr_list[0], he->h_length);
        #endif
    }

    if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == SOCKET_ERROR_VALUE) {
        #ifdef _WIN32
            int error = WSAGetLastError();
            if (error != WSAEWOULDBLOCK) {
                CLOSE_SOCKET(sockfd);
                sockfd = INVALID_SOCKET_VALUE;
                conn_state = MPD_CONN_ERROR;
                return false;
            }
        #else
            if (errno != EINPROGRESS) {
                CLOSE_SOCKET(sockfd);
                sockfd = INVALID_SOCKET_VALUE;
                conn_state = MPD_CONN_ERROR;
                return false;
            }
        #endif
    }

    #ifdef _WIN32
        fd_set write_fds;
        struct timeval tv;
        FD_ZERO(&write_fds);
        FD_SET(sockfd, &write_fds);
        tv.tv_sec = 5;
        tv.tv_usec = 0;
        select(0, NULL, &write_fds, NULL, &tv);
    #else
        fd_set write_fds;
        struct timeval tv;
        FD_ZERO(&write_fds);
        FD_SET(sockfd, &write_fds);
        tv.tv_sec = 5;
        tv.tv_usec = 0;
        select(sockfd + 1, NULL, &write_fds, NULL, &tv);
    #endif

    char response[1024];
    if (mpd_recv_response(response, sizeof(response)) < 0) {
        CLOSE_SOCKET(sockfd);
        sockfd = INVALID_SOCKET_VALUE;
        conn_state = MPD_CONN_ERROR;
        return false;
    }

    conn_state = MPD_CONN_CONNECTED;
    return true;
}

void mpd_client_disconnect(void)
{
    if (sockfd != INVALID_SOCKET_VALUE) {
        CLOSE_SOCKET(sockfd);
        sockfd = INVALID_SOCKET_VALUE;
    }
    conn_state = MPD_CONN_DISCONNECTED;
}

mpd_conn_state_t mpd_client_get_conn_state(void)
{
    return conn_state;
}

bool mpd_client_play(void)
{
    if (conn_state != MPD_CONN_CONNECTED) {
        return false;
    }

    if (!mpd_send_command("play\n")) {
        return false;
    }

    char response[1024];
    int len = mpd_recv_response(response, sizeof(response));
    return (len >= 0 && strstr(response, "ACK") == NULL);
}

bool mpd_client_pause(void)
{
    if (conn_state != MPD_CONN_CONNECTED) {
        return false;
    }

    if (!mpd_send_command("pause 1\n")) {
        return false;
    }

    char response[1024];
    int len = mpd_recv_response(response, sizeof(response));
    return (len >= 0 && strstr(response, "ACK") == NULL);
}

bool mpd_client_stop(void)
{
    if (conn_state != MPD_CONN_CONNECTED) {
        return false;
    }

    if (!mpd_send_command("stop\n")) {
        return false;
    }

    char response[1024];
    int len = mpd_recv_response(response, sizeof(response));
    return (len >= 0 && strstr(response, "ACK") == NULL);
}

bool mpd_client_next(void)
{
    if (conn_state != MPD_CONN_CONNECTED) {
        return false;
    }

    if (!mpd_send_command("next\n")) {
        return false;
    }

    char response[1024];
    int len = mpd_recv_response(response, sizeof(response));
    return (len >= 0 && strstr(response, "ACK") == NULL);
}

bool mpd_client_previous(void)
{
    if (conn_state != MPD_CONN_CONNECTED) {
        return false;
    }

    if (!mpd_send_command("previous\n")) {
        return false;
    }

    char response[1024];
    int len = mpd_recv_response(response, sizeof(response));
    return (len >= 0 && strstr(response, "ACK") == NULL);
}

bool mpd_client_play_index(int index)
{
    if (conn_state != MPD_CONN_CONNECTED) {
        return false;
    }

    char cmd[64];
    snprintf(cmd, sizeof(cmd), "play %d\n", index);
    
    if (!mpd_send_command(cmd)) {
        return false;
    }

    char response[1024];
    int len = mpd_recv_response(response, sizeof(response));
    return (len >= 0 && strstr(response, "ACK") == NULL);
}

bool mpd_client_clear_playlist(void)
{
    if (conn_state != MPD_CONN_CONNECTED) {
        return false;
    }

    if (!mpd_send_command("clear\n")) {
        return false;
    }

    char response[1024];
    int len = mpd_recv_response(response, sizeof(response));
    return (len >= 0 && strstr(response, "ACK") == NULL);
}

bool mpd_client_add_song(const char* song_path)
{
    if (conn_state != MPD_CONN_CONNECTED) {
        return false;
    }

    char cmd[256];
    snprintf(cmd, sizeof(cmd), "add %s\n", song_path);
    
    if (!mpd_send_command(cmd)) {
        return false;
    }

    char response[1024];
    int len = mpd_recv_response(response, sizeof(response));
    return (len >= 0 && strstr(response, "ACK") == NULL);
}

bool mpd_client_add_all_songs(void)
{
    if (conn_state != MPD_CONN_CONNECTED) {
        return false;
    }

    if (!mpd_send_command("add /\n")) {
        return false;
    }

    char response[1024];
    int len = mpd_recv_response(response, sizeof(response));
    return (len >= 0 && strstr(response, "ACK") == NULL);
}

void mpd_client_deinit(void)
{
    mpd_client_disconnect();
    #ifdef _WIN32
        WSACleanup();
    #endif
}