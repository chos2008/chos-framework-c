#include "dllexport.h"

#ifndef LOG
#define LOG

// <stdio.h>
// 
// struct _iobuf {
//     char *_ptr;
//     int   _cnt;
//     char *_base;
//     int   _flag;
//     int   _file;
//     int   _charbuf;
//     int   _bufsiz;
//     char *_tmpfname;
// };
//
// typedef struct _iobuf FILE;
// 
// /* Declare _iob[] array */
//
// #ifndef _STDIO_DEFINED
// _CRTIMP extern FILE _iob[];
// 
// #endif  /* _STDIO_DEFINED */
// #define stdin  (&_iob[0])
// #define stdout (&_iob[1])
// #define stderr (&_iob[2])


#ifdef __cplusplus
extern "C" {
#endif

void ap_out();

#ifdef __cplusplus
}
#endif

/**
 * Log level define specifications
 * 
 * Each level specifics the log output level, "FATAL" is the highest level, following 
 * "ERROR", "WARN", "INFO", "DEBUG". "DEBUG" is the lowest level, and usually used for 
 * debuging.
 */
#define LOG_LV_FATAL "FATAL"
#define LOG_LV_ERROR "ERROR"
#define LOG_LV_WARN  "WARN"
#define LOG_LV_INFO  "INFO"
#define LOG_LV_DEBUG "DEBUG"

//#define FATAL LOG_LV_FATAL
//#define ERROR LOG_LV_ERROR
//#define WARN  LOG_LV_WARN
//#define INFO  LOG_LV_INFO
//#define DEBUG LOG_LV_DEBUG

/*
 *
 */
__extern_c __declspec_dllexport char* __dateformat(const char* format);

/*
 *
 */
__extern_c __declspec_dllexport char* dateformat();

__extern_c void log_prefix_format(const char* level);


__extern_c void __return(int _return);


__extern_c void auto_return();


/*
 *
 */
__extern_c __declspec_dllexport char* logdate();


/*
 *
 */
__extern_c __declspec_dllexport void log(const char* level, const char* log);

__extern_c __declspec_dllexport void __log(const char* level, const char * fmt, ...);

/*
 *
 */
__extern_c __declspec_dllexport void logdebug(const char* debug);

__extern_c __declspec_dllexport void debug(const char *fmt, ...);

/*
 *
 */
__extern_c __declspec_dllexport void loginfo(const char* info);

__extern_c __declspec_dllexport void info(const char *fmt, ...);

/*
 *
 */
__extern_c __declspec_dllexport void logwarn(const char* warn);

__extern_c __declspec_dllexport void warn(const char *fmt, ...);

/*
 *
 */
__extern_c __declspec_dllexport void logerror(const char* error);

__extern_c __declspec_dllexport void error(const char *fmt, ...);

/*
 *
 */
__extern_c __declspec_dllexport void logfatal(const char* fatal);

__extern_c __declspec_dllexport void fatal(const char *fmt, ...);

#endif