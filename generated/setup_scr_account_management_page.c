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



void setup_scr_account_management_page(lv_ui *ui)
{
    //Write codes account_management_page
    ui->account_management_page = lv_obj_create(NULL);
    lv_obj_set_size(ui->account_management_page, 240, 320);
    lv_obj_set_scrollbar_mode(ui->account_management_page, LV_SCROLLBAR_MODE_OFF);

    //Write style for account_management_page, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->account_management_page, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->account_management_page, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->account_management_page, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes account_management_page_account_information
    ui->account_management_page_account_information = lv_obj_create(ui->account_management_page);
    lv_obj_set_pos(ui->account_management_page_account_information, 16, 193);
    lv_obj_set_size(ui->account_management_page_account_information, 208, 88);
    lv_obj_set_scrollbar_mode(ui->account_management_page_account_information, LV_SCROLLBAR_MODE_OFF);

    //Write style for account_management_page_account_information, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->account_management_page_account_information, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->account_management_page_account_information, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->account_management_page_account_information, 26, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->account_management_page_account_information, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->account_management_page_account_information, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->account_management_page_account_information, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->account_management_page_account_information, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->account_management_page_account_information, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->account_management_page_account_information, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->account_management_page_account_information, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes account_management_page_account_validity_period
    ui->account_management_page_account_validity_period = lv_label_create(ui->account_management_page_account_information);
    lv_obj_set_pos(ui->account_management_page_account_validity_period, 12, 50);
    lv_obj_set_size(ui->account_management_page_account_validity_period, 180, 20);
    lv_label_set_text(ui->account_management_page_account_validity_period, "有效期至 2026-12-12");
    lv_label_set_long_mode(ui->account_management_page_account_validity_period, LV_LABEL_LONG_WRAP);

    //Write style for account_management_page_account_validity_period, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->account_management_page_account_validity_period, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->account_management_page_account_validity_period, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->account_management_page_account_validity_period, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->account_management_page_account_validity_period, &lv_font_PingFangSC_Regular_14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->account_management_page_account_validity_period, 160, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->account_management_page_account_validity_period, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->account_management_page_account_validity_period, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->account_management_page_account_validity_period, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->account_management_page_account_validity_period, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->account_management_page_account_validity_period, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->account_management_page_account_validity_period, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->account_management_page_account_validity_period, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->account_management_page_account_validity_period, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->account_management_page_account_validity_period, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes account_management_page_phone_number
    ui->account_management_page_phone_number = lv_label_create(ui->account_management_page_account_information);
    lv_obj_set_pos(ui->account_management_page_phone_number, 12, 20);
    lv_obj_set_size(ui->account_management_page_phone_number, 120, 25);
    lv_label_set_text(ui->account_management_page_phone_number, "158****3000");
    lv_label_set_long_mode(ui->account_management_page_phone_number, LV_LABEL_LONG_WRAP);

    //Write style for account_management_page_phone_number, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->account_management_page_phone_number, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->account_management_page_phone_number, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->account_management_page_phone_number, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->account_management_page_phone_number, &lv_font_PingFangSC_Semibold_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->account_management_page_phone_number, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->account_management_page_phone_number, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->account_management_page_phone_number, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->account_management_page_phone_number, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->account_management_page_phone_number, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->account_management_page_phone_number, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->account_management_page_phone_number, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->account_management_page_phone_number, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->account_management_page_phone_number, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->account_management_page_phone_number, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes account_management_page_status_bar
    ui->account_management_page_status_bar = lv_obj_create(ui->account_management_page);
    lv_obj_set_pos(ui->account_management_page_status_bar, 0, 0);
    lv_obj_set_size(ui->account_management_page_status_bar, 240, 64);
    lv_obj_set_scrollbar_mode(ui->account_management_page_status_bar, LV_SCROLLBAR_MODE_OFF);

    //Write style for account_management_page_status_bar, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->account_management_page_status_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->account_management_page_status_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->account_management_page_status_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->account_management_page_status_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->account_management_page_status_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->account_management_page_status_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->account_management_page_status_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->account_management_page_status_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes account_management_page_main_title
    ui->account_management_page_main_title = lv_label_create(ui->account_management_page_status_bar);
    lv_obj_set_pos(ui->account_management_page_main_title, 148, 32);
    lv_obj_set_size(ui->account_management_page_main_title, 80, 28);
    lv_label_set_text(ui->account_management_page_main_title, "账号管理");
    lv_label_set_long_mode(ui->account_management_page_main_title, LV_LABEL_LONG_WRAP);

    //Write style for account_management_page_main_title, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->account_management_page_main_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->account_management_page_main_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->account_management_page_main_title, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->account_management_page_main_title, &lv_font_PingFangSC_Medium_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->account_management_page_main_title, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->account_management_page_main_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->account_management_page_main_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->account_management_page_main_title, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->account_management_page_main_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->account_management_page_main_title, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->account_management_page_main_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->account_management_page_main_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->account_management_page_main_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->account_management_page_main_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes account_management_page_left_control_button
    ui->account_management_page_left_control_button = lv_image_create(ui->account_management_page_status_bar);
    lv_obj_set_pos(ui->account_management_page_left_control_button, 16, 16);
    lv_obj_set_size(ui->account_management_page_left_control_button, 40, 40);
    lv_obj_add_flag(ui->account_management_page_left_control_button, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->account_management_page_left_control_button, &_left_control_RGB565A8_40x40);
    lv_image_set_pivot(ui->account_management_page_left_control_button, 50,50);
    lv_image_set_rotation(ui->account_management_page_left_control_button, 0);

    //Write style for account_management_page_left_control_button, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->account_management_page_left_control_button, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->account_management_page_left_control_button, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes account_management_page_container_3
    ui->account_management_page_container_3 = lv_obj_create(ui->account_management_page);
    lv_obj_set_pos(ui->account_management_page_container_3, 140, 80);
    lv_obj_set_size(ui->account_management_page_container_3, 60, 97);
    lv_obj_set_scrollbar_mode(ui->account_management_page_container_3, LV_SCROLLBAR_MODE_OFF);
    lv_obj_add_flag(ui->account_management_page_container_3, LV_OBJ_FLAG_HIDDEN);

    //Write style for account_management_page_container_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->account_management_page_container_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->account_management_page_container_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->account_management_page_container_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->account_management_page_container_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->account_management_page_container_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->account_management_page_container_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->account_management_page_container_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->account_management_page_container_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes account_management_page_sub_account_name_3
    ui->account_management_page_sub_account_name_3 = lv_label_create(ui->account_management_page_container_3);
    lv_obj_set_pos(ui->account_management_page_sub_account_name_3, 3, 75);
    lv_obj_set_size(ui->account_management_page_sub_account_name_3, 54, 25);
    lv_label_set_text(ui->account_management_page_sub_account_name_3, "小茉莉");
    lv_label_set_long_mode(ui->account_management_page_sub_account_name_3, LV_LABEL_LONG_WRAP);

    //Write style for account_management_page_sub_account_name_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->account_management_page_sub_account_name_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->account_management_page_sub_account_name_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->account_management_page_sub_account_name_3, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->account_management_page_sub_account_name_3, &lv_font_PingFangSC_Semibold_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->account_management_page_sub_account_name_3, 206, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->account_management_page_sub_account_name_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->account_management_page_sub_account_name_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->account_management_page_sub_account_name_3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->account_management_page_sub_account_name_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->account_management_page_sub_account_name_3, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->account_management_page_sub_account_name_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->account_management_page_sub_account_name_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->account_management_page_sub_account_name_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->account_management_page_sub_account_name_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes account_management_page_child_icon_3
    ui->account_management_page_child_icon_3 = lv_image_create(ui->account_management_page_container_3);
    lv_obj_set_pos(ui->account_management_page_child_icon_3, 0, 0);
    lv_obj_set_size(ui->account_management_page_child_icon_3, 60, 60);
    lv_obj_add_flag(ui->account_management_page_child_icon_3, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->account_management_page_child_icon_3, &_music_cover_example_RGB565A8_60x60);
    lv_image_set_pivot(ui->account_management_page_child_icon_3, 50,50);
    lv_image_set_rotation(ui->account_management_page_child_icon_3, 0);

    //Write style for account_management_page_child_icon_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->account_management_page_child_icon_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->account_management_page_child_icon_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes account_management_page_mask_3
    ui->account_management_page_mask_3 = lv_obj_create(ui->account_management_page_container_3);
    lv_obj_set_pos(ui->account_management_page_mask_3, 0, 0);
    lv_obj_set_size(ui->account_management_page_mask_3, 60, 60);
    lv_obj_set_scrollbar_mode(ui->account_management_page_mask_3, LV_SCROLLBAR_MODE_OFF);

    //Write style for account_management_page_mask_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->account_management_page_mask_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->account_management_page_mask_3, 24, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->account_management_page_mask_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->account_management_page_mask_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->account_management_page_mask_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->account_management_page_mask_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->account_management_page_mask_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->account_management_page_mask_3, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui->account_management_page_mask_3, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui->account_management_page_mask_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui->account_management_page_mask_3, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(ui->account_management_page_mask_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(ui->account_management_page_mask_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes account_management_page_ic_download_done_icon_3
    ui->account_management_page_ic_download_done_icon_3 = lv_image_create(ui->account_management_page_container_3);
    lv_obj_set_pos(ui->account_management_page_ic_download_done_icon_3, 12, 42);
    lv_obj_set_size(ui->account_management_page_ic_download_done_icon_3, 36, 36);
    lv_obj_add_flag(ui->account_management_page_ic_download_done_icon_3, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->account_management_page_ic_download_done_icon_3, &_ic_download_done_RGB565A8_36x36);
    lv_image_set_pivot(ui->account_management_page_ic_download_done_icon_3, 50,50);
    lv_image_set_rotation(ui->account_management_page_ic_download_done_icon_3, 0);

    //Write style for account_management_page_ic_download_done_icon_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->account_management_page_ic_download_done_icon_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->account_management_page_ic_download_done_icon_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes account_management_page_container_2
    ui->account_management_page_container_2 = lv_obj_create(ui->account_management_page);
    lv_obj_set_pos(ui->account_management_page_container_2, 40, 80);
    lv_obj_set_size(ui->account_management_page_container_2, 60, 97);
    lv_obj_set_scrollbar_mode(ui->account_management_page_container_2, LV_SCROLLBAR_MODE_OFF);
    lv_obj_add_flag(ui->account_management_page_container_2, LV_OBJ_FLAG_HIDDEN);

    //Write style for account_management_page_container_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->account_management_page_container_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->account_management_page_container_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->account_management_page_container_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->account_management_page_container_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->account_management_page_container_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->account_management_page_container_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->account_management_page_container_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->account_management_page_container_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes account_management_page_sub_account_name_2
    ui->account_management_page_sub_account_name_2 = lv_label_create(ui->account_management_page_container_2);
    lv_obj_set_pos(ui->account_management_page_sub_account_name_2, 3, 75);
    lv_obj_set_size(ui->account_management_page_sub_account_name_2, 54, 25);
    lv_label_set_text(ui->account_management_page_sub_account_name_2, "小茉莉");
    lv_label_set_long_mode(ui->account_management_page_sub_account_name_2, LV_LABEL_LONG_WRAP);

    //Write style for account_management_page_sub_account_name_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->account_management_page_sub_account_name_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->account_management_page_sub_account_name_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->account_management_page_sub_account_name_2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->account_management_page_sub_account_name_2, &lv_font_PingFangSC_Semibold_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->account_management_page_sub_account_name_2, 206, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->account_management_page_sub_account_name_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->account_management_page_sub_account_name_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->account_management_page_sub_account_name_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->account_management_page_sub_account_name_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->account_management_page_sub_account_name_2, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->account_management_page_sub_account_name_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->account_management_page_sub_account_name_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->account_management_page_sub_account_name_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->account_management_page_sub_account_name_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes account_management_page_child_icon_2
    ui->account_management_page_child_icon_2 = lv_image_create(ui->account_management_page_container_2);
    lv_obj_set_pos(ui->account_management_page_child_icon_2, 0, 0);
    lv_obj_set_size(ui->account_management_page_child_icon_2, 60, 60);
    lv_obj_add_flag(ui->account_management_page_child_icon_2, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->account_management_page_child_icon_2, &_music_cover_example_RGB565A8_60x60);
    lv_image_set_pivot(ui->account_management_page_child_icon_2, 50,50);
    lv_image_set_rotation(ui->account_management_page_child_icon_2, 0);

    //Write style for account_management_page_child_icon_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->account_management_page_child_icon_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->account_management_page_child_icon_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes account_management_page_mask_2
    ui->account_management_page_mask_2 = lv_obj_create(ui->account_management_page_container_2);
    lv_obj_set_pos(ui->account_management_page_mask_2, 0, 0);
    lv_obj_set_size(ui->account_management_page_mask_2, 60, 60);
    lv_obj_set_scrollbar_mode(ui->account_management_page_mask_2, LV_SCROLLBAR_MODE_OFF);

    //Write style for account_management_page_mask_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->account_management_page_mask_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->account_management_page_mask_2, 24, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->account_management_page_mask_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->account_management_page_mask_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->account_management_page_mask_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->account_management_page_mask_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->account_management_page_mask_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->account_management_page_mask_2, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui->account_management_page_mask_2, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui->account_management_page_mask_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui->account_management_page_mask_2, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(ui->account_management_page_mask_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(ui->account_management_page_mask_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes account_management_page_ic_download_done_icon_2
    ui->account_management_page_ic_download_done_icon_2 = lv_image_create(ui->account_management_page_container_2);
    lv_obj_set_pos(ui->account_management_page_ic_download_done_icon_2, 12, 42);
    lv_obj_set_size(ui->account_management_page_ic_download_done_icon_2, 36, 36);
    lv_obj_add_flag(ui->account_management_page_ic_download_done_icon_2, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->account_management_page_ic_download_done_icon_2, &_ic_download_done_RGB565A8_36x36);
    lv_image_set_pivot(ui->account_management_page_ic_download_done_icon_2, 50,50);
    lv_image_set_rotation(ui->account_management_page_ic_download_done_icon_2, 0);

    //Write style for account_management_page_ic_download_done_icon_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->account_management_page_ic_download_done_icon_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->account_management_page_ic_download_done_icon_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes account_management_page_container_1
    ui->account_management_page_container_1 = lv_obj_create(ui->account_management_page);
    lv_obj_set_pos(ui->account_management_page_container_1, 90, 80);
    lv_obj_set_size(ui->account_management_page_container_1, 60, 97);
    lv_obj_set_scrollbar_mode(ui->account_management_page_container_1, LV_SCROLLBAR_MODE_OFF);

    //Write style for account_management_page_container_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->account_management_page_container_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->account_management_page_container_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->account_management_page_container_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->account_management_page_container_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->account_management_page_container_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->account_management_page_container_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->account_management_page_container_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->account_management_page_container_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes account_management_page_sub_account_name_1
    ui->account_management_page_sub_account_name_1 = lv_label_create(ui->account_management_page_container_1);
    lv_obj_set_pos(ui->account_management_page_sub_account_name_1, 3, 75);
    lv_obj_set_size(ui->account_management_page_sub_account_name_1, 54, 25);
    lv_label_set_text(ui->account_management_page_sub_account_name_1, "小茉莉");
    lv_label_set_long_mode(ui->account_management_page_sub_account_name_1, LV_LABEL_LONG_WRAP);

    //Write style for account_management_page_sub_account_name_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->account_management_page_sub_account_name_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->account_management_page_sub_account_name_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->account_management_page_sub_account_name_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->account_management_page_sub_account_name_1, &lv_font_PingFangSC_Semibold_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->account_management_page_sub_account_name_1, 206, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->account_management_page_sub_account_name_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->account_management_page_sub_account_name_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->account_management_page_sub_account_name_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->account_management_page_sub_account_name_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->account_management_page_sub_account_name_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->account_management_page_sub_account_name_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->account_management_page_sub_account_name_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->account_management_page_sub_account_name_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->account_management_page_sub_account_name_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes account_management_page_child_icon_1
    ui->account_management_page_child_icon_1 = lv_image_create(ui->account_management_page_container_1);
    lv_obj_set_pos(ui->account_management_page_child_icon_1, 0, 0);
    lv_obj_set_size(ui->account_management_page_child_icon_1, 60, 60);
    lv_obj_add_flag(ui->account_management_page_child_icon_1, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->account_management_page_child_icon_1, &_music_cover_example_RGB565A8_60x60);
    lv_image_set_pivot(ui->account_management_page_child_icon_1, 50,50);
    lv_image_set_rotation(ui->account_management_page_child_icon_1, 0);

    //Write style for account_management_page_child_icon_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->account_management_page_child_icon_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->account_management_page_child_icon_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes account_management_page_mask_1
    ui->account_management_page_mask_1 = lv_obj_create(ui->account_management_page_container_1);
    lv_obj_set_pos(ui->account_management_page_mask_1, 0, 0);
    lv_obj_set_size(ui->account_management_page_mask_1, 60, 60);
    lv_obj_set_scrollbar_mode(ui->account_management_page_mask_1, LV_SCROLLBAR_MODE_OFF);

    //Write style for account_management_page_mask_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->account_management_page_mask_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->account_management_page_mask_1, 24, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->account_management_page_mask_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->account_management_page_mask_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->account_management_page_mask_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->account_management_page_mask_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->account_management_page_mask_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->account_management_page_mask_1, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui->account_management_page_mask_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui->account_management_page_mask_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui->account_management_page_mask_1, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(ui->account_management_page_mask_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(ui->account_management_page_mask_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes account_management_page_ic_download_done_icon_1
    ui->account_management_page_ic_download_done_icon_1 = lv_image_create(ui->account_management_page_container_1);
    lv_obj_set_pos(ui->account_management_page_ic_download_done_icon_1, 12, 42);
    lv_obj_set_size(ui->account_management_page_ic_download_done_icon_1, 36, 36);
    lv_obj_add_flag(ui->account_management_page_ic_download_done_icon_1, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->account_management_page_ic_download_done_icon_1, &_ic_download_done_RGB565A8_36x36);
    lv_image_set_pivot(ui->account_management_page_ic_download_done_icon_1, 50,50);
    lv_image_set_rotation(ui->account_management_page_ic_download_done_icon_1, 0);

    //Write style for account_management_page_ic_download_done_icon_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->account_management_page_ic_download_done_icon_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->account_management_page_ic_download_done_icon_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of account_management_page.


    //Update current screen layout.
    lv_obj_update_layout(ui->account_management_page);

    //Init events for screen.
    events_init_account_management_page(ui);
}
