#include <stdio.h>

int main()
{
#ifdef __CYG_WIN
	printf("__CYG_WIN defined\n");
#else 
	printf("__CYG_WIN not defined\n");
#endif
	return 1;
}