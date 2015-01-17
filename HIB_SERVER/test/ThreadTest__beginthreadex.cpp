#ifndef _MT
#error "Compiler linking options /MT not specific"
#endif


#include <stdio.h>
#include <windows.h>
#include <process.h>

#include "../Thread.hpp"
#include "../LinkedLibrary.h"


void start_address(void *arg)
{
	printf("_beginthread start_address\n");
}

unsigned __stdcall start_address_ex(void *arg)
{
	printf("_beginthreadex start_address_ex\n");
	return 0;
}

int main()
{
	printf("Thread test\n");

#ifdef _MT 
	printf("MT defined\n");
#endif

	unsigned long th;
	printf("Thread _beginthread test\n");
	th = _beginthread(start_address, 
		0, 
		NULL);
	printf("_beginthread return %ld\n", th);

	unsigned thread;
	// CREATE_SUSPENDED 
	th = _beginthreadex(NULL, 0, start_address_ex, NULL, 0, &thread);

	Thread *t = new Thread();
	t->start();

	ExitThread(0);
	return 0;
}