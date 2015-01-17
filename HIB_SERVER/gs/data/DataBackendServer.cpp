/*
 *
 *
 * @author ada
 * @version 1.0
 * @since 1.0
 */
#include <string.h>
#include <log.h>
#include "../LuaRuntime.hpp"
#include "../Task.hpp"
#include "../Instance.hpp"
#include "../InstanceBarrier.hpp"
#include "../Hero.h"
#include "../../LinkedLibrary.h"

LuaRuntime *runtime = NULL;

int lua_create_task(struct lua_State *L)
{
	LuaContext &context = runtime->getContext();
	int taskId = context.getIntArgument(1);
	const char *taskName = context.getStringArgument(2);
	int preTaskId = context.getIntArgument(3);
	int postTaskId = context.getIntArgument(4);
	const char *awards = context.getStringArgument(5);
	info("create task id: %d, name: %s, pre-task-id: %d, post-task-id: %d, awards: %s", taskId, taskName, preTaskId, postTaskId, awards);

	Task task;
	task.createGlobalTask(taskId, taskName, preTaskId, postTaskId, awards);
	return 0;
}

int lua_create_instance(struct lua_State *L)
{
	LuaContext &context = runtime->getContext();
	int scriptId = context.getIntArgument(1);
	int instanceId = context.getIntArgument(2);
	const char *instanceName = context.getStringArgument(3);
	int preInstanceId = context.getIntArgument(4);
	const char *awards = context.getStringArgument(5);
	const char *constraints = context.getStringArgument(6);
	int level = context.getIntArgument(7);
	const char *storyline = context.getStringArgument(8);
	info("create instance id: %d, name: %s, pre-instance-id: %d, awards: %s, constraints: %s", instanceId, instanceName, preInstanceId, awards, constraints);

	Instance instance;
	instance.createGlobalInstance(instanceId, instanceName, preInstanceId, awards, constraints, level, storyline);
	return 0;
}

int lua_create_barrier(struct lua_State *L)
{
	LuaContext &context = runtime->getContext();
	int idx = context.getIntArgument(1);
	const char *barrierName = context.getStringArgument(2);
	int level = context.getIntArgument(3);
	int instanceIdx = context.getIntArgument(4);
	const char *awards = context.getStringArgument(5);
	const char *constraints = context.getStringArgument(6);
	const char *storyline = context.getStringArgument(7);
	info("create barrier id: %d, name: %s, level: %d, instance-index: %d, awards: %s, constraints: %s", idx, barrierName, level, instanceIdx, awards, constraints);

	InstanceBarrier barrier;
	barrier.createGlobalBarrier(idx, barrierName, level, instanceIdx, awards, constraints, storyline);
	return 0;
}

int lua_create_character(struct lua_State *L)
{
	LuaContext &context = runtime->getContext();
	int idx = context.getIntArgument(1);
	const char *characterName = context.getStringArgument(2);
	// int atk, int def, int blood, int intellect, int quality, int male
	int atk = context.getIntArgument(3);
	int def = context.getIntArgument(4);
	int blood = context.getIntArgument(5);
	int intellect = context.getIntArgument(6);
	int quality = context.getIntArgument(7);
	int male = context.getIntArgument(8);
	const char *comment = context.getStringArgument(9);
	info("create barrier id: %d, name: %s, atk: %d, def: %d, blood: %d, intellect: %d, quality: %d, male: %d, comment: %s", 
		idx, characterName, atk, def, blood, intellect, quality, male, comment);

	Hero hero;
	hero.createGlobalCharacter(idx, characterName, atk, def, blood, intellect, quality, male, comment);
	return 0;
}

int lua_create_object(struct lua_State *L)
{
	return 0;
}

void init_task(const char *dir)
{
	Task task;
	task.clearGlobal();

	char *filename = "Task.data.lua";
	char *file = (char *) malloc(strlen(dir) + strlen(filename) + 2);
	memset(file, 0, strlen(dir) + strlen(filename) + 2);
	strcat(file, dir);
	strcat(file, "/");
	strcat(file, filename);
	printf("file: %s\n", file);
	runtime->dexecute(file);
	free(file);
}

void init_instance(const char *dir)
{
	Instance instance;
	instance.clearGlobal();

	InstanceBarrier barrier;
	barrier.clearGlobal();

	char *filename = "Instance.data.lua";
	char *file = (char *) malloc(strlen(dir) + strlen(filename) + 2);
	memset(file, 0, strlen(dir) + strlen(filename) + 2);
	strcat(file, dir);
	strcat(file, "/");
	strcat(file, filename);
	printf("file: %s\n", file);
	runtime->dexecute(file);
	free(file);
}

void init_character(const char *dir)
{
	Hero hero;
	hero.clearGlobal();

	char *filename = "Character.data.lua";
	char *file = (char *) malloc(strlen(dir) + strlen(filename) + 2);
	memset(file, 0, strlen(dir) + strlen(filename) + 2);
	strcat(file, dir);
	strcat(file, "/");
	strcat(file, filename);
	printf("file: %s\n", file);
	runtime->dexecute(file);
	free(file);
}

int lua_runtime_version()
{
	puts(LUA_VERSION);
	puts(LUA_COPYRIGHT);
	puts(LUA_AUTHORS);
	return 0;
}

void init(const char *dir)
{
	///*
	runtime = LuaRuntime::instance();
	lua_runtime_version();
	runtime->registerFunction("lua_create_task", lua_create_task);
	runtime->registerFunction("lua_create_instance", lua_create_instance);
	runtime->registerFunction("lua_create_barrier", lua_create_barrier);
	runtime->registerFunction("lua_create_character", lua_create_character);
	runtime->registerFunction("lua_create_object", lua_create_object);
	//*/
	
	init_task(dir);
	init_instance(dir);
	init_character(dir);
}

int main(int argc, char **args) 
{
	const char *dir = NULL;
	printf("Usage: databackendserver lua_script_dir\n");
	if (argc != 2)
	{
		return 1;
	}
	dir = args[1];
	init(dir);
    return 0;
}