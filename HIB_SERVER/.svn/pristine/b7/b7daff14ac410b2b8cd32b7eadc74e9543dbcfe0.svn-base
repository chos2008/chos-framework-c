/*
 * game server module
 * <p>
 * game server module provides game server implementations as a module. 
 * the game server module implements as a thread module with windows api 
 * style. 
 *
 * thread module can see @WinAPIThreadModule@ for details.
 * 
 * @author ada
 * @version 1.0
 * @since 1.0
 */
#include "GameServer.h"

/**
 * game server module callback handler.
 * <p>
 * the callback handler of thread module with windows api 
 * style must defines format like this: 
 * 
 * The LPTHREAD_START_ROUTINE type defines a pointer to this callback function. 
 * ThreadProc is a placeholder for the application-defined function name.
 * 
 * typedef DWORD (__stdcall *LPTHREAD_START_ROUTINE) (
 *     [in] LPVOID lpThreadParameter
 * );
 *
 * Function prototype: 
 * 
 * DWORD WINAPI ThreadProc(
 *     _In_  LPVOID lpParameter
 * );
 *
 * The return value indicates the success or failure of this function. The ret-
 * urn value should never be set to STILL_ACTIVE (259), as noted in GetExitCod-
 * eThread.
 * 
 * Do not declare this callback function with a void return type and cast the 
 * function pointer to LPTHREAD_START_ROUTINE when creating the thread. Code t-
 * hat does this is common, but it can crash on 64-bit Windows.
 */
DWORD WINAPI ModuleGameServer(LPVOID args) 
{
	//signal(SIGINT, interruptHandler);

	DWORD ret = 0;


	GameServer *server = new GameServer();
    server->start();
	return ret;

}