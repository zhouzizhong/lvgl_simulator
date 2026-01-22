
# 自定义字体
include $(PRJ_DIR)/custom/custom_fonts/custom_fonts.mk

GEN_CSRCS += $(notdir $(wildcard $(PRJ_DIR)/custom/*.c))
GEN_CSRCS += $(notdir $(CUSTOM_FONT_SRCS))

DEPPATH += --dep-path $(PRJ_DIR)/custom
VPATH += :$(PRJ_DIR)/custom

CFLAGS += "-I$(PRJ_DIR)/custom"
AFLAGS += "-I$(PRJ_DIR)/custom"
