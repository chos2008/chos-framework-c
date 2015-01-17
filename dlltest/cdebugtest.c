#include <stdio.h>
#include "windows.h"

// void debug(const char *fmt, ...);
typedef void (*h_method_debug) (const char *fmt, ...);
typedef void (*h_method_info) (const char *fmt, ...);

void testDefine()
{
	#ifdef h_method_info
		printf("h_method_info defined\n");
	#else
		printf("h_method_info not defined\n");
	#endif
}

void testDebug()
{
	const char *dlllog = 
		"D:\\home\\admin\\workstation\\c\\liblog\\Debug\\liblog.dll";
	HINSTANCE hInstance = NULL;
	h_method_debug debug;
	
	printf("dll %s\n", dlllog);
	hInstance = LoadLibrary(dlllog);
	if (hInstance == NULL) 
	{
		return;
	}

	debug = (h_method_debug) GetProcAddress(hInstance, "debug");
	debug("test dll %s debug method", dlllog);

	FreeLibrary(hInstance);
}

void testDebug2()
{
	const char *dlllog = 
		"D:\\home\\admin\\workstation\\c\\liblog\\Debug\\liblog.dll";
	HINSTANCE hInstance = NULL;
	h_method_debug debug;
	
	printf("dll %s\n", dlllog);
	hInstance = LoadLibrary(dlllog);
	if (hInstance == NULL) 
	{
		return;
	}

	debug = (h_method_debug) 0x0000100F;
	debug("test dll %s debug method", dlllog);

	FreeLibrary(hInstance);
}


void main()
{
	
	testDebug2();


	return;
}