#include "LuaContext.hpp"
#include "LuaExecutor.hpp"

#ifndef LUA_SCRIPT_EXECUTOR
#define LUA_SCRIPT_EXECUTOR
class LuaScriptExecutor : public LuaExecutor 
{
	private: 
		LuaContext *luaContext; 

		char *script;
		int isFile;
	public:

		LuaScriptExecutor(LuaContext *luaContext, char *script, int isFile);

		virtual void execute();
};
#endif