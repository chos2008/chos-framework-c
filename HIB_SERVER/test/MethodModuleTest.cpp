#include <stdio.h>
#include "../Module.hpp"
#include "../MethodModule.hpp"

void method()
{
	printf("Hello, this is method module!\n");
}

void main()
{
	Module *module = NULL;
	
	module = new MethodModule("Method module", method);
	printf("Module name: %s\n", module->getModuleName());

	module->start();
}