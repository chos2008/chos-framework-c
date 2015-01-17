#include <stdio.h>
#include <string>
#include <windows.h>

#include "log.h"
#include "WinAPIThreadModule.hpp"

using namespace std;

WinAPIThreadModule::WinAPIThreadModule(const char *name, LPTHREAD_START_ROUTINE lpStartAddress)
{
	this->moduleName = (char *) name;
	this->lpStartAddress = lpStartAddress;
}

void WinAPIThreadModule::load()
{

}

void WinAPIThreadModule::start()
{
	DWORD threadID;

	/*
	 * HANDLE WINAPI CreateThread(
     *     _In_opt_   LPSECURITY_ATTRIBUTES lpThreadAttributes,
     *     _In_       SIZE_T dwStackSize,
     *     _In_       LPTHREAD_START_ROUTINE lpStartAddress,
     *     _In_opt_   LPVOID lpParameter,
     *     _In_       DWORD dwCreationFlags,
     *     _Out_opt_  LPDWORD lpThreadId
     * );
	 * 
	 * Parameters
     * 
	 * lpThreadAttributes [in, optional]
     * A pointer to a SECURITY_ATTRIBUTES structure that determines whether the returned handle can be inherited by child processes. If lpThreadAttributes is NULL, the handle cannot be inherited.
     * The lpSecurityDescriptor member of the structure specifies a security descriptor for the new thread. If lpThreadAttributes is NULL, the thread gets a default security descriptor. The ACLs in the default security descriptor for a thread come from the primary token of the creator.
	 * Windows XP:  The ACLs in the default security descriptor for a thread come from the primary or impersonation token of the creator. This behavior changed with Windows XP with SP2 and Windows Server 2003. For more information, see Remarks.
	 * dwStackSize [in]
	 * The initial size of the stack, in bytes. The system rounds this value to the nearest page. If this parameter is zero, the new thread uses the default size for the executable. For more information, see Thread Stack Size.
	 * lpStartAddress [in]
	 * A pointer to the application-defined function to be executed by the thread. This pointer represents the starting address of the thread. For more information on the thread function, see ThreadProc.
	 * lpParameter [in, optional]
	 * A pointer to a variable to be passed to the thread.
	 * dwCreationFlags [in]
	 * The flags that control the creation of the thread.
	 * Value	Meaning
	 * 0
	 * The thread runs immediately after creation.
	 * CREATE_SUSPENDED
	 * 0x00000004
	 * The thread is created in a suspended state, and does not run until the ResumeThread function is called.
	 * STACK_SIZE_PARAM_IS_A_RESERVATION
	 * 0x00010000
	 * The dwStackSize parameter specifies the initial reserve size of the stack. If this flag is not specified, dwStackSize specifies the commit size.
	 *  
	 * lpThreadId [out, optional]
	 * A pointer to a variable that receives the thread identifier. If this parameter is NULL, the thread identifier is not returned.
     */
	HANDLE hThread = CreateThread(NULL, 0, this->lpStartAddress, (LPVOID) NULL, 0, &threadID);
	if (hThread == NULL) 
	{
		DWORD errorCode = GetLastError();
		printf("Fail to start module %s, error code: %ld\n", this->moduleName, errorCode);
		return;
	}

	string debug = "Module ";
	debug.append(this->moduleName);
	debug.append(" started...\n");
	logdebug(debug.c_str());
}
