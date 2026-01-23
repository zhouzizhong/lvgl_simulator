/*
* Copyright 2024 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

/*
 * lv_conf_ext.h for custom lvconf file.
 * example :
 *	#undef LV_FONT_FMT_TXT_LARGE
 *  #define LV_FONT_FMT_TXT_LARGE 1
 */

#ifndef LV_CONF_EXT_H
#define LV_CONF_EXT_H


/* common code  begin  */
#undef LV_FONT_FMT_TXT_LARGE
#define LV_FONT_FMT_TXT_LARGE 1

#undef LV_USE_FS_WIN32
#define LV_USE_FS_WIN32 1
#if LV_USE_FS_WIN32
/*Set an upper cased letter on which the drive will accessible (e.g. 'A')*/
#undef LV_FS_WIN32_LETTER
#define LV_FS_WIN32_LETTER 'D'
/*Set the working directory. File/directory paths will be appended to it.*/
#undef LV_FS_WIN32_PATH
#define LV_FS_WIN32_PATH "/work/lvgl_ings/"
/*>0 to cache this number of bytes in lv_fs_read()*/
#undef LV_FS_WIN32_CACHE_SIZE
#define LV_FS_WIN32_CACHE_SIZE 1024
#endif /* LV_USE_FS_WIN32 */

#undef LV_USE_LODEPNG
#define LV_USE_LODEPNG 1

#undef LV_USE_GIF
#define LV_USE_GIF 1
#if LV_USE_GIF
    /*GIF decoder accelerate*/
#undef LV_GIF_CACHE_DECODE_DATA
#define LV_GIF_CACHE_DECODE_DATA 1
#endif
/* common code end */


#if LV_USE_GUIDER_SIMULATOR
/* code for simulator begin  */


/* code for simulator end */
#else
/* code for board begin */


/* code for board end */	
#endif



#endif  /* LV_CONF_EXT_H */	