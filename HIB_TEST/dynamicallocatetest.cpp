#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>
#include <windows.h>

char* __dateformat(const char* format) 
{
	/**
	 * typedef long time_t;        // time value
	 */
	time_t t;
	time(&t);

	/**
	 * struct tm *localtime(
     *     const time_t *timer 
     * );
	 *
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
	tm* tt = localtime(&t);
	char *ptr = new char[20]; // (char *) malloc(20 * sizeof(char)); // 这里不能使用 char ptr[20]; 
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
	time(&t);

	tm* tt = localtime(&t);
	int t_year = tt->tm_year + 1900;
	int t_mon = tt->tm_mon + 1;
	int t_date = tt->tm_mday;
	int t_hour = tt->tm_hour;
	int t_min = tt->tm_min;
	int t_sec = tt->tm_sec;

	fprintf(stderr, "[%s] %04d-%02d-%02d %02d:%02d:%02d ", level, 
		t_year, t_mon, t_date, t_hour, t_min, t_sec);
}


void __return(int _return) 
{
    if (_return) 
	{
	    fprintf(stderr, "\n");
	}
	fflush(stderr);
}


void auto_return() 
{
    __return(1);
}

void __log(const char* level, const char * fmt, ...) 
{
	log_prefix_format(level);

	va_list argp;
	va_start(argp, fmt);
	vfprintf(stderr, fmt, argp);
	va_end(argp);

	auto_return();
	
}

void warn(const char *fmt, ...)
{
	time_t t;
	time(&t);

	va_list argp;

	va_start(argp, fmt);

	tm* tt = localtime(&t);
	int t_year = tt->tm_year + 1900;
	int t_mon = tt->tm_mon + 1;
	int t_date = tt->tm_mday;
	int t_hour = tt->tm_hour;
	int t_min = tt->tm_min;
	int t_sec = tt->tm_sec;

	fprintf(stderr, "[WARN] %04d-%02d-%02d %02d:%02d:%02d ",
		t_year, t_mon, t_date, t_hour, t_min, t_sec);
	vfprintf(stderr, fmt, argp);
	fprintf(stderr, "\n");
	fflush(stderr);
	va_end(argp);
}


void error(const char *fmt, ...) 
{
	log_prefix_format("ERROR");

	va_list argp;
	va_start(argp, fmt);
	vfprintf(stderr, fmt, argp);
	va_end(argp);

	auto_return();
}

void main() 
{
	while (1) 
	{
		char *df = dateformat();
		printf("%s\n", df);
		free(df);
		
		//Sleep(1000);
	}

	//warn("Hello %s, this is %s", "ada", "luo, xiaoyong");
	//error("Hello %s, this is %s", "ada", "luo, xiaoyong");
}