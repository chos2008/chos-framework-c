#include <Winsock2.h>
#pragma comment(lib,"ws2_32")
#include <stdio.h>

#include "CModule.h"

int main(int argc, char* args[]) {
	char* e = args[0];
	printf("Microsoft Windows XP [版本 5.1.2600]\n");
	printf("(C) 版权所有 1985-2001 Microsoft Corp.\n");
	printf("\n%s\n", args[0]);

	int i = 0, length = 0;
	while (e[i] != '\0') {
		length++;
		i++;
	}
	length++;
	for (i = length - 1; i >= 0; i--) {
		char c = e[i];
		e[i] = '\0';
		if (c == '\\') {
			break;
		}
	}
	printf("%s\n\n", e);

	//CModuleFrameworkEcho(e);
	//CModuleFrameworkXMPP(e);
	CModuleFrameworkGameClient(e);
	ExitThread(0);
	return 0;
}