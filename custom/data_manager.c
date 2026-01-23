/*
* Copyright 2024 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

/*********************  DATA MANAGER INCLUDES  *********************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lvgl.h"
#include "gui_guider.h"
#include "data_manager.h"
#include "custom.h"
#include "page_manager.h"

/**********************
 *  STATIC VARIABLES
 **********************/
/* 读取游标（每个歌单独立） */
static int g_today_read_idx = 0;
static int g_recent_read_idx = 0;
static int g_my_read_idx = 0;

/**********************
 *  STATIC PROTOTYPES
 **********************/
/**
  * 向歌库添加歌曲
  * @param pl playlist_t结构体指针
  * @param name 歌曲名称
  * @param album 专辑名称
  * @param cover 封面图片
  */
static void playlist_add(playlist_t* pl, const char* name, const char* album, const char* cover)
{
    if (!pl || !name || !album || !cover)
        return;

    song_item_t* tmp = realloc(pl->items,
        (pl->count + 1) * sizeof(song_item_t));
    if (!tmp)
    {
        return;
    }
    pl->items = tmp;

    song_item_t* it = &pl->items[pl->count];
    strncpy(it->song_name, name, sizeof(it->song_name) - 1);
    strncpy(it->album_name, album, sizeof(it->album_name) - 1);
    strncpy(it->cover_path, cover, sizeof(it->cover_path) - 1);
    it->song_index = pl->count; // 设置索引值，从0开始
    it->song_name[sizeof(it->song_name) - 1] = '\0';
    it->album_name[sizeof(it->album_name) - 1] = '\0';
    it->cover_path[sizeof(it->cover_path) - 1] = '\0';

    pl->count++;
}
/**
 * 歌曲点击事件处理
 * @param e lv_event_t结构体指针
 */
static void song_item_click_event_handler(lv_event_t* e)
{
    lv_event_code_t code = lv_event_get_code(e);
    if (code == LV_EVENT_CLICKED)
    {
        song_user_data_t* user_data = (song_user_data_t*)lv_event_get_user_data(e);
        if (user_data && user_data->ui)
        {
            lv_ui* ui = user_data->ui;
            // 更新当前播放歌曲的歌曲信息
            strcpy(g_current_play_data.song_name, user_data->song_name);
            strcpy(g_current_play_data.album_name, user_data->album_name);
            strcpy(g_current_play_data.cover_path, user_data->cover_img);
            if (g_current_play_data.song_index == user_data->song_index && g_cur_songlist == g_current_page)
            {
                ui_load_scr_animation(&guider_ui, &guider_ui.player_page,
                    guider_ui.player_page_del, &guider_ui.home_page_del,
                    setup_scr_player_page, NEXT_LOAD_ANIM, LOAD_ANIM_TIME, LOAD_ANIM_DELAY, false, false);
                update_player_page_content(ui);
                page_stack_push(g_current_page);
                g_current_page = PLAYER_PAGE;
                hide_battery_display();
                return;
            }
            g_current_play_data.play_status = PLAY_STATUS_PLAYING;
            g_current_play_data.song_index = user_data->song_index; // 更新歌曲索引
            g_cur_songlist = g_current_page;
            ui_load_scr_animation(&guider_ui, &guider_ui.player_page,
                guider_ui.player_page_del, &guider_ui.home_page_del,
                setup_scr_player_page, NEXT_LOAD_ANIM, LOAD_ANIM_TIME, LOAD_ANIM_DELAY, false, false);
            update_player_page_content(ui);
            lv_bar_set_value(ui->player_page_music_progress_bar, 0, LV_ANIM_OFF);
            page_stack_push(g_current_page);
            g_current_page = PLAYER_PAGE;
            hide_battery_display();
        }
    }
}
/**
 * 歌曲被清理事件处理
 * @param e lv_event_t结构体指针
 */
static void song_container_delete_event(lv_event_t* e)
{
    if (lv_event_get_code(e) == LV_EVENT_DELETE)
    {
        song_user_data_t* user_data = (song_user_data_t*)lv_event_get_user_data(e);
        if (user_data)
        {
            lv_free(user_data);
        }
    }
}
/**
 * 添加歌曲到播放列表
 * @param ui ui结构体指针
 * @param album_name 专辑名称
 * @param song_name 歌曲名称
 * @param cover_img 封面图片
 * @param songlist 歌单标签
 * @param song_index 歌曲索引
 */
static void add_song_to_listening(lv_ui* ui, const char* album_name, const char* song_name, const char* cover_img, int songlist, int song_index)
{
    // 获取列表容器
    lv_obj_t* list_container;
    lv_group_t* list_group;
    if (songlist == SONGLIST_TODAY)
    {
        list_container = ui->today_listening_page_list;
        list_group = today_listening_group;
    }
    else if (songlist == SONGLIST_RECENT)
    {
        list_container = ui->recently_listening_page_list;
        list_group = recently_listening_group;
    }
    else if (songlist == SONGLIST_MY)
    {
        list_container = ui->my_order_page_list;
        list_group = my_order_group;
    }
    else if (songlist == SONGLIST_LOCAL)
    {
        list_container = ui->local_listening_page_list;
        list_group = local_listening_group;
    }

    // 安全检查：限制最大歌曲数量
    uint32_t child_cnt = lv_obj_get_child_cnt(list_container);
    if (child_cnt >= MAX_SONG_COUNT)
    { // 防止内存溢出
        return;
    }

    // 计算新歌曲项的位置（基于已有项的数量）
    lv_coord_t new_y_pos = 10;

    // 跳过第一个子对象（可能是已有的模板项）
    if (child_cnt > 0)
    {
        lv_obj_t* last_child = lv_obj_get_child(list_container, child_cnt - 1);
        lv_coord_t last_y = lv_obj_get_y(last_child);
        lv_coord_t last_height = lv_obj_get_height(last_child);
        new_y_pos = last_y + last_height + 8;
    }

    // 创建新的歌曲容器
    lv_obj_t* song_container = lv_obj_create(list_container);
    if (!song_container)
    {
        return;
    }
    lv_obj_set_pos(song_container, 16, new_y_pos);
    lv_obj_set_size(song_container, 208, 68);
    lv_obj_set_scrollbar_mode(song_container, LV_SCROLLBAR_MODE_OFF);

    // 为歌曲容器设置唯一标识，用于后续样式更新
    lv_obj_set_user_data(song_container, (void*)(intptr_t)song_index);

    // 设置歌曲容器样式
    lv_obj_set_style_border_width(song_container, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(song_container, 14, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(song_container, CONT_BG_OPA, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(song_container, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(song_container, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(song_container, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(song_container, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(song_container, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(song_container, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(song_container, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    //Write codes cover_img_mask
    lv_obj_t* cover_img_mask = lv_obj_create(song_container);
    lv_obj_set_pos(cover_img_mask, 8, 14);
    lv_obj_set_size(cover_img_mask, 40, 40);
    lv_obj_set_scrollbar_mode(cover_img_mask, LV_SCROLLBAR_MODE_OFF);
    lv_obj_remove_flag(cover_img_mask, LV_OBJ_FLAG_CLICKABLE);

    //Write style for cover_img_mask, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(cover_img_mask, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(cover_img_mask, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(cover_img_mask, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(cover_img_mask, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(cover_img_mask, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(cover_img_mask, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(cover_img_mask, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(cover_img_mask, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(cover_img_mask, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(cover_img_mask, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(cover_img_mask, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_x(cover_img_mask, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_y(cover_img_mask, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(cover_img_mask, true, 0);

    // 创建封面图片
    lv_obj_t* cover_img_obj = lv_img_create(cover_img_mask);
    lv_obj_remove_flag(cover_img_obj, LV_OBJ_FLAG_CLICKABLE);
    if (strcmp(cover_img, "default_cover") == 0)
    {
        lv_img_set_src(cover_img_obj, &_music_cover_example_RGB565A8_40x40);
    }
    else
    {
        lv_img_set_src(cover_img_obj, cover_img);
    }
    // 设置图片位置和大小
    lv_obj_set_size(cover_img_obj, 42, 42);
    lv_img_set_pivot(cover_img_obj, 20, 20);
    lv_img_set_angle(cover_img_obj, 0);
    lv_obj_set_pos(cover_img_obj, 0, 0);
    lv_image_set_inner_align(cover_img_obj, LV_IMAGE_ALIGN_STRETCH);

    // 创建歌曲标题
    lv_obj_t* song_title = lv_label_create(song_container);
    lv_label_set_text(song_title, song_name);
    lv_label_set_long_mode(song_title, LV_LABEL_LONG_DOT);
    lv_obj_set_pos(song_title, 56, 11);
    lv_obj_set_size(song_title, 122, 25);

    // 设置歌曲标题样式
    lv_obj_set_style_border_width(song_title, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(song_title, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(song_title, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(song_title, &lv_font_MyPingFangSC_Semibold_18, 0);
    lv_obj_set_style_text_opa(song_title, LV_OPA_90, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(song_title, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(song_title, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(song_title, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(song_title, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(song_title, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(song_title, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(song_title, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(song_title, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(song_title, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // 创建专辑标题
    lv_obj_t* album_title = lv_label_create(song_container);
    lv_label_set_text(album_title, album_name);
    lv_label_set_long_mode(album_title, LV_LABEL_LONG_DOT);
    lv_obj_set_pos(album_title, 56, 38);
    lv_obj_set_size(album_title, 144, 20);

    // 设置专辑标题样式
    lv_obj_set_style_border_width(album_title, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(album_title, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(album_title, lv_color_hex(0xf2f4fc), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(album_title, &lv_font_MyPingFangSC_Regular_14, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(album_title, LV_OPA_70, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(album_title, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(album_title, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(album_title, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(album_title, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(album_title, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(album_title, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(album_title, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(album_title, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(album_title, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // 创建旋律图标（默认隐藏）
    lv_obj_t* rhythm_icon = lv_gif_create(song_container);
    lv_obj_remove_flag(rhythm_icon, LV_OBJ_FLAG_CLICKABLE);
    lv_gif_set_src(rhythm_icon, &ic_play);
    lv_obj_set_pos(rhythm_icon, 56, 12);
    lv_obj_set_size(rhythm_icon, 22, 22);
    lv_obj_add_flag(rhythm_icon, LV_OBJ_FLAG_HIDDEN); // 默认隐藏

    // 设置旋律图标样式
    lv_obj_set_style_img_recolor_opa(rhythm_icon, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(rhythm_icon, LV_OPA_100, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(rhythm_icon, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(rhythm_icon, true, LV_PART_MAIN | LV_STATE_DEFAULT);

    // 创建用户数据，存储歌曲信息
    song_user_data_t* user_data = (song_user_data_t*)lv_malloc(sizeof(song_user_data_t));
    if (!user_data)
    {
        // 即使内存分配失败，也要确保UI正常
        return;
    }
    if (user_data)
    {
        // 使用strncpy复制字符串内容，而不是存储指针
        if (song_name)
            strncpy(user_data->song_name, song_name, sizeof(user_data->song_name) - 1);
        else
            user_data->song_name[0] = '\0';

        if (album_name)
            strncpy(user_data->album_name, album_name, sizeof(user_data->album_name) - 1);
        else
            user_data->album_name[0] = '\0';

        if (cover_img)
            strncpy(user_data->cover_img, cover_img, sizeof(user_data->cover_img) - 1);
        else
            user_data->cover_img[0] = '\0';

        user_data->ui = ui;
        user_data->song_index = song_index; // 设置歌曲索引
    }

    // 确保字符串正确终止
    user_data->song_name[sizeof(user_data->song_name) - 1] = '\0';
    user_data->album_name[sizeof(user_data->album_name) - 1] = '\0';
    user_data->cover_img[sizeof(user_data->cover_img) - 1] = '\0';

    // 设置必要标志位
    lv_obj_add_flag(song_container, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_remove_flag(song_container, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_add_flag(song_container, LV_OBJ_FLAG_CLICK_FOCUSABLE);
    lv_obj_add_flag(song_container, LV_OBJ_FLAG_SCROLL_ON_FOCUS);

    // 添加点击事件和删除事件
    lv_obj_add_event_cb(song_container, song_item_click_event_handler, LV_EVENT_CLICKED, user_data);
    lv_obj_add_event_cb(song_container, song_container_delete_event, LV_EVENT_DELETE, user_data);
    lv_obj_add_style(song_container, &style_focus, LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_group_add_obj(list_group, song_container);
}

/**
 * 向歌单列表追加歌曲
 * @param ui ui结构体指针
 * @param pl playlist_t结构体指针
 * @param read_idx 读取游标指针
 * @param song_count 追加歌曲数量
 * @param tag 歌单标签
 */
static void playlist_load_more(lv_ui* ui, playlist_t* pl, int* read_idx, int song_count, int tag)
{
    if (!ui || !pl || !read_idx)
        return;

    int left = pl->count - *read_idx;
    int add = (song_count > left) ? left : song_count;
    if (add <= 0)
        return;

    for (int i = 0; i < add; ++i)
    {
        const song_item_t* it = &pl->items[*read_idx + i];
        if (tag == SONGLIST_TODAY)
        {
            add_song_to_listening(ui, it->album_name, it->song_name, it->cover_path, SONGLIST_TODAY, it->song_index);
        }
        else if (tag == SONGLIST_RECENT)
        {
            add_song_to_listening(ui, it->album_name, it->song_name, it->cover_path, SONGLIST_RECENT, it->song_index);
        }
        else if (tag == SONGLIST_MY)
        {
            add_song_to_listening(ui, it->album_name, it->song_name, it->cover_path, SONGLIST_MY, it->song_index);
        }
        else if (tag == SONGLIST_LOCAL)
        {
            add_song_to_listening(ui, it->album_name, it->song_name, it->cover_path, SONGLIST_LOCAL, it->song_index);
        }
    }
    *read_idx += add;
}
static void local_playlist_item_click_event_handler(lv_event_t* e) {
    lv_event_code_t code = lv_event_get_code(e);
    if (code == LV_EVENT_CLICKED) {
        // 获取用户数据
        playlist_item_user_data_t* user_data = (playlist_item_user_data_t*)lv_event_get_user_data(e);
        if (user_data && user_data->ui && user_data->folder) {
            free(g_local_playlist.items);
            g_local_playlist.items = NULL;
            g_local_playlist.count = 0;
            g_local_read_idx = 0;
            local_scrolly_bottom_loader = 134;
            g_cur_localfolder_path = strdup(user_data->folder->folder_path);
            g_cur_localfolder_name = strdup(user_data->folder->folder_name);
            g_cur_localfolder_song_count = user_data->folder->song_count;

            // 加载本地歌单界面
            scan_playlist_add(user_data->folder->folder_path, user_data->folder->folder_name);
            ui_load_scr_animation(&guider_ui, &guider_ui.local_listening_page, guider_ui.local_listening_page_del, &guider_ui.local_audio_page_del, setup_scr_local_listening_page, NEXT_LOAD_ANIM, LOAD_ANIM_TIME, LOAD_ANIM_DELAY, false, false);
            page_stack_push(g_current_page);
            g_current_page = LOCAL_LISTENING_PAGE;
            lv_label_set_text(user_data->ui->local_listening_page_main_title, g_cur_localfolder_name);
            lv_obj_clean(user_data->ui->local_listening_page_list);
            add_songs_to_local_listening(user_data->ui, g_cur_localfolder_song_count);
            update_song_rhythm_icon(user_data->ui, SONGLIST_LOCAL, g_current_play_data.song_index);
        }
    }
}
/**********************
 *  GLOBAL PROTOTYPES
 **********************/
void add_song_to_today(const char* n, const char* a, const char* c)
{
    playlist_add(&g_today_playlist, n, a, c);
}
void add_song_to_recent(const char* n, const char* a, const char* c)
{
    playlist_add(&g_recent_playlist, n, a, c);
}
void add_song_to_my(const char* n, const char* a, const char* c)
{
    playlist_add(&g_my_playlist, n, a, c);
}
void add_songs_to_today_listening(lv_ui* ui, int song_count)
{
    playlist_load_more(ui, &g_today_playlist, &g_today_read_idx, song_count, SONGLIST_TODAY);
    update_song_rhythm_icon(ui, SONGLIST_TODAY, g_current_play_data.song_index);
}
void add_songs_to_recent_listening(lv_ui* ui, int song_count)
{
    playlist_load_more(ui, &g_recent_playlist, &g_recent_read_idx, song_count, SONGLIST_RECENT);
    update_song_rhythm_icon(ui, SONGLIST_RECENT, g_current_play_data.song_index);
}
void add_songs_to_my_listening(lv_ui* ui, int song_count)
{
    playlist_load_more(ui, &g_my_playlist, &g_my_read_idx, song_count, SONGLIST_MY);
    update_song_rhythm_icon(ui, SONGLIST_MY, g_current_play_data.song_index);
}
void add_songs_to_local_listening(lv_ui* ui, int song_count)
{
    playlist_load_more(ui, &g_local_playlist, &g_local_read_idx, song_count, SONGLIST_LOCAL);
    update_song_rhythm_icon(ui, SONGLIST_LOCAL, g_current_play_data.song_index);
}
void clean_all_listening_page(lv_ui* ui)
{
    // 安全检查：确保UI对象已初始化
    if (!ui || !ui->today_listening_page_list)
    {
        return;
    }
    free(g_today_playlist.items);
    g_today_playlist.items = NULL;
    free(g_recent_playlist.items);
    g_recent_playlist.items = NULL;
    free(g_my_playlist.items);
    g_my_playlist.items = NULL;
    g_today_playlist.count = 0;
    g_recent_playlist.count = 0;
    g_my_playlist.count = 0;
    g_today_read_idx = 0;
    g_recent_read_idx = 0;
    g_my_read_idx = 0;

    if (ui)
    {
        lv_obj_clean(ui->today_listening_page_list);
        lv_obj_clean(ui->recently_listening_page_list);
        lv_obj_clean(ui->my_order_page_list);
    }
}
bool add_local_folder(const char* folder_name, int song_count, const char* folder_path)
{
    // 参数有效性检查
    if (!folder_name || strlen(folder_name) == 0 || song_count < 0)
    {
        return false;
    }

    // 检查文件夹是否已存在
    for (int i = 0; i < g_local_folder_repo.count; i++)
    {
        if (strcmp(g_local_folder_repo.folders[i].folder_name, folder_name) == 0)
        {
            // 如果文件夹已存在，更新歌曲数量
            g_local_folder_repo.folders[i].song_count = song_count;
            return true;
        }
    }

    // 检查是否需要扩容
    if (g_local_folder_repo.count >= g_local_folder_repo.capacity)
    {
        // 初始容量设为10，之后每次扩容增加10
        int new_capacity = (g_local_folder_repo.capacity == 0) ? 10 : g_local_folder_repo.capacity + 10;
        local_folder_t* new_folders = (local_folder_t*)realloc(g_local_folder_repo.folders, sizeof(local_folder_t) * new_capacity);

        if (!new_folders)
        {
            return false;
        }

        g_local_folder_repo.folders = new_folders;
        g_local_folder_repo.capacity = new_capacity;
    }

    // 添加新文件夹
    local_folder_t* new_folder = &g_local_folder_repo.folders[g_local_folder_repo.count];
    strncpy(new_folder->folder_name, folder_name, sizeof(new_folder->folder_name) - 1);
    new_folder->folder_name[sizeof(new_folder->folder_name) - 1] = '\0'; // 确保字符串结束符
    strncpy(new_folder->folder_path, folder_path, sizeof(new_folder->folder_path) - 1);
    new_folder->folder_path[sizeof(new_folder->folder_path) - 1] = '\0'; // 确保字符串结束符
    new_folder->song_count = song_count;

    g_local_folder_repo.count++;
    return true;
}
void add_local_playlists_to_page(lv_ui* ui, const local_folder_repository_t* repo) {
    if (!ui || !ui->local_audio_page_subpage_entry || !repo) {
        return;
    }
    // 清除容器中的现有内容
    lv_obj_clean(ui->local_audio_page_subpage_entry);
    // 移除隐藏标志，显示容器
    lv_obj_remove_flag(ui->local_audio_page_subpage_entry, LV_OBJ_FLAG_HIDDEN);
    // 遍历仓库中的每个文件夹
    for (int i = 0; i < repo->count; i++) {
        const local_folder_t* folder = &repo->folders[i];

        // 创建歌单项容器
        lv_obj_t* album_item = lv_obj_create(ui->local_audio_page_subpage_entry);
        lv_obj_set_pos(album_item, 16, 8 + i * 64);
        lv_obj_set_size(album_item, 208, 58);
        lv_obj_set_scrollbar_mode(album_item, LV_SCROLLBAR_MODE_OFF);

        // 创建用户数据结构体
        playlist_item_user_data_t* user_data = (playlist_item_user_data_t*)lv_malloc(sizeof(playlist_item_user_data_t));
        if (user_data) {
            user_data->ui = ui;
            user_data->folder = (void*)folder;
        }

        // 设置歌单项样式
        lv_obj_set_style_border_width(album_item, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_radius(album_item, 14, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_opa(album_item, CONT_BG_OPA, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(album_item, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_grad_dir(album_item, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_pad_top(album_item, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_pad_bottom(album_item, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_pad_left(album_item, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_pad_right(album_item, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_shadow_width(album_item, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

        // 创建图标
        lv_obj_t* album_icon = lv_img_create(album_item);
        lv_obj_remove_flag(album_icon, LV_OBJ_FLAG_CLICKABLE);
        lv_img_set_src(album_icon, &_local_audio_album_icon2_RGB565A8_30x30); // 使用现有的图标资源
        lv_img_set_pivot(album_icon, 50, 50);
        lv_img_set_angle(album_icon, 0);
        lv_obj_set_pos(album_icon, 12, 14);
        lv_obj_set_size(album_icon, 30, 30);

        // 设置图标样式
        lv_obj_set_style_img_recolor_opa(album_icon, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_img_opa(album_icon, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_radius(album_icon, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_clip_corner(album_icon, true, LV_PART_MAIN | LV_STATE_DEFAULT);

        // 创建标题标签
        lv_obj_t* album_title = lv_label_create(album_item);
        lv_label_set_text(album_title, folder->folder_name);
        lv_label_set_long_mode(album_title, LV_LABEL_LONG_SCROLL_CIRCULAR);
        lv_obj_set_style_anim_duration(album_title, LABLE_SCROLL_SPEED, LV_PART_MAIN);
        lv_obj_set_pos(album_title, 44, 17);
        lv_obj_set_size(album_title, 120, 22);

        // 设置标题样式
        lv_obj_set_style_border_width(album_title, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_radius(album_title, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(album_title, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_font(album_title, &lv_font_MyPingFangSC_Semibold_18, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_opa(album_title, LV_OPA_90, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_letter_space(album_title, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_line_space(album_title, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_align(album_title, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_opa(album_title, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_pad_top(album_title, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_pad_right(album_title, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_pad_bottom(album_title, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_pad_left(album_title, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_shadow_width(album_title, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

        // 创建歌曲数量标签
        lv_obj_t* songs_num = lv_label_create(album_item);
        char songs_num_text[16];
        snprintf(songs_num_text, sizeof(songs_num_text), "%d首", folder->song_count);
        lv_label_set_text(songs_num, songs_num_text);
        lv_label_set_long_mode(songs_num, LV_LABEL_LONG_WRAP);
        lv_obj_set_pos(songs_num, 158, 18);
        lv_obj_set_size(songs_num, 40, 20); // 增加宽度以避免换行

        // 设置歌曲数量标签样式
        lv_obj_set_style_border_width(songs_num, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_radius(songs_num, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(songs_num, lv_color_hex(0xf2f4fc), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_font(songs_num, &lv_font_MyPingFangSC_Regular_14, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_opa(songs_num, LV_OPA_70, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_letter_space(songs_num, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_line_space(songs_num, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_align(songs_num, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_opa(songs_num, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_pad_top(songs_num, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_pad_right(songs_num, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_pad_bottom(songs_num, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_pad_left(songs_num, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_shadow_width(songs_num, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

        // 添加点击事件
        lv_obj_add_flag(album_item, LV_OBJ_FLAG_CLICKABLE);
        lv_obj_add_event_cb(album_item, local_playlist_item_click_event_handler, LV_EVENT_CLICKED, user_data);

        // 添加删除事件以释放内存
        lv_obj_add_event_cb(album_item, song_container_delete_event, LV_EVENT_DELETE, user_data);

        lv_obj_add_style(album_item, &style_focus, LV_PART_MAIN | LV_STATE_FOCUSED);
        lv_obj_add_flag(album_item, LV_OBJ_FLAG_CLICKABLE);
        lv_obj_remove_flag(album_item, LV_OBJ_FLAG_SCROLLABLE);
        lv_obj_add_flag(album_item, LV_OBJ_FLAG_CLICK_FOCUSABLE);
        lv_obj_add_flag(album_item, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
        lv_group_add_obj(local_songlist_group, album_item);
    }
}
int scan_musicdir(void) {
    //检索本地音乐文件夹
    add_local_folder("叫早儿歌", 7, "文件夹路径");
    add_local_folder("哄睡儿歌", 7, "文件夹路径");
    add_local_folder("诗词", 7, "文件夹路径");
    add_local_folder("童谣", 7, "文件夹路径");
    add_local_folder("童话", 7, "文件夹路径");
    is_localsong_exists = 1;
    return 0;
}
void scan_playlist_add(const char* playlist_path, const char* playlist_name) {
    //检索获取的文件夹路径
    playlist_add(&g_local_playlist, "Rise and Shine, Little Star", playlist_name, "D:Rise and Shine, Little Star.png");
    playlist_add(&g_local_playlist, "Good Morning, Sunny Bunny", playlist_name, "D:Good Morning, Sunny Bunny.png");
    playlist_add(&g_local_playlist, "Wake Up, Wiggle Worms", playlist_name, "D:Wake Up, Wiggle Worms.png");
    playlist_add(&g_local_playlist, "Hello Sunshine, Time to Play", playlist_name, "D:Hello Sunshine, Time to Play.png");
    playlist_add(&g_local_playlist, "Stretch and Yawn Adventure Song", playlist_name, "D:Stretch and Yawn Adventure Song.png");
    playlist_add(&g_local_playlist, "Cock-a-Doodle Jump", playlist_name, "D:Cock-a-Doodle Jump.png");
    playlist_add(&g_local_playlist, "Little Bird, Little Bird", playlist_name, "default_cover");
    return;
}
void init_child_info_repo(void) {
    g_child_info_repo.count = 0;
    memset(g_child_info_repo.children, 0, sizeof(g_child_info_repo.children));
}
void add_child_to_repo(const current_child_info_t* child) {
    if (!child) {
        return;
    }

    // 如果库已满，将第一个孩子挤掉，后面的孩子依次前移
    if (g_child_info_repo.count >= MAX_CHILDREN_COUNT) {
        // 将后面的孩子依次前移
        for (int i = 0; i < MAX_CHILDREN_COUNT - 1; i++) {
            memcpy(&g_child_info_repo.children[i], &g_child_info_repo.children[i + 1], sizeof(current_child_info_t));
        }
        // 添加新孩子到最后一个位置
        memcpy(&g_child_info_repo.children[MAX_CHILDREN_COUNT - 1], child, sizeof(current_child_info_t));
    }
    else {
        // 直接添加到当前位置
        memcpy(&g_child_info_repo.children[g_child_info_repo.count], child, sizeof(current_child_info_t));
        g_child_info_repo.count++;
    }
}
current_child_info_t* get_child_from_repo(int index) {
    if (index < 0 || index >= g_child_info_repo.count) {
        return NULL;
    }
    return &g_child_info_repo.children[index];
}
int update_current_song_by_index(lv_ui* ui, int songlist, int song_index) {
    // 根据歌单标识获取对应的歌单
    playlist_t* target_playlist = NULL;

    // 检查UI指针是否有效
    if (!ui) {
        return -1;
    }
    switch (songlist) {
    case SONGLIST_TODAY:
        target_playlist = &g_today_playlist;
        break;
    case SONGLIST_RECENT:
        target_playlist = &g_recent_playlist;
        break;
    case SONGLIST_MY:
        target_playlist = &g_my_playlist;
        break;
    case SONGLIST_LOCAL:
        target_playlist = &g_local_playlist;
        break;
    default:
        return -1;
    }
    // 检查歌单是否有效
    if (target_playlist == NULL || target_playlist->items == NULL || target_playlist->count == 0) {
        return -1;
    }
    g_current_play_data.song_index = song_index;
    // 更新当前播放索引
    if (g_current_play_data.song_index >= target_playlist->count)
    {
        g_current_play_data.song_index = 0;
    }
    else if (g_current_play_data.song_index < 0)
    {
        g_current_play_data.song_index = target_playlist->count - 1;
    }

    // 再次检查索引是否有效
    if (g_current_play_data.song_index >= target_playlist->count) {
        return -1;
    }

    // 获取指定索引的歌曲信息
    song_item_t* song_item = &target_playlist->items[g_current_play_data.song_index];

    // 更新当前播放歌曲信息
    strncpy(g_current_play_data.song_name, song_item->song_name, sizeof(g_current_play_data.song_name) - 1);
    g_current_play_data.song_name[sizeof(g_current_play_data.song_name) - 1] = '\0';

    strncpy(g_current_play_data.album_name, song_item->album_name, sizeof(g_current_play_data.album_name) - 1);
    g_current_play_data.album_name[sizeof(g_current_play_data.album_name) - 1] = '\0';

    strncpy(g_current_play_data.cover_path, song_item->cover_path, sizeof(g_current_play_data.cover_path) - 1);
    g_current_play_data.cover_path[sizeof(g_current_play_data.cover_path) - 1] = '\0';

    return 0;
}
void bluetooth_container_init(void) {
    g_bt_device_container.capacity = 8; // 初始容量为8
    g_bt_device_container.count = 0;
    g_bt_device_container.devices = (bluetooth_device_t*)malloc(g_bt_device_container.capacity * sizeof(bluetooth_device_t));
    if (g_bt_device_container.devices == NULL) {
        g_bt_device_container.capacity = 0;
    }
}
void bluetooth_container_deinit(void) {
    if (g_bt_device_container.devices != NULL) {
        free(g_bt_device_container.devices);
        g_bt_device_container.devices = NULL;
    }
    g_bt_device_container.count = 0;
    g_bt_device_container.capacity = 0;
}
bool bluetooth_container_add(const char* name, const char* type) {
    if (name == NULL || type == NULL) {
        return false;
    }
    // 检查设备是否已存在
    for (int i = 0; i < g_bt_device_container.count; i++) {
        if (strcmp(g_bt_device_container.devices[i].name, name) == 0) {
            // 设备已存在，更新连接状态和类型
            g_bt_device_container.devices[i].connected = true;
            strncpy(g_bt_device_container.devices[i].type, type, sizeof(g_bt_device_container.devices[i].type) - 1);
            g_bt_device_container.devices[i].type[sizeof(g_bt_device_container.devices[i].type) - 1] = '\0';

            // 将设备移到列表末尾（表示最新连接）
            if (i != g_bt_device_container.count - 1) {
                bluetooth_device_t temp = g_bt_device_container.devices[i];
                for (int j = i; j < g_bt_device_container.count - 1; j++) {
                    g_bt_device_container.devices[j] = g_bt_device_container.devices[j + 1];
                }
                g_bt_device_container.devices[g_bt_device_container.count - 1] = temp;
            }
            return true;
        }
    }

    // 检查容量是否足够，不足则扩容
    if (g_bt_device_container.count >= g_bt_device_container.capacity) {
        int new_capacity = g_bt_device_container.capacity * 2;
        bluetooth_device_t* new_devices = (bluetooth_device_t*)realloc(
            g_bt_device_container.devices, new_capacity * sizeof(bluetooth_device_t));
        if (new_devices == NULL) {
            return false;
        }
        g_bt_device_container.devices = new_devices;
        g_bt_device_container.capacity = new_capacity;
    }

    // 添加新设备
    bluetooth_device_t* new_device = &g_bt_device_container.devices[g_bt_device_container.count];
    strncpy(new_device->name, name, sizeof(new_device->name) - 1);
    new_device->name[sizeof(new_device->name) - 1] = '\0';
    strncpy(new_device->type, type, sizeof(new_device->type) - 1);
    new_device->type[sizeof(new_device->type) - 1] = '\0';
    new_device->connected = true;

    g_bt_device_container.count++;
    return true;
}
bool bluetooth_container_remove(const char* name) {
    if (name == NULL) {
        return false;
    }

    for (int i = 0; i < g_bt_device_container.count; i++) {
        if (strcmp(g_bt_device_container.devices[i].name, name) == 0) {
            // 移除设备
            g_bt_device_container.devices[i].connected = false;

            // 将后续设备向前移动
            for (int j = i; j < g_bt_device_container.count - 1; j++) {
                g_bt_device_container.devices[j] = g_bt_device_container.devices[j + 1];
            }

            g_bt_device_container.count--;
            return true;
        }
    }
    return false;
}
bluetooth_device_t* bluetooth_container_get_latest(void) {
    if (g_bt_device_container.count == 0) {
        return NULL;
    }
    return &g_bt_device_container.devices[g_bt_device_container.count - 1];
}
bluetooth_device_t* bluetooth_container_get(const char* name) {
    if (name == NULL) {
        return NULL;
    }
    for (int i = 0; i < g_bt_device_container.count; i++) {
        if (strcmp(g_bt_device_container.devices[i].name, name) == 0) {
            return &g_bt_device_container.devices[i];
        }
    }
    return NULL;
}
void bluetooth_container_update_display_name(void) {
    bluetooth_device_t* latest_device = bluetooth_container_get_latest();
    if (latest_device != NULL && latest_device->connected) {
        strncpy(bt_name, latest_device->name, 63); // bt_name is defined as char[64] in custom.c
        bt_name[63] = '\0';
    }
    else {
        // 没有已连接的设备，清空显示名称
        strcpy(bt_name, "扫码配对");
    }
}
