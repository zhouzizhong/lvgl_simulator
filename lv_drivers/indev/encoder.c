/**
 * @file encoder.c
 *
 */

/*********************
 *      INCLUDES
 *********************/
#include "encoder.h"
#if USE_ENCODER != 0

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <linux/input.h>
#include <pthread.h>
#include <string.h>

/*********************
 *      DEFINES
 *********************/


/**********************
 *      TYPEDEFS
 **********************/

typedef struct {
    int fd;                     /* Device file descriptor */
    int rotation;               /* Accumulated rotation value */
    lv_indev_state_t button_state;  /* Button state */
} encoder_state_t;

/**********************
 *  STATIC VARIABLES
 **********************/
static encoder_state_t encoder_state = {
    .fd = -1,
    .rotation = 0,
    .button_state = LV_INDEV_STATE_REL
};

/**********************
 *  GLOBAL VARIABLES
 **********************/


/**********************
 *   GLOBAL FUNCTIONS
 **********************/

/**
 * Initialize the encoder interface
 */
void encoder_init(void)
{
    encoder_state.fd = open(dev_name, O_RDWR | O_NOCTTY | O_NDELAY);

    if (encoder_state.fd == -1) {
        perror("encoder_init: Failed to open encoder device:");
        return;
    }

    fcntl(encoder_state.fd, F_SETFL, O_ASYNC | O_NONBLOCK);

    encoder_state.rotation = 0;
    encoder_state.button_state = LV_INDEV_STATE_REL;
}

/**
 * Set the encoder device file
 * @param dev_name set the encoder device filename
 * @return true: the device file set complete
 *         false: the device file doesn't exist current system
 */
bool encoder_set_file(char* dev_name)
{
    if (encoder_state.fd != -1) {
        close(encoder_state.fd);
    }
    encoder_state.fd = open(dev_name, O_RDWR | O_NOCTTY | O_NDELAY);

    if (encoder_state.fd == -1) {
        ALOGD("encoder_set_file: unable to open encoder device");
        return false;
    }

    fcntl(encoder_state.fd, F_SETFL, O_ASYNC | O_NONBLOCK);

    encoder_state.rotation = 0;
    encoder_state.button_state = LV_INDEV_STATE_REL;

    return true;
}

/**
 * Get the current encoder state (rotation and button)
 * @param data store the encoder data here
 */
void encoder_read(lv_indev_drv_t * drv, lv_indev_data_t * data)
{
    struct input_event in;

    while (read(encoder_state.fd, &in, sizeof(struct input_event)) > 0) {
        switch (in.type) {
        case EV_REL:
            /* Handle relative events (rotation) */
            if (in.code == REL_DIAL) {
                /* Accumulate rotation */
                encoder_state.rotation += in.value;
            }
            break;
        case EV_KEY:
            /* Handle key events (button) */
            if (in.code == BTN_DIAL) {
                if (in.value == 1) {
                    encoder_state.button_state = LV_INDEV_STATE_PR;
                } else {
                    encoder_state.button_state = LV_INDEV_STATE_REL;
                }
            }
            break;
        default:
            /* Unknown event type */
            break;
        }
    }
    /* Set encoder data */
    if (encoder_state.rotation > 0)
    {
        if (g_current_page == HOME_PAGE)
        {
            data->enc_diff = -1;
        }
        else
        {
            data->enc_diff = 1;
        }
    }
    else if (encoder_state.rotation < 0)
    {
        if (g_current_page == HOME_PAGE)
        {
            data->enc_diff = 1;
        }
        else
        {
            data->enc_diff = -1;
        }
    }
    if (lv_obj_get_scroll_x(guider_ui.home_page_subpage_entry) > 712 || lv_obj_get_scroll_x(guider_ui.home_page_subpage_entry) < -712)
    {
        data->enc_diff = 0;
    }
    /* Set button state */
    data->state = encoder_state.button_state;
    
    /* Set key to LV_KEY_ENTER for encoder button press to simulate click on focused object */
    if (data->state == LV_INDEV_STATE_PR) {
        data->key = LV_KEY_ENTER;
    }

    /* Auto release button after one frame to simulate complete press/release cycle */
    if (encoder_state.button_state == LV_INDEV_STATE_PR) {
        ALOGD("encoder_handle_events: button_state LV_INDEV_STATE_PR\n");
        encoder_state.button_state = LV_INDEV_STATE_REL;
    }
    
    encoder_state.rotation = 0;
}

#endif /* USE_ENCODER */