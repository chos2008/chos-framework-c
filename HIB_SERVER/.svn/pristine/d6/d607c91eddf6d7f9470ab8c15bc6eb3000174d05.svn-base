#include <stdio.h>
#include <string>
#include <windows.h>

#include "log.h"
#include "MethodModule.hpp"

using namespace std;
MethodModule::MethodModule(char *name, void *handle) : Module(name, handle)
{
	
}

void MethodModule::start()
{
	void *handle = this->getHandle();

	void (*hMethod)(void) = (void (*)(void)) handle; // (void (__cdecl *)(void))handle;
	hMethod();
}