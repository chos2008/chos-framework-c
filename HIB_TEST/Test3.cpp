#include <stdio.h>
#include <stdlib.h>
#include <string.h>

class Base
{
public:
	Base() 
	{
		printf("Base\n");
		x = 1;
	}

	int x;
};

class Sub3 : public Base 
{
public:
	Sub3() 
	{
		printf("Sub3\n");
		x = 2;
	}
	int x;
};

void getMem2(void *s)
{
	s = (void *) malloc(100);
}

char * getMem()
{
	char v2[100]={'a','b','c',0};
	return v2;
}

void main()
{
	char ss[] = "abcde";
	printf("%d\n", sizeof(ss));

	char *str2 = NULL;
	getMem2(str2);
	//strcpy(str2, "abc");

	char *str = getMem();
	printf("%s\n", str);

	Base *s = new Sub3;

	Sub3 sub;

	Base &b = sub;

	printf("%d, %d, %d\n", sub.x, sizeof(sub), sizeof(b));
}
