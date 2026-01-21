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



void setup_scr_account_login_page(lv_ui *ui)
{
    //Write codes account_login_page
    ui->account_login_page = lv_obj_create(NULL);
    lv_obj_set_size(ui->account_login_page, 240, 320);
    lv_obj_set_scrollbar_mode(ui->account_login_page, LV_SCROLLBAR_MODE_OFF);

    //Write style for account_login_page, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->account_login_page, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->account_login_page, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->account_login_page, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes account_login_page_mask
    ui->account_login_page_mask = lv_obj_create(ui->account_login_page);
    lv_obj_set_pos(ui->account_login_page_mask, 16, 113);
    lv_obj_set_size(ui->account_login_page_mask, 208, 177);
    lv_obj_set_scrollbar_mode(ui->account_login_page_mask, LV_SCROLLBAR_MODE_OFF);

    //Write style for account_login_page_mask, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->account_login_page_mask, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->account_login_page_mask, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->account_login_page_mask, 28, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->account_login_page_mask, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->account_login_page_mask, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->account_login_page_mask, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->account_login_page_mask, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->account_login_page_mask, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->account_login_page_mask, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->account_login_page_mask, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes account_login_page_solid_color_background
    ui->account_login_page_solid_color_background = lv_obj_create(ui->account_login_page_mask);
    lv_obj_set_pos(ui->account_login_page_solid_color_background, 36, 20);
    lv_obj_set_size(ui->account_login_page_solid_color_background, 137, 137);
    lv_obj_set_scrollbar_mode(ui->account_login_page_solid_color_background, LV_SCROLLBAR_MODE_OFF);

    //Write style for account_login_page_solid_color_background, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->account_login_page_solid_color_background, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->account_login_page_solid_color_background, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->account_login_page_solid_color_background, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->account_login_page_solid_color_background, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->account_login_page_solid_color_background, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->account_login_page_solid_color_background, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->account_login_page_solid_color_background, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->account_login_page_solid_color_background, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->account_login_page_solid_color_background, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->account_login_page_solid_color_background, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes account_login_page_account_login_qrcode
    ui->account_login_page_account_login_qrcode = lv_qrcode_create(ui->account_login_page_solid_color_background);
    lv_obj_set_pos(ui->account_login_page_account_login_qrcode, 10, 10);
    lv_obj_set_size(ui->account_login_page_account_login_qrcode, 117, 117);
    lv_qrcode_set_size(ui->account_login_page_account_login_qrcode, 117);
    lv_qrcode_set_dark_color(ui->account_login_page_account_login_qrcode, lv_color_hex(0x2C3224));
    lv_qrcode_set_light_color(ui->account_login_page_account_login_qrcode, lv_color_hex(0xffffff));
    const char * account_login_page_account_login_qrcode_data = "https://www.nxp.com/";
    lv_qrcode_update(ui->account_login_page_account_login_qrcode, account_login_page_account_login_qrcode_data, 20);

    //Write codes account_login_page_tips
    ui->account_login_page_tips = lv_label_create(ui->account_login_page);
    lv_obj_set_pos(ui->account_login_page_tips, 57, 76);
    lv_obj_set_size(ui->account_login_page_tips, 126, 25);
    lv_label_set_text(ui->account_login_page_tips, "使用微信扫一扫");
    lv_label_set_long_mode(ui->account_login_page_tips, LV_LABEL_LONG_WRAP);

    //Write style for account_login_page_tips, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->account_login_page_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->account_login_page_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->account_login_page_tips, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->account_login_page_tips, &lv_font_PingFangSC_Semibold_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->account_login_page_tips, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->account_login_page_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->account_login_page_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->account_login_page_tips, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->account_login_page_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->account_login_page_tips, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->account_login_page_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->account_login_page_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->account_login_page_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->account_login_page_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes account_login_page_status_bar
    ui->account_login_page_status_bar = lv_obj_create(ui->account_login_page);
    lv_obj_set_pos(ui->account_login_page_status_bar, 0, 0);
    lv_obj_set_size(ui->account_login_page_status_bar, 240, 64);
    lv_obj_set_scrollbar_mode(ui->account_login_page_status_bar, LV_SCROLLBAR_MODE_OFF);

    //Write style for account_login_page_status_bar, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->account_login_page_status_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->account_login_page_status_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->account_login_page_status_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->account_login_page_status_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->account_login_page_status_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->account_login_page_status_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->account_login_page_status_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->account_login_page_status_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes account_login_page_main_title
    ui->account_login_page_main_title = lv_label_create(ui->account_login_page_status_bar);
    lv_obj_set_pos(ui->account_login_page_main_title, 148, 32);
    lv_obj_set_size(ui->account_login_page_main_title, 80, 28);
    lv_label_set_text(ui->account_login_page_main_title, "账号登录");
    lv_label_set_long_mode(ui->account_login_page_main_title, LV_LABEL_LONG_WRAP);

    //Write style for account_login_page_main_title, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->account_login_page_main_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->account_login_page_main_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->account_login_page_main_title, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->account_login_page_main_title, &lv_font_PingFangSC_Medium_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->account_login_page_main_title, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->account_login_page_main_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->account_login_page_main_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->account_login_page_main_title, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->account_login_page_main_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->account_login_page_main_title, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->account_login_page_main_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->account_login_page_main_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->account_login_page_main_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->account_login_page_main_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes account_login_page_left_control_button
    ui->account_login_page_left_control_button = lv_image_create(ui->account_login_page_status_bar);
    lv_obj_set_pos(ui->account_login_page_left_control_button, 16, 16);
    lv_obj_set_size(ui->account_login_page_left_control_button, 40, 40);
    lv_obj_add_flag(ui->account_login_page_left_control_button, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->account_login_page_left_control_button, &_left_control_RGB565A8_40x40);
    lv_image_set_pivot(ui->account_login_page_left_control_button, 50,50);
    lv_image_set_rotation(ui->account_login_page_left_control_button, 0);

    //Write style for account_login_page_left_control_button, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->account_login_page_left_control_button, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->account_login_page_left_control_button, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of account_login_page.


    //Update current screen layout.
    lv_obj_update_layout(ui->account_login_page);

    //Init events for screen.
    events_init_account_login_page(ui);
}
