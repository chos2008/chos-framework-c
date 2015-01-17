#include <stdio.h>
#include "../gs/LuaRuntime.hpp"
#include "../LinkedLibrary.h"

class TestRegisterClass
{
	private:
		int data;
	public:
		TestRegisterClass()
		{
			this->data = 1;
		}

		~TestRegisterClass()
		{
		
		}

		void print()
		{
			printf("i: %d\n", data);
		}
};

int main(int argv, char **argc) 
{
	LuaRuntime *runtime = LuaRuntime::instance();

	//runtime->registerClass("TestRegisterClass_0", NULL, sizeof(TestRegisterClass)); // Assertion failed: obj != NULL, file ../gs/LuaRuntime.cpp, line 61
	runtime->getLuaObject(NULL);

	TestRegisterClass *trc1 = new TestRegisterClass();
	runtime->registerClass("TestRegisterClass_1", trc1, sizeof(TestRegisterClass));
	const char* luaObject = runtime->getLuaObject(trc1);
	printf("Lua object %s\n", luaObject);
	return 0;
}