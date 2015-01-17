#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

void testmemcpy()
{
	/*
	char *s1 = "abcdefg1234567";
	char st1[100];
	strcpy(st1, s1);
	printf("s1 string %s, st1 string %s\n", s1, st1);

	char *s2 = "abcdefg1234567\0";
	char st2[100];
	strcpy(st2, s2);
	printf("s2 string %s, st2 string %s\n", s2, st2);
	
	char *s3 = "abcdefg\0\1234567";
	char st3[100];
	strcpy(st3, s3);
	printf("s3 string %s, st3 string %s\n", s3, st3);
	
	char *s4 = "\0abcdefg1234567";
	char st4[100];
	strcpy(st2, s2);
	printf("s4 string %s, st4 string %s\n", s4, st4);

	//*/
	char sa1[] = {'a', 'b', 'c', 'd', 'e', '1', '2', '3', '4', '5'};
	char sat1[100];
	memset(sat1, 0, sizeof(sat1));
	memcpy(sat1, sa1, sizeof(sa1));
	printf("sizeof sa1 %d, sizeof sat1 %d\n", sizeof(sa1), sizeof(sat1));
	printf("sa1 string %s, sat1 string %s\n", sa1, sat1);

	printf("--------------\n");
}

char* _strcpy(char *dest, const char *src)
{
	assert(src != NULL);
	assert(dest != NULL);
	char *pt = dest, *p = (char *) src;
	while (*p) 
	{
		*pt = *p;
		p++;
		pt++;
	}
	*pt = '\0';
	return dest;
}

void test_strcpy()
{
	/*
	char *s1 = "abcdefg1234567";
	char st1[100];
	_strcpy(st1, s1);
	printf("s1 string %s, st1 string %s\n", s1, st1);

	char *s2 = "abcdefg1234567\0";
	char st2[100];
	_strcpy(st2, s2);
	printf("s2 string %s, st2 string %s\n", s2, st2);
	
	char *s3 = "abcdefg\0\1234567";
	char st3[100];
	_strcpy(st3, s3);
	printf("s3 string %s, st3 string %s\n", s3, st3);
	//*/
	/*
	char *s4 = "\0abcdefg1234567";
	char st4[100];
	_strcpy(st4, s4);
	printf("s4 string %s, st4 string %s\n", s4, st4);

	//*/
	///*
	char sa1[] = {'a', 'b', 'c', 'd', 'e', '1', '2', '3', '4', '5'};
	char sat1[100];
	_strcpy(sat1, sa1);
	printf("sizeof sa1 %d, sizeof sat1 %d\n", sizeof(sa1), sizeof(sat1));
	printf("sa1 string %s, sat1 string %s\n", sa1, sat1);
	//*/
	printf("--------------\n");
}

void teststrcpy()
{
	/*
	char *s1 = "abcdefg1234567";
	char st1[100];
	strcpy(st1, s1);
	printf("s1 string %s, st1 string %s\n", s1, st1);

	char *s2 = "abcdefg1234567\0";
	char st2[100];
	strcpy(st2, s2);
	printf("s2 string %s, st2 string %s\n", s2, st2);
	
	char *s3 = "abcdefg\0\1234567";
	char st3[100];
	strcpy(st3, s3);
	printf("s3 string %s, st3 string %s\n", s3, st3);
	
	char *s4 = "\0abcdefg1234567";
	char st4[100];
	strcpy(st4, s4);
	printf("s4 string %s, st4 string %s\n", s4, st4);

	//*/
	char sa1[] = {'a', 'b', 'c', 'd', 'e', '1', '2', '3', '4', '5'};
	char sat1[100];
	strcpy(sat1, sa1);
	printf("sizeof sa1 %d, sizeof sat1 %d\n", sizeof(sa1), sizeof(sat1));
	printf("sa1 string %s, sat1 string %s\n", sa1, sat1);

	printf("--------------\n");
}

void test() 
{
	printf("Content-type:text/html\n\n");
	printf("<html>");
	printf("<head>");
	printf("<title>Welcome to c cgi.</title>");
	printf("</head>");
	printf("<body>");
	printf("ÄãºÃ, ÊÀ½ç</br>");
	printf("Hello, World!</br>");
	printf("</body>");
	printf("</html>");
}

int main(int argc, char* argv[])
{
	//teststrcpy();
	//test_strcpy();
	//testmemcpy();

	char *s = "1234";
	int i = atoi(s);
	printf("s %s, i %d\n", s, i);

	s = "1234567890987654321";
	i = atoi(s);
	printf("s %s, i %d\n", s, i);

	s = "1234567890";
	i = atoi(s);
	printf("s %s, i %d\n", s, i);

	s = "-1234";
	i = atoi(s);
	printf("s %s, i %d\n", s, i);

	s = "0";
	i = atoi(s);
	printf("s %s, i %d\n", s, i);
	
	s = "";
	i = atoi(s);
	printf("s %s, i %d\n", s, i);
	
	s = "a";
	i = atoi(s);
	printf("s %s, i %d\n", s, i);
	
	s = "abcdefg";
	i = atoi(s);
	printf("s %s, i %d\n", s, i);

	i = 12345;
	s = new char[4];//(char *) malloc(sizeof(int));
	itoa(i, s, 10);
	printf("s %s, i %d\n", s, i);

	i = 1234567890;
	char ss[4];//(char *) malloc(sizeof(int));
	itoa(i, ss, 10);
	printf("s %s, i %d, sizeof(int) %d, sizeof(ss) %d, strlen(ss) %d\n", 
		ss, i, 
		sizeof(int), sizeof(ss), strlen(ss));
	
	char *p;
	//free(p);
	p = ss;
	//free(p);

	printf("\\0%c(%d),\/0%c(%d)\n", '\0', '\0', '/0', '/0');
	return 0;
}

