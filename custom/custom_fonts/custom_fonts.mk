# 自定义字体构建配置

# 包含字体源文件列表
-include $(PRJ_DIR)/custom/custom_fonts/fonts_list.mk

# 添加依赖路径
DEPPATH += --dep-path $(PRJ_DIR)/custom/custom_fonts

# 添加源文件搜索路径
VPATH += :$(PRJ_DIR)/custom/custom_fonts

# 添加包含目录
CFLAGS += "-I$(PRJ_DIR)/custom/custom_fonts"
