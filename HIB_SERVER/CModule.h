#include <windows.h>

#if ! defined __C_MODULE
#define __C_MODULE 
void module_start(char *moduleName, LPTHREAD_START_ROUTINE lpStartAddress);
#endif;
