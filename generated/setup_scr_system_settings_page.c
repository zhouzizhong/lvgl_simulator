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



void setup_scr_system_settings_page(lv_ui *ui)
{
    //Write codes system_settings_page
    ui->system_settings_page = lv_obj_create(NULL);
    lv_obj_set_size(ui->system_settings_page, 240, 320);
    lv_obj_set_scrollbar_mode(ui->system_settings_page, LV_SCROLLBAR_MODE_OFF);

    //Write style for system_settings_page, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->system_settings_page, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->system_settings_page, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->system_settings_page, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes system_settings_page_subpage_entry
    ui->system_settings_page_subpage_entry = lv_obj_create(ui->system_settings_page);
    lv_obj_set_pos(ui->system_settings_page_subpage_entry, 0, 64);
    lv_obj_set_size(ui->system_settings_page_subpage_entry, 240, 256);
    lv_obj_set_scrollbar_mode(ui->system_settings_page_subpage_entry, LV_SCROLLBAR_MODE_OFF);

    //Write style for system_settings_page_subpage_entry, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->system_settings_page_subpage_entry, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->system_settings_page_subpage_entry, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->system_settings_page_subpage_entry, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->system_settings_page_subpage_entry, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->system_settings_page_subpage_entry, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->system_settings_page_subpage_entry, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->system_settings_page_subpage_entry, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->system_settings_page_subpage_entry, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes system_settings_page_bottom_mask
    ui->system_settings_page_bottom_mask = lv_obj_create(ui->system_settings_page_subpage_entry);
    lv_obj_set_pos(ui->system_settings_page_bottom_mask, 15, 300);
    lv_obj_set_size(ui->system_settings_page_bottom_mask, 208, 30);
    lv_obj_set_scrollbar_mode(ui->system_settings_page_bottom_mask, LV_SCROLLBAR_MODE_OFF);

    //Write style for system_settings_page_bottom_mask, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->system_settings_page_bottom_mask, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->system_settings_page_bottom_mask, 14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->system_settings_page_bottom_mask, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->system_settings_page_bottom_mask, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->system_settings_page_bottom_mask, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->system_settings_page_bottom_mask, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->system_settings_page_bottom_mask, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->system_settings_page_bottom_mask, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes system_settings_page_device_information
    ui->system_settings_page_device_information = lv_obj_create(ui->system_settings_page_subpage_entry);
    lv_obj_set_pos(ui->system_settings_page_device_information, 16, 225);
    lv_obj_set_size(ui->system_settings_page_device_information, 208, 68);
    lv_obj_set_scrollbar_mode(ui->system_settings_page_device_information, LV_SCROLLBAR_MODE_OFF);

    //Write style for system_settings_page_device_information, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->system_settings_page_device_information, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->system_settings_page_device_information, 14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->system_settings_page_device_information, 51, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->system_settings_page_device_information, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->system_settings_page_device_information, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->system_settings_page_device_information, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->system_settings_page_device_information, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->system_settings_page_device_information, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->system_settings_page_device_information, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->system_settings_page_device_information, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes system_settings_page_version_update_information
    ui->system_settings_page_version_update_information = lv_label_create(ui->system_settings_page_device_information);
    lv_obj_set_pos(ui->system_settings_page_version_update_information, 44, 36);
    lv_obj_set_size(ui->system_settings_page_version_update_information, 120, 20);
    lv_label_set_text(ui->system_settings_page_version_update_information, "新版本 V1.4.0");
    lv_label_set_long_mode(ui->system_settings_page_version_update_information, LV_LABEL_LONG_WRAP);

    //Write style for system_settings_page_version_update_information, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->system_settings_page_version_update_information, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->system_settings_page_version_update_information, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->system_settings_page_version_update_information, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->system_settings_page_version_update_information, &lv_font_PingFangSC_Regular_14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->system_settings_page_version_update_information, 186, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->system_settings_page_version_update_information, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->system_settings_page_version_update_information, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->system_settings_page_version_update_information, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->system_settings_page_version_update_information, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->system_settings_page_version_update_information, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->system_settings_page_version_update_information, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->system_settings_page_version_update_information, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->system_settings_page_version_update_information, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->system_settings_page_version_update_information, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes system_settings_page_device_information_title
    ui->system_settings_page_device_information_title = lv_label_create(ui->system_settings_page_device_information);
    lv_obj_set_pos(ui->system_settings_page_device_information_title, 44, 12);
    lv_obj_set_size(ui->system_settings_page_device_information_title, 120, 25);
    lv_label_set_text(ui->system_settings_page_device_information_title, "设备信息");
    lv_label_set_long_mode(ui->system_settings_page_device_information_title, LV_LABEL_LONG_WRAP);

    //Write style for system_settings_page_device_information_title, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->system_settings_page_device_information_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->system_settings_page_device_information_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->system_settings_page_device_information_title, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->system_settings_page_device_information_title, &lv_font_PingFangSC_Medium_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->system_settings_page_device_information_title, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->system_settings_page_device_information_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->system_settings_page_device_information_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->system_settings_page_device_information_title, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->system_settings_page_device_information_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->system_settings_page_device_information_title, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->system_settings_page_device_information_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->system_settings_page_device_information_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->system_settings_page_device_information_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->system_settings_page_device_information_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes system_settings_page_device_information_icon
    ui->system_settings_page_device_information_icon = lv_image_create(ui->system_settings_page_device_information);
    lv_obj_set_pos(ui->system_settings_page_device_information_icon, 10, 19);
    lv_obj_set_size(ui->system_settings_page_device_information_icon, 30, 30);
    lv_obj_add_flag(ui->system_settings_page_device_information_icon, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->system_settings_page_device_information_icon, &_device_information_icon_RGB565A8_30x30);
    lv_image_set_pivot(ui->system_settings_page_device_information_icon, 50,50);
    lv_image_set_rotation(ui->system_settings_page_device_information_icon, 0);

    //Write style for system_settings_page_device_information_icon, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->system_settings_page_device_information_icon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->system_settings_page_device_information_icon, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes system_settings_page_screen_brightness
    ui->system_settings_page_screen_brightness = lv_obj_create(ui->system_settings_page_subpage_entry);
    lv_obj_set_pos(ui->system_settings_page_screen_brightness, 16, 154);
    lv_obj_set_size(ui->system_settings_page_screen_brightness, 208, 64);
    lv_obj_set_scrollbar_mode(ui->system_settings_page_screen_brightness, LV_SCROLLBAR_MODE_OFF);

    //Write style for system_settings_page_screen_brightness, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->system_settings_page_screen_brightness, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->system_settings_page_screen_brightness, 14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->system_settings_page_screen_brightness, 51, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->system_settings_page_screen_brightness, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->system_settings_page_screen_brightness, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->system_settings_page_screen_brightness, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->system_settings_page_screen_brightness, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->system_settings_page_screen_brightness, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->system_settings_page_screen_brightness, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->system_settings_page_screen_brightness, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes system_settings_page_screen_brightness_title
    ui->system_settings_page_screen_brightness_title = lv_label_create(ui->system_settings_page_screen_brightness);
    lv_obj_set_pos(ui->system_settings_page_screen_brightness_title, 43, 18);
    lv_obj_set_size(ui->system_settings_page_screen_brightness_title, 120, 25);
    lv_label_set_text(ui->system_settings_page_screen_brightness_title, "屏幕亮度");
    lv_label_set_long_mode(ui->system_settings_page_screen_brightness_title, LV_LABEL_LONG_WRAP);

    //Write style for system_settings_page_screen_brightness_title, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->system_settings_page_screen_brightness_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->system_settings_page_screen_brightness_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->system_settings_page_screen_brightness_title, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->system_settings_page_screen_brightness_title, &lv_font_PingFangSC_Medium_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->system_settings_page_screen_brightness_title, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->system_settings_page_screen_brightness_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->system_settings_page_screen_brightness_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->system_settings_page_screen_brightness_title, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->system_settings_page_screen_brightness_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->system_settings_page_screen_brightness_title, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->system_settings_page_screen_brightness_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->system_settings_page_screen_brightness_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->system_settings_page_screen_brightness_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->system_settings_page_screen_brightness_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes system_settings_page_screen_brightness_icon
    ui->system_settings_page_screen_brightness_icon = lv_image_create(ui->system_settings_page_screen_brightness);
    lv_obj_set_pos(ui->system_settings_page_screen_brightness_icon, 10, 17);
    lv_obj_set_size(ui->system_settings_page_screen_brightness_icon, 30, 30);
    lv_obj_add_flag(ui->system_settings_page_screen_brightness_icon, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->system_settings_page_screen_brightness_icon, &_screen_brightness_icon_RGB565A8_30x30);
    lv_image_set_pivot(ui->system_settings_page_screen_brightness_icon, 50,50);
    lv_image_set_rotation(ui->system_settings_page_screen_brightness_icon, 0);

    //Write style for system_settings_page_screen_brightness_icon, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->system_settings_page_screen_brightness_icon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->system_settings_page_screen_brightness_icon, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes system_settings_page_network_and_bluetooth
    ui->system_settings_page_network_and_bluetooth = lv_obj_create(ui->system_settings_page_subpage_entry);
    lv_obj_set_pos(ui->system_settings_page_network_and_bluetooth, 16, 82);
    lv_obj_set_size(ui->system_settings_page_network_and_bluetooth, 208, 64);
    lv_obj_set_scrollbar_mode(ui->system_settings_page_network_and_bluetooth, LV_SCROLLBAR_MODE_OFF);

    //Write style for system_settings_page_network_and_bluetooth, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->system_settings_page_network_and_bluetooth, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->system_settings_page_network_and_bluetooth, 14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->system_settings_page_network_and_bluetooth, 51, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->system_settings_page_network_and_bluetooth, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->system_settings_page_network_and_bluetooth, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->system_settings_page_network_and_bluetooth, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->system_settings_page_network_and_bluetooth, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->system_settings_page_network_and_bluetooth, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->system_settings_page_network_and_bluetooth, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->system_settings_page_network_and_bluetooth, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes system_settings_page_network_and_bluetooth_title
    ui->system_settings_page_network_and_bluetooth_title = lv_label_create(ui->system_settings_page_network_and_bluetooth);
    lv_obj_set_pos(ui->system_settings_page_network_and_bluetooth_title, 44, 19);
    lv_obj_set_size(ui->system_settings_page_network_and_bluetooth_title, 120, 25);
    lv_label_set_text(ui->system_settings_page_network_and_bluetooth_title, "网络与蓝牙");
    lv_label_set_long_mode(ui->system_settings_page_network_and_bluetooth_title, LV_LABEL_LONG_WRAP);

    //Write style for system_settings_page_network_and_bluetooth_title, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->system_settings_page_network_and_bluetooth_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->system_settings_page_network_and_bluetooth_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->system_settings_page_network_and_bluetooth_title, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->system_settings_page_network_and_bluetooth_title, &lv_font_PingFangSC_Medium_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->system_settings_page_network_and_bluetooth_title, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->system_settings_page_network_and_bluetooth_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->system_settings_page_network_and_bluetooth_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->system_settings_page_network_and_bluetooth_title, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->system_settings_page_network_and_bluetooth_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->system_settings_page_network_and_bluetooth_title, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->system_settings_page_network_and_bluetooth_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->system_settings_page_network_and_bluetooth_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->system_settings_page_network_and_bluetooth_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->system_settings_page_network_and_bluetooth_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes system_settings_page_network_and_bluetooth_icon
    ui->system_settings_page_network_and_bluetooth_icon = lv_image_create(ui->system_settings_page_network_and_bluetooth);
    lv_obj_set_pos(ui->system_settings_page_network_and_bluetooth_icon, 10, 17);
    lv_obj_set_size(ui->system_settings_page_network_and_bluetooth_icon, 30, 30);
    lv_obj_add_flag(ui->system_settings_page_network_and_bluetooth_icon, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->system_settings_page_network_and_bluetooth_icon, &_network_and_bluetooth_icon_RGB565A8_30x30);
    lv_image_set_pivot(ui->system_settings_page_network_and_bluetooth_icon, 50,50);
    lv_image_set_rotation(ui->system_settings_page_network_and_bluetooth_icon, 0);

    //Write style for system_settings_page_network_and_bluetooth_icon, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->system_settings_page_network_and_bluetooth_icon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->system_settings_page_network_and_bluetooth_icon, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes system_settings_page_account_management
    ui->system_settings_page_account_management = lv_obj_create(ui->system_settings_page_subpage_entry);
    lv_obj_set_pos(ui->system_settings_page_account_management, 16, 10);
    lv_obj_set_size(ui->system_settings_page_account_management, 208, 64);
    lv_obj_set_scrollbar_mode(ui->system_settings_page_account_management, LV_SCROLLBAR_MODE_OFF);

    //Write style for system_settings_page_account_management, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->system_settings_page_account_management, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->system_settings_page_account_management, 14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->system_settings_page_account_management, 51, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->system_settings_page_account_management, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->system_settings_page_account_management, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->system_settings_page_account_management, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->system_settings_page_account_management, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->system_settings_page_account_management, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->system_settings_page_account_management, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->system_settings_page_account_management, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes system_settings_page_account_switching_icon
    ui->system_settings_page_account_switching_icon = lv_image_create(ui->system_settings_page_account_management);
    lv_obj_set_pos(ui->system_settings_page_account_switching_icon, 174, 20);
    lv_obj_set_size(ui->system_settings_page_account_switching_icon, 24, 24);
    lv_obj_add_flag(ui->system_settings_page_account_switching_icon, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->system_settings_page_account_switching_icon, &_account_switching_icon_RGB565A8_24x24);
    lv_image_set_pivot(ui->system_settings_page_account_switching_icon, 50,50);
    lv_image_set_rotation(ui->system_settings_page_account_switching_icon, 0);

    //Write style for system_settings_page_account_switching_icon, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->system_settings_page_account_switching_icon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->system_settings_page_account_switching_icon, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes system_settings_page_account_management_title
    ui->system_settings_page_account_management_title = lv_label_create(ui->system_settings_page_account_management);
    lv_obj_set_pos(ui->system_settings_page_account_management_title, 44, 19);
    lv_obj_set_size(ui->system_settings_page_account_management_title, 72, 25);
    lv_label_set_text(ui->system_settings_page_account_management_title, "账号管理");
    lv_label_set_long_mode(ui->system_settings_page_account_management_title, LV_LABEL_LONG_WRAP);

    //Write style for system_settings_page_account_management_title, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->system_settings_page_account_management_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->system_settings_page_account_management_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->system_settings_page_account_management_title, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->system_settings_page_account_management_title, &lv_font_PingFangSC_Medium_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->system_settings_page_account_management_title, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->system_settings_page_account_management_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->system_settings_page_account_management_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->system_settings_page_account_management_title, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->system_settings_page_account_management_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->system_settings_page_account_management_title, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->system_settings_page_account_management_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->system_settings_page_account_management_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->system_settings_page_account_management_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->system_settings_page_account_management_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes system_settings_page_account_management_icon
    ui->system_settings_page_account_management_icon = lv_image_create(ui->system_settings_page_account_management);
    lv_obj_set_pos(ui->system_settings_page_account_management_icon, 10, 17);
    lv_obj_set_size(ui->system_settings_page_account_management_icon, 30, 30);
    lv_obj_add_flag(ui->system_settings_page_account_management_icon, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->system_settings_page_account_management_icon, &_account_management_icon_RGB565A8_30x30);
    lv_image_set_pivot(ui->system_settings_page_account_management_icon, 50,50);
    lv_image_set_rotation(ui->system_settings_page_account_management_icon, 0);

    //Write style for system_settings_page_account_management_icon, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->system_settings_page_account_management_icon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->system_settings_page_account_management_icon, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes system_settings_page_status_bar
    ui->system_settings_page_status_bar = lv_obj_create(ui->system_settings_page);
    lv_obj_set_pos(ui->system_settings_page_status_bar, 0, 0);
    lv_obj_set_size(ui->system_settings_page_status_bar, 240, 64);
    lv_obj_set_scrollbar_mode(ui->system_settings_page_status_bar, LV_SCROLLBAR_MODE_OFF);

    //Write style for system_settings_page_status_bar, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->system_settings_page_status_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->system_settings_page_status_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->system_settings_page_status_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->system_settings_page_status_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->system_settings_page_status_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->system_settings_page_status_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->system_settings_page_status_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->system_settings_page_status_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes system_settings_page_main_title
    ui->system_settings_page_main_title = lv_label_create(ui->system_settings_page_status_bar);
    lv_obj_set_pos(ui->system_settings_page_main_title, 148, 32);
    lv_obj_set_size(ui->system_settings_page_main_title, 80, 28);
    lv_label_set_text(ui->system_settings_page_main_title, "系统设置");
    lv_label_set_long_mode(ui->system_settings_page_main_title, LV_LABEL_LONG_WRAP);

    //Write style for system_settings_page_main_title, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->system_settings_page_main_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->system_settings_page_main_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->system_settings_page_main_title, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->system_settings_page_main_title, &lv_font_PingFangSC_Medium_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->system_settings_page_main_title, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->system_settings_page_main_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->system_settings_page_main_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->system_settings_page_main_title, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->system_settings_page_main_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->system_settings_page_main_title, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->system_settings_page_main_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->system_settings_page_main_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->system_settings_page_main_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->system_settings_page_main_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes system_settings_page_left_control_button
    ui->system_settings_page_left_control_button = lv_image_create(ui->system_settings_page_status_bar);
    lv_obj_set_pos(ui->system_settings_page_left_control_button, 16, 16);
    lv_obj_set_size(ui->system_settings_page_left_control_button, 40, 40);
    lv_obj_add_flag(ui->system_settings_page_left_control_button, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->system_settings_page_left_control_button, &_left_control_RGB565A8_40x40);
    lv_image_set_pivot(ui->system_settings_page_left_control_button, 50,50);
    lv_image_set_rotation(ui->system_settings_page_left_control_button, 0);

    //Write style for system_settings_page_left_control_button, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->system_settings_page_left_control_button, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->system_settings_page_left_control_button, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of system_settings_page.
    lv_obj_remove_flag(ui->system_settings_page_account_management_icon, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_remove_flag(ui->system_settings_page_account_switching_icon, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_remove_flag(ui->system_settings_page_device_information_icon, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_remove_flag(ui->system_settings_page_screen_brightness_icon, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_remove_flag(ui->system_settings_page_network_and_bluetooth_icon, LV_OBJ_FLAG_CLICKABLE);

    lv_obj_add_style(ui->system_settings_page_device_information, &style_focus, LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_add_style(ui->system_settings_page_account_management, &style_focus, LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_add_style(ui->system_settings_page_network_and_bluetooth, &style_focus, LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_add_style(ui->system_settings_page_screen_brightness, &style_focus, LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_add_flag(ui->system_settings_page_device_information, LV_OBJ_FLAG_CLICK_FOCUSABLE);
    lv_obj_add_flag(ui->system_settings_page_account_management, LV_OBJ_FLAG_CLICK_FOCUSABLE);
    lv_obj_add_flag(ui->system_settings_page_network_and_bluetooth, LV_OBJ_FLAG_CLICK_FOCUSABLE);
    lv_obj_add_flag(ui->system_settings_page_screen_brightness, LV_OBJ_FLAG_CLICK_FOCUSABLE);
    lv_obj_add_flag(ui->system_settings_page_device_information, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    lv_obj_add_flag(ui->system_settings_page_account_management, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    lv_obj_add_flag(ui->system_settings_page_network_and_bluetooth, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    lv_obj_add_flag(ui->system_settings_page_screen_brightness, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    lv_obj_add_flag(ui->system_settings_page_device_information, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_remove_flag(ui->system_settings_page_device_information, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_add_flag(ui->system_settings_page_account_management, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_remove_flag(ui->system_settings_page_account_management, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_add_flag(ui->system_settings_page_network_and_bluetooth, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_remove_flag(ui->system_settings_page_network_and_bluetooth, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_add_flag(ui->system_settings_page_screen_brightness, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_remove_flag(ui->system_settings_page_screen_brightness, LV_OBJ_FLAG_SCROLLABLE);
    lv_group_add_obj(system_settings_group, ui->system_settings_page_account_management);
    lv_group_add_obj(system_settings_group, ui->system_settings_page_network_and_bluetooth);
    lv_group_add_obj(system_settings_group, ui->system_settings_page_screen_brightness);
    lv_group_add_obj(system_settings_group, ui->system_settings_page_device_information);

    //Update current screen layout.
    lv_obj_update_layout(ui->system_settings_page);

    //Init events for screen.
    events_init_system_settings_page(ui);
}
