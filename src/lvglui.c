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
#include "log.h"
#include "network.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <dirent.h>

// Supported music file formats
static const char* supported_formats[] = {".mp3", ".ogg", ".wav", ".flac", ".aac", ".mp2", ".amr"};
static const int num_formats = 7;

lv_ui guider_ui;
pthread_mutex_t lvgl_mutex;

static void* mpd_ping_thread_func(void* arg)
{
  while (1) {
    mpd_client_ping();
    sleep(30);
  }
}

static lv_display_t* sdl_hal_init(int32_t w, int32_t h)
{
    lv_group_set_default(lv_group_create());

    lv_display_t* disp = lv_sdl_window_create(w, h);

    // 鼠标输入设备
    lv_indev_t* mouse = lv_sdl_mouse_create();
    lv_indev_set_group(mouse, lv_group_get_default());
    lv_indev_set_display(mouse, disp);
    lv_display_set_default(disp);

    /*Create a cursor*/
    // LV_IMAGE_DECLARE(mouse_cursor_icon); /*Declare the image file.*/
    // lv_obj_t * cursor_obj;
    // cursor_obj = lv_image_create(lv_screen_active()); /*Create an image object for the cursor */
    // lv_image_set_src(cursor_obj, &mouse_cursor_icon);           /*Set the image source*/
    // lv_indev_set_cursor(mouse, cursor_obj);             /*Connect the image  object to the driver*/

    return disp;
}

int lvglui_init(int argc, char** argv)
{
  // Parse command line arguments
  if (argc > 1) {
      // Initialize and connect
      LOG_INFO("Initializing MPD client...");
      if (!mpd_client_init()) {
          LOG_ERROR("MPD client initialization failed");
          return 1;
      }
      LOG_INFO("MPD client initialized successfully");

      if (!mpd_client_connect("localhost", 6600)) {
          LOG_ERROR("MPD connection failed");
          return 1;
      }
      LOG_INFO("MPD client initialized and connected successfully");

      // 1. List all folders (playlists)
      char** folders = NULL;
      int folder_count = 0;
      LOG_INFO("Listing all folders...");
      bool list_result = mpd_client_list_folders(&folders, &folder_count);
      if (list_result) {
          LOG_INFO("=== Available Playlists ===");
          for (int i = 0; i < folder_count; i++) {
              LOG_INFO("%d: %s", i + 1, folders[i]);
          }
      }
      LOG_INFO("Folder listing completed. Found %d folders", folder_count);

      // 2. Switch to the first folder playlist and play
      if (folder_count > 0) {
          LOG_INFO("=== Switching to playlist: %s ===", folders[0]);
          if (mpd_client_switch_folder_playlist(folders[0])) {
              LOG_INFO("Successfully switched playlist, now playing...");
          }
      }
      LOG_INFO("Playlist switching completed");

      // 3. Get songs in the current folder
      if (folder_count > 0) {
          char** songs = NULL;
          int song_count = 0;
          LOG_INFO("Retrieving songs in folder...");
          LOG_DEBUG("Folder name: %s", folders[0]);
          bool get_result = mpd_client_get_folder_songs(folders[0], &songs, &song_count);
          LOG_DEBUG("Song count: %d", song_count);
          if (get_result) {
              LOG_INFO("=== Current Playlist Songs ===");
              if (songs != NULL) {
                  for (int i = 0; i < song_count; i++) {
                      if (songs[i] != NULL) {
                          LOG_INFO("%d: %s", i + 1, songs[i]);
                          free(songs[i]);
                      }
                  }
                  free(songs);
              }
          }
          LOG_INFO("Song retrieval completed. Found %d songs", song_count);
      }
      LOG_INFO("MPD client deinitialized");
  }

  /*Initialize LVGL*/
  lv_init();
  /*Initialize the display, and the input devices*/
  sdl_hal_init(240, 320);
  /* 初始化显示硬件 */
  display_init();
  /*Setup the UI*/
  setup_ui(&guider_ui);

  /* 当前播放歌曲信息初始化 */
  strcpy(g_current_play_data.song_name, "default-song-name");
  strcpy(g_current_play_data.album_name, "default-album-name");
  strcpy(g_current_play_data.cover_path, "/imgs/local_audio_icon.png");
  g_current_play_data.total_duration = 180;
  g_current_play_data.play_status = PLAY_STATUS_STOPPED;
  g_current_play_data.current_position = 0;
  g_current_play_data.song_index = 0;

  /* 当前设备信息初始化 */
  strcpy(g_current_device_info.software_version, "1.0.1");
  strcpy(g_current_device_info.firmware_version, "1.0.1");
  strcpy(g_current_device_info.latest_version, "当前已是最新版本");
  strcpy(g_current_device_info.device_name, "default device_name");
  strcpy(g_current_device_info.model_name, "default device_model");
  strcpy(g_current_device_info.device_id, "default device_id");
  strcpy(g_current_device_info.device_sn, "default device_sn");
  strcpy(g_current_device_info.total_storage, "30GB");
  strcpy(g_current_device_info.free_storage, "15GB");
  strcpy(g_current_device_info.system_storage, "系统文件 5.1GB");
  strcpy(g_current_device_info.audio_storage, "音频 8.8GB");
  strcpy(g_current_device_info.cache_storage, "缓存 1.1GB");
  g_current_device_info.total_storage_int = 30LL * 1024 * 1024 * 1024;
  g_current_device_info.free_storage_int = 15LL * 1024 * 1024 * 1024;
  g_current_device_info.system_storage_int = (long long)(5.1 * 1024 * 1024 * 1024);
  g_current_device_info.audio_storage_int = (long long)(8.8 * 1024 * 1024 * 1024);
  g_current_device_info.cache_storage_int = (long long)(1.1 * 1024 * 1024 * 1024);

  /* 当前用户信息初始化 */
  strcpy(g_current_user_info.user_phone, "default user_phone");
  strcpy(g_current_user_info.user_vip_status, "default user_vip_status");
  strcpy(g_current_user_info.user_vip_expire, "default user_vip_expire");
  /* 账号登录流程*/
  boot_toast_showed = boot_login();
  /* 初始化自定义UI组件 */
  custom_init(&guider_ui);
  events_init(&guider_ui);

  /* 初始化LVGL主循环线程锁 */
  pthread_mutex_init(&lvgl_mutex, NULL);

  pthread_t mpd_ping_thread;
  pthread_create(&mpd_ping_thread, NULL, mpd_ping_thread_func, NULL);

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
