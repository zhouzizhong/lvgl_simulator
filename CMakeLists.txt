# ==============================================================================
# CMake 基本配置
# ==============================================================================
cmake_minimum_required(VERSION 3.10)  # CMake 版本要求
project(lvgl)                         # 项目名称

# ==============================================================================
# 编译选项配置
# ==============================================================================
# 可选特性开关
option(LV_USE_DRAW_SDL "Use SDL draw unit" OFF)            # 使用 SDL 绘制单元
option(LV_USE_LIBPNG "Use libpng to decode PNG" OFF)       # 使用 libpng 解码 PNG
option(LV_USE_LV_DRIVERS "Use LVGL drivers" OFF)           # 使用 LVGL 驱动

# 设置 C/C++ 标准
set(CMAKE_C_STANDARD 99)              # C 标准: C99
set(CMAKE_CXX_STANDARD 17)            # C++ 标准: C17
set(CMAKE_CXX_STANDARD_REQUIRED ON)   # 要求严格遵循标准

# 设置可执行文件输出目录
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

# ==============================================================================
# 外部依赖查找
# ==============================================================================
find_package(SDL2 REQUIRED SDL2)      # 查找 SDL2 库

# ==============================================================================
# 编译定义
# ==============================================================================
# 根据选项生成编译定义
add_compile_definitions($<$<BOOL:${LV_USE_DRAW_SDL}>:LV_USE_DRAW_SDL=1>)
add_compile_definitions($<$<BOOL:${LV_USE_LIBPNG}>:LV_USE_LIBPNG=1>)
add_compile_definitions($<$<BOOL:${LV_USE_LIBJPEG_TURBO}>:LV_USE_LIBJPEG_TURBO=1>)
add_compile_definitions($<$<BOOL:${LV_USE_LV_DRIVERS}>:LV_USE_LV_DRIVERS=1>)

# ==============================================================================
# LVGL 库配置
# ==============================================================================
add_subdirectory(lvgl)                # 添加 LVGL 子目录
# 为 LVGL 添加包含目录

target_include_directories(lvgl PUBLIC ${PROJECT_SOURCE_DIR} ${SDL2_INCLUDE_DIRS})

# ==============================================================================
# LVGL 驱动配置
# ==============================================================================
if(LV_USE_LV_DRIVERS)
    # 添加 lv_drivers 包含目录
    target_include_directories(lvgl PUBLIC ${PROJECT_SOURCE_DIR}/lv_drivers)
    
    # 配置显示驱动源文件
    set(LV_DRIVERS_DISPLAY_SRCS
        ${PROJECT_SOURCE_DIR}/lv_drivers/display/fbdev.c
        # 可在此添加更多显示驱动
    )
    
    # 配置输入驱动源文件
    set(LV_DRIVERS_INPUT_SRCS
        # 可在此添加输入驱动
        # e.g., ${PROJECT_SOURCE_DIR}/lv_drivers/indev/evdev.c
    )
    
    # 将驱动源文件添加到主可执行文件
    target_sources(main PRIVATE ${LV_DRIVERS_DISPLAY_SRCS} ${LV_DRIVERS_INPUT_SRCS})
endif()

# ==============================================================================
# 源文件收集
# ==============================================================================
# 1. 搜索自定义代码和自动生成代码
file(GLOB_RECURSE CUSTOM_SRCS "${PROJECT_SOURCE_DIR}/custom/*.c" "${PROJECT_SOURCE_DIR}/custom/*.cpp" "${PROJECT_SOURCE_DIR}/custom/*.h")
file(GLOB_RECURSE GENERATED_SRCS "${PROJECT_SOURCE_DIR}/generated/*.c" "${PROJECT_SOURCE_DIR}/generated/*.cpp")

# ==============================================================================
# 可执行文件创建
# ==============================================================================
# 2. 创建主可执行文件
add_executable(main 
    main.c                           # 主程序入口
    mouse_cursor_icon.c              # 鼠标光标图标
    ${CUSTOM_SRCS}                   # 自定义代码
    ${GENERATED_SRCS}                # 自动生成代码
)

# ==============================================================================
# 包含目录设置
# ==============================================================================
# 3. 添加包含目录

target_include_directories(main PRIVATE
    ${PROJECT_SOURCE_DIR}/custom     # 自定义代码包含目录
    ${PROJECT_SOURCE_DIR}/generated  # 自动生成代码包含目录
)

# ==============================================================================
# 链接配置
# ==============================================================================
target_compile_definitions(main PRIVATE LV_CONF_INCLUDE_SIMPLE)  # LVGL 配置包含方式

# 链接主程序所需库

target_link_libraries(main lvgl lvgl::examples lvgl::demos lvgl::thorvg ${SDL2_LIBRARIES} m pthread)

# ==============================================================================
# 自定义目标
# ==============================================================================
# 添加 run 目标，用于运行主程序
add_custom_target (run COMMAND ${EXECUTABLE_OUTPUT_PATH}/main DEPENDS main)

# ==============================================================================
# 条件依赖处理
# ==============================================================================
# SDL 绘制单元依赖
if(LV_USE_DRAW_SDL)
    set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")
    find_package(SDL2_image REQUIRED)  # 查找 SDL2_image 库
    target_include_directories(lvgl PUBLIC ${SDL2_IMAGE_INCLUDE_DIRS})
    target_link_libraries(main ${SDL2_IMAGE_LIBRARIES})
endif(LV_USE_DRAW_SDL)

# libpng 依赖
if(LV_USE_LIBPNG)
    find_package(PNG REQUIRED)        # 查找 PNG 库
    target_include_directories(lvgl PUBLIC ${PNG_INCLUDE_DIR})
    target_link_libraries(main ${PNG_LIBRARY})
endif(LV_USE_LIBPNG)

# ==============================================================================
# 调试配置
# ==============================================================================
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    # 为 LVGL 添加调试编译选项
    target_compile_options(lvgl PRIVATE
        -pedantic-errors
        -Wall
        -Wclobbered
        -Wdeprecated
        -Wdouble-promotion
        -Wempty-body
        -Wextra
        -Wformat-security
        -Wmaybe-uninitialized
        # -Wmissing-prototypes
        -Wpointer-arith
        -Wmultichar
        -Wno-pedantic
        -Wreturn-type
        -Wshadow
        -Wshift-negative-value
        -Wsizeof-pointer-memaccess
        -Wtype-limits
        -Wundef
        -Wuninitialized
        -Wunreachable-code
        -Wfloat-conversion
        -Wstrict-aliasing
    )

    # 在非 Windows 平台使用 sanitizers
    if(NOT WIN32)
        target_compile_options(main PRIVATE -fsanitize=address,leak,undefined)
        target_link_options(main PRIVATE -fsanitize=address,leak,undefined)
    endif()
endif()

