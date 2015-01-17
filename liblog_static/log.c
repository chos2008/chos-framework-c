/*
 * log 
 *
 * @author ada
 * @version 1.0
 * @since 1.0
 */
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>

#include "log.h"

void ap_out()
{

}



char* __dateformat(const char* format) 
{
	/**
	 * typedef long time_t;        // time value
	 */
	time_t t;

	/**
	 * #ifndef _TM_DEFINED
     * struct tm {
     *     int tm_sec;     // seconds after the minute - [0,59] 
     *     int tm_min;     // minutes after the hour - [0,59] 
     *     int tm_hour;    // hours since midnight - [0,23] 
     *     int tm_mday;    // day of the month - [1,31] 
     *     int tm_mon;     // months since January - [0,11] 
     *     int tm_year;    // years since 1900 
     *     int tm_wday;    // days since Sunday - [0,6] 
     *     int tm_yday;    // days since January 1 - [0,365] 
     *     int tm_isdst;   // daylight savings time flag 
     * };
     * #define _TM_DEFINED
     * #endif
	 */
	struct tm* tt;
	char* ptr;

	time(&t);

	/**
	 * struct tm *localtime(
     *     const time_t *timer 
     * );
	 */
	tt = localtime(&t);
	ptr = (char *) malloc(20 * sizeof(char));
	strftime(ptr, 20, format, tt);
	return ptr;
}

char* dateformat() 
{
	return __dateformat("%Y-%m-%d %I:%M:%S");
}


void log_prefix_format(const char* level) 
{
    time_t t;
	struct tm* tt;
	int t_year, t_mon, t_date, t_hour, t_min, t_sec;
	
	time(&t);
	tt = localtime(&t);
	t_year = tt->tm_year + 1900;
	t_mon = tt->tm_mon + 1;
	t_date = tt->tm_mday;
	t_hour = tt->tm_hour;
	t_min = tt->tm_min;
	t_sec = tt->tm_sec;

	fprintf(stdout, "[%s] %04d-%02d-%02d %02d:%02d:%02d ", level, 
		t_year, t_mon, t_date, t_hour, t_min, t_sec);
}


void __return(int _return) 
{
    if (_return) 
	{
	    fprintf(stdout, "\n");
	}
	fflush(stdout);
}


void auto_return() 
{
    __return(1);
}

char* logdate() 
{
	return dateformat();
}

void log(const char* level, const char* log) 
{
	char * dateformat = logdate();
	printf("[%s] %s %s\n", level, dateformat, log);
	free(dateformat);
}

void __log(const char* level, const char * fmt, ...) 
{
	va_list argp;

	log_prefix_format(level);
	
	va_start(argp, fmt);
	vfprintf(stdout, fmt, argp);
	va_end(argp);

	auto_return();
}

void logdebug(const char* debug) 
{
	log(LOG_LV_DEBUG, debug);
}

void debug(const char *fmt, ...) 
{
	va_list argp;

	log_prefix_format(LOG_LV_DEBUG);
	
	va_start(argp, fmt);
	vfprintf(stdout, fmt, argp);
	va_end(argp);

	auto_return();
}

void loginfo(const char* info) 
{
	log(LOG_LV_INFO, info);
}

void info(const char *fmt, ...) 
{
	va_list argp;

	log_prefix_format(LOG_LV_INFO);
	
	va_start(argp, fmt);
	vfprintf(stdout, fmt, argp);
	va_end(argp);

	auto_return();
}

void logwarn(const char* warn) 
{
	log(LOG_LV_WARN, warn);
}

void warn(const char *fmt, ...)
{
	va_list argp;

	log_prefix_format(LOG_LV_WARN);

	va_start(argp, fmt);
	vfprintf(stdout, fmt, argp);
	va_end(argp);

	auto_return();
}

void logerror(const char* error) 
{
	log(LOG_LV_ERROR, error);
}

void error(const char *fmt, ...) 
{
	va_list argp;

	log_prefix_format(LOG_LV_ERROR);

	va_start(argp, fmt);
	vfprintf(stdout, fmt, argp);
	va_end(argp);

	auto_return();
}

void logfatal(const char* fatal) 
{
	log(LOG_LV_FATAL, fatal);
}

void fatal(const char *fmt, ...) 
{
	va_list argp;

	log_prefix_format(LOG_LV_FATAL);
	
	va_start(argp, fmt);
	vfprintf(stdout, fmt, argp);
	va_end(argp);

	auto_return();
}