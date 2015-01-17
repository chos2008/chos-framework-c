#include <stdio.h>
#include <string.h>
#include <windows.h>

#include "log.h"
#include "CModule.h"

void module_start(char *moduleName, LPTHREAD_START_ROUTINE lpStartAddress)
{
	
	DWORD threadID;
	HANDLE hThread = CreateThread(NULL, 0, lpStartAddress, (LPVOID) NULL, 0, &threadID);
	if (hThread == NULL) 
	{
		DWORD errorCode = GetLastError();
		printf("Fail to start module %s, error code: %ld\n", moduleName, errorCode);
		return;
	}
	
	//string debug = "Module ";
	//debug.append(moduleName);
	//debug.append(" started...\n");
	//logdebug(debug.c_str());
}
