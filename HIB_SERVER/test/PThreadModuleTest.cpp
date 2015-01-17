#include <stdio.h>
#include <pthread.h>
#include <log.h>
#include "../PThreadModule.hpp"
#define NUM_THREADS     5

void *PrintHello(void *args)
{
   long arg = (long) args;
   info("Hello World! It's me, with argument passed: %ld", arg);
   pthread_exit(NULL);
   return (void *) 1;
}


int main (int argc, char *argv[])
{
    /*
	pthread_t threads[NUM_THREADS];
	int rc;
	long t;
	for(t=0; t<NUM_THREADS; t++)
	{
		printf("In main: creating thread %ld\n", t);
		rc = pthread_create(&threads[t], NULL, PrintHello, (void *)t);
		printf("%d\t%d\n", rc, threads[t]);
		if (rc)
		{
			printf("ERROR; return code from pthread_create() is %d\n", rc);
			//exit(-1);
		}
	}
	*/

	PThreadModule *module = NULL;
	module = new PThreadModule("Thread AS Server", PrintHello);
	module->start();
	
	// Last thing that main() should do 
	//pthread_exit(NULL);
	return 1;
}
