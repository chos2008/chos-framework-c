#include <stdio.h>
#include "Appender.hpp"
#include "FileAppender.hpp"


FileAppender::FileAppender(const char *dest)
{
	FILE* appender = fopen(dest, "r");

    if (appender)
    {
		
    }
	this->appender = appender;
}

FileAppender::FileAppender(FILE *appender) : Appender(appender)
{
	
}

void FileAppender::log(const char *level, const char *log, ...)
{
	
}

void FileAppender::debug(const char *log, ...)
{

}

void FileAppender::info(const char *log, ...)
{

}

void FileAppender::warn(const char *log, ...)
{

}

void FileAppender::error(const char *log, ...)
{

}

void FileAppender::fatal(const char *log, ...)
{

}