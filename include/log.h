// include/log.h
#ifndef __LOG_H__
#define __LOG_H__

#include <stdio.h>
#include <stdarg.h>

// 日志级别定义
typedef enum {
    LOG_LEVEL_OFF = 0,    // 关闭所有日志
    LOG_LEVEL_ERROR,      // 只显示错误信息
    LOG_LEVEL_WARN,       // 显示警告和错误信息
    LOG_LEVEL_INFO,       // 显示信息、警告和错误信息
    LOG_LEVEL_DEBUG       // 显示所有日志（包括调试信息）
} log_level_t;

// 日志配置
// 可以通过修改这个宏来控制全局日志级别
#define LOG_LEVEL LOG_LEVEL_DEBUG

// 日志输出函数
void log_printf(log_level_t level, const char* file, int line, const char* format, ...);

// 日志宏定义
#if LOG_LEVEL >= LOG_LEVEL_DEBUG
#define LOG_DEBUG(format, ...) log_printf(LOG_LEVEL_DEBUG, __FILE__, __LINE__, format, ##__VA_ARGS__)
#else
#define LOG_DEBUG(format, ...)
#endif

#if LOG_LEVEL >= LOG_LEVEL_INFO
#define LOG_INFO(format, ...) log_printf(LOG_LEVEL_INFO, __FILE__, __LINE__, format, ##__VA_ARGS__)
#else
#define LOG_INFO(format, ...)
#endif

#if LOG_LEVEL >= LOG_LEVEL_WARN
#define LOG_WARN(format, ...) log_printf(LOG_LEVEL_WARN, __FILE__, __LINE__, format, ##__VA_ARGS__)
#else
#define LOG_WARN(format, ...)
#endif

#if LOG_LEVEL >= LOG_LEVEL_ERROR
#define LOG_ERROR(format, ...) log_printf(LOG_LEVEL_ERROR, __FILE__, __LINE__, format, ##__VA_ARGS__)
#else
#define LOG_ERROR(format, ...)
#endif

#endif /* __LOG_H__ */
