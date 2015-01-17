#include <stdio.h>
#include "windows.h"

// void debug(const char *fmt, ...);
typedef void (*h_method_debug) (const char *fmt, ...);
typedef void (*h_method_info) (const char *fmt, ...);

void main()
{
	HINSTANCE hInstance = NULL;
	h_method_debug debug;

	const char *dlllog = "D:\\usr\\bin\\Tencent\\QQ\\Bin\\LIBEXPATW.DLL";
	printf("dll %s\n", dlllog);
	hInstance = LoadLibrary(dlllog);

	debug = (h_method_debug) GetProcAddress(hInstance, "XML_Parse");
	debug("aaa");

	FreeLibrary(hInstance);

	/*
	dlllog = "D:\\usr\\bin\\Tencent\\QQ\\Bin\\zlib.dll";
	printf("dll %s\n", dlllog);
	hInstance = LoadLibrary(dlllog);

	dlllog = "D:\\usr\\bin\\Tencent\\QQ\\Bin\\Common.dll";
	printf("dll %s\n", dlllog);
	hInstance = LoadLibrary(dlllog);


	dlllog = "D:\\usr\\bin\\Tencent\\QQ\\Bin\\LoginLogic.dll";
	printf("dll %s\n", dlllog);
	hInstance = LoadLibrary(dlllog);
	
	
	
	
	if (hInstance == NULL) 
	{
		return;
	}

	//debug = (h_method_debug) GetProcAddress(hInstance, "debug");
	//debug("test dll %s debug method", dlllog);

	GetProcAddress(hInstance, "DllRegisterServer");

	FreeLibrary(hInstance);

#ifdef h_method_info
	printf("h_method_info defined\n");
#else
	printf("h_method_info not defined\n");
#endif
	*/
	return;
}