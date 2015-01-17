#include <stdio.h>
#include "../Module.hpp"
#include "../MethodModule.hpp"

void method()
{
	printf("Hello, this is method module!\n");
}

int method1(int i)
{
	printf("Hello, this is method1 module, i: %d!\n", i);
	return 1;
}

class TestMethodModule : public Module 
{
public:
	TestMethodModule(char *name, void *handle) : Module(name, handle)
	{
		
	}

	void start()
	{
		void *handle = this->getHandle();

		int (*hMethod)(int) = (int (*)(int))handle; // (void (__cdecl *)(void))handle;
		int i = hMethod(2);
		printf("method1 return %d\n", i);
	}
};

void main()
{
	method();
	void (*pMethod)() = method;
	pMethod();

	Module *module = new TestMethodModule("Method module", method1);
	printf("Module name: %s\n", module->getModuleName());

	module->start();
}