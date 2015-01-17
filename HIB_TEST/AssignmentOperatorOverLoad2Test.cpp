#include "stdafx.h"
#include <stdlib.h>
#include <string.h>
#include "TString.h"


int main(int argc, char* argv[])
{
	
	TString s("hello, lxy!");
	s.print();
	printf("s addr: %d\n", &s);

	TString *s2 = new TString("hello, lxy 2!");
	s2->print();

	TString s3(s);
	s3.print();

	TString *s4 = new TString(s);
	s4->print();


	TString s5("hello, lxy 3!");
	s5.print();
	printf("s5 addr: %d\n", &s5);

	s5 = s;
	s5.print();
	printf("s5 addr: %d\n", &s5);
	
	if (s == s5) 
	{
		printf("s equal s5\n");
	}
	else 
	{
		printf("s not equal s5\n");
	}


	//
	//
	char* pPath;
	pPath = getenv ("PATH");
	if (pPath!=NULL)
		printf ("The current path is: %s\n",pPath);


	//
	// 判断系统（CPU）的字节顺序是大头(big-endian)还是小头(little－endian)
	short int a = 0x1234;
	printf("sizeof(a): %d\n", sizeof(a));
    char *p = (char *)&a;
	printf("%s\n", p);
	printf("%#hhx\n", p);
    
    
    printf("p=%#hhx\n",*p);

    if(*p == 0x34)
        printf("Little endian \n");
    else if(*p == 0x12)
        printf("Big endian \n");
    else
        printf("Unknow endian \n");
	return 0;
}

