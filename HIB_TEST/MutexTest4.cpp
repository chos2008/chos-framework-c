#include <stdio.h>
#include <windows.h>

HANDLE hMutex;

DWORD WINAPI Callback1(LPVOID args)
{
	DWORD CurrentThreadId = GetCurrentThreadId();

	//HANDLE hMutex = OpenMutex(MUTEX_ALL_ACCESS, TRUE, MutexName);
	int i = 1;
	while (i < 50) 
	{
		DWORD WaitState = WaitForSingleObject(hMutex, INFINITE);
		printf("Thread %ld print %d\n", CurrentThreadId, i);
		i++;
		printf("Thread %ld next print %d\n", CurrentThreadId, i);
		ReleaseMutex(hMutex);
	}
	return 1;
}

DWORD WINAPI Callback2(LPVOID args) 
{
	DWORD CurrentThreadId = GetCurrentThreadId();

	unsigned long milliseconds = 5000;
	int i = 0;
	while(i < 10) 
	{
		DWORD WaitState = WaitForSingleObject(hMutex, INFINITE);
		//HANDLE mutex = OpenMutex(MUTEX_ALL_ACCESS, TRUE, NULL);
		//if (mutex == NULL) 
		//{
		//	printf("aaaaaaaaaaaaa\n");	
		//}
		Sleep(milliseconds);
		printf("Thread %ld sleeped %ld milliseconds\n", CurrentThreadId, milliseconds);
		ReleaseMutex(hMutex);
		i++;
	}
	return 1;
}

void main()
{
		hMutex = CreateMutex( 
        NULL,              // default security attributes
        FALSE,             // initially not owned
        NULL);             // unnamed mutex

	if (hMutex == NULL) 
	{
		printf("Fail to create mutex\n");
		exit(1);
	}

	

	DWORD threadID;

	CreateThread(NULL, 0, Callback1, (LPVOID) NULL, 0, &threadID);
	printf("Thread %ld started...\n", threadID);

	
	CreateThread(NULL, 0, Callback2, (LPVOID) NULL, 0, &threadID);
	printf("Thread %ld started...\n", threadID);
	
	

	ExitThread(0);
}