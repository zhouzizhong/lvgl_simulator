# 设置 CMake 版本和项目名
cmake_minimum_required(VERSION 3.16)
project(lvglui VERSION 1.0)
# 设置 C/C++ 标准
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 14)
# 设置输出目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
set(LIB_OUTPUT_DIR ${PROJECT_SOURCE_DIR}/lib)
# 外部依赖查找
find_package(SDL2 REQUIRED SDL2)

# 添加包含目录
include_directories(${PROJECT_SOURCE_DIR})
include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR}/custom)
include_directories(${PROJECT_SOURCE_DIR}/generated)
include_directories(${PROJECT_SOURCE_DIR}/third_party)

# 禁用 LVGL 不需要的组件
set(LV_CONF_BUILD_DISABLE_EXAMPLES ON CACHE BOOL "Disable LVGL examples" FORCE)
set(LV_CONF_BUILD_DISABLE_DEMOS ON CACHE BOOL "Disable LVGL demos" FORCE)
set(LV_CONF_BUILD_DISABLE_THORVG_INTERNAL ON CACHE BOOL "Disable LVGL ThorVG" FORCE)

# 第三方库配置
add_subdirectory(third_party/id3v2lib-dev)
add_subdirectory(third_party/lvgl)

# 收集所有源文件（排除第三方库和测试文件）
file(GLOB_RECURSE SRC_DIRS
    ${PROJECT_SOURCE_DIR}/*.c
    ${PROJECT_SOURCE_DIR}/src/**/*.c
    ${PROJECT_SOURCE_DIR}/custom/*.c
    ${PROJECT_SOURCE_DIR}/custom/**/*.c
    ${PROJECT_SOURCE_DIR}/generated/*.c
    ${PROJECT_SOURCE_DIR}/generated/**/*.c
)
# 排除不需要的文件
list(FILTER SRC_DIRS EXCLUDE REGEX "third_party/.*test.*")
list(FILTER SRC_DIRS EXCLUDE REGEX ".*CMakeFiles.*CompilerId.*")
# 创建可执行文件
add_executable(main ${SRC_DIRS})

# 链接可执行文件依赖
target_link_libraries(main PRIVATE
    id3v2lib
    lvgl
    ${SDL2_LIBRARIES}
    pthread
    ws2_32
    m
)

# 自定义目标
add_custom_target(run COMMAND ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/main DEPENDS main)

# 确保生成控制台应用程序（Windows）
if(WIN32)
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -mconsole")
endif()