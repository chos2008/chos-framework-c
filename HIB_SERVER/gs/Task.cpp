/*
 *
 *
 * @author ada
 * @version 1.0
 * @since 1.0
 */
#include <log.h>
#include <string>

#include "Task.hpp"

#include "../SQLException.hpp"
#include "../Mysql.hpp"
#include "../Connection.hpp"
#include "../Statement.h"
#include "../ResultSet.hpp"

void Task::clearGlobal()
{
	Mysql *mysql = new Mysql("localhost", 3306, "liveim_test", "root", "jxcoco1128");
	mysql->setEncode("gbk");
	Connection *connection = NULL;
	try 
	{
		connection = mysql->openConnection();

		Statement *stat = connection->createStatement();

		stat->execute("delete from global_task");
	}
	catch (SQLException e) 
	{
		error("Connection error %d: %s", e.getCode(), e.getMessage());
		return;
	}
	info("global task cleared");
}


void Task::createGlobalTask(int taskId, const char *taskName, int preTaskId, int postTaskId, const char *awards)
{
	Mysql *mysql = new Mysql("localhost", 3306, "liveim_test", "root", "jxcoco1128");
	mysql->setEncode("gbk");
	Connection *connection = NULL;
	try 
	{
		connection = mysql->openConnection();

		Statement *stat = connection->createStatement();

		std::string sql;
		sql.append("insert into global_task values(");
		char c_taskId[8];
		itoa(taskId, c_taskId, 10);
		sql.append(c_taskId).append(", ");
		sql.append("'").append(taskName).append("', ");
		memset(c_taskId, 0, sizeof(c_taskId));
		itoa(preTaskId, c_taskId, 10);
		sql.append(c_taskId).append(", ");
		memset(c_taskId, 0, sizeof(c_taskId));
		itoa(postTaskId, c_taskId, 10);
		sql.append(c_taskId).append(", ");
		sql.append("'").append(awards).append("')");
		info("sql: %s", sql.c_str());
		stat->execute(sql.c_str());
	}
	catch (SQLException e) 
	{
		error("Connection error %d: %s", e.getCode(), e.getMessage());
		return;
	}
}
