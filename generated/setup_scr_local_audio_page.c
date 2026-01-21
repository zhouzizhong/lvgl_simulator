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



void setup_scr_local_audio_page(lv_ui *ui)
{
    //Write codes local_audio_page
    ui->local_audio_page = lv_obj_create(NULL);
    lv_obj_set_size(ui->local_audio_page, 240, 320);
    lv_obj_set_scrollbar_mode(ui->local_audio_page, LV_SCROLLBAR_MODE_OFF);

    //Write style for local_audio_page, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->local_audio_page, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->local_audio_page, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->local_audio_page, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes local_audio_page_subpage_entry
    ui->local_audio_page_subpage_entry = lv_obj_create(ui->local_audio_page);
    lv_obj_set_pos(ui->local_audio_page_subpage_entry, 0, 64);
    lv_obj_set_size(ui->local_audio_page_subpage_entry, 240, 256);
    lv_obj_set_scrollbar_mode(ui->local_audio_page_subpage_entry, LV_SCROLLBAR_MODE_OFF);

    //Write style for local_audio_page_subpage_entry, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->local_audio_page_subpage_entry, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->local_audio_page_subpage_entry, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->local_audio_page_subpage_entry, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->local_audio_page_subpage_entry, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->local_audio_page_subpage_entry, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->local_audio_page_subpage_entry, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->local_audio_page_subpage_entry, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->local_audio_page_subpage_entry, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes local_audio_page_local_audio_album_1
    ui->local_audio_page_local_audio_album_1 = lv_obj_create(ui->local_audio_page_subpage_entry);
    lv_obj_set_pos(ui->local_audio_page_local_audio_album_1, 16, 10);
    lv_obj_set_size(ui->local_audio_page_local_audio_album_1, 208, 58);
    lv_obj_set_scrollbar_mode(ui->local_audio_page_local_audio_album_1, LV_SCROLLBAR_MODE_OFF);

    //Write style for local_audio_page_local_audio_album_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->local_audio_page_local_audio_album_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->local_audio_page_local_audio_album_1, 14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->local_audio_page_local_audio_album_1, 51, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->local_audio_page_local_audio_album_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->local_audio_page_local_audio_album_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->local_audio_page_local_audio_album_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->local_audio_page_local_audio_album_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->local_audio_page_local_audio_album_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->local_audio_page_local_audio_album_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->local_audio_page_local_audio_album_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes local_audio_page_songs_num_1
    ui->local_audio_page_songs_num_1 = lv_label_create(ui->local_audio_page_local_audio_album_1);
    lv_obj_set_pos(ui->local_audio_page_songs_num_1, 158, 18);
    lv_obj_set_size(ui->local_audio_page_songs_num_1, 40, 20);
    lv_label_set_text(ui->local_audio_page_songs_num_1, "12首");
    lv_label_set_long_mode(ui->local_audio_page_songs_num_1, LV_LABEL_LONG_WRAP);

    //Write style for local_audio_page_songs_num_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->local_audio_page_songs_num_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->local_audio_page_songs_num_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->local_audio_page_songs_num_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->local_audio_page_songs_num_1, &lv_font_PingFangSC_Regular_14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->local_audio_page_songs_num_1, 206, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->local_audio_page_songs_num_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->local_audio_page_songs_num_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->local_audio_page_songs_num_1, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->local_audio_page_songs_num_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->local_audio_page_songs_num_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->local_audio_page_songs_num_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->local_audio_page_songs_num_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->local_audio_page_songs_num_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->local_audio_page_songs_num_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes local_audio_page_album_title_1
    ui->local_audio_page_album_title_1 = lv_label_create(ui->local_audio_page_local_audio_album_1);
    lv_obj_set_pos(ui->local_audio_page_album_title_1, 45, 17);
    lv_obj_set_size(ui->local_audio_page_album_title_1, 120, 20);
    lv_label_set_text(ui->local_audio_page_album_title_1, "叫早儿歌");
    lv_label_set_long_mode(ui->local_audio_page_album_title_1, LV_LABEL_LONG_WRAP);

    //Write style for local_audio_page_album_title_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->local_audio_page_album_title_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->local_audio_page_album_title_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->local_audio_page_album_title_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->local_audio_page_album_title_1, &lv_font_PingFangSC_Medium_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->local_audio_page_album_title_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->local_audio_page_album_title_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->local_audio_page_album_title_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->local_audio_page_album_title_1, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->local_audio_page_album_title_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->local_audio_page_album_title_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->local_audio_page_album_title_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->local_audio_page_album_title_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->local_audio_page_album_title_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->local_audio_page_album_title_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes local_audio_page_local_audio_album_icon_1
    ui->local_audio_page_local_audio_album_icon_1 = lv_image_create(ui->local_audio_page_local_audio_album_1);
    lv_obj_set_pos(ui->local_audio_page_local_audio_album_icon_1, 12, 14);
    lv_obj_set_size(ui->local_audio_page_local_audio_album_icon_1, 30, 30);
    lv_obj_add_flag(ui->local_audio_page_local_audio_album_icon_1, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->local_audio_page_local_audio_album_icon_1, &_local_audio_album_icon2_RGB565A8_30x30);
    lv_image_set_pivot(ui->local_audio_page_local_audio_album_icon_1, 50,50);
    lv_image_set_rotation(ui->local_audio_page_local_audio_album_icon_1, 0);

    //Write style for local_audio_page_local_audio_album_icon_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->local_audio_page_local_audio_album_icon_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->local_audio_page_local_audio_album_icon_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes local_audio_page_mask
    ui->local_audio_page_mask = lv_obj_create(ui->local_audio_page);
    lv_obj_set_pos(ui->local_audio_page_mask, 16, 113);
    lv_obj_set_size(ui->local_audio_page_mask, 208, 190);
    lv_obj_set_scrollbar_mode(ui->local_audio_page_mask, LV_SCROLLBAR_MODE_OFF);
    lv_obj_add_flag(ui->local_audio_page_mask, LV_OBJ_FLAG_HIDDEN);

    //Write style for local_audio_page_mask, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->local_audio_page_mask, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->local_audio_page_mask, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->local_audio_page_mask, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->local_audio_page_mask, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->local_audio_page_mask, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->local_audio_page_mask, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->local_audio_page_mask, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->local_audio_page_mask, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes local_audio_page_tips_icon
    ui->local_audio_page_tips_icon = lv_image_create(ui->local_audio_page_mask);
    lv_obj_set_pos(ui->local_audio_page_tips_icon, 82, 140);
    lv_obj_set_size(ui->local_audio_page_tips_icon, 43, 41);
    lv_obj_add_flag(ui->local_audio_page_tips_icon, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->local_audio_page_tips_icon, &_local_audio_tips_RGB565A8_43x41);
    lv_image_set_pivot(ui->local_audio_page_tips_icon, 50,50);
    lv_image_set_rotation(ui->local_audio_page_tips_icon, 0);

    //Write style for local_audio_page_tips_icon, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->local_audio_page_tips_icon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->local_audio_page_tips_icon, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes local_audio_page_tips_subtitle
    ui->local_audio_page_tips_subtitle = lv_label_create(ui->local_audio_page_mask);
    lv_obj_set_pos(ui->local_audio_page_tips_subtitle, 13, 48);
    lv_obj_set_size(ui->local_audio_page_tips_subtitle, 184, 80);
    lv_label_set_text(ui->local_audio_page_tips_subtitle, "成功连接电脑后，在“优趣视听精灵”下新建文件夹并命名，然后把歌曲mp3文件复制到文件夹下即可");
    lv_label_set_long_mode(ui->local_audio_page_tips_subtitle, LV_LABEL_LONG_WRAP);

    //Write style for local_audio_page_tips_subtitle, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->local_audio_page_tips_subtitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->local_audio_page_tips_subtitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->local_audio_page_tips_subtitle, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->local_audio_page_tips_subtitle, &lv_font_PingFangSC_Regular_14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->local_audio_page_tips_subtitle, 160, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->local_audio_page_tips_subtitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->local_audio_page_tips_subtitle, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->local_audio_page_tips_subtitle, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->local_audio_page_tips_subtitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->local_audio_page_tips_subtitle, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->local_audio_page_tips_subtitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->local_audio_page_tips_subtitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->local_audio_page_tips_subtitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->local_audio_page_tips_subtitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes local_audio_page_tips_title
    ui->local_audio_page_tips_title = lv_label_create(ui->local_audio_page_mask);
    lv_obj_set_pos(ui->local_audio_page_tips_title, 23, 15);
    lv_obj_set_size(ui->local_audio_page_tips_title, 162, 25);
    lv_label_set_text(ui->local_audio_page_tips_title, "通过数据线连接电脑");
    lv_label_set_long_mode(ui->local_audio_page_tips_title, LV_LABEL_LONG_WRAP);

    //Write style for local_audio_page_tips_title, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->local_audio_page_tips_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->local_audio_page_tips_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->local_audio_page_tips_title, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->local_audio_page_tips_title, &lv_font_PingFangSC_Semibold_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->local_audio_page_tips_title, 230, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->local_audio_page_tips_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->local_audio_page_tips_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->local_audio_page_tips_title, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->local_audio_page_tips_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->local_audio_page_tips_title, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->local_audio_page_tips_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->local_audio_page_tips_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->local_audio_page_tips_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->local_audio_page_tips_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes local_audio_page_tips
    ui->local_audio_page_tips = lv_label_create(ui->local_audio_page);
    lv_obj_set_pos(ui->local_audio_page_tips, 66, 76);
    lv_obj_set_size(ui->local_audio_page_tips, 108, 25);
    lv_obj_add_flag(ui->local_audio_page_tips, LV_OBJ_FLAG_HIDDEN);
    lv_label_set_text(ui->local_audio_page_tips, "创建音频合辑");
    lv_label_set_long_mode(ui->local_audio_page_tips, LV_LABEL_LONG_WRAP);

    //Write style for local_audio_page_tips, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->local_audio_page_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->local_audio_page_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->local_audio_page_tips, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->local_audio_page_tips, &lv_font_PingFangSC_Semibold_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->local_audio_page_tips, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->local_audio_page_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->local_audio_page_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->local_audio_page_tips, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->local_audio_page_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->local_audio_page_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->local_audio_page_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->local_audio_page_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->local_audio_page_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->local_audio_page_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes local_audio_page_status_bar
    ui->local_audio_page_status_bar = lv_obj_create(ui->local_audio_page);
    lv_obj_set_pos(ui->local_audio_page_status_bar, 0, 0);
    lv_obj_set_size(ui->local_audio_page_status_bar, 240, 64);
    lv_obj_set_scrollbar_mode(ui->local_audio_page_status_bar, LV_SCROLLBAR_MODE_OFF);

    //Write style for local_audio_page_status_bar, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->local_audio_page_status_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->local_audio_page_status_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->local_audio_page_status_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->local_audio_page_status_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->local_audio_page_status_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->local_audio_page_status_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->local_audio_page_status_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->local_audio_page_status_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes local_audio_page_main_title
    ui->local_audio_page_main_title = lv_label_create(ui->local_audio_page_status_bar);
    lv_obj_set_pos(ui->local_audio_page_main_title, 148, 32);
    lv_obj_set_size(ui->local_audio_page_main_title, 80, 28);
    lv_label_set_text(ui->local_audio_page_main_title, "本地音频");
    lv_label_set_long_mode(ui->local_audio_page_main_title, LV_LABEL_LONG_WRAP);

    //Write style for local_audio_page_main_title, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->local_audio_page_main_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->local_audio_page_main_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->local_audio_page_main_title, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->local_audio_page_main_title, &lv_font_PingFangSC_Medium_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->local_audio_page_main_title, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->local_audio_page_main_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->local_audio_page_main_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->local_audio_page_main_title, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->local_audio_page_main_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->local_audio_page_main_title, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->local_audio_page_main_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->local_audio_page_main_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->local_audio_page_main_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->local_audio_page_main_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes local_audio_page_left_control_button
    ui->local_audio_page_left_control_button = lv_image_create(ui->local_audio_page_status_bar);
    lv_obj_set_pos(ui->local_audio_page_left_control_button, 16, 16);
    lv_obj_set_size(ui->local_audio_page_left_control_button, 40, 40);
    lv_obj_add_flag(ui->local_audio_page_left_control_button, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->local_audio_page_left_control_button, &_left_control_RGB565A8_40x40);
    lv_image_set_pivot(ui->local_audio_page_left_control_button, 50,50);
    lv_image_set_rotation(ui->local_audio_page_left_control_button, 0);

    //Write style for local_audio_page_left_control_button, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->local_audio_page_left_control_button, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->local_audio_page_left_control_button, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of local_audio_page.


    //Update current screen layout.
    lv_obj_update_layout(ui->local_audio_page);

}
