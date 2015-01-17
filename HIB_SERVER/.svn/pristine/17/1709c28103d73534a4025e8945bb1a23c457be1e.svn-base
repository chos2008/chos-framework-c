#include <stdio.h>
#include <string>
#include <pthread.h>

#include "log.h"
#include "PThreadModule.hpp"

using namespace std;

PThreadModule::PThreadModule(const char *name, void *(*lpStartAddress) (void *))
{
	this->moduleName = (char *) name;
	this->lpStartAddress = lpStartAddress;
	this->arg = NULL;
}

PThreadModule::PThreadModule(const char *name, 
							 void *(*lpStartAddress) (void *), void * arg) 
{
    this->moduleName = (char *) name;
	this->lpStartAddress = lpStartAddress;
	this->arg = arg;
}

void PThreadModule::init()
{

}

void PThreadModule::start()
{
	pthread_t pthread;

	/*
	 * #include <pthread.h>
     *
     * int pthread_create(pthread_t *restrict thread,
     *        const pthread_attr_t *restrict attr,
     *        void *(*start_routine)(void*), void *restrict arg);
	 */
	int error = pthread_create(&pthread, NULL, this->lpStartAddress, this->arg);

	printf("%d\t%d\n", error, pthread);
    if (error) 
	{
        warn("pthread_create() error %d", error);
		return;
	}

	/*
	string debug = "Module ";
	debug.append(this->moduleName);
	debug.append(" started...\n");
	logdebug(debug.c_str());
	*/
	debug("Module %s#%d started", this->moduleName, pthread);
}


void PThreadModule::destroy()
{
	
}