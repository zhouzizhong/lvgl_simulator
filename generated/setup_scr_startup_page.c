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

    //The custom code of startup_page.


    //Update current screen layout.
    lv_obj_update_layout(ui->startup_page);

}
