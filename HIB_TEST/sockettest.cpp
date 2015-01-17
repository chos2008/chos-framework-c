#include <stdio.h>
#pragma comment(lib, "ws2_32")
#include <windows.h>
#include <string>
using namespace std;

int main(int argc, char *args[]) {
	/*
    WSAData wsaData;
	WORD socketVersion = MAKEWORD(2, 2);

	string log = "Loading Socket Library, Version ";
	char* c = (char *) malloc(2 * sizeof(char));
	itoa(socketVersion, c, 10);
	log = log + c;
	log = log + "\n";
	//printf("%s Loading Socket Library, Version %i\n", logdate(), socketVersion);
	printf(log.c_str());
	
	int iStartUp = WSAStartup(socketVersion, &wsaData);
	if (iStartUp != 0) {
		string log = "Load Socket Library, Version ";
		char* c = (char *) malloc(2 * sizeof(char));
		itoa(socketVersion, c, 10);
		log = log + c;
		log = log + "                        [ERROR]\n";
		//printf("%s Load Socket Library, Version %i                        [ERROR]\n", logdate(), socketVersion);
		printf(log.c_str());
	}
	
	log = "Loaded Socket Library, Version ";
	c = (char *) malloc(2 * sizeof(char));
	itoa(socketVersion, c, 10);
	log = log + c;
	log = log + "                         [OK]\n";
	//char* logDate = logdate();
	//printf("%s Loaded Socket Library, Version %i                          [OK]\n", logDate, socketVersion);
	printf(log.c_str());
	
	*/
    SOCKET sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (sock == INVALID_SOCKET) {
		int error = WSAGetLastError();
		
		printf("Create Socket                                          [ERROR:%d]\n", error);
		return 1;
	}
	printf("Create Socket                                              [OK]\n");
	return 0;
}