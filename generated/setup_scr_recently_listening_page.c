/*
* Copyright 2026 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "widgets_init.h"
#include "custom.h"



void setup_scr_recently_listening_page(lv_ui *ui)
{
    //Write codes recently_listening_page
    ui->recently_listening_page = lv_obj_create(NULL);
    lv_obj_set_size(ui->recently_listening_page, 240, 320);
    lv_obj_set_scrollbar_mode(ui->recently_listening_page, LV_SCROLLBAR_MODE_OFF);

    //Write style for recently_listening_page, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->recently_listening_page, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->recently_listening_page, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->recently_listening_page, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes recently_listening_page_list
    ui->recently_listening_page_list = lv_obj_create(ui->recently_listening_page);
    lv_obj_set_pos(ui->recently_listening_page_list, 0, 64);
    lv_obj_set_size(ui->recently_listening_page_list, 240, 256);
    lv_obj_set_scrollbar_mode(ui->recently_listening_page_list, LV_SCROLLBAR_MODE_OFF);
    lv_obj_add_flag(ui->recently_listening_page_list, LV_OBJ_FLAG_HIDDEN);

    //Write style for recently_listening_page_list, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->recently_listening_page_list, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->recently_listening_page_list, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->recently_listening_page_list, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->recently_listening_page_list, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->recently_listening_page_list, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->recently_listening_page_list, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->recently_listening_page_list, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->recently_listening_page_list, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes recently_listening_page_no_song
    ui->recently_listening_page_no_song = lv_obj_create(ui->recently_listening_page);
    lv_obj_set_pos(ui->recently_listening_page_no_song, 0, 64);
    lv_obj_set_size(ui->recently_listening_page_no_song, 240, 256);
    lv_obj_set_scrollbar_mode(ui->recently_listening_page_no_song, LV_SCROLLBAR_MODE_OFF);

    //Write style for recently_listening_page_no_song, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->recently_listening_page_no_song, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->recently_listening_page_no_song, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->recently_listening_page_no_song, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->recently_listening_page_no_song, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->recently_listening_page_no_song, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->recently_listening_page_no_song, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->recently_listening_page_no_song, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->recently_listening_page_no_song, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes recently_listening_page_no_song_tips
    ui->recently_listening_page_no_song_tips = lv_label_create(ui->recently_listening_page_no_song);
    lv_obj_set_pos(ui->recently_listening_page_no_song_tips, 16, 137);
    lv_obj_set_size(ui->recently_listening_page_no_song_tips, 208, 22);
    lv_label_set_text(ui->recently_listening_page_no_song_tips, "看完动画后，再来熏听哦");
    lv_label_set_long_mode(ui->recently_listening_page_no_song_tips, LV_LABEL_LONG_WRAP);

    //Write style for recently_listening_page_no_song_tips, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->recently_listening_page_no_song_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->recently_listening_page_no_song_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->recently_listening_page_no_song_tips, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->recently_listening_page_no_song_tips, &lv_font_PingFangSC_Medium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->recently_listening_page_no_song_tips, 230, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->recently_listening_page_no_song_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->recently_listening_page_no_song_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->recently_listening_page_no_song_tips, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->recently_listening_page_no_song_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->recently_listening_page_no_song_tips, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->recently_listening_page_no_song_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->recently_listening_page_no_song_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->recently_listening_page_no_song_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->recently_listening_page_no_song_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes recently_listening_page_no_song_logo
    ui->recently_listening_page_no_song_logo = lv_image_create(ui->recently_listening_page_no_song);
    lv_obj_set_pos(ui->recently_listening_page_no_song_logo, 79, 55);
    lv_obj_set_size(ui->recently_listening_page_no_song_logo, 81, 62);
    lv_obj_add_flag(ui->recently_listening_page_no_song_logo, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->recently_listening_page_no_song_logo, &_no_songs_RGB565A8_81x62);
    lv_image_set_pivot(ui->recently_listening_page_no_song_logo, 50,50);
    lv_image_set_rotation(ui->recently_listening_page_no_song_logo, 0);

    //Write style for recently_listening_page_no_song_logo, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->recently_listening_page_no_song_logo, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->recently_listening_page_no_song_logo, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes recently_listening_page_status_bar
    ui->recently_listening_page_status_bar = lv_obj_create(ui->recently_listening_page);
    lv_obj_set_pos(ui->recently_listening_page_status_bar, 0, 0);
    lv_obj_set_size(ui->recently_listening_page_status_bar, 240, 64);
    lv_obj_set_scrollbar_mode(ui->recently_listening_page_status_bar, LV_SCROLLBAR_MODE_OFF);

    //Write style for recently_listening_page_status_bar, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->recently_listening_page_status_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->recently_listening_page_status_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->recently_listening_page_status_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->recently_listening_page_status_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->recently_listening_page_status_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->recently_listening_page_status_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->recently_listening_page_status_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->recently_listening_page_status_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes recently_listening_page_main_title
    ui->recently_listening_page_main_title = lv_label_create(ui->recently_listening_page_status_bar);
    lv_obj_set_pos(ui->recently_listening_page_main_title, 148, 32);
    lv_obj_set_size(ui->recently_listening_page_main_title, 80, 28);
    lv_label_set_text(ui->recently_listening_page_main_title, "最近熏听");
    lv_label_set_long_mode(ui->recently_listening_page_main_title, LV_LABEL_LONG_WRAP);

    //Write style for recently_listening_page_main_title, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->recently_listening_page_main_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->recently_listening_page_main_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->recently_listening_page_main_title, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->recently_listening_page_main_title, &lv_font_PingFangSC_Medium_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->recently_listening_page_main_title, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->recently_listening_page_main_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->recently_listening_page_main_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->recently_listening_page_main_title, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->recently_listening_page_main_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->recently_listening_page_main_title, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->recently_listening_page_main_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->recently_listening_page_main_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->recently_listening_page_main_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->recently_listening_page_main_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes recently_listening_page_left_control_button
    ui->recently_listening_page_left_control_button = lv_image_create(ui->recently_listening_page_status_bar);
    lv_obj_set_pos(ui->recently_listening_page_left_control_button, 16, 16);
    lv_obj_set_size(ui->recently_listening_page_left_control_button, 40, 40);
    lv_obj_add_flag(ui->recently_listening_page_left_control_button, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->recently_listening_page_left_control_button, &_left_control_RGB565A8_40x40);
    lv_image_set_pivot(ui->recently_listening_page_left_control_button, 50,50);
    lv_image_set_rotation(ui->recently_listening_page_left_control_button, 0);

    //Write style for recently_listening_page_left_control_button, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->recently_listening_page_left_control_button, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->recently_listening_page_left_control_button, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of recently_listening_page.
    //子容器初始化
    children[0] = guider_ui.home_page_local_audio_1;
    children[1] = guider_ui.home_page_today_listening_1;
    children[2] = guider_ui.home_page_recently_listening_1;
    children[3] = guider_ui.home_page_my_order_1;
    children[4] = guider_ui.home_page_system_settings;
    children[5] = guider_ui.home_page_local_audio;
    children[6] = guider_ui.home_page_today_listening;
    children[7] = guider_ui.home_page_recently_listening;
    children[8] = guider_ui.home_page_my_order;
    children[9] = guider_ui.home_page_system_settings_1;
    children[10] = guider_ui.home_page_local_audio_2;
    children[11] = guider_ui.home_page_today_listening_2;
    children[12] = guider_ui.home_page_recently_listening_2;
// 设置滚动方向和模式
    lv_obj_set_scroll_dir(ui->home_page_subpage_entry, LV_DIR_HOR);
    lv_obj_set_scroll_snap_x(ui->home_page_subpage_entry, LV_SCROLL_SNAP_CENTER);
    lv_obj_set_scrollbar_mode(ui->home_page_subpage_entry, LV_SCROLLBAR_MODE_OFF);
    lv_obj_add_flag(ui->home_page_subpage_entry, LV_OBJ_FLAG_SCROLLABLE); // 确保可滚动
    lv_obj_add_flag(ui->home_page_subpage_entry, LV_OBJ_FLAG_SCROLL_ONE);

// 主页组件滚动样式初始化
    lv_obj_remove_flag(ui->home_page_my_order_subtitle, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_remove_flag(ui->home_page_my_order_title, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_remove_flag(ui->home_page_my_order_icon, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_remove_flag(ui->home_page_my_order_subtitle_1, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_remove_flag(ui->home_page_my_order_title_1, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_remove_flag(ui->home_page_my_order_icon_1, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_remove_flag(ui->home_page_recently_listening_subtitle, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_remove_flag(ui->home_page_recently_listening_title, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_remove_flag(ui->home_page_recently_listening_icon, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_remove_flag(ui->home_page_recently_listening_subtitle_1, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_remove_flag(ui->home_page_recently_listening_title_1, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_remove_flag(ui->home_page_recently_listening_icon_1, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_remove_flag(ui->home_page_recently_listening_subtitle_2, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_remove_flag(ui->home_page_recently_listening_title_2, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_remove_flag(ui->home_page_recently_listening_icon_2, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_remove_flag(ui->home_page_today_listening_subtitle, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_remove_flag(ui->home_page_today_listening_title, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_remove_flag(ui->home_page_today_listening_icon, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_remove_flag(ui->home_page_today_listening_subtitle_1, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_remove_flag(ui->home_page_today_listening_title_1, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_remove_flag(ui->home_page_today_listening_icon_1, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_remove_flag(ui->home_page_today_listening_subtitle_2, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_remove_flag(ui->home_page_today_listening_title_2, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_remove_flag(ui->home_page_today_listening_icon_2, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_remove_flag(ui->home_page_play_icon, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_remove_flag(ui->home_page_play_icon_1, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_remove_flag(ui->home_page_play_icon_2, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_remove_flag(ui->home_page_local_audio_subtitle, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_remove_flag(ui->home_page_local_audio_title, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_remove_flag(ui->home_page_local_audio_icon, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_remove_flag(ui->home_page_local_audio_subtitle_1, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_remove_flag(ui->home_page_local_audio_title_1, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_remove_flag(ui->home_page_local_audio_icon_1, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_remove_flag(ui->home_page_local_audio_subtitle_2, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_remove_flag(ui->home_page_local_audio_title_2, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_remove_flag(ui->home_page_local_audio_icon_2, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_remove_flag(ui->home_page_system_settings_subtitle, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_remove_flag(ui->home_page_system_settings_title, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_remove_flag(ui->home_page_system_settings_icon, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_remove_flag(ui->home_page_system_settings_subtitle_1, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_remove_flag(ui->home_page_system_settings_title_1, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_remove_flag(ui->home_page_system_settings_icon_1, LV_OBJ_FLAG_CLICKABLE);

    for (int i = 0; i < 13; i++)
    {
        lv_obj_add_flag(children[i], LV_OBJ_FLAG_CLICKABLE);
    }
    for (int i = 0; i < 13; i++)
    {
        lv_obj_clear_flag(children[i], LV_OBJ_FLAG_SCROLLABLE);
    }
    for (int i = 0; i < 13; i++)
    {
        lv_obj_add_flag(children[i], LV_OBJ_FLAG_CLICK_FOCUSABLE);
    }
    for (int i = 0; i < 13; i++)
    {
        lv_obj_add_flag(children[i], LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    }
// for (int i = 0; i < 13; i++)
// {
// 	lv_obj_add_style(children[i], &style_focus, LV_PART_MAIN | LV_STATE_FOCUSED);
// }
// 添加所有可滚动的子对象到组中
    for (int i = 0; i < 13; i++)
    {
        lv_group_add_obj(home_group, children[i]);
    }
// 🔥 关键：控制滚动速度和惯性
    lv_obj_set_style_anim_time(ui->home_page_subpage_entry, 2000, LV_STATE_DEFAULT); // 增加动画时间使滚动变慢




    //Update current screen layout.
    lv_obj_update_layout(ui->recently_listening_page);

    //Init events for screen.
    events_init_recently_listening_page(ui);
}
