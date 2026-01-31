#ifndef NETWORK_H
#define NETWORK_H
#include "custom.h"
#ifdef __cplusplus
extern "C" {
#endif
    // 孩子列表查询函数
    typedef struct ChildInfo {
        char chdId[64];
        char nickName[128];
        char avatarUrl[512];
        int gender;
    } ChildInfo;

    // 用于接收curl返回数据的结构体
    typedef struct MemoryStruct {
        char* memory;
        size_t size;
    } MemoryStruct;

    // 熏听相关函数
    typedef struct ListenerItem {
        char id[64];
        char name[256];
        char rssType[32];
        char img[512];
        char subtitleUrl[512];
        char duration[32];
    } ListenerItem;

    extern char* base_url;
    extern char token[512];
    extern char refresh_token[512];
    extern char chdId[64];
    extern ChildInfo* childrens;
    extern int child_count;

    // 登录相关函数
    int listener_login(const char* base_url, char* token, char* refresh_token, char* chdId);

    // Token刷新函数
    int update_token(const char* base_url, const char* refreshToken, char* newToken, char* newRefreshToken);

    // 用户信息查询函数
    int get_user_info(const char* base_url, const char* token);

    // 孩子列表查询函数
    int get_children_list(const char* base_url, const char* token, ChildInfo** childrens, int* count);

    // 今日熏听查询函数
    int get_recommended_list(const char* base_url, const char* token, const char* chdId, ListenerItem** items, int* count);

    // 最近熏听查询函数
    int get_history_list(const char* base_url, const char* token, const char* chdId, ListenerItem** items, int* count);

    // 我的听单查询函数
    int get_playlist_list(const char* base_url, const char* token, const char* chdId, ListenerItem** items, int* count);

    // 播放鉴权函数
    int get_play_auth(const char* base_url, const char* token, const char* chdId, const char* id, const char* rssType, char* playUrl, long* size, char* duration);

    // 工具函数
    void free_listener_items(ListenerItem* items, int count);
    void free_children(ChildInfo* childrens, int count);

    // 开机登录流程
    int boot_login();

#ifdef __cplusplus
}
#endif
#endif /* NETWORK_H_ */
