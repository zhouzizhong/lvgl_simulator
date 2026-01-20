/*
* Copyright 2024 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/


/*********************
 *      INCLUDES
 *********************/
#include <stdio.h>
#include "lvgl.h"
#include "custom.h"

/**********************
 *  GLOBAL VARIABLES
 **********************/
/* 当前播放歌曲信息 */
current_play_data_t g_current_play_data;
/* 当前设备信息 */
current_device_info_t g_current_device_info;
/* 当前用户信息 */
current_user_info_t g_current_user_info;
/* 当前孩子信息 */
current_child_info_t g_current_child_info;
int g_log_child = 0;
child_info_repository_t g_child_info_repo = { 0 };
/* 固件更新内容 */
firmware_update_content_t g_firmware_update_content = { 0 };
int g_firmware_update_progress = 0;
bool is_updating = false; // 是否正在更新
bool is_latest_version = true; // 是否已是最新版本

/* 编码器控制分组 */
lv_group_t* today_listening_group = NULL;
lv_group_t* recently_listening_group = NULL;
lv_group_t* my_order_group = NULL;
lv_group_t* local_listening_group = NULL;
lv_group_t* local_songlist_group = NULL;
lv_group_t* system_settings_group = NULL;
lv_group_t* home_group = NULL;
lv_style_t style_focus;

/* 本地音乐文件夹仓库 */
local_folder_repository_t g_local_folder_repo = { 0 };
char* g_cur_localfolder_path = NULL;
char* g_cur_localfolder_name = NULL;
int g_cur_localfolder_song_count = 0;
playlist_t g_local_playlist = { 0 };     // 本地音频
int g_local_read_idx = 0;
int is_localsong_exists = 0;
char** audio_paths = NULL;
int audio_count = 0;            // 当前有多少条路径
int audio_capacity = 0;         // 已分配容量

/* 儿童锁状态*/
bool child_locked = false;

/* 电池状态 */
int g_current_battery_level = BATTERY_DEFAULT_LEVEL; // 当前电量值
int g_pre_battery_level = BATTERY_DEFAULT_LEVEL;
int g_current_charge_status = 0; // 当前充电状态，0表示未充电，1表示充电中
int g_pre_charge_status = 0;

/* wifi蓝牙连接 */
char login_qrcode[256] = "login ";
char bt_qrcode[256] = "bt ";
char wifi_qrcode[256] = "wifi ";
bool is_wifi_connected = false;
bool is_bt_connected = false;
char wifi_name[64] = "wifi_default_name";
char bt_name[64] = "bt_default_name";

/* 蓝牙设备容器全局变量 */
bluetooth_device_container_t g_bt_device_container = { 0 };
/* 弹出页面自动关闭定时器 */
lv_timer_t* g_pop_page_timer = NULL;
/* 子对象容器 */
lv_obj_t* children[CHILDREN_COUNT];

/* 页面管理 */
int g_cur_songlist = SONGLIST_MY;
int g_pre_page = STARTUP_PAGE;
int g_current_page = STARTUP_PAGE;
page_stack_t g_page_stack = { .top = -1 };
bool today_songlist_load_flag = false;
bool recently_songlist_load_flag = false;
bool my_songlist_load_flag = false;

/**********************
 *  STATIC VARIABLES
 **********************/
/* 支持的音频文件扩展名 */
static const char* AUDIO_EXTENSIONS[] = {
    ".mp3", ".mp2", ".ogg", ".m4r", ".aac", ".amr", ".flac", ".wav"
};
/* 三个歌单 */
static playlist_t g_today_playlist = { 0 };  // 今日熏听
static playlist_t g_recent_playlist = { 0 }; // 最近熏听
static playlist_t g_my_playlist = { 0 };     // 我的听单
/* 读取游标（每个歌单独立） */
static int g_today_read_idx = 0;
static int g_recent_read_idx = 0;
static int g_my_read_idx = 0;
/* toast相关变量 */
static lv_obj_t* g_toast_container = NULL;      // Toast容器
static lv_obj_t* g_volume_bar = NULL;           // 音量条
static lv_obj_t* g_toast_label = NULL;          // 文本标签

/* 定时器定义 */
static lv_timer_t* g_toast_timer = NULL;                    // 自动隐藏定时器
static lv_timer_t* g_volume_bar_timer = NULL;               // 音量条自动隐藏定时器
static lv_timer_t* play_progress_timer = NULL;              // 播放进度更新定时器
static lv_timer_t* play_progress_delay_timer = NULL;        // 播放进度更新延迟定时器

// 封面图旋转相关变量
static lv_timer_t* music_cover_timer = NULL;
static bool music_cover_rotating = false;
static int32_t current_angle = 0;
/**********************
 *  STATIC PROTOTYPES
 **********************/

/**
 * Create a demo application
 */

void custom_init(lv_ui *ui)
{
    /* Add your codes here */
}

