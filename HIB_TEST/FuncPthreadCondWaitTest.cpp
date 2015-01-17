#include <stdio.h>
#include <pthread.h>
#include <windows.h>

pthread_mutex_t mutex;
pthread_cond_t condition;

class ThreadIllegalStateException
{
private: 
	int code;

	char *message;

public:
	ThreadIllegalStateException(int code, char* message);

	char* getMessage();

	int getCode();
};

ThreadIllegalStateException::ThreadIllegalStateException(int code, char* message)
{
	this->code = code;
	this->message = message;
}

char* ThreadIllegalStateException::getMessage()
{
	return this->message;
}

int ThreadIllegalStateException::getCode()
{
	return this->code;
}

void watch1() throw (ThreadIllegalStateException)
{
	pthread_t ct = pthread_self();
	pthread_mutex_lock(&mutex);

	int i = 1;
	while(i <= 50)
	{
		int error = pthread_cond_wait(&condition, &mutex);
		if (error) 
		{
			throw ThreadIllegalStateException(error, "Thread in a illegal state, thread not owned mutex");
			//printf("ERROR: Error code: %d\n", error);
			//return (void *) error;
		}
		printf("%ld print %d\n", &ct, i);
		i++;
		printf("%ld next print %d\n", &ct, i);
	}

	pthread_mutex_unlock(&mutex);
}

void * watch_count1(void *t)
{	
	try 
	{
		watch1();
	} 
	catch (ThreadIllegalStateException e) 
	{
		fprintf(stderr, "%s, Error code: %d\n", e.getMessage(), e.getCode());
	}
	
	return (void *) 1;
}

void * watch_count2(void *t)
{
	pthread_t ct = pthread_self();

	while (1)
	{
		//pthread_mutex_lock(&mutex);
		/*
		int i = 0;
		while(i > 10000000000)
		{	
			i++;
		}
		*/
		int milliseconds = 5000;
		Sleep(milliseconds);                     // number is in milliseconds 1Sec = 1000 MiliSeconds
		printf("%ld sleeped %d milliseconds\n", &ct, milliseconds);

		pthread_cond_signal(&condition);
		//pthread_mutex_unlock(&mutex);
	}
}

void main()
{
	pthread_mutex_init(&mutex, NULL);
	pthread_cond_init(&condition, NULL);

	pthread_attr_t attr;
	pthread_attr_init(&attr);
	pthread_t pthread1, pthread2;

	pthread_create(&pthread1, &attr, watch_count1, (void *) 1);
	pthread_create(&pthread2, &attr, watch_count2, (void *) 2);

	pthread_join(pthread1, NULL);
	pthread_join(pthread2, NULL);

	pthread_mutex_destroy(&mutex);
	pthread_cond_destroy(&condition);

	pthread_exit(NULL);
}