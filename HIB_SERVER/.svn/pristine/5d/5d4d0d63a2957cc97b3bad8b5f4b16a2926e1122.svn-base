/*
 *
 *
 * @author ada
 * @version 1.0
 * @since 1.0
 */
#include <stdio.h>
#include <string.h>
#include <log.h>
#include "../gs/LuaContext.hpp"
#include "../gs/LuaExecutor.hpp"
#include "../gs/LuaScriptExecutor.hpp"
/*
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
*/
#include "../LinkedLibrary.h"

#define BUFSIZE 1024

LuaContext *luaContext;
char *strEventHandler = NULL;


/**
 * LuaGlue 函数原型
 * 
 *     int (__cdecl *)(struct lua_State *) 
 * 
 * 如果在C编译环境下，函数定义可以不严格遵循这种原型。
 */
int __lua_version(struct lua_State *L)
{
	printf("int __lua_version(struct lua_State *L)\n");

	puts(LUA_VERSION);
	puts(LUA_COPYRIGHT);
	puts(LUA_AUTHORS);
	return 0;
}

int registerEvent(struct lua_State *L)
{
	printf("registerEvent()\n");
	return 0;
}

int registerClass(struct lua_State *L) 
{
	printf("registerClass()\n");
	return 0;
}

int registerEventHandler(struct lua_State *L) 
{
	strEventHandler = (char *) luaContext->getStringArgument(1);
	info("lua event handler %s registered\n", strEventHandler);
	return 0;
}

void FireEvent(char* event, ...)
{
	char callback[254];
	sprintf(callback, "%s(\"%s\")", strEventHandler, event);
	
	lua_State *luaHandle = luaContext->getLuaContext();
	//lua_dostring(luaHandle, script);
	luaL_dostring(luaHandle, callback);
}

int main(int argc, char *argv[])
{
	luaContext = new LuaContext();
	lua_State *L = NULL;
	char line[BUFSIZE];
	int len;

	puts(LUA_VERSION);
	puts(LUA_COPYRIGHT);
	puts(LUA_AUTHORS);

	/*
	//luaContext = lua_open(); // #define lua_open()	luaL_newstate()
	L = luaL_newstate(); // 创建一个解释器句柄

	luaL_openlibs(L); // 打开所有的Lua库
	//info("lua runtime environment opened");
	*/
	L = luaContext->getLuaContext();
	
	lua_register(L, "__lua_version", __lua_version);
	debug("LuaGlue function %s registered", "__lua_version");

	luaContext->registerFunction("registerEvent", registerEvent);

	lua_pushcfunction(L, registerClass);
	lua_setglobal(L, "registerClass");
	debug("LuaGlue function %s registered", "registerClass");

	luaContext->registerFunction("registerEventHandler", registerEventHandler);
	

	printf("Type lua script from stdin terminal, and the script typed would be executed.\n");
	printf("Usage: \n");
	printf("\tType <Enter> to exit stdin\n");
	while(fgets(line, sizeof(line), stdin) != 0) 
	{
		if (line[0] == '\n')
		{
			break;
		}
		len = strlen(line);
		printf("lua script length: %d\n", len);
		printf("executing %s\n", line);
		
		//lua_dostring(L, line); 
		//luaL_dostring(L, line);
		LuaScriptExecutor et(luaContext, line, 0);
		et.execute();

		memset(line, 0, BUFSIZE);
	}
	printf("exit stdin terminal\n");
	

	//luaL_dostring(L, "print(\"this is lua output\")");
	LuaExecutor *executor = new LuaScriptExecutor(luaContext, "print(\"this is lua output\")", 0);
	executor->execute();
	delete executor;

	printf("第一种方式：\n");
	//luaL_loadfile(L, "test.lua"); // 调入Lua脚本文件
	//luaContext->load("test.lua");
	//lua_pcall(L, 0, 0, 0); //执行Lua脚本
    luaContext->execute("test.lua");

	printf("第二种方式：\n");
	//luaL_dofile(L, "test.lua");
	luaContext->dexecute("test.lua");

	printf("call lua function lua_version\n");
	lua_getglobal(L, "lua_version");
	//lua_pushnumber(m_pState, nParam1);
	//lua_pushnumber(m_pState, nParam2);
	lua_pcall(L, 0, 0, 0);

	printf("call lua function lua_onEvent\n");
	lua_getglobal(L, "lua_onEvent");
	lua_pushstring(L, "Click");
	lua_pcall(L, 1, 0, 0);

	FireEvent("DoubleClick");
	FireEvent("Move");

    delete luaContext;
    return 0;
}