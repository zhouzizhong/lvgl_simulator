/**
 * @file encoder.h
 *
 */

#ifndef ENCODER_H
#define ENCODER_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/
#ifndef LV_DRV_NO_CONF
#ifdef LV_CONF_INCLUDE_SIMPLE
#include "lv_drv_conf.h"
#else
#include "../../lv_drv_conf.h"
#endif
#endif

#if USE_ENCODER

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL PROTOTYPES
 **********************/

/**
 * Initialize the encoder input device
 */
void encoder_init(void);

/**
 * Get the current encoder state (rotation and button)
 * @param data store the encoder data here
 */
void encoder_read(lv_indev_drv_t * drv, lv_indev_data_t * data);

/**
 * Set the encoder device file
 * @param dev_name set the encoder device filename
 * @return true: the device file set complete
 *         false: the device file doesn't exist current system
 */
bool encoder_set_file(char* dev_name);

/**
 * Set external button state from client
 * @param pressed true if button is pressed, false otherwise
 */
void encoder_set_external_button(bool pressed);

/**********************
 *      MACROS
 **********************/

#endif /* USE_ENCODER */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* ENCODER_H */