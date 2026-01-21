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



void setup_scr_network_and_bluetooth_page(lv_ui *ui)
{
    //Write codes network_and_bluetooth_page
    ui->network_and_bluetooth_page = lv_obj_create(NULL);
    lv_obj_set_size(ui->network_and_bluetooth_page, 240, 320);
    lv_obj_set_scrollbar_mode(ui->network_and_bluetooth_page, LV_SCROLLBAR_MODE_OFF);

    //Write style for network_and_bluetooth_page, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->network_and_bluetooth_page, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->network_and_bluetooth_page, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->network_and_bluetooth_page, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes network_and_bluetooth_page_subpage_entry
    ui->network_and_bluetooth_page_subpage_entry = lv_obj_create(ui->network_and_bluetooth_page);
    lv_obj_set_pos(ui->network_and_bluetooth_page_subpage_entry, 0, 64);
    lv_obj_set_size(ui->network_and_bluetooth_page_subpage_entry, 240, 256);
    lv_obj_set_scrollbar_mode(ui->network_and_bluetooth_page_subpage_entry, LV_SCROLLBAR_MODE_OFF);

    //Write style for network_and_bluetooth_page_subpage_entry, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->network_and_bluetooth_page_subpage_entry, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->network_and_bluetooth_page_subpage_entry, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->network_and_bluetooth_page_subpage_entry, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->network_and_bluetooth_page_subpage_entry, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->network_and_bluetooth_page_subpage_entry, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->network_and_bluetooth_page_subpage_entry, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->network_and_bluetooth_page_subpage_entry, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->network_and_bluetooth_page_subpage_entry, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes network_and_bluetooth_page_bt_pair_up
    ui->network_and_bluetooth_page_bt_pair_up = lv_obj_create(ui->network_and_bluetooth_page_subpage_entry);
    lv_obj_set_pos(ui->network_and_bluetooth_page_bt_pair_up, 16, 82);
    lv_obj_set_size(ui->network_and_bluetooth_page_bt_pair_up, 208, 64);
    lv_obj_set_scrollbar_mode(ui->network_and_bluetooth_page_bt_pair_up, LV_SCROLLBAR_MODE_OFF);

    //Write style for network_and_bluetooth_page_bt_pair_up, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->network_and_bluetooth_page_bt_pair_up, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->network_and_bluetooth_page_bt_pair_up, 14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->network_and_bluetooth_page_bt_pair_up, 51, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->network_and_bluetooth_page_bt_pair_up, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->network_and_bluetooth_page_bt_pair_up, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->network_and_bluetooth_page_bt_pair_up, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->network_and_bluetooth_page_bt_pair_up, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->network_and_bluetooth_page_bt_pair_up, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->network_and_bluetooth_page_bt_pair_up, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->network_and_bluetooth_page_bt_pair_up, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes network_and_bluetooth_page_bt_scan_code_button
    ui->network_and_bluetooth_page_bt_scan_code_button = lv_image_create(ui->network_and_bluetooth_page_bt_pair_up);
    lv_obj_set_pos(ui->network_and_bluetooth_page_bt_scan_code_button, 174, 20);
    lv_obj_set_size(ui->network_and_bluetooth_page_bt_scan_code_button, 24, 24);
    lv_obj_add_flag(ui->network_and_bluetooth_page_bt_scan_code_button, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->network_and_bluetooth_page_bt_scan_code_button, &_wifi_scan_code_RGB565A8_24x24);
    lv_image_set_pivot(ui->network_and_bluetooth_page_bt_scan_code_button, 50,50);
    lv_image_set_rotation(ui->network_and_bluetooth_page_bt_scan_code_button, 0);

    //Write style for network_and_bluetooth_page_bt_scan_code_button, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->network_and_bluetooth_page_bt_scan_code_button, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->network_and_bluetooth_page_bt_scan_code_button, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes network_and_bluetooth_page_bt_pair_up_title
    ui->network_and_bluetooth_page_bt_pair_up_title = lv_label_create(ui->network_and_bluetooth_page_bt_pair_up);
    lv_obj_set_pos(ui->network_and_bluetooth_page_bt_pair_up_title, 44, 19);
    lv_obj_set_size(ui->network_and_bluetooth_page_bt_pair_up_title, 120, 25);
    lv_label_set_text(ui->network_and_bluetooth_page_bt_pair_up_title, "扫码配对");
    lv_label_set_long_mode(ui->network_and_bluetooth_page_bt_pair_up_title, LV_LABEL_LONG_WRAP);

    //Write style for network_and_bluetooth_page_bt_pair_up_title, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->network_and_bluetooth_page_bt_pair_up_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->network_and_bluetooth_page_bt_pair_up_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->network_and_bluetooth_page_bt_pair_up_title, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->network_and_bluetooth_page_bt_pair_up_title, &lv_font_PingFangSC_Medium_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->network_and_bluetooth_page_bt_pair_up_title, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->network_and_bluetooth_page_bt_pair_up_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->network_and_bluetooth_page_bt_pair_up_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->network_and_bluetooth_page_bt_pair_up_title, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->network_and_bluetooth_page_bt_pair_up_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->network_and_bluetooth_page_bt_pair_up_title, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->network_and_bluetooth_page_bt_pair_up_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->network_and_bluetooth_page_bt_pair_up_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->network_and_bluetooth_page_bt_pair_up_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->network_and_bluetooth_page_bt_pair_up_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes network_and_bluetooth_page_bt_pair_up_icon
    ui->network_and_bluetooth_page_bt_pair_up_icon = lv_image_create(ui->network_and_bluetooth_page_bt_pair_up);
    lv_obj_set_pos(ui->network_and_bluetooth_page_bt_pair_up_icon, 10, 17);
    lv_obj_set_size(ui->network_and_bluetooth_page_bt_pair_up_icon, 30, 30);
    lv_obj_add_flag(ui->network_and_bluetooth_page_bt_pair_up_icon, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->network_and_bluetooth_page_bt_pair_up_icon, &_bluetooth_RGB565A8_30x30);
    lv_image_set_pivot(ui->network_and_bluetooth_page_bt_pair_up_icon, 50,50);
    lv_image_set_rotation(ui->network_and_bluetooth_page_bt_pair_up_icon, 0);

    //Write style for network_and_bluetooth_page_bt_pair_up_icon, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->network_and_bluetooth_page_bt_pair_up_icon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->network_and_bluetooth_page_bt_pair_up_icon, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes network_and_bluetooth_page_wifi_pair_up
    ui->network_and_bluetooth_page_wifi_pair_up = lv_obj_create(ui->network_and_bluetooth_page_subpage_entry);
    lv_obj_set_pos(ui->network_and_bluetooth_page_wifi_pair_up, 16, 10);
    lv_obj_set_size(ui->network_and_bluetooth_page_wifi_pair_up, 208, 64);
    lv_obj_set_scrollbar_mode(ui->network_and_bluetooth_page_wifi_pair_up, LV_SCROLLBAR_MODE_OFF);

    //Write style for network_and_bluetooth_page_wifi_pair_up, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->network_and_bluetooth_page_wifi_pair_up, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->network_and_bluetooth_page_wifi_pair_up, 14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->network_and_bluetooth_page_wifi_pair_up, 51, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->network_and_bluetooth_page_wifi_pair_up, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->network_and_bluetooth_page_wifi_pair_up, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->network_and_bluetooth_page_wifi_pair_up, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->network_and_bluetooth_page_wifi_pair_up, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->network_and_bluetooth_page_wifi_pair_up, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->network_and_bluetooth_page_wifi_pair_up, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->network_and_bluetooth_page_wifi_pair_up, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes network_and_bluetooth_page_wifi_scan_code_button
    ui->network_and_bluetooth_page_wifi_scan_code_button = lv_image_create(ui->network_and_bluetooth_page_wifi_pair_up);
    lv_obj_set_pos(ui->network_and_bluetooth_page_wifi_scan_code_button, 172, 20);
    lv_obj_set_size(ui->network_and_bluetooth_page_wifi_scan_code_button, 24, 24);
    lv_obj_add_flag(ui->network_and_bluetooth_page_wifi_scan_code_button, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->network_and_bluetooth_page_wifi_scan_code_button, &_wifi_scan_code_RGB565A8_24x24);
    lv_image_set_pivot(ui->network_and_bluetooth_page_wifi_scan_code_button, 50,50);
    lv_image_set_rotation(ui->network_and_bluetooth_page_wifi_scan_code_button, 0);

    //Write style for network_and_bluetooth_page_wifi_scan_code_button, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->network_and_bluetooth_page_wifi_scan_code_button, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->network_and_bluetooth_page_wifi_scan_code_button, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes network_and_bluetooth_page_wifi_pair_up_title
    ui->network_and_bluetooth_page_wifi_pair_up_title = lv_label_create(ui->network_and_bluetooth_page_wifi_pair_up);
    lv_obj_set_pos(ui->network_and_bluetooth_page_wifi_pair_up_title, 44, 19);
    lv_obj_set_size(ui->network_and_bluetooth_page_wifi_pair_up_title, 72, 25);
    lv_label_set_text(ui->network_and_bluetooth_page_wifi_pair_up_title, "扫码配对");
    lv_label_set_long_mode(ui->network_and_bluetooth_page_wifi_pair_up_title, LV_LABEL_LONG_WRAP);

    //Write style for network_and_bluetooth_page_wifi_pair_up_title, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->network_and_bluetooth_page_wifi_pair_up_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->network_and_bluetooth_page_wifi_pair_up_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->network_and_bluetooth_page_wifi_pair_up_title, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->network_and_bluetooth_page_wifi_pair_up_title, &lv_font_PingFangSC_Medium_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->network_and_bluetooth_page_wifi_pair_up_title, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->network_and_bluetooth_page_wifi_pair_up_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->network_and_bluetooth_page_wifi_pair_up_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->network_and_bluetooth_page_wifi_pair_up_title, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->network_and_bluetooth_page_wifi_pair_up_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->network_and_bluetooth_page_wifi_pair_up_title, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->network_and_bluetooth_page_wifi_pair_up_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->network_and_bluetooth_page_wifi_pair_up_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->network_and_bluetooth_page_wifi_pair_up_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->network_and_bluetooth_page_wifi_pair_up_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes network_and_bluetooth_page_wifi_pair_up_icon
    ui->network_and_bluetooth_page_wifi_pair_up_icon = lv_image_create(ui->network_and_bluetooth_page_wifi_pair_up);
    lv_obj_set_pos(ui->network_and_bluetooth_page_wifi_pair_up_icon, 10, 17);
    lv_obj_set_size(ui->network_and_bluetooth_page_wifi_pair_up_icon, 30, 30);
    lv_obj_add_flag(ui->network_and_bluetooth_page_wifi_pair_up_icon, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->network_and_bluetooth_page_wifi_pair_up_icon, &_wifi_RGB565A8_30x30);
    lv_image_set_pivot(ui->network_and_bluetooth_page_wifi_pair_up_icon, 50,50);
    lv_image_set_rotation(ui->network_and_bluetooth_page_wifi_pair_up_icon, 0);

    //Write style for network_and_bluetooth_page_wifi_pair_up_icon, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->network_and_bluetooth_page_wifi_pair_up_icon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->network_and_bluetooth_page_wifi_pair_up_icon, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes network_and_bluetooth_page_status_bar
    ui->network_and_bluetooth_page_status_bar = lv_obj_create(ui->network_and_bluetooth_page);
    lv_obj_set_pos(ui->network_and_bluetooth_page_status_bar, 0, 0);
    lv_obj_set_size(ui->network_and_bluetooth_page_status_bar, 240, 64);
    lv_obj_set_scrollbar_mode(ui->network_and_bluetooth_page_status_bar, LV_SCROLLBAR_MODE_OFF);

    //Write style for network_and_bluetooth_page_status_bar, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->network_and_bluetooth_page_status_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->network_and_bluetooth_page_status_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->network_and_bluetooth_page_status_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->network_and_bluetooth_page_status_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->network_and_bluetooth_page_status_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->network_and_bluetooth_page_status_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->network_and_bluetooth_page_status_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->network_and_bluetooth_page_status_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes network_and_bluetooth_page_main_title
    ui->network_and_bluetooth_page_main_title = lv_label_create(ui->network_and_bluetooth_page_status_bar);
    lv_obj_set_pos(ui->network_and_bluetooth_page_main_title, 128, 32);
    lv_obj_set_size(ui->network_and_bluetooth_page_main_title, 100, 28);
    lv_label_set_text(ui->network_and_bluetooth_page_main_title, "网络与蓝牙");
    lv_label_set_long_mode(ui->network_and_bluetooth_page_main_title, LV_LABEL_LONG_WRAP);

    //Write style for network_and_bluetooth_page_main_title, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->network_and_bluetooth_page_main_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->network_and_bluetooth_page_main_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->network_and_bluetooth_page_main_title, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->network_and_bluetooth_page_main_title, &lv_font_PingFangSC_Medium_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->network_and_bluetooth_page_main_title, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->network_and_bluetooth_page_main_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->network_and_bluetooth_page_main_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->network_and_bluetooth_page_main_title, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->network_and_bluetooth_page_main_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->network_and_bluetooth_page_main_title, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->network_and_bluetooth_page_main_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->network_and_bluetooth_page_main_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->network_and_bluetooth_page_main_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->network_and_bluetooth_page_main_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes network_and_bluetooth_page_left_control_button
    ui->network_and_bluetooth_page_left_control_button = lv_image_create(ui->network_and_bluetooth_page_status_bar);
    lv_obj_set_pos(ui->network_and_bluetooth_page_left_control_button, 16, 16);
    lv_obj_set_size(ui->network_and_bluetooth_page_left_control_button, 40, 40);
    lv_obj_add_flag(ui->network_and_bluetooth_page_left_control_button, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->network_and_bluetooth_page_left_control_button, &_left_control_RGB565A8_40x40);
    lv_image_set_pivot(ui->network_and_bluetooth_page_left_control_button, 50,50);
    lv_image_set_rotation(ui->network_and_bluetooth_page_left_control_button, 0);

    //Write style for network_and_bluetooth_page_left_control_button, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->network_and_bluetooth_page_left_control_button, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->network_and_bluetooth_page_left_control_button, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of network_and_bluetooth_page.


    //Update current screen layout.
    lv_obj_update_layout(ui->network_and_bluetooth_page);

    //Init events for screen.
    events_init_network_and_bluetooth_page(ui);
}
