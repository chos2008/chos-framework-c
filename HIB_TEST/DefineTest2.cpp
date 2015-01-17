#include <stdio.h>

#define __DLLEXPORT _declspec(dllexport)

int main()
{
#ifdef __DLLEXPORT 
//#define 
	printf("__DLLEXPORT defined\n");
#else
	printf("__DLLEXPORT not defined\n");
#endif

// __CYG_WIN is a user defined
// when g++(or g++ -c) -D __CYG_WIN like this: 
//     g++ -c -D __CYG_WIN UserDTest.cpp -o UserDTest.o
// __CYG_WIN defined, otherwise __CYG_WIN not defined.
#ifdef __CYG_WIN
	printf("__CYG_WIN defined\n");
#else 
	printf("__CYG_WIN not defined\n");
#endif

#ifdef _WIN32
	printf("_WIN32 defined\n");
#else
	printf("_WIN32 not defined\n");
#endif
}