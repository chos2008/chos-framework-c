#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include <log.h>

void testfread() 
{
	const char *file = "D:\\home\\admin\\workstation\\c\\HIB_SERVER\\data\\data.xml";
	/**
	 *
	 * r, w, a, rb, wb, ab, r+, w+, a+, rb+, wb+, ab+
	 */
	FILE *fp = fopen(file, "r");
	if (! fp) 
	{
		error("fail to open file %s", file);
		return;
	}

	int bytes = 128 * sizeof(char);
	char *rb = (char *) malloc(bytes);
	memset(rb, 0, bytes);
	int i = 0;
	while (i < 20) 
	{
		unsigned int b = fread(rb, bytes, 1, fp);
		printf("%s\n\t%d\n", rb, b);
		memset(rb, 0, bytes);
		i++;
	}
}

void testfgets()
{
	const char *file = "D:\\home\\admin\\workstation\\c\\HIB_SERVER\\data\\bb.xml";
	const char *file_to = "D:\\home\\admin\\workstation\\c\\HIB_SERVER\\data\\data.tmp.xml";
	/**
	 *
	 * r, w, a, rb, wb, ab, r+, w+, a+, rb+, wb+, ab+
	 */
	FILE *fp = fopen(file, "r");
	if (! fp) 
	{
		error("fail to open file %s", file);
		return;
	}
	FILE *fp_to = fopen(file_to, "w");

	int size = 128;
	int bytes = size * sizeof(wchar_t);
	printf("128 * sizeof(wchar_t): %d\n", bytes);
	wchar_t rb[128];//*rb = (char *) malloc(bytes);
	//memset(rb, 0, bytes);

	setlocale(LC_ALL, "chs");
	while (fgetws(rb, size, fp) != NULL) 
	{
		//printf("%s", rb);
		
		wprintf(L"%ls", rb);
		fputws(rb, fp_to);
		//memset(rb, 0, bytes);
	}

	printf("%s\n", "中文");
	printf("%ls\n", L"中文");
}

void main()
{
	testfgets();

	/*
	char *s = "abcdef";
	int len = strlen(s);
	printf("%s     %dbytes\n", s, len + 1);

	char s1[] = "abcdef";
	printf("%s     %dbytes\n", s, sizeof(s1));

	setlocale(LC_ALL, "chs");
	wchar_t *s2 = L"我是中国人";
	//len = strlen(s2);
	wprintf(L"%ls     %dbytes\n", s2, len + 1);

	wchar_t s3[5];
	s3[0] = L'我'; s3[1] = L'是'; s3[2] = L'美'; s3[3] = L'国'; s3[4] = L'人';
	wprintf(L"%ls     %dbytes\n", s3, len + 1);

	//*/

}