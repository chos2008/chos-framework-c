#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

int main()
{
	const char* set = "set names ";
	const char* gbk = "gbk";
	int set_len = strlen(set);
	int set_gbk = strlen(gbk);
	int sz = set_len + set_gbk + 1;
	//sz = 1024 * 1024 * 1024;
	//sz = 0;
	char *cs = (char *) malloc(sz);
	memset(cs, 0, sz);
	strcat(cs, set);
	strcat(cs, gbk);
	
	//cs[0] = 'a'; cs[1] = 'b'; cs[2] = 'c';
	//strcat(cs, "gbk");
	printf("%s\n", cs);

	//Sleep(20000);
	
	free(cs);
	printf("free... %s\n", cs == NULL ? "null" : "not null");
	//Sleep(20000);
	
	/*
	// 1
	char *str1 = "abcdef";
	int length = strlen(str1);
	for (int i = 0; i < length; i++) 
	{
		printf("%c", str1[i]);
	}
	printf("\n------------------\n");

	//////////////////////////////////////////////////////////
	// 2
	char *str2 = "abcdefg";
	while (*str2)
	{
		printf("%c", *str2++);
	}
	printf("\n------------------\n");
	//////////////////////////////////////////////////////////

	//////////////////////////////////////////////////////////
	// 3
	
	char *str3 = "abcdefg\0";
	while (*str3)
	{
		printf("%c(%d)", *str3, *str3++);
	}
	printf("\n------------------\n");
	//////////////////////////////////////////////////////////

	//////////////////////////////////////////////////////////
	// 4
	
	char str4[] = {'a', 'b', 'c'};
	int length4 = sizeof(str4) / sizeof(char);
	printf("sizeof(str4): %d, sizeof(char): %d, length4: %d\n", 
		sizeof(str4), sizeof(char), length4);
	for (int i4 = 0; i4 < length4; i4++) 
	{
		printf("%c(%d)", str4[i4], str4[i4]);
	}
	printf("\n------------------\n");
	//////////////////////////////////////////////////////////

	//////////////////////////////////////////////////////////
	// 5
	
	char str5[] = {'a', 'b', 'c', 'd', '\0'};
	int length5 = sizeof(str5) / sizeof(char);
	printf("sizeof(str5): %d, sizeof(char): %d, length5: %d\n", sizeof(str5), sizeof(char), length5);
	for (int i5 = 0; i5 < length5; i5++) 
	{
		printf("%c(%d)", str5[i5], str5[i5]);
	}
	printf("\n------------------\n");
	//////////////////////////////////////////////////////////
  //char d[20]="Golden Global";
  char *d = (char *) malloc(255 * sizeof(char));
  memset(d, 0, 255);

  printf("%d\n", strlen(d));
	//char *d = (char *) malloc(255);;
  char *s=" View";
  //clrscr();
  strcat(d,s);
  printf("%s\n",d);

  
  printf("%d\n", strlen(d));
  //getchar();
	*/

	/*

	char *s = (char *) malloc(6 * sizeof(char));
	memset(s, 0, 6);
	printf("%d\n", sizeof(s));
	printf("%d\n", sizeof(*s));
	printf("%d\n", sizeof(char));
	printf("%d\n", strlen(s));
	printf("%s\n", s);
	for (int i = 0; i < 5; i++) 
	{
		s[i] = 'a';
	}
	printf("%d\n", sizeof(s));
	printf("%d\n", sizeof(*s));
	printf("%d\n", sizeof(char));
	printf("%d\n", strlen(s));
	printf("%s\n", s);

	printf("======================\n");

	char s2[6];
	memset(s2, 0, 6);
	printf("%d\n", sizeof(s2));
	printf("%d\n", sizeof(*s2));
	printf("%d\n", sizeof(char));
	printf("%d\n", strlen(s2));
	printf("%s\n", s2);
	for (i = 0; i < 5; i++) 
	{
		s2[i] = 'a';
	}
	printf("%d\n", sizeof(s2));
	printf("%d\n", sizeof(*s2));
	printf("%d\n", sizeof(char));
	printf("%d\n", strlen(s2));
	printf("%s\n", s2);
	*/
  return 0;
}