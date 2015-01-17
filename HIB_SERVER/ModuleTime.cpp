#include <WINDOWS.H>
#include <stdio.h>
#include "time.h"
#include "log.h"

DWORD WINAPI ModuleTime(LPVOID args) {
	DWORD ret = 0;

	SYSTEMTIME stime;
	GetSystemTime(&stime);
	printf("%d Thread starting...\n", stime);
	
	time_t t;
	time(&t);
	char* ct = ctime(&t);
	printf("%s Thread starting...\n", ct);

	tm* tt = gmtime(&t);
	char* at = asctime(tt);
	printf("%s Thread starting...\n", at);

	tt = localtime(&t);
	at = asctime(tt);
	printf("%s Thread starting...\n", at);

	char* dt = dateformat();
	printf("%s Thread starting...\n", dt);
	return ret;

}