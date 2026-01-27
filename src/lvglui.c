/**
 * @file main
 *
 */
/*********************
 *      INCLUDES
 *********************/
#include "lvglui.h"
#include "lvgl/lvgl.h"
#include "gui_guider.h"
#include "custom.h"
#include "widgets_init.h"
#include "events_init.h"
#include "display_driver.h"
#include "mpd_client.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <dirent.h>

// Supported music file formats
static const char* supported_formats[] = {".mp3", ".ogg", ".wav", ".flac", ".aac", ".mp2", ".amr"};
static const int num_formats = 7;

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC FUNCTIONS
 **********************/
static lv_display_t* sdl_hal_init(int32_t w, int32_t h);

// MPD测试函数：初始化连接并播放指定索引的歌曲
static void mpd_test_play_song(int index) {
    printf("\n=== MPD Test ===\n");
    
    // 1. Initialize MPD client
    printf("1. Initialize MPD client...\n");
    if (!mpd_client_init()) {
        printf("   Init failed\n");
        return;
    }
    printf("   Init success\n");
    
    // 2. Connect to MPD server
    printf("2. Connect to MPD server %s:%d...\n", MPD_DEFAULT_HOST, MPD_DEFAULT_PORT);
    if (!mpd_client_connect(MPD_DEFAULT_HOST, MPD_DEFAULT_PORT)) {
        printf("   Connect failed, make sure MPD server is running\n");
        mpd_client_deinit();
        return;
    }
    printf("   Connect success\n");
    
    // 3. Clear existing playlist
    printf("3. Clear existing playlist...\n");
    if (mpd_client_clear_playlist()) {
        printf("   Clear playlist success\n");
    } else {
        printf("   Clear playlist failed\n");
    }
    
    // 4. Add all songs to playlist
    printf("4. Add all songs to playlist...\n");
    if (mpd_client_add_all_songs()) {
        printf("   Add all songs success\n");
    } else {
        printf("   Add all songs failed\n");
    }
    
    // 5. Start playback at specified index
    printf("5. Start playback at index %d...\n", index);
    if (mpd_client_play_index(index)) {
        printf("   Play success\n");
    } else {
        printf("   Play failed (index may be invalid or playlist empty)\n");
    }
    
    printf("=== MPD Test Complete ===\n\n");
}

/**********************
 *  STATIC VARIABLES
 **********************/

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *      VARIABLES
 **********************/
lv_ui guider_ui;
pthread_mutex_t lvgl_mutex;

/**********************
 *  STATIC FUNCTIONS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

int lvglui_init(int argc, char** argv)
{
  int play_index = 0;  // 默认播放第一首
  
  // 解析命令行参数
  if (argc > 1) {
      play_index = atoi(argv[1]);
  }

  /*Initialize LVGL*/
  lv_init();
  /*Initialize the display, and the input devices*/
  sdl_hal_init(240, 320);
  /*Setup the UI*/
  setup_ui(&guider_ui);
  custom_init(&guider_ui);
  events_init(&guider_ui);

  /* MPD测试：初始化连接并播放指定索引的歌曲 */
  mpd_test_play_song(play_index);

  /* 初始化LVGL主循环线程锁 */
  pthread_mutex_init(&lvgl_mutex, NULL);

  while (1) {
    /* Periodically call the lv_timer_handler. */
    pthread_mutex_lock(&lvgl_mutex);
    lv_timer_handler();
    pthread_mutex_unlock(&lvgl_mutex);
  }

demo_end:
  lv_deinit();
  return 0;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

/**
 * Initialize the Hardware Abstraction Layer (HAL) for the LVGL graphics
 * library
 */
static lv_display_t* sdl_hal_init(int32_t w, int32_t h)
{
  /* 初始化显示硬件 */
  display_init();

  lv_group_set_default(lv_group_create());

  lv_display_t * disp = lv_sdl_window_create(w, h);

  // 鼠标输入设备
  lv_indev_t* mouse = lv_sdl_mouse_create();
  lv_indev_set_group(mouse, lv_group_get_default());
  lv_indev_set_display(mouse, disp);
  lv_display_set_default(disp);

  // // 滚轮输入设备
  // lv_indev_t* mousewheel = lv_sdl_mousewheel_create();
  // lv_indev_set_group(mouse, lv_group_get_default());
  // lv_indev_set_display(mousewheel, disp);
  // lv_display_set_default(disp);

  /*Create a cursor*/
  // LV_IMAGE_DECLARE(mouse_cursor_icon); /*Declare the image file.*/
  // lv_obj_t * cursor_obj;
  // cursor_obj = lv_image_create(lv_screen_active()); /*Create an image object for the cursor */
  // lv_image_set_src(cursor_obj, &mouse_cursor_icon);           /*Set the image source*/
  // lv_indev_set_cursor(mouse, cursor_obj);             /*Connect the image  object to the driver*/
  
  lv_indev_t* keyboard = lv_sdl_keyboard_create();
  lv_indev_set_display(keyboard, disp);
  lv_indev_set_group(keyboard, lv_group_get_default());

  return disp;
}
