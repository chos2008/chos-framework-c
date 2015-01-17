#include <windows.h>
#include <string>
using namespace std;

#include "log.h"
#include "CModuleGameClient.h"
#include "CModuleEcho.h"
#include "CModuleXMPP.h"

void CModuleFrameworkGameClient(char* home) {
	string tname = "Thread-Echo Service";
	DWORD threadID;
	CreateThread(NULL, 0, CModuleGameClient, home, 0, &threadID);

	string log = "";
	log = log + "Thread ";
	log = log + tname;
	log = log + " #";
	char* a = (char*) malloc(4 * sizeof(char));
	itoa(threadID, a, 10);
	log = log + a;
	log = log + " starting...\n";
	//logdebug("Thread ??? started...\n");
	logdebug(log.c_str());
}

void CModuleFrameworkEcho(char* home) {
	string tname = "Thread-Echo Service";
	DWORD threadID;
	CreateThread(NULL, 0, CModuleEcho, home, 0, &threadID);

	string log = "";
	log = log + "Thread ";
	log = log + tname;
	log = log + " #";
	char* a = (char*) malloc(4 * sizeof(char));
	itoa(threadID, a, 10);
	log = log + a;
	log = log + " starting...\n";
	//logdebug("Thread ??? started...\n");
	logdebug(log.c_str());
}

void CModuleFrameworkXMPP(char* home) {
	/*
	SECURITY_ATTRIBUTES * lpSecurityAttributes = (SECURITY_ATTRIBUTES *) malloc(sizeof(SECURITY_ATTRIBUTES));
	lpSecurityAttributes->bInheritHandle = TRUE;
	lpSecurityAttributes->lpSecurityDescriptor = "Thread-";
	*/
	string tname = "Thread-XMPP Service";
	DWORD threadID;
	CreateThread(NULL, 0, CModuleXMPP, home, 0, &threadID);

	string log = "";
	log = log + "Thread ";
	log = log + tname;
	log = log + " #";
	char* a = (char*) malloc(4 * sizeof(char));
	itoa(threadID, a, 10);
	log = log + a;
	log = log + " starting...\n";
	//logdebug("Thread ??? started...\n");
	logdebug(log.c_str());
}
