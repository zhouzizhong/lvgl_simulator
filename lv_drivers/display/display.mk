CSRCS += fbdev.c
CSRCS += ST7565.c

DEPPATH += --dep-path $(LVGL_DIR)/lv_drivers/display
VPATH += :$(LVGL_DIR)/lv_drivers/display

CFLAGS += "-I$(LVGL_DIR)/lv_drivers/display"
