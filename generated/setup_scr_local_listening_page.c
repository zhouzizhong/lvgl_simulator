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



void setup_scr_local_listening_page(lv_ui *ui)
{
    //Write codes local_listening_page
    ui->local_listening_page = lv_obj_create(NULL);
    lv_obj_set_size(ui->local_listening_page, 240, 320);
    lv_obj_set_scrollbar_mode(ui->local_listening_page, LV_SCROLLBAR_MODE_OFF);

    //Write style for local_listening_page, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->local_listening_page, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->local_listening_page, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->local_listening_page, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes local_listening_page_list
    ui->local_listening_page_list = lv_obj_create(ui->local_listening_page);
    lv_obj_set_pos(ui->local_listening_page_list, 0, 64);
    lv_obj_set_size(ui->local_listening_page_list, 240, 256);
    lv_obj_set_scrollbar_mode(ui->local_listening_page_list, LV_SCROLLBAR_MODE_OFF);

    //Write style for local_listening_page_list, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->local_listening_page_list, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->local_listening_page_list, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->local_listening_page_list, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->local_listening_page_list, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->local_listening_page_list, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->local_listening_page_list, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->local_listening_page_list, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->local_listening_page_list, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes local_listening_page_status_bar
    ui->local_listening_page_status_bar = lv_obj_create(ui->local_listening_page);
    lv_obj_set_pos(ui->local_listening_page_status_bar, 0, 0);
    lv_obj_set_size(ui->local_listening_page_status_bar, 240, 64);
    lv_obj_set_scrollbar_mode(ui->local_listening_page_status_bar, LV_SCROLLBAR_MODE_OFF);

    //Write style for local_listening_page_status_bar, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->local_listening_page_status_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->local_listening_page_status_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->local_listening_page_status_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->local_listening_page_status_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->local_listening_page_status_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->local_listening_page_status_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->local_listening_page_status_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->local_listening_page_status_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes local_listening_page_main_title
    ui->local_listening_page_main_title = lv_label_create(ui->local_listening_page_status_bar);
    lv_obj_set_pos(ui->local_listening_page_main_title, 78, 32);
    lv_obj_set_size(ui->local_listening_page_main_title, 150, 28);
    lv_label_set_text(ui->local_listening_page_main_title, "自定义专辑");
    lv_label_set_long_mode(ui->local_listening_page_main_title, LV_LABEL_LONG_WRAP);

    //Write style for local_listening_page_main_title, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->local_listening_page_main_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->local_listening_page_main_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->local_listening_page_main_title, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->local_listening_page_main_title, &lv_font_PingFangSC_Medium_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->local_listening_page_main_title, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->local_listening_page_main_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->local_listening_page_main_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->local_listening_page_main_title, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->local_listening_page_main_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->local_listening_page_main_title, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->local_listening_page_main_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->local_listening_page_main_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->local_listening_page_main_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->local_listening_page_main_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes local_listening_page_left_control_button
    ui->local_listening_page_left_control_button = lv_image_create(ui->local_listening_page_status_bar);
    lv_obj_set_pos(ui->local_listening_page_left_control_button, 16, 16);
    lv_obj_set_size(ui->local_listening_page_left_control_button, 40, 40);
    lv_obj_add_flag(ui->local_listening_page_left_control_button, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->local_listening_page_left_control_button, &_left_control_RGB565A8_40x40);
    lv_image_set_pivot(ui->local_listening_page_left_control_button, 50,50);
    lv_image_set_rotation(ui->local_listening_page_left_control_button, 0);

    //Write style for local_listening_page_left_control_button, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->local_listening_page_left_control_button, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->local_listening_page_left_control_button, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of local_listening_page.


    //Update current screen layout.
    lv_obj_update_layout(ui->local_listening_page);

}
