// WaitForSingleObject Sample.cpp 

#include <stdio.h>
#include <windows.h>
#include <iostream.h>

HANDLE hEvent;

DWORD WINAPI SampleThread(LPVOID iValue)
{
	int i = 0;
	while(i < 5) 
	{
		//Sleep(5000);
		printf("Thread sleeped 5 seconds\n");
		i++;
	}
 	
	
	//SetEvent(hEvent);
	return 0;
}

void main()
{
	HANDLE hThread;
	DWORD dwGenericThread;
	hThread = CreateThread(NULL,0,SampleThread,NULL,0,&dwGenericThread);
	if(hThread == NULL)
	{
		DWORD dwError = GetLastError();
		cout<<"SCM:Error in Creating thread"<<dwError<<endl ;
		return;
	}

	hEvent = CreateEvent(NULL,FALSE,FALSE,"Test");

	cout<<"Started waiting for the thread to complete.."<<endl ;
	WaitForSingleObject(hEvent, INFINITE);
	cout<<"Thread Completed."<<endl ;

	CloseHandle(hEvent);

}