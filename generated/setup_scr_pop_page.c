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



void setup_scr_pop_page(lv_ui *ui)
{
    //Write codes pop_page
    ui->pop_page = lv_obj_create(NULL);
    lv_obj_set_size(ui->pop_page, 240, 320);
    lv_obj_set_scrollbar_mode(ui->pop_page, LV_SCROLLBAR_MODE_OFF);

    //Write style for pop_page, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->pop_page, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->pop_page, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->pop_page, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes pop_page_status_bar
    ui->pop_page_status_bar = lv_obj_create(ui->pop_page);
    lv_obj_set_pos(ui->pop_page_status_bar, 0, 0);
    lv_obj_set_size(ui->pop_page_status_bar, 240, 64);
    lv_obj_set_scrollbar_mode(ui->pop_page_status_bar, LV_SCROLLBAR_MODE_OFF);

    //Write style for pop_page_status_bar, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->pop_page_status_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->pop_page_status_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->pop_page_status_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->pop_page_status_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->pop_page_status_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->pop_page_status_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->pop_page_status_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->pop_page_status_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes pop_page_delete_control_button
    ui->pop_page_delete_control_button = lv_image_create(ui->pop_page_status_bar);
    lv_obj_set_pos(ui->pop_page_delete_control_button, 16, 8);
    lv_obj_set_size(ui->pop_page_delete_control_button, 56, 56);
    lv_obj_add_flag(ui->pop_page_delete_control_button, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->pop_page_delete_control_button, &_delete_control_RGB565A8_56x56);
    lv_image_set_pivot(ui->pop_page_delete_control_button, 50,50);
    lv_image_set_rotation(ui->pop_page_delete_control_button, 0);

    //Write style for pop_page_delete_control_button, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->pop_page_delete_control_button, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->pop_page_delete_control_button, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes pop_page_battery_low_pop
    ui->pop_page_battery_low_pop = lv_obj_create(ui->pop_page);
    lv_obj_set_pos(ui->pop_page_battery_low_pop, 0, 64);
    lv_obj_set_size(ui->pop_page_battery_low_pop, 240, 256);
    lv_obj_set_scrollbar_mode(ui->pop_page_battery_low_pop, LV_SCROLLBAR_MODE_OFF);
    lv_obj_add_flag(ui->pop_page_battery_low_pop, LV_OBJ_FLAG_HIDDEN);

    //Write style for pop_page_battery_low_pop, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->pop_page_battery_low_pop, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->pop_page_battery_low_pop, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->pop_page_battery_low_pop, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->pop_page_battery_low_pop, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->pop_page_battery_low_pop, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->pop_page_battery_low_pop, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->pop_page_battery_low_pop, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->pop_page_battery_low_pop, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes pop_page_battery_low_tips
    ui->pop_page_battery_low_tips = lv_label_create(ui->pop_page_battery_low_pop);
    lv_obj_set_pos(ui->pop_page_battery_low_tips, 16, 126);
    lv_obj_set_size(ui->pop_page_battery_low_tips, 208, 44);
    lv_label_set_text(ui->pop_page_battery_low_tips, "电量快用完了\n快给我充电吧！");
    lv_label_set_long_mode(ui->pop_page_battery_low_tips, LV_LABEL_LONG_WRAP);

    //Write style for pop_page_battery_low_tips, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->pop_page_battery_low_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->pop_page_battery_low_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->pop_page_battery_low_tips, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->pop_page_battery_low_tips, &lv_font_PingFangSC_Medium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->pop_page_battery_low_tips, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->pop_page_battery_low_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->pop_page_battery_low_tips, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->pop_page_battery_low_tips, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->pop_page_battery_low_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->pop_page_battery_low_tips, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->pop_page_battery_low_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->pop_page_battery_low_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->pop_page_battery_low_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->pop_page_battery_low_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes pop_page_battery_low_icon
    ui->pop_page_battery_low_icon = lv_image_create(ui->pop_page_battery_low_pop);
    lv_obj_set_pos(ui->pop_page_battery_low_icon, 78, 40);
    lv_obj_set_size(ui->pop_page_battery_low_icon, 79, 65);
    lv_obj_add_flag(ui->pop_page_battery_low_icon, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->pop_page_battery_low_icon, &_battery_low_icon_RGB565A8_79x65);
    lv_image_set_pivot(ui->pop_page_battery_low_icon, 50,50);
    lv_image_set_rotation(ui->pop_page_battery_low_icon, 0);

    //Write style for pop_page_battery_low_icon, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->pop_page_battery_low_icon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->pop_page_battery_low_icon, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes pop_page_charging_pop
    ui->pop_page_charging_pop = lv_obj_create(ui->pop_page);
    lv_obj_set_pos(ui->pop_page_charging_pop, 0, 64);
    lv_obj_set_size(ui->pop_page_charging_pop, 240, 256);
    lv_obj_set_scrollbar_mode(ui->pop_page_charging_pop, LV_SCROLLBAR_MODE_OFF);
    lv_obj_add_flag(ui->pop_page_charging_pop, LV_OBJ_FLAG_HIDDEN);

    //Write style for pop_page_charging_pop, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->pop_page_charging_pop, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->pop_page_charging_pop, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->pop_page_charging_pop, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->pop_page_charging_pop, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->pop_page_charging_pop, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->pop_page_charging_pop, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->pop_page_charging_pop, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->pop_page_charging_pop, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes pop_page_charging_tips
    ui->pop_page_charging_tips = lv_label_create(ui->pop_page_charging_pop);
    lv_obj_set_pos(ui->pop_page_charging_tips, 16, 132);
    lv_obj_set_size(ui->pop_page_charging_tips, 208, 22);
    lv_label_set_text(ui->pop_page_charging_tips, "正在充电中...");
    lv_label_set_long_mode(ui->pop_page_charging_tips, LV_LABEL_LONG_WRAP);

    //Write style for pop_page_charging_tips, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->pop_page_charging_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->pop_page_charging_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->pop_page_charging_tips, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->pop_page_charging_tips, &lv_font_PingFangSC_Medium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->pop_page_charging_tips, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->pop_page_charging_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->pop_page_charging_tips, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->pop_page_charging_tips, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->pop_page_charging_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->pop_page_charging_tips, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->pop_page_charging_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->pop_page_charging_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->pop_page_charging_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->pop_page_charging_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes pop_page_charging_icon
    ui->pop_page_charging_icon = lv_image_create(ui->pop_page_charging_pop);
    lv_obj_set_pos(ui->pop_page_charging_icon, 78, 40);
    lv_obj_set_size(ui->pop_page_charging_icon, 79, 70);
    lv_obj_add_flag(ui->pop_page_charging_icon, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->pop_page_charging_icon, &_charging_icon_RGB565A8_79x70);
    lv_image_set_pivot(ui->pop_page_charging_icon, 50,50);
    lv_image_set_rotation(ui->pop_page_charging_icon, 0);

    //Write style for pop_page_charging_icon, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->pop_page_charging_icon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->pop_page_charging_icon, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes pop_page_headset_connected_pop
    ui->pop_page_headset_connected_pop = lv_obj_create(ui->pop_page);
    lv_obj_set_pos(ui->pop_page_headset_connected_pop, 0, 64);
    lv_obj_set_size(ui->pop_page_headset_connected_pop, 240, 256);
    lv_obj_set_scrollbar_mode(ui->pop_page_headset_connected_pop, LV_SCROLLBAR_MODE_OFF);
    lv_obj_add_flag(ui->pop_page_headset_connected_pop, LV_OBJ_FLAG_HIDDEN);

    //Write style for pop_page_headset_connected_pop, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->pop_page_headset_connected_pop, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->pop_page_headset_connected_pop, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->pop_page_headset_connected_pop, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->pop_page_headset_connected_pop, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->pop_page_headset_connected_pop, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->pop_page_headset_connected_pop, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->pop_page_headset_connected_pop, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->pop_page_headset_connected_pop, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes pop_page_headset_connected_tips
    ui->pop_page_headset_connected_tips = lv_label_create(ui->pop_page_headset_connected_pop);
    lv_obj_set_pos(ui->pop_page_headset_connected_tips, 16, 135);
    lv_obj_set_size(ui->pop_page_headset_connected_tips, 208, 22);
    lv_label_set_text(ui->pop_page_headset_connected_tips, "耳机已接入");
    lv_label_set_long_mode(ui->pop_page_headset_connected_tips, LV_LABEL_LONG_WRAP);

    //Write style for pop_page_headset_connected_tips, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->pop_page_headset_connected_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->pop_page_headset_connected_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->pop_page_headset_connected_tips, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->pop_page_headset_connected_tips, &lv_font_PingFangSC_Medium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->pop_page_headset_connected_tips, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->pop_page_headset_connected_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->pop_page_headset_connected_tips, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->pop_page_headset_connected_tips, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->pop_page_headset_connected_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->pop_page_headset_connected_tips, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->pop_page_headset_connected_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->pop_page_headset_connected_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->pop_page_headset_connected_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->pop_page_headset_connected_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes pop_page_headset_connected_icon
    ui->pop_page_headset_connected_icon = lv_image_create(ui->pop_page_headset_connected_pop);
    lv_obj_set_pos(ui->pop_page_headset_connected_icon, 80, 35);
    lv_obj_set_size(ui->pop_page_headset_connected_icon, 80, 78);
    lv_obj_add_flag(ui->pop_page_headset_connected_icon, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->pop_page_headset_connected_icon, &_bluetooth_headset_connected_icon_RGB565A8_80x78);
    lv_image_set_pivot(ui->pop_page_headset_connected_icon, 50,50);
    lv_image_set_rotation(ui->pop_page_headset_connected_icon, 0);

    //Write style for pop_page_headset_connected_icon, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->pop_page_headset_connected_icon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->pop_page_headset_connected_icon, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes pop_page_headset_disconnected_pop
    ui->pop_page_headset_disconnected_pop = lv_obj_create(ui->pop_page);
    lv_obj_set_pos(ui->pop_page_headset_disconnected_pop, 0, 64);
    lv_obj_set_size(ui->pop_page_headset_disconnected_pop, 240, 256);
    lv_obj_set_scrollbar_mode(ui->pop_page_headset_disconnected_pop, LV_SCROLLBAR_MODE_OFF);
    lv_obj_add_flag(ui->pop_page_headset_disconnected_pop, LV_OBJ_FLAG_HIDDEN);

    //Write style for pop_page_headset_disconnected_pop, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->pop_page_headset_disconnected_pop, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->pop_page_headset_disconnected_pop, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->pop_page_headset_disconnected_pop, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->pop_page_headset_disconnected_pop, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->pop_page_headset_disconnected_pop, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->pop_page_headset_disconnected_pop, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->pop_page_headset_disconnected_pop, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->pop_page_headset_disconnected_pop, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes pop_page_headset_disconnected_tips
    ui->pop_page_headset_disconnected_tips = lv_label_create(ui->pop_page_headset_disconnected_pop);
    lv_obj_set_pos(ui->pop_page_headset_disconnected_tips, 16, 135);
    lv_obj_set_size(ui->pop_page_headset_disconnected_tips, 208, 22);
    lv_label_set_text(ui->pop_page_headset_disconnected_tips, "耳机已断开");
    lv_label_set_long_mode(ui->pop_page_headset_disconnected_tips, LV_LABEL_LONG_WRAP);

    //Write style for pop_page_headset_disconnected_tips, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->pop_page_headset_disconnected_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->pop_page_headset_disconnected_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->pop_page_headset_disconnected_tips, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->pop_page_headset_disconnected_tips, &lv_font_PingFangSC_Medium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->pop_page_headset_disconnected_tips, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->pop_page_headset_disconnected_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->pop_page_headset_disconnected_tips, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->pop_page_headset_disconnected_tips, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->pop_page_headset_disconnected_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->pop_page_headset_disconnected_tips, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->pop_page_headset_disconnected_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->pop_page_headset_disconnected_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->pop_page_headset_disconnected_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->pop_page_headset_disconnected_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes pop_page_headset_disconnected_icon
    ui->pop_page_headset_disconnected_icon = lv_image_create(ui->pop_page_headset_disconnected_pop);
    lv_obj_set_pos(ui->pop_page_headset_disconnected_icon, 82, 35);
    lv_obj_set_size(ui->pop_page_headset_disconnected_icon, 74, 77);
    lv_obj_add_flag(ui->pop_page_headset_disconnected_icon, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->pop_page_headset_disconnected_icon, &_bluetooth_headset_disconnected_icon_RGB565A8_74x77);
    lv_image_set_pivot(ui->pop_page_headset_disconnected_icon, 50,50);
    lv_image_set_rotation(ui->pop_page_headset_disconnected_icon, 0);

    //Write style for pop_page_headset_disconnected_icon, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->pop_page_headset_disconnected_icon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->pop_page_headset_disconnected_icon, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes pop_page_charge_full_pop
    ui->pop_page_charge_full_pop = lv_obj_create(ui->pop_page);
    lv_obj_set_pos(ui->pop_page_charge_full_pop, 0, 64);
    lv_obj_set_size(ui->pop_page_charge_full_pop, 240, 256);
    lv_obj_set_scrollbar_mode(ui->pop_page_charge_full_pop, LV_SCROLLBAR_MODE_OFF);
    lv_obj_add_flag(ui->pop_page_charge_full_pop, LV_OBJ_FLAG_HIDDEN);

    //Write style for pop_page_charge_full_pop, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->pop_page_charge_full_pop, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->pop_page_charge_full_pop, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->pop_page_charge_full_pop, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->pop_page_charge_full_pop, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->pop_page_charge_full_pop, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->pop_page_charge_full_pop, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->pop_page_charge_full_pop, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->pop_page_charge_full_pop, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes pop_page_charge_full_tips
    ui->pop_page_charge_full_tips = lv_label_create(ui->pop_page_charge_full_pop);
    lv_obj_set_pos(ui->pop_page_charge_full_tips, 16, 126);
    lv_obj_set_size(ui->pop_page_charge_full_tips, 208, 44);
    lv_label_set_text(ui->pop_page_charge_full_tips, "电量已充满\n可以开始使用啦！");
    lv_label_set_long_mode(ui->pop_page_charge_full_tips, LV_LABEL_LONG_WRAP);

    //Write style for pop_page_charge_full_tips, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->pop_page_charge_full_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->pop_page_charge_full_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->pop_page_charge_full_tips, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->pop_page_charge_full_tips, &lv_font_PingFangSC_Medium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->pop_page_charge_full_tips, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->pop_page_charge_full_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->pop_page_charge_full_tips, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->pop_page_charge_full_tips, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->pop_page_charge_full_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->pop_page_charge_full_tips, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->pop_page_charge_full_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->pop_page_charge_full_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->pop_page_charge_full_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->pop_page_charge_full_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes pop_page_charge_full_icon
    ui->pop_page_charge_full_icon = lv_image_create(ui->pop_page_charge_full_pop);
    lv_obj_set_pos(ui->pop_page_charge_full_icon, 78, 40);
    lv_obj_set_size(ui->pop_page_charge_full_icon, 80, 70);
    lv_obj_add_flag(ui->pop_page_charge_full_icon, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->pop_page_charge_full_icon, &_charge_full_icon_RGB565A8_80x70);
    lv_image_set_pivot(ui->pop_page_charge_full_icon, 50,50);
    lv_image_set_rotation(ui->pop_page_charge_full_icon, 0);

    //Write style for pop_page_charge_full_icon, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->pop_page_charge_full_icon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->pop_page_charge_full_icon, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes pop_page_warning_general_pop
    ui->pop_page_warning_general_pop = lv_obj_create(ui->pop_page);
    lv_obj_set_pos(ui->pop_page_warning_general_pop, 0, 64);
    lv_obj_set_size(ui->pop_page_warning_general_pop, 240, 256);
    lv_obj_set_scrollbar_mode(ui->pop_page_warning_general_pop, LV_SCROLLBAR_MODE_OFF);
    lv_obj_add_flag(ui->pop_page_warning_general_pop, LV_OBJ_FLAG_HIDDEN);

    //Write style for pop_page_warning_general_pop, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->pop_page_warning_general_pop, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->pop_page_warning_general_pop, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->pop_page_warning_general_pop, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->pop_page_warning_general_pop, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->pop_page_warning_general_pop, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->pop_page_warning_general_pop, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->pop_page_warning_general_pop, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->pop_page_warning_general_pop, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes pop_page_warning_general_tips
    ui->pop_page_warning_general_tips = lv_label_create(ui->pop_page_warning_general_pop);
    lv_obj_set_pos(ui->pop_page_warning_general_tips, 15, 112);
    lv_obj_set_size(ui->pop_page_warning_general_tips, 208, 44);
    lv_label_set_text(ui->pop_page_warning_general_tips, "哎呀，出错啦\n请再试一次");
    lv_label_set_long_mode(ui->pop_page_warning_general_tips, LV_LABEL_LONG_WRAP);

    //Write style for pop_page_warning_general_tips, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->pop_page_warning_general_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->pop_page_warning_general_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->pop_page_warning_general_tips, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->pop_page_warning_general_tips, &lv_font_PingFangSC_Medium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->pop_page_warning_general_tips, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->pop_page_warning_general_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->pop_page_warning_general_tips, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->pop_page_warning_general_tips, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->pop_page_warning_general_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->pop_page_warning_general_tips, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->pop_page_warning_general_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->pop_page_warning_general_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->pop_page_warning_general_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->pop_page_warning_general_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes pop_page_warning_general_icon
    ui->pop_page_warning_general_icon = lv_image_create(ui->pop_page_warning_general_pop);
    lv_obj_set_pos(ui->pop_page_warning_general_icon, 86, 12);
    lv_obj_set_size(ui->pop_page_warning_general_icon, 69, 81);
    lv_obj_add_flag(ui->pop_page_warning_general_icon, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->pop_page_warning_general_icon, &_warning_general_icon_RGB565A8_69x81);
    lv_image_set_pivot(ui->pop_page_warning_general_icon, 50,50);
    lv_image_set_rotation(ui->pop_page_warning_general_icon, 0);

    //Write style for pop_page_warning_general_icon, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->pop_page_warning_general_icon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->pop_page_warning_general_icon, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes pop_page_try_again_button
    ui->pop_page_try_again_button = lv_button_create(ui->pop_page_warning_general_pop);
    lv_obj_set_pos(ui->pop_page_try_again_button, 16, 184);
    lv_obj_set_size(ui->pop_page_try_again_button, 208, 52);
    ui->pop_page_try_again_button_label = lv_label_create(ui->pop_page_try_again_button);
    lv_label_set_text(ui->pop_page_try_again_button_label, "重试");
    lv_label_set_long_mode(ui->pop_page_try_again_button_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->pop_page_try_again_button_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->pop_page_try_again_button, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->pop_page_try_again_button_label, LV_PCT(100));

    //Write style for pop_page_try_again_button, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->pop_page_try_again_button, 28, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->pop_page_try_again_button, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->pop_page_try_again_button, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->pop_page_try_again_button, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->pop_page_try_again_button, 16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->pop_page_try_again_button, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->pop_page_try_again_button, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->pop_page_try_again_button, &lv_font_PingFangSC_Semibold_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->pop_page_try_again_button, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->pop_page_try_again_button, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes pop_page_ota_update_pop
    ui->pop_page_ota_update_pop = lv_obj_create(ui->pop_page);
    lv_obj_set_pos(ui->pop_page_ota_update_pop, 0, 64);
    lv_obj_set_size(ui->pop_page_ota_update_pop, 240, 256);
    lv_obj_set_scrollbar_mode(ui->pop_page_ota_update_pop, LV_SCROLLBAR_MODE_OFF);
    lv_obj_add_flag(ui->pop_page_ota_update_pop, LV_OBJ_FLAG_HIDDEN);

    //Write style for pop_page_ota_update_pop, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->pop_page_ota_update_pop, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->pop_page_ota_update_pop, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->pop_page_ota_update_pop, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->pop_page_ota_update_pop, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->pop_page_ota_update_pop, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->pop_page_ota_update_pop, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->pop_page_ota_update_pop, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->pop_page_ota_update_pop, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes pop_page_ota_update_tips
    ui->pop_page_ota_update_tips = lv_label_create(ui->pop_page_ota_update_pop);
    lv_obj_set_pos(ui->pop_page_ota_update_tips, 16, 126);
    lv_obj_set_size(ui->pop_page_ota_update_tips, 208, 40);
    lv_label_set_text(ui->pop_page_ota_update_tips, "正在更新系统，请勿\n关闭或重启系统");
    lv_label_set_long_mode(ui->pop_page_ota_update_tips, LV_LABEL_LONG_WRAP);

    //Write style for pop_page_ota_update_tips, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->pop_page_ota_update_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->pop_page_ota_update_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->pop_page_ota_update_tips, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->pop_page_ota_update_tips, &lv_font_PingFangSC_Medium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->pop_page_ota_update_tips, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->pop_page_ota_update_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->pop_page_ota_update_tips, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->pop_page_ota_update_tips, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->pop_page_ota_update_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->pop_page_ota_update_tips, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->pop_page_ota_update_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->pop_page_ota_update_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->pop_page_ota_update_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->pop_page_ota_update_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes pop_page_ota_update_icon
    ui->pop_page_ota_update_icon = lv_image_create(ui->pop_page_ota_update_pop);
    lv_obj_set_pos(ui->pop_page_ota_update_icon, 82, 27);
    lv_obj_set_size(ui->pop_page_ota_update_icon, 78, 78);
    lv_obj_add_flag(ui->pop_page_ota_update_icon, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->pop_page_ota_update_icon, &_ota_update_icon_RGB565A8_78x78);
    lv_image_set_pivot(ui->pop_page_ota_update_icon, 50,50);
    lv_image_set_rotation(ui->pop_page_ota_update_icon, 0);

    //Write style for pop_page_ota_update_icon, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->pop_page_ota_update_icon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->pop_page_ota_update_icon, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes pop_page_update_progress_bar
    ui->pop_page_update_progress_bar = lv_bar_create(ui->pop_page_ota_update_pop);
    lv_obj_set_pos(ui->pop_page_update_progress_bar, 40, 196);
    lv_obj_set_size(ui->pop_page_update_progress_bar, 160, 8);
    lv_obj_set_style_anim_duration(ui->pop_page_update_progress_bar, 1000, 0);
    lv_bar_set_mode(ui->pop_page_update_progress_bar, LV_BAR_MODE_NORMAL);
    lv_bar_set_range(ui->pop_page_update_progress_bar, 0, 100);
    lv_bar_set_value(ui->pop_page_update_progress_bar, 50, LV_ANIM_OFF);

    //Write style for pop_page_update_progress_bar, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->pop_page_update_progress_bar, 66, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->pop_page_update_progress_bar, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->pop_page_update_progress_bar, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->pop_page_update_progress_bar, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->pop_page_update_progress_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for pop_page_update_progress_bar, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->pop_page_update_progress_bar, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->pop_page_update_progress_bar, lv_color_hex(0xffffff), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->pop_page_update_progress_bar, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->pop_page_update_progress_bar, 10, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write codes pop_page_bluetooth_disconnected_pop
    ui->pop_page_bluetooth_disconnected_pop = lv_obj_create(ui->pop_page);
    lv_obj_set_pos(ui->pop_page_bluetooth_disconnected_pop, 0, 64);
    lv_obj_set_size(ui->pop_page_bluetooth_disconnected_pop, 240, 256);
    lv_obj_set_scrollbar_mode(ui->pop_page_bluetooth_disconnected_pop, LV_SCROLLBAR_MODE_OFF);
    lv_obj_add_flag(ui->pop_page_bluetooth_disconnected_pop, LV_OBJ_FLAG_HIDDEN);

    //Write style for pop_page_bluetooth_disconnected_pop, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->pop_page_bluetooth_disconnected_pop, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->pop_page_bluetooth_disconnected_pop, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->pop_page_bluetooth_disconnected_pop, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->pop_page_bluetooth_disconnected_pop, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->pop_page_bluetooth_disconnected_pop, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->pop_page_bluetooth_disconnected_pop, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->pop_page_bluetooth_disconnected_pop, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->pop_page_bluetooth_disconnected_pop, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes pop_page_bluetooth_disconnected_tips
    ui->pop_page_bluetooth_disconnected_tips = lv_label_create(ui->pop_page_bluetooth_disconnected_pop);
    lv_obj_set_pos(ui->pop_page_bluetooth_disconnected_tips, 16, 108);
    lv_obj_set_size(ui->pop_page_bluetooth_disconnected_tips, 208, 44);
    lv_label_set_text(ui->pop_page_bluetooth_disconnected_tips, "蓝牙断开啦\n帮我重新连上吧！");
    lv_label_set_long_mode(ui->pop_page_bluetooth_disconnected_tips, LV_LABEL_LONG_WRAP);

    //Write style for pop_page_bluetooth_disconnected_tips, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->pop_page_bluetooth_disconnected_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->pop_page_bluetooth_disconnected_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->pop_page_bluetooth_disconnected_tips, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->pop_page_bluetooth_disconnected_tips, &lv_font_PingFangSC_Medium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->pop_page_bluetooth_disconnected_tips, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->pop_page_bluetooth_disconnected_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->pop_page_bluetooth_disconnected_tips, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->pop_page_bluetooth_disconnected_tips, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->pop_page_bluetooth_disconnected_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->pop_page_bluetooth_disconnected_tips, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->pop_page_bluetooth_disconnected_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->pop_page_bluetooth_disconnected_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->pop_page_bluetooth_disconnected_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->pop_page_bluetooth_disconnected_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes pop_page_bluetooth_disconnected_icon
    ui->pop_page_bluetooth_disconnected_icon = lv_image_create(ui->pop_page_bluetooth_disconnected_pop);
    lv_obj_set_pos(ui->pop_page_bluetooth_disconnected_icon, 80, 20);
    lv_obj_set_size(ui->pop_page_bluetooth_disconnected_icon, 79, 74);
    lv_obj_add_flag(ui->pop_page_bluetooth_disconnected_icon, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->pop_page_bluetooth_disconnected_icon, &_bluetooth_disconnected_icon_RGB565A8_79x74);
    lv_image_set_pivot(ui->pop_page_bluetooth_disconnected_icon, 50,50);
    lv_image_set_rotation(ui->pop_page_bluetooth_disconnected_icon, 0);

    //Write style for pop_page_bluetooth_disconnected_icon, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->pop_page_bluetooth_disconnected_icon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->pop_page_bluetooth_disconnected_icon, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes pop_page_check_bluetooth_button
    ui->pop_page_check_bluetooth_button = lv_button_create(ui->pop_page_bluetooth_disconnected_pop);
    lv_obj_set_pos(ui->pop_page_check_bluetooth_button, 16, 184);
    lv_obj_set_size(ui->pop_page_check_bluetooth_button, 208, 52);
    ui->pop_page_check_bluetooth_button_label = lv_label_create(ui->pop_page_check_bluetooth_button);
    lv_label_set_text(ui->pop_page_check_bluetooth_button_label, "检查网络");
    lv_label_set_long_mode(ui->pop_page_check_bluetooth_button_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->pop_page_check_bluetooth_button_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->pop_page_check_bluetooth_button, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->pop_page_check_bluetooth_button_label, LV_PCT(100));

    //Write style for pop_page_check_bluetooth_button, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->pop_page_check_bluetooth_button, 28, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->pop_page_check_bluetooth_button, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->pop_page_check_bluetooth_button, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->pop_page_check_bluetooth_button, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->pop_page_check_bluetooth_button, 16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->pop_page_check_bluetooth_button, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->pop_page_check_bluetooth_button, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->pop_page_check_bluetooth_button, &lv_font_PingFangSC_Semibold_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->pop_page_check_bluetooth_button, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->pop_page_check_bluetooth_button, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes pop_page_child_lock_on_pop
    ui->pop_page_child_lock_on_pop = lv_obj_create(ui->pop_page);
    lv_obj_set_pos(ui->pop_page_child_lock_on_pop, 0, 64);
    lv_obj_set_size(ui->pop_page_child_lock_on_pop, 240, 256);
    lv_obj_set_scrollbar_mode(ui->pop_page_child_lock_on_pop, LV_SCROLLBAR_MODE_OFF);
    lv_obj_add_flag(ui->pop_page_child_lock_on_pop, LV_OBJ_FLAG_HIDDEN);

    //Write style for pop_page_child_lock_on_pop, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->pop_page_child_lock_on_pop, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->pop_page_child_lock_on_pop, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->pop_page_child_lock_on_pop, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->pop_page_child_lock_on_pop, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->pop_page_child_lock_on_pop, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->pop_page_child_lock_on_pop, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->pop_page_child_lock_on_pop, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->pop_page_child_lock_on_pop, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes pop_page_child_lock_on_tips
    ui->pop_page_child_lock_on_tips = lv_label_create(ui->pop_page_child_lock_on_pop);
    lv_obj_set_pos(ui->pop_page_child_lock_on_tips, 16, 126);
    lv_obj_set_size(ui->pop_page_child_lock_on_tips, 208, 44);
    lv_label_set_text(ui->pop_page_child_lock_on_tips, "童锁已打开\n设备安全保护中");
    lv_label_set_long_mode(ui->pop_page_child_lock_on_tips, LV_LABEL_LONG_WRAP);

    //Write style for pop_page_child_lock_on_tips, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->pop_page_child_lock_on_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->pop_page_child_lock_on_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->pop_page_child_lock_on_tips, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->pop_page_child_lock_on_tips, &lv_font_PingFangSC_Medium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->pop_page_child_lock_on_tips, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->pop_page_child_lock_on_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->pop_page_child_lock_on_tips, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->pop_page_child_lock_on_tips, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->pop_page_child_lock_on_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->pop_page_child_lock_on_tips, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->pop_page_child_lock_on_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->pop_page_child_lock_on_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->pop_page_child_lock_on_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->pop_page_child_lock_on_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes pop_page_child_lock_on_icon
    ui->pop_page_child_lock_on_icon = lv_image_create(ui->pop_page_child_lock_on_pop);
    lv_obj_set_pos(ui->pop_page_child_lock_on_icon, 80, 35);
    lv_obj_set_size(ui->pop_page_child_lock_on_icon, 77, 70);
    lv_obj_add_flag(ui->pop_page_child_lock_on_icon, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->pop_page_child_lock_on_icon, &_child_lock_on_icon_RGB565A8_77x70);
    lv_image_set_pivot(ui->pop_page_child_lock_on_icon, 50,50);
    lv_image_set_rotation(ui->pop_page_child_lock_on_icon, 0);

    //Write style for pop_page_child_lock_on_icon, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->pop_page_child_lock_on_icon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->pop_page_child_lock_on_icon, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes pop_page_child_lock_off_pop
    ui->pop_page_child_lock_off_pop = lv_obj_create(ui->pop_page);
    lv_obj_set_pos(ui->pop_page_child_lock_off_pop, 0, 64);
    lv_obj_set_size(ui->pop_page_child_lock_off_pop, 240, 256);
    lv_obj_set_scrollbar_mode(ui->pop_page_child_lock_off_pop, LV_SCROLLBAR_MODE_OFF);
    lv_obj_add_flag(ui->pop_page_child_lock_off_pop, LV_OBJ_FLAG_HIDDEN);

    //Write style for pop_page_child_lock_off_pop, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->pop_page_child_lock_off_pop, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->pop_page_child_lock_off_pop, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->pop_page_child_lock_off_pop, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->pop_page_child_lock_off_pop, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->pop_page_child_lock_off_pop, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->pop_page_child_lock_off_pop, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->pop_page_child_lock_off_pop, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->pop_page_child_lock_off_pop, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes pop_page_child_lock_off_tips
    ui->pop_page_child_lock_off_tips = lv_label_create(ui->pop_page_child_lock_off_pop);
    lv_obj_set_pos(ui->pop_page_child_lock_off_tips, 16, 127);
    lv_obj_set_size(ui->pop_page_child_lock_off_tips, 208, 44);
    lv_label_set_text(ui->pop_page_child_lock_off_tips, "童锁已关闭\n设备安全保护中");
    lv_label_set_long_mode(ui->pop_page_child_lock_off_tips, LV_LABEL_LONG_WRAP);

    //Write style for pop_page_child_lock_off_tips, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->pop_page_child_lock_off_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->pop_page_child_lock_off_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->pop_page_child_lock_off_tips, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->pop_page_child_lock_off_tips, &lv_font_PingFangSC_Medium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->pop_page_child_lock_off_tips, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->pop_page_child_lock_off_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->pop_page_child_lock_off_tips, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->pop_page_child_lock_off_tips, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->pop_page_child_lock_off_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->pop_page_child_lock_off_tips, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->pop_page_child_lock_off_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->pop_page_child_lock_off_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->pop_page_child_lock_off_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->pop_page_child_lock_off_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes pop_page_child_lock_off_icon
    ui->pop_page_child_lock_off_icon = lv_image_create(ui->pop_page_child_lock_off_pop);
    lv_obj_set_pos(ui->pop_page_child_lock_off_icon, 78, 28);
    lv_obj_set_size(ui->pop_page_child_lock_off_icon, 76, 70);
    lv_obj_add_flag(ui->pop_page_child_lock_off_icon, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->pop_page_child_lock_off_icon, &_child_lock_off_icon_RGB565A8_76x70);
    lv_image_set_pivot(ui->pop_page_child_lock_off_icon, 50,50);
    lv_image_set_rotation(ui->pop_page_child_lock_off_icon, 0);

    //Write style for pop_page_child_lock_off_icon, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->pop_page_child_lock_off_icon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->pop_page_child_lock_off_icon, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes pop_page_storage_full_pop
    ui->pop_page_storage_full_pop = lv_obj_create(ui->pop_page);
    lv_obj_set_pos(ui->pop_page_storage_full_pop, 0, 64);
    lv_obj_set_size(ui->pop_page_storage_full_pop, 240, 256);
    lv_obj_set_scrollbar_mode(ui->pop_page_storage_full_pop, LV_SCROLLBAR_MODE_OFF);
    lv_obj_add_flag(ui->pop_page_storage_full_pop, LV_OBJ_FLAG_HIDDEN);

    //Write style for pop_page_storage_full_pop, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->pop_page_storage_full_pop, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->pop_page_storage_full_pop, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->pop_page_storage_full_pop, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->pop_page_storage_full_pop, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->pop_page_storage_full_pop, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->pop_page_storage_full_pop, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->pop_page_storage_full_pop, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->pop_page_storage_full_pop, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes pop_page_storage_full_tips
    ui->pop_page_storage_full_tips = lv_label_create(ui->pop_page_storage_full_pop);
    lv_obj_set_pos(ui->pop_page_storage_full_tips, 16, 108);
    lv_obj_set_size(ui->pop_page_storage_full_tips, 208, 44);
    lv_label_set_text(ui->pop_page_storage_full_tips, "存储空间不足\n请清理空间");
    lv_label_set_long_mode(ui->pop_page_storage_full_tips, LV_LABEL_LONG_WRAP);

    //Write style for pop_page_storage_full_tips, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->pop_page_storage_full_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->pop_page_storage_full_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->pop_page_storage_full_tips, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->pop_page_storage_full_tips, &lv_font_PingFangSC_Medium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->pop_page_storage_full_tips, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->pop_page_storage_full_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->pop_page_storage_full_tips, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->pop_page_storage_full_tips, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->pop_page_storage_full_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->pop_page_storage_full_tips, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->pop_page_storage_full_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->pop_page_storage_full_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->pop_page_storage_full_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->pop_page_storage_full_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes pop_page_storage_full_icon
    ui->pop_page_storage_full_icon = lv_image_create(ui->pop_page_storage_full_pop);
    lv_obj_set_pos(ui->pop_page_storage_full_icon, 78, 12);
    lv_obj_set_size(ui->pop_page_storage_full_icon, 76, 67);
    lv_obj_add_flag(ui->pop_page_storage_full_icon, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->pop_page_storage_full_icon, &_storage_full_icon_RGB565A8_76x67);
    lv_image_set_pivot(ui->pop_page_storage_full_icon, 50,50);
    lv_image_set_rotation(ui->pop_page_storage_full_icon, 0);

    //Write style for pop_page_storage_full_icon, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->pop_page_storage_full_icon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->pop_page_storage_full_icon, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes pop_page_clean_button
    ui->pop_page_clean_button = lv_button_create(ui->pop_page_storage_full_pop);
    lv_obj_set_pos(ui->pop_page_clean_button, 16, 184);
    lv_obj_set_size(ui->pop_page_clean_button, 208, 52);
    ui->pop_page_clean_button_label = lv_label_create(ui->pop_page_clean_button);
    lv_label_set_text(ui->pop_page_clean_button_label, "立即清理");
    lv_label_set_long_mode(ui->pop_page_clean_button_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->pop_page_clean_button_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->pop_page_clean_button, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->pop_page_clean_button_label, LV_PCT(100));

    //Write style for pop_page_clean_button, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->pop_page_clean_button, 28, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->pop_page_clean_button, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->pop_page_clean_button, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->pop_page_clean_button, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->pop_page_clean_button, 16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->pop_page_clean_button, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->pop_page_clean_button, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->pop_page_clean_button, &lv_font_PingFangSC_Semibold_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->pop_page_clean_button, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->pop_page_clean_button, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes pop_page_wifi_disconnected_pop
    ui->pop_page_wifi_disconnected_pop = lv_obj_create(ui->pop_page);
    lv_obj_set_pos(ui->pop_page_wifi_disconnected_pop, 0, 64);
    lv_obj_set_size(ui->pop_page_wifi_disconnected_pop, 240, 256);
    lv_obj_set_scrollbar_mode(ui->pop_page_wifi_disconnected_pop, LV_SCROLLBAR_MODE_OFF);
    lv_obj_add_flag(ui->pop_page_wifi_disconnected_pop, LV_OBJ_FLAG_HIDDEN);

    //Write style for pop_page_wifi_disconnected_pop, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->pop_page_wifi_disconnected_pop, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->pop_page_wifi_disconnected_pop, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->pop_page_wifi_disconnected_pop, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->pop_page_wifi_disconnected_pop, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->pop_page_wifi_disconnected_pop, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->pop_page_wifi_disconnected_pop, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->pop_page_wifi_disconnected_pop, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->pop_page_wifi_disconnected_pop, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes pop_page_wifi_disconnected_tips
    ui->pop_page_wifi_disconnected_tips = lv_label_create(ui->pop_page_wifi_disconnected_pop);
    lv_obj_set_pos(ui->pop_page_wifi_disconnected_tips, 19, 108);
    lv_obj_set_size(ui->pop_page_wifi_disconnected_tips, 208, 44);
    lv_label_set_text(ui->pop_page_wifi_disconnected_tips, "网络不见啦\n快检查一下Wi-Fi吧");
    lv_label_set_long_mode(ui->pop_page_wifi_disconnected_tips, LV_LABEL_LONG_WRAP);

    //Write style for pop_page_wifi_disconnected_tips, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->pop_page_wifi_disconnected_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->pop_page_wifi_disconnected_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->pop_page_wifi_disconnected_tips, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->pop_page_wifi_disconnected_tips, &lv_font_PingFangSC_Medium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->pop_page_wifi_disconnected_tips, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->pop_page_wifi_disconnected_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->pop_page_wifi_disconnected_tips, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->pop_page_wifi_disconnected_tips, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->pop_page_wifi_disconnected_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->pop_page_wifi_disconnected_tips, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->pop_page_wifi_disconnected_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->pop_page_wifi_disconnected_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->pop_page_wifi_disconnected_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->pop_page_wifi_disconnected_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes pop_page_wifi_disconnected_icon
    ui->pop_page_wifi_disconnected_icon = lv_image_create(ui->pop_page_wifi_disconnected_pop);
    lv_obj_set_pos(ui->pop_page_wifi_disconnected_icon, 82, 8);
    lv_obj_set_size(ui->pop_page_wifi_disconnected_icon, 84, 68);
    lv_obj_add_flag(ui->pop_page_wifi_disconnected_icon, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->pop_page_wifi_disconnected_icon, &_wifi_disconnected_icon_RGB565A8_84x68);
    lv_image_set_pivot(ui->pop_page_wifi_disconnected_icon, 50,50);
    lv_image_set_rotation(ui->pop_page_wifi_disconnected_icon, 0);

    //Write style for pop_page_wifi_disconnected_icon, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->pop_page_wifi_disconnected_icon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->pop_page_wifi_disconnected_icon, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes pop_page_check_network_button
    ui->pop_page_check_network_button = lv_button_create(ui->pop_page_wifi_disconnected_pop);
    lv_obj_set_pos(ui->pop_page_check_network_button, 16, 184);
    lv_obj_set_size(ui->pop_page_check_network_button, 208, 52);
    ui->pop_page_check_network_button_label = lv_label_create(ui->pop_page_check_network_button);
    lv_label_set_text(ui->pop_page_check_network_button_label, "检查网络");
    lv_label_set_long_mode(ui->pop_page_check_network_button_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->pop_page_check_network_button_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->pop_page_check_network_button, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->pop_page_check_network_button_label, LV_PCT(100));

    //Write style for pop_page_check_network_button, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->pop_page_check_network_button, 28, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->pop_page_check_network_button, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->pop_page_check_network_button, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->pop_page_check_network_button, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->pop_page_check_network_button, 16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->pop_page_check_network_button, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->pop_page_check_network_button, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->pop_page_check_network_button, &lv_font_PingFangSC_Semibold_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->pop_page_check_network_button, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->pop_page_check_network_button, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of pop_page.


    //Update current screen layout.
    lv_obj_update_layout(ui->pop_page);

    //Init events for screen.
    events_init_pop_page(ui);
}
