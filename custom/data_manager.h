/*
* Copyright 2024 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#ifndef DATA_MANAGER_H_
#define DATA_MANAGER_H_
#include "custom.h"
#ifdef __cplusplus
extern "C" {
#endif

    /* 添加歌曲到今日熏听歌单仓库*/
    void add_song_to_today(const char* n, const char* a, const char* c);
    /* 添加歌曲到最近熏听歌单仓库*/
    void add_song_to_recent(const char* n, const char* a, const char* c);
    /* 添加歌曲到我的听单歌单仓库*/
    void add_song_to_my(const char* n, const char* a, const char* c);
    /* 向今日熏听歌单添加歌曲*/
    void add_songs_to_today_listening(lv_ui* ui, int song_count);
    /* 向最近熏听歌单添加歌曲*/
    void add_songs_to_recent_listening(lv_ui* ui, int song_count);
    /* 向我的听单添加歌曲*/
    void add_songs_to_my_listening(lv_ui* ui, int song_count);
    /* 向本地听单添加歌曲*/
    void add_songs_to_local_listening(lv_ui* ui, int song_count);
    /* 清空所有歌单页面*/
    void clean_all_listening_page(lv_ui* ui);
    /* 添加本地音乐文件夹*/
    bool add_local_folder(const char* folder_name, int song_count, const char* folder_path);
    /* 添加本地音乐列表项*/
    void add_local_playlists_to_page(lv_ui* ui, const local_folder_repository_t* repo);
    /* 扫描本地音乐文件夹*/
    int scan_musicdir(void);
    /* 扫描歌单文件夹并加入歌库*/
    void scan_playlist_add(const char* playlist_path, const char* playlist_name);
    /* 初始化孩子信息库 */
    void init_child_info_repo(void);
    /* 添加孩子信息到库 */
    void add_child_to_repo(const current_child_info_t* child);
    /* 获取孩子信息库中的孩子 */
    current_child_info_t* get_child_from_repo(int index);
    /* 根据歌单标识和索引更新当前播放歌曲信息*/
    int update_current_song_by_index(lv_ui* ui, int songlist, int song_index);
    /* 初始化蓝牙设备容器*/
    void bluetooth_container_init(void);
    /* 销毁蓝牙设备容器*/
    void bluetooth_container_deinit(void);
    /* 向蓝牙设备容器添加设备*/
    bool bluetooth_container_add(const char* name, const char* type);
    /* 从蓝牙设备容器移除设备*/
    bool bluetooth_container_remove(const char* name);
    /* 获取最新连接的蓝牙设备*/
    bluetooth_device_t* bluetooth_container_get_latest(void);
    /* 获取蓝牙设备*/
    bluetooth_device_t* bluetooth_container_get(const char* name);
    /* 更新蓝牙设备显示名称*/
    void bluetooth_container_update_display_name(void);

#ifdef __cplusplus
}
#endif
#endif /* DATA_MANAGER_H_ */
