#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include "json_object.h"
#include "json_tokener.h"
#include "network.h"
#include "custom.h"
#include "log.h"

char* base_url = "http://apitest.ukids.cn";
char token[512] = { 0 };
char refresh_token[512] = { 0 };
char chdId[64] = { 0 };
ChildInfo* childrens = NULL;
int child_count = 0;
static size_t WriteMemoryCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    size_t realsize = size * nmemb;
    MemoryStruct *mem = (MemoryStruct *)userp;

    char *ptr = realloc(mem->memory, mem->size + realsize + 1);
    if (!ptr) {
        LOG_ERROR("realloc() failed");
        return 0;
    }
    mem->memory = ptr;
    memcpy(&(mem->memory[mem->size]), contents, realsize);
    mem->size += realsize;
    mem->memory[mem->size] = 0;
    return realsize;
}

static char* http_request(const char* url, const char* method, const struct curl_slist* headers, const char* post_data) {
    CURL *curl = curl_easy_init();
    if (!curl) return NULL;

    MemoryStruct chunk = {0};
    chunk.memory = malloc(1);
    chunk.size = 0;

    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, method);
    if (headers) curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    if (post_data) {
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, post_data);
    }
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&chunk);
    curl_easy_setopt(curl, CURLOPT_USERAGENT, "listener-example/1.0");
    // 禁用 SSL 验证（仅用于测试环境）
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);

    CURLcode res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
        LOG_ERROR("curl_easy_perform() failed: %s", curl_easy_strerror(res));
        free(chunk.memory);
        chunk.memory = NULL;
    }

    curl_easy_cleanup(curl);
    return chunk.memory;  // 调用方需要 free
}

static int parse_listener_items(const char* response, ListenerItem** items, int* count) {
    json_object* root = json_tokener_parse(response);
    if (!root) {
        LOG_ERROR("Failed to parse response");
        return -1;
    }

    int result = -1;
    if (json_object_get_boolean(json_object_object_get(root, "success"))) {
        json_object* data = json_object_object_get(root, "data");
        if (data && json_object_get_type(data) == json_type_array) {
            int item_count = json_object_array_length(data);
            *items = (ListenerItem*)malloc(sizeof(ListenerItem) * item_count);
            if (!*items) {
                LOG_ERROR("Memory allocation failed");
                json_object_put(root);
                return -1;
            }

            for (int i = 0; i < item_count; i++) {
                json_object* item = json_object_array_get_idx(data, i);
                const char* id = json_object_get_string(json_object_object_get(item, "id"));
                const char* name = json_object_get_string(json_object_object_get(item, "name"));
                const char* rssType = json_object_get_string(json_object_object_get(item, "rssType"));
                const char* img = json_object_get_string(json_object_object_get(item, "img"));
                const char* subtitleUrl = json_object_get_string(json_object_object_get(item, "subtitleUrl"));
                const char* duration = json_object_get_string(json_object_object_get(item, "duration"));

                if (id) snprintf((*items)[i].id, sizeof((*items)[i].id), "%s", id);
                if (name) strcpy((*items)[i].name, name);
                if (rssType) strcpy((*items)[i].rssType, rssType);
                if (img) strcpy((*items)[i].img, img);
                if (subtitleUrl) strcpy((*items)[i].subtitleUrl, subtitleUrl);
                if (duration) strcpy((*items)[i].duration, duration);
            }

            *count = item_count;
            result = 0;
        }
    }

    json_object_put(root);
    return result;
}

int listener_login(const char* base_url, char* token, char* refresh_token, char* chdId) {
    char url[256];
    snprintf(url, sizeof(url), "%s/ucapp/listener/login/code", base_url);

    struct curl_slist *headers = NULL;
    headers = curl_slist_append(headers, "xfrom: 6");

    char *response = http_request(url, "POST", headers, NULL);
    curl_slist_free_all(headers);

    if (!response) {
        LOG_ERROR("Failed to get login QR code");
        return -1;
    }

    json_object *root = json_tokener_parse(response);
    if (!root) {
        LOG_ERROR("Failed to parse login QR code response");
        free(response);
        return -1;
    }

    if (json_object_get_boolean(json_object_object_get(root, "success"))) {
        json_object *data = json_object_object_get(root, "data");
        if (data) {
            const char* h5Url = json_object_get_string(json_object_object_get(data, "h5Url"));
            const char* reqId = json_object_get_string(json_object_object_get(data, "reqId"));
            int duration = json_object_get_int(json_object_object_get(data, "duration"));
            int interval = json_object_get_int(json_object_object_get(data, "interval"));

            LOG_INFO("Please scan the following QR code to login (valid for %d seconds):\n%s", duration, h5Url);
            LOG_INFO("Start polling login result, every %d seconds...", interval);

            int polled = 0;
            while (polled < duration) {
                snprintf(url, sizeof(url), "%s/ucapp/listener/login/poll", base_url);
                char post_data[256];
                snprintf(post_data, sizeof(post_data), "reqId=%s", reqId);
                LOG_DEBUG("Post data: %s", post_data);

                headers = NULL;
                headers = curl_slist_append(headers, "xfrom: 6");
                headers = curl_slist_append(headers, "udid: simulator-123456");

                char *poll_resp = http_request(url, "POST", headers, post_data);
                curl_slist_free_all(headers);

                if (poll_resp) {
                    LOG_DEBUG("Poll response: %s", poll_resp);
                    json_object* poll_root = json_tokener_parse(poll_resp);
                    if (poll_root) {
                        if (json_object_get_boolean(json_object_object_get(poll_root, "success"))) {
                            json_object *data_obj = json_object_object_get(poll_root, "data");
                            if (data_obj) {
                                json_object *token_obj = json_object_object_get(data_obj, "token");
                                if (token_obj) {
                                    const char* t = json_object_get_string(json_object_object_get(token_obj, "token"));
                                    const char* rt = json_object_get_string(json_object_object_get(token_obj, "refreshToken"));
                                    strcpy(token, t);
                                    strcpy(refresh_token, rt);
                                    
                                    // 尝试获取第一个孩子的ID
                                    json_object *childrens = json_object_object_get(data_obj, "childrens");
                                    if (childrens && json_object_get_type(childrens) == json_type_array) {
                                        if (json_object_array_length(childrens) > 0) {
                                            json_object *first_child = json_object_array_get_idx(childrens, 0);
                                            const char* child_id = json_object_get_string(json_object_object_get(first_child, "chdId"));
                                            strcpy(chdId, child_id);
                                        }
                                    }
                                    
                                    LOG_INFO("Login successful! Token obtained.");
                                    json_object_put(poll_root);
                                    free(poll_resp);
                                    json_object_put(root);
                                    free(response);
                                    return 0;
                                }
                            }
                        }
                        else {
                            LOG_ERROR("Login failed: %s", json_object_get_string(json_object_object_get(poll_root, "errorMsg")));
                        }
                        json_object_put(poll_root);
                    }
                    else {
                        LOG_ERROR("Unknown error: %s", json_object_get_string(json_object_object_get(poll_root, "errorMsg")));
                    }
                    free(poll_resp);
                }
                else {
                    LOG_ERROR("Failed to poll login result");
                }
                #ifdef _WIN32
                Sleep(interval * 1000);
                #else
                usleep(interval * 1000000);
                #endif
                polled += interval;
            }
        }
    }

    json_object_put(root);
    free(response);
    return -1;
}

int update_token(const char* base_url, const char* refreshToken, char* newToken, char* newRefreshToken) {
    char url[256];
    snprintf(url, sizeof(url), "%s/ucapp/listener/refreshToken", base_url);

    char post_json[256];
    snprintf(post_json, sizeof(post_json), "{\"refreshToken\":\"%s\"}", refreshToken);

    struct curl_slist *headers = NULL;
    headers = curl_slist_append(headers, "xfrom: 6");
    headers = curl_slist_append(headers, "Content-Type: application/json");

    char *response = http_request(url, "POST", headers, post_json);
    curl_slist_free_all(headers);

    if (!response) {
        LOG_ERROR("Failed to refresh token");
        return -1;
    }

    json_object *root = json_tokener_parse(response);
    if (!root) {
        LOG_ERROR("Failed to parse refresh token response");
        free(response);
        return -1;
    }

    int result = -1;
    if (json_object_get_boolean(json_object_object_get(root, "success"))) {
        json_object *data = json_object_object_get(root, "data");
        if (data) {
            const char* t = json_object_get_string(json_object_object_get(data, "token"));
            const char* rt = json_object_get_string(json_object_object_get(data, "refreshToken"));
            strcpy(newToken, t);
            strcpy(newRefreshToken, rt);
            result = 0;
        }
    }

    json_object_put(root);
    free(response);
    return result;
}

int get_user_info(const char* base_url, const char* token) {
    char url[256];
    snprintf(url, sizeof(url), "%s/ucapp/listener/user", base_url);

    struct curl_slist *headers = NULL;
    char token_header[256];
    char chdId_header[256];
    snprintf(token_header, sizeof(token_header), "token: %s", token);
    headers = curl_slist_append(headers, "xfrom: 6");
    headers = curl_slist_append(headers, token_header);

    char *response = http_request(url, "GET", headers, NULL);
    curl_slist_free_all(headers);

    if (!response) {
        LOG_ERROR("Failed to get user info");
        return -1;
    }

    json_object *root = json_tokener_parse(response);
    if (!root) {
        LOG_ERROR("Failed to parse user info response");
        free(response);
        return -1;
    }

    int result = -1;
    if (json_object_get_boolean(json_object_object_get(root, "success"))) {
        json_object *data = json_object_object_get(root, "data");
        if (data) {
            const char* m = json_object_get_string(json_object_object_get(data, "mobile"));
            if (m) LOG_INFO("Mobile: %s", m);;
            int v = json_object_get_int(json_object_object_get(data, "vip"));
            if (v == 0)
            {
                LOG_INFO("VIP status: %d", v);
            }else if (v == 1)
            {
                LOG_INFO("VIP status: %d", v);
            }else if (v == 2)
            {
                LOG_INFO("VIP status: %d", v);
            }
            const char* ve = json_object_get_string(json_object_object_get(data, "vipEnd"));
            if (ve) LOG_INFO("VIP end time: %s", ve);
            result = 0;
        }
    }

    json_object_put(root);
    free(response);
    return result;
}

int get_children_list(const char* base_url, const char* token, ChildInfo** childrens, int* count) {
    char url[256];
    snprintf(url, sizeof(url), "%s/ucapp/listener/children", base_url);

    struct curl_slist *headers = NULL;
    char token_header[256];
    snprintf(token_header, sizeof(token_header), "token: %s", token);
    headers = curl_slist_append(headers, "xfrom: 6");
    headers = curl_slist_append(headers, token_header);
    headers = curl_slist_append(headers, "Content-Type: application/json");

    char *response = http_request(url, "GET", headers, NULL);
    curl_slist_free_all(headers);

    if (!response) {
        LOG_ERROR("Failed to get childrens list");
        return -1;
    }

    json_object *root = json_tokener_parse(response);
    if (!root) {
        LOG_ERROR("Failed to parse childrens list response");
        free(response);
        return -1;
    }

    int result = -1;
    if (json_object_get_boolean(json_object_object_get(root, "success"))) {
        json_object *data = json_object_object_get(root, "data");
        if (data && json_object_get_type(data) == json_type_array) {
            int child_count = json_object_array_length(data);
            *childrens = (ChildInfo*)malloc(sizeof(ChildInfo) * child_count);
            if (!*childrens) {
                LOG_ERROR("Memory allocation failed");
                json_object_put(root);
                free(response);
                return -1;
            }

            for (int i = 0; i < child_count; i++) {
                json_object *child = json_object_array_get_idx(data, i);
                const char* id = json_object_get_string(json_object_object_get(child, "chdId"));
                const char* name = json_object_get_string(json_object_object_get(child, "nickName"));
                const char* avatar = json_object_get_string(json_object_object_get(child, "avatarUrl"));
                int gender = json_object_get_int(json_object_object_get(child, "gender"));

                if (id) strcpy((*childrens)[i].chdId, id);
                if (name) strcpy((*childrens)[i].nickName, name);
                if (avatar) strcpy((*childrens)[i].avatarUrl, avatar);
                (*childrens)[i].gender = gender;
            }

            *count = child_count;
            result = 0;
        }
    }

    json_object_put(root);
    free(response);
    return result;
}

int get_recommended_list(const char* base_url, const char* token, const char* chdId, ListenerItem** items, int* count) {
    char url[256];
    snprintf(url, sizeof(url), "%s/coreapp/listener/rcmd", base_url);

    struct curl_slist *headers = NULL;
    char token_header[256];
    char chdId_header[256];
    snprintf(token_header, sizeof(token_header), "token: %s", token);
    snprintf(chdId_header, sizeof(chdId_header), "chdId: %s", chdId);
    headers = curl_slist_append(headers, "xfrom: 6");
    headers = curl_slist_append(headers, token_header);
    headers = curl_slist_append(headers, chdId_header);
    headers = curl_slist_append(headers, "Content-Type: application/json");

    char *response = http_request(url, "GET", headers, NULL);
    curl_slist_free_all(headers);

    if (!response) {
        LOG_ERROR("Failed to get recommended list");
        return -1;
    }

    int result = parse_listener_items(response, items, count);
    free(response);
    return result;
}

int get_history_list(const char* base_url, const char* token, const char* chdId, ListenerItem** items, int* count) {
    char url[256];
    snprintf(url, sizeof(url), "%s/coreapp/listener/history", base_url);

    struct curl_slist *headers = NULL;
    char token_header[256];
    char chdId_header[256];
    snprintf(token_header, sizeof(token_header), "token: %s", token);
    snprintf(chdId_header, sizeof(chdId_header), "chdId: %s", chdId);
    headers = curl_slist_append(headers, "xfrom: 6");
    headers = curl_slist_append(headers, token_header);
    headers = curl_slist_append(headers, chdId_header);
    headers = curl_slist_append(headers, "Content-Type: application/json");

    char *response = http_request(url, "GET", headers, NULL);
    curl_slist_free_all(headers);

    if (!response) {
        LOG_ERROR("Failed to get history list");
        return -1;
    }

    int result = parse_listener_items(response, items, count);
    free(response);
    return result;
}

int get_playlist_list(const char* base_url, const char* token, const char* chdId, ListenerItem** items, int* count) {
    char url[256];
    snprintf(url, sizeof(url), "%s/coreapp/listener/playlist", base_url);

    struct curl_slist *headers = NULL;
    char token_header[256];
    char chdId_header[256];
    snprintf(token_header, sizeof(token_header), "token: %s", token);
    snprintf(chdId_header, sizeof(chdId_header), "chdId: %s", chdId);
    headers = curl_slist_append(headers, "xfrom: 6");
    headers = curl_slist_append(headers, token_header);
    headers = curl_slist_append(headers, chdId_header);
    headers = curl_slist_append(headers, "Content-Type: application/json");

    char *response = http_request(url, "GET", headers, NULL);
    curl_slist_free_all(headers);

    if (!response) {
        LOG_ERROR("Failed to get playlist list");
        return -1;
    }

    int result = parse_listener_items(response, items, count);
    free(response);
    return result;
}

int get_play_auth(const char* base_url, const char* token, const char* chdId, const char* id, const char* rssType, char* playUrl, long* size, char* duration) {
    char url[256];
    snprintf(url, sizeof(url), "%s/coreapp/listener/play/auth?id=%s&rssType=%s", base_url, id, rssType);

    struct curl_slist *headers = NULL;
    char token_header[256];
    char chdId_header[256];
    snprintf(token_header, sizeof(token_header), "token: %s", token);
    snprintf(chdId_header, sizeof(chdId_header), "chdId: %s", chdId);
    headers = curl_slist_append(headers, "xfrom: 6");
    headers = curl_slist_append(headers, token_header);
    headers = curl_slist_append(headers, chdId_header);
    headers = curl_slist_append(headers, "Content-Type: application/json");

    char *response = http_request(url, "GET", headers, NULL);
    curl_slist_free_all(headers);

    if (!response) {
        LOG_ERROR("Failed to get play auth");
        return -1;
    }

    json_object *root = json_tokener_parse(response);
    if (!root) {
        LOG_ERROR("Failed to parse play auth response");
        free(response);
        return -1;
    }

    int result = -1;
    if (json_object_get_boolean(json_object_object_get(root, "success"))) {
        json_object *data = json_object_object_get(root, "data");
        if (data) {
            const char* url = json_object_get_string(json_object_object_get(data, "playUrl"));
            long s = json_object_get_int64(json_object_object_get(data, "size"));
            const char* d = json_object_get_string(json_object_object_get(data, "duration"));
            if (url) strcpy(playUrl, url);
            *size = s;
            if (d) strcpy(duration, d);
            result = 0;
        }
    }

    json_object_put(root);
    free(response);
    return result;
}

void free_listener_items(ListenerItem* items, int count) {
    if (items) {
        free(items);
    }
}

void free_children(ChildInfo* childrens, int count) {
    if (childrens) {
        free(childrens);
    }
}
int network_check_connection() {
    curl_global_init(CURL_GLOBAL_DEFAULT);

    CURL* curl = curl_easy_init();
    if (!curl) {
        curl_global_cleanup();
        return -1;
    }
    // 使用百度作为测试服务器，因为它是一个可靠的公共服务器
    const char* test_url = "http://www.baidu.com";
    curl_easy_setopt(curl, CURLOPT_URL, test_url);
    curl_easy_setopt(curl, CURLOPT_NOBODY, 1L); // 只发送 HEAD 请求，不获取内容
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
    curl_easy_setopt(curl, CURLOPT_TIMEOUT, 5L); // 5秒超时
    curl_easy_setopt(curl, CURLOPT_CONNECTTIMEOUT, 3L); // 3秒连接超时

    CURLcode res = curl_easy_perform(curl);

    int result = -1;
    if (res == CURLE_OK) {
        long response_code = 0;
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
        if (response_code >= 200 && response_code < 400) {
            result = 0;
        }
    }
    curl_easy_cleanup(curl);
    curl_global_cleanup();
    return result;
}

int boot_login() {
    int network_result = network_check_connection();
    if (network_result != 0) {
        return BOOT_NETWORK_ERROR;
    }
    curl_global_init(CURL_GLOBAL_DEFAULT);

    char old_refresh_token[256];
    strcpy(old_refresh_token, refresh_token);
    update_token(base_url, old_refresh_token, token, refresh_token);

    strcpy(token, "MTQyMDcxOTNlZjBkMWU2OTFkZjdmYzBlNjMyZjQ1OWMwNmQzMDNkNjAxZjg0ZjUwMTZjYTNhZTcwZTA0YTg4MzA1NmI1MTZhYzNhODk2MmJhMTRjOWZhZTAwYTYwNzAx");

    if (get_user_info(base_url, token) != 0)
    {
        return BOOT_LOGIN_EXPIRED;
    }
    int children_result = get_children_list(base_url, token, &childrens, &child_count);
    if (children_result == 0) {
        LOG_INFO("Children list obtained successfully! Total %d childrens", child_count);
        for (int i = 0; i < child_count; i++) {
            LOG_INFO("Child %d: ID=%s, Name=%s, Gender=%d", i + 1, childrens[i].chdId, childrens[i].nickName, childrens[i].gender);
        }
    }

    curl_global_cleanup();
    return BOOT_LOGIN_SUCCESS;
}
