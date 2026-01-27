/*
 * Display Driver Header File
 *
 * This file defines the interface for initializing and controlling a display device.
 * It provides functions for hardware initialization, display control, and LVGL integration.
 */

#ifndef DISPLAY_DRIVER_H
#define DISPLAY_DRIVER_H

#include "lvgl/lvgl.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * 定义显示参数
 */
#define DISPLAY_XRES 240
#define DISPLAY_YRES 320
#define DISPLAY_BUFSIZE (DISPLAY_XRES * DISPLAY_YRES * (LV_COLOR_DEPTH / 8))
#define LVGLUI_STRING_LEN_MAX 128

typedef struct lvglui_properties
{
    char spi_device[LVGLUI_STRING_LEN_MAX];
    uint32_t spi_mode;
    uint8_t spi_bits;
    uint32_t spi_speed;
    uint16_t spi_delay;
    uint8_t spi_lsb_first;
} lvglui_properties_t;

/**
 * 初始化显示硬件
 * @return true 初始化成功，false 初始化失败
 */
bool display_init(void);
/**
 * 初始化lvgl显示
 * @return 显示设备指针，用于LVGL
 */
lv_display_t *display_lvgl_init(void);
/**
 * LVGL显示刷新回调函数
 * @param disp_drv LVGL显示驱动指针
 * @param area 刷新区域
 * @param color_p 颜色数据指针
 */
void display_lvgl_flush(lv_display_t* disp, const lv_area_t* area, uint8_t* px_map);

#ifdef __cplusplus
}
#endif

#endif /* DISPLAY_DRIVER_H */
