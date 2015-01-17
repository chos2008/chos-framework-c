#include <stdio.h>
#include <string.h>
#include <windows.h>
#pragma comment(lib,"ws2_32")

void testPoint()
{
	printf("sizeof(char): %d\n", sizeof(char));
	printf("sizeof(long): %d\n", sizeof(long));

	char *p1 = NULL;
	long *p2 = NULL;

	p1 = (char *) 0x8000;
	p2 = (long *) 0x8000;

	printf("%ld(0x%x) %ld(0x%x) %ld(0x%x)\n", 
		0x8000, 0x8000, p1, p1, p1 + 5, p1 + 5);
	printf("%ld(0x%x) %ld(0x%x) %ld(0x%x)\n", 
		0x8000, 0x8000, p2, p2, p2 + 5, p2 + 5);
	
	//*p1 = 'a';  ERROR, NOT WRITE
	//*p2 = 12345L;  ERROR, NOT WRITE
	//printf("*p1: %c\n", *p1);  ERROR, NOT READ
	//printf("*p2: %ld\n", *p2);  ERROR, NOT READ

	char a[10] = {'a', '1', 'a', '1', 'a', '1'};
	const char* s = a;
	printf("s : %s\n", s);
	//*s = '1'; // error C2166: l-value specifies const object
	//printf("s : %s\n", s);

	//s[0] = '1'; // error C2166: l-value specifies const object


	s++;
	printf("s : %s\n", s);

}

void testhtons()
{
	char s[8];
	memset(s, 0, sizeof(s));
	unsigned short command = 245;
	command = htons(command);
	char *p = s;
	memcpy(p, &command, sizeof(command));
	printf("%s\n", s);
	
}

void testprintf()
{
	int char_t = printf("%d", 1);
	printf("print %d chars\n", char_t);

	char_t = printf("%d", 1234);
	printf("print %d chars\n", char_t);

	int bytes = fprintf(stderr, "%d", 1);
	printf("print %d bytes\n", bytes);

	bytes = fprintf(stderr, "%d", 1234);
	printf("print %d bytes\n", bytes);

}

void main()
{
	char *s = "abcdefg\0hijklmn";
	printf("%s, length: %d\n", s, strlen(s));

	s = "abcdefghijklmn";
	printf("%s, length: %d\n", s, strlen(s));

	s = "abcdefghijklmn\0";
	printf("%s, length: %d\n", s, strlen(s));


	
}