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



void setup_scr_today_listening_page(lv_ui *ui)
{
    //Write codes today_listening_page
    ui->today_listening_page = lv_obj_create(NULL);
    lv_obj_set_size(ui->today_listening_page, 240, 320);
    lv_obj_set_scrollbar_mode(ui->today_listening_page, LV_SCROLLBAR_MODE_OFF);

    //Write style for today_listening_page, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->today_listening_page, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->today_listening_page, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->today_listening_page, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes today_listening_page_list
    ui->today_listening_page_list = lv_obj_create(ui->today_listening_page);
    lv_obj_set_pos(ui->today_listening_page_list, 0, 64);
    lv_obj_set_size(ui->today_listening_page_list, 240, 256);
    lv_obj_set_scrollbar_mode(ui->today_listening_page_list, LV_SCROLLBAR_MODE_OFF);
    lv_obj_add_flag(ui->today_listening_page_list, LV_OBJ_FLAG_HIDDEN);

    //Write style for today_listening_page_list, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->today_listening_page_list, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->today_listening_page_list, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->today_listening_page_list, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->today_listening_page_list, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->today_listening_page_list, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->today_listening_page_list, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->today_listening_page_list, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->today_listening_page_list, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes today_listening_page_no_song
    ui->today_listening_page_no_song = lv_obj_create(ui->today_listening_page);
    lv_obj_set_pos(ui->today_listening_page_no_song, 0, 64);
    lv_obj_set_size(ui->today_listening_page_no_song, 240, 256);
    lv_obj_set_scrollbar_mode(ui->today_listening_page_no_song, LV_SCROLLBAR_MODE_OFF);

    //Write style for today_listening_page_no_song, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->today_listening_page_no_song, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->today_listening_page_no_song, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->today_listening_page_no_song, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->today_listening_page_no_song, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->today_listening_page_no_song, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->today_listening_page_no_song, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->today_listening_page_no_song, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->today_listening_page_no_song, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes today_listening_page_no_song_tips
    ui->today_listening_page_no_song_tips = lv_label_create(ui->today_listening_page_no_song);
    lv_obj_set_pos(ui->today_listening_page_no_song_tips, 16, 137);
    lv_obj_set_size(ui->today_listening_page_no_song_tips, 208, 22);
    lv_label_set_text(ui->today_listening_page_no_song_tips, "看完动画后，再来熏听哦");
    lv_label_set_long_mode(ui->today_listening_page_no_song_tips, LV_LABEL_LONG_WRAP);

    //Write style for today_listening_page_no_song_tips, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->today_listening_page_no_song_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->today_listening_page_no_song_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->today_listening_page_no_song_tips, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->today_listening_page_no_song_tips, &lv_font_PingFangSC_Medium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->today_listening_page_no_song_tips, 230, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->today_listening_page_no_song_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->today_listening_page_no_song_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->today_listening_page_no_song_tips, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->today_listening_page_no_song_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->today_listening_page_no_song_tips, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->today_listening_page_no_song_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->today_listening_page_no_song_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->today_listening_page_no_song_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->today_listening_page_no_song_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes today_listening_page_no_song_logo
    ui->today_listening_page_no_song_logo = lv_image_create(ui->today_listening_page_no_song);
    lv_obj_set_pos(ui->today_listening_page_no_song_logo, 79, 55);
    lv_obj_set_size(ui->today_listening_page_no_song_logo, 81, 62);
    lv_obj_add_flag(ui->today_listening_page_no_song_logo, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->today_listening_page_no_song_logo, &_no_songs_RGB565A8_81x62);
    lv_image_set_pivot(ui->today_listening_page_no_song_logo, 50,50);
    lv_image_set_rotation(ui->today_listening_page_no_song_logo, 0);

    //Write style for today_listening_page_no_song_logo, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->today_listening_page_no_song_logo, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->today_listening_page_no_song_logo, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes today_listening_page_status_bar
    ui->today_listening_page_status_bar = lv_obj_create(ui->today_listening_page);
    lv_obj_set_pos(ui->today_listening_page_status_bar, 0, 0);
    lv_obj_set_size(ui->today_listening_page_status_bar, 240, 64);
    lv_obj_set_scrollbar_mode(ui->today_listening_page_status_bar, LV_SCROLLBAR_MODE_OFF);

    //Write style for today_listening_page_status_bar, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->today_listening_page_status_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->today_listening_page_status_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->today_listening_page_status_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->today_listening_page_status_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->today_listening_page_status_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->today_listening_page_status_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->today_listening_page_status_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->today_listening_page_status_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes today_listening_page_main_title
    ui->today_listening_page_main_title = lv_label_create(ui->today_listening_page_status_bar);
    lv_obj_set_pos(ui->today_listening_page_main_title, 148, 32);
    lv_obj_set_size(ui->today_listening_page_main_title, 80, 28);
    lv_label_set_text(ui->today_listening_page_main_title, "今日熏听");
    lv_label_set_long_mode(ui->today_listening_page_main_title, LV_LABEL_LONG_WRAP);

    //Write style for today_listening_page_main_title, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->today_listening_page_main_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->today_listening_page_main_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->today_listening_page_main_title, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->today_listening_page_main_title, &lv_font_PingFangSC_Medium_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->today_listening_page_main_title, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->today_listening_page_main_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->today_listening_page_main_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->today_listening_page_main_title, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->today_listening_page_main_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->today_listening_page_main_title, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->today_listening_page_main_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->today_listening_page_main_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->today_listening_page_main_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->today_listening_page_main_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes today_listening_page_left_control_button
    ui->today_listening_page_left_control_button = lv_image_create(ui->today_listening_page_status_bar);
    lv_obj_set_pos(ui->today_listening_page_left_control_button, 16, 16);
    lv_obj_set_size(ui->today_listening_page_left_control_button, 40, 40);
    lv_obj_add_flag(ui->today_listening_page_left_control_button, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->today_listening_page_left_control_button, &_left_control_RGB565A8_40x40);
    lv_image_set_pivot(ui->today_listening_page_left_control_button, 50,50);
    lv_image_set_rotation(ui->today_listening_page_left_control_button, 0);

    //Write style for today_listening_page_left_control_button, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->today_listening_page_left_control_button, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->today_listening_page_left_control_button, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of today_listening_page.


    //Update current screen layout.
    lv_obj_update_layout(ui->today_listening_page);

    //Init events for screen.
    events_init_today_listening_page(ui);
}
