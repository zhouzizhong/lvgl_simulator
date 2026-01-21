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
	lv_obj_t *startup_page_battery;
	lv_obj_t *startup_page_battery_anode;
	lv_obj_t *startup_page_battery_cont;
	lv_obj_t *startup_page_battery_value;
	lv_obj_t *startup_page_charge_logo;
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
	lv_obj_t *player_page;
	bool player_page_del;
	lv_obj_t *player_page_background;
	lv_obj_t *player_page_mask;
	lv_obj_t *player_page_music_progress_bar;
	lv_obj_t *player_page_ic_next;
	lv_obj_t *player_page_ic_pre;
	lv_obj_t *player_page_play_button;
	lv_obj_t *player_page_play_button_label;
	lv_obj_t *player_page_album_title;
	lv_obj_t *player_page_song_title;
	lv_obj_t *player_page_music_cover;
	lv_obj_t *player_page_status_bar;
	lv_obj_t *player_page_list_button;
	lv_obj_t *player_page_left_control_button;
	lv_obj_t *today_listening_page;
	bool today_listening_page_del;
	lv_obj_t *today_listening_page_list;
	lv_obj_t *today_listening_page_no_song;
	lv_obj_t *today_listening_page_no_song_tips;
	lv_obj_t *today_listening_page_no_song_logo;
	lv_obj_t *today_listening_page_status_bar;
	lv_obj_t *today_listening_page_main_title;
	lv_obj_t *today_listening_page_left_control_button;
	lv_obj_t *recently_listening_page;
	bool recently_listening_page_del;
	lv_obj_t *recently_listening_page_list;
	lv_obj_t *recently_listening_page_no_song;
	lv_obj_t *recently_listening_page_no_song_tips;
	lv_obj_t *recently_listening_page_no_song_logo;
	lv_obj_t *recently_listening_page_status_bar;
	lv_obj_t *recently_listening_page_main_title;
	lv_obj_t *recently_listening_page_left_control_button;
	lv_obj_t *my_order_page;
	bool my_order_page_del;
	lv_obj_t *my_order_page_list;
	lv_obj_t *my_order_page_no_song;
	lv_obj_t *my_order_page_no_song_tips;
	lv_obj_t *my_order_page_no_song_logo;
	lv_obj_t *my_order_page_status_bar;
	lv_obj_t *my_order_page_main_title;
	lv_obj_t *my_order_page_left_control_button;
	lv_obj_t *local_listening_page;
	bool local_listening_page_del;
	lv_obj_t *local_listening_page_list;
	lv_obj_t *local_listening_page_status_bar;
	lv_obj_t *local_listening_page_main_title;
	lv_obj_t *local_listening_page_left_control_button;
	lv_obj_t *local_audio_page;
	bool local_audio_page_del;
	lv_obj_t *local_audio_page_subpage_entry;
	lv_obj_t *local_audio_page_local_audio_album_1;
	lv_obj_t *local_audio_page_songs_num_1;
	lv_obj_t *local_audio_page_album_title_1;
	lv_obj_t *local_audio_page_local_audio_album_icon_1;
	lv_obj_t *local_audio_page_mask;
	lv_obj_t *local_audio_page_tips_icon;
	lv_obj_t *local_audio_page_tips_subtitle;
	lv_obj_t *local_audio_page_tips_title;
	lv_obj_t *local_audio_page_tips;
	lv_obj_t *local_audio_page_status_bar;
	lv_obj_t *local_audio_page_main_title;
	lv_obj_t *local_audio_page_left_control_button;
	lv_obj_t *system_settings_page;
	bool system_settings_page_del;
	lv_obj_t *system_settings_page_subpage_entry;
	lv_obj_t *system_settings_page_bottom_mask;
	lv_obj_t *system_settings_page_device_information;
	lv_obj_t *system_settings_page_version_update_information;
	lv_obj_t *system_settings_page_device_information_title;
	lv_obj_t *system_settings_page_device_information_icon;
	lv_obj_t *system_settings_page_screen_brightness;
	lv_obj_t *system_settings_page_screen_brightness_title;
	lv_obj_t *system_settings_page_screen_brightness_icon;
	lv_obj_t *system_settings_page_network_and_bluetooth;
	lv_obj_t *system_settings_page_network_and_bluetooth_title;
	lv_obj_t *system_settings_page_network_and_bluetooth_icon;
	lv_obj_t *system_settings_page_account_management;
	lv_obj_t *system_settings_page_account_switching_icon;
	lv_obj_t *system_settings_page_account_management_title;
	lv_obj_t *system_settings_page_account_management_icon;
	lv_obj_t *system_settings_page_status_bar;
	lv_obj_t *system_settings_page_main_title;
	lv_obj_t *system_settings_page_left_control_button;
	lv_obj_t *account_login_page;
	bool account_login_page_del;
	lv_obj_t *account_login_page_mask;
	lv_obj_t *account_login_page_solid_color_background;
	lv_obj_t *account_login_page_account_login_qrcode;
	lv_obj_t *account_login_page_tips;
	lv_obj_t *account_login_page_status_bar;
	lv_obj_t *account_login_page_main_title;
	lv_obj_t *account_login_page_left_control_button;
	lv_obj_t *account_management_page;
	bool account_management_page_del;
	lv_obj_t *account_management_page_account_information;
	lv_obj_t *account_management_page_account_validity_period;
	lv_obj_t *account_management_page_phone_number;
	lv_obj_t *account_management_page_status_bar;
	lv_obj_t *account_management_page_main_title;
	lv_obj_t *account_management_page_left_control_button;
	lv_obj_t *account_management_page_container_3;
	lv_obj_t *account_management_page_sub_account_name_3;
	lv_obj_t *account_management_page_child_icon_3;
	lv_obj_t *account_management_page_mask_3;
	lv_obj_t *account_management_page_ic_download_done_icon_3;
	lv_obj_t *account_management_page_container_2;
	lv_obj_t *account_management_page_sub_account_name_2;
	lv_obj_t *account_management_page_child_icon_2;
	lv_obj_t *account_management_page_mask_2;
	lv_obj_t *account_management_page_ic_download_done_icon_2;
	lv_obj_t *account_management_page_container_1;
	lv_obj_t *account_management_page_sub_account_name_1;
	lv_obj_t *account_management_page_child_icon_1;
	lv_obj_t *account_management_page_mask_1;
	lv_obj_t *account_management_page_ic_download_done_icon_1;
	lv_obj_t *network_and_bluetooth_page;
	bool network_and_bluetooth_page_del;
	lv_obj_t *network_and_bluetooth_page_subpage_entry;
	lv_obj_t *network_and_bluetooth_page_bt_pair_up;
	lv_obj_t *network_and_bluetooth_page_bt_scan_code_button;
	lv_obj_t *network_and_bluetooth_page_bt_pair_up_title;
	lv_obj_t *network_and_bluetooth_page_bt_pair_up_icon;
	lv_obj_t *network_and_bluetooth_page_wifi_pair_up;
	lv_obj_t *network_and_bluetooth_page_wifi_scan_code_button;
	lv_obj_t *network_and_bluetooth_page_wifi_pair_up_title;
	lv_obj_t *network_and_bluetooth_page_wifi_pair_up_icon;
	lv_obj_t *network_and_bluetooth_page_status_bar;
	lv_obj_t *network_and_bluetooth_page_main_title;
	lv_obj_t *network_and_bluetooth_page_left_control_button;
	lv_obj_t *screen_brightness_page;
	bool screen_brightness_page_del;
	lv_obj_t *screen_brightness_page_automatic_screen_off;
	lv_obj_t *screen_brightness_page_automatic_screen_off_switch;
	lv_obj_t *screen_brightness_page_automatic_screen_off_subtitle;
	lv_obj_t *screen_brightness_page_automatic_screen_off_title;
	lv_obj_t *screen_brightness_page_brightness_adjustment;
	lv_obj_t *screen_brightness_page_brightness_bar;
	lv_obj_t *screen_brightness_page_mask_3;
	lv_obj_t *screen_brightness_page_mask_2;
	lv_obj_t *screen_brightness_page_brightness_up;
	lv_obj_t *screen_brightness_page_mask_1;
	lv_obj_t *screen_brightness_page_brightness_dowm;
	lv_obj_t *screen_brightness_page_status_bar;
	lv_obj_t *screen_brightness_page_main_title;
	lv_obj_t *screen_brightness_page_left_control_button;
	lv_obj_t *device_information_page;
	bool device_information_page_del;
	lv_obj_t *device_information_page_list;
	lv_obj_t *device_information_page_line_7;
	lv_obj_t *device_information_page_sn_code_title;
	lv_obj_t *device_information_page_sn_code;
	lv_obj_t *device_information_page_line_6;
	lv_obj_t *device_information_page_device_number_title;
	lv_obj_t *device_information_page_device_number;
	lv_obj_t *device_information_page_line_5;
	lv_obj_t *device_information_page_firmware_version_upgrade_button;
	lv_obj_t *device_information_page_firmware_version_upgrade_button_label;
	lv_obj_t *device_information_page_firmware_version_title;
	lv_obj_t *device_information_page_firmware_version;
	lv_obj_t *device_information_page_line_4;
	lv_obj_t *device_information_page_device_model_title;
	lv_obj_t *device_information_page_device_model;
	lv_obj_t *device_information_page_line_3;
	lv_obj_t *device_information_page_device_name_title;
	lv_obj_t *device_information_page_device_name;
	lv_obj_t *device_information_page_line_2;
	lv_obj_t *device_information_page_cache_file_size;
	lv_obj_t *device_information_page_sample_color_3;
	lv_obj_t *device_information_page_audio_file_size;
	lv_obj_t *device_information_page_sample_color_2;
	lv_obj_t *device_information_page_system_file_size;
	lv_obj_t *device_information_page_sample_color_1;
	lv_obj_t *device_information_page_cache_file_bar;
	lv_obj_t *device_information_page_audio_file_bar;
	lv_obj_t *device_information_page_system_file_bar;
	lv_obj_t *device_information_page_clear_cache_button;
	lv_obj_t *device_information_page_clear_cache_button_label;
	lv_obj_t *device_information_page_available_space_title;
	lv_obj_t *device_information_page_available_space;
	lv_obj_t *device_information_page_line_1;
	lv_obj_t *device_information_page_storage_space_title;
	lv_obj_t *device_information_page_storage_space;
	lv_obj_t *device_information_page_status_bar;
	lv_obj_t *device_information_page_main_title;
	lv_obj_t *device_information_page_left_control_button;
	lv_obj_t *wifi_connect_page;
	bool wifi_connect_page_del;
	lv_obj_t *wifi_connect_page_mask;
	lv_obj_t *wifi_connect_page_solid_color_background;
	lv_obj_t *wifi_connect_page_wifi_connect_qrcode;
	lv_obj_t *wifi_connect_page_tips;
	lv_obj_t *wifi_connect_page_status_bar;
	lv_obj_t *wifi_connect_page_main_title;
	lv_obj_t *wifi_connect_page_left_control_button;
	lv_obj_t *bt_connect_page;
	bool bt_connect_page_del;
	lv_obj_t *bt_connect_page_mask;
	lv_obj_t *bt_connect_page_solid_color_background;
	lv_obj_t *bt_connect_page_bt_connect_qrcode;
	lv_obj_t *bt_connect_page_tips;
	lv_obj_t *bt_connect_page_status_bar;
	lv_obj_t *bt_connect_page_main_title;
	lv_obj_t *bt_connect_page_left_control_button;
	lv_obj_t *pop_page;
	bool pop_page_del;
	lv_obj_t *pop_page_status_bar;
	lv_obj_t *pop_page_delete_control_button;
	lv_obj_t *pop_page_battery_low_pop;
	lv_obj_t *pop_page_battery_low_tips;
	lv_obj_t *pop_page_battery_low_icon;
	lv_obj_t *pop_page_charging_pop;
	lv_obj_t *pop_page_charging_tips;
	lv_obj_t *pop_page_charging_icon;
	lv_obj_t *pop_page_headset_connected_pop;
	lv_obj_t *pop_page_headset_connected_tips;
	lv_obj_t *pop_page_headset_connected_icon;
	lv_obj_t *pop_page_headset_disconnected_pop;
	lv_obj_t *pop_page_headset_disconnected_tips;
	lv_obj_t *pop_page_headset_disconnected_icon;
	lv_obj_t *pop_page_charge_full_pop;
	lv_obj_t *pop_page_charge_full_tips;
	lv_obj_t *pop_page_charge_full_icon;
	lv_obj_t *pop_page_warning_general_pop;
	lv_obj_t *pop_page_warning_general_tips;
	lv_obj_t *pop_page_warning_general_icon;
	lv_obj_t *pop_page_try_again_button;
	lv_obj_t *pop_page_try_again_button_label;
	lv_obj_t *pop_page_ota_update_pop;
	lv_obj_t *pop_page_ota_update_tips;
	lv_obj_t *pop_page_ota_update_icon;
	lv_obj_t *pop_page_update_progress_bar;
	lv_obj_t *pop_page_bluetooth_disconnected_pop;
	lv_obj_t *pop_page_bluetooth_disconnected_tips;
	lv_obj_t *pop_page_bluetooth_disconnected_icon;
	lv_obj_t *pop_page_check_bluetooth_button;
	lv_obj_t *pop_page_check_bluetooth_button_label;
	lv_obj_t *pop_page_child_lock_on_pop;
	lv_obj_t *pop_page_child_lock_on_tips;
	lv_obj_t *pop_page_child_lock_on_icon;
	lv_obj_t *pop_page_child_lock_off_pop;
	lv_obj_t *pop_page_child_lock_off_tips;
	lv_obj_t *pop_page_child_lock_off_icon;
	lv_obj_t *pop_page_storage_full_pop;
	lv_obj_t *pop_page_storage_full_tips;
	lv_obj_t *pop_page_storage_full_icon;
	lv_obj_t *pop_page_clean_button;
	lv_obj_t *pop_page_clean_button_label;
	lv_obj_t *pop_page_wifi_disconnected_pop;
	lv_obj_t *pop_page_wifi_disconnected_tips;
	lv_obj_t *pop_page_wifi_disconnected_icon;
	lv_obj_t *pop_page_check_network_button;
	lv_obj_t *pop_page_check_network_button_label;
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
void setup_scr_player_page(lv_ui *ui);
void setup_scr_today_listening_page(lv_ui *ui);
void setup_scr_recently_listening_page(lv_ui *ui);
void setup_scr_my_order_page(lv_ui *ui);
void setup_scr_local_listening_page(lv_ui *ui);
void setup_scr_local_audio_page(lv_ui *ui);
void setup_scr_system_settings_page(lv_ui *ui);
void setup_scr_account_login_page(lv_ui *ui);
void setup_scr_account_management_page(lv_ui *ui);
void setup_scr_network_and_bluetooth_page(lv_ui *ui);
void setup_scr_screen_brightness_page(lv_ui *ui);
void setup_scr_device_information_page(lv_ui *ui);
void setup_scr_wifi_connect_page(lv_ui *ui);
void setup_scr_bt_connect_page(lv_ui *ui);
void setup_scr_pop_page(lv_ui *ui);
LV_IMAGE_DECLARE(_startup_page_RGB565A8_240x320);
LV_IMAGE_DECLARE(_charge_logo_RGB565A8_14x14);
LV_IMAGE_DECLARE(_system_settings_icon2_RGB565A8_70x65);
LV_IMAGE_DECLARE(_local_audio_icon2_RGB565A8_70x60);
LV_IMAGE_DECLARE(_my_order_icon2_RGB565A8_70x68);
LV_IMAGE_DECLARE(_recently_listening_icon2_RGB565A8_70x70);
LV_IMAGE_DECLARE(_today_listening_icon_RGB565A8_82x70);
LV_IMAGE_DECLARE(_play_button2_RGB565A8_34x34);
LV_IMAGE_DECLARE(_play_button3_RGB565A8_40x40);
LV_IMAGE_DECLARE(_pause_button3_RGB565A8_40x40);
LV_IMAGE_DECLARE(_music_cover_example_RGB565A8_36x36);
LV_IMAGE_DECLARE(_music_cover_example_RGB565_320x320);
LV_IMAGE_DECLARE(_ic_next_RGB565A8_44x44);
LV_IMAGE_DECLARE(_ic_pre_RGB565A8_44x44);
LV_IMAGE_DECLARE(_ic_play_RGB565A8_60x60);
LV_IMAGE_DECLARE(_ic_pause_RGB565A8_60x60);
LV_IMAGE_DECLARE(_music_cover_example_RGB565A8_92x92);
LV_IMAGE_DECLARE(_list_button_RGB565A8_56x56);
LV_IMAGE_DECLARE(_left_control_RGB565A8_40x40);
LV_IMAGE_DECLARE(_no_songs_RGB565A8_81x62);
LV_IMAGE_DECLARE(_local_audio_album_icon2_RGB565A8_30x30);
LV_IMAGE_DECLARE(_local_audio_tips_RGB565A8_43x41);
LV_IMAGE_DECLARE(_device_information_icon_RGB565A8_30x30);
LV_IMAGE_DECLARE(_screen_brightness_icon_RGB565A8_30x30);
LV_IMAGE_DECLARE(_network_and_bluetooth_icon_RGB565A8_30x30);
LV_IMAGE_DECLARE(_account_switching_icon_RGB565A8_24x24);
LV_IMAGE_DECLARE(_account_management_icon_RGB565A8_30x30);
LV_IMAGE_DECLARE(_music_cover_example_RGB565A8_60x60);
LV_IMAGE_DECLARE(_ic_download_done_RGB565A8_36x36);
LV_IMAGE_DECLARE(_wifi_scan_code_RGB565A8_24x24);
LV_IMAGE_DECLARE(_bluetooth_RGB565A8_30x30);
LV_IMAGE_DECLARE(_wifi_RGB565A8_30x30);
LV_IMAGE_DECLARE(_brightness_up_RGB565A8_30x30);
LV_IMAGE_DECLARE(_brightness_down_RGB565A8_30x30);
LV_IMAGE_DECLARE(_delete_control_RGB565A8_56x56);
LV_IMAGE_DECLARE(_battery_low_icon_RGB565A8_79x65);
LV_IMAGE_DECLARE(_charging_icon_RGB565A8_79x70);
LV_IMAGE_DECLARE(_bluetooth_headset_connected_icon_RGB565A8_80x78);
LV_IMAGE_DECLARE(_bluetooth_headset_disconnected_icon_RGB565A8_74x77);
LV_IMAGE_DECLARE(_charge_full_icon_RGB565A8_80x70);
LV_IMAGE_DECLARE(_warning_general_icon_RGB565A8_69x81);
LV_IMAGE_DECLARE(_ota_update_icon_RGB565A8_78x78);
LV_IMAGE_DECLARE(_bluetooth_disconnected_icon_RGB565A8_79x74);
LV_IMAGE_DECLARE(_child_lock_on_icon_RGB565A8_77x70);
LV_IMAGE_DECLARE(_child_lock_off_icon_RGB565A8_76x70);
LV_IMAGE_DECLARE(_storage_full_icon_RGB565A8_76x67);
LV_IMAGE_DECLARE(_wifi_disconnected_icon_RGB565A8_84x68);

LV_FONT_DECLARE(lv_font_PingFangSC_Regular_14)
LV_FONT_DECLARE(lv_font_montserratMedium_16)
LV_FONT_DECLARE(lv_font_FZCuYuan_M03S_18)
LV_FONT_DECLARE(lv_font_montserratMedium_12)
LV_FONT_DECLARE(lv_font_PingFangSC_Semibold_16)
LV_FONT_DECLARE(lv_font_PingFangSC_Medium_24)
LV_FONT_DECLARE(lv_font_PingFangSC_Semibold_20)
LV_FONT_DECLARE(lv_font_PingFangSC_Medium_16)
LV_FONT_DECLARE(lv_font_PingFangSC_Medium_20)
LV_FONT_DECLARE(lv_font_PingFangSC_Medium_18)
LV_FONT_DECLARE(lv_font_PingFangSC_Semibold_18)
LV_FONT_DECLARE(lv_font_PingFangSC_Regular_16)


#ifdef __cplusplus
}
#endif
#endif
