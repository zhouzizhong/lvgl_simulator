/*
* Copyright 2026 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#ifndef GUI_GUIDER_H
#define GUI_GUIDER_H
#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"


typedef struct
{
  
	lv_obj_t *startup_page;
	bool startup_page_del;
	lv_obj_t *startup_page_startup_page_image;
	lv_obj_t *home_page;
	bool home_page_del;
	lv_obj_t *home_page_subpage_entry;
	lv_obj_t *home_page_system_settings_1;
	lv_obj_t *home_page_system_settings_subtitle_1;
	lv_obj_t *home_page_system_settings_title_1;
	lv_obj_t *home_page_system_settings_icon_1;
	lv_obj_t *home_page_system_settings;
	lv_obj_t *home_page_system_settings_subtitle;
	lv_obj_t *home_page_system_settings_title;
	lv_obj_t *home_page_system_settings_icon;
	lv_obj_t *home_page_local_audio_2;
	lv_obj_t *home_page_local_audio_subtitle_2;
	lv_obj_t *home_page_local_audio_title_2;
	lv_obj_t *home_page_local_audio_icon_2;
	lv_obj_t *home_page_local_audio_1;
	lv_obj_t *home_page_local_audio_subtitle_1;
	lv_obj_t *home_page_local_audio_title_1;
	lv_obj_t *home_page_local_audio_icon_1;
	lv_obj_t *home_page_local_audio;
	lv_obj_t *home_page_local_audio_subtitle;
	lv_obj_t *home_page_local_audio_title;
	lv_obj_t *home_page_local_audio_icon;
	lv_obj_t *home_page_my_order_1;
	lv_obj_t *home_page_my_order_subtitle_1;
	lv_obj_t *home_page_my_order_title_1;
	lv_obj_t *home_page_my_order_icon_1;
	lv_obj_t *home_page_my_order;
	lv_obj_t *home_page_my_order_subtitle;
	lv_obj_t *home_page_my_order_title;
	lv_obj_t *home_page_my_order_icon;
	lv_obj_t *home_page_recently_listening_2;
	lv_obj_t *home_page_recently_listening_subtitle_2;
	lv_obj_t *home_page_recently_listening_title_2;
	lv_obj_t *home_page_recently_listening_icon_2;
	lv_obj_t *home_page_recently_listening_1;
	lv_obj_t *home_page_recently_listening_subtitle_1;
	lv_obj_t *home_page_recently_listening_title_1;
	lv_obj_t *home_page_recently_listening_icon_1;
	lv_obj_t *home_page_recently_listening;
	lv_obj_t *home_page_recently_listening_subtitle;
	lv_obj_t *home_page_recently_listening_title;
	lv_obj_t *home_page_recently_listening_icon;
	lv_obj_t *home_page_today_listening_2;
	lv_obj_t *home_page_today_listening_subtitle_2;
	lv_obj_t *home_page_today_listening_title_2;
	lv_obj_t *home_page_today_listening_icon_2;
	lv_obj_t *home_page_play_icon_2;
	lv_obj_t *home_page_today_listening_1;
	lv_obj_t *home_page_today_listening_subtitle_1;
	lv_obj_t *home_page_today_listening_title_1;
	lv_obj_t *home_page_today_listening_icon_1;
	lv_obj_t *home_page_play_icon_1;
	lv_obj_t *home_page_today_listening;
	lv_obj_t *home_page_today_listening_subtitle;
	lv_obj_t *home_page_today_listening_title;
	lv_obj_t *home_page_today_listening_icon;
	lv_obj_t *home_page_play_icon;
	lv_obj_t *home_page_quick_play_panel;
	lv_obj_t *home_page_play_button;
	lv_obj_t *home_page_play_button_label;
	lv_obj_t *home_page_song_title;
	lv_obj_t *home_page_mask_home_cover;
	lv_obj_t *home_page_music_cover;
	lv_obj_t *home_page_status_bar;
	lv_obj_t *home_page_main_title;
}lv_ui;

typedef void (*ui_setup_scr_t)(lv_ui * ui);

void ui_init_style(lv_style_t * style);

void ui_load_scr_animation(lv_ui *ui, lv_obj_t ** new_scr, bool new_scr_del, bool * old_scr_del, ui_setup_scr_t setup_scr,
                           lv_screen_load_anim_t anim_type, uint32_t time, uint32_t delay, bool is_clean, bool auto_del);

void ui_animation(void * var, uint32_t duration, int32_t delay, int32_t start_value, int32_t end_value, lv_anim_path_cb_t path_cb,
                  uint32_t repeat_cnt, uint32_t repeat_delay, uint32_t playback_time, uint32_t playback_delay,
                  lv_anim_exec_xcb_t exec_cb, lv_anim_start_cb_t start_cb, lv_anim_completed_cb_t ready_cb, lv_anim_deleted_cb_t deleted_cb);


void init_scr_del_flag(lv_ui *ui);

void setup_bottom_layer(void);

void setup_ui(lv_ui *ui);

void video_play(lv_ui *ui);

void init_keyboard(lv_ui *ui);

extern lv_ui guider_ui;


void setup_scr_startup_page(lv_ui *ui);
void setup_scr_home_page(lv_ui *ui);
LV_IMAGE_DECLARE(_startup_page_RGB565A8_240x320);
LV_IMAGE_DECLARE(_system_settings_icon2_RGB565A8_70x65);
LV_IMAGE_DECLARE(_local_audio_icon2_RGB565A8_70x60);
LV_IMAGE_DECLARE(_my_order_icon2_RGB565A8_70x68);
LV_IMAGE_DECLARE(_recently_listening_icon2_RGB565A8_70x70);
LV_IMAGE_DECLARE(_today_listening_icon_RGB565A8_82x70);
LV_IMAGE_DECLARE(_play_button2_RGB565A8_34x34);
LV_IMAGE_DECLARE(_play_button3_RGB565A8_40x40);
LV_IMAGE_DECLARE(_pause_button3_RGB565A8_40x40);
LV_IMAGE_DECLARE(_music_cover_example_RGB565A8_36x36);

LV_FONT_DECLARE(lv_font_PingFangSC_Regular_14)
LV_FONT_DECLARE(lv_font_montserratMedium_16)
LV_FONT_DECLARE(lv_font_FZCuYuan_M03S_18)
LV_FONT_DECLARE(lv_font_montserratMedium_12)
LV_FONT_DECLARE(lv_font_PingFangSC_Semibold_16)
LV_FONT_DECLARE(lv_font_PingFangSC_Medium_24)


#ifdef __cplusplus
}
#endif
#endif
