/**
 * Provides a set of function to read or write initialize file 
 *
 * @author a.da
 * @since 1.0
 */
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "ini.h"

char* get(const char *section, const char* key, const char *defaultValue, const char *filename)
{
	int size = 16;
	char *bf = (char *) malloc(16);
	memset(bf, 0, size);
	while (1) 
	{
		DWORD length = GetPrivateProfileString(section, 
			key, 
			defaultValue, 
			bf, 
			size, 
			filename);
		if (length < (DWORD) (size - 1)) 
		{
			break;
		}
		size = (size * 3)/2 + 1;
		bf = (char *) realloc(bf, size);
		memset(bf, 0, size);
	}
	return bf;
}