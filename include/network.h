#ifndef NETWORK_H
#define NETWORK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <json.h>

#include "log.h"


// 用于接收curl返回数据的结构体
typedef struct MemoryStruct {
    char *memory;
    size_t size;
} MemoryStruct;

// 发送HTTP请求的通用函数
char* http_request(const char* url, const char* method, const struct curl_slist* headers, const char* post_data);

// 登录相关函数
int listener_login(const char* base_url, char* token, char* refresh_token, char* chdId);

// Token刷新函数
int refresh_token(const char* base_url, const char* refreshToken, char* newToken, char* newRefreshToken);

// 用户信息查询函数
int get_user_info(const char* base_url, const char* token, const char* chdId, char* mobile, int* vip, char* vipEnd);

// 孩子列表查询函数
typedef struct ChildInfo {
    char chdId[64];
    char nickName[128];
    char avatarUrl[512];
    int gender;
} ChildInfo;

int get_children_list(const char* base_url, const char* token, ChildInfo** children, int* count);

// 熏听相关函数
typedef struct ListenerItem {
    char id[64];
    char name[256];
    char rssType[32];
    char img[512];
    char subtitleUrl[512];
    char duration[32];
} ListenerItem;

int get_recommended_list(const char* base_url, const char* token, const char* chdId, ListenerItem** items, int* count);
int get_history_list(const char* base_url, const char* token, const char* chdId, ListenerItem** items, int* count);
int get_playlist_list(const char* base_url, const char* token, const char* chdId, ListenerItem** items, int* count);

// 播放鉴权函数
int get_play_auth(const char* base_url, const char* token, const char* chdId, const char* id, const char* rssType, char* playUrl, long* size, char* duration);

// 工具函数
void free_listener_items(ListenerItem* items, int count);
void free_children(ChildInfo* children, int count);

// 测试函数
int test_network();

#endif
