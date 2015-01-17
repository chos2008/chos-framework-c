/*
 *
 *
 * @author ada
 * @version 1.0
 * @since 1.0
 */
// using <lua.hpp> instead <lua.h>, <lualib.h>, <lauxlib.h>
// 
// and it also: 
//     extern "C" {
//         #include "lua.h"
//         #include "lualib.h"
//         #include "lauxlib.h"
//     }
//
//#include <lua.h>
//#include <lualib.h>
//#include <lauxlib.h>
#include <lua.hpp>
#include "LuaException.hpp"

#if ! defined LUA_CONTEXT
#define LUA_CONTEXT

/**
 * LuaGlue ����ԭ��
 * 
 *     int (__cdecl *)(struct lua_State *) 
 * 
 * 
 */
typedef int (*LUAGLUEFUNCTION)(struct lua_State *);

class LuaContext
{
	private:
		lua_State *luaContext;
	public:
		LuaContext();

		~LuaContext();

		/**
		 * Register LuaGlue function.
		 * 
		 * Lua provides two ways to register LuaGlue function: 
		 * 
		 * 1��call lua_register function
		 *     void lua_register (lua_State *L, const char *name, lua_CFunction f);
		 * 
		 * 2��call lua_pushcfunction and lua_setglobal function
		 *     void lua_pushcfunction (lua_State *L, lua_CFunction f);
		 *     void lua_setglobal (lua_State *L, const char *name);
		 * 
		 * function void lua_register (lua_State *L, const char *name, lua_CFunction f) defines: 
		 *     #define lua_register(L,n,f) (lua_pushcfunction(L, (f)), lua_setglobal(L, (n)))
		 *
		 * 
		 *
		 */
		void registerFunction(const char* name, LUAGLUEFUNCTION function);

		void load(const char* file) throw (LuaException);

		void execute(const char* file) throw (LuaException);

		void dexecute(const char* file) throw (LuaException);

		/**
		 * lua provides this way to receive the arguments passed to LuaGlue function.
		 * <p>
		 * See this method implementations to know how lua to receive the arguments 
		 * passed to LuaGlue function.
		 * <p>
		 * Like the others language, lua function and LuaGlue function can have numb-
		 * ers of argument. Like this: 
		 * 
		 *     function lua_function(arg1, arg2, arg3, ...)  ---> int lua_glue_function(struct lua_State *L)
		 * 
		 * On lua runtime environment, to call c or cplusplus function, like this: 
		 *
		 *     lua_function(arg1, arg2, arg3, ...)
		 *
		 * Note: c or cplusplus function(LuaGlue function) lua_glue_function registered as lua_function
		 * 
		 * when call c or cplusplus function through lua, arguments are passed to.
		 */
		const char* getStringArgument(int n);

		/**
		 *
		 * 
		 * int luaL_checkint (lua_State *L, int narg);
		 * 
		 * @see #getStringArgument(int)
		 */
		int getIntArgument(int n);

		lua_State * getLuaContext();
};
#endif