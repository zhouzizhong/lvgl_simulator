/*
* Copyright 2026 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/


#ifndef EVENTS_INIT_H_
#define EVENTS_INIT_H_
#ifdef __cplusplus
extern "C" {
#endif

#include "gui_guider.h"

void events_init(lv_ui *ui);

void events_init_home_page(lv_ui *ui);
void events_init_player_page(lv_ui *ui);
void events_init_today_listening_page(lv_ui *ui);
void events_init_recently_listening_page(lv_ui *ui);
void events_init_my_order_page(lv_ui *ui);
void events_init_local_listening_page(lv_ui *ui);
void events_init_local_audio_page(lv_ui *ui);
void events_init_system_settings_page(lv_ui *ui);
void events_init_account_login_page(lv_ui *ui);
void events_init_account_management_page(lv_ui *ui);
void events_init_network_and_bluetooth_page(lv_ui *ui);
void events_init_screen_brightness_page(lv_ui *ui);
void events_init_device_information_page(lv_ui *ui);
void events_init_wifi_connect_page(lv_ui *ui);
void events_init_bt_connect_page(lv_ui *ui);
void events_init_pop_page(lv_ui *ui);

#ifdef __cplusplus
}
#endif
#endif /* EVENT_CB_H_ */
