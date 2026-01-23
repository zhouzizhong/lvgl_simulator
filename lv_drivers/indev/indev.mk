CSRCS += evdev.c

DEPPATH += --dep-path $(LVGL_DIR)/lv_drivers/indev
VPATH += :$(LVGL_DIR)/lv_drivers/indev

CFLAGS += "-I$(LVGL_DIR)/lv_drivers/indev"
