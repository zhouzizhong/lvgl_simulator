/*
* Copyright 2024 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

/*********************  PAGE MANAGER INCLUDES  *********************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lvgl.h"
#include "gui_guider.h"
#include "page_manager.h"
#include "data_manager.h"
#include "custom.h"


/**********************
 *  STATIC PROTOTYPES
 **********************/
 /**
  * 弹出页面自动关闭回调函数
  * @param timer 定时器对象
  */
static void pop_page_auto_close_cb(lv_timer_t* timer)
{
    // 返回上一页，关闭弹出页面
    return_pre_page(&guider_ui);

    // 删除定时器
    if (g_pop_page_timer)
    {
        lv_timer_del(g_pop_page_timer);
        g_pop_page_timer = NULL;
    }
}
/**
 * 显示弹出页面
 * @param ui 界面指针
 * @param pop_type 弹出页面类型
 */
static void show_pop_page(lv_ui* ui, int pop_type)
{
    // 参数有效性检查
    if (ui == NULL) {
        return;
    }

    // 如果之前有定时器，先删除
    if (g_pop_page_timer) {
        lv_timer_del(g_pop_page_timer);
        g_pop_page_timer = NULL;
    }

    // 统一使用传入的ui参数，而不是全局的guider_ui
    ui_load_scr_animation(ui, &ui->pop_page, ui->pop_page_del, &ui->home_page_del, setup_scr_pop_page, POP_LOAD_ANIM, LOAD_ANIM_TIME, LOAD_ANIM_DELAY, false, false);
    page_stack_push(g_current_page);
    g_current_page = POP_PAGE;

    // 首先隐藏所有可能显示的pop组件
    lv_obj_add_flag(ui->pop_page_battery_low_pop, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui->pop_page_charging_pop, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui->pop_page_charge_full_pop, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui->pop_page_wifi_disconnected_pop, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui->pop_page_warning_general_pop, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui->pop_page_ota_update_pop, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui->pop_page_bluetooth_disconnected_pop, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui->pop_page_child_lock_on_pop, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui->pop_page_child_lock_off_pop, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui->pop_page_storage_full_pop, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui->pop_page_headset_connected_pop, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui->pop_page_headset_disconnected_pop, LV_OBJ_FLAG_HIDDEN);

    // 根据pop_type显示对应的组件
    bool auto_close = false; // 是否需要自动关闭
    switch (pop_type) {
    case MSG_LOW_BATTERY:
        lv_obj_clear_flag(ui->pop_page_battery_low_pop, LV_OBJ_FLAG_HIDDEN);
        auto_close = true; // 3秒后自动关闭
        break;
    case MSG_CHARGING:
        lv_obj_clear_flag(ui->pop_page_charging_pop, LV_OBJ_FLAG_HIDDEN);
        auto_close = true; // 3秒后自动关闭
        break;
    case MSG_CHARGE_COMPLETE:
        lv_obj_clear_flag(ui->pop_page_charge_full_pop, LV_OBJ_FLAG_HIDDEN);
        auto_close = true; // 3秒后自动关闭
        break;
    case MSG_GENERAL_ERROR:
        lv_obj_clear_flag(ui->pop_page_warning_general_pop, LV_OBJ_FLAG_HIDDEN);
        // 一般错误需要用户手动关闭或选择重试，不自动关闭
        break;
    case MSG_WIFI_DISCONNECT:
        lv_obj_clear_flag(ui->pop_page_wifi_disconnected_pop, LV_OBJ_FLAG_HIDDEN);
        // WiFi断开需要用户选择手动关闭或检查网络，不自动关闭
        break;
    case MSG_OTA_UPDATE:
        lv_obj_clear_flag(ui->pop_page_ota_update_pop, LV_OBJ_FLAG_HIDDEN);
        // OTA更新需要用户手动关闭，不自动关闭
        break;
    case MSG_BLUETOOTH_DISCONNECT:
        lv_obj_clear_flag(ui->pop_page_bluetooth_disconnected_pop, LV_OBJ_FLAG_HIDDEN);
        // 蓝牙断开需要用户选择手动关闭或检查网络，不自动关闭
        break;
    case MSG_CHILD_LOCK_ON:
        lv_obj_clear_flag(ui->pop_page_child_lock_on_pop, LV_OBJ_FLAG_HIDDEN);
        auto_close = true; // 3秒后自动关闭
        break;
    case MSG_CHILD_LOCK_OFF:
        lv_obj_clear_flag(ui->pop_page_child_lock_off_pop, LV_OBJ_FLAG_HIDDEN);
        auto_close = true; // 3秒后自动关闭
        break;
    case MSG_STORAGE_LOW:
        lv_obj_clear_flag(ui->pop_page_storage_full_pop, LV_OBJ_FLAG_HIDDEN);
        // 存储已满需要用户处理，不自动关闭
        break;
    case MSG_BT_HEADSET_CONNECT:
        lv_obj_clear_flag(ui->pop_page_headset_connected_pop, LV_OBJ_FLAG_HIDDEN);
        auto_close = true; // 3秒后自动关闭
        break;
    case MSG_BT_HEADSET_DISCONNECT:
        lv_obj_clear_flag(ui->pop_page_headset_disconnected_pop, LV_OBJ_FLAG_HIDDEN);
        auto_close = true; // 3秒后自动关闭
        break;
    default:
        // 对于未知类型，可以显示一个默认的提示
        break;
    }

    // 如果需要自动关闭，创建3秒定时器
    if (auto_close) {
        g_pop_page_timer = lv_timer_create(pop_page_auto_close_cb, 3000, NULL);
        lv_timer_set_repeat_count(g_pop_page_timer, 1); // 只执行一次
    }
}
/**********************
 *  GLOBAL PROTOTYPES
 **********************/
void page_init(lv_ui* ui) {
    ui->startup_page_del = false;
    ui->home_page_del = false;
    ui->player_page_del = false;
    ui->today_listening_page_del = false;
    ui->recently_listening_page_del = false;
    ui->my_order_page_del = false;
    ui->local_listening_page_del = false;
    ui->local_audio_page_del = false;
    ui->system_settings_page_del = false;
    ui->account_login_page_del = false;
    ui->account_management_page_del = false;
    ui->network_and_bluetooth_page_del = false;
    ui->screen_brightness_page_del = false;
    ui->device_information_page_del = false;
    ui->wifi_connect_page_del = false;
    ui->bt_connect_page_del = false;
    ui->pop_page_del = false;

    setup_scr_startup_page(ui);
    setup_scr_home_page(ui);
    setup_scr_player_page(ui);
    setup_scr_today_listening_page(ui);
    setup_scr_local_audio_page(ui);
    setup_scr_system_settings_page(ui);
    setup_scr_account_login_page(ui);
    setup_scr_account_management_page(ui);
    setup_scr_network_and_bluetooth_page(ui);
    setup_scr_screen_brightness_page(ui);
    setup_scr_device_information_page(ui);
    setup_scr_recently_listening_page(ui);
    setup_scr_my_order_page(ui);
    setup_scr_local_listening_page(ui);
    setup_scr_pop_page(ui);
    setup_scr_wifi_connect_page(ui);
    setup_scr_bt_connect_page(ui);
}
bool return_pre_page(lv_ui* ui)
{
    // 如果当前页面是弹出页面，且存在自动关闭定时器，先删除定时器
    if (g_current_page == POP_PAGE && g_pop_page_timer) {
        lv_timer_del(g_pop_page_timer);
        g_pop_page_timer = NULL;
    }

    // 从栈中弹出上一页面
    if (!page_stack_pop(&g_pre_page)) {
        // 栈为空，无法返回
        return false;
    }
    if (g_pre_page == STARTUP_PAGE)
    {
        // ui_load_scr_animation(&guider_ui, &guider_ui.startup_page, guider_ui.startup_page_del, &guider_ui.home_page_del, setup_scr_startup_page, RETURN_LOAD_ANIM, LOAD_ANIM_TIME, LOAD_ANIM_DELAY, true, true);
    }
    else if (g_pre_page == HOME_PAGE)
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.home_page, guider_ui.home_page_del, &guider_ui.home_page_del, setup_scr_home_page, RETURN_LOAD_ANIM, LOAD_ANIM_TIME, LOAD_ANIM_DELAY, false, false);
        update_home_page_content(ui);
    }
    else if (g_pre_page == TODAY_LISTENING_PAGE)
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.today_listening_page, guider_ui.today_listening_page_del, &guider_ui.home_page_del, setup_scr_today_listening_page, RETURN_LOAD_ANIM, LOAD_ANIM_TIME, LOAD_ANIM_DELAY, false, false);
        update_song_rhythm_icon(&guider_ui, SONGLIST_TODAY, g_current_play_data.song_index);
    }
    else if (g_pre_page == RECENTLY_LISTENING_PAGE)
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.recently_listening_page, guider_ui.home_page_del, &guider_ui.player_page_del, setup_scr_today_listening_page, RETURN_LOAD_ANIM, LOAD_ANIM_TIME, LOAD_ANIM_DELAY, false, false);
        update_song_rhythm_icon(&guider_ui, SONGLIST_RECENT, g_current_play_data.song_index);
    }
    else if (g_pre_page == MY_ORDER_PAGE)
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.my_order_page, guider_ui.home_page_del, &guider_ui.player_page_del, setup_scr_today_listening_page, RETURN_LOAD_ANIM, LOAD_ANIM_TIME, LOAD_ANIM_DELAY, false, false);
        update_song_rhythm_icon(&guider_ui, SONGLIST_MY, g_current_play_data.song_index);
    }
    else if (g_pre_page == LOCAL_LISTENING_PAGE)
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.local_listening_page, guider_ui.local_listening_page_del, &guider_ui.home_page_del, setup_scr_account_management_page, RETURN_LOAD_ANIM, LOAD_ANIM_TIME, LOAD_ANIM_DELAY, false, false);
        update_song_rhythm_icon(&guider_ui, SONGLIST_LOCAL, g_current_play_data.song_index);
    }
    else if (g_pre_page == LOCAL_AUDIO_PAGE)
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.local_audio_page, guider_ui.local_audio_page_del, &guider_ui.home_page_del, setup_scr_local_audio_page, RETURN_LOAD_ANIM, LOAD_ANIM_TIME, LOAD_ANIM_DELAY, false, false);
    }
    else if (g_pre_page == PLAYER_PAGE)
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.player_page, guider_ui.player_page_del, &guider_ui.home_page_del, setup_scr_player_page, POP_LOAD_ANIM, LOAD_ANIM_TIME, LOAD_ANIM_DELAY, false, false);
        update_player_page_content(ui);
        hide_battery_display();
    }
    else if (g_pre_page == DEVICE_INFORMATION_PAGE)
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.device_information_page, guider_ui.device_information_page_del, &guider_ui.home_page_del, setup_scr_device_information_page, POP_LOAD_ANIM, LOAD_ANIM_TIME, LOAD_ANIM_DELAY, false, false);
    }
    else if (g_pre_page == SCREEN_BRIGHTNESS_PAGE)
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.screen_brightness_page, guider_ui.screen_brightness_page_del, &guider_ui.home_page_del, setup_scr_screen_brightness_page, POP_LOAD_ANIM, LOAD_ANIM_TIME, LOAD_ANIM_DELAY, false, false);
    }
    else if (g_pre_page == SYSTEM_SETTINGS_PAGE)
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.system_settings_page, guider_ui.system_settings_page_del, &guider_ui.home_page_del, setup_scr_system_settings_page, RETURN_LOAD_ANIM, LOAD_ANIM_TIME, LOAD_ANIM_DELAY, false, false);
    }
    else if (g_pre_page == ACCOUNT_LOGIN_PAGE)
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.account_login_page, guider_ui.account_login_page_del, &guider_ui.home_page_del, setup_scr_account_login_page, POP_LOAD_ANIM, LOAD_ANIM_TIME, LOAD_ANIM_DELAY, false, false);
    }
    else if (g_pre_page == BT_CONNECT_PAGE)
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.bt_connect_page, guider_ui.bt_connect_page_del, &guider_ui.home_page_del, setup_scr_bt_connect_page, POP_LOAD_ANIM, LOAD_ANIM_TIME, LOAD_ANIM_DELAY, false, false);
    }
    else if (g_pre_page == WIFI_CONNECT_PAGE)
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.wifi_connect_page, guider_ui.wifi_connect_page_del, &guider_ui.home_page_del, setup_scr_wifi_connect_page, POP_LOAD_ANIM, LOAD_ANIM_TIME, LOAD_ANIM_DELAY, false, false);
    }
    else if (g_pre_page == ACCOUNT_MANAGEMENT_PAGE)
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.account_management_page, guider_ui.account_management_page_del, &guider_ui.home_page_del, setup_scr_account_management_page, POP_LOAD_ANIM, LOAD_ANIM_TIME, LOAD_ANIM_DELAY, false, false);
    }
    else if (g_pre_page == NETWORK_AND_BLUETOOTH_PAGE)
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.network_and_bluetooth_page, guider_ui.network_and_bluetooth_page_del, &guider_ui.home_page_del, setup_scr_network_and_bluetooth_page, POP_LOAD_ANIM, LOAD_ANIM_TIME, LOAD_ANIM_DELAY, false, false);
        if (is_bt_connected)
        {
            lv_label_set_text(ui->network_and_bluetooth_page_bt_pair_up_title, bt_name);
        }
        else
        {
            lv_label_set_text(ui->network_and_bluetooth_page_bt_pair_up_title, "扫码配对");
        }
        if (is_wifi_connected)
        {
            lv_label_set_text(ui->network_and_bluetooth_page_wifi_pair_up_title, wifi_name);
        }
        else
        {
            lv_label_set_text(ui->network_and_bluetooth_page_wifi_pair_up_title, "扫码配对");
        }
    }
    g_current_page = g_pre_page;

    return true;
}
void page_stack_init(void) {
    g_page_stack.top = -1;
}
bool page_stack_is_empty(void) {
    return g_page_stack.top == -1;
}
bool page_stack_is_full(void) {
    return g_page_stack.top >= PAGE_STACK_SIZE - 1;
}
bool page_stack_push(int page_id) {
    if (page_stack_is_full()) {
        return false;  // 栈已满，入栈失败
    }

    g_page_stack.top++;
    g_page_stack.stack[g_page_stack.top] = page_id;
    return true;
}
bool page_stack_pop(int* page_id) {
    if (page_stack_is_empty()) {
        return false;  // 栈为空，出栈失败
    }

    *page_id = g_page_stack.stack[g_page_stack.top];
    g_page_stack.top--;
    return true;
}
void page_stack_clear(void) {
    g_page_stack.top = -1;
}
void songlist_load(lv_ui* ui, int load_songlist, bool* old_scr_del)
{
    if (load_songlist == SONGLIST_TODAY)
    {
        if (lv_obj_get_child_cnt(ui->today_listening_page_list) > 6)
        {
            today_songlist_load_flag = 1;
        }
        if (today_songlist_load_flag == 0)
        {
            ui_load_scr_animation(&guider_ui, &guider_ui.today_listening_page, guider_ui.today_listening_page_del, old_scr_del, setup_scr_today_listening_page, NEXT_LOAD_ANIM, LOAD_ANIM_TIME, LOAD_ANIM_DELAY, false, false);
            // 今日熏听初始化
            add_songs_to_today_listening(ui, 6);
            if (lv_obj_get_child_cnt(ui->today_listening_page_list) == 0)
            {
                lv_obj_clear_flag(ui->today_listening_page_no_song, LV_OBJ_FLAG_HIDDEN);
                lv_obj_add_flag(ui->today_listening_page_list, LV_OBJ_FLAG_HIDDEN);
            }
            else
            {
                lv_obj_add_flag(ui->today_listening_page_no_song, LV_OBJ_FLAG_HIDDEN);
                lv_obj_clear_flag(ui->today_listening_page_list, LV_OBJ_FLAG_HIDDEN);
            }
        }
        else
        {
            ui_load_scr_animation(&guider_ui, &guider_ui.today_listening_page, guider_ui.today_listening_page_del, old_scr_del, setup_scr_today_listening_page, NEXT_LOAD_ANIM, LOAD_ANIM_TIME, LOAD_ANIM_DELAY, false, false);
        }
        page_stack_push(g_current_page);
        g_current_page = TODAY_LISTENING_PAGE;
    }
    else if (load_songlist == SONGLIST_RECENT)
    {
        if (lv_obj_get_child_cnt(ui->recently_listening_page_list) >= 6)
        {
            recently_songlist_load_flag = 1;
        }
        if (recently_songlist_load_flag == 0)
        {
            ui_load_scr_animation(&guider_ui, &guider_ui.recently_listening_page, guider_ui.recently_listening_page_del, old_scr_del, setup_scr_recently_listening_page, NEXT_LOAD_ANIM, LOAD_ANIM_TIME, LOAD_ANIM_DELAY, false, false);
            // 最近熏听初始化
            add_songs_to_recent_listening(ui, 6);
            if (lv_obj_get_child_cnt(ui->recently_listening_page_list) == 0)
            {
                lv_obj_clear_flag(ui->recently_listening_page_no_song, LV_OBJ_FLAG_HIDDEN);
                lv_obj_add_flag(ui->recently_listening_page_list, LV_OBJ_FLAG_HIDDEN);
            }
            else
            {
                lv_obj_add_flag(ui->recently_listening_page_no_song, LV_OBJ_FLAG_HIDDEN);
                lv_obj_clear_flag(ui->recently_listening_page_list, LV_OBJ_FLAG_HIDDEN);
            }
        }
        else
        {
            ui_load_scr_animation(&guider_ui, &guider_ui.recently_listening_page, guider_ui.recently_listening_page_del, old_scr_del, setup_scr_recently_listening_page, NEXT_LOAD_ANIM, LOAD_ANIM_TIME, LOAD_ANIM_DELAY, false, false);
        }
        page_stack_push(g_current_page);
        g_current_page = RECENTLY_LISTENING_PAGE;
    }
    else if (load_songlist == SONGLIST_MY)
    {
        if (lv_obj_get_child_cnt(ui->my_order_page_list) > 6)
        {
            my_songlist_load_flag = 1;
        }
        if (my_songlist_load_flag == 0)
        {
            ui_load_scr_animation(&guider_ui, &guider_ui.my_order_page, guider_ui.my_order_page_del, old_scr_del, setup_scr_my_order_page, NEXT_LOAD_ANIM, LOAD_ANIM_TIME, LOAD_ANIM_DELAY, false, false);
            // 我的听单初始化
            add_songs_to_my_listening(ui, 6);
            if (lv_obj_get_child_cnt(ui->my_order_page_list) == 0)
            {
                lv_obj_clear_flag(ui->my_order_page_no_song, LV_OBJ_FLAG_HIDDEN);
                lv_obj_add_flag(ui->my_order_page_list, LV_OBJ_FLAG_HIDDEN);
            }
            else
            {
                lv_obj_add_flag(ui->my_order_page_no_song, LV_OBJ_FLAG_HIDDEN);
                lv_obj_clear_flag(ui->my_order_page_list, LV_OBJ_FLAG_HIDDEN);
            }
        }
        else
        {
            ui_load_scr_animation(&guider_ui, &guider_ui.my_order_page, guider_ui.my_order_page_del, old_scr_del, setup_scr_my_order_page, NEXT_LOAD_ANIM, LOAD_ANIM_TIME, LOAD_ANIM_DELAY, false, false);
        }
        page_stack_push(g_current_page);
        g_current_page = MY_ORDER_PAGE;
    }
    update_song_rhythm_icon(ui, load_songlist, g_current_play_data.song_index);
}
void update_home_page_content(lv_ui* ui) {
    if (ui == NULL || ui->home_page == NULL) {
        return;
    }
    if (g_current_play_data.play_status == PLAY_STATUS_PLAYING)
    {
        // 设置为选中状态（显示暂停图标）
        lv_obj_add_state(ui->home_page_play_button, LV_STATE_CHECKED);
        start_music_cover_rotation(ui);
    }
    else if (g_current_play_data.play_status == PLAY_STATUS_STOPPED)
    {
        // 设置为未选中状态（显示播放图标）
        lv_obj_clear_state(ui->home_page_play_button, LV_STATE_CHECKED);
        stop_music_cover_rotation(ui);
    }
    lv_label_set_text(ui->home_page_song_title, g_current_play_data.song_name);
    lv_img_set_src(ui->home_page_music_cover, g_current_play_data.cover_path);
}
void update_player_page_content(lv_ui* ui)
{
    if (!ui)
        return;
    if (!ui->player_page)
        return;

    //根据当前歌曲信息更新播放页面
    lv_label_set_text(ui->player_page_song_title, g_current_play_data.song_name);
    lv_label_set_text(ui->player_page_album_title, g_current_play_data.album_name);
    lv_img_set_src(ui->player_page_music_cover, g_current_play_data.cover_path);
}
void update_player_page_progress(lv_ui* ui) {
    // 更新进度条
    if (ui->player_page_music_progress_bar != NULL) {
        if (g_current_play_data.total_duration > 0) {
            lv_bar_set_value(ui->player_page_music_progress_bar, g_current_play_data.current_position, LV_ANIM_OFF);
        }
    }
}
void update_song_rhythm_icon(lv_ui* ui, int songlist, int current_song_index)
{
    lv_obj_t* list_container = NULL;

    // 检查UI指针是否有效
    if (!ui) {
        return;
    }

    // 根据歌单类型获取对应的容器
    switch (songlist) {
    case SONGLIST_TODAY:
        list_container = ui->today_listening_page_list;
        break;
    case SONGLIST_RECENT:
        list_container = ui->recently_listening_page_list;
        break;
    case SONGLIST_MY:
        list_container = ui->my_order_page_list;
        break;
    case SONGLIST_LOCAL:
        list_container = ui->local_listening_page_list;
        break;
    default:
        return;
    }

    if (!list_container) {
        return;
    }

    // 遍历歌单容器中的所有子项
    uint32_t child_cnt = lv_obj_get_child_cnt(list_container);
    for (uint32_t i = 0; i < child_cnt; i++) {
        lv_obj_t* song_container = lv_obj_get_child(list_container, i);
        if (!song_container) continue;

        // 获取歌曲索引（通过用户数据）
        intptr_t song_index = (intptr_t)lv_obj_get_user_data(song_container);

        // 查找旋律图标和歌曲标题（假设它们是容器的子项）
        lv_obj_t* rhythm_icon = NULL;
        lv_obj_t* song_title = NULL;
        lv_obj_t* album_title = NULL;

        // 遍历歌曲容器的子项来找到旋律图标和标题
        uint32_t song_child_cnt = lv_obj_get_child_cnt(song_container);
        for (uint32_t j = 0; j < song_child_cnt; j++) {
            lv_obj_t* child = lv_obj_get_child(song_container, j);
            if (!child) continue;

            // 检查是否是旋律图标（通过大小和位置判断）
            lv_coord_t width = lv_obj_get_width(child);
            lv_coord_t height = lv_obj_get_height(child);
            lv_coord_t x = lv_obj_get_x(child);

            if (width == 22 && height == 22 && x == 56) {
                rhythm_icon = child;
            }
            // 检查是否是歌曲标题（通过大小判断）
            else if (width == 122 && height == 25) {
                song_title = child;
            }
            // 检查是否是专辑标题（通过大小判断）
            else if (width == 144 && height == 20) {
                album_title = child;
            }
        }

        if (rhythm_icon && song_title) {
            if (song_index == current_song_index) {
                // 显示当前播放歌曲的旋律图标，并调整标题位置
                lv_obj_clear_flag(rhythm_icon, LV_OBJ_FLAG_HIDDEN);
                lv_obj_set_pos(song_title, 78, 11);
                lv_label_set_long_mode(song_title, LV_LABEL_LONG_SCROLL_CIRCULAR);
                lv_obj_set_style_text_opa(song_title, LV_OPA_100, LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_label_set_long_mode(album_title, LV_LABEL_LONG_SCROLL_CIRCULAR);
                lv_obj_set_style_anim_duration(song_title, LABLE_SCROLL_SPEED, LV_PART_MAIN);
                lv_obj_set_style_anim_duration(album_title, LABLE_SCROLL_SPEED, LV_PART_MAIN);
            }
            else {
                // 隐藏其他歌曲的旋律图标，恢复标题位置
                lv_obj_add_flag(rhythm_icon, LV_OBJ_FLAG_HIDDEN);
                // 恢复标题到原始位置
                lv_obj_set_pos(song_title, 56, 12);
                lv_label_set_long_mode(song_title, LV_LABEL_LONG_DOT);
                lv_obj_set_style_text_opa(song_title, LV_OPA_90, LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_label_set_long_mode(album_title, LV_LABEL_LONG_DOT);
            }
        }
    }
}
void update_device_info(lv_ui* ui)
{
    lv_label_set_text(ui->device_information_page_storage_space, g_current_device_info.total_storage);
    lv_label_set_text(ui->device_information_page_available_space, g_current_device_info.free_storage);
    lv_label_set_text(ui->device_information_page_system_file_size, g_current_device_info.system_storage);
    lv_label_set_text(ui->device_information_page_audio_file_size, g_current_device_info.audio_storage);
    lv_label_set_text(ui->device_information_page_cache_file_size, g_current_device_info.cache_storage);
    lv_label_set_text(ui->device_information_page_device_name, g_current_device_info.device_name);
    lv_label_set_text(ui->device_information_page_device_model, g_current_device_info.model_name);
    lv_label_set_text(ui->device_information_page_firmware_version, g_current_device_info.firmware_version);
    lv_label_set_text(ui->device_information_page_device_number, g_current_device_info.device_id);
    lv_label_set_text(ui->device_information_page_sn_code, g_current_device_info.device_sn);
    lv_bar_set_range(ui->device_information_page_system_file_bar, 0, g_current_device_info.total_storage_int);
    lv_bar_set_value(ui->device_information_page_system_file_bar, g_current_device_info.system_storage_int, LV_ANIM_OFF);
    lv_bar_set_range(ui->device_information_page_audio_file_bar, 0, g_current_device_info.total_storage_int);
    lv_bar_set_value(ui->device_information_page_audio_file_bar, g_current_device_info.audio_storage_int + g_current_device_info.system_storage_int, LV_ANIM_OFF);
    lv_bar_set_range(ui->device_information_page_cache_file_bar, 0, g_current_device_info.total_storage_int);
    lv_bar_set_value(ui->device_information_page_cache_file_bar, g_current_device_info.cache_storage_int + g_current_device_info.system_storage_int + g_current_device_info.audio_storage_int, LV_ANIM_OFF);
}

void update_account_management_page(lv_ui* ui)
{
    if (g_child_info_repo.count == 0)
    {
        lv_label_set_text(ui->account_management_page_sub_account_name_1, "小橘子");
        lv_img_set_src(ui->account_management_page_child_icon_1, "/imgs/test_1.png");
    }
    else if (g_child_info_repo.count == 1)
    {
        lv_obj_add_flag(ui->account_management_page_container_2, LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(ui->account_management_page_container_3, LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_flag(ui->account_management_page_container_1, LV_OBJ_FLAG_HIDDEN);
        lv_label_set_text(ui->account_management_page_sub_account_name_1, g_child_info_repo.children[0].child_nickname);
        lv_img_set_src(ui->account_management_page_child_icon_1, g_child_info_repo.children[0].child_avatar);
    }
    else if (g_child_info_repo.count == 2)
    {
        lv_obj_add_flag(ui->account_management_page_container_1, LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_flag(ui->account_management_page_container_2, LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_flag(ui->account_management_page_container_3, LV_OBJ_FLAG_HIDDEN);
        if (g_log_child == 0)
        {
            lv_obj_clear_flag(ui->account_management_page_ic_download_done_icon_2, LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_flag(ui->account_management_page_ic_download_done_icon_3, LV_OBJ_FLAG_HIDDEN);
            lv_obj_set_style_text_opa(ui->account_management_page_sub_account_name_2, LV_OPA_100, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(ui->account_management_page_sub_account_name_3, LV_OPA_70, LV_PART_MAIN | LV_STATE_DEFAULT);
            strcpy(g_current_child_info.child_id, g_child_info_repo.children[0].child_id);
            strcpy(g_current_child_info.child_nickname, g_child_info_repo.children[0].child_nickname);
            strcpy(g_current_child_info.child_avatar, g_child_info_repo.children[0].child_avatar);
            g_current_child_info.child_gender = g_child_info_repo.children[0].child_gender;
        }
        else if (g_log_child == 1)
        {
            lv_obj_add_flag(ui->account_management_page_ic_download_done_icon_2, LV_OBJ_FLAG_HIDDEN);
            lv_obj_clear_flag(ui->account_management_page_ic_download_done_icon_3, LV_OBJ_FLAG_HIDDEN);
            lv_obj_set_style_text_opa(ui->account_management_page_sub_account_name_2, LV_OPA_70, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(ui->account_management_page_sub_account_name_3, LV_OPA_100, LV_PART_MAIN | LV_STATE_DEFAULT);
            strcpy(g_current_child_info.child_id, g_child_info_repo.children[1].child_id);
            strcpy(g_current_child_info.child_nickname, g_child_info_repo.children[1].child_nickname);
            strcpy(g_current_child_info.child_avatar, g_child_info_repo.children[1].child_avatar);
            g_current_child_info.child_gender = g_child_info_repo.children[1].child_gender;
        }
        lv_label_set_text(ui->account_management_page_sub_account_name_2, g_child_info_repo.children[0].child_nickname);
        lv_img_set_src(ui->account_management_page_child_icon_2, g_child_info_repo.children[0].child_avatar);
        lv_label_set_text(ui->account_management_page_sub_account_name_3, g_child_info_repo.children[1].child_nickname);
        lv_img_set_src(ui->account_management_page_child_icon_3, g_child_info_repo.children[1].child_avatar);
    }

    lv_label_set_text(ui->account_management_page_phone_number, g_current_user_info.user_phone);
    lv_label_set_text(ui->account_management_page_account_validity_period, g_current_user_info.user_vip_expire);
}
void pop_battery_level(void)
{
    // 静态标志位，用于控制提示只显示一次
    static bool low_battery_shown = false;
    static bool full_battery_shown = false;
    lv_bar_set_value(guider_ui.startup_page_battery_value, g_current_battery_level, LV_ANIM_OFF);
    // 当电量变化时，检查是否需要清除标志位
    if (g_pre_battery_level != g_current_battery_level) {
        // 如果电量从低于20%变为高于20%，清除低电量标志位
        if (g_pre_battery_level < 20 && g_current_battery_level > 20) {
            low_battery_shown = false;
        }
        // 如果电量从高于100%变为低于100%，清除满电标志位
        if (g_pre_battery_level >= 100 && g_current_battery_level < 100) {
            full_battery_shown = false;
        }
        if (g_current_battery_level >= 20 && g_current_battery_level < 100 && g_current_charge_status == 0) {
            lv_obj_set_style_bg_color(guider_ui.startup_page_battery_value, lv_color_hex(0xffffff), LV_PART_INDICATOR | LV_STATE_DEFAULT);
        }
        else if (g_current_battery_level < 20 && g_current_battery_level >= 0 && g_current_charge_status == 0) {
            lv_obj_set_style_bg_color(guider_ui.startup_page_battery_value, lv_color_hex(0xff0000), LV_PART_INDICATOR | LV_STATE_DEFAULT);
        }
    }
    // 电量低于20%且未显示过低电量提示
    if (g_current_battery_level < 20 && !low_battery_shown) {
        show_pop_page(&guider_ui, MSG_LOW_BATTERY);
        low_battery_shown = true;
    }
    // 电量高于100%且未显示过满电提示
    else if (g_current_battery_level >= 100 && !full_battery_shown) {
        show_pop_page(&guider_ui, MSG_CHARGE_COMPLETE);
        full_battery_shown = true;
    }
}
void pop_charge_status(void)
{
    // 检查充电状态是否从未充电变为充电
    if (g_pre_charge_status == 0 && g_current_charge_status == 1) {
        // 从未充电变为充电，显示充电提示弹出页面
        show_pop_page(&guider_ui, MSG_CHARGING);
        lv_obj_set_style_bg_color(guider_ui.startup_page_battery_value, lv_color_hex(0x34c759), LV_PART_INDICATOR | LV_STATE_DEFAULT);
        lv_obj_clear_flag(guider_ui.startup_page_charge_logo, LV_OBJ_FLAG_HIDDEN);
    }
    else if (g_pre_charge_status == 1 && g_current_charge_status == 0) {
        // 从充电变为未充电，隐藏充电提示弹出页面
        lv_obj_add_flag(guider_ui.startup_page_charge_logo, LV_OBJ_FLAG_HIDDEN);
        if (g_current_battery_level >= 20 && g_current_battery_level < 100) {
            lv_obj_set_style_bg_color(guider_ui.startup_page_battery_value, lv_color_hex(0xffffff), LV_PART_INDICATOR | LV_STATE_DEFAULT);
        }
        else if (g_current_battery_level < 20 && g_current_battery_level >= 0) {
            lv_obj_set_style_bg_color(guider_ui.startup_page_battery_value, lv_color_hex(0xff0000), LV_PART_INDICATOR | LV_STATE_DEFAULT);
        }
        if (g_current_page == POP_PAGE)
        {
            return_pre_page(&guider_ui);
            show_battery_display();
            // 删除定时器
            if (g_pop_page_timer)
            {
                lv_timer_del(g_pop_page_timer);
                g_pop_page_timer = NULL;
            }
        }
    }
}
void pop_storage_low(void)
{
    if (g_current_page != DEVICE_INFORMATION_PAGE && g_current_page != POP_PAGE)
    {
        show_pop_page(&guider_ui, MSG_STORAGE_LOW);
    }
}
void pop_general_error(void)
{
    show_pop_page(&guider_ui, MSG_GENERAL_ERROR);
}
void pop_wifi_disconnect(void)
{
    show_pop_page(&guider_ui, MSG_WIFI_DISCONNECT);
}
void pop_bluetooth_disconnect(void)
{
    show_pop_page(&guider_ui, MSG_BLUETOOTH_DISCONNECT);
}
void pop_ota_update(void)
{
    show_pop_page(&guider_ui, MSG_OTA_UPDATE);
}
void pop_child_lock_on(void)
{
    show_pop_page(&guider_ui, MSG_CHILD_LOCK_ON);
}
void pop_child_lock_off(void)
{
    show_pop_page(&guider_ui, MSG_CHILD_LOCK_OFF);
}
void pop_bt_headset_connect(void)
{
    show_pop_page(&guider_ui, MSG_BT_HEADSET_CONNECT);
}
void pop_bt_headset_disconnect(void)
{
    show_pop_page(&guider_ui, MSG_BT_HEADSET_DISCONNECT);
}
void show_local_page(lv_ui* ui, int is_localsong_exists)
{
    if (is_localsong_exists)
    {
        lv_obj_add_flag(ui->local_audio_page_mask, LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(ui->local_audio_page_tips, LV_OBJ_FLAG_HIDDEN);
        add_local_playlists_to_page(ui, &g_local_folder_repo);
    }
    else
    {
        lv_obj_add_flag(ui->local_audio_page_subpage_entry, LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_flag(ui->local_audio_page_mask, LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_flag(ui->local_audio_page_tips, LV_OBJ_FLAG_HIDDEN);
    }
}
