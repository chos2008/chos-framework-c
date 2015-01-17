/*
 * LuaRuntime provides a run time environment for c and cplusplus to integrate 
 * between c or cplusplus and lua. 
 * <p>
 * LuaRuntime acts as runtime environment to provides lua runtime context which 
 * handles lua state, register LuaGlue function to provides a way to call c or 
 * cplusplus function between lua to c or cplusplus, lua function simple call and 
 * based-event model between c or cplusplus and lua
 *
 * See LuaContext.hpp to checkout Lua runtime context for details.
 * 
 * @author ada
 * @version 1.0
 */
#include <assert.h>
#include <log.h>
#include "LuaRuntime.hpp"

LuaRuntime::LuaRuntime()
{
	dump = 1;
	luaContext = new LuaContext();
}

LuaRuntime::~LuaRuntime()
{
	if (dump)
	{
		destroyLuaContext();
	}
}

LuaRuntime* LuaRuntime::instance()
{
	static LuaRuntime runtime; // In this way, the deconstruct function mut be declared as public
	return &runtime;
}

void LuaRuntime::destroyLuaContext()
{
	delete luaContext;
	info("lua runtime context destroyed");
}

void LuaRuntime::destroy()
{
	destroyLuaContext();
	dump = 0;
	info("destroy lua runtime context explicitly, and the runtime would be destroyed automatic.");
}

LuaContext& LuaRuntime::getContext()
{
	return *luaContext;
}

void LuaRuntime::load(const char* file)
{
	luaContext->load(file);
}

void LuaRuntime::execute(const char* file)
{
	luaContext->execute(file);
}

void LuaRuntime::dexecute(const char* file)
{
	luaContext->dexecute(file);
}

void LuaRuntime::registerFunction(const char* name, LUAGLUEFUNCTION function)
{
	luaContext->registerFunction(name, function);
}

void LuaRuntime::registerEventFunction(const char* name, LUAGLUEFUNCTION function)
{
	registerFunction(name, function);
}

void LuaRuntime::registerClass(const char* name, void *obj, size_t size)
{
	assert(obj != NULL);
	lua_State *L = luaContext->getLuaContext();
	lua_newuserdata(L, size);
	luaL_getmetatable(L, name);
	lua_setmetatable(L, -2);

	oc.insert(std::pair<void *, const char *>(obj, name));
}

const char* LuaRuntime::getLuaObject(void *obj)
{
	std::map<void *, const char *>::iterator iter = oc.find(obj);
	if (iter == oc.end())
	{
		debug("No lua object associate the obj #%d\n", obj);
		return NULL;
	}
	const char *value = iter->second;
	debug("The lua object associate the obj #%d is %s\n", obj, value);
	return value;
}