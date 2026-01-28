// src/utils/log.c
#include "log.h"

// 日志级别名称
static const char* log_level_names[] = {
    "OFF",
    "ERROR",
    "WARN",
    "INFO",
    "DEBUG"
};

// 日志输出函数
void log_printf(log_level_t level, const char* file, int line, const char* format, ...)
{
    // 检查日志级别
    if (level > LOG_LEVEL) {
        return;
    }

    // 输出日志前缀（包含级别、文件和行号）
    printf("[%s] %s:%d: ", log_level_names[level], file, line);

    // 输出日志内容
    va_list args;
    va_start(args, format);
    vprintf(format, args);
    va_end(args);

    // 输出换行符
    printf("\n");
}
