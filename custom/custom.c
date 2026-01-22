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
#include <stdlib.h>
#include <string.h>
#include "lvgl.h"
#include "gui_guider.h"
#include "custom.h"
#include "data_manager.h"
#include "page_manager.h"

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
bool is_logged_in = false; // 是否已登录

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
page_stack_t g_page_stack = { .top = -1 };
int g_cur_songlist = SONGLIST_MY;
int g_pre_page = STARTUP_PAGE;
int g_current_page = STARTUP_PAGE;
bool today_songlist_load_flag = false;
bool recently_songlist_load_flag = false;
bool my_songlist_load_flag = false;
// 歌单滚动控制变量
int today_scrolly_bottom_loader = 134;
int recently_scrolly_bottom_loader = 134;
int my_scrolly_bottom_loader = 134;
int local_scrolly_bottom_loader = 134;

/* 三个网络歌单 */
playlist_t g_today_playlist = { 0 };  // 今日熏听
playlist_t g_recent_playlist = { 0 }; // 最近熏听
playlist_t g_my_playlist = { 0 };     // 我的听单

/**********************
 *  STATIC VARIABLES
 **********************/
/* 支持的音频文件扩展名 */
static const char* AUDIO_EXTENSIONS[] = {
    ".mp3", ".mp2", ".ogg", ".m4r", ".aac", ".amr", ".flac", ".wav"
};
/* toast相关变量 */
static lv_obj_t* g_toast_container = NULL;      // Toast容器
static lv_obj_t* g_volume_bar = NULL;           // 音量条
static lv_obj_t* g_toast_label = NULL;          // 文本标签

/* 定时器定义 */
static lv_timer_t* g_toast_timer = NULL;                    // 自动隐藏定时器
static lv_timer_t* g_volume_bar_timer = NULL;               // 音量条自动隐藏定时器
static lv_timer_t* play_progress_timer = NULL;              // 播放进度更新定时器

// 封面图旋转相关变量
static lv_timer_t* music_cover_timer = NULL;
static bool music_cover_rotating = false;
static int32_t current_angle = 0;
/**********************
 *  STATIC PROTOTYPES
 **********************/
/**
 * Toast自动隐藏回调函数
 * @param timer 定时器对象
 */
static void toast_hide_timer_cb(lv_timer_t* timer)
{
    // 直接隐藏Toast容器
    if (g_toast_container)
    {
        lv_obj_add_flag(g_toast_container, LV_OBJ_FLAG_HIDDEN);
    }
    // 删除定时器
    if (g_toast_timer)
    {
        lv_timer_del(g_toast_timer);
        g_toast_timer = NULL;
    }
}
/**
 * 音量条自动隐藏回调函数
 * @param timer 定时器对象
 */
static void volume_bar_hide_timer_cb(lv_timer_t* timer)
{
    // 隐藏音量条
    if (g_volume_bar)
    {
        lv_obj_add_flag(g_volume_bar, LV_OBJ_FLAG_HIDDEN);
    }

    // 删除定时器
    if (g_volume_bar_timer)
    {
        lv_timer_del(g_volume_bar_timer);
        g_volume_bar_timer = NULL;
    }
}
/**
 * 初始化Toast组件和音量条组件
 * @return true 初始化成功，false 初始化失败
 */
static bool init_toast_volume_bar(void)
{
    // 获取顶层图层
    lv_obj_t* top_layer = lv_layer_top();
    if (!top_layer)
    {
        return false;
    }
    // 直接在顶层图层上创建Toast容器
    g_toast_container = lv_obj_create(top_layer);
    if (!g_toast_container)
    {
        return false;
    }
    // 设置Toast容器样式
    lv_obj_remove_style_all(g_toast_container);
    lv_obj_set_size(g_toast_container, 120, 40);
    lv_obj_set_style_bg_color(g_toast_container, lv_color_hex(0x262626), LV_PART_MAIN);
    lv_obj_set_style_bg_opa(g_toast_container, 180, LV_PART_MAIN);
    // 增大圆角半径到更明显的值，如20像素
    lv_obj_set_style_radius(g_toast_container, 20, LV_PART_MAIN);
    // 可选：添加边框使圆角更明显
    lv_obj_set_style_border_width(g_toast_container, 1, LV_PART_MAIN); // 无边框
    // 可选：设置阴影增强视觉效果
    lv_obj_set_style_shadow_color(g_toast_container, lv_color_hex(0x000000), LV_PART_MAIN);
    lv_obj_set_style_shadow_opa(g_toast_container, 100, LV_PART_MAIN);
    lv_obj_set_style_shadow_width(g_toast_container, 5, LV_PART_MAIN);
    lv_obj_center(g_toast_container);
    // 初始隐藏状态
    lv_obj_add_flag(g_toast_container, LV_OBJ_FLAG_HIDDEN);
    // 创建文本标签
    g_toast_label = lv_label_create(g_toast_container);
    if (!g_toast_label)
    {
        lv_obj_del(g_toast_container);
        g_toast_container = NULL;
        return false;
    }
    // 设置文本标签样式
    lv_label_set_text(g_toast_label, "Toast");
    lv_obj_center(g_toast_label);
    lv_obj_set_style_border_width(g_toast_label, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(g_toast_label, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(g_toast_label, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(g_toast_label, &lv_font_MyPingFangSC_Semibold_16, 0);
    lv_obj_set_style_text_opa(g_toast_label, 200, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(g_toast_label, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(g_toast_label, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(g_toast_label, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(g_toast_label, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(g_toast_label, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(g_toast_label, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(g_toast_label, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(g_toast_label, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(g_toast_label, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // 初始化音量条组件
    g_volume_bar = lv_bar_create(top_layer);
    lv_obj_set_style_anim_time(g_volume_bar, 1000, 0);
    lv_bar_set_mode(g_volume_bar, LV_BAR_MODE_NORMAL);
    lv_bar_set_range(g_volume_bar, 0, 25);
    lv_bar_set_value(g_volume_bar, 10, LV_ANIM_OFF);
    lv_obj_set_pos(g_volume_bar, 8, 89);
    lv_obj_set_size(g_volume_bar, 8, 120);
    //Write style for volume_bar, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(g_volume_bar, LV_OPA_100, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(g_volume_bar, lv_color_hex(0x333333), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(g_volume_bar, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(g_volume_bar, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(g_volume_bar, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    //Write style for volume_bar, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(g_volume_bar, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(g_volume_bar, lv_color_hex(0xffffff), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(g_volume_bar, LV_GRAD_DIR_NONE, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(g_volume_bar, 0, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    // 初始隐藏状态
    lv_obj_add_flag(g_volume_bar, LV_OBJ_FLAG_HIDDEN);

    return true;
}
/**
 * 初始化电池电量显示组件
 * @return true 初始化成功，false 初始化失败
 */
static bool init_battery(lv_ui* ui)
{
    // 获取顶层图层
    lv_obj_t* top_layer = lv_layer_top();
    if (!top_layer)
    {
        return false;
    }
    //Write codes startup_page_battery
    ui->startup_page_battery = lv_obj_create(top_layer);
    lv_obj_set_pos(ui->startup_page_battery, 193, 15);
    lv_obj_set_size(ui->startup_page_battery, 35, 14);
    lv_obj_set_scrollbar_mode(ui->startup_page_battery, LV_SCROLLBAR_MODE_OFF);
    //Write style for startup_page_battery, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->startup_page_battery, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->startup_page_battery, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->startup_page_battery, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->startup_page_battery, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->startup_page_battery, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->startup_page_battery, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->startup_page_battery, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->startup_page_battery, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    //Write codes startup_page_battery_anode
    ui->startup_page_battery_anode = lv_obj_create(ui->startup_page_battery);
    lv_obj_set_pos(ui->startup_page_battery_anode, 30, 5);
    lv_obj_set_size(ui->startup_page_battery_anode, 3, 4);
    lv_obj_set_scrollbar_mode(ui->startup_page_battery_anode, LV_SCROLLBAR_MODE_OFF);
    //Write style for startup_page_battery_anode, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_radius(ui->startup_page_battery_anode, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->startup_page_battery_anode, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->startup_page_battery_anode, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->startup_page_battery_anode, lv_color_hex(0x666666), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->startup_page_battery_anode, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->startup_page_battery_anode, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->startup_page_battery_anode, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->startup_page_battery_anode, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->startup_page_battery_anode, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->startup_page_battery_anode, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    //Write codes startup_page_battery_cont
    ui->startup_page_battery_cont = lv_obj_create(ui->startup_page_battery);
    lv_obj_set_pos(ui->startup_page_battery_cont, 0, 0);
    lv_obj_set_size(ui->startup_page_battery_cont, 30, 14);
    lv_obj_set_scrollbar_mode(ui->startup_page_battery_cont, LV_SCROLLBAR_MODE_OFF);
    //Write style for startup_page_battery_cont, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->startup_page_battery_cont, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->startup_page_battery_cont, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->startup_page_battery_cont, lv_color_hex(0x666666), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->startup_page_battery_cont, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->startup_page_battery_cont, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->startup_page_battery_cont, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->startup_page_battery_cont, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->startup_page_battery_cont, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->startup_page_battery_cont, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->startup_page_battery_cont, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->startup_page_battery_cont, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui->startup_page_battery_cont, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui->startup_page_battery_cont, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui->startup_page_battery_cont, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_x(ui->startup_page_battery_cont, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_y(ui->startup_page_battery_cont, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    //Write codes startup_page_battery_value
    ui->startup_page_battery_value = lv_bar_create(ui->startup_page_battery);
    lv_obj_set_style_anim_time(ui->startup_page_battery_value, 1000, 0);
    lv_bar_set_mode(ui->startup_page_battery_value, LV_BAR_MODE_NORMAL);
    lv_bar_set_range(ui->startup_page_battery_value, 0, 100);
    lv_bar_set_value(ui->startup_page_battery_value, g_current_battery_level, LV_ANIM_OFF);
    lv_obj_set_pos(ui->startup_page_battery_value, 2, 2);
    lv_obj_set_size(ui->startup_page_battery_value, 26, 10);
    //Write style for startup_page_battery_value, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->startup_page_battery_value, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->startup_page_battery_value, lv_color_hex(0x666666), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->startup_page_battery_value, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->startup_page_battery_value, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->startup_page_battery_value, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    //Write style for startup_page_battery_value, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->startup_page_battery_value, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->startup_page_battery_value, lv_color_hex(0xffffff), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->startup_page_battery_value, LV_GRAD_DIR_NONE, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->startup_page_battery_value, 1, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    //Write codes startup_page_charge_logo
    ui->startup_page_charge_logo = lv_img_create(ui->startup_page_battery);
    lv_obj_add_flag(ui->startup_page_charge_logo, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->startup_page_charge_logo, &_charge_logo_RGB565A8_14x14);
    lv_img_set_pivot(ui->startup_page_charge_logo, 50, 50);
    lv_img_set_angle(ui->startup_page_charge_logo, 0);
    lv_obj_set_pos(ui->startup_page_charge_logo, 8, 0);
    lv_obj_set_size(ui->startup_page_charge_logo, 14, 14);
    //Write style for startup_page_charge_logo, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->startup_page_charge_logo, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->startup_page_charge_logo, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->startup_page_charge_logo, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->startup_page_charge_logo, true, LV_PART_MAIN | LV_STATE_DEFAULT);
    if (g_current_charge_status)
    {
        lv_obj_set_style_bg_color(guider_ui.startup_page_battery_value, lv_color_hex(0x34c759), LV_PART_INDICATOR | LV_STATE_DEFAULT);
        lv_obj_clear_flag(guider_ui.startup_page_charge_logo, LV_OBJ_FLAG_HIDDEN);
    }
    else
    {
        lv_obj_add_flag(guider_ui.startup_page_charge_logo, LV_OBJ_FLAG_HIDDEN);
        if (g_current_battery_level >= 20 && g_current_battery_level < 100) {
            lv_obj_set_style_bg_color(guider_ui.startup_page_battery_value, lv_color_hex(0xffffff), LV_PART_INDICATOR | LV_STATE_DEFAULT);
        }
        else if (g_current_battery_level < 20 && g_current_battery_level >= 0) {
            lv_obj_set_style_bg_color(guider_ui.startup_page_battery_value, lv_color_hex(0xff0000), LV_PART_INDICATOR | LV_STATE_DEFAULT);
        }
    }
    // 电池显示默认是可见的
    lv_obj_clear_flag(ui->startup_page_battery, LV_OBJ_FLAG_HIDDEN);
    lv_obj_clear_flag(ui->startup_page_battery, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_clear_flag(ui->startup_page_battery_anode, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_clear_flag(ui->startup_page_battery_cont, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_clear_flag(ui->startup_page_battery_value, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_clear_flag(ui->startup_page_charge_logo, LV_OBJ_FLAG_SCROLLABLE);

    return true;
}
// 播放进度更新回调函数
static void play_progress_update_cb(lv_timer_t* timer) {
    update_player_page_progress(&guider_ui);
}
/**
 * 定时器回调函数 - 更新封面图旋转角度
 * @param timer 定时器指针
 */
static void music_cover_rotation_timer_cb(lv_timer_t* timer)
{
    current_angle += 3;
    if (current_angle >= 360) {
        current_angle = 0; // 重置角度
    }

    // 设置新的角度
    lv_img_set_angle(guider_ui.home_page_music_cover, current_angle * 10); // LVGL角度单位是0.1度
}

/**
 * Create a demo application
 */
void custom_init(lv_ui *ui)
{
    /* Add your codes here */
    /* 当前播放歌曲信息初始化 */
    strcpy(g_current_play_data.song_name, "default-song-name");
    strcpy(g_current_play_data.album_name, "default-album-name");
    strcpy(g_current_play_data.cover_path, "/imgs/local_audio_icon.png");
    g_current_play_data.total_duration = 180;
    g_current_play_data.play_status = PLAY_STATUS_STOPPED;
    g_current_play_data.current_position = 0;
    g_current_play_data.song_index = 0;

    /* 当前设备信息初始化 */
    strcpy(g_current_device_info.software_version, "1.0.1");
    strcpy(g_current_device_info.firmware_version, "1.0.1");
    strcpy(g_current_device_info.latest_version, "当前已是最新版本");
    strcpy(g_current_device_info.device_name, "default device_name");
    strcpy(g_current_device_info.model_name, "default device_model");
    strcpy(g_current_device_info.device_id, "default device_id");
    strcpy(g_current_device_info.device_sn, "default device_sn");
    strcpy(g_current_device_info.total_storage, "30GB");
    strcpy(g_current_device_info.free_storage, "15GB");
    strcpy(g_current_device_info.system_storage, "系统文件 5.1GB");
    strcpy(g_current_device_info.audio_storage, "音频 8.8GB");
    strcpy(g_current_device_info.cache_storage, "缓存 1.1GB");
    g_current_device_info.total_storage_int = 30LL * 1024 * 1024 * 1024;
    g_current_device_info.free_storage_int = 15LL * 1024 * 1024 * 1024;
    g_current_device_info.system_storage_int = (long long)(5.1 * 1024 * 1024 * 1024);
    g_current_device_info.audio_storage_int = (long long)(8.8 * 1024 * 1024 * 1024);
    g_current_device_info.cache_storage_int = (long long)(1.1 * 1024 * 1024 * 1024);

    /* 当前用户信息初始化 */
    strcpy(g_current_user_info.user_phone, "default user_phone");
    strcpy(g_current_user_info.user_vip_status, "default user_vip_status");
    strcpy(g_current_user_info.user_vip_expire, "default user_vip_expire");

    /* 初始化孩子信息库 */
    init_child_info_repo();
    child_locked = false;
    is_updating = false;
    g_firmware_update_progress = 0;

    /* 蓝牙设备容器初始化 */
    bluetooth_container_init();

    /* 编码器控制分组及聚焦样式初始化 */
    today_listening_group = lv_group_create();
    recently_listening_group = lv_group_create();
    my_order_group = lv_group_create();
    local_listening_group = lv_group_create();
    local_songlist_group = lv_group_create();
    system_settings_group = lv_group_create();
    home_group = lv_group_create();
    lv_style_init(&style_focus);
    lv_style_set_outline_color(&style_focus, lv_color_hex(0xffffff));
    lv_style_set_outline_width(&style_focus, 2);
    lv_style_set_outline_opa(&style_focus, LV_OPA_90);
    lv_style_set_border_width(&style_focus, 0);

    page_init(ui);

    // 初始化电池显示
    init_battery(ui);

    // 正常流程：加载主页
    ui_load_scr_animation(&guider_ui, &guider_ui.home_page, guider_ui.home_page_del, &guider_ui.startup_page_del, setup_scr_home_page, LV_SCR_LOAD_ANIM_FADE_ON, LOAD_ANIM_TIME, 1000, false, false);
    update_home_page_content(ui);
    g_current_page = HOME_PAGE;
}
void show_toast(const char* message, uint32_t duration_ms)
{
    // 参数检查
    if (!message)
    {
        return;
    }
    // 如果已有定时器，先删除
    if (g_toast_timer)
    {
        lv_timer_del(g_toast_timer);
        g_toast_timer = NULL;
    }
    // 更新文本内容
    lv_label_set_text(g_toast_label, message);
    // 根据文本长度调整Toast容器大小
    const lv_font_t* font = lv_obj_get_style_text_font(g_toast_label, LV_PART_MAIN);
    lv_coord_t letter_space = lv_obj_get_style_text_letter_space(g_toast_label, LV_PART_MAIN);
    // 计算文本宽度，增加一些边距
    uint32_t text_width = lv_text_get_width(message, strlen(message), font, letter_space) + 40;
    // 确保Toast容器大小合适
    if (text_width > 120)
    {
        // 不超过屏幕宽度的70%
        lv_coord_t max_width = lv_disp_get_hor_res(lv_disp_get_default()) * 0.7;
        if (text_width > max_width)
        {
            text_width = max_width;
            // 设置文本换行模式
            lv_label_set_long_mode(g_toast_label, LV_LABEL_LONG_WRAP);
            lv_obj_set_size(g_toast_label, text_width - 30, LV_SIZE_CONTENT);
            lv_obj_set_size(g_toast_container, text_width, LV_SIZE_CONTENT);
        }
        else
        {
            lv_label_set_long_mode(g_toast_label, LV_LABEL_LONG_SCROLL_CIRCULAR);
            lv_obj_set_size(g_toast_container, text_width, 40);
        }
    }
    else
    {
        lv_label_set_long_mode(g_toast_label, LV_LABEL_LONG_SCROLL_CIRCULAR);
        lv_obj_set_size(g_toast_container, 120, 40);
    }
    // 确保Toast容器居中
    lv_obj_align(g_toast_container, LV_ALIGN_BOTTOM_MID, 0, -30);
    // 显示Toast
    lv_obj_clear_flag(g_toast_container, LV_OBJ_FLAG_HIDDEN);
    // 创建定时器，在指定时间后自动隐藏
    g_toast_timer = lv_timer_create(toast_hide_timer_cb, duration_ms, NULL);
    lv_timer_set_repeat_count(g_toast_timer, 1); // 只执行一次
}
void show_volume_bar(int volume)
{
    if (g_volume_bar == NULL) {
        return;
    }
    lv_bar_set_value(g_volume_bar, volume, LV_ANIM_OFF);
    lv_obj_clear_flag(g_volume_bar, LV_OBJ_FLAG_HIDDEN);

    // 如果定时器存在，先删除它（重置定时器）
    if (g_volume_bar_timer) {
        lv_timer_del(g_volume_bar_timer);
        g_volume_bar_timer = NULL;
    }

    // 创建新的定时器，2秒后自动隐藏音量条
    g_volume_bar_timer = lv_timer_create(volume_bar_hide_timer_cb, 2000, NULL);
    lv_timer_set_repeat_count(g_volume_bar_timer, 1); // 只执行一次
}
void show_battery_display(void)
{
    if (guider_ui.startup_page_battery)
    {
        lv_obj_remove_flag(guider_ui.startup_page_battery, LV_OBJ_FLAG_HIDDEN);
    }
}
void hide_battery_display(void)
{
    if (guider_ui.startup_page_battery)
    {
        lv_obj_add_flag(guider_ui.startup_page_battery, LV_OBJ_FLAG_HIDDEN);
    }
}
int save_brightness_value(int brightness_level) {
    
}
int load_brightness_value(void) {
    
}
void apply_brightness_to_ui(lv_ui* ui, int brightness_level) {

}
void apply_brightness_to_hardware(int brightness_level) {
    // 根据亮度级别计算实际的亮度值（0-255）
    int hardware_brightness;
    switch (brightness_level) {
    case -1: hardware_brightness = 0;  // 0%亮度
        break;
    case 0: hardware_brightness = 64;  // 25%亮度
        break;
    case 1: hardware_brightness = 128; // 50%亮度
        break;
    case 2: hardware_brightness = 192; // 75%亮度
        break;
    case 3: hardware_brightness = 255; // 100%亮度
        break;
    default: hardware_brightness = 192; // 默认75%亮度
    }
}
void set_screen_brightness(lv_ui* ui, int brightness_level) {
    // 保存到系统属性（持久化）
    save_brightness_value(brightness_level);

    // 应用到硬件
    apply_brightness_to_hardware(brightness_level);

    // 更新UI显示
    apply_brightness_to_ui(ui, brightness_level);
}
void start_music_cover_rotation(lv_ui* ui)
{
    if (!ui || !ui->home_page_music_cover) {
        return;
    }

    // 如果已经在旋转，先停止
    if (music_cover_rotating) {
        stop_music_cover_rotation(ui);
    }

    // 重置角度
    current_angle = 0;
    lv_img_set_angle(ui->home_page_music_cover, 0);

    // 创建定时器，每100毫秒更新一次
    music_cover_timer = lv_timer_create(music_cover_rotation_timer_cb, 100, ui);
    if (music_cover_timer) {
        music_cover_rotating = true;
    }
    else {
    }
}
void stop_music_cover_rotation(lv_ui* ui)
{
    if (!ui || !ui->home_page_music_cover) {
        return;
    }

    // 停止并删除定时器
    if (music_cover_timer) {
        lv_timer_del(music_cover_timer);
        music_cover_timer = NULL;
    }

    // 重置角度到0
    current_angle = 0;
    lv_img_set_angle(ui->home_page_music_cover, 0);

    music_cover_rotating = false;
}
