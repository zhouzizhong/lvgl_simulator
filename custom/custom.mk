
# 自定义字体
include $(PRJ_DIR)/custom/custom_fonts/custom_fonts.mk

# 自定义图片
include $(PRJ_DIR)/custom/custom_images/custom_images.mk

GEN_CSRCS += $(notdir $(wildcard $(PRJ_DIR)/custom/*.c))
GEN_CSRCS += $(notdir $(CUSTOM_FONT_SRCS))
GEN_CSRCS += $(notdir $(CUSTOM_IMAGE_SRCS))

DEPPATH += --dep-path $(PRJ_DIR)/custom
VPATH += :$(PRJ_DIR)/custom

CFLAGS += "-I$(PRJ_DIR)/custom"
AFLAGS += "-I$(PRJ_DIR)/custom"
