/*
* Copyright 2026 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "events_init.h"
#include <stdio.h>
#include "lvgl.h"

#if LV_USE_GUIDER_SIMULATOR && LV_USE_FREEMASTER
#include "freemaster_client.h"
#endif

#include <stdlib.h>
#include <unistd.h>
#include "custom.h"
#include "data_manager.h"
#include "page_manager.h"

static void home_page_subpage_entry_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_SCROLL:
    {
        lv_coord_t current_scroll_x = lv_obj_get_scroll_x(guider_ui.home_page_subpage_entry);
        for (int i = 0; i < 13; i++)
        {
            // 子元素自身的宽度中心
            int child_center = lv_obj_get_x(children[i]) + 70 - current_scroll_x;

            // 子元素中心与容器中心的差值（绝对坐标差值）
            int diff = child_center - 120;
            diff = LV_ABS(diff); // 取绝对值（LVGL提供的工具函数）

            // 计算Y偏移并设置
            int y_offset = diff / 17;
            lv_obj_set_y(children[i], y_offset);
        }
        break;
    }
    case LV_EVENT_SCROLL_END:
    {
        if (lv_obj_get_scroll_x(guider_ui.home_page_subpage_entry) <= -890)
        {
            lv_obj_scroll_to_x(guider_ui.home_page_subpage_entry, 0, LV_ANIM_OFF);
        }
        else if (lv_obj_get_scroll_x(guider_ui.home_page_subpage_entry) >= 890)
        {
            lv_obj_scroll_to_x(guider_ui.home_page_subpage_entry, 0, LV_ANIM_OFF);
        }

        // 回滚聚焦
        if (lv_obj_get_scroll_x(guider_ui.home_page_subpage_entry) == -712) {
            lv_group_focus_obj(guider_ui.home_page_recently_listening_1);
        }
        else if (lv_obj_get_scroll_x(guider_ui.home_page_subpage_entry) == -534)
        {
            lv_group_focus_obj(guider_ui.home_page_my_order_1);
        }
        else if (lv_obj_get_scroll_x(guider_ui.home_page_subpage_entry) == -356)
        {
            lv_group_focus_obj(guider_ui.home_page_system_settings);
        }
        else if (lv_obj_get_scroll_x(guider_ui.home_page_subpage_entry) == -178)
        {
            lv_group_focus_obj(guider_ui.home_page_local_audio);
        }
        else if (lv_obj_get_scroll_x(guider_ui.home_page_subpage_entry) == 0)
        {
            lv_group_focus_obj(guider_ui.home_page_today_listening);
        }
        else if (lv_obj_get_scroll_x(guider_ui.home_page_subpage_entry) == 178)
        {
            lv_group_focus_obj(guider_ui.home_page_recently_listening);
        }
        else if (lv_obj_get_scroll_x(guider_ui.home_page_subpage_entry) == 356)
        {
            lv_group_focus_obj(guider_ui.home_page_my_order);
        }
        else if (lv_obj_get_scroll_x(guider_ui.home_page_subpage_entry) == 534)
        {
            lv_group_focus_obj(guider_ui.home_page_system_settings_1);
        }
        else if (lv_obj_get_scroll_x(guider_ui.home_page_subpage_entry) == 712)
        {
            lv_group_focus_obj(guider_ui.home_page_local_audio_2);
        }
        break;
    }
    default:
        break;
    }
}

static void home_page_system_settings_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        page_stack_push(g_current_page);
        g_current_page = SYSTEM_SETTINGS_PAGE;
        ui_load_scr_animation(&guider_ui, &guider_ui.system_settings_page, guider_ui.system_settings_page_del, &guider_ui.home_page_del, setup_scr_system_settings_page, NEXT_LOAD_ANIM, LOAD_ANIM_TIME, LOAD_ANIM_DELAY, false, false);
        if (!is_latest_version)
        {
            lv_label_set_text(guider_ui.system_settings_page_version_update_information, g_current_device_info.latest_version);
        } else
        {
            lv_label_set_text(guider_ui.system_settings_page_version_update_information, "当前已是最新版本");
        }
        break;
    }
    default:
        break;
    }
}

static void home_page_system_settings_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        page_stack_push(g_current_page);
        g_current_page = SYSTEM_SETTINGS_PAGE;
        ui_load_scr_animation(&guider_ui, &guider_ui.system_settings_page, guider_ui.system_settings_page_del, &guider_ui.home_page_del, setup_scr_system_settings_page, NEXT_LOAD_ANIM, LOAD_ANIM_TIME, LOAD_ANIM_DELAY, false, false);
        if (!is_latest_version)
        {
            lv_label_set_text(guider_ui.system_settings_page_version_update_information, g_current_device_info.latest_version);
        } else
        {
            lv_label_set_text(guider_ui.system_settings_page_version_update_information, "当前已是最新版本");
        }
        break;
    }
    default:
        break;
    }
}

static void home_page_local_audio_2_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        lv_ui* ui = lv_event_get_user_data(e);
        page_stack_push(g_current_page);
        g_current_page = LOCAL_AUDIO_PAGE;
        ui_load_scr_animation(&guider_ui, &guider_ui.local_audio_page, guider_ui.local_audio_page_del, &guider_ui.home_page_del, setup_scr_local_audio_page, NEXT_LOAD_ANIM, LOAD_ANIM_TIME, LOAD_ANIM_DELAY, false, false);
        is_localsong_exists = 0;
        // 本地音乐读取
        scan_musicdir();
        show_local_page(ui, is_localsong_exists);
        break;
    }
    default:
        break;
    }
}

static void home_page_local_audio_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        lv_ui* ui = lv_event_get_user_data(e);
        page_stack_push(g_current_page);
        g_current_page = LOCAL_AUDIO_PAGE;
        ui_load_scr_animation(&guider_ui, &guider_ui.local_audio_page, guider_ui.local_audio_page_del, &guider_ui.home_page_del, setup_scr_local_audio_page, NEXT_LOAD_ANIM, LOAD_ANIM_TIME, LOAD_ANIM_DELAY, false, false);
        is_localsong_exists = 0;
        // 本地音乐读取
        scan_musicdir();
        show_local_page(ui, is_localsong_exists);
        break;
    }
    default:
        break;
    }
}

static void home_page_local_audio_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        lv_ui* ui = lv_event_get_user_data(e);
        page_stack_push(g_current_page);
        g_current_page = LOCAL_AUDIO_PAGE;
        ui_load_scr_animation(&guider_ui, &guider_ui.local_audio_page, guider_ui.local_audio_page_del, &guider_ui.home_page_del, setup_scr_local_audio_page, NEXT_LOAD_ANIM, LOAD_ANIM_TIME, LOAD_ANIM_DELAY, false, false);
        is_localsong_exists = 0;
        // 本地音乐读取
        scan_musicdir();
        show_local_page(ui, is_localsong_exists);
        break;
    }
    default:
        break;
    }
}

static void home_page_my_order_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        lv_ui* ui = lv_event_get_user_data(e);
        //我的听单
        songlist_load(ui, SONGLIST_MY, &guider_ui.home_page_del);
        break;
    }
    default:
        break;
    }
}

static void home_page_my_order_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        lv_ui* ui = lv_event_get_user_data(e);
        //我的听单
        songlist_load(ui, SONGLIST_MY, &guider_ui.home_page_del);
        break;
    }
    default:
        break;
    }
}

static void home_page_recently_listening_2_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        lv_ui* ui = lv_event_get_user_data(e);
        //最近熏听
        songlist_load(ui, SONGLIST_RECENT, &guider_ui.home_page_del);
        break;
    }
    default:
        break;
    }
}

static void home_page_recently_listening_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        lv_ui* ui = lv_event_get_user_data(e);
        //最近熏听
        songlist_load(ui, SONGLIST_RECENT, &guider_ui.home_page_del);
        break;
    }
    default:
        break;
    }
}

static void home_page_recently_listening_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        lv_ui* ui = lv_event_get_user_data(e);
        //最近熏听
        songlist_load(ui, SONGLIST_RECENT, &guider_ui.home_page_del);
        break;
    }
    default:
        break;
    }
}

static void home_page_today_listening_2_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        lv_ui* ui = lv_event_get_user_data(e);
        //今日熏听
        songlist_load(ui, SONGLIST_TODAY, &guider_ui.home_page_del);
        break;
    }
    default:
        break;
    }
}

static void home_page_today_listening_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        lv_ui* ui = lv_event_get_user_data(e);
        //今日熏听
        songlist_load(ui, SONGLIST_TODAY, &guider_ui.home_page_del);
        break;
    }
    default:
        break;
    }
}

static void home_page_today_listening_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        lv_ui* ui = lv_event_get_user_data(e);
        //今日熏听
        songlist_load(ui, SONGLIST_TODAY, &guider_ui.home_page_del);
        break;
    }
    default:
        break;
    }
}

static void home_page_quick_play_panel_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        lv_ui* ui = lv_event_get_user_data(e);
        ui_load_scr_animation(&guider_ui, &guider_ui.player_page,
                              guider_ui.player_page_del, &guider_ui.home_page_del,
                              setup_scr_player_page, NEXT_LOAD_ANIM, LOAD_ANIM_TIME, LOAD_ANIM_DELAY, false, false);
        page_stack_push(g_current_page);
        g_current_page = PLAYER_PAGE;
        update_player_page_content(ui);
        hide_battery_display();
        break;
    }
    default:
        break;
    }
}

void events_init_home_page (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->home_page_subpage_entry, home_page_subpage_entry_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->home_page_system_settings_1, home_page_system_settings_1_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->home_page_system_settings, home_page_system_settings_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->home_page_local_audio_2, home_page_local_audio_2_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->home_page_local_audio_1, home_page_local_audio_1_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->home_page_local_audio, home_page_local_audio_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->home_page_my_order_1, home_page_my_order_1_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->home_page_my_order, home_page_my_order_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->home_page_recently_listening_2, home_page_recently_listening_2_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->home_page_recently_listening_1, home_page_recently_listening_1_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->home_page_recently_listening, home_page_recently_listening_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->home_page_today_listening_2, home_page_today_listening_2_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->home_page_today_listening_1, home_page_today_listening_1_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->home_page_today_listening, home_page_today_listening_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->home_page_quick_play_panel, home_page_quick_play_panel_event_handler, LV_EVENT_ALL, ui);
}

static void player_page_list_button_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        lv_ui* ui = lv_event_get_user_data(e);
        if (g_cur_songlist == TODAY_LISTENING_PAGE)
        {
            songlist_load(ui, SONGLIST_TODAY, &guider_ui.player_page_del);
        }
        else if (g_cur_songlist == RECENTLY_LISTENING_PAGE)
        {
            songlist_load(ui, SONGLIST_RECENT, &guider_ui.player_page_del);
        }
        else if (g_cur_songlist == MY_ORDER_PAGE)
        {
            songlist_load(ui, SONGLIST_MY, &guider_ui.player_page_del);
        }
        else if (g_cur_songlist == LOCAL_LISTENING_PAGE)
        {
            free(g_local_playlist.items);
            g_local_playlist.items = NULL;
            g_local_playlist.count = 0;
            g_local_read_idx = 0;
            local_scrolly_bottom_loader = 134;
        }
        show_battery_display();
        break;
    }
    default:
        break;
    }
}

static void player_page_left_control_button_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        lv_ui* ui = lv_event_get_user_data(e);
        return_pre_page(ui);
        show_battery_display();
        break;
    }
    default:
        break;
    }
}

void events_init_player_page (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->player_page_list_button, player_page_list_button_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->player_page_left_control_button, player_page_left_control_button_event_handler, LV_EVENT_ALL, ui);
}

static void today_listening_page_left_control_button_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        lv_ui* ui = lv_event_get_user_data(e);
        return_pre_page(ui);
        break;
    }
    default:
        break;
    }
}

void events_init_today_listening_page (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->today_listening_page_left_control_button, today_listening_page_left_control_button_event_handler, LV_EVENT_ALL, ui);
}

static void recently_listening_page_left_control_button_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        lv_ui* ui = lv_event_get_user_data(e);
        return_pre_page(ui);
        break;
    }
    default:
        break;
    }
}

void events_init_recently_listening_page (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->recently_listening_page_left_control_button, recently_listening_page_left_control_button_event_handler, LV_EVENT_ALL, ui);
}

static void my_order_page_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        break;
    }
    default:
        break;
    }
}

static void my_order_page_left_control_button_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        lv_ui* ui = lv_event_get_user_data(e);
        return_pre_page(ui);
        break;
    }
    default:
        break;
    }
}

void events_init_my_order_page (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->my_order_page, my_order_page_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->my_order_page_left_control_button, my_order_page_left_control_button_event_handler, LV_EVENT_ALL, ui);
}

static void local_listening_page_left_control_button_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_SHORT_CLICKED:
    {
        lv_ui* ui = lv_event_get_user_data(e);
        return_pre_page(ui);
        break;
    }
    default:
        break;
    }
}

void events_init_local_listening_page (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->local_listening_page_left_control_button, local_listening_page_left_control_button_event_handler, LV_EVENT_ALL, ui);
}

static void local_audio_page_left_control_button_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        lv_ui* ui = lv_event_get_user_data(e);
        return_pre_page(ui);
        break;
    }
    default:
        break;
    }
}

void events_init_local_audio_page (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->local_audio_page_left_control_button, local_audio_page_left_control_button_event_handler, LV_EVENT_ALL, ui);
}

static void system_settings_page_device_information_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.device_information_page, guider_ui.device_information_page_del, &guider_ui.system_settings_page_del, setup_scr_device_information_page, NEXT_LOAD_ANIM, LOAD_ANIM_TIME, LOAD_ANIM_DELAY, false, false);
        page_stack_push(g_current_page);
        update_device_info(&guider_ui);
        g_current_page = DEVICE_INFORMATION_PAGE;
        break;
    }
    default:
        break;
    }
}

static void system_settings_page_screen_brightness_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.screen_brightness_page, guider_ui.screen_brightness_page_del, &guider_ui.system_settings_page_del, setup_scr_screen_brightness_page, NEXT_LOAD_ANIM, LOAD_ANIM_TIME, LOAD_ANIM_DELAY, false, false);
        page_stack_push(g_current_page);
        g_current_page = SCREEN_BRIGHTNESS_PAGE;
        break;
    }
    default:
        break;
    }
}

static void system_settings_page_network_and_bluetooth_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.network_and_bluetooth_page, guider_ui.network_and_bluetooth_page_del, &guider_ui.system_settings_page_del, setup_scr_network_and_bluetooth_page, NEXT_LOAD_ANIM, LOAD_ANIM_TIME, LOAD_ANIM_DELAY, false, false);
        if (is_bt_connected)
        {
            lv_label_set_text(guider_ui.network_and_bluetooth_page_bt_pair_up_title, bt_name);
        }
        else
        {
            lv_label_set_text(guider_ui.network_and_bluetooth_page_bt_pair_up_title, "扫码配对");
        }
        if (is_wifi_connected)
        {
            lv_label_set_text(guider_ui.network_and_bluetooth_page_wifi_pair_up_title, wifi_name);
        }
        else
        {
            lv_label_set_text(guider_ui.network_and_bluetooth_page_wifi_pair_up_title, "扫码配对");
        }
        page_stack_push(g_current_page);
        g_current_page = NETWORK_AND_BLUETOOTH_PAGE;
        break;
    }
    default:
        break;
    }
}

static void system_settings_page_account_management_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        if (is_logged_in)
        {
            ui_load_scr_animation(&guider_ui, &guider_ui.account_management_page, guider_ui.account_management_page_del, &guider_ui.system_settings_page_del, setup_scr_account_management_page, NEXT_LOAD_ANIM, LOAD_ANIM_TIME, LOAD_ANIM_DELAY, false, false);
            update_account_management_page(&guider_ui);
            page_stack_push(g_current_page);
            g_current_page = ACCOUNT_MANAGEMENT_PAGE;
        }
        else
        {
            ui_load_scr_animation(&guider_ui, &guider_ui.account_login_page, guider_ui.account_login_page_del, &guider_ui.home_page_del, setup_scr_account_login_page, NEXT_LOAD_ANIM, LOAD_ANIM_TIME, LOAD_ANIM_DELAY, false, false);
            page_stack_push(g_current_page);
            g_current_page = ACCOUNT_LOGIN_PAGE;
            is_logged_in = true;
        }
        break;
    }
    default:
        break;
    }
}

static void system_settings_page_left_control_button_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        lv_ui* ui = lv_event_get_user_data(e);
        return_pre_page(ui);
        break;
    }
    default:
        break;
    }
}

void events_init_system_settings_page (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->system_settings_page_device_information, system_settings_page_device_information_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->system_settings_page_screen_brightness, system_settings_page_screen_brightness_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->system_settings_page_network_and_bluetooth, system_settings_page_network_and_bluetooth_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->system_settings_page_account_management, system_settings_page_account_management_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->system_settings_page_left_control_button, system_settings_page_left_control_button_event_handler, LV_EVENT_ALL, ui);
}

static void account_login_page_left_control_button_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        lv_ui* ui = lv_event_get_user_data(e);
        return_pre_page(ui);
        break;
    }
    default:
        break;
    }
}

void events_init_account_login_page (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->account_login_page_left_control_button, account_login_page_left_control_button_event_handler, LV_EVENT_ALL, ui);
}

static void account_management_page_left_control_button_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        lv_ui* ui = lv_event_get_user_data(e);
        return_pre_page(ui);
        break;
    }
    default:
        break;
    }
}

void events_init_account_management_page (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->account_management_page_left_control_button, account_management_page_left_control_button_event_handler, LV_EVENT_ALL, ui);
}

static void network_and_bluetooth_page_bt_pair_up_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.bt_connect_page, guider_ui.bt_connect_page_del, &guider_ui.network_and_bluetooth_page_del, setup_scr_bt_connect_page, NEXT_LOAD_ANIM, LOAD_ANIM_TIME, LOAD_ANIM_DELAY, false, false);
        page_stack_push(g_current_page);
        g_current_page = BT_CONNECT_PAGE;
        break;
    }
    default:
        break;
    }
}

static void network_and_bluetooth_page_wifi_pair_up_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.wifi_connect_page, guider_ui.wifi_connect_page_del, &guider_ui.network_and_bluetooth_page_del, setup_scr_wifi_connect_page, NEXT_LOAD_ANIM, LOAD_ANIM_TIME, LOAD_ANIM_DELAY, false, false);
        page_stack_push(g_current_page);
        g_current_page = WIFI_CONNECT_PAGE;
        break;
    }
    default:
        break;
    }
}

static void network_and_bluetooth_page_left_control_button_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        lv_ui* ui = lv_event_get_user_data(e);
        return_pre_page(ui);
        break;
    }
    default:
        break;
    }
}

void events_init_network_and_bluetooth_page (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->network_and_bluetooth_page_bt_pair_up, network_and_bluetooth_page_bt_pair_up_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->network_and_bluetooth_page_wifi_pair_up, network_and_bluetooth_page_wifi_pair_up_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->network_and_bluetooth_page_left_control_button, network_and_bluetooth_page_left_control_button_event_handler, LV_EVENT_ALL, ui);
}

static void screen_brightness_page_left_control_button_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        lv_ui* ui = lv_event_get_user_data(e);
        return_pre_page(ui);
        break;
    }
    default:
        break;
    }
}

void events_init_screen_brightness_page (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->screen_brightness_page_left_control_button, screen_brightness_page_left_control_button_event_handler, LV_EVENT_ALL, ui);
}

static void device_information_page_left_control_button_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        lv_ui* ui = lv_event_get_user_data(e);
        return_pre_page(ui);
        break;
    }
    default:
        break;
    }
}

void events_init_device_information_page (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->device_information_page_left_control_button, device_information_page_left_control_button_event_handler, LV_EVENT_ALL, ui);
}

static void wifi_connect_page_left_control_button_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        lv_ui* ui = lv_event_get_user_data(e);
        return_pre_page(ui);
        break;
    }
    default:
        break;
    }
}

void events_init_wifi_connect_page (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->wifi_connect_page_left_control_button, wifi_connect_page_left_control_button_event_handler, LV_EVENT_ALL, ui);
}

static void bt_connect_page_left_control_button_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        lv_ui* ui = lv_event_get_user_data(e);
        return_pre_page(ui);
        break;
    }
    default:
        break;
    }
}

void events_init_bt_connect_page (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->bt_connect_page_left_control_button, bt_connect_page_left_control_button_event_handler, LV_EVENT_ALL, ui);
}

static void pop_page_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        lv_ui* ui = lv_event_get_user_data(e);
        return_pre_page(ui);
        break;
    }
    default:
        break;
    }
}

static void pop_page_delete_control_button_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        break;
    }
    default:
        break;
    }
}

void events_init_pop_page (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->pop_page, pop_page_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->pop_page_delete_control_button, pop_page_delete_control_button_event_handler, LV_EVENT_ALL, ui);
}


void events_init(lv_ui *ui)
{

}
