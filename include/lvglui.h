/**
 * @file lvglui.h
 * @brief LVGL UI 初始化和管理头文件
 */

#ifndef LVGLUI_H
#define LVGLUI_H

/*********************  INCLUDES  *********************/
#include "lvgl/lvgl.h"
#include "gui_guider.h"
#include <pthread.h>

/*********************  DEFINES  *********************/

/** MPD 音乐目录 */
#define MPD_MUSIC_DIR "D:/work/music"

/** MPD 默认主机地址 */
#define MPD_DEFAULT_HOST "127.0.0.1"

/** MPD 默认端口 */
#define MPD_DEFAULT_PORT 6600

/*********************  EXTERN VARIABLES  *********************/

/** GUI 引导界面对象 */
extern lv_ui guider_ui;

/** LVGL 互斥锁 */
extern pthread_mutex_t lvgl_mutex;

/*********************  FUNCTIONS  *********************/

/**
 * @brief LVGL UI 初始化函数
 * @param argc 命令行参数数量
 * @param argv 命令行参数数组
 * @return 初始化结果
 */
int lvglui_init(int argc, char** argv);

#endif /* LVGLUI_H */
