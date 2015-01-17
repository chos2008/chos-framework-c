#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>


int *exitStatus = NULL;
int count = 0;

void* run_up(void *arg)
{
	printf("&exitStatus: %d, exitStatus: %d, *exitStatus: %d, &*exitStatus: %d\n", &exitStatus, exitStatus, *exitStatus, &*exitStatus);
	
	//pthread_exit((void *) exitStatus);
	//pthread_exit(NULL);
	//const char *s = "Thread funtion finished!";
	//pthread_exit((void *) s);
	
	return (void *) exitStatus;
	//return NULL;
	//return (void *) "Thread funtion finished!";
}


int main()
{
	
	exitStatus = (int *) malloc(sizeof(int));
	*exitStatus = 8;

	pthread_t pthread1, pthread2;
	pthread_create(&pthread1, 
		NULL, 
		run_up, 
		(void *) 0);

	int *p_status = (int *) malloc(sizeof(int));
	int **status = &p_status;
	pthread_join(pthread1, (void **) status);
	printf("&p_status: %d, p_status: %d, *p_status: %d, &*p_status: %d\n", &p_status, p_status, *p_status, &*p_status);
	printf("&status: %d, status: %d, *status: %d, &*status: %d, **status: %d, &**status: %d\n", &status, status, *status, &*status, **status, &**status);
	
	printf("final count: %d\n", count);
	return 0;
}