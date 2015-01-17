#include <stdio.h>
#include <string>
#include <windows.h>

#include "log.h"
#include "Module.hpp"

using namespace std;

Module::Module(const char *name, void *handle)
{
	this->moduleName = (char *) name;
	this->handle = handle;
}

char * Module::getModuleName()
{
	return this->moduleName;
}

void * Module::getHandle()
{
	return this->handle;
}

void Module::load()
{

}

// virtual function start()

void Module::start()
{
	printf("Module::start()\n");	
}
