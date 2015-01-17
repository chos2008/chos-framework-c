#include <stdarg.h>
#include "StandardAppender.hpp"


void StandardAppender::log(const char *level, const char *log, ...)
{
	va_list argp;

	log_prefix_format(level);
	
	va_start(argp, log);
	vfprintf(this->appender, log, argp);
	va_end(argp);

	auto_return();
}

void StandardAppender::debug(const char *log, ...)
{
	va_list argp;

	log_prefix_format(LOG_LV_DEBUG);
	
	va_start(argp, log);
	vfprintf(this->appender, log, argp);
	va_end(argp);

	auto_return();
}

void StandardAppender::info(const char *log, ...)
{
	va_list argp;

	log_prefix_format(LOG_LV_INFO);
	
	va_start(argp, log);
	vfprintf(this->appender, log, argp);
	va_end(argp);

	auto_return();
}

void StandardAppender::warn(const char *log, ...)
{
	va_list argp;

	log_prefix_format(LOG_LV_WARN);

	va_start(argp, log);
	vfprintf(this->appender, log, argp);
	va_end(argp);

	auto_return();
}

void StandardAppender::error(const char *log, ...)
{
	va_list argp;

	log_prefix_format(LOG_LV_ERROR);

	va_start(argp, log);
	vfprintf(this->appender, log, argp);
	va_end(argp);

	auto_return();
}

void StandardAppender::fatal(const char *log, ...)
{
	va_list argp;

	log_prefix_format(LOG_LV_FATAL);
	
	va_start(argp, log);
	vfprintf(this->appender, log, argp);
	va_end(argp);

	auto_return();
}