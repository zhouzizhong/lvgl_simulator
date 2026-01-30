#include "network.h"
#include "log.h"

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

static size_t WriteMemoryCallback(void *contents, size_t size, size_t nmemb, void *userp) {
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

char* http_request(const char* url, const char* method, const struct curl_slist* headers, const char* post_data) {
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
                char post_json[256];
                snprintf(post_json, sizeof(post_json), "{\"reqId\":\"%s\"}", reqId);
                LOG_DEBUG("Post JSON: %s", post_json);

                headers = NULL;
                headers = curl_slist_append(headers, "xfrom: 6");

                char *poll_resp = http_request(url, "POST", headers, post_json);
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
                                    json_object *children = json_object_object_get(data_obj, "children");
                                    if (children && json_object_get_type(children) == json_type_array) {
                                        if (json_object_array_length(children) > 0) {
                                            json_object *first_child = json_object_array_get_idx(children, 0);
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

int refresh_token(const char* base_url, const char* refreshToken, char* newToken, char* newRefreshToken) {
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

int get_user_info(const char* base_url, const char* token, const char* chdId, char* mobile, int* vip, char* vipEnd) {
    char url[256];
    snprintf(url, sizeof(url), "%s/ucapp/listener/user", base_url);

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
            int v = json_object_get_int(json_object_object_get(data, "vip"));
            const char* ve = json_object_get_string(json_object_object_get(data, "vipEnd"));
            if (m) strcpy(mobile, m);
            *vip = v;
            if (ve) strcpy(vipEnd, ve);
            result = 0;
        }
    }

    json_object_put(root);
    free(response);
    return result;
}

int get_children_list(const char* base_url, const char* token, ChildInfo** children, int* count) {
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
        LOG_ERROR("Failed to get children list");
        return -1;
    }

    json_object *root = json_tokener_parse(response);
    if (!root) {
        LOG_ERROR("Failed to parse children list response");
        free(response);
        return -1;
    }

    int result = -1;
    if (json_object_get_boolean(json_object_object_get(root, "success"))) {
        json_object *data = json_object_object_get(root, "data");
        if (data && json_object_get_type(data) == json_type_array) {
            int child_count = json_object_array_length(data);
            *children = (ChildInfo*)malloc(sizeof(ChildInfo) * child_count);
            if (!*children) {
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

                if (id) strcpy((*children)[i].chdId, id);
                if (name) strcpy((*children)[i].nickName, name);
                if (avatar) strcpy((*children)[i].avatarUrl, avatar);
                (*children)[i].gender = gender;
            }

            *count = child_count;
            result = 0;
        }
    }

    json_object_put(root);
    free(response);
    return result;
}

static int parse_listener_items(const char* response, ListenerItem** items, int* count) {
    json_object *root = json_tokener_parse(response);
    if (!root) {
        LOG_ERROR("Failed to parse response");
        return -1;
    }

    int result = -1;
    if (json_object_get_boolean(json_object_object_get(root, "success"))) {
        json_object *data = json_object_object_get(root, "data");
        if (data && json_object_get_type(data) == json_type_array) {
            int item_count = json_object_array_length(data);
            *items = (ListenerItem*)malloc(sizeof(ListenerItem) * item_count);
            if (!*items) {
                LOG_ERROR("Memory allocation failed");
                json_object_put(root);
                return -1;
            }

            for (int i = 0; i < item_count; i++) {
                json_object *item = json_object_array_get_idx(data, i);
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

void free_children(ChildInfo* children, int count) {
    if (children) {
        free(children);
    }
}

int test_network() {
    curl_global_init(CURL_GLOBAL_DEFAULT);
    
    // 检查 curl 版本和功能
    const char* curl_version_str = curl_version();
    LOG_INFO("curl version: %s", curl_version_str);
    
    // 检查是否支持 SSL
    curl_version_info_data *info = curl_version_info(CURLVERSION_NOW);
    if (info->features & CURL_VERSION_SSL) {
        LOG_INFO("curl supports SSL");
    } else {
        LOG_ERROR("curl does not support SSL");
    }
    
    // 检查支持的协议
    LOG_INFO("Supported protocols:");
    for (int i = 0; info->protocols[i]; i++) {
        LOG_INFO("  %s", info->protocols[i]);
    }

    const char* base_url = "http://apitest.ukids.cn";

    char token[512] = { 0 };
    char refresh_token[512] = { 0 };
    char chdId[64] = { 0 };

    // 1. 测试登录功能
    LOG_INFO("=== Test login function ===");
    int login_result = listener_login(base_url, token, refresh_token, chdId);
    if (login_result != 0) {
        LOG_ERROR("Login failed, program ended.");
        curl_global_cleanup();
        return 1;
    }

    LOG_INFO("Login successful!");
    LOG_INFO("Token: %s", token);
    LOG_INFO("Refresh Token: %s", refresh_token);
    LOG_INFO("Child ID: %s", chdId);

    // 2. 测试用户信息查询功能
    LOG_INFO("=== Test user info query function ===");
    char mobile[32] = { 0 };
    int vip = 0;
    char vipEnd[32] = { 0 };
    int user_info_result = get_user_info(base_url, token, chdId, mobile, &vip, vipEnd);
    if (user_info_result == 0) {
        LOG_INFO("User info obtained successfully!");
        LOG_INFO("Mobile: %s", mobile);
        LOG_INFO("VIP status: %d", vip);
        LOG_INFO("VIP end time: %s", vipEnd);
    }
    else {
        LOG_ERROR("Failed to get user info");
    }

    // 3. 测试孩子列表查询功能
    LOG_INFO("=== Test children list query function ===");
    ChildInfo* children = NULL;
    int child_count = 0;
    int children_result = get_children_list(base_url, token, &children, &child_count);
    if (children_result == 0) {
        LOG_INFO("Children list obtained successfully! Total %d children", child_count);
        for (int i = 0; i < child_count; i++) {
            LOG_INFO("Child %d: ID=%s, Name=%s, Gender=%d", i + 1, children[i].chdId, children[i].nickName, children[i].gender);
        }
        free_children(children, child_count);
    }
    else {
        LOG_ERROR("Failed to get children list");
    }

    // 4. 测试推荐列表功能
    LOG_INFO("=== Test recommended list function ===");
    ListenerItem* recommended_items = NULL;
    int recommended_count = 0;
    int recommended_result = get_recommended_list(base_url, token, chdId, &recommended_items, &recommended_count);
    if (recommended_result == 0) {
        LOG_INFO("Recommended list obtained successfully! Total %d items", recommended_count);
        for (int i = 0; i < recommended_count && i < 5; i++) {
            LOG_INFO("Recommended %d: ID=%s, Name=%s, Type=%s", i + 1, recommended_items[i].id, recommended_items[i].name, recommended_items[i].rssType);
        }
        if (recommended_count > 5) {
            LOG_INFO("... %d more items not shown", recommended_count - 5);
        }
        free_listener_items(recommended_items, recommended_count);
    }
    else {
        LOG_ERROR("Failed to get recommended list");
    }

    // 5. 测试历史列表功能
    LOG_INFO("=== Test history list function ===");
    ListenerItem* history_items = NULL;
    int history_count = 0;
    int history_result = get_history_list(base_url, token, chdId, &history_items, &history_count);
    if (history_result == 0) {
        LOG_INFO("History list obtained successfully! Total %d items", history_count);
        for (int i = 0; i < history_count && i < 5; i++) {
            LOG_INFO("History %d: ID=%s, Name=%s, Type=%s", i + 1, history_items[i].id, history_items[i].name, history_items[i].rssType);
        }
        if (history_count > 5) {
            LOG_INFO("... %d more items not shown", history_count - 5);
        }
        free_listener_items(history_items, history_count);
    }
    else {
        LOG_ERROR("Failed to get history list");
    }

    // 6. 测试听单列表功能
    LOG_INFO("=== Test playlist list function ===");
    ListenerItem* playlist_items = NULL;
    int playlist_count = 0;
    int playlist_result = get_playlist_list(base_url, token, chdId, &playlist_items, &playlist_count);
    if (playlist_result == 0) {
        LOG_INFO("Playlist list obtained successfully! Total %d items", playlist_count);
        for (int i = 0; i < playlist_count && i < 5; i++) {
            LOG_INFO("Playlist %d: ID=%s, Name=%s, Type=%s", i + 1, playlist_items[i].id, playlist_items[i].name, playlist_items[i].rssType);
        }
        if (playlist_count > 5) {
            LOG_INFO("... %d more items not shown", playlist_count - 5);
        }
        free_listener_items(playlist_items, playlist_count);
    }
    else {
        LOG_ERROR("Failed to get playlist list");
    }

    // 7. 测试播放鉴权功能（使用推荐列表中的第一个项目）
    LOG_INFO("=== Test play auth function ===");
    recommended_result = get_recommended_list(base_url, token, chdId, &recommended_items, &recommended_count);
    if (recommended_result == 0 && recommended_count > 0) {
        char playUrl[1024] = { 0 };
        long size = 0;
        char duration[32] = { 0 };
        int play_auth_result = get_play_auth(base_url, token, chdId, recommended_items[0].id, recommended_items[0].rssType, playUrl, &size, duration);
        if (play_auth_result == 0) {
            LOG_INFO("Play auth successful!");
            LOG_INFO("Play URL: %s", playUrl);
            LOG_INFO("File size: %ld", size);
            LOG_INFO("Duration: %s", duration);
        }
        else {
            LOG_ERROR("Failed to get play auth");
        }
        free_listener_items(recommended_items, recommended_count);
    }
    else {
        LOG_INFO("Cannot get test item, play auth test skipped");
    }

    LOG_INFO("=== All tests completed ===");

    curl_global_cleanup();
    return 0;
}
