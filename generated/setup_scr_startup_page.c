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



void setup_scr_startup_page(lv_ui *ui)
{
    //Write codes startup_page
    ui->startup_page = lv_obj_create(NULL);
    lv_obj_set_size(ui->startup_page, 240, 320);
    lv_obj_set_scrollbar_mode(ui->startup_page, LV_SCROLLBAR_MODE_OFF);

    //Write style for startup_page, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->startup_page, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes startup_page_startup_page_image
    ui->startup_page_startup_page_image = lv_image_create(ui->startup_page);
    lv_obj_set_pos(ui->startup_page_startup_page_image, 0, 0);
    lv_obj_set_size(ui->startup_page_startup_page_image, 240, 320);
    lv_obj_add_flag(ui->startup_page_startup_page_image, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->startup_page_startup_page_image, &_startup_page_RGB565A8_240x320);
    lv_image_set_pivot(ui->startup_page_startup_page_image, 50,50);
    lv_image_set_rotation(ui->startup_page_startup_page_image, 0);

    //Write style for startup_page_startup_page_image, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->startup_page_startup_page_image, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->startup_page_startup_page_image, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes startup_page_battery
    ui->startup_page_battery = lv_obj_create(ui->startup_page);
    lv_obj_set_pos(ui->startup_page_battery, 193, 15);
    lv_obj_set_size(ui->startup_page_battery, 35, 14);
    lv_obj_set_scrollbar_mode(ui->startup_page_battery, LV_SCROLLBAR_MODE_OFF);

    //Write style for startup_page_battery, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->startup_page_battery, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->startup_page_battery, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->startup_page_battery, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->startup_page_battery, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->startup_page_battery, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->startup_page_battery, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->startup_page_battery, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->startup_page_battery, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes startup_page_battery_anode
    ui->startup_page_battery_anode = lv_obj_create(ui->startup_page_battery);
    lv_obj_set_pos(ui->startup_page_battery_anode, 30, 5);
    lv_obj_set_size(ui->startup_page_battery_anode, 3, 4);
    lv_obj_set_scrollbar_mode(ui->startup_page_battery_anode, LV_SCROLLBAR_MODE_OFF);

    //Write style for startup_page_battery_anode, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->startup_page_battery_anode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->startup_page_battery_anode, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->startup_page_battery_anode, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->startup_page_battery_anode, lv_color_hex(0x666666), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->startup_page_battery_anode, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->startup_page_battery_anode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->startup_page_battery_anode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->startup_page_battery_anode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->startup_page_battery_anode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->startup_page_battery_anode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes startup_page_battery_cont
    ui->startup_page_battery_cont = lv_obj_create(ui->startup_page_battery);
    lv_obj_set_pos(ui->startup_page_battery_cont, 0, 0);
    lv_obj_set_size(ui->startup_page_battery_cont, 30, 14);
    lv_obj_set_scrollbar_mode(ui->startup_page_battery_cont, LV_SCROLLBAR_MODE_OFF);

    //Write style for startup_page_battery_cont, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->startup_page_battery_cont, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->startup_page_battery_cont, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->startup_page_battery_cont, lv_color_hex(0x666666), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->startup_page_battery_cont, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->startup_page_battery_cont, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->startup_page_battery_cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->startup_page_battery_cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->startup_page_battery_cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->startup_page_battery_cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->startup_page_battery_cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->startup_page_battery_cont, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui->startup_page_battery_cont, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui->startup_page_battery_cont, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui->startup_page_battery_cont, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(ui->startup_page_battery_cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(ui->startup_page_battery_cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes startup_page_battery_value
    ui->startup_page_battery_value = lv_bar_create(ui->startup_page_battery);
    lv_obj_set_pos(ui->startup_page_battery_value, 2, 2);
    lv_obj_set_size(ui->startup_page_battery_value, 26, 10);
    lv_obj_set_style_anim_duration(ui->startup_page_battery_value, 1000, 0);
    lv_bar_set_mode(ui->startup_page_battery_value, LV_BAR_MODE_NORMAL);
    lv_bar_set_range(ui->startup_page_battery_value, 0, 100);
    lv_bar_set_value(ui->startup_page_battery_value, 50, LV_ANIM_OFF);

    //Write style for startup_page_battery_value, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->startup_page_battery_value, 60, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->startup_page_battery_value, lv_color_hex(0x666666), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->startup_page_battery_value, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->startup_page_battery_value, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->startup_page_battery_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for startup_page_battery_value, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->startup_page_battery_value, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->startup_page_battery_value, lv_color_hex(0x34c759), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->startup_page_battery_value, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->startup_page_battery_value, 0, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write codes startup_page_charge_logo
    ui->startup_page_charge_logo = lv_image_create(ui->startup_page_battery);
    lv_obj_set_pos(ui->startup_page_charge_logo, 8, 0);
    lv_obj_set_size(ui->startup_page_charge_logo, 14, 14);
    lv_obj_add_flag(ui->startup_page_charge_logo, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->startup_page_charge_logo, &_charge_logo_RGB565A8_14x14);
    lv_image_set_pivot(ui->startup_page_charge_logo, 50,50);
    lv_image_set_rotation(ui->startup_page_charge_logo, 0);

    //Write style for startup_page_charge_logo, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->startup_page_charge_logo, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->startup_page_charge_logo, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of startup_page.


    //Update current screen layout.
    lv_obj_update_layout(ui->startup_page);

    //Init events for screen.
    events_init_startup_page(ui);
}
