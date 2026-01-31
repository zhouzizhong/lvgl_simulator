/*
* Copyright 2024 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#ifndef __CUSTOM_H_
#define __CUSTOM_H_
#ifdef __cplusplus
extern "C" {
#endif
#include "lvgl.h"
#include "gui_guider.h"

    LV_FONT_DECLARE(lv_font_MyPingFangSC_Semibold_20)
    LV_FONT_DECLARE(lv_font_MyPingFangSC_Semibold_18)
    LV_FONT_DECLARE(lv_font_MyPingFangSC_Semibold_16)
    LV_FONT_DECLARE(lv_font_MyPingFangSC_Regular_14)
    LV_FONT_DECLARE(lv_font_MyPingFangSC_Regular_16)
    LV_FONT_DECLARE(lv_font_MyPingFangSC_Medium_18)

    LV_IMAGE_DECLARE(ic_play);

/*********************
 *      DEFINES
 *********************/
    // 系统提示消息定义
    #define MSG_LOW_BATTERY          1    // 低电量提示
    #define MSG_CHARGING             2    // 正在充电
    #define MSG_CHARGE_COMPLETE      3    // 充电完成
    #define MSG_WIFI_DISCONNECT      4    // WiFi断开
    #define MSG_GENERAL_ERROR        5    // 通用异常提示
    #define MSG_OTA_UPDATE           6    // OTA升级提示
    #define MSG_BLUETOOTH_DISCONNECT 7    // 蓝牙断开
    #define MSG_CHILD_LOCK_ON        8    // 童锁开启
    #define MSG_CHILD_LOCK_OFF       9    // 童锁关闭
    #define MSG_STORAGE_LOW          10   // 存储空间不足
    #define MSG_BT_HEADSET_CONNECT   11   // 蓝牙耳机接入
    #define MSG_BT_HEADSET_DISCONNECT 12  // 蓝牙耳机断开

    // UI相关定义
    #define CONT_BG_OPA 25                              // 容器背景透明度
    #define MAIN_TITLE_OPA 256                          // 主标题透明度
    #define SUB_TITLE_OPA 205                           // 副标题透明度
    #define BLUR_RADIUS 15                              // 模糊半径
    #define RETURN_LOAD_ANIM LV_SCR_LOAD_ANIM_OUT_RIGHT // 返回动画样式
    #define NEXT_LOAD_ANIM LV_SCR_LOAD_ANIM_OVER_LEFT   // 跳转动画样式
    #define POP_LOAD_ANIM LV_SCR_LOAD_ANIM_FADE_ON      // 弹出动画样式
    #define LABLE_SCROLL_SPEED 8000                     // 标签滚动速度
    #define LOAD_ANIM_TIME 200                          // 加载动画时间
    #define LOAD_ANIM_DELAY 200                         // 加载动画延迟
    #define INACTIVITY_TIMEOUT_MS   (5 * 60 * 1000)     // 5分钟
    #define PLAY_STATUS_STOPPED  0                      // 播放暂停
    #define PLAY_STATUS_PLAYING  1                      // 播放中
    #define CHILDREN_COUNT 13                           // 主页子容器个数
    #define MAX_CHILDREN_COUNT 2                        // 最大孩子数量
    #define TOAST_DEFAULT_DURATION 2000                 // 默认显示时间2秒
    #define TOAST_ANIM_DURATION 300                     // 动画持续时间
    #define MAX_SONG_COUNT 200                          // 最大歌曲数量

    /* 系统属性默认值 */
    #define BATTERY_DEFAULT_LEVEL 80                    // 默认电量值
    #define DEFAULT_BRIGHTNESS 2                        // 默认亮度级别（0-3）

    /* 歌单页面标识宏 */
    #define SONGLIST_NONE 0
    #define SONGLIST_TODAY 1
    #define SONGLIST_RECENT 2
    #define SONGLIST_MY 3
    #define SONGLIST_LOCAL 4
    /* 跳转页面标识宏 */
    #define STARTUP_PAGE 0
    #define HOME_PAGE 1
    #define PLAYER_PAGE 2
    #define TODAY_LISTENING_PAGE 3
    #define ACCOUNT_MANAGEMENT_PAGE 4
    #define ACCOUNT_LOGIN_PAGE 5
    #define DEVICE_INFORMATION_PAGE 6
    #define LOCAL_AUDIO_PAGE 7
    #define NETWORK_AND_BLUETOOTH_PAGE 8
    #define SCREEN_BRIGHTNESS_PAGE 9
    #define SYSTEM_SETTINGS_PAGE 10
    #define MY_ORDER_PAGE 11
    #define RECENTLY_LISTENING_PAGE 12
    #define LOCAL_LISTENING_PAGE 13
    #define POP_PAGE 14
    #define WIFI_CONNECT_PAGE 15
    #define BT_CONNECT_PAGE 16
    /* 页面栈最大深度 */
    #define PAGE_STACK_SIZE 20

    /* 开机登录流程相关 */
    #define BOOT_LOGIN_SUCCESS 0        // 开机登录成功
    #define BOOT_NETWORK_ERROR 1        // 网络连接错误
    #define BOOT_LOGIN_EXPIRED 2        // 登录信息过期

/**********************
 *      TYPEDEFS
 **********************/
    /* 当前播放歌曲信息 */
    typedef struct {
    char song_name[128];        // 歌曲名
    char album_name[128];       // 专辑名
    char cover_path[256];   // 封面图路径
    int play_status;            // 播放状态 (0:暂停, 1:播放中)
    int current_position;       // 播放进度 (单位:秒)
    int total_duration;         // 总时长 (单位:秒)
    int song_index;             // 歌曲在歌单中的索引
    } current_play_data_t;
    /* 当前设备信息 */
    typedef struct {
        /* 存储空间相关信息 */
        char total_storage[128];     /* 总存储空间 */
        char free_storage[128];      /* 可用存储空间 */
        char system_storage[128];    /* 系统文件存储空间 */
        char audio_storage[128];     /* 音频文件存储空间 */
        char cache_storage[128];     /* 缓存文件存储空间 */
        long long  total_storage_int;      /* 总存储空间（单位：字节） */
        long long  free_storage_int;       /* 可用存储空间（单位：字节） */
        long long  system_storage_int;     /* 系统文件存储空间（单位：字节） */
        long long  audio_storage_int;      /* 音频文件存储空间（单位：字节） */
        long long  cache_storage_int;      /* 缓存文件存储空间（单位：字节） */

        /* 版本信息 */
        char software_version[128];  /* 软件版本 */
        char firmware_version[128];  /* 固件版本 */
        char latest_version[128];    /* 最新版本 */
        /* 设备信息 */
        char device_name[128];       /* 设备名称 */
        char model_name[128];        /* 设备型号 */
        char device_id[128];         /* 设备唯一标识符 */
        char device_sn[128];         /* 设备序列号(SN码) */
    } current_device_info_t;
    /* 当前用户信息 */
    typedef struct {
        char user_phone[128];         // 手机号
        char user_vip_status[128];    // 会员状态
        char user_vip_expire[128];    // 会员到期时间
    } current_user_info_t;
    /* 当前孩子信息 */
    typedef struct {
        char child_id[128];          // 孩子ID
        char child_nickname[128];    // 孩子昵称
        char child_avatar[256];      // 孩子头像
        int child_gender;            // 孩子性别 (1:男, 2:女)
    } current_child_info_t;
    /*本地音乐文件夹信息*/
    typedef struct {
        char folder_name[128];  // 文件夹名称
        char folder_path[128];  // 文件夹路径
        int song_count;         // 歌曲数量
    } local_folder_t;
    /* 本地音乐文件夹仓库 */
    typedef struct {
        local_folder_t* folders; // 文件夹数组
        int count;               // 文件夹数量
        int capacity;            // 容量大小
    } local_folder_repository_t;
    /* 一首歌的元数据 */
    typedef struct
    {
        char song_name[128];
        char album_name[128];
        char cover_path[256];
        int song_index; // 歌曲在歌单中的索引，从0开始
    } song_item_t;
    /* 一个歌单 = 动态数组 */
    typedef struct
    {
        song_item_t* items;
        int count; // 已存歌曲数
    } playlist_t;
    /* 孩子信息库 */
    typedef struct {
        current_child_info_t children[MAX_CHILDREN_COUNT];
        int count;
    } child_info_repository_t;
    /* 固件更新内容 */
    typedef struct {
        char ex_version[128];
        char is_must_update[128];
        char update_content[1024];
    } firmware_update_content_t;
    /* 蓝牙设备信息 */
    typedef struct {
        char name[64];      // 蓝牙设备名称
        char type[32];      // 蓝牙设备类型
        bool connected;     // 连接状态
    } bluetooth_device_t;
    /* 蓝牙设备容器 */
    typedef struct {
        bluetooth_device_t* devices;    // 蓝牙设备数组
        int count;                      // 当前设备数量
        int capacity;                   // 容器容量
    } bluetooth_device_container_t;
    /* 播放列表用户数据结构体 */
    typedef struct
    {
        char song_name[128];
        char album_name[128];
        char cover_img[256];
        lv_ui* ui;
        int song_index; // 歌曲在歌单中的索引
    } song_user_data_t;
    /* Toast用户数据结构体 */
    typedef struct
    {
        lv_obj_t* toast;
        lv_timer_t* timer;
    } toast_data_t;
    /* 本地音乐歌单项用户数据结构体 */
    typedef struct
    {
        lv_ui* ui;
        local_folder_t* folder;
    } playlist_item_user_data_t;
    /* 扫描线程参数结构体 */
    typedef struct {
        const char* playlist_path;
        const char* playlist_name;
    } scan_thread_params_t;
    typedef struct {
        int stack[PAGE_STACK_SIZE];  // 存储页面ID的数组
        int top;                           // 栈顶指针
    } page_stack_t;

/**********************
 *  GLOBAL VARIABLES
 **********************/
    /* 当前播放歌曲信息 */
    extern current_play_data_t g_current_play_data;
    /* 当前设备信息 */
    extern current_device_info_t g_current_device_info;
    /* 当前用户信息 */
    extern current_user_info_t g_current_user_info;
    /* 当前孩子信息 */
    extern current_child_info_t g_current_child_info;
    extern int g_log_child;
    extern child_info_repository_t g_child_info_repo;;
    /* 固件更新内容 */
    extern firmware_update_content_t g_firmware_update_content;
    extern int g_firmware_update_progress;
    extern bool is_updating;                // 更新状态事件：0=未更新，1=正在更新
    extern bool is_latest_version;          // 是否已是最新版本
    extern bool is_logged_in;               // 是否已登录

    /* 编码器控制分组 */
    extern lv_group_t* today_listening_group;
    extern lv_group_t* recently_listening_group;
    extern lv_group_t* my_order_group;
    extern lv_group_t* local_listening_group;
    extern lv_group_t* local_songlist_group;
    extern lv_group_t* system_settings_group;
    extern lv_group_t* home_group;
    extern lv_style_t style_focus;

    /* 本地音乐文件夹仓库 */
    extern local_folder_repository_t g_local_folder_repo;
    extern char* g_cur_localfolder_path;
    extern char* g_cur_localfolder_name;
    extern int g_cur_localfolder_song_count;
    extern int is_localsong_exists;
    extern playlist_t g_local_playlist;     // 本地音频列表
    extern int g_local_read_idx;            // 本地音频列表当前读取索引
    extern char** audio_paths;              // 本地音频文件路径数组

    /* 儿童锁状态*/
    extern bool g_child_locked;

    /* 电池状态 */
    extern int g_current_battery_level; // 当前电量值
    extern int g_pre_battery_level;
    extern int g_current_charge_status; // 当前充电状态，0表示未充电，1表示充电中
    extern int g_pre_charge_status;

    /* 屏幕亮度 */
    extern int g_current_brightness;

    /* wifi蓝牙连接 */
    extern char login_qrcode[];
    extern char bt_qrcode[];
    extern char wifi_qrcode[];
    extern bool is_wifi_connected;
    extern bool is_bt_connected;
    extern char wifi_name[];
    extern char bt_name[];
    // 蓝牙设备容器全局变量
    extern bluetooth_device_container_t g_bt_device_container;
    // 弹出页面自动关闭定时器
    extern lv_timer_t* g_pop_page_timer;
    // 主页子容器数组
    extern lv_obj_t* children[CHILDREN_COUNT];
    /* 页面管理变量 */
    extern page_stack_t g_page_stack;
    extern int g_cur_songlist;
    extern int g_pre_page;
    extern int g_current_page;
    extern bool today_songlist_load_flag;
    extern bool recently_songlist_load_flag;
    extern bool my_songlist_load_flag;
    extern int today_scrolly_bottom_loader;
    extern int recently_scrolly_bottom_loader;
    extern int my_scrolly_bottom_loader;
    extern int local_scrolly_bottom_loader;

    /* 三个网络歌单 */
    extern playlist_t g_today_playlist;  // 今日熏听
    extern playlist_t g_recent_playlist; // 最近熏听
    extern playlist_t g_my_playlist;     // 我的听单

    /* 开机流程相关 */
    extern int boot_toast_showed;

    void custom_init(lv_ui* ui);

    /* 显示Toast*/
    void show_toast(const char* message, uint32_t duration_ms);
    /* 显示音量条*/
    void show_volume_bar(int volume);
    /* 显示电池电量显示组件*/
    void show_battery_display(void);
    /* 隐藏电池电量显示组件*/
    void hide_battery_display(void);
    /* 保存亮度值*/
    void save_brightness_value(int brightness_level);
    /* 加载亮度值*/
    void load_brightness_value(int* brightness_level);
    /* 应用亮度值到UI*/
    void apply_brightness_to_ui(int brightness_level);
    /* 设置硬件亮度 */
    void apply_brightness_to_hardware(int brightness_level);
    /* 设置屏幕亮度 */
    void set_screen_brightness(int brightness_level);
    /* 开始封面图旋转动画 */
    void start_music_cover_rotation(lv_ui* ui);
    /* 停止封面图旋转动画 */
    void stop_music_cover_rotation(lv_ui* ui);
#ifdef __cplusplus
}
#endif
#endif /* __CUSTOM_H_ */
