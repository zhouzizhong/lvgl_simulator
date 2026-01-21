/*
* Copyright 2026 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "events_init.h"
#include <stdio.h>
#include "lvgl.h"

#if LV_USE_GUIDER_SIMULATOR && LV_USE_FREEMASTER
#include "freemaster_client.h"
#endif

#include <stdlib.h>
#include <unistd.h>
#include "custom.h"

static void home_page_subpage_entry_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_SCROLL:
    {
        lv_coord_t current_scroll_x = lv_obj_get_scroll_x(guider_ui.home_page_subpage_entry);
        for (int i = 0; i < 13; i++)
        {
            // 子元素自身的宽度中心
            int child_center = lv_obj_get_x(children[i]) + 70 - current_scroll_x;

            // 子元素中心与容器中心的差值（绝对坐标差值）
            int diff = child_center - 120;
            diff = LV_ABS(diff); // 取绝对值（LVGL提供的工具函数）

            // 计算Y偏移并设置
            int y_offset = diff / 17;
            lv_obj_set_y(children[i], y_offset);
        }
        break;
    }
    case LV_EVENT_SCROLL_END:
    {
        if (lv_obj_get_scroll_x(guider_ui.home_page_subpage_entry) <= -890)
        {
            lv_obj_scroll_to_x(guider_ui.home_page_subpage_entry, 0, LV_ANIM_OFF);
        }
        else if (lv_obj_get_scroll_x(guider_ui.home_page_subpage_entry) >= 890)
        {
            lv_obj_scroll_to_x(guider_ui.home_page_subpage_entry, 0, LV_ANIM_OFF);
        }

        // 回滚聚焦
        if (lv_obj_get_scroll_x(guider_ui.home_page_subpage_entry) == -712) {
            lv_group_focus_obj(guider_ui.home_page_recently_listening_1);
        }
        else if (lv_obj_get_scroll_x(guider_ui.home_page_subpage_entry) == -534)
        {
            lv_group_focus_obj(guider_ui.home_page_my_order_1);
        }
        else if (lv_obj_get_scroll_x(guider_ui.home_page_subpage_entry) == -356)
        {
            lv_group_focus_obj(guider_ui.home_page_system_settings);
        }
        else if (lv_obj_get_scroll_x(guider_ui.home_page_subpage_entry) == -178)
        {
            lv_group_focus_obj(guider_ui.home_page_local_audio);
        }
        else if (lv_obj_get_scroll_x(guider_ui.home_page_subpage_entry) == 0)
        {
            lv_group_focus_obj(guider_ui.home_page_today_listening);
        }
        else if (lv_obj_get_scroll_x(guider_ui.home_page_subpage_entry) == 178)
        {
            lv_group_focus_obj(guider_ui.home_page_recently_listening);
        }
        else if (lv_obj_get_scroll_x(guider_ui.home_page_subpage_entry) == 356)
        {
            lv_group_focus_obj(guider_ui.home_page_my_order);
        }
        else if (lv_obj_get_scroll_x(guider_ui.home_page_subpage_entry) == 534)
        {
            lv_group_focus_obj(guider_ui.home_page_system_settings_1);
        }
        else if (lv_obj_get_scroll_x(guider_ui.home_page_subpage_entry) == 712)
        {
            lv_group_focus_obj(guider_ui.home_page_local_audio_2);
        }
        break;
    }
    default:
        break;
    }
}

static void home_page_today_listening_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.player_page, guider_ui.player_page_del, &guider_ui.home_page_del, setup_scr_player_page, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, false);
        break;
    }
    default:
        break;
    }
}

void events_init_home_page (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->home_page_subpage_entry, home_page_subpage_entry_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->home_page_today_listening, home_page_today_listening_event_handler, LV_EVENT_ALL, ui);
}


void events_init(lv_ui *ui)
{

}
