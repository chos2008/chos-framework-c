/*
 *
 *
 * @author ada
 * @version 1.0
 * @since 1.0
 */
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include "PosixThread.hpp"

PosixThread::PosixThread()
{
	atf = 0;
}

PosixThread::PosixThread(int stackSize)
{
	size_t stacksize;
	pthread_attr_init(&attr);
	atf = 1;
	pthread_attr_setstacksize(&attr, (size_t) stackSize);
	pthread_attr_getstacksize(&attr, &stacksize);
	printf("Thread stack size = %li\n", stacksize);
}

#if ! defined _GLOBAL_START_ROUTINE
void* PosixThread::execute(void *args)
{
	PosixThread* t = (PosixThread *) args;
    t->run();
	//return (void *) 100;
}
#else
void* execute(void *args) 
{
	PosixThread* t = (PosixThread *) args;
    t->run();
	//return (void *) 100;
	pthread_exit((void *) 8);
}
#endif

void PosixThread::start()
{
#ifndef _GLOBAL_START_ROUTINE
	LPTHREAD_START_ROUTINE startRoutine = (LPTHREAD_START_ROUTINE) PosixThread::execute;
	printf("GLOBAL_START_ROUTINE not defined, do not using global thread start routine\n");
#else
	LPTHREAD_START_ROUTINE startRoutine = (LPTHREAD_START_ROUTINE) execute;
	printf("GLOBAL_START_ROUTINE defined, using global thread start routine\n");
#endif
	
	pthread_attr_t* att = this->atf ? &attr : NULL;
	int error = pthread_create(&pthread, 
		att, 
		startRoutine, 
		(void *) this);
	if (error)
	{
		printf("Thread start fail: fail to call pthread_create, error %d\n", error);
	}
}

void PosixThread::run()
{
	printf("PosixThread::run()\n");
}

pthread_t& PosixThread::getId()
{
	return pthread;
}