#include <windows.h>
#include "log.h"
/*
 *
 *
 * @author ada
 * @version 1.0
 * @since 1.0
 */
#include "Request.h"
#include "RequestProcessor.h"
#include "../net/DataBufferQueue.h"

RequestProcessor::RequestProcessor()
{

}

void RequestProcessor::process(char *data)
{
	//Request *request = new Request("aaaa");
	
	Request *request = NULL;
	try 
	{
		request = parse(data);
	}
	catch (RequestException e)
	{
		printf("%s\n", e.getMessage());
		return;
	}
	
	printf("Success to parse request data...\n");
	printf("%s\n", data);
}

Request* RequestProcessor::parse(char* data) throw(RequestException)
{
	if (! completed(data)) 
	{
		throw RequestException("Illegal request data, a complete request data Must be end with \"\\r\\n\\r\\n\"");
	}

	int length = strlen(data);
	char* temp = data;
	data = (char *) malloc(length);
	memset(data, 0, length);
	memcpy(data, temp, length);
	
	data[length - 1] = '\0';
	data[length - 2] = '\0';
	data[length - 3] = '\0';
	data[length - 4] = '\0';

	std::map<char*, char*> paramMap;
	DataBufferQueue queue;
	while(*data) 
	{
		if (! queue.isEmpty() && queue.element(queue.size_of() - 1) == '\r' && *data == '\n') 
		{
			queue.remove(queue.size_of() - 1);
			*data++;
			char* pair = queue.toString();
			
			std::pair<char*, char*> p = parseParamPair(pair);	
			paramMap.insert (p);
			queue.clear();
		}
		queue.enqueue(*data++);
	}

	char* pair = queue.toString();
			
	std::pair<char*, char*> p = parseParamPair(pair);	
	paramMap.insert (p);
	queue.clear();

	//paramMap.insert (std::pair<char*, char*>("req", "abc"));

	char *req = "req";
	std::map<char*, char*>::iterator it 
		= paramMap.find(req);
	if (it == paramMap.end())
	{
		throw RequestException("Illegal request data, no parameter req!");
	}
	Request* request = new Request(it->second);
	for (it = paramMap.begin(); it != paramMap.end(); ++it)
	{
		if (strcmp(it->first, "req") != 0) 
		{
			request->setParameter(it->first, it->second);
		}
	}
	return request;
}


bool RequestProcessor::completed(char* data)
{
	int length = strlen(data);
	if (length >= 4) 
	{
		return (
		data[length - 4] == '\r' &&
		data[length - 3] == '\n' &&
		data[length - 2] == '\r' &&
		data[length - 1] == '\n' );
	}

	return false;
}

char* RequestProcessor::substring(char* s, int offset, int to)
{
	if (s == NULL) 
	{
		return NULL;
	}
	if (offset > to) 
	{
		return NULL;
	}
	int length = strlen(s);
	if (to >= length) 
	{
		return NULL;
	}
	int size = to - offset + 1;
	char *sub = (char *) malloc(size + 1);
	memset(sub, 0, size);
	sub[size] = '\0';
	char *p = sub;
	
	for (int i = offset; i <= to; i++) 
	{
		*sub = s[i];
		*sub++;
	}
	return p;
}

std::pair<char*, char*> RequestProcessor::parseParamPair(char* pair)
{
	if (pair != NULL) 
	{
		int i = 0;
		int length = strlen(pair);
		for (int ii = 0; ii < length; ii++)
		{
			if (pair[ii] == ':')
			{
				i = ii;
			}
		}
		if (i < 1) 
		{

			throw RequestException("Illegal request data, a illegal K/V pair found!");
		}
		
		char *key = substring(pair, 0, i - 1);
		char *value = substring(pair, i + 1, length - 1);
		if (key == NULL) 
		{
			throw RequestException();
		}
		if (strcmp(key, "req") == 0) 
		{
			key = "req";
		}
		return std::pair<char*, char*>(key, value);
	}
}
