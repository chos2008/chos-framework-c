#include <stdio.h>
#include <winsock2.h>

int main() {
#ifndef _WINSOCK2API_
	printf("_WINSOCK2API_ not defined!\n");
#else 
	printf("_WINSOCK2API_ defined!\n");
#endif
}