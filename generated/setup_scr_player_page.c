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



void setup_scr_player_page(lv_ui *ui)
{
    //Write codes player_page
    ui->player_page = lv_obj_create(NULL);
    lv_obj_set_size(ui->player_page, 240, 320);
    lv_obj_set_scrollbar_mode(ui->player_page, LV_SCROLLBAR_MODE_OFF);

    //Write style for player_page, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->player_page, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->player_page, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->player_page, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes player_page_background
    LV_DRAW_BUF_DEFINE_STATIC(player_page_background_draw_buf, 240, 320, LV_COLOR_FORMAT_ARGB8888);
    LV_DRAW_BUF_INIT_STATIC(player_page_background_draw_buf);
    ui->player_page_background = lv_canvas_create(ui->player_page);
    lv_obj_set_pos(ui->player_page_background, 0, 0);
    lv_obj_set_size(ui->player_page_background, 240, 320);
    lv_obj_set_scrollbar_mode(ui->player_page_background, LV_SCROLLBAR_MODE_OFF);
    lv_canvas_set_draw_buf(ui->player_page_background, &player_page_background_draw_buf);
    lv_canvas_fill_bg(ui->player_page_background, lv_color_hex(0xffffff), 128);

    lv_layer_t layer_player_page_background;
    lv_canvas_init_layer(ui->player_page_background, &layer_player_page_background);
    //Canvas draw image
    lv_draw_image_dsc_t player_page_background_image_dsc_0;
    lv_draw_image_dsc_init(&player_page_background_image_dsc_0);
    player_page_background_image_dsc_0.src = &_music_cover_example_RGB565_320x320;
    lv_area_t player_page_background_coords_image_0 = {-40, 0, 240, 320};
    lv_draw_image(&layer_player_page_background, &player_page_background_image_dsc_0, &player_page_background_coords_image_0);

    lv_canvas_finish_layer(ui->player_page_background, &layer_player_page_background);

    //Write codes player_page_mask
    ui->player_page_mask = lv_obj_create(ui->player_page);
    lv_obj_set_pos(ui->player_page_mask, 0, 0);
    lv_obj_set_size(ui->player_page_mask, 240, 320);
    lv_obj_set_scrollbar_mode(ui->player_page_mask, LV_SCROLLBAR_MODE_OFF);

    //Write style for player_page_mask, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->player_page_mask, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->player_page_mask, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->player_page_mask, 205, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->player_page_mask, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->player_page_mask, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->player_page_mask, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->player_page_mask, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->player_page_mask, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->player_page_mask, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->player_page_mask, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes player_page_music_progress_bar
    ui->player_page_music_progress_bar = lv_bar_create(ui->player_page);
    lv_obj_set_pos(ui->player_page_music_progress_bar, 30, 294);
    lv_obj_set_size(ui->player_page_music_progress_bar, 180, 4);
    lv_obj_set_style_anim_duration(ui->player_page_music_progress_bar, 1000, 0);
    lv_bar_set_mode(ui->player_page_music_progress_bar, LV_BAR_MODE_NORMAL);
    lv_bar_set_range(ui->player_page_music_progress_bar, 0, 180);
    lv_bar_set_value(ui->player_page_music_progress_bar, 60, LV_ANIM_OFF);

    //Write style for player_page_music_progress_bar, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->player_page_music_progress_bar, 33, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->player_page_music_progress_bar, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->player_page_music_progress_bar, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->player_page_music_progress_bar, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->player_page_music_progress_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for player_page_music_progress_bar, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->player_page_music_progress_bar, 130, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->player_page_music_progress_bar, lv_color_hex(0xffffff), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->player_page_music_progress_bar, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->player_page_music_progress_bar, 0, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write codes player_page_ic_next
    ui->player_page_ic_next = lv_image_create(ui->player_page);
    lv_obj_set_pos(ui->player_page_ic_next, 176, 220);
    lv_obj_set_size(ui->player_page_ic_next, 44, 44);
    lv_obj_add_flag(ui->player_page_ic_next, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->player_page_ic_next, &_ic_next_RGB565A8_44x44);
    lv_image_set_pivot(ui->player_page_ic_next, 50,50);
    lv_image_set_rotation(ui->player_page_ic_next, 0);

    //Write style for player_page_ic_next, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->player_page_ic_next, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->player_page_ic_next, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes player_page_ic_pre
    ui->player_page_ic_pre = lv_image_create(ui->player_page);
    lv_obj_set_pos(ui->player_page_ic_pre, 20, 220);
    lv_obj_set_size(ui->player_page_ic_pre, 44, 44);
    lv_obj_add_flag(ui->player_page_ic_pre, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->player_page_ic_pre, &_ic_pre_RGB565A8_44x44);
    lv_image_set_pivot(ui->player_page_ic_pre, 50,50);
    lv_image_set_rotation(ui->player_page_ic_pre, 0);

    //Write style for player_page_ic_pre, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->player_page_ic_pre, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->player_page_ic_pre, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes player_page_play_button
    ui->player_page_play_button = lv_imagebutton_create(ui->player_page);
    lv_obj_set_pos(ui->player_page_play_button, 90, 212);
    lv_obj_set_size(ui->player_page_play_button, 60, 60);
    lv_obj_add_flag(ui->player_page_play_button, LV_OBJ_FLAG_CHECKABLE);
    lv_imagebutton_set_src(ui->player_page_play_button, LV_IMAGEBUTTON_STATE_RELEASED, &_ic_play_RGB565A8_60x60, NULL, NULL);
    lv_imagebutton_set_src(ui->player_page_play_button, LV_IMAGEBUTTON_STATE_PRESSED, &_ic_pause_RGB565A8_60x60, NULL, NULL);
    lv_imagebutton_set_src(ui->player_page_play_button, LV_IMAGEBUTTON_STATE_CHECKED_RELEASED, &_ic_pause_RGB565A8_60x60, NULL, NULL);
    lv_imagebutton_set_src(ui->player_page_play_button, LV_IMAGEBUTTON_STATE_CHECKED_PRESSED, &_ic_play_RGB565A8_60x60, NULL, NULL);
    ui->player_page_play_button_label = lv_label_create(ui->player_page_play_button);
    lv_label_set_text(ui->player_page_play_button_label, "");
    lv_label_set_long_mode(ui->player_page_play_button_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->player_page_play_button_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->player_page_play_button, 0, LV_STATE_DEFAULT);

    //Write style for player_page_play_button, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->player_page_play_button, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->player_page_play_button, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->player_page_play_button, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->player_page_play_button, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->player_page_play_button, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for player_page_play_button, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_image_recolor_opa(ui->player_page_play_button, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_image_opa(ui->player_page_play_button, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->player_page_play_button, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->player_page_play_button, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->player_page_play_button, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->player_page_play_button, 0, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for player_page_play_button, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_image_recolor_opa(ui->player_page_play_button, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_image_opa(ui->player_page_play_button, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->player_page_play_button, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->player_page_play_button, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->player_page_play_button, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->player_page_play_button, 0, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for player_page_play_button, Part: LV_PART_MAIN, State: LV_IMAGEBUTTON_STATE_RELEASED.
    lv_obj_set_style_image_recolor_opa(ui->player_page_play_button, 0, LV_PART_MAIN|LV_IMAGEBUTTON_STATE_RELEASED);
    lv_obj_set_style_image_opa(ui->player_page_play_button, 255, LV_PART_MAIN|LV_IMAGEBUTTON_STATE_RELEASED);

    //Write codes player_page_album_title
    ui->player_page_album_title = lv_label_create(ui->player_page);
    lv_obj_set_pos(ui->player_page_album_title, 16, 178);
    lv_obj_set_size(ui->player_page_album_title, 208, 20);
    lv_label_set_text(ui->player_page_album_title, "SSS英文儿歌全集");
    lv_label_set_long_mode(ui->player_page_album_title, LV_LABEL_LONG_SCROLL_CIRCULAR);

    //Write style for player_page_album_title, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->player_page_album_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->player_page_album_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->player_page_album_title, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->player_page_album_title, &lv_font_PingFangSC_Regular_14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->player_page_album_title, 179, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->player_page_album_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->player_page_album_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->player_page_album_title, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->player_page_album_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->player_page_album_title, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->player_page_album_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->player_page_album_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->player_page_album_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->player_page_album_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes player_page_song_title
    ui->player_page_song_title = lv_label_create(ui->player_page);
    lv_obj_set_pos(ui->player_page_song_title, 16, 149);
    lv_obj_set_size(ui->player_page_song_title, 208, 27);
    lv_label_set_text(ui->player_page_song_title, "Lots of Shallots isaa Shallots");
    lv_label_set_long_mode(ui->player_page_song_title, LV_LABEL_LONG_SCROLL_CIRCULAR);

    //Write style for player_page_song_title, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->player_page_song_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->player_page_song_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->player_page_song_title, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->player_page_song_title, &lv_font_PingFangSC_Semibold_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->player_page_song_title, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->player_page_song_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->player_page_song_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->player_page_song_title, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->player_page_song_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->player_page_song_title, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->player_page_song_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->player_page_song_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->player_page_song_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->player_page_song_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes player_page_mask_music_cover
    ui->player_page_mask_music_cover = lv_obj_create(ui->player_page);
    lv_obj_set_pos(ui->player_page_mask_music_cover, 74, 49);
    lv_obj_set_size(ui->player_page_mask_music_cover, 92, 92);
    lv_obj_set_scrollbar_mode(ui->player_page_mask_music_cover, LV_SCROLLBAR_MODE_OFF);

    //Write style for player_page_mask_music_cover, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->player_page_mask_music_cover, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->player_page_mask_music_cover, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->player_page_mask_music_cover, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->player_page_mask_music_cover, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->player_page_mask_music_cover, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->player_page_mask_music_cover, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->player_page_mask_music_cover, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->player_page_mask_music_cover, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes player_page_music_cover
    ui->player_page_music_cover = lv_image_create(ui->player_page_mask_music_cover);
    lv_obj_set_pos(ui->player_page_music_cover, -2, -2);
    lv_obj_set_size(ui->player_page_music_cover, 96, 96);
    lv_obj_add_flag(ui->player_page_music_cover, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->player_page_music_cover, &_music_cover_example_RGB565A8_96x96);
    lv_image_set_pivot(ui->player_page_music_cover, 50,50);
    lv_image_set_rotation(ui->player_page_music_cover, 0);

    //Write style for player_page_music_cover, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->player_page_music_cover, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->player_page_music_cover, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes player_page_status_bar
    ui->player_page_status_bar = lv_obj_create(ui->player_page);
    lv_obj_set_pos(ui->player_page_status_bar, 0, 0);
    lv_obj_set_size(ui->player_page_status_bar, 240, 64);
    lv_obj_set_scrollbar_mode(ui->player_page_status_bar, LV_SCROLLBAR_MODE_OFF);

    //Write style for player_page_status_bar, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->player_page_status_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->player_page_status_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->player_page_status_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->player_page_status_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->player_page_status_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->player_page_status_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->player_page_status_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->player_page_status_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes player_page_list_button
    ui->player_page_list_button = lv_image_create(ui->player_page_status_bar);
    lv_obj_set_pos(ui->player_page_list_button, 168, 8);
    lv_obj_set_size(ui->player_page_list_button, 56, 56);
    lv_obj_add_flag(ui->player_page_list_button, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->player_page_list_button, &_list_button_RGB565A8_56x56);
    lv_image_set_pivot(ui->player_page_list_button, 50,50);
    lv_image_set_rotation(ui->player_page_list_button, 0);

    //Write style for player_page_list_button, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->player_page_list_button, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->player_page_list_button, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes player_page_left_control_button
    ui->player_page_left_control_button = lv_image_create(ui->player_page_status_bar);
    lv_obj_set_pos(ui->player_page_left_control_button, 16, 16);
    lv_obj_set_size(ui->player_page_left_control_button, 40, 40);
    lv_obj_add_flag(ui->player_page_left_control_button, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->player_page_left_control_button, &_left_control_RGB565A8_40x40);
    lv_image_set_pivot(ui->player_page_left_control_button, 50,50);
    lv_image_set_rotation(ui->player_page_left_control_button, 0);

    //Write style for player_page_left_control_button, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->player_page_left_control_button, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->player_page_left_control_button, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of player_page.
    lv_obj_set_style_text_font(ui->player_page_album_title, &lv_font_MyPingFangSC_Regular_14, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->player_page_song_title, &lv_font_MyPingFangSC_Semibold_20, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_image_set_inner_align(ui->player_page_music_cover, LV_IMAGE_ALIGN_STRETCH);
    lv_obj_set_style_clip_corner(ui->player_page_mask_music_cover, true, 0);

    //Update current screen layout.
    lv_obj_update_layout(ui->player_page);

    //Init events for screen.
    events_init_player_page(ui);
}
