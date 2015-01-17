#include <stdio.h>

struct _struct
{
	char c;
	short sts;
};

struct xx{
        char b;
        int a;
        int c;
        char d;
};

struct _xx{
        char b; 
        char d;
        int a;          
        int c;                  
};

int main()
{
	printf("sizeof(struct _struct): %d\n", sizeof(struct _struct));
	printf("sizeof(struct xx): %d\n", sizeof(struct xx));
	printf("sizeof(struct _xx): %d\n", sizeof(struct _xx));
	printf("sizeof(int): %d\n", sizeof(int));
	return 0;
}