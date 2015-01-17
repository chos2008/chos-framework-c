// test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int main(int argc, char* argv[])
{

	printf("Hello World!\n");

	char *str = "abcdef";
	printf("%d\n", &str);
	printf("%s\n", str);
	printf("%d\n", *str);
	//printf("%d\n", str->length);
	printf("%d\n", sizeof(*str));
	printf("%d\n", sizeof(str));

	printf("--------------\n");

	char astr[] = "abcdef";
	printf("%s\n", astr);
	printf("%d\n", *astr);
	//printf("%d\n", str->length);
	printf("%d\n", sizeof(*astr));
	printf("%d\n", sizeof(astr));

	printf("--------------\n");

	int *i = new int(7);
	printf("%d\n", &i);
	printf("%d\n", i);
	printf("%d\n", *i);
	//printf("%d\n", str->length);
	printf("%d\n", sizeof(*i));
	printf("%d\n", sizeof(i));

	return 0;
}

