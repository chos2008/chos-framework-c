// test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>

int main(int argc, char* argv[])
{

	char* querystring = getenv("QUERY_STRING");

	printf("Content-type:text/html\n\n");
	printf("<html>");
	printf("<head>");
	printf("<title>Welcome to c cgi.</title>");
	printf("</head>");
	printf("<body>");
	if (querystring != NULL)
		printf(querystring);
	else {
		printf("QUERY_STRING为NULL, 没有提交参数!");
	}
	printf("</body>");
	printf("</html>");

	

	return 0;
}

