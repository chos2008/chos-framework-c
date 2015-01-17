#include "../LinkedLibrary.h"
#include "MessageDestination.hpp"
#include "MessageProducer.hpp"
#include "MessageConsumer.hpp"
/*
int i = 1;

DWORD WINAPI Callback1(LPVOID args)
{
	DWORD CurrentThreadId = GetCurrentThreadId();

	//HANDLE hMutex = OpenMutex(MUTEX_ALL_ACCESS, TRUE, MutexName);
	while (1) 
	{
		printf("Thread %ld print %d\n", CurrentThreadId, i);
		//Sleep(200);
	}
	return 1;
}

DWORD WINAPI Callback2(LPVOID args) 
{
	DWORD CurrentThreadId = GetCurrentThreadId();

	while(1) 
	{
		printf("Thread %ld print %d\n", CurrentThreadId, i);
		//Sleep(2000);
	}
	return 1;
}
*/
void main()
{
	///*
	MessageDestination *destination = new MessageDestination();

	MessageProducer *producer = new MessageProducer();
	producer->registerProducer(destination);
	producer->start();

	MessageConsumer *consumer = new MessageConsumer();
	consumer->registerConsumer(destination);
	consumer->start();

	/*
	while(1)
	{
		Sleep(2000);
	}
	*/
	ExitThread(0);


	/*
	DWORD threadID;
	CreateThread(NULL, 0, Callback1, (LPVOID) NULL, 0, &threadID);
	printf("Thread %ld started...\n", threadID);

	CreateThread(NULL, 0, Callback2, (LPVOID) NULL, 0, &threadID);
	printf("Thread %ld started...\n", threadID);

	ExitThread(0);
	*/
}
