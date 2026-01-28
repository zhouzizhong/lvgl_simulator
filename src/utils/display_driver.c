/*
 * Display Driver Implementation File
 *
 * This file implements the display driver for a SPI interface TFT display.
 * It provides hardware initialization, display control, and LVGL integration.
 *
 * Note: This implementation is a template and may need to be adapted for your specific hardware.
 */
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#include "display_driver.h"
#include "lvgl/lvgl.h"
#include "log.h"

#define ALIGNED(a) __attribute__((aligned(a)))

static int fd;
static lvglui_properties_t hw_properties = {
    .spi_device = "/dev/spidev1.0",
    .spi_mode = 0,
    .spi_bits = 8,
    .spi_speed = 80000000,
    .spi_delay = 0,
    .spi_lsb_first = 1,
};
static uint8_t lvgl_buffer0[DISPLAY_BUFSIZE] ALIGNED(64);
static uint8_t lvgl_buffer1[DISPLAY_BUFSIZE] ALIGNED(64);

/**
 * 初始化GPIO
 */
static void gpio_init(void)
{
    /* TODO: 根据硬件实际情况实现GPIO初始化
     * 这是一个占位符实现，需要替换为实际的GPIO初始化代码
     */
    LOG_INFO("GPIO initialized");
}
/**
 * 设置DC引脚状态
 * @param data_mode true: 数据模式, false: 命令模式
 */
static void set_dc_pin(bool data_mode)
{
    /* TODO: 根据硬件实际情况实现DC引脚控制
     * 这是一个占位符实现，需要替换为实际的GPIO控制代码
     */
    (void)data_mode;  /* 占位符 */
    LOG_INFO("DC pin set to %s", data_mode ? "data" : "command");
}
/**
 * 设置RST引脚状态
 * @param active true: 复位, false: 正常
 */
static void set_rst_pin(bool active)
{
    /* TODO: 根据硬件实际情况实现RST引脚控制
     * 这是一个占位符实现，需要替换为实际的GPIO控制代码
     */
    (void)active;  /* 占位符 */
    LOG_INFO("RST pin set to %s", active ? "reset" : "normal");
}
static void spi_init(void)
{
    /* TODO: 根据硬件实际情况实现SPI初始化
     * 这是一个占位符实现，需要替换为实际的SPI初始化代码
     */
    LOG_INFO("SPI initialized");
}
/**
 * 初始化SPI屏幕
 */
static void spi_screen_init(void)
{
    /* TODO: 根据硬件实际情况实现SPI屏幕初始化
      * 这是一个占位符实现，需要替换为实际的SPI屏幕初始化代码
      */
    LOG_INFO("SPI screen initialized");
}
/**
 * 初始化SPI接口
 */
/**
 * 初始化显示硬件
 * @return true 初始化成功，false 初始化失败
 */
bool display_init(void)
{
    /* 初始化GPIO */
    gpio_init();
    
    /* 初始化SPI */
    spi_init();
    
    /* 初始化spi屏幕 */
    spi_screen_init();

    /* 初始化lvgl显示 */
    // display_lvgl_init();

    return true;
}
lv_display_t *display_lvgl_init(void)
{
    /* 创建显示设备 */
    lv_display_t* disp = lv_display_create(DISPLAY_XRES, DISPLAY_YRES);

    memset(lvgl_buffer0, 0, DISPLAY_BUFSIZE);
    memset(lvgl_buffer1, 0, DISPLAY_BUFSIZE);
    /* 设置显示缓冲区 */
    lv_display_set_buffers(disp, lvgl_buffer0, lvgl_buffer1, DISPLAY_BUFSIZE, LV_DISPLAY_RENDER_MODE_DIRECT);
    /* 设置刷新回调函数 */
    lv_display_set_flush_cb(disp, display_lvgl_flush);
    /* 设置分辨率 */
    lv_display_set_resolution(disp, DISPLAY_XRES, DISPLAY_YRES);

    return disp;
}
/**
 * LVGL显示刷新回调函数
 * @param disp_drv LVGL显示驱动指针
 * @param area 刷新区域
 * @param color_p 颜色数据指针
 */
void display_lvgl_flush(lv_display_t* disp, const lv_area_t* area, uint8_t* px_map)
{
    /*The most simple case (but also the slowest) to put all pixels to the screen one-by-one
     *`put_px` is just an example, it needs to be implemented by you.*/
    uint16_t* buf16 = (uint16_t*)px_map; /*Let's say it's a 16 bit (RGB565) display*/
    int32_t x, y;
    for (y = area->y1; y <= area->y2; y++) {
        for (x = area->x1; x <= area->x2; x++) {
            // put_px(x, y, *buf16);
            if (*buf16 != 0)
            {
                LOG_INFO("display_lvgl_flush: x=%d, y=%d, color=%x", x, y, *buf16);
            }
            buf16++;
        }
    }
    /* IMPORTANT!!!
     * Inform LVGL that you are ready with the flushing and buf is not used anymore*/
    lv_display_flush_ready(disp);
}
