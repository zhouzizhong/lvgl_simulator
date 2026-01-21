/*
* Copyright 2024 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#ifndef PAGE_MANAGER_H_
#define PAGE_MANAGER_H_
#include "custom.h"
#ifdef __cplusplus
extern "C" {
#endif
    /* 加载指定页面 */
    void page_init(lv_ui* ui);
    /* 返回上一页 */
    bool return_pre_page(lv_ui* ui);
    /* 初始化页面栈 */
    void page_stack_init(void);
    /* 检查页面栈是否为空 */
    bool page_stack_is_empty(void);
    /* 检查页面栈是否已满*/
    bool page_stack_is_full(void);
    /* 将页面ID压入栈中 */
    bool page_stack_push(int page_id);
    /* 从栈中弹出页面ID */
    bool page_stack_pop(int* page_id);
    /* 清空页面栈 */
    void page_stack_clear(void);
    /* 加载不同类型的歌曲列表页面 */
    void songlist_load(lv_ui* ui, int load_songlist, bool* old_scr_del);
    /* 更新主页内容*/
    void update_home_page_content(lv_ui* ui);
    /* 更新播放页面内容*/
    void update_player_page_content(lv_ui* ui);
    /* 更新播放页面进度条*/
    void update_player_page_progress(lv_ui* ui);
    /* 更新歌曲节拍图标 */
    void update_song_rhythm_icon(lv_ui* ui, int songlist, int current_song_index);
    /* 更新设备信息 */
    void update_device_info(lv_ui* ui);
    /* 更新账户管理页面 */
    void update_account_management_page(lv_ui* ui);
    /* pop界面显示*/
    void pop_battery_level(void);
    void pop_charge_status(void);
    void pop_general_error(void);
    void pop_wifi_disconnect(void);
    void pop_ota_update(void);
    void pop_bluetooth_disconnect(void);
    void pop_child_lock_on(void);
    void pop_child_lock_off(void);
    void pop_storage_low(void);
    void pop_bt_headset_connect(void);
    void pop_bt_headset_disconnect(void);
    /* 显示本地音乐页面*/
    void show_local_page(lv_ui* ui, int is_localsong_exists);

#ifdef __cplusplus
}
#endif
#endif /* PAGE_MANAGER_H_ */
