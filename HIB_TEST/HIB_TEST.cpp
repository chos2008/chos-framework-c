// HIB_TEST.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char* argv[])
{
	printf("Hello World!\n");

	char* strings[] = {"vc.ext", "-server", "--user", "--password", "-host", "--port", "3306", "123"};
	printf("%s\n", strings);
	//printf("%d\n", *strings);
	printf("%d\n", sizeof(strings));
	printf("%d\n", sizeof(*strings));
	//printf("%d\n", strlen(strings));

	printf("-------------------------------\n");


	char st[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g'};
	printf("%s\n", st);
	printf("%d\n", *st);
	printf("%d\n", sizeof(st));
	printf("%d\n", sizeof(*st));
	printf("%d\n", strlen(st));

	printf("-------------------------------\n");

	char *str = "abcdefghijklmn";
	printf("%s\n", str);
	printf("%d\n", *str);
	printf("%d\n", sizeof(str));
	printf("%d\n", sizeof(*str));
	printf("%d\n", strlen(str));

	
	

	printf("-------------------------------\n");
	char *strt = (char *) malloc(sizeof(char) * strlen(str));
	strcpy(strt, str);
	printf("%s\n", strt);
	printf("%d\n", *str);
	printf("%d\n", sizeof(strt));
	printf("%d\n", sizeof(*strt));
	printf("%d\n", strlen(strt));


	printf("-------------------------------\n");
	strt[0] = 'A';
	printf("%s\n", strt);
	printf("%d\n", *strt);
	printf("%d\n", sizeof(strt));
	printf("%d\n", sizeof(*strt));
	printf("%d\n", strlen(strt));

	return 0;
}

