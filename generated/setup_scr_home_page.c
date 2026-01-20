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



void setup_scr_home_page(lv_ui *ui)
{
    //Write codes home_page
    ui->home_page = lv_obj_create(NULL);
    lv_obj_set_size(ui->home_page, 240, 320);
    lv_obj_set_scrollbar_mode(ui->home_page, LV_SCROLLBAR_MODE_OFF);

    //Write style for home_page, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->home_page, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->home_page, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->home_page, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes home_page_subpage_entry
    ui->home_page_subpage_entry = lv_obj_create(ui->home_page);
    lv_obj_set_pos(ui->home_page_subpage_entry, 0, 64);
    lv_obj_set_size(ui->home_page_subpage_entry, 240, 256);
    lv_obj_set_scrollbar_mode(ui->home_page_subpage_entry, LV_SCROLLBAR_MODE_OFF);

    //Write style for home_page_subpage_entry, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->home_page_subpage_entry, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->home_page_subpage_entry, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->home_page_subpage_entry, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->home_page_subpage_entry, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->home_page_subpage_entry, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->home_page_subpage_entry, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->home_page_subpage_entry, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->home_page_subpage_entry, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes home_page_today_listening
    ui->home_page_today_listening = lv_obj_create(ui->home_page_subpage_entry);
    lv_obj_set_pos(ui->home_page_today_listening, 41, 0);
    lv_obj_set_size(ui->home_page_today_listening, 158, 168);
    lv_obj_set_scrollbar_mode(ui->home_page_today_listening, LV_SCROLLBAR_MODE_OFF);

    //Write style for home_page_today_listening, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->home_page_today_listening, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->home_page_today_listening, 36, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->home_page_today_listening, 28, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->home_page_today_listening, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->home_page_today_listening, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->home_page_today_listening, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->home_page_today_listening, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->home_page_today_listening, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->home_page_today_listening, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->home_page_today_listening, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes home_page_today_listening_subtitle
    ui->home_page_today_listening_subtitle = lv_label_create(ui->home_page_today_listening);
    lv_obj_set_pos(ui->home_page_today_listening_subtitle, 10, 128);
    lv_obj_set_size(ui->home_page_today_listening_subtitle, 138, 20);
    lv_label_set_text(ui->home_page_today_listening_subtitle, "完播动画智能推荐");
    lv_label_set_long_mode(ui->home_page_today_listening_subtitle, LV_LABEL_LONG_WRAP);

    //Write style for home_page_today_listening_subtitle, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->home_page_today_listening_subtitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->home_page_today_listening_subtitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->home_page_today_listening_subtitle, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->home_page_today_listening_subtitle, &lv_font_PingFangSC_Regular_14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->home_page_today_listening_subtitle, 211, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->home_page_today_listening_subtitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->home_page_today_listening_subtitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->home_page_today_listening_subtitle, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->home_page_today_listening_subtitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->home_page_today_listening_subtitle, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->home_page_today_listening_subtitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->home_page_today_listening_subtitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->home_page_today_listening_subtitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->home_page_today_listening_subtitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes home_page_today_listening_title
    ui->home_page_today_listening_title = lv_label_create(ui->home_page_today_listening);
    lv_obj_set_pos(ui->home_page_today_listening_title, 43, 103);
    lv_obj_set_size(ui->home_page_today_listening_title, 72, 22);
    lv_label_set_text(ui->home_page_today_listening_title, "今日熏听");
    lv_label_set_long_mode(ui->home_page_today_listening_title, LV_LABEL_LONG_WRAP);

    //Write style for home_page_today_listening_title, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->home_page_today_listening_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->home_page_today_listening_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->home_page_today_listening_title, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->home_page_today_listening_title, &lv_font_FZCuYuan_M03S_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->home_page_today_listening_title, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->home_page_today_listening_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->home_page_today_listening_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->home_page_today_listening_title, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->home_page_today_listening_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->home_page_today_listening_title, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->home_page_today_listening_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->home_page_today_listening_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->home_page_today_listening_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->home_page_today_listening_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes home_page_today_listening_icon
    ui->home_page_today_listening_icon = lv_image_create(ui->home_page_today_listening);
    lv_obj_set_pos(ui->home_page_today_listening_icon, 45, 24);
    lv_obj_set_size(ui->home_page_today_listening_icon, 82, 70);
    lv_obj_add_flag(ui->home_page_today_listening_icon, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->home_page_today_listening_icon, &_today_listening_icon_RGB565A8_82x70);
    lv_image_set_pivot(ui->home_page_today_listening_icon, 50,50);
    lv_image_set_rotation(ui->home_page_today_listening_icon, 0);

    //Write style for home_page_today_listening_icon, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->home_page_today_listening_icon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->home_page_today_listening_icon, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes home_page_play_icon
    ui->home_page_play_icon = lv_image_create(ui->home_page_today_listening);
    lv_obj_set_pos(ui->home_page_play_icon, 62, 41);
    lv_obj_set_size(ui->home_page_play_icon, 34, 34);
    lv_obj_add_flag(ui->home_page_play_icon, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->home_page_play_icon, &_play_button2_RGB565A8_34x34);
    lv_image_set_pivot(ui->home_page_play_icon, 50,50);
    lv_image_set_rotation(ui->home_page_play_icon, 0);

    //Write style for home_page_play_icon, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->home_page_play_icon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->home_page_play_icon, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes home_page_quick_play_panel
    ui->home_page_quick_play_panel = lv_obj_create(ui->home_page);
    lv_obj_set_pos(ui->home_page_quick_play_panel, 16, 248);
    lv_obj_set_size(ui->home_page_quick_play_panel, 208, 52);
    lv_obj_set_scrollbar_mode(ui->home_page_quick_play_panel, LV_SCROLLBAR_MODE_OFF);

    //Write style for home_page_quick_play_panel, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->home_page_quick_play_panel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->home_page_quick_play_panel, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->home_page_quick_play_panel, 26, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->home_page_quick_play_panel, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->home_page_quick_play_panel, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->home_page_quick_play_panel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->home_page_quick_play_panel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->home_page_quick_play_panel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->home_page_quick_play_panel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->home_page_quick_play_panel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes home_page_play_button
    ui->home_page_play_button = lv_imagebutton_create(ui->home_page_quick_play_panel);
    lv_obj_set_pos(ui->home_page_play_button, 159, 6);
    lv_obj_set_size(ui->home_page_play_button, 40, 40);
    lv_obj_add_flag(ui->home_page_play_button, LV_OBJ_FLAG_CHECKABLE);
    lv_imagebutton_set_src(ui->home_page_play_button, LV_IMAGEBUTTON_STATE_RELEASED, &_play_button3_RGB565A8_40x40, NULL, NULL);
    lv_imagebutton_set_src(ui->home_page_play_button, LV_IMAGEBUTTON_STATE_PRESSED, &_pause_button3_RGB565A8_40x40, NULL, NULL);
    lv_imagebutton_set_src(ui->home_page_play_button, LV_IMAGEBUTTON_STATE_CHECKED_RELEASED, &_pause_button3_RGB565A8_40x40, NULL, NULL);
    lv_imagebutton_set_src(ui->home_page_play_button, LV_IMAGEBUTTON_STATE_CHECKED_PRESSED, &_play_button3_RGB565A8_40x40, NULL, NULL);
    ui->home_page_play_button_label = lv_label_create(ui->home_page_play_button);
    lv_label_set_text(ui->home_page_play_button_label, "");
    lv_label_set_long_mode(ui->home_page_play_button_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->home_page_play_button_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->home_page_play_button, 0, LV_STATE_DEFAULT);

    //Write style for home_page_play_button, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->home_page_play_button, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->home_page_play_button, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->home_page_play_button, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->home_page_play_button, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->home_page_play_button, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for home_page_play_button, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_image_recolor_opa(ui->home_page_play_button, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_image_opa(ui->home_page_play_button, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->home_page_play_button, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->home_page_play_button, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->home_page_play_button, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->home_page_play_button, 0, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for home_page_play_button, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_image_recolor_opa(ui->home_page_play_button, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_image_opa(ui->home_page_play_button, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->home_page_play_button, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->home_page_play_button, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->home_page_play_button, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->home_page_play_button, 0, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for home_page_play_button, Part: LV_PART_MAIN, State: LV_IMAGEBUTTON_STATE_RELEASED.
    lv_obj_set_style_image_recolor_opa(ui->home_page_play_button, 0, LV_PART_MAIN|LV_IMAGEBUTTON_STATE_RELEASED);
    lv_obj_set_style_image_opa(ui->home_page_play_button, 255, LV_PART_MAIN|LV_IMAGEBUTTON_STATE_RELEASED);

    //Write codes home_page_song_title
    ui->home_page_song_title = lv_label_create(ui->home_page_quick_play_panel);
    lv_obj_set_pos(ui->home_page_song_title, 52, 15);
    lv_obj_set_size(ui->home_page_song_title, 108, 22);
    lv_label_set_text(ui->home_page_song_title, "Lots of Shallots isaa Shallots");
    lv_label_set_long_mode(ui->home_page_song_title, LV_LABEL_LONG_SCROLL_CIRCULAR);

    //Write style for home_page_song_title, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->home_page_song_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->home_page_song_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->home_page_song_title, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->home_page_song_title, &lv_font_PingFangSC_Semibold_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->home_page_song_title, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->home_page_song_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->home_page_song_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->home_page_song_title, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->home_page_song_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->home_page_song_title, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->home_page_song_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->home_page_song_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->home_page_song_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->home_page_song_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes home_page_mask_home_cover
    ui->home_page_mask_home_cover = lv_obj_create(ui->home_page_quick_play_panel);
    lv_obj_set_pos(ui->home_page_mask_home_cover, 8, 8);
    lv_obj_set_size(ui->home_page_mask_home_cover, 36, 36);
    lv_obj_set_scrollbar_mode(ui->home_page_mask_home_cover, LV_SCROLLBAR_MODE_OFF);

    //Write style for home_page_mask_home_cover, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->home_page_mask_home_cover, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->home_page_mask_home_cover, 36, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->home_page_mask_home_cover, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->home_page_mask_home_cover, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->home_page_mask_home_cover, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->home_page_mask_home_cover, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->home_page_mask_home_cover, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->home_page_mask_home_cover, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui->home_page_mask_home_cover, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui->home_page_mask_home_cover, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui->home_page_mask_home_cover, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(ui->home_page_mask_home_cover, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(ui->home_page_mask_home_cover, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes home_page_music_cover
    ui->home_page_music_cover = lv_image_create(ui->home_page_mask_home_cover);
    lv_obj_set_pos(ui->home_page_music_cover, 0, 0);
    lv_obj_set_size(ui->home_page_music_cover, 36, 36);
    lv_obj_add_flag(ui->home_page_music_cover, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui->home_page_music_cover, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->home_page_music_cover, &_music_cover_example_RGB565A8_36x36);
    lv_image_set_pivot(ui->home_page_music_cover, 50,50);
    lv_image_set_rotation(ui->home_page_music_cover, 0);

    //Write style for home_page_music_cover, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->home_page_music_cover, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->home_page_music_cover, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes home_page_status_bar
    ui->home_page_status_bar = lv_obj_create(ui->home_page);
    lv_obj_set_pos(ui->home_page_status_bar, 0, 0);
    lv_obj_set_size(ui->home_page_status_bar, 240, 64);
    lv_obj_set_scrollbar_mode(ui->home_page_status_bar, LV_SCROLLBAR_MODE_OFF);

    //Write style for home_page_status_bar, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->home_page_status_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->home_page_status_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->home_page_status_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->home_page_status_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->home_page_status_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->home_page_status_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->home_page_status_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->home_page_status_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes home_page_main_title
    ui->home_page_main_title = lv_label_create(ui->home_page_status_bar);
    lv_obj_set_pos(ui->home_page_main_title, 16, 26);
    lv_obj_set_size(ui->home_page_main_title, 48, 30);
    lv_label_set_text(ui->home_page_main_title, "首页");
    lv_label_set_long_mode(ui->home_page_main_title, LV_LABEL_LONG_WRAP);

    //Write style for home_page_main_title, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->home_page_main_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->home_page_main_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->home_page_main_title, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->home_page_main_title, &lv_font_PingFangSC_Medium_24, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->home_page_main_title, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->home_page_main_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->home_page_main_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->home_page_main_title, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->home_page_main_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->home_page_main_title, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->home_page_main_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->home_page_main_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->home_page_main_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->home_page_main_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of home_page.


    //Update current screen layout.
    lv_obj_update_layout(ui->home_page);

}
