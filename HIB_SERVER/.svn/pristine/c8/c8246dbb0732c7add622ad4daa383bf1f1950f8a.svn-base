/*
 *
 *
 * @author ada
 * @version 1.0
 * @since 1.0
 */
#include "Request.h"

#ifndef REQUEST_PROCESSOR
#define REQUEST_PROCESSOR 


class RequestProcessor
{
public:
	RequestProcessor();

	void process(char *data);

	Request* parse(char* data) throw(RequestException);

	
	bool completed(char* data);

	char* substring(char* s, int offset, int to);

	std::pair<char*, char*> parseParamPair(char* pair);
};

#endif;