#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "../net/DataBufferQueue.h"

void testStrcmp()
{
	char *s1 = NULL;
	char *s2 = NULL;

	s1 = (char *) malloc(100 * sizeof(char));
	s2 = (char *) malloc(100 * sizeof(char));
	printf("%ld %s\n", &s1, s1);
	printf("%ld %s\n", &s2, s2);
	assert(strcmp(s1, s2) != 0);

	*s1 = 'a';
	*s2 = 'a';
	printf("%ld %s\n", &s1, s1);
	printf("%ld %s\n", &s2, s2);
	assert(strcmp(s1, s2) != 0);


	
	s1 = (char *) malloc(100 * sizeof(char));
	memset(s1, 0, 100 * sizeof(char));
	s2 = (char *) malloc(100 * sizeof(char));
	memset(s2, 0, 100 * sizeof(char));
	
	printf("%ld %s\n", &s1, s1);
	printf("%ld %s\n", &s2, s2);
	assert(strcmp(s1, s2) == 0);
	
	
	
	*s1 = 'a';
	*s2 = 'a';
	
	printf("%ld %s\n", &s1, s1);
	printf("%ld %s\n", &s2, s2);
	assert(strcmp(s1, s2) == 0);
	

	
	s1 = (char *) malloc(4 * sizeof(char));
	memset(s1, 0, 4 * sizeof(char));
	char *p = s1;
	*p = 'a';
	p++;
	*p = 'a';
	p++;
	*p = 'a';
	s2 = "aaa";
	printf("%ld %s\n", &s1, s1);
	printf("%ld %s\n", &s2, s2);
	assert(strcmp(s1, s2) == 0);
}

void main() 
{
	//testStrcmp();

	
	char *str = NULL;
	assert(str == NULL);
	
	
	DataBufferQueue *dataBuffer = new DataBufferQueue();
	printf("%s\n", dataBuffer->toString());
	assert(dataBuffer->toString() == NULL);

	str = "abcdefg";
	dataBuffer->enqueue(str);
	printf("%s\n", dataBuffer->toString());
	assert(strcmp("abcdefg", "abcdefg") == 0);
	assert(strcmp(dataBuffer->toString(), str) == 0);

	dataBuffer->clear();
	printf("%s\n", dataBuffer->toString());
	assert(dataBuffer->toString() == NULL);

	str = "GET / HTTP/1.1\r\nHost: localhost:1111\r\nConnection: keep-alive\r\nCache-Control: max-age=0\r\nAccept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8\r\nUser-Agent: Mozilla/5.0 (Windows NT 5.1) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/27.0.1453.110 Safari/537.36\r\nAccept-Encoding: gzip,deflate,sdch\r\nAccept-Language: zh-CN,zh;q=0.8\r\n\r\n";
	dataBuffer->enqueue(str);
	printf("%s\n", dataBuffer->toString());
	assert(strcmp(dataBuffer->toString(), str) == 0);
}