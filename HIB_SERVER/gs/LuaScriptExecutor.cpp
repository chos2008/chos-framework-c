/*
 *
 *
 * @author ada
 * @version 1.0
 * @since 1.0
 */
#include <stdio.h>
#include "LuaScriptExecutor.hpp"

LuaScriptExecutor::LuaScriptExecutor(LuaContext *luaContext, char *script, int isFile)
{
	this->luaContext = luaContext;
	this->script = script;
	this->isFile = isFile;
}

void LuaScriptExecutor::execute()
{
	if (isFile)
	{
		luaContext->dexecute(script);
	}
	else 
	{
		lua_State *luaHandle = luaContext->getLuaContext();
		//lua_dostring(luaHandle, script); 
		luaL_dostring(luaHandle, script);
	}
}