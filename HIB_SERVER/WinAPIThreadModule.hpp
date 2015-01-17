
#if ! defined WIN_API_THREAD_MODULE
#define WIN_API_THREAD_MODULE 
class WinAPIThreadModule 
{
private: 
	char *moduleName;

	/* 
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
	LPTHREAD_START_ROUTINE lpStartAddress;

public:
	WinAPIThreadModule(const char *name, LPTHREAD_START_ROUTINE lpStartAddress);

	void load();

	void start();
};
#endif;
