/**
 * @file main.c
 * @brief 主入口文件，链接动态库并启动 LVGL UI 应用程序
 */
/*********************  INCLUDES  *********************/
#include "lvglui.h"
#include <stdio.h>

/*********************  MAIN FUNCTION  *********************/

/**
 * @brief 主函数
 * @param argc 命令行参数数量
 * @param argv 命令行参数数组
 * @return 程序退出状态
 */
int main(int argc, char** argv)
{
    printf("=== LVGL UI Application ===\n");
    printf("Starting application...\n");
    
    // 调用 LVGL UI 初始化函数
    int result = lvglui_init(argc, argv);
    
    printf("Application exited with code: %d\n", result);
    
    return result;
}
