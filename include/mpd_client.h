#ifndef __MPD_CLIENT_H_
#define __MPD_CLIENT_H_

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

#define MPD_DEFAULT_HOST "127.0.0.1"
#define MPD_DEFAULT_PORT 6600

typedef enum {
    MPD_CONN_DISCONNECTED = 0,
    MPD_CONN_CONNECTED,
    MPD_CONN_ERROR
} mpd_conn_state_t;

bool mpd_client_init(void);
bool mpd_client_connect(const char* host, int port);
void mpd_client_disconnect(void);
mpd_conn_state_t mpd_client_get_conn_state(void);
bool mpd_client_play(void);
bool mpd_client_play_index(int index);
bool mpd_client_pause(void);
bool mpd_client_stop(void);
bool mpd_client_next(void);
bool mpd_client_previous(void);
bool mpd_client_clear_playlist(void);
bool mpd_client_add_song(const char* song_path);
bool mpd_client_add_all_songs(void);

// 心跳连接
bool mpd_client_ping(void);

// 文件夹（歌单）管理函数
bool mpd_client_list_folders(char*** folders, int* count);
bool mpd_client_load_folder_playlist(const char* folder_name);
bool mpd_client_switch_folder_playlist(const char* folder_name);
bool mpd_client_get_folder_songs(const char* folder_name, char*** songs, int* count);

void mpd_client_deinit(void);

#ifdef __cplusplus
}
#endif

#endif /* __MPD_CLIENT_H_ */