#include <stdio.h>
#include <string>
#include <windows.h>

#include "log.h"
#include "Module.hpp"
#include "ObjectModule.hpp"

using namespace std;
ObjectModule::ObjectModule(char *name, void *target, void *handle) : Module(name, handle)
{
	this->target = target;
}

void ObjectModule::start()
{
	void *handle = this->getHandle();

	void (*hMethod)(void) = (void (*)(void)) handle; // (void (__cdecl *)(void))handle;
	hMethod();
}