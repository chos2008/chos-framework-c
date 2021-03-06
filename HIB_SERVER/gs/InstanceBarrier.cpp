#include <stdlib.h>
#include <string>
#include <log.h>
#include "InstanceBarrier.hpp"

#include "../SQLException.hpp"
#include "../Mysql.hpp"
#include "../Connection.hpp"
#include "../Statement.h"
#include "../ResultSet.hpp"

InstanceBarrier::InstanceBarrier() : AbstractLinkedBarrier(NULL)
{

}

InstanceBarrier::InstanceBarrier(int idx, char* name, int level, int instance_idx) : AbstractLinkedBarrier(NULL)
{
    this->idx = idx;
	this->name = name;
	this->level = level;
	this->instance = instance_idx;
}

int InstanceBarrier::getIdx()
{
	return this->idx;
}

char* InstanceBarrier::getName()
{
	return this->name;
}

int InstanceBarrier::getLevel()
{
	return this->level;
}

int InstanceBarrier::getInstance()
{
	return this->instance;
}

void InstanceBarrier::clearGlobal()
{
	Mysql *mysql = new Mysql("localhost", 3306, "liveim_test", "root", "jxcoco1128");
	mysql->setEncode("gbk");
	Connection *connection = NULL;
	try 
	{
		connection = mysql->openConnection();

		Statement *stat = connection->createStatement();

		stat->execute("delete from global_barrier");
	}
	catch (SQLException e) 
	{
		error("Connection error %d: %s", e.getCode(), e.getMessage());
		return;
	}
	info("global barrier cleared");
}

void InstanceBarrier::createGlobalBarrier(int idx, const char *barrierName, int level, int instance_index, 
	const char *awards, const char *constraints, const char *storyline)
{
	Mysql *mysql = new Mysql("localhost", 3306, "liveim_test", "root", "jxcoco1128");
	mysql->setEncode("gbk");
	Connection *connection = NULL;
	try 
	{
		connection = mysql->openConnection();

		Statement *stat = connection->createStatement();

		std::string sql;
		sql.append("insert into global_barrier values(");
		char s[10];
		itoa(idx, s, 10);
		sql.append(s).append(", ");
		sql.append("'").append(barrierName).append("', ");
		memset(s, 0, sizeof(s));
		itoa(level, s, 10);
		sql.append(s).append(", ");
		memset(s, 0, sizeof(s));
		itoa(instance_index, s, 10);
		sql.append(s).append(", ");
		sql.append("'").append(awards).append("', ");
		sql.append("'").append(constraints).append("', ");
		sql.append("'").append(storyline).append("')");
		info("sql: %s", sql.c_str());
		stat->execute(sql.c_str());
	}
	catch (SQLException e) 
	{
		error("Connection error %d: %s", e.getCode(), e.getMessage());
		return;
	}
}