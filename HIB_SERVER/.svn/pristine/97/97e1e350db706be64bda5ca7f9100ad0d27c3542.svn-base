#include <stdio.h>
#include <windows.h>
#include "../ini.h"

void main()
{
	char s[20];
	memset(s, 0, 20);
	DWORD length = GetPrivateProfileString("mysql", 
		"default-character-set", 
		"gbk", 
		s, 
		20, 
		"D:\\home\\admin\\workstation\\c\\HIB_SERVER\\https\\config\\https.ini");
	printf("\n");
	length = GetPrivateProfileString("mysql", 
		"data-dir", 
		"c:\\", 
		s, 
		20, 
		"D:\\home\\admin\\workstation\\c\\HIB_SERVER\\https\\config\\https.ini");
	printf("\n");
	length = GetPrivateProfileString("mysql", 
		"data-dir", 
		"c:\\", 
		s, 
		20, 
		"D:\\home\\admin\\workstation\\c\\HIB_SERVER\\https\\config\\https.ini");
	printf("\n");
	
	char *value = get("mysql", 
		"default-character-set", 
		"gbk", 
		"D:\\home\\admin\\workstation\\c\\HIB_SERVER\\https\\config\\https.ini");
	printf("Value of default-character-set: %s\n", value);

	value = get("mysql", 
		"data-dir", 
		"c:\\", 
		"D:\\home\\admin\\workstation\\c\\HIB_SERVER\\https\\config\\https.ini");
	
	printf("Value of default-character-set: %s\n", value);
}
