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

static int mpd_recv_response(char* response, int max_len)
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
            int select_result = select(sockfd + 1, &read_fds, NULL, NULL, &tv);
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

    // 更新全局变量
    strncpy(mpd_host, host, sizeof(mpd_host) - 1);
    mpd_port = port;

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);

    pton_result = inet_pton(AF_INET, host, &serv_addr.sin_addr);
    if (pton_result <= 0) {
        #ifdef _WIN32
            struct hostent* he = gethostbyname(host);
            if (he == NULL) {
                CLOSE_SOCKET(sockfd);
                sockfd = INVALID_SOCKET_VALUE;
                conn_state = MPD_CONN_ERROR;
                return false;
            }
            memcpy(&serv_addr.sin_addr, he->h_addr_list[0], he->h_length);
        #else
            struct hostent* he = gethostbyname(host);
            if (he == NULL) {
                CLOSE_SOCKET(sockfd);
                sockfd = INVALID_SOCKET_VALUE;
                conn_state = MPD_CONN_ERROR;
                return false;
            }
            memcpy(&serv_addr.sin_addr, he->h_addr_list[0], he->h_length);
        #endif
    }

    // 尝试使用更简单的连接方式
    int connect_result = connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
    if (connect_result == SOCKET_ERROR_VALUE) {
        #ifdef _WIN32
            int error = WSAGetLastError();
            CLOSE_SOCKET(sockfd);
            sockfd = INVALID_SOCKET_VALUE;
            conn_state = MPD_CONN_ERROR;
            return false;
        #else
            CLOSE_SOCKET(sockfd);
            sockfd = INVALID_SOCKET_VALUE;
            conn_state = MPD_CONN_ERROR;
            return false;
        #endif
    }

    // 接收MPD服务器的欢迎信息
    char response[1024];
    int recv_len = recv(sockfd, response, sizeof(response) - 1, 0);
    if (recv_len <= 0) {
        CLOSE_SOCKET(sockfd);
        sockfd = INVALID_SOCKET_VALUE;
        conn_state = MPD_CONN_ERROR;
        return false;
    }
    response[recv_len] = '\0';

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

// 解析 lsinfo 响应，提取文件夹或歌曲
static bool parse_lsinfo_response(const char* response, char*** items, int* count, bool folders_only)
{
    if (!response || !items || !count) {
        return false;
    }

    *count = 0;
    *items = NULL;

    // 统计项目数量
    const char* ptr = response;
    while (ptr != NULL) {
        const char* file_ptr = strstr(ptr, "file:");
        const char* dir_ptr = strstr(ptr, "directory:");
        
        // 找到下一个file或directory
        if (file_ptr == NULL && dir_ptr == NULL) {
            break;
        }
        
        // 选择较近的一个
        if (file_ptr == NULL) {
            ptr = dir_ptr;
        } else if (dir_ptr == NULL) {
            ptr = file_ptr;
        } else {
            ptr = (file_ptr < dir_ptr) ? file_ptr : dir_ptr;
        }
        
        // 检查是否只需要文件夹
        if (folders_only && strstr(ptr, "file:") != NULL) {
            // 跳过这个文件，移动到下一行
            const char* end = strstr(ptr, "\n");
            if (end == NULL) {
                break;
            }
            ptr = end + 1;
            continue;
        }
        
        (*count)++;
        
        // 移动到下一行
        const char* end = strstr(ptr, "\n");
        if (end == NULL) {
            break;
        }
        ptr = end + 1;
    }

    if (*count == 0) {
        return true;
    }

    // 分配内存
    *items = (char**)malloc(sizeof(char*) * (*count));
    if (!*items) {
        return false;
    }

    // 提取项目
    int index = 0;
    ptr = response;
    while ((ptr = strstr(ptr, "file:")) != NULL || (ptr = strstr(ptr, "directory:")) != NULL) {
        if (folders_only && strstr(ptr, "file:") != NULL) {
            ptr += 5;
            continue;
        }

        // 跳过 "file:" 或 "directory:" 前缀
        if (strstr(ptr, "directory:") != NULL) {
            ptr += 10;
        } else {
            ptr += 5;
        }

        // 跳过空格
        while (*ptr == ' ') ptr++;

        // 找到行尾
        const char* end = strstr(ptr, "\n");
        if (!end) break;

        // 复制项目路径
        int len = end - ptr;
        (*items)[index] = (char*)malloc(len + 1);
        if (!(*items)[index]) {
            // 释放已分配的内存
            for (int i = 0; i < index; i++) {
                free((*items)[i]);
            }
            free(*items);
            *items = NULL;
            *count = 0;
            return false;
        }
        strncpy((*items)[index], ptr, len);
        (*items)[index][len] = '\0';

        index++;
        ptr = end;
    }

    return true;
}

// 列出所有文件夹（歌单）
bool mpd_client_list_folders(char*** folders, int* count)
{
    if (conn_state != MPD_CONN_CONNECTED) {
        return false;
    }

    // 发送lsinfo命令
    const char* cmd = "lsinfo \"/\"\n";
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

    // 接收响应
    char response[4096];
    memset(response, 0, sizeof(response));
    int total = 0;
    char buffer[256];

    while (total < sizeof(response) - 1) {
        #ifdef _WIN32
            int ret = recv(sockfd, buffer, sizeof(buffer) - 1, 0);
        #else
            int ret = read(sockfd, buffer, sizeof(buffer) - 1);
        #endif
        
        if (ret == SOCKET_ERROR_VALUE || ret == 0) {
            conn_state = (ret == 0) ? MPD_CONN_DISCONNECTED : MPD_CONN_ERROR;
            return false;
        }
        
        strncat(response, buffer, sizeof(response) - total - 1);
        total += ret;
        
        if (strstr(response, "OK\n") != NULL || strstr(response, "ACK") != NULL) {
            break;
        }
    }

    if (strstr(response, "ACK") != NULL) {
        return false;
    }

    // 解析响应
    *count = 0;
    *folders = NULL;

    // 统计文件夹数量
    const char* ptr = response;
    while ((ptr = strstr(ptr, "directory:")) != NULL) {
        (*count)++;
        ptr += strlen("directory:");
    }

    if (*count == 0) {
        return true;
    }

    // 分配内存
    *folders = (char**)malloc(sizeof(char*) * (*count));
    if (!*folders) {
        return false;
    }

    // 提取文件夹路径
    int index = 0;
    ptr = response;
    while ((ptr = strstr(ptr, "directory:")) != NULL) {
        ptr += strlen("directory:");
        // 跳过空格
        while (*ptr == ' ') ptr++;
        // 找到行尾
        const char* end = strstr(ptr, "\n");
        if (!end) break;
        // 复制文件夹路径
        int folder_len = end - ptr;
        (*folders)[index] = (char*)malloc(folder_len + 1);
        if (!(*folders)[index]) {
            for (int i = 0; i < index; i++) {
                free((*folders)[i]);
            }
            free(*folders);
            *folders = NULL;
            *count = 0;
            return false;
        }
        strncpy((*folders)[index], ptr, folder_len);
        (*folders)[index][folder_len] = '\0';
        index++;
        ptr = end;
    }

    return true;
}

// 加载文件夹作为播放列表
bool mpd_client_load_folder_playlist(const char* folder_name)
{
    if (conn_state != MPD_CONN_CONNECTED || !folder_name) {
        return false;
    }

    // 清空当前播放列表
    if (!mpd_client_clear_playlist()) {
        return false;
    }

    // 添加文件夹中的所有歌曲
    char cmd[256];
    snprintf(cmd, sizeof(cmd), "add \"%s\"\n", folder_name);
    
    if (!mpd_send_command(cmd)) {
        return false;
    }

    char response[1024];
    int len = mpd_recv_response(response, sizeof(response));
    return (len >= 0 && strstr(response, "ACK") == NULL);
}

// 切换到指定文件夹的播放列表并开始播放
bool mpd_client_switch_folder_playlist(const char* folder_name)
{
    if (conn_state != MPD_CONN_CONNECTED || !folder_name) {
        return false;
    }

    // 加载文件夹播放列表
    if (!mpd_client_load_folder_playlist(folder_name)) {
        return false;
    }

    // 开始播放
    return mpd_client_play();
}

// 获取文件夹中的所有歌曲
bool mpd_client_get_folder_songs(const char* folder_name, char*** songs, int* count)
{
    if (conn_state != MPD_CONN_CONNECTED || !folder_name) {
        return false;
    }

    // 发送lsinfo命令
    char cmd[256];
    snprintf(cmd, sizeof(cmd), "lsinfo \"%s\"\n", folder_name);
    int len = strlen(cmd);
    int sent = 0;
    int ret;

    // 确保命令发送成功
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

    // 接收响应
    char response[4096];
    memset(response, 0, sizeof(response));
    int total = 0;
    char buffer[256];
    int timeout = 0;
    const int max_timeout = 5; // 5秒超时

    // 接收响应，添加超时处理
    while (total < sizeof(response) - 1) {
        #ifdef _WIN32
            // 使用select来实现超时
            fd_set read_fds;
            struct timeval tv;
            FD_ZERO(&read_fds);
            FD_SET(sockfd, &read_fds);
            tv.tv_sec = 1;
            tv.tv_usec = 0;
            int select_result = select(sockfd + 1, &read_fds, NULL, NULL, &tv);
            if (select_result <= 0) {
                timeout++;
                if (timeout >= max_timeout) {
                    return false;
                }
                continue;
            }
            ret = recv(sockfd, buffer, sizeof(buffer) - 1, 0);
        #else
            ret = read(sockfd, buffer, sizeof(buffer) - 1);
        #endif
        
        if (ret == SOCKET_ERROR_VALUE || ret == 0) {
            conn_state = (ret == 0) ? MPD_CONN_DISCONNECTED : MPD_CONN_ERROR;
            return false;
        }
        
        strncat(response, buffer, sizeof(response) - total - 1);
        total += ret;
        
        if (strstr(response, "OK\n") != NULL || strstr(response, "ACK") != NULL) {
            break;
        }
    }

    if (strstr(response, "ACK") != NULL) {
        return false;
    }

    // 解析响应
    *count = 0;
    *songs = NULL;

    // 统计歌曲数量
    const char* ptr = response;
    while ((ptr = strstr(ptr, "file:")) != NULL) {
        (*count)++;
        ptr += strlen("file:");
    }

    if (*count == 0) {
        return true;
    }

    // 分配内存
    *songs = (char**)malloc(sizeof(char*) * (*count));
    if (!*songs) {
        return false;
    }

    // 提取歌曲路径
    int index = 0;
    ptr = response;
    while ((ptr = strstr(ptr, "file:")) != NULL) {
        ptr += strlen("file:");
        // 跳过空格
        while (*ptr == ' ') ptr++;
        // 找到行尾
        const char* end = strstr(ptr, "\n");
        if (!end) break;
        // 复制歌曲路径
        int song_len = end - ptr;
        (*songs)[index] = (char*)malloc(song_len + 1);
        if (!(*songs)[index]) {
            for (int i = 0; i < index; i++) {
                free((*songs)[i]);
            }
            free(*songs);
            *songs = NULL;
            *count = 0;
            return false;
        }
        strncpy((*songs)[index], ptr, song_len);
        (*songs)[index][song_len] = '\0';
        index++;
        ptr = end;
    }

    return true;
}