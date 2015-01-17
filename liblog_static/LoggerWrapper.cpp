#include "LoggerWrapper.hpp"
#include "StandardAppender.hpp"

LoggerWrapper::LoggerWrapper()
{
    this->appender = new StandardAppender();
}

LoggerWrapper::~LoggerWrapper()
{

}

void LoggerWrapper::log(const char *level, const char *log, ...)
{
	
}

void LoggerWrapper::debug(const char *log, ...)
{

}

void LoggerWrapper::info(const char *log, ...)
{

}

void LoggerWrapper::warn(const char *log, ...)
{

}

void LoggerWrapper::error(const char *log, ...)
{

}

void LoggerWrapper::fatal(const char *log, ...)
{

}
