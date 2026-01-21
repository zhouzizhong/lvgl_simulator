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



void setup_scr_screen_brightness_page(lv_ui *ui)
{
    //Write codes screen_brightness_page
    ui->screen_brightness_page = lv_obj_create(NULL);
    lv_obj_set_size(ui->screen_brightness_page, 240, 320);
    lv_obj_set_scrollbar_mode(ui->screen_brightness_page, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_brightness_page, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_brightness_page, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_brightness_page, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_brightness_page, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_brightness_page_automatic_screen_off
    ui->screen_brightness_page_automatic_screen_off = lv_obj_create(ui->screen_brightness_page);
    lv_obj_set_pos(ui->screen_brightness_page_automatic_screen_off, 16, 162);
    lv_obj_set_size(ui->screen_brightness_page_automatic_screen_off, 208, 68);
    lv_obj_set_scrollbar_mode(ui->screen_brightness_page_automatic_screen_off, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_brightness_page_automatic_screen_off, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_brightness_page_automatic_screen_off, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_brightness_page_automatic_screen_off, 14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_brightness_page_automatic_screen_off, 26, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_brightness_page_automatic_screen_off, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_brightness_page_automatic_screen_off, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_brightness_page_automatic_screen_off, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_brightness_page_automatic_screen_off, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_brightness_page_automatic_screen_off, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_brightness_page_automatic_screen_off, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_brightness_page_automatic_screen_off, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_brightness_page_automatic_screen_off_switch
    ui->screen_brightness_page_automatic_screen_off_switch = lv_switch_create(ui->screen_brightness_page_automatic_screen_off);
    lv_obj_set_pos(ui->screen_brightness_page_automatic_screen_off_switch, 159, 11);
    lv_obj_set_size(ui->screen_brightness_page_automatic_screen_off_switch, 36, 22);

    //Write style for screen_brightness_page_automatic_screen_off_switch, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_brightness_page_automatic_screen_off_switch, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_brightness_page_automatic_screen_off_switch, lv_color_hex(0x88898d), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_brightness_page_automatic_screen_off_switch, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_brightness_page_automatic_screen_off_switch, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_brightness_page_automatic_screen_off_switch, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_brightness_page_automatic_screen_off_switch, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_brightness_page_automatic_screen_off_switch, Part: LV_PART_INDICATOR, State: LV_STATE_CHECKED.
    lv_obj_set_style_bg_opa(ui->screen_brightness_page_automatic_screen_off_switch, 255, LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui->screen_brightness_page_automatic_screen_off_switch, lv_color_hex(0x04de71), LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_dir(ui->screen_brightness_page_automatic_screen_off_switch, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui->screen_brightness_page_automatic_screen_off_switch, 0, LV_PART_INDICATOR|LV_STATE_CHECKED);

    //Write style for screen_brightness_page_automatic_screen_off_switch, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_brightness_page_automatic_screen_off_switch, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_brightness_page_automatic_screen_off_switch, lv_color_hex(0xffffff), LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_brightness_page_automatic_screen_off_switch, LV_GRAD_DIR_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_brightness_page_automatic_screen_off_switch, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_brightness_page_automatic_screen_off_switch, 10, LV_PART_KNOB|LV_STATE_DEFAULT);

    //Write codes screen_brightness_page_automatic_screen_off_subtitle
    ui->screen_brightness_page_automatic_screen_off_subtitle = lv_label_create(ui->screen_brightness_page_automatic_screen_off);
    lv_obj_set_pos(ui->screen_brightness_page_automatic_screen_off_subtitle, 12, 37);
    lv_obj_set_size(ui->screen_brightness_page_automatic_screen_off_subtitle, 150, 18);
    lv_label_set_text(ui->screen_brightness_page_automatic_screen_off_subtitle, "设备无动作5分钟后息屏");
    lv_label_set_long_mode(ui->screen_brightness_page_automatic_screen_off_subtitle, LV_LABEL_LONG_WRAP);

    //Write style for screen_brightness_page_automatic_screen_off_subtitle, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_brightness_page_automatic_screen_off_subtitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_brightness_page_automatic_screen_off_subtitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_brightness_page_automatic_screen_off_subtitle, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_brightness_page_automatic_screen_off_subtitle, &lv_font_PingFangSC_Regular_14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_brightness_page_automatic_screen_off_subtitle, 192, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_brightness_page_automatic_screen_off_subtitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_brightness_page_automatic_screen_off_subtitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_brightness_page_automatic_screen_off_subtitle, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_brightness_page_automatic_screen_off_subtitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_brightness_page_automatic_screen_off_subtitle, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_brightness_page_automatic_screen_off_subtitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_brightness_page_automatic_screen_off_subtitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_brightness_page_automatic_screen_off_subtitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_brightness_page_automatic_screen_off_subtitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_brightness_page_automatic_screen_off_title
    ui->screen_brightness_page_automatic_screen_off_title = lv_label_create(ui->screen_brightness_page_automatic_screen_off);
    lv_obj_set_pos(ui->screen_brightness_page_automatic_screen_off_title, 12, 12);
    lv_obj_set_size(ui->screen_brightness_page_automatic_screen_off_title, 72, 20);
    lv_label_set_text(ui->screen_brightness_page_automatic_screen_off_title, "自动息屏");
    lv_label_set_long_mode(ui->screen_brightness_page_automatic_screen_off_title, LV_LABEL_LONG_WRAP);

    //Write style for screen_brightness_page_automatic_screen_off_title, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_brightness_page_automatic_screen_off_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_brightness_page_automatic_screen_off_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_brightness_page_automatic_screen_off_title, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_brightness_page_automatic_screen_off_title, &lv_font_PingFangSC_Medium_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_brightness_page_automatic_screen_off_title, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_brightness_page_automatic_screen_off_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_brightness_page_automatic_screen_off_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_brightness_page_automatic_screen_off_title, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_brightness_page_automatic_screen_off_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_brightness_page_automatic_screen_off_title, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_brightness_page_automatic_screen_off_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_brightness_page_automatic_screen_off_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_brightness_page_automatic_screen_off_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_brightness_page_automatic_screen_off_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_brightness_page_brightness_adjustment
    ui->screen_brightness_page_brightness_adjustment = lv_obj_create(ui->screen_brightness_page);
    lv_obj_set_pos(ui->screen_brightness_page_brightness_adjustment, 16, 74);
    lv_obj_set_size(ui->screen_brightness_page_brightness_adjustment, 208, 80);
    lv_obj_set_scrollbar_mode(ui->screen_brightness_page_brightness_adjustment, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_brightness_page_brightness_adjustment, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_brightness_page_brightness_adjustment, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_brightness_page_brightness_adjustment, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_brightness_page_brightness_adjustment, 28, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_brightness_page_brightness_adjustment, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_brightness_page_brightness_adjustment, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_brightness_page_brightness_adjustment, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_brightness_page_brightness_adjustment, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_brightness_page_brightness_adjustment, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_brightness_page_brightness_adjustment, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_brightness_page_brightness_adjustment, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_brightness_page_brightness_bar
    ui->screen_brightness_page_brightness_bar = lv_bar_create(ui->screen_brightness_page_brightness_adjustment);
    lv_obj_set_pos(ui->screen_brightness_page_brightness_bar, 63, 38);
    lv_obj_set_size(ui->screen_brightness_page_brightness_bar, 82, 4);
    lv_obj_set_style_anim_duration(ui->screen_brightness_page_brightness_bar, 1000, 0);
    lv_bar_set_mode(ui->screen_brightness_page_brightness_bar, LV_BAR_MODE_NORMAL);
    lv_bar_set_range(ui->screen_brightness_page_brightness_bar, 0, 3);
    lv_bar_set_value(ui->screen_brightness_page_brightness_bar, 2, LV_ANIM_OFF);

    //Write style for screen_brightness_page_brightness_bar, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_brightness_page_brightness_bar, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_brightness_page_brightness_bar, lv_color_hex(0x1b4f36), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_brightness_page_brightness_bar, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_brightness_page_brightness_bar, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_brightness_page_brightness_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_brightness_page_brightness_bar, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_brightness_page_brightness_bar, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_brightness_page_brightness_bar, lv_color_hex(0x04de71), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_brightness_page_brightness_bar, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_brightness_page_brightness_bar, 10, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write codes screen_brightness_page_mask_3
    ui->screen_brightness_page_mask_3 = lv_obj_create(ui->screen_brightness_page_brightness_adjustment);
    lv_obj_set_pos(ui->screen_brightness_page_mask_3, 90, 38);
    lv_obj_set_size(ui->screen_brightness_page_mask_3, 28, 4);
    lv_obj_set_scrollbar_mode(ui->screen_brightness_page_mask_3, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_brightness_page_mask_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_brightness_page_mask_3, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_brightness_page_mask_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_brightness_page_mask_3, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_brightness_page_mask_3, LV_BORDER_SIDE_LEFT | LV_BORDER_SIDE_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_brightness_page_mask_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_brightness_page_mask_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_brightness_page_mask_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_brightness_page_mask_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_brightness_page_mask_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_brightness_page_mask_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_brightness_page_mask_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_brightness_page_mask_2
    ui->screen_brightness_page_mask_2 = lv_obj_create(ui->screen_brightness_page_brightness_adjustment);
    lv_obj_set_pos(ui->screen_brightness_page_mask_2, 150, 0);
    lv_obj_set_size(ui->screen_brightness_page_mask_2, 56, 80);
    lv_obj_set_scrollbar_mode(ui->screen_brightness_page_mask_2, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_brightness_page_mask_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_brightness_page_mask_2, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_brightness_page_mask_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_brightness_page_mask_2, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_brightness_page_mask_2, LV_BORDER_SIDE_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_brightness_page_mask_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_brightness_page_mask_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_brightness_page_mask_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_brightness_page_mask_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_brightness_page_mask_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_brightness_page_mask_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_brightness_page_mask_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_brightness_page_brightness_up
    ui->screen_brightness_page_brightness_up = lv_image_create(ui->screen_brightness_page_mask_2);
    lv_obj_set_pos(ui->screen_brightness_page_brightness_up, 13, 25);
    lv_obj_set_size(ui->screen_brightness_page_brightness_up, 30, 30);
    lv_obj_add_flag(ui->screen_brightness_page_brightness_up, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->screen_brightness_page_brightness_up, &_brightness_up_RGB565A8_30x30);
    lv_image_set_pivot(ui->screen_brightness_page_brightness_up, 50,50);
    lv_image_set_rotation(ui->screen_brightness_page_brightness_up, 0);

    //Write style for screen_brightness_page_brightness_up, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->screen_brightness_page_brightness_up, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->screen_brightness_page_brightness_up, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_brightness_page_mask_1
    ui->screen_brightness_page_mask_1 = lv_obj_create(ui->screen_brightness_page_brightness_adjustment);
    lv_obj_set_pos(ui->screen_brightness_page_mask_1, 0, 0);
    lv_obj_set_size(ui->screen_brightness_page_mask_1, 56, 80);
    lv_obj_set_scrollbar_mode(ui->screen_brightness_page_mask_1, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_brightness_page_mask_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_brightness_page_mask_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_brightness_page_mask_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_brightness_page_mask_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_brightness_page_mask_1, LV_BORDER_SIDE_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_brightness_page_mask_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_brightness_page_mask_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_brightness_page_mask_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_brightness_page_mask_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_brightness_page_mask_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_brightness_page_mask_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_brightness_page_mask_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_brightness_page_brightness_dowm
    ui->screen_brightness_page_brightness_dowm = lv_image_create(ui->screen_brightness_page_mask_1);
    lv_obj_set_pos(ui->screen_brightness_page_brightness_dowm, 13, 25);
    lv_obj_set_size(ui->screen_brightness_page_brightness_dowm, 30, 30);
    lv_obj_add_flag(ui->screen_brightness_page_brightness_dowm, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->screen_brightness_page_brightness_dowm, &_brightness_down_RGB565A8_30x30);
    lv_image_set_pivot(ui->screen_brightness_page_brightness_dowm, 50,50);
    lv_image_set_rotation(ui->screen_brightness_page_brightness_dowm, 0);

    //Write style for screen_brightness_page_brightness_dowm, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->screen_brightness_page_brightness_dowm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->screen_brightness_page_brightness_dowm, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_brightness_page_status_bar
    ui->screen_brightness_page_status_bar = lv_obj_create(ui->screen_brightness_page);
    lv_obj_set_pos(ui->screen_brightness_page_status_bar, 0, 0);
    lv_obj_set_size(ui->screen_brightness_page_status_bar, 240, 64);
    lv_obj_set_scrollbar_mode(ui->screen_brightness_page_status_bar, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_brightness_page_status_bar, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_brightness_page_status_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_brightness_page_status_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_brightness_page_status_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_brightness_page_status_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_brightness_page_status_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_brightness_page_status_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_brightness_page_status_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_brightness_page_status_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_brightness_page_main_title
    ui->screen_brightness_page_main_title = lv_label_create(ui->screen_brightness_page_status_bar);
    lv_obj_set_pos(ui->screen_brightness_page_main_title, 148, 32);
    lv_obj_set_size(ui->screen_brightness_page_main_title, 80, 28);
    lv_label_set_text(ui->screen_brightness_page_main_title, "屏幕亮度");
    lv_label_set_long_mode(ui->screen_brightness_page_main_title, LV_LABEL_LONG_WRAP);

    //Write style for screen_brightness_page_main_title, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_brightness_page_main_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_brightness_page_main_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_brightness_page_main_title, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_brightness_page_main_title, &lv_font_PingFangSC_Medium_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_brightness_page_main_title, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_brightness_page_main_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_brightness_page_main_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_brightness_page_main_title, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_brightness_page_main_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_brightness_page_main_title, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_brightness_page_main_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_brightness_page_main_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_brightness_page_main_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_brightness_page_main_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_brightness_page_left_control_button
    ui->screen_brightness_page_left_control_button = lv_image_create(ui->screen_brightness_page_status_bar);
    lv_obj_set_pos(ui->screen_brightness_page_left_control_button, 16, 16);
    lv_obj_set_size(ui->screen_brightness_page_left_control_button, 40, 40);
    lv_obj_add_flag(ui->screen_brightness_page_left_control_button, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->screen_brightness_page_left_control_button, &_left_control_RGB565A8_40x40);
    lv_image_set_pivot(ui->screen_brightness_page_left_control_button, 50,50);
    lv_image_set_rotation(ui->screen_brightness_page_left_control_button, 0);

    //Write style for screen_brightness_page_left_control_button, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->screen_brightness_page_left_control_button, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->screen_brightness_page_left_control_button, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of screen_brightness_page.


    //Update current screen layout.
    lv_obj_update_layout(ui->screen_brightness_page);

    //Init events for screen.
    events_init_screen_brightness_page(ui);
}
