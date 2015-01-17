#include <stdio.h>

int main() {
#ifndef _WINDOWS_
	printf("_WINDOWS_ defined!\n");
#else 
	printf("_WINDOWS_ not defined!\n");
#endif
}