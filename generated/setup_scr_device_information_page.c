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



void setup_scr_device_information_page(lv_ui *ui)
{
    //Write codes device_information_page
    ui->device_information_page = lv_obj_create(NULL);
    lv_obj_set_size(ui->device_information_page, 240, 320);
    lv_obj_set_scrollbar_mode(ui->device_information_page, LV_SCROLLBAR_MODE_OFF);

    //Write style for device_information_page, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->device_information_page, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->device_information_page, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->device_information_page, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes device_information_page_list
    ui->device_information_page_list = lv_obj_create(ui->device_information_page);
    lv_obj_set_pos(ui->device_information_page_list, 0, 64);
    lv_obj_set_size(ui->device_information_page_list, 240, 256);
    lv_obj_set_scrollbar_mode(ui->device_information_page_list, LV_SCROLLBAR_MODE_OFF);

    //Write style for device_information_page_list, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->device_information_page_list, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->device_information_page_list, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->device_information_page_list, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->device_information_page_list, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->device_information_page_list, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->device_information_page_list, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->device_information_page_list, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->device_information_page_list, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes device_information_page_line_7
    ui->device_information_page_line_7 = lv_line_create(ui->device_information_page_list);
    lv_obj_set_pos(ui->device_information_page_line_7, 16, 630);
    lv_obj_set_size(ui->device_information_page_line_7, 208, 2);
    static lv_point_precise_t device_information_page_line_7[] = {{0, 0},{208, 0}};
    lv_line_set_points(ui->device_information_page_line_7, device_information_page_line_7, 2);

    //Write style for device_information_page_line_7, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_line_opa(ui->device_information_page_line_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes device_information_page_sn_code_title
    ui->device_information_page_sn_code_title = lv_label_create(ui->device_information_page_list);
    lv_obj_set_pos(ui->device_information_page_sn_code_title, 16, 579);
    lv_obj_set_size(ui->device_information_page_sn_code_title, 160, 25);
    lv_label_set_text(ui->device_information_page_sn_code_title, "S/N编码");
    lv_label_set_long_mode(ui->device_information_page_sn_code_title, LV_LABEL_LONG_WRAP);

    //Write style for device_information_page_sn_code_title, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->device_information_page_sn_code_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->device_information_page_sn_code_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->device_information_page_sn_code_title, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->device_information_page_sn_code_title, &lv_font_PingFangSC_Semibold_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->device_information_page_sn_code_title, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->device_information_page_sn_code_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->device_information_page_sn_code_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->device_information_page_sn_code_title, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->device_information_page_sn_code_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->device_information_page_sn_code_title, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->device_information_page_sn_code_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->device_information_page_sn_code_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->device_information_page_sn_code_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->device_information_page_sn_code_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes device_information_page_sn_code
    ui->device_information_page_sn_code = lv_label_create(ui->device_information_page_list);
    lv_obj_set_pos(ui->device_information_page_sn_code, 16, 553);
    lv_obj_set_size(ui->device_information_page_sn_code, 150, 22);
    lv_label_set_text(ui->device_information_page_sn_code, "HFNEM71228658");
    lv_label_set_long_mode(ui->device_information_page_sn_code, LV_LABEL_LONG_WRAP);

    //Write style for device_information_page_sn_code, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->device_information_page_sn_code, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->device_information_page_sn_code, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->device_information_page_sn_code, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->device_information_page_sn_code, &lv_font_PingFangSC_Regular_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->device_information_page_sn_code, 174, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->device_information_page_sn_code, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->device_information_page_sn_code, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->device_information_page_sn_code, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->device_information_page_sn_code, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->device_information_page_sn_code, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->device_information_page_sn_code, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->device_information_page_sn_code, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->device_information_page_sn_code, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->device_information_page_sn_code, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes device_information_page_line_6
    ui->device_information_page_line_6 = lv_line_create(ui->device_information_page_list);
    lv_obj_set_pos(ui->device_information_page_line_6, 16, 543);
    lv_obj_set_size(ui->device_information_page_line_6, 208, 2);
    static lv_point_precise_t device_information_page_line_6[] = {{0, 0},{208, 0}};
    lv_line_set_points(ui->device_information_page_line_6, device_information_page_line_6, 2);

    //Write style for device_information_page_line_6, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_line_width(ui->device_information_page_line_6, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_color(ui->device_information_page_line_6, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_opa(ui->device_information_page_line_6, 51, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_rounded(ui->device_information_page_line_6, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes device_information_page_device_number_title
    ui->device_information_page_device_number_title = lv_label_create(ui->device_information_page_list);
    lv_obj_set_pos(ui->device_information_page_device_number_title, 16, 510);
    lv_obj_set_size(ui->device_information_page_device_number_title, 128, 22);
    lv_label_set_text(ui->device_information_page_device_number_title, "设备型号");
    lv_label_set_long_mode(ui->device_information_page_device_number_title, LV_LABEL_LONG_WRAP);

    //Write style for device_information_page_device_number_title, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->device_information_page_device_number_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->device_information_page_device_number_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->device_information_page_device_number_title, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->device_information_page_device_number_title, &lv_font_PingFangSC_Regular_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->device_information_page_device_number_title, 174, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->device_information_page_device_number_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->device_information_page_device_number_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->device_information_page_device_number_title, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->device_information_page_device_number_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->device_information_page_device_number_title, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->device_information_page_device_number_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->device_information_page_device_number_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->device_information_page_device_number_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->device_information_page_device_number_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes device_information_page_device_number
    ui->device_information_page_device_number = lv_label_create(ui->device_information_page_list);
    lv_obj_set_pos(ui->device_information_page_device_number, 16, 485);
    lv_obj_set_size(ui->device_information_page_device_number, 160, 25);
    lv_label_set_text(ui->device_information_page_device_number, "FM1039");
    lv_label_set_long_mode(ui->device_information_page_device_number, LV_LABEL_LONG_WRAP);

    //Write style for device_information_page_device_number, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->device_information_page_device_number, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->device_information_page_device_number, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->device_information_page_device_number, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->device_information_page_device_number, &lv_font_PingFangSC_Semibold_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->device_information_page_device_number, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->device_information_page_device_number, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->device_information_page_device_number, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->device_information_page_device_number, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->device_information_page_device_number, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->device_information_page_device_number, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->device_information_page_device_number, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->device_information_page_device_number, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->device_information_page_device_number, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->device_information_page_device_number, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes device_information_page_line_5
    ui->device_information_page_line_5 = lv_line_create(ui->device_information_page_list);
    lv_obj_set_pos(ui->device_information_page_line_5, 16, 475);
    lv_obj_set_size(ui->device_information_page_line_5, 208, 2);
    static lv_point_precise_t device_information_page_line_5[] = {{0, 0},{208, 0}};
    lv_line_set_points(ui->device_information_page_line_5, device_information_page_line_5, 2);

    //Write style for device_information_page_line_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_line_width(ui->device_information_page_line_5, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_color(ui->device_information_page_line_5, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_opa(ui->device_information_page_line_5, 51, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_rounded(ui->device_information_page_line_5, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes device_information_page_firmware_version_upgrade_button
    ui->device_information_page_firmware_version_upgrade_button = lv_button_create(ui->device_information_page_list);
    lv_obj_set_pos(ui->device_information_page_firmware_version_upgrade_button, 176, 419);
    lv_obj_set_size(ui->device_information_page_firmware_version_upgrade_button, 48, 36);
    ui->device_information_page_firmware_version_upgrade_button_label = lv_label_create(ui->device_information_page_firmware_version_upgrade_button);
    lv_label_set_text(ui->device_information_page_firmware_version_upgrade_button_label, "升级");
    lv_label_set_long_mode(ui->device_information_page_firmware_version_upgrade_button_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->device_information_page_firmware_version_upgrade_button_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->device_information_page_firmware_version_upgrade_button, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->device_information_page_firmware_version_upgrade_button_label, LV_PCT(100));

    //Write style for device_information_page_firmware_version_upgrade_button, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->device_information_page_firmware_version_upgrade_button, 28, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->device_information_page_firmware_version_upgrade_button, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->device_information_page_firmware_version_upgrade_button, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->device_information_page_firmware_version_upgrade_button, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->device_information_page_firmware_version_upgrade_button, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->device_information_page_firmware_version_upgrade_button, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->device_information_page_firmware_version_upgrade_button, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->device_information_page_firmware_version_upgrade_button, &lv_font_PingFangSC_Medium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->device_information_page_firmware_version_upgrade_button, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->device_information_page_firmware_version_upgrade_button, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes device_information_page_firmware_version_title
    ui->device_information_page_firmware_version_title = lv_label_create(ui->device_information_page_list);
    lv_obj_set_pos(ui->device_information_page_firmware_version_title, 16, 441);
    lv_obj_set_size(ui->device_information_page_firmware_version_title, 128, 22);
    lv_label_set_text(ui->device_information_page_firmware_version_title, "固件版本");
    lv_label_set_long_mode(ui->device_information_page_firmware_version_title, LV_LABEL_LONG_WRAP);

    //Write style for device_information_page_firmware_version_title, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->device_information_page_firmware_version_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->device_information_page_firmware_version_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->device_information_page_firmware_version_title, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->device_information_page_firmware_version_title, &lv_font_PingFangSC_Regular_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->device_information_page_firmware_version_title, 174, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->device_information_page_firmware_version_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->device_information_page_firmware_version_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->device_information_page_firmware_version_title, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->device_information_page_firmware_version_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->device_information_page_firmware_version_title, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->device_information_page_firmware_version_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->device_information_page_firmware_version_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->device_information_page_firmware_version_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->device_information_page_firmware_version_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes device_information_page_firmware_version
    ui->device_information_page_firmware_version = lv_label_create(ui->device_information_page_list);
    lv_obj_set_pos(ui->device_information_page_firmware_version, 16, 415);
    lv_obj_set_size(ui->device_information_page_firmware_version, 160, 25);
    lv_label_set_text(ui->device_information_page_firmware_version, "V 2.3.0");
    lv_label_set_long_mode(ui->device_information_page_firmware_version, LV_LABEL_LONG_WRAP);

    //Write style for device_information_page_firmware_version, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->device_information_page_firmware_version, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->device_information_page_firmware_version, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->device_information_page_firmware_version, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->device_information_page_firmware_version, &lv_font_PingFangSC_Semibold_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->device_information_page_firmware_version, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->device_information_page_firmware_version, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->device_information_page_firmware_version, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->device_information_page_firmware_version, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->device_information_page_firmware_version, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->device_information_page_firmware_version, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->device_information_page_firmware_version, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->device_information_page_firmware_version, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->device_information_page_firmware_version, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->device_information_page_firmware_version, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes device_information_page_line_4
    ui->device_information_page_line_4 = lv_line_create(ui->device_information_page_list);
    lv_obj_set_pos(ui->device_information_page_line_4, 16, 407);
    lv_obj_set_size(ui->device_information_page_line_4, 208, 2);
    static lv_point_precise_t device_information_page_line_4[] = {{0, 0},{208, 0}};
    lv_line_set_points(ui->device_information_page_line_4, device_information_page_line_4, 2);

    //Write style for device_information_page_line_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_line_width(ui->device_information_page_line_4, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_color(ui->device_information_page_line_4, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_opa(ui->device_information_page_line_4, 51, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_rounded(ui->device_information_page_line_4, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes device_information_page_device_model_title
    ui->device_information_page_device_model_title = lv_label_create(ui->device_information_page_list);
    lv_obj_set_pos(ui->device_information_page_device_model_title, 16, 373);
    lv_obj_set_size(ui->device_information_page_device_model_title, 128, 22);
    lv_label_set_text(ui->device_information_page_device_model_title, "设备型号");
    lv_label_set_long_mode(ui->device_information_page_device_model_title, LV_LABEL_LONG_WRAP);

    //Write style for device_information_page_device_model_title, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->device_information_page_device_model_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->device_information_page_device_model_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->device_information_page_device_model_title, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->device_information_page_device_model_title, &lv_font_PingFangSC_Regular_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->device_information_page_device_model_title, 174, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->device_information_page_device_model_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->device_information_page_device_model_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->device_information_page_device_model_title, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->device_information_page_device_model_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->device_information_page_device_model_title, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->device_information_page_device_model_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->device_information_page_device_model_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->device_information_page_device_model_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->device_information_page_device_model_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes device_information_page_device_model
    ui->device_information_page_device_model = lv_label_create(ui->device_information_page_list);
    lv_obj_set_pos(ui->device_information_page_device_model, 16, 347);
    lv_obj_set_size(ui->device_information_page_device_model, 160, 25);
    lv_label_set_text(ui->device_information_page_device_model, "YQ201");
    lv_label_set_long_mode(ui->device_information_page_device_model, LV_LABEL_LONG_WRAP);

    //Write style for device_information_page_device_model, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->device_information_page_device_model, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->device_information_page_device_model, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->device_information_page_device_model, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->device_information_page_device_model, &lv_font_PingFangSC_Semibold_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->device_information_page_device_model, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->device_information_page_device_model, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->device_information_page_device_model, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->device_information_page_device_model, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->device_information_page_device_model, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->device_information_page_device_model, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->device_information_page_device_model, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->device_information_page_device_model, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->device_information_page_device_model, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->device_information_page_device_model, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes device_information_page_line_3
    ui->device_information_page_line_3 = lv_line_create(ui->device_information_page_list);
    lv_obj_set_pos(ui->device_information_page_line_3, 16, 338);
    lv_obj_set_size(ui->device_information_page_line_3, 208, 2);
    static lv_point_precise_t device_information_page_line_3[] = {{0, 0},{208, 0}};
    lv_line_set_points(ui->device_information_page_line_3, device_information_page_line_3, 2);

    //Write style for device_information_page_line_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_line_width(ui->device_information_page_line_3, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_color(ui->device_information_page_line_3, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_opa(ui->device_information_page_line_3, 51, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_rounded(ui->device_information_page_line_3, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes device_information_page_device_name_title
    ui->device_information_page_device_name_title = lv_label_create(ui->device_information_page_list);
    lv_obj_set_pos(ui->device_information_page_device_name_title, 16, 304);
    lv_obj_set_size(ui->device_information_page_device_name_title, 128, 22);
    lv_label_set_text(ui->device_information_page_device_name_title, "设备名称");
    lv_label_set_long_mode(ui->device_information_page_device_name_title, LV_LABEL_LONG_WRAP);

    //Write style for device_information_page_device_name_title, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->device_information_page_device_name_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->device_information_page_device_name_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->device_information_page_device_name_title, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->device_information_page_device_name_title, &lv_font_PingFangSC_Regular_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->device_information_page_device_name_title, 174, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->device_information_page_device_name_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->device_information_page_device_name_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->device_information_page_device_name_title, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->device_information_page_device_name_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->device_information_page_device_name_title, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->device_information_page_device_name_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->device_information_page_device_name_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->device_information_page_device_name_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->device_information_page_device_name_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes device_information_page_device_name
    ui->device_information_page_device_name = lv_label_create(ui->device_information_page_list);
    lv_obj_set_pos(ui->device_information_page_device_name, 16, 278);
    lv_obj_set_size(ui->device_information_page_device_name, 160, 25);
    lv_label_set_text(ui->device_information_page_device_name, "小小优趣视听精灵");
    lv_label_set_long_mode(ui->device_information_page_device_name, LV_LABEL_LONG_WRAP);

    //Write style for device_information_page_device_name, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->device_information_page_device_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->device_information_page_device_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->device_information_page_device_name, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->device_information_page_device_name, &lv_font_PingFangSC_Semibold_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->device_information_page_device_name, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->device_information_page_device_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->device_information_page_device_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->device_information_page_device_name, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->device_information_page_device_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->device_information_page_device_name, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->device_information_page_device_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->device_information_page_device_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->device_information_page_device_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->device_information_page_device_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes device_information_page_line_2
    ui->device_information_page_line_2 = lv_line_create(ui->device_information_page_list);
    lv_obj_set_pos(ui->device_information_page_line_2, 16, 265);
    lv_obj_set_size(ui->device_information_page_line_2, 208, 2);
    static lv_point_precise_t device_information_page_line_2[] = {{0, 0},{208, 0}};
    lv_line_set_points(ui->device_information_page_line_2, device_information_page_line_2, 2);

    //Write style for device_information_page_line_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_line_width(ui->device_information_page_line_2, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_color(ui->device_information_page_line_2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_opa(ui->device_information_page_line_2, 51, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_rounded(ui->device_information_page_line_2, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes device_information_page_cache_file_size
    ui->device_information_page_cache_file_size = lv_label_create(ui->device_information_page_list);
    lv_obj_set_pos(ui->device_information_page_cache_file_size, 28, 231);
    lv_obj_set_size(ui->device_information_page_cache_file_size, 150, 22);
    lv_label_set_text(ui->device_information_page_cache_file_size, "缓存 1.4G");
    lv_label_set_long_mode(ui->device_information_page_cache_file_size, LV_LABEL_LONG_WRAP);

    //Write style for device_information_page_cache_file_size, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->device_information_page_cache_file_size, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->device_information_page_cache_file_size, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->device_information_page_cache_file_size, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->device_information_page_cache_file_size, &lv_font_PingFangSC_Regular_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->device_information_page_cache_file_size, 131, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->device_information_page_cache_file_size, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->device_information_page_cache_file_size, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->device_information_page_cache_file_size, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->device_information_page_cache_file_size, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->device_information_page_cache_file_size, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->device_information_page_cache_file_size, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->device_information_page_cache_file_size, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->device_information_page_cache_file_size, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->device_information_page_cache_file_size, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes device_information_page_sample_color_3
    ui->device_information_page_sample_color_3 = lv_obj_create(ui->device_information_page_list);
    lv_obj_set_pos(ui->device_information_page_sample_color_3, 16, 240);
    lv_obj_set_size(ui->device_information_page_sample_color_3, 8, 8);
    lv_obj_set_scrollbar_mode(ui->device_information_page_sample_color_3, LV_SCROLLBAR_MODE_OFF);

    //Write style for device_information_page_sample_color_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->device_information_page_sample_color_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->device_information_page_sample_color_3, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->device_information_page_sample_color_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->device_information_page_sample_color_3, lv_color_hex(0xff5000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->device_information_page_sample_color_3, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->device_information_page_sample_color_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->device_information_page_sample_color_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->device_information_page_sample_color_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->device_information_page_sample_color_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->device_information_page_sample_color_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes device_information_page_audio_file_size
    ui->device_information_page_audio_file_size = lv_label_create(ui->device_information_page_list);
    lv_obj_set_pos(ui->device_information_page_audio_file_size, 27, 205);
    lv_obj_set_size(ui->device_information_page_audio_file_size, 150, 22);
    lv_label_set_text(ui->device_information_page_audio_file_size, "音频 16.3G");
    lv_label_set_long_mode(ui->device_information_page_audio_file_size, LV_LABEL_LONG_WRAP);

    //Write style for device_information_page_audio_file_size, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->device_information_page_audio_file_size, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->device_information_page_audio_file_size, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->device_information_page_audio_file_size, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->device_information_page_audio_file_size, &lv_font_PingFangSC_Regular_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->device_information_page_audio_file_size, 131, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->device_information_page_audio_file_size, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->device_information_page_audio_file_size, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->device_information_page_audio_file_size, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->device_information_page_audio_file_size, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->device_information_page_audio_file_size, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->device_information_page_audio_file_size, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->device_information_page_audio_file_size, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->device_information_page_audio_file_size, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->device_information_page_audio_file_size, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes device_information_page_sample_color_2
    ui->device_information_page_sample_color_2 = lv_obj_create(ui->device_information_page_list);
    lv_obj_set_pos(ui->device_information_page_sample_color_2, 16, 214);
    lv_obj_set_size(ui->device_information_page_sample_color_2, 8, 8);
    lv_obj_set_scrollbar_mode(ui->device_information_page_sample_color_2, LV_SCROLLBAR_MODE_OFF);

    //Write style for device_information_page_sample_color_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->device_information_page_sample_color_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->device_information_page_sample_color_2, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->device_information_page_sample_color_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->device_information_page_sample_color_2, lv_color_hex(0x627aef), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->device_information_page_sample_color_2, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->device_information_page_sample_color_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->device_information_page_sample_color_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->device_information_page_sample_color_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->device_information_page_sample_color_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->device_information_page_sample_color_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes device_information_page_system_file_size
    ui->device_information_page_system_file_size = lv_label_create(ui->device_information_page_list);
    lv_obj_set_pos(ui->device_information_page_system_file_size, 28, 180);
    lv_obj_set_size(ui->device_information_page_system_file_size, 150, 22);
    lv_label_set_text(ui->device_information_page_system_file_size, "系统文件 3.2G");
    lv_label_set_long_mode(ui->device_information_page_system_file_size, LV_LABEL_LONG_WRAP);

    //Write style for device_information_page_system_file_size, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->device_information_page_system_file_size, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->device_information_page_system_file_size, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->device_information_page_system_file_size, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->device_information_page_system_file_size, &lv_font_PingFangSC_Regular_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->device_information_page_system_file_size, 131, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->device_information_page_system_file_size, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->device_information_page_system_file_size, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->device_information_page_system_file_size, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->device_information_page_system_file_size, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->device_information_page_system_file_size, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->device_information_page_system_file_size, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->device_information_page_system_file_size, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->device_information_page_system_file_size, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->device_information_page_system_file_size, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes device_information_page_sample_color_1
    ui->device_information_page_sample_color_1 = lv_obj_create(ui->device_information_page_list);
    lv_obj_set_pos(ui->device_information_page_sample_color_1, 16, 188);
    lv_obj_set_size(ui->device_information_page_sample_color_1, 8, 8);
    lv_obj_set_scrollbar_mode(ui->device_information_page_sample_color_1, LV_SCROLLBAR_MODE_OFF);

    //Write style for device_information_page_sample_color_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->device_information_page_sample_color_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->device_information_page_sample_color_1, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->device_information_page_sample_color_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->device_information_page_sample_color_1, lv_color_hex(0xb1b1b1), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->device_information_page_sample_color_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->device_information_page_sample_color_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->device_information_page_sample_color_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->device_information_page_sample_color_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->device_information_page_sample_color_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->device_information_page_sample_color_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes device_information_page_cache_file_bar
    ui->device_information_page_cache_file_bar = lv_bar_create(ui->device_information_page_list);
    lv_obj_set_pos(ui->device_information_page_cache_file_bar, 16, 157);
    lv_obj_set_size(ui->device_information_page_cache_file_bar, 208, 8);
    lv_obj_set_style_anim_duration(ui->device_information_page_cache_file_bar, 1000, 0);
    lv_bar_set_mode(ui->device_information_page_cache_file_bar, LV_BAR_MODE_NORMAL);
    lv_bar_set_range(ui->device_information_page_cache_file_bar, 0, 4762);
    lv_bar_set_value(ui->device_information_page_cache_file_bar, 2090, LV_ANIM_OFF);

    //Write style for device_information_page_cache_file_bar, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->device_information_page_cache_file_bar, 65, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->device_information_page_cache_file_bar, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->device_information_page_cache_file_bar, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->device_information_page_cache_file_bar, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->device_information_page_cache_file_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for device_information_page_cache_file_bar, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->device_information_page_cache_file_bar, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->device_information_page_cache_file_bar, lv_color_hex(0xff5000), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->device_information_page_cache_file_bar, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->device_information_page_cache_file_bar, 0, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write codes device_information_page_audio_file_bar
    ui->device_information_page_audio_file_bar = lv_bar_create(ui->device_information_page_list);
    lv_obj_set_pos(ui->device_information_page_audio_file_bar, 16, 157);
    lv_obj_set_size(ui->device_information_page_audio_file_bar, 208, 8);
    lv_obj_set_style_anim_duration(ui->device_information_page_audio_file_bar, 1000, 0);
    lv_bar_set_mode(ui->device_information_page_audio_file_bar, LV_BAR_MODE_NORMAL);
    lv_bar_set_range(ui->device_information_page_audio_file_bar, 0, 4762);
    lv_bar_set_value(ui->device_information_page_audio_file_bar, 1950, LV_ANIM_OFF);

    //Write style for device_information_page_audio_file_bar, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->device_information_page_audio_file_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->device_information_page_audio_file_bar, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->device_information_page_audio_file_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for device_information_page_audio_file_bar, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->device_information_page_audio_file_bar, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->device_information_page_audio_file_bar, lv_color_hex(0x627aef), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->device_information_page_audio_file_bar, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->device_information_page_audio_file_bar, 0, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write codes device_information_page_system_file_bar
    ui->device_information_page_system_file_bar = lv_bar_create(ui->device_information_page_list);
    lv_obj_set_pos(ui->device_information_page_system_file_bar, 16, 157);
    lv_obj_set_size(ui->device_information_page_system_file_bar, 208, 8);
    lv_obj_set_style_anim_duration(ui->device_information_page_system_file_bar, 1000, 0);
    lv_bar_set_mode(ui->device_information_page_system_file_bar, LV_BAR_MODE_NORMAL);
    lv_bar_set_range(ui->device_information_page_system_file_bar, 0, 4762);
    lv_bar_set_value(ui->device_information_page_system_file_bar, 320, LV_ANIM_OFF);

    //Write style for device_information_page_system_file_bar, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->device_information_page_system_file_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->device_information_page_system_file_bar, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->device_information_page_system_file_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for device_information_page_system_file_bar, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->device_information_page_system_file_bar, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->device_information_page_system_file_bar, lv_color_hex(0xb1b1b1), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->device_information_page_system_file_bar, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->device_information_page_system_file_bar, 0, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write codes device_information_page_clear_cache_button
    ui->device_information_page_clear_cache_button = lv_button_create(ui->device_information_page_list);
    lv_obj_set_pos(ui->device_information_page_clear_cache_button, 144, 93);
    lv_obj_set_size(ui->device_information_page_clear_cache_button, 80, 36);
    ui->device_information_page_clear_cache_button_label = lv_label_create(ui->device_information_page_clear_cache_button);
    lv_label_set_text(ui->device_information_page_clear_cache_button_label, "清除缓存");
    lv_label_set_long_mode(ui->device_information_page_clear_cache_button_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->device_information_page_clear_cache_button_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->device_information_page_clear_cache_button, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->device_information_page_clear_cache_button_label, LV_PCT(100));

    //Write style for device_information_page_clear_cache_button, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->device_information_page_clear_cache_button, 28, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->device_information_page_clear_cache_button, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->device_information_page_clear_cache_button, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->device_information_page_clear_cache_button, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->device_information_page_clear_cache_button, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->device_information_page_clear_cache_button, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->device_information_page_clear_cache_button, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->device_information_page_clear_cache_button, &lv_font_PingFangSC_Medium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->device_information_page_clear_cache_button, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->device_information_page_clear_cache_button, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes device_information_page_available_space_title
    ui->device_information_page_available_space_title = lv_label_create(ui->device_information_page_list);
    lv_obj_set_pos(ui->device_information_page_available_space_title, 16, 123);
    lv_obj_set_size(ui->device_information_page_available_space_title, 64, 18);
    lv_label_set_text(ui->device_information_page_available_space_title, "可用空间");
    lv_label_set_long_mode(ui->device_information_page_available_space_title, LV_LABEL_LONG_WRAP);

    //Write style for device_information_page_available_space_title, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->device_information_page_available_space_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->device_information_page_available_space_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->device_information_page_available_space_title, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->device_information_page_available_space_title, &lv_font_PingFangSC_Regular_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->device_information_page_available_space_title, 174, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->device_information_page_available_space_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->device_information_page_available_space_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->device_information_page_available_space_title, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->device_information_page_available_space_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->device_information_page_available_space_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->device_information_page_available_space_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->device_information_page_available_space_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->device_information_page_available_space_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->device_information_page_available_space_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes device_information_page_available_space
    ui->device_information_page_available_space = lv_label_create(ui->device_information_page_list);
    lv_obj_set_pos(ui->device_information_page_available_space, 15, 93);
    lv_obj_set_size(ui->device_information_page_available_space, 82, 28);
    lv_label_set_text(ui->device_information_page_available_space, "26.72GB");
    lv_label_set_long_mode(ui->device_information_page_available_space, LV_LABEL_LONG_WRAP);

    //Write style for device_information_page_available_space, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->device_information_page_available_space, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->device_information_page_available_space, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->device_information_page_available_space, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->device_information_page_available_space, &lv_font_PingFangSC_Semibold_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->device_information_page_available_space, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->device_information_page_available_space, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->device_information_page_available_space, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->device_information_page_available_space, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->device_information_page_available_space, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->device_information_page_available_space, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->device_information_page_available_space, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->device_information_page_available_space, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->device_information_page_available_space, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->device_information_page_available_space, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes device_information_page_line_1
    ui->device_information_page_line_1 = lv_line_create(ui->device_information_page_list);
    lv_obj_set_pos(ui->device_information_page_line_1, 16, 76);
    lv_obj_set_size(ui->device_information_page_line_1, 208, 2);
    static lv_point_precise_t device_information_page_line_1[] = {{0, 0},{208, 0}};
    lv_line_set_points(ui->device_information_page_line_1, device_information_page_line_1, 2);

    //Write style for device_information_page_line_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_line_width(ui->device_information_page_line_1, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_color(ui->device_information_page_line_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_opa(ui->device_information_page_line_1, 51, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_rounded(ui->device_information_page_line_1, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes device_information_page_storage_space_title
    ui->device_information_page_storage_space_title = lv_label_create(ui->device_information_page_list);
    lv_obj_set_pos(ui->device_information_page_storage_space_title, 16, 42);
    lv_obj_set_size(ui->device_information_page_storage_space_title, 64, 18);
    lv_label_set_text(ui->device_information_page_storage_space_title, "储存空间");
    lv_label_set_long_mode(ui->device_information_page_storage_space_title, LV_LABEL_LONG_WRAP);

    //Write style for device_information_page_storage_space_title, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->device_information_page_storage_space_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->device_information_page_storage_space_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->device_information_page_storage_space_title, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->device_information_page_storage_space_title, &lv_font_PingFangSC_Regular_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->device_information_page_storage_space_title, 174, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->device_information_page_storage_space_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->device_information_page_storage_space_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->device_information_page_storage_space_title, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->device_information_page_storage_space_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->device_information_page_storage_space_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->device_information_page_storage_space_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->device_information_page_storage_space_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->device_information_page_storage_space_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->device_information_page_storage_space_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes device_information_page_storage_space
    ui->device_information_page_storage_space = lv_label_create(ui->device_information_page_list);
    lv_obj_set_pos(ui->device_information_page_storage_space, 16, 12);
    lv_obj_set_size(ui->device_information_page_storage_space, 128, 22);
    lv_label_set_text(ui->device_information_page_storage_space, "64GB");
    lv_label_set_long_mode(ui->device_information_page_storage_space, LV_LABEL_LONG_WRAP);

    //Write style for device_information_page_storage_space, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->device_information_page_storage_space, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->device_information_page_storage_space, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->device_information_page_storage_space, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->device_information_page_storage_space, &lv_font_PingFangSC_Semibold_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->device_information_page_storage_space, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->device_information_page_storage_space, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->device_information_page_storage_space, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->device_information_page_storage_space, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->device_information_page_storage_space, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->device_information_page_storage_space, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->device_information_page_storage_space, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->device_information_page_storage_space, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->device_information_page_storage_space, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->device_information_page_storage_space, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes device_information_page_status_bar
    ui->device_information_page_status_bar = lv_obj_create(ui->device_information_page);
    lv_obj_set_pos(ui->device_information_page_status_bar, 0, 0);
    lv_obj_set_size(ui->device_information_page_status_bar, 240, 64);
    lv_obj_set_scrollbar_mode(ui->device_information_page_status_bar, LV_SCROLLBAR_MODE_OFF);

    //Write style for device_information_page_status_bar, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->device_information_page_status_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->device_information_page_status_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->device_information_page_status_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->device_information_page_status_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->device_information_page_status_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->device_information_page_status_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->device_information_page_status_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->device_information_page_status_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes device_information_page_main_title
    ui->device_information_page_main_title = lv_label_create(ui->device_information_page_status_bar);
    lv_obj_set_pos(ui->device_information_page_main_title, 148, 32);
    lv_obj_set_size(ui->device_information_page_main_title, 80, 28);
    lv_label_set_text(ui->device_information_page_main_title, "设备信息");
    lv_label_set_long_mode(ui->device_information_page_main_title, LV_LABEL_LONG_WRAP);

    //Write style for device_information_page_main_title, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->device_information_page_main_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->device_information_page_main_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->device_information_page_main_title, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->device_information_page_main_title, &lv_font_PingFangSC_Medium_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->device_information_page_main_title, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->device_information_page_main_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->device_information_page_main_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->device_information_page_main_title, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->device_information_page_main_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->device_information_page_main_title, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->device_information_page_main_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->device_information_page_main_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->device_information_page_main_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->device_information_page_main_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes device_information_page_left_control_button
    ui->device_information_page_left_control_button = lv_image_create(ui->device_information_page_status_bar);
    lv_obj_set_pos(ui->device_information_page_left_control_button, 16, 16);
    lv_obj_set_size(ui->device_information_page_left_control_button, 40, 40);
    lv_obj_add_flag(ui->device_information_page_left_control_button, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->device_information_page_left_control_button, &_left_control_RGB565A8_40x40);
    lv_image_set_pivot(ui->device_information_page_left_control_button, 50,50);
    lv_image_set_rotation(ui->device_information_page_left_control_button, 0);

    //Write style for device_information_page_left_control_button, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->device_information_page_left_control_button, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->device_information_page_left_control_button, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of device_information_page.
    lv_obj_set_style_text_font(ui->device_information_page_sn_code, &lv_font_MyPingFangSC_Semibold_18, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->device_information_page_device_number, &lv_font_MyPingFangSC_Semibold_18, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->device_information_page_firmware_version, &lv_font_MyPingFangSC_Semibold_18, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->device_information_page_device_model, &lv_font_MyPingFangSC_Semibold_18, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->device_information_page_device_name, &lv_font_MyPingFangSC_Semibold_18, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->device_information_page_cache_file_size, &lv_font_MyPingFangSC_Regular_16, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->device_information_page_audio_file_size, &lv_font_MyPingFangSC_Regular_16, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->device_information_page_system_file_size, &lv_font_MyPingFangSC_Regular_16, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->device_information_page_available_space, &lv_font_MyPingFangSC_Semibold_20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->device_information_page_storage_space, &lv_font_MyPingFangSC_Semibold_20, LV_PART_MAIN | LV_STATE_DEFAULT);

    //Update current screen layout.
    lv_obj_update_layout(ui->device_information_page);

    //Init events for screen.
    events_init_device_information_page(ui);
}
