#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "../gs/Request.h"

void testParse()
{
	char* data = NULL;
	Request *request = NULL;

	//data = "GET / HTTP/1.1\r\nHost: localhost:1111\r\nConnection: keep-alive\r\nCache-Control: max-age=0\r\nAccept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8\r\nUser-Agent: Mozilla/5.0 (Windows NT 5.1?AppleWebKit/537.36 (KHTML, like Gecko) Chrome/27.0.1453.110 Safari/537.36\r\nAccept-Encoding: gzip,deflate,sdch\r\nAccept-Language: zh-CN,zh;q=0.8\r\n\r\n";
	/*
	try 
	{
		request = parse(data);
	}
	catch(RequestException e) 
	{
		printf("Request exception occurs! reason: %s", e.getMessage());
	}
	printf("\n");
	*/
	////////////////////////////////////////////////

	//data = "Host: localhost:1111\r\nConnection: keep-alive\r\nCache-Control: max-age=0\r\nAccept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8\r\nUser-Agent: Mozilla/5.0 (Windows NT 5.1?AppleWebKit/537.36 (KHTML, like Gecko) Chrome/27.0.1453.110 Safari/537.36\r\nAccept-Encoding: gzip,deflate,sdch\r\nAccept-Language: zh-CN,zh;q=0.8\r\n\r\n";
	/*
	request = NULL;
	
	try 
	{
		request = parse(data);
	}
	catch(RequestException e) 
	{
		printf("Request exception occurs! reason: %s", e.getMessage());
	}
	printf("\n");
	*/
	////////////////////////////////////////////////

	data = "req:reg\r\nHost: localhost:1111\r\n\r\n";
	request = NULL;
	
	try 
	{
		request = parse(data);
		printf("Request data parse Ok!\n");
	}
	catch(RequestException e) 
	{
		printf("Request exception occurs! reason: %s", e.getMessage());
	}
	printf("\n");
}

void testRequest()
{
	Request * request = new Request("reg");
	request->setParameter("username", "luoxiaoyong");
	request->setParameter("password", "jxcoco1128");

	char* value = request->getParameterValue("password");
	printf("The key %s with value %s\n", "password", value);
	assert (strcmp(value, "jxcoco1128") == 0);

	value = request->getParameterValue("username");
	printf("The key %s with value %s\n", "username", value);
	assert (strcmp(value, "luoxiaoyong") == 0);

	value = request->getParameterValue("nothiskey");
	if (value == NULL) 
	{
		printf("value == NULL");
	}
	/*
	if (strcmp(value, "") == 0) 
	{
		printf("strcmp(value, \"\") == 0");
	}
	*/
	printf("The key %s with value %s\n", "username", value);
	assert (value == NULL);
}
int main(int argc, char* argv[])
{
	testParse();
	//testRequest();
	return 0;
}