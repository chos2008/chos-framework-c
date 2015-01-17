#include <stdio.h>
#include <windows.h>

HANDLE hEvent;

DWORD WINAPI Callback1(LPVOID args)
{
	DWORD CurrentThreadId = GetCurrentThreadId();

	//HANDLE hMutex = OpenMutex(MUTEX_ALL_ACCESS, TRUE, MutexName);
	int i = 1;
	while (1) 
	{
		DWORD WaitState = WaitForSingleObject(hEvent, INFINITE);
		printf("Thread %ld print %d\n", CurrentThreadId, i);
		i++;
		printf("Thread %ld next print %d\n", CurrentThreadId, i);
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
		Sleep(milliseconds);
		printf("Thread %ld sleeped %ld milliseconds\n", CurrentThreadId, milliseconds);
		SetEvent(hEvent);
		i++;
	}
	return 1;
}

void main()
{
	/*
	m_hMutex = CreateMutex(NULL, FALSE, NULL);
	if (m_hMutex == NULL) 
	{
		printf("Fail to create mutex\n");
		exit(1);
	}
	*/

	hEvent = CreateEvent(NULL,FALSE,FALSE,"Test");

	DWORD threadID;

	CreateThread(NULL, 0, Callback1, (LPVOID) NULL, 0, &threadID);
	printf("Thread %ld started...\n", threadID);

	
	CreateThread(NULL, 0, Callback2, (LPVOID) NULL, 0, &threadID);
	printf("Thread %ld started...\n", threadID);
	
	

	ExitThread(0);
}