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



void setup_scr_home_page(lv_ui *ui)
{
    //Write codes home_page
    ui->home_page = lv_obj_create(NULL);
    lv_obj_set_size(ui->home_page, 240, 320);
    lv_obj_set_scrollbar_mode(ui->home_page, LV_SCROLLBAR_MODE_OFF);

    //Write style for home_page, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->home_page, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->home_page, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->home_page, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes home_page_status_bar
    ui->home_page_status_bar = lv_obj_create(ui->home_page);
    lv_obj_set_pos(ui->home_page_status_bar, 0, 0);
    lv_obj_set_size(ui->home_page_status_bar, 240, 64);
    lv_obj_set_scrollbar_mode(ui->home_page_status_bar, LV_SCROLLBAR_MODE_OFF);

    //Write style for home_page_status_bar, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->home_page_status_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->home_page_status_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->home_page_status_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->home_page_status_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->home_page_status_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->home_page_status_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->home_page_status_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->home_page_status_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes home_page_main_title
    ui->home_page_main_title = lv_label_create(ui->home_page_status_bar);
    lv_obj_set_pos(ui->home_page_main_title, 16, 26);
    lv_obj_set_size(ui->home_page_main_title, 48, 30);
    lv_label_set_text(ui->home_page_main_title, "首页");
    lv_label_set_long_mode(ui->home_page_main_title, LV_LABEL_LONG_WRAP);

    //Write style for home_page_main_title, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->home_page_main_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->home_page_main_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->home_page_main_title, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->home_page_main_title, &lv_font_PingFangSC_Medium_24, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->home_page_main_title, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->home_page_main_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->home_page_main_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->home_page_main_title, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->home_page_main_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->home_page_main_title, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->home_page_main_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->home_page_main_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->home_page_main_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->home_page_main_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes home_page_subpage_entry
    ui->home_page_subpage_entry = lv_obj_create(ui->home_page);
    lv_obj_set_pos(ui->home_page_subpage_entry, 0, 64);
    lv_obj_set_size(ui->home_page_subpage_entry, 240, 256);
    lv_obj_set_scrollbar_mode(ui->home_page_subpage_entry, LV_SCROLLBAR_MODE_OFF);

    //Write style for home_page_subpage_entry, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->home_page_subpage_entry, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->home_page_subpage_entry, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->home_page_subpage_entry, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->home_page_subpage_entry, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->home_page_subpage_entry, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->home_page_subpage_entry, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->home_page_subpage_entry, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->home_page_subpage_entry, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes home_page_system_settings_1
    ui->home_page_system_settings_1 = lv_obj_create(ui->home_page_subpage_entry);
    lv_obj_set_pos(ui->home_page_system_settings_1, 575, 30);
    lv_obj_set_size(ui->home_page_system_settings_1, 158, 168);
    lv_obj_set_scrollbar_mode(ui->home_page_system_settings_1, LV_SCROLLBAR_MODE_OFF);

    //Write style for home_page_system_settings_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->home_page_system_settings_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->home_page_system_settings_1, 36, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->home_page_system_settings_1, 28, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->home_page_system_settings_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->home_page_system_settings_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->home_page_system_settings_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->home_page_system_settings_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->home_page_system_settings_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->home_page_system_settings_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->home_page_system_settings_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes home_page_system_settings_subtitle_1
    ui->home_page_system_settings_subtitle_1 = lv_label_create(ui->home_page_system_settings_1);
    lv_obj_set_pos(ui->home_page_system_settings_subtitle_1, 10, 128);
    lv_obj_set_size(ui->home_page_system_settings_subtitle_1, 138, 20);
    lv_label_set_text(ui->home_page_system_settings_subtitle_1, "管理您的设备");
    lv_label_set_long_mode(ui->home_page_system_settings_subtitle_1, LV_LABEL_LONG_WRAP);

    //Write style for home_page_system_settings_subtitle_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->home_page_system_settings_subtitle_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->home_page_system_settings_subtitle_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->home_page_system_settings_subtitle_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->home_page_system_settings_subtitle_1, &lv_font_PingFangSC_Regular_14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->home_page_system_settings_subtitle_1, 211, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->home_page_system_settings_subtitle_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->home_page_system_settings_subtitle_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->home_page_system_settings_subtitle_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->home_page_system_settings_subtitle_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->home_page_system_settings_subtitle_1, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->home_page_system_settings_subtitle_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->home_page_system_settings_subtitle_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->home_page_system_settings_subtitle_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->home_page_system_settings_subtitle_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes home_page_system_settings_title_1
    ui->home_page_system_settings_title_1 = lv_label_create(ui->home_page_system_settings_1);
    lv_obj_set_pos(ui->home_page_system_settings_title_1, 43, 102);
    lv_obj_set_size(ui->home_page_system_settings_title_1, 72, 22);
    lv_label_set_text(ui->home_page_system_settings_title_1, "系统设置");
    lv_label_set_long_mode(ui->home_page_system_settings_title_1, LV_LABEL_LONG_WRAP);

    //Write style for home_page_system_settings_title_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->home_page_system_settings_title_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->home_page_system_settings_title_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->home_page_system_settings_title_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->home_page_system_settings_title_1, &lv_font_FZCuYuan_M03S_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->home_page_system_settings_title_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->home_page_system_settings_title_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->home_page_system_settings_title_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->home_page_system_settings_title_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->home_page_system_settings_title_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->home_page_system_settings_title_1, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->home_page_system_settings_title_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->home_page_system_settings_title_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->home_page_system_settings_title_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->home_page_system_settings_title_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes home_page_system_settings_icon_1
    ui->home_page_system_settings_icon_1 = lv_image_create(ui->home_page_system_settings_1);
    lv_obj_set_pos(ui->home_page_system_settings_icon_1, 44, 25);
    lv_obj_set_size(ui->home_page_system_settings_icon_1, 70, 65);
    lv_obj_add_flag(ui->home_page_system_settings_icon_1, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->home_page_system_settings_icon_1, &_system_settings_icon2_RGB565A8_70x65);
    lv_image_set_pivot(ui->home_page_system_settings_icon_1, 50,50);
    lv_image_set_rotation(ui->home_page_system_settings_icon_1, 0);

    //Write style for home_page_system_settings_icon_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->home_page_system_settings_icon_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->home_page_system_settings_icon_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes home_page_system_settings
    ui->home_page_system_settings = lv_obj_create(ui->home_page_subpage_entry);
    lv_obj_set_pos(ui->home_page_system_settings, -315, 20);
    lv_obj_set_size(ui->home_page_system_settings, 158, 168);
    lv_obj_set_scrollbar_mode(ui->home_page_system_settings, LV_SCROLLBAR_MODE_OFF);

    //Write style for home_page_system_settings, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->home_page_system_settings, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->home_page_system_settings, 36, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->home_page_system_settings, 28, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->home_page_system_settings, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->home_page_system_settings, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->home_page_system_settings, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->home_page_system_settings, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->home_page_system_settings, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->home_page_system_settings, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->home_page_system_settings, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes home_page_system_settings_subtitle
    ui->home_page_system_settings_subtitle = lv_label_create(ui->home_page_system_settings);
    lv_obj_set_pos(ui->home_page_system_settings_subtitle, 10, 128);
    lv_obj_set_size(ui->home_page_system_settings_subtitle, 138, 20);
    lv_label_set_text(ui->home_page_system_settings_subtitle, "管理您的设备");
    lv_label_set_long_mode(ui->home_page_system_settings_subtitle, LV_LABEL_LONG_WRAP);

    //Write style for home_page_system_settings_subtitle, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->home_page_system_settings_subtitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->home_page_system_settings_subtitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->home_page_system_settings_subtitle, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->home_page_system_settings_subtitle, &lv_font_PingFangSC_Regular_14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->home_page_system_settings_subtitle, 211, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->home_page_system_settings_subtitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->home_page_system_settings_subtitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->home_page_system_settings_subtitle, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->home_page_system_settings_subtitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->home_page_system_settings_subtitle, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->home_page_system_settings_subtitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->home_page_system_settings_subtitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->home_page_system_settings_subtitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->home_page_system_settings_subtitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes home_page_system_settings_title
    ui->home_page_system_settings_title = lv_label_create(ui->home_page_system_settings);
    lv_obj_set_pos(ui->home_page_system_settings_title, 43, 102);
    lv_obj_set_size(ui->home_page_system_settings_title, 72, 22);
    lv_label_set_text(ui->home_page_system_settings_title, "系统设置");
    lv_label_set_long_mode(ui->home_page_system_settings_title, LV_LABEL_LONG_WRAP);

    //Write style for home_page_system_settings_title, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->home_page_system_settings_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->home_page_system_settings_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->home_page_system_settings_title, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->home_page_system_settings_title, &lv_font_FZCuYuan_M03S_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->home_page_system_settings_title, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->home_page_system_settings_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->home_page_system_settings_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->home_page_system_settings_title, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->home_page_system_settings_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->home_page_system_settings_title, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->home_page_system_settings_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->home_page_system_settings_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->home_page_system_settings_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->home_page_system_settings_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes home_page_system_settings_icon
    ui->home_page_system_settings_icon = lv_image_create(ui->home_page_system_settings);
    lv_obj_set_pos(ui->home_page_system_settings_icon, 44, 25);
    lv_obj_set_size(ui->home_page_system_settings_icon, 70, 65);
    lv_obj_add_flag(ui->home_page_system_settings_icon, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->home_page_system_settings_icon, &_system_settings_icon2_RGB565A8_70x65);
    lv_image_set_pivot(ui->home_page_system_settings_icon, 50,50);
    lv_image_set_rotation(ui->home_page_system_settings_icon, 0);

    //Write style for home_page_system_settings_icon, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->home_page_system_settings_icon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->home_page_system_settings_icon, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes home_page_local_audio_2
    ui->home_page_local_audio_2 = lv_obj_create(ui->home_page_subpage_entry);
    lv_obj_set_pos(ui->home_page_local_audio_2, 754, 40);
    lv_obj_set_size(ui->home_page_local_audio_2, 158, 168);
    lv_obj_set_scrollbar_mode(ui->home_page_local_audio_2, LV_SCROLLBAR_MODE_OFF);

    //Write style for home_page_local_audio_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->home_page_local_audio_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->home_page_local_audio_2, 36, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->home_page_local_audio_2, 28, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->home_page_local_audio_2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->home_page_local_audio_2, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->home_page_local_audio_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->home_page_local_audio_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->home_page_local_audio_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->home_page_local_audio_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->home_page_local_audio_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes home_page_local_audio_subtitle_2
    ui->home_page_local_audio_subtitle_2 = lv_label_create(ui->home_page_local_audio_2);
    lv_obj_set_pos(ui->home_page_local_audio_subtitle_2, 10, 128);
    lv_obj_set_size(ui->home_page_local_audio_subtitle_2, 138, 20);
    lv_label_set_text(ui->home_page_local_audio_subtitle_2, "上传到本机的音频");
    lv_label_set_long_mode(ui->home_page_local_audio_subtitle_2, LV_LABEL_LONG_WRAP);

    //Write style for home_page_local_audio_subtitle_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->home_page_local_audio_subtitle_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->home_page_local_audio_subtitle_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->home_page_local_audio_subtitle_2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->home_page_local_audio_subtitle_2, &lv_font_PingFangSC_Regular_14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->home_page_local_audio_subtitle_2, 211, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->home_page_local_audio_subtitle_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->home_page_local_audio_subtitle_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->home_page_local_audio_subtitle_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->home_page_local_audio_subtitle_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->home_page_local_audio_subtitle_2, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->home_page_local_audio_subtitle_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->home_page_local_audio_subtitle_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->home_page_local_audio_subtitle_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->home_page_local_audio_subtitle_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes home_page_local_audio_title_2
    ui->home_page_local_audio_title_2 = lv_label_create(ui->home_page_local_audio_2);
    lv_obj_set_pos(ui->home_page_local_audio_title_2, 43, 102);
    lv_obj_set_size(ui->home_page_local_audio_title_2, 72, 22);
    lv_label_set_text(ui->home_page_local_audio_title_2, "本地音频");
    lv_label_set_long_mode(ui->home_page_local_audio_title_2, LV_LABEL_LONG_WRAP);

    //Write style for home_page_local_audio_title_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->home_page_local_audio_title_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->home_page_local_audio_title_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->home_page_local_audio_title_2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->home_page_local_audio_title_2, &lv_font_FZCuYuan_M03S_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->home_page_local_audio_title_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->home_page_local_audio_title_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->home_page_local_audio_title_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->home_page_local_audio_title_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->home_page_local_audio_title_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->home_page_local_audio_title_2, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->home_page_local_audio_title_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->home_page_local_audio_title_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->home_page_local_audio_title_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->home_page_local_audio_title_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes home_page_local_audio_icon_2
    ui->home_page_local_audio_icon_2 = lv_image_create(ui->home_page_local_audio_2);
    lv_obj_set_pos(ui->home_page_local_audio_icon_2, 44, 25);
    lv_obj_set_size(ui->home_page_local_audio_icon_2, 70, 60);
    lv_obj_add_flag(ui->home_page_local_audio_icon_2, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->home_page_local_audio_icon_2, &_local_audio_icon2_RGB565A8_70x60);
    lv_image_set_pivot(ui->home_page_local_audio_icon_2, 50,50);
    lv_image_set_rotation(ui->home_page_local_audio_icon_2, 0);

    //Write style for home_page_local_audio_icon_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->home_page_local_audio_icon_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->home_page_local_audio_icon_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes home_page_local_audio_1
    ui->home_page_local_audio_1 = lv_obj_create(ui->home_page_subpage_entry);
    lv_obj_set_pos(ui->home_page_local_audio_1, -1027, 60);
    lv_obj_set_size(ui->home_page_local_audio_1, 158, 168);
    lv_obj_set_scrollbar_mode(ui->home_page_local_audio_1, LV_SCROLLBAR_MODE_OFF);

    //Write style for home_page_local_audio_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->home_page_local_audio_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->home_page_local_audio_1, 36, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->home_page_local_audio_1, 28, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->home_page_local_audio_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->home_page_local_audio_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->home_page_local_audio_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->home_page_local_audio_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->home_page_local_audio_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->home_page_local_audio_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->home_page_local_audio_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes home_page_local_audio_subtitle_1
    ui->home_page_local_audio_subtitle_1 = lv_label_create(ui->home_page_local_audio_1);
    lv_obj_set_pos(ui->home_page_local_audio_subtitle_1, 10, 128);
    lv_obj_set_size(ui->home_page_local_audio_subtitle_1, 138, 20);
    lv_label_set_text(ui->home_page_local_audio_subtitle_1, "上传到本机的音频");
    lv_label_set_long_mode(ui->home_page_local_audio_subtitle_1, LV_LABEL_LONG_WRAP);

    //Write style for home_page_local_audio_subtitle_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->home_page_local_audio_subtitle_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->home_page_local_audio_subtitle_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->home_page_local_audio_subtitle_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->home_page_local_audio_subtitle_1, &lv_font_PingFangSC_Regular_14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->home_page_local_audio_subtitle_1, 211, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->home_page_local_audio_subtitle_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->home_page_local_audio_subtitle_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->home_page_local_audio_subtitle_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->home_page_local_audio_subtitle_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->home_page_local_audio_subtitle_1, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->home_page_local_audio_subtitle_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->home_page_local_audio_subtitle_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->home_page_local_audio_subtitle_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->home_page_local_audio_subtitle_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes home_page_local_audio_title_1
    ui->home_page_local_audio_title_1 = lv_label_create(ui->home_page_local_audio_1);
    lv_obj_set_pos(ui->home_page_local_audio_title_1, 43, 102);
    lv_obj_set_size(ui->home_page_local_audio_title_1, 72, 22);
    lv_label_set_text(ui->home_page_local_audio_title_1, "本地音频");
    lv_label_set_long_mode(ui->home_page_local_audio_title_1, LV_LABEL_LONG_WRAP);

    //Write style for home_page_local_audio_title_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->home_page_local_audio_title_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->home_page_local_audio_title_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->home_page_local_audio_title_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->home_page_local_audio_title_1, &lv_font_FZCuYuan_M03S_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->home_page_local_audio_title_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->home_page_local_audio_title_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->home_page_local_audio_title_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->home_page_local_audio_title_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->home_page_local_audio_title_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->home_page_local_audio_title_1, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->home_page_local_audio_title_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->home_page_local_audio_title_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->home_page_local_audio_title_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->home_page_local_audio_title_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes home_page_local_audio_icon_1
    ui->home_page_local_audio_icon_1 = lv_image_create(ui->home_page_local_audio_1);
    lv_obj_set_pos(ui->home_page_local_audio_icon_1, 44, 25);
    lv_obj_set_size(ui->home_page_local_audio_icon_1, 70, 60);
    lv_obj_add_flag(ui->home_page_local_audio_icon_1, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->home_page_local_audio_icon_1, &_local_audio_icon2_RGB565A8_70x60);
    lv_image_set_pivot(ui->home_page_local_audio_icon_1, 50,50);
    lv_image_set_rotation(ui->home_page_local_audio_icon_1, 0);

    //Write style for home_page_local_audio_icon_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->home_page_local_audio_icon_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->home_page_local_audio_icon_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes home_page_local_audio
    ui->home_page_local_audio = lv_obj_create(ui->home_page_subpage_entry);
    lv_obj_set_pos(ui->home_page_local_audio, -137, 10);
    lv_obj_set_size(ui->home_page_local_audio, 158, 168);
    lv_obj_set_scrollbar_mode(ui->home_page_local_audio, LV_SCROLLBAR_MODE_OFF);

    //Write style for home_page_local_audio, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->home_page_local_audio, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->home_page_local_audio, 36, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->home_page_local_audio, 28, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->home_page_local_audio, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->home_page_local_audio, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->home_page_local_audio, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->home_page_local_audio, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->home_page_local_audio, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->home_page_local_audio, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->home_page_local_audio, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes home_page_local_audio_subtitle
    ui->home_page_local_audio_subtitle = lv_label_create(ui->home_page_local_audio);
    lv_obj_set_pos(ui->home_page_local_audio_subtitle, 10, 128);
    lv_obj_set_size(ui->home_page_local_audio_subtitle, 138, 20);
    lv_label_set_text(ui->home_page_local_audio_subtitle, "上传到本机的音频");
    lv_label_set_long_mode(ui->home_page_local_audio_subtitle, LV_LABEL_LONG_WRAP);

    //Write style for home_page_local_audio_subtitle, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->home_page_local_audio_subtitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->home_page_local_audio_subtitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->home_page_local_audio_subtitle, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->home_page_local_audio_subtitle, &lv_font_PingFangSC_Regular_14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->home_page_local_audio_subtitle, 211, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->home_page_local_audio_subtitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->home_page_local_audio_subtitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->home_page_local_audio_subtitle, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->home_page_local_audio_subtitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->home_page_local_audio_subtitle, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->home_page_local_audio_subtitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->home_page_local_audio_subtitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->home_page_local_audio_subtitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->home_page_local_audio_subtitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes home_page_local_audio_title
    ui->home_page_local_audio_title = lv_label_create(ui->home_page_local_audio);
    lv_obj_set_pos(ui->home_page_local_audio_title, 43, 102);
    lv_obj_set_size(ui->home_page_local_audio_title, 72, 22);
    lv_label_set_text(ui->home_page_local_audio_title, "本地音频");
    lv_label_set_long_mode(ui->home_page_local_audio_title, LV_LABEL_LONG_WRAP);

    //Write style for home_page_local_audio_title, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->home_page_local_audio_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->home_page_local_audio_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->home_page_local_audio_title, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->home_page_local_audio_title, &lv_font_FZCuYuan_M03S_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->home_page_local_audio_title, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->home_page_local_audio_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->home_page_local_audio_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->home_page_local_audio_title, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->home_page_local_audio_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->home_page_local_audio_title, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->home_page_local_audio_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->home_page_local_audio_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->home_page_local_audio_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->home_page_local_audio_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes home_page_local_audio_icon
    ui->home_page_local_audio_icon = lv_image_create(ui->home_page_local_audio);
    lv_obj_set_pos(ui->home_page_local_audio_icon, 44, 25);
    lv_obj_set_size(ui->home_page_local_audio_icon, 70, 60);
    lv_obj_add_flag(ui->home_page_local_audio_icon, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->home_page_local_audio_icon, &_local_audio_icon2_RGB565A8_70x60);
    lv_image_set_pivot(ui->home_page_local_audio_icon, 50,50);
    lv_image_set_rotation(ui->home_page_local_audio_icon, 0);

    //Write style for home_page_local_audio_icon, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->home_page_local_audio_icon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->home_page_local_audio_icon, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes home_page_my_order_1
    ui->home_page_my_order_1 = lv_obj_create(ui->home_page_subpage_entry);
    lv_obj_set_pos(ui->home_page_my_order_1, -493, 30);
    lv_obj_set_size(ui->home_page_my_order_1, 158, 168);
    lv_obj_set_scrollbar_mode(ui->home_page_my_order_1, LV_SCROLLBAR_MODE_OFF);

    //Write style for home_page_my_order_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->home_page_my_order_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->home_page_my_order_1, 36, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->home_page_my_order_1, 28, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->home_page_my_order_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->home_page_my_order_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->home_page_my_order_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->home_page_my_order_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->home_page_my_order_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->home_page_my_order_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->home_page_my_order_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes home_page_my_order_subtitle_1
    ui->home_page_my_order_subtitle_1 = lv_label_create(ui->home_page_my_order_1);
    lv_obj_set_pos(ui->home_page_my_order_subtitle_1, 10, 128);
    lv_obj_set_size(ui->home_page_my_order_subtitle_1, 138, 20);
    lv_label_set_text(ui->home_page_my_order_subtitle_1, "app内的听单内容");
    lv_label_set_long_mode(ui->home_page_my_order_subtitle_1, LV_LABEL_LONG_WRAP);

    //Write style for home_page_my_order_subtitle_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->home_page_my_order_subtitle_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->home_page_my_order_subtitle_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->home_page_my_order_subtitle_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->home_page_my_order_subtitle_1, &lv_font_PingFangSC_Regular_14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->home_page_my_order_subtitle_1, 211, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->home_page_my_order_subtitle_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->home_page_my_order_subtitle_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->home_page_my_order_subtitle_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->home_page_my_order_subtitle_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->home_page_my_order_subtitle_1, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->home_page_my_order_subtitle_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->home_page_my_order_subtitle_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->home_page_my_order_subtitle_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->home_page_my_order_subtitle_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes home_page_my_order_title_1
    ui->home_page_my_order_title_1 = lv_label_create(ui->home_page_my_order_1);
    lv_obj_set_pos(ui->home_page_my_order_title_1, 43, 102);
    lv_obj_set_size(ui->home_page_my_order_title_1, 72, 22);
    lv_label_set_text(ui->home_page_my_order_title_1, "我的听单");
    lv_label_set_long_mode(ui->home_page_my_order_title_1, LV_LABEL_LONG_WRAP);

    //Write style for home_page_my_order_title_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->home_page_my_order_title_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->home_page_my_order_title_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->home_page_my_order_title_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->home_page_my_order_title_1, &lv_font_FZCuYuan_M03S_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->home_page_my_order_title_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->home_page_my_order_title_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->home_page_my_order_title_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->home_page_my_order_title_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->home_page_my_order_title_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->home_page_my_order_title_1, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->home_page_my_order_title_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->home_page_my_order_title_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->home_page_my_order_title_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->home_page_my_order_title_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes home_page_my_order_icon_1
    ui->home_page_my_order_icon_1 = lv_image_create(ui->home_page_my_order_1);
    lv_obj_set_pos(ui->home_page_my_order_icon_1, 44, 25);
    lv_obj_set_size(ui->home_page_my_order_icon_1, 70, 68);
    lv_obj_add_flag(ui->home_page_my_order_icon_1, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->home_page_my_order_icon_1, &_my_order_icon2_RGB565A8_70x68);
    lv_image_set_pivot(ui->home_page_my_order_icon_1, 50,50);
    lv_image_set_rotation(ui->home_page_my_order_icon_1, 0);

    //Write style for home_page_my_order_icon_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->home_page_my_order_icon_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->home_page_my_order_icon_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes home_page_my_order
    ui->home_page_my_order = lv_obj_create(ui->home_page_subpage_entry);
    lv_obj_set_pos(ui->home_page_my_order, 397, 20);
    lv_obj_set_size(ui->home_page_my_order, 158, 168);
    lv_obj_set_scrollbar_mode(ui->home_page_my_order, LV_SCROLLBAR_MODE_OFF);

    //Write style for home_page_my_order, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->home_page_my_order, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->home_page_my_order, 36, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->home_page_my_order, 28, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->home_page_my_order, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->home_page_my_order, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->home_page_my_order, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->home_page_my_order, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->home_page_my_order, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->home_page_my_order, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->home_page_my_order, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes home_page_my_order_subtitle
    ui->home_page_my_order_subtitle = lv_label_create(ui->home_page_my_order);
    lv_obj_set_pos(ui->home_page_my_order_subtitle, 10, 128);
    lv_obj_set_size(ui->home_page_my_order_subtitle, 138, 20);
    lv_label_set_text(ui->home_page_my_order_subtitle, "app内的听单内容");
    lv_label_set_long_mode(ui->home_page_my_order_subtitle, LV_LABEL_LONG_WRAP);

    //Write style for home_page_my_order_subtitle, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->home_page_my_order_subtitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->home_page_my_order_subtitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->home_page_my_order_subtitle, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->home_page_my_order_subtitle, &lv_font_PingFangSC_Regular_14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->home_page_my_order_subtitle, 211, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->home_page_my_order_subtitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->home_page_my_order_subtitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->home_page_my_order_subtitle, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->home_page_my_order_subtitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->home_page_my_order_subtitle, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->home_page_my_order_subtitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->home_page_my_order_subtitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->home_page_my_order_subtitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->home_page_my_order_subtitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes home_page_my_order_title
    ui->home_page_my_order_title = lv_label_create(ui->home_page_my_order);
    lv_obj_set_pos(ui->home_page_my_order_title, 43, 102);
    lv_obj_set_size(ui->home_page_my_order_title, 72, 22);
    lv_label_set_text(ui->home_page_my_order_title, "我的听单");
    lv_label_set_long_mode(ui->home_page_my_order_title, LV_LABEL_LONG_WRAP);

    //Write style for home_page_my_order_title, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->home_page_my_order_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->home_page_my_order_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->home_page_my_order_title, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->home_page_my_order_title, &lv_font_FZCuYuan_M03S_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->home_page_my_order_title, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->home_page_my_order_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->home_page_my_order_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->home_page_my_order_title, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->home_page_my_order_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->home_page_my_order_title, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->home_page_my_order_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->home_page_my_order_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->home_page_my_order_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->home_page_my_order_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes home_page_my_order_icon
    ui->home_page_my_order_icon = lv_image_create(ui->home_page_my_order);
    lv_obj_set_pos(ui->home_page_my_order_icon, 44, 25);
    lv_obj_set_size(ui->home_page_my_order_icon, 70, 68);
    lv_obj_add_flag(ui->home_page_my_order_icon, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->home_page_my_order_icon, &_my_order_icon2_RGB565A8_70x68);
    lv_image_set_pivot(ui->home_page_my_order_icon, 50,50);
    lv_image_set_rotation(ui->home_page_my_order_icon, 0);

    //Write style for home_page_my_order_icon, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->home_page_my_order_icon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->home_page_my_order_icon, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes home_page_recently_listening_2
    ui->home_page_recently_listening_2 = lv_obj_create(ui->home_page_subpage_entry);
    lv_obj_set_pos(ui->home_page_recently_listening_2, 1109, 60);
    lv_obj_set_size(ui->home_page_recently_listening_2, 158, 168);
    lv_obj_set_scrollbar_mode(ui->home_page_recently_listening_2, LV_SCROLLBAR_MODE_OFF);

    //Write style for home_page_recently_listening_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->home_page_recently_listening_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->home_page_recently_listening_2, 36, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->home_page_recently_listening_2, 28, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->home_page_recently_listening_2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->home_page_recently_listening_2, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->home_page_recently_listening_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->home_page_recently_listening_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->home_page_recently_listening_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->home_page_recently_listening_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->home_page_recently_listening_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes home_page_recently_listening_subtitle_2
    ui->home_page_recently_listening_subtitle_2 = lv_label_create(ui->home_page_recently_listening_2);
    lv_obj_set_pos(ui->home_page_recently_listening_subtitle_2, 10, 128);
    lv_obj_set_size(ui->home_page_recently_listening_subtitle_2, 138, 20);
    lv_label_set_text(ui->home_page_recently_listening_subtitle_2, "宝贝的熏听记录");
    lv_label_set_long_mode(ui->home_page_recently_listening_subtitle_2, LV_LABEL_LONG_WRAP);

    //Write style for home_page_recently_listening_subtitle_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->home_page_recently_listening_subtitle_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->home_page_recently_listening_subtitle_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->home_page_recently_listening_subtitle_2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->home_page_recently_listening_subtitle_2, &lv_font_PingFangSC_Regular_14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->home_page_recently_listening_subtitle_2, 211, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->home_page_recently_listening_subtitle_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->home_page_recently_listening_subtitle_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->home_page_recently_listening_subtitle_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->home_page_recently_listening_subtitle_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->home_page_recently_listening_subtitle_2, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->home_page_recently_listening_subtitle_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->home_page_recently_listening_subtitle_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->home_page_recently_listening_subtitle_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->home_page_recently_listening_subtitle_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes home_page_recently_listening_title_2
    ui->home_page_recently_listening_title_2 = lv_label_create(ui->home_page_recently_listening_2);
    lv_obj_set_pos(ui->home_page_recently_listening_title_2, 43, 102);
    lv_obj_set_size(ui->home_page_recently_listening_title_2, 72, 22);
    lv_label_set_text(ui->home_page_recently_listening_title_2, "最近熏听");
    lv_label_set_long_mode(ui->home_page_recently_listening_title_2, LV_LABEL_LONG_WRAP);

    //Write style for home_page_recently_listening_title_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->home_page_recently_listening_title_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->home_page_recently_listening_title_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->home_page_recently_listening_title_2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->home_page_recently_listening_title_2, &lv_font_FZCuYuan_M03S_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->home_page_recently_listening_title_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->home_page_recently_listening_title_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->home_page_recently_listening_title_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->home_page_recently_listening_title_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->home_page_recently_listening_title_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->home_page_recently_listening_title_2, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->home_page_recently_listening_title_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->home_page_recently_listening_title_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->home_page_recently_listening_title_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->home_page_recently_listening_title_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes home_page_recently_listening_icon_2
    ui->home_page_recently_listening_icon_2 = lv_image_create(ui->home_page_recently_listening_2);
    lv_obj_set_pos(ui->home_page_recently_listening_icon_2, 44, 25);
    lv_obj_set_size(ui->home_page_recently_listening_icon_2, 70, 70);
    lv_obj_add_flag(ui->home_page_recently_listening_icon_2, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->home_page_recently_listening_icon_2, &_recently_listening_icon2_RGB565A8_70x70);
    lv_image_set_pivot(ui->home_page_recently_listening_icon_2, 50,50);
    lv_image_set_rotation(ui->home_page_recently_listening_icon_2, 0);

    //Write style for home_page_recently_listening_icon_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->home_page_recently_listening_icon_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->home_page_recently_listening_icon_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes home_page_recently_listening_1
    ui->home_page_recently_listening_1 = lv_obj_create(ui->home_page_subpage_entry);
    lv_obj_set_pos(ui->home_page_recently_listening_1, -671, 40);
    lv_obj_set_size(ui->home_page_recently_listening_1, 158, 168);
    lv_obj_set_scrollbar_mode(ui->home_page_recently_listening_1, LV_SCROLLBAR_MODE_OFF);

    //Write style for home_page_recently_listening_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->home_page_recently_listening_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->home_page_recently_listening_1, 36, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->home_page_recently_listening_1, 28, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->home_page_recently_listening_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->home_page_recently_listening_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->home_page_recently_listening_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->home_page_recently_listening_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->home_page_recently_listening_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->home_page_recently_listening_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->home_page_recently_listening_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes home_page_recently_listening_subtitle_1
    ui->home_page_recently_listening_subtitle_1 = lv_label_create(ui->home_page_recently_listening_1);
    lv_obj_set_pos(ui->home_page_recently_listening_subtitle_1, 10, 128);
    lv_obj_set_size(ui->home_page_recently_listening_subtitle_1, 138, 20);
    lv_label_set_text(ui->home_page_recently_listening_subtitle_1, "宝贝的熏听记录");
    lv_label_set_long_mode(ui->home_page_recently_listening_subtitle_1, LV_LABEL_LONG_WRAP);

    //Write style for home_page_recently_listening_subtitle_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->home_page_recently_listening_subtitle_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->home_page_recently_listening_subtitle_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->home_page_recently_listening_subtitle_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->home_page_recently_listening_subtitle_1, &lv_font_PingFangSC_Regular_14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->home_page_recently_listening_subtitle_1, 211, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->home_page_recently_listening_subtitle_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->home_page_recently_listening_subtitle_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->home_page_recently_listening_subtitle_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->home_page_recently_listening_subtitle_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->home_page_recently_listening_subtitle_1, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->home_page_recently_listening_subtitle_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->home_page_recently_listening_subtitle_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->home_page_recently_listening_subtitle_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->home_page_recently_listening_subtitle_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes home_page_recently_listening_title_1
    ui->home_page_recently_listening_title_1 = lv_label_create(ui->home_page_recently_listening_1);
    lv_obj_set_pos(ui->home_page_recently_listening_title_1, 43, 102);
    lv_obj_set_size(ui->home_page_recently_listening_title_1, 72, 22);
    lv_label_set_text(ui->home_page_recently_listening_title_1, "最近熏听");
    lv_label_set_long_mode(ui->home_page_recently_listening_title_1, LV_LABEL_LONG_WRAP);

    //Write style for home_page_recently_listening_title_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->home_page_recently_listening_title_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->home_page_recently_listening_title_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->home_page_recently_listening_title_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->home_page_recently_listening_title_1, &lv_font_FZCuYuan_M03S_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->home_page_recently_listening_title_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->home_page_recently_listening_title_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->home_page_recently_listening_title_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->home_page_recently_listening_title_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->home_page_recently_listening_title_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->home_page_recently_listening_title_1, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->home_page_recently_listening_title_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->home_page_recently_listening_title_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->home_page_recently_listening_title_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->home_page_recently_listening_title_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes home_page_recently_listening_icon_1
    ui->home_page_recently_listening_icon_1 = lv_image_create(ui->home_page_recently_listening_1);
    lv_obj_set_pos(ui->home_page_recently_listening_icon_1, 44, 25);
    lv_obj_set_size(ui->home_page_recently_listening_icon_1, 70, 70);
    lv_obj_add_flag(ui->home_page_recently_listening_icon_1, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->home_page_recently_listening_icon_1, &_recently_listening_icon2_RGB565A8_70x70);
    lv_image_set_pivot(ui->home_page_recently_listening_icon_1, 50,50);
    lv_image_set_rotation(ui->home_page_recently_listening_icon_1, 0);

    //Write style for home_page_recently_listening_icon_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->home_page_recently_listening_icon_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->home_page_recently_listening_icon_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes home_page_recently_listening
    ui->home_page_recently_listening = lv_obj_create(ui->home_page_subpage_entry);
    lv_obj_set_pos(ui->home_page_recently_listening, 219, 10);
    lv_obj_set_size(ui->home_page_recently_listening, 158, 168);
    lv_obj_set_scrollbar_mode(ui->home_page_recently_listening, LV_SCROLLBAR_MODE_OFF);

    //Write style for home_page_recently_listening, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->home_page_recently_listening, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->home_page_recently_listening, 36, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->home_page_recently_listening, 28, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->home_page_recently_listening, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->home_page_recently_listening, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->home_page_recently_listening, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->home_page_recently_listening, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->home_page_recently_listening, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->home_page_recently_listening, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->home_page_recently_listening, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes home_page_recently_listening_subtitle
    ui->home_page_recently_listening_subtitle = lv_label_create(ui->home_page_recently_listening);
    lv_obj_set_pos(ui->home_page_recently_listening_subtitle, 10, 128);
    lv_obj_set_size(ui->home_page_recently_listening_subtitle, 138, 20);
    lv_label_set_text(ui->home_page_recently_listening_subtitle, "宝贝的熏听记录");
    lv_label_set_long_mode(ui->home_page_recently_listening_subtitle, LV_LABEL_LONG_WRAP);

    //Write style for home_page_recently_listening_subtitle, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->home_page_recently_listening_subtitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->home_page_recently_listening_subtitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->home_page_recently_listening_subtitle, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->home_page_recently_listening_subtitle, &lv_font_PingFangSC_Regular_14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->home_page_recently_listening_subtitle, 211, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->home_page_recently_listening_subtitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->home_page_recently_listening_subtitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->home_page_recently_listening_subtitle, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->home_page_recently_listening_subtitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->home_page_recently_listening_subtitle, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->home_page_recently_listening_subtitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->home_page_recently_listening_subtitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->home_page_recently_listening_subtitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->home_page_recently_listening_subtitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes home_page_recently_listening_title
    ui->home_page_recently_listening_title = lv_label_create(ui->home_page_recently_listening);
    lv_obj_set_pos(ui->home_page_recently_listening_title, 43, 102);
    lv_obj_set_size(ui->home_page_recently_listening_title, 72, 22);
    lv_label_set_text(ui->home_page_recently_listening_title, "最近熏听");
    lv_label_set_long_mode(ui->home_page_recently_listening_title, LV_LABEL_LONG_WRAP);

    //Write style for home_page_recently_listening_title, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->home_page_recently_listening_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->home_page_recently_listening_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->home_page_recently_listening_title, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->home_page_recently_listening_title, &lv_font_FZCuYuan_M03S_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->home_page_recently_listening_title, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->home_page_recently_listening_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->home_page_recently_listening_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->home_page_recently_listening_title, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->home_page_recently_listening_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->home_page_recently_listening_title, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->home_page_recently_listening_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->home_page_recently_listening_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->home_page_recently_listening_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->home_page_recently_listening_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes home_page_recently_listening_icon
    ui->home_page_recently_listening_icon = lv_image_create(ui->home_page_recently_listening);
    lv_obj_set_pos(ui->home_page_recently_listening_icon, 44, 25);
    lv_obj_set_size(ui->home_page_recently_listening_icon, 70, 70);
    lv_obj_add_flag(ui->home_page_recently_listening_icon, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->home_page_recently_listening_icon, &_recently_listening_icon2_RGB565A8_70x70);
    lv_image_set_pivot(ui->home_page_recently_listening_icon, 50,50);
    lv_image_set_rotation(ui->home_page_recently_listening_icon, 0);

    //Write style for home_page_recently_listening_icon, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->home_page_recently_listening_icon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->home_page_recently_listening_icon, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes home_page_today_listening_2
    ui->home_page_today_listening_2 = lv_obj_create(ui->home_page_subpage_entry);
    lv_obj_set_pos(ui->home_page_today_listening_2, 931, 50);
    lv_obj_set_size(ui->home_page_today_listening_2, 158, 168);
    lv_obj_set_scrollbar_mode(ui->home_page_today_listening_2, LV_SCROLLBAR_MODE_OFF);

    //Write style for home_page_today_listening_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->home_page_today_listening_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->home_page_today_listening_2, 36, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->home_page_today_listening_2, 28, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->home_page_today_listening_2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->home_page_today_listening_2, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->home_page_today_listening_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->home_page_today_listening_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->home_page_today_listening_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->home_page_today_listening_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->home_page_today_listening_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes home_page_today_listening_subtitle_2
    ui->home_page_today_listening_subtitle_2 = lv_label_create(ui->home_page_today_listening_2);
    lv_obj_set_pos(ui->home_page_today_listening_subtitle_2, 10, 128);
    lv_obj_set_size(ui->home_page_today_listening_subtitle_2, 138, 20);
    lv_label_set_text(ui->home_page_today_listening_subtitle_2, "完播动画智能推荐");
    lv_label_set_long_mode(ui->home_page_today_listening_subtitle_2, LV_LABEL_LONG_WRAP);

    //Write style for home_page_today_listening_subtitle_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->home_page_today_listening_subtitle_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->home_page_today_listening_subtitle_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->home_page_today_listening_subtitle_2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->home_page_today_listening_subtitle_2, &lv_font_PingFangSC_Regular_14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->home_page_today_listening_subtitle_2, 211, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->home_page_today_listening_subtitle_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->home_page_today_listening_subtitle_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->home_page_today_listening_subtitle_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->home_page_today_listening_subtitle_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->home_page_today_listening_subtitle_2, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->home_page_today_listening_subtitle_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->home_page_today_listening_subtitle_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->home_page_today_listening_subtitle_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->home_page_today_listening_subtitle_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes home_page_today_listening_title_2
    ui->home_page_today_listening_title_2 = lv_label_create(ui->home_page_today_listening_2);
    lv_obj_set_pos(ui->home_page_today_listening_title_2, 43, 103);
    lv_obj_set_size(ui->home_page_today_listening_title_2, 72, 22);
    lv_label_set_text(ui->home_page_today_listening_title_2, "今日熏听");
    lv_label_set_long_mode(ui->home_page_today_listening_title_2, LV_LABEL_LONG_WRAP);

    //Write style for home_page_today_listening_title_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->home_page_today_listening_title_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->home_page_today_listening_title_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->home_page_today_listening_title_2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->home_page_today_listening_title_2, &lv_font_FZCuYuan_M03S_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->home_page_today_listening_title_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->home_page_today_listening_title_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->home_page_today_listening_title_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->home_page_today_listening_title_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->home_page_today_listening_title_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->home_page_today_listening_title_2, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->home_page_today_listening_title_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->home_page_today_listening_title_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->home_page_today_listening_title_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->home_page_today_listening_title_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes home_page_today_listening_icon_2
    ui->home_page_today_listening_icon_2 = lv_image_create(ui->home_page_today_listening_2);
    lv_obj_set_pos(ui->home_page_today_listening_icon_2, 45, 24);
    lv_obj_set_size(ui->home_page_today_listening_icon_2, 82, 70);
    lv_obj_add_flag(ui->home_page_today_listening_icon_2, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->home_page_today_listening_icon_2, &_today_listening_icon_RGB565A8_82x70);
    lv_image_set_pivot(ui->home_page_today_listening_icon_2, 50,50);
    lv_image_set_rotation(ui->home_page_today_listening_icon_2, 0);

    //Write style for home_page_today_listening_icon_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->home_page_today_listening_icon_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->home_page_today_listening_icon_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes home_page_play_icon_2
    ui->home_page_play_icon_2 = lv_image_create(ui->home_page_today_listening_2);
    lv_obj_set_pos(ui->home_page_play_icon_2, 62, 41);
    lv_obj_set_size(ui->home_page_play_icon_2, 34, 34);
    lv_obj_add_flag(ui->home_page_play_icon_2, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->home_page_play_icon_2, &_play_button2_RGB565A8_34x34);
    lv_image_set_pivot(ui->home_page_play_icon_2, 50,50);
    lv_image_set_rotation(ui->home_page_play_icon_2, 0);

    //Write style for home_page_play_icon_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->home_page_play_icon_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->home_page_play_icon_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes home_page_today_listening_1
    ui->home_page_today_listening_1 = lv_obj_create(ui->home_page_subpage_entry);
    lv_obj_set_pos(ui->home_page_today_listening_1, -849, 50);
    lv_obj_set_size(ui->home_page_today_listening_1, 158, 168);
    lv_obj_set_scrollbar_mode(ui->home_page_today_listening_1, LV_SCROLLBAR_MODE_OFF);

    //Write style for home_page_today_listening_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->home_page_today_listening_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->home_page_today_listening_1, 36, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->home_page_today_listening_1, 28, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->home_page_today_listening_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->home_page_today_listening_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->home_page_today_listening_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->home_page_today_listening_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->home_page_today_listening_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->home_page_today_listening_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->home_page_today_listening_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes home_page_today_listening_subtitle_1
    ui->home_page_today_listening_subtitle_1 = lv_label_create(ui->home_page_today_listening_1);
    lv_obj_set_pos(ui->home_page_today_listening_subtitle_1, 10, 128);
    lv_obj_set_size(ui->home_page_today_listening_subtitle_1, 138, 20);
    lv_label_set_text(ui->home_page_today_listening_subtitle_1, "完播动画智能推荐");
    lv_label_set_long_mode(ui->home_page_today_listening_subtitle_1, LV_LABEL_LONG_WRAP);

    //Write style for home_page_today_listening_subtitle_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->home_page_today_listening_subtitle_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->home_page_today_listening_subtitle_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->home_page_today_listening_subtitle_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->home_page_today_listening_subtitle_1, &lv_font_PingFangSC_Regular_14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->home_page_today_listening_subtitle_1, 211, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->home_page_today_listening_subtitle_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->home_page_today_listening_subtitle_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->home_page_today_listening_subtitle_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->home_page_today_listening_subtitle_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->home_page_today_listening_subtitle_1, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->home_page_today_listening_subtitle_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->home_page_today_listening_subtitle_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->home_page_today_listening_subtitle_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->home_page_today_listening_subtitle_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes home_page_today_listening_title_1
    ui->home_page_today_listening_title_1 = lv_label_create(ui->home_page_today_listening_1);
    lv_obj_set_pos(ui->home_page_today_listening_title_1, 43, 103);
    lv_obj_set_size(ui->home_page_today_listening_title_1, 72, 22);
    lv_label_set_text(ui->home_page_today_listening_title_1, "今日熏听");
    lv_label_set_long_mode(ui->home_page_today_listening_title_1, LV_LABEL_LONG_WRAP);

    //Write style for home_page_today_listening_title_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->home_page_today_listening_title_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->home_page_today_listening_title_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->home_page_today_listening_title_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->home_page_today_listening_title_1, &lv_font_FZCuYuan_M03S_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->home_page_today_listening_title_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->home_page_today_listening_title_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->home_page_today_listening_title_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->home_page_today_listening_title_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->home_page_today_listening_title_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->home_page_today_listening_title_1, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->home_page_today_listening_title_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->home_page_today_listening_title_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->home_page_today_listening_title_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->home_page_today_listening_title_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes home_page_today_listening_icon_1
    ui->home_page_today_listening_icon_1 = lv_image_create(ui->home_page_today_listening_1);
    lv_obj_set_pos(ui->home_page_today_listening_icon_1, 45, 24);
    lv_obj_set_size(ui->home_page_today_listening_icon_1, 82, 70);
    lv_obj_add_flag(ui->home_page_today_listening_icon_1, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->home_page_today_listening_icon_1, &_today_listening_icon_RGB565A8_82x70);
    lv_image_set_pivot(ui->home_page_today_listening_icon_1, 50,50);
    lv_image_set_rotation(ui->home_page_today_listening_icon_1, 0);

    //Write style for home_page_today_listening_icon_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->home_page_today_listening_icon_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->home_page_today_listening_icon_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes home_page_play_icon_1
    ui->home_page_play_icon_1 = lv_image_create(ui->home_page_today_listening_1);
    lv_obj_set_pos(ui->home_page_play_icon_1, 62, 41);
    lv_obj_set_size(ui->home_page_play_icon_1, 34, 34);
    lv_obj_add_flag(ui->home_page_play_icon_1, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->home_page_play_icon_1, &_play_button2_RGB565A8_34x34);
    lv_image_set_pivot(ui->home_page_play_icon_1, 50,50);
    lv_image_set_rotation(ui->home_page_play_icon_1, 0);

    //Write style for home_page_play_icon_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->home_page_play_icon_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->home_page_play_icon_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes home_page_today_listening
    ui->home_page_today_listening = lv_obj_create(ui->home_page_subpage_entry);
    lv_obj_set_pos(ui->home_page_today_listening, 41, 0);
    lv_obj_set_size(ui->home_page_today_listening, 158, 168);
    lv_obj_set_scrollbar_mode(ui->home_page_today_listening, LV_SCROLLBAR_MODE_OFF);

    //Write style for home_page_today_listening, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->home_page_today_listening, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->home_page_today_listening, 36, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->home_page_today_listening, 28, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->home_page_today_listening, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->home_page_today_listening, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->home_page_today_listening, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->home_page_today_listening, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->home_page_today_listening, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->home_page_today_listening, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->home_page_today_listening, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes home_page_today_listening_subtitle
    ui->home_page_today_listening_subtitle = lv_label_create(ui->home_page_today_listening);
    lv_obj_set_pos(ui->home_page_today_listening_subtitle, 10, 128);
    lv_obj_set_size(ui->home_page_today_listening_subtitle, 138, 20);
    lv_label_set_text(ui->home_page_today_listening_subtitle, "完播动画智能推荐");
    lv_label_set_long_mode(ui->home_page_today_listening_subtitle, LV_LABEL_LONG_WRAP);

    //Write style for home_page_today_listening_subtitle, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->home_page_today_listening_subtitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->home_page_today_listening_subtitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->home_page_today_listening_subtitle, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->home_page_today_listening_subtitle, &lv_font_PingFangSC_Regular_14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->home_page_today_listening_subtitle, 211, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->home_page_today_listening_subtitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->home_page_today_listening_subtitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->home_page_today_listening_subtitle, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->home_page_today_listening_subtitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->home_page_today_listening_subtitle, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->home_page_today_listening_subtitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->home_page_today_listening_subtitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->home_page_today_listening_subtitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->home_page_today_listening_subtitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes home_page_today_listening_title
    ui->home_page_today_listening_title = lv_label_create(ui->home_page_today_listening);
    lv_obj_set_pos(ui->home_page_today_listening_title, 43, 103);
    lv_obj_set_size(ui->home_page_today_listening_title, 72, 22);
    lv_label_set_text(ui->home_page_today_listening_title, "今日熏听");
    lv_label_set_long_mode(ui->home_page_today_listening_title, LV_LABEL_LONG_WRAP);

    //Write style for home_page_today_listening_title, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->home_page_today_listening_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->home_page_today_listening_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->home_page_today_listening_title, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->home_page_today_listening_title, &lv_font_FZCuYuan_M03S_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->home_page_today_listening_title, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->home_page_today_listening_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->home_page_today_listening_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->home_page_today_listening_title, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->home_page_today_listening_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->home_page_today_listening_title, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->home_page_today_listening_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->home_page_today_listening_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->home_page_today_listening_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->home_page_today_listening_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes home_page_today_listening_icon
    ui->home_page_today_listening_icon = lv_image_create(ui->home_page_today_listening);
    lv_obj_set_pos(ui->home_page_today_listening_icon, 45, 24);
    lv_obj_set_size(ui->home_page_today_listening_icon, 82, 70);
    lv_obj_add_flag(ui->home_page_today_listening_icon, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->home_page_today_listening_icon, &_today_listening_icon_RGB565A8_82x70);
    lv_image_set_pivot(ui->home_page_today_listening_icon, 50,50);
    lv_image_set_rotation(ui->home_page_today_listening_icon, 0);

    //Write style for home_page_today_listening_icon, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->home_page_today_listening_icon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->home_page_today_listening_icon, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes home_page_play_icon
    ui->home_page_play_icon = lv_image_create(ui->home_page_today_listening);
    lv_obj_set_pos(ui->home_page_play_icon, 62, 41);
    lv_obj_set_size(ui->home_page_play_icon, 34, 34);
    lv_obj_add_flag(ui->home_page_play_icon, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->home_page_play_icon, &_play_button2_RGB565A8_34x34);
    lv_image_set_pivot(ui->home_page_play_icon, 50,50);
    lv_image_set_rotation(ui->home_page_play_icon, 0);

    //Write style for home_page_play_icon, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->home_page_play_icon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->home_page_play_icon, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes home_page_quick_play_panel
    ui->home_page_quick_play_panel = lv_obj_create(ui->home_page);
    lv_obj_set_pos(ui->home_page_quick_play_panel, 16, 248);
    lv_obj_set_size(ui->home_page_quick_play_panel, 208, 52);
    lv_obj_set_scrollbar_mode(ui->home_page_quick_play_panel, LV_SCROLLBAR_MODE_OFF);

    //Write style for home_page_quick_play_panel, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->home_page_quick_play_panel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->home_page_quick_play_panel, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->home_page_quick_play_panel, 26, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->home_page_quick_play_panel, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->home_page_quick_play_panel, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->home_page_quick_play_panel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->home_page_quick_play_panel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->home_page_quick_play_panel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->home_page_quick_play_panel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->home_page_quick_play_panel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes home_page_play_button
    ui->home_page_play_button = lv_imagebutton_create(ui->home_page_quick_play_panel);
    lv_obj_set_pos(ui->home_page_play_button, 159, 6);
    lv_obj_set_size(ui->home_page_play_button, 40, 40);
    lv_obj_add_flag(ui->home_page_play_button, LV_OBJ_FLAG_CHECKABLE);
    lv_imagebutton_set_src(ui->home_page_play_button, LV_IMAGEBUTTON_STATE_RELEASED, &_play_button3_RGB565A8_40x40, NULL, NULL);
    lv_imagebutton_set_src(ui->home_page_play_button, LV_IMAGEBUTTON_STATE_PRESSED, &_pause_button3_RGB565A8_40x40, NULL, NULL);
    lv_imagebutton_set_src(ui->home_page_play_button, LV_IMAGEBUTTON_STATE_CHECKED_RELEASED, &_pause_button3_RGB565A8_40x40, NULL, NULL);
    lv_imagebutton_set_src(ui->home_page_play_button, LV_IMAGEBUTTON_STATE_CHECKED_PRESSED, &_play_button3_RGB565A8_40x40, NULL, NULL);
    ui->home_page_play_button_label = lv_label_create(ui->home_page_play_button);
    lv_label_set_text(ui->home_page_play_button_label, "");
    lv_label_set_long_mode(ui->home_page_play_button_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->home_page_play_button_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->home_page_play_button, 0, LV_STATE_DEFAULT);

    //Write style for home_page_play_button, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->home_page_play_button, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->home_page_play_button, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->home_page_play_button, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->home_page_play_button, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->home_page_play_button, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for home_page_play_button, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_image_recolor_opa(ui->home_page_play_button, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_image_opa(ui->home_page_play_button, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->home_page_play_button, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->home_page_play_button, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->home_page_play_button, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->home_page_play_button, 0, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for home_page_play_button, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_image_recolor_opa(ui->home_page_play_button, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_image_opa(ui->home_page_play_button, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->home_page_play_button, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->home_page_play_button, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->home_page_play_button, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->home_page_play_button, 0, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for home_page_play_button, Part: LV_PART_MAIN, State: LV_IMAGEBUTTON_STATE_RELEASED.
    lv_obj_set_style_image_recolor_opa(ui->home_page_play_button, 0, LV_PART_MAIN|LV_IMAGEBUTTON_STATE_RELEASED);
    lv_obj_set_style_image_opa(ui->home_page_play_button, 255, LV_PART_MAIN|LV_IMAGEBUTTON_STATE_RELEASED);

    //Write codes home_page_song_title
    ui->home_page_song_title = lv_label_create(ui->home_page_quick_play_panel);
    lv_obj_set_pos(ui->home_page_song_title, 52, 15);
    lv_obj_set_size(ui->home_page_song_title, 108, 22);
    lv_label_set_text(ui->home_page_song_title, "Lots of Shallots isaa Shallots");
    lv_label_set_long_mode(ui->home_page_song_title, LV_LABEL_LONG_SCROLL_CIRCULAR);

    //Write style for home_page_song_title, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->home_page_song_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->home_page_song_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->home_page_song_title, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->home_page_song_title, &lv_font_PingFangSC_Semibold_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->home_page_song_title, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->home_page_song_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->home_page_song_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->home_page_song_title, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->home_page_song_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->home_page_song_title, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->home_page_song_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->home_page_song_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->home_page_song_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->home_page_song_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes home_page_mask_home_cover
    ui->home_page_mask_home_cover = lv_obj_create(ui->home_page_quick_play_panel);
    lv_obj_set_pos(ui->home_page_mask_home_cover, 8, 8);
    lv_obj_set_size(ui->home_page_mask_home_cover, 36, 36);
    lv_obj_set_scrollbar_mode(ui->home_page_mask_home_cover, LV_SCROLLBAR_MODE_OFF);

    //Write style for home_page_mask_home_cover, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->home_page_mask_home_cover, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->home_page_mask_home_cover, 36, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->home_page_mask_home_cover, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->home_page_mask_home_cover, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->home_page_mask_home_cover, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->home_page_mask_home_cover, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->home_page_mask_home_cover, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->home_page_mask_home_cover, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui->home_page_mask_home_cover, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui->home_page_mask_home_cover, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui->home_page_mask_home_cover, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(ui->home_page_mask_home_cover, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(ui->home_page_mask_home_cover, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes home_page_music_cover
    ui->home_page_music_cover = lv_image_create(ui->home_page_mask_home_cover);
    lv_obj_set_pos(ui->home_page_music_cover, -2, -2);
    lv_obj_set_size(ui->home_page_music_cover, 40, 40);
    lv_obj_add_flag(ui->home_page_music_cover, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->home_page_music_cover, &_music_cover_example_RGB565A8_40x40);
    lv_image_set_pivot(ui->home_page_music_cover, 18,18);
    lv_image_set_rotation(ui->home_page_music_cover, 0);

    //Write style for home_page_music_cover, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->home_page_music_cover, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->home_page_music_cover, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of home_page.
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
    lv_obj_remove_flag(ui->home_page_mask_home_cover, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_remove_flag(ui->home_page_music_cover, LV_OBJ_FLAG_CLICKABLE);

// 使用自定义字体
    lv_obj_set_style_text_font(ui->home_page_song_title, &lv_font_MyPingFangSC_Semibold_16, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_image_set_inner_align(ui->home_page_music_cover, LV_IMAGE_ALIGN_STRETCH);
    lv_obj_set_style_transform_pivot_x(ui->home_page_mask_home_cover, 18, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_transform_pivot_y(ui->home_page_mask_home_cover, 18, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->home_page_mask_home_cover, true, 0);

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
// lv_group_focus_obj(guider_ui.home_page_today_listening);
// for (int i = 0; i < 13; i++)
// {
// 	lv_obj_add_style(children[i], &style_focus, LV_PART_MAIN | LV_STATE_FOCUSED);
// }
//添加所有可滚动的子对象到组中
    for (int i = 0; i < 13; i++)
    {
        lv_group_add_obj(home_group, children[i]);
    }
// 🔥 关键：控制滚动速度和惯性
    lv_obj_set_style_anim_time(ui->home_page_subpage_entry, 2000, LV_STATE_DEFAULT); // 增加动画时间使滚动变慢

    //Update current screen layout.
    lv_obj_update_layout(ui->home_page);

    //Init events for screen.
    events_init_home_page(ui);
}
