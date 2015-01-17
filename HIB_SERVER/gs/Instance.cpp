#include <stdlib.h>
#include <string>
#include <log.h>
#include "Instance.hpp"

#include "../SQLException.hpp"
#include "../Mysql.hpp"
#include "../Connection.hpp"
#include "../Statement.h"
#include "../ResultSet.hpp"

Instance::Instance() 
{

}

Instance::Instance(int id, int idx, char* name, AbstractLinkedBarrier *barrier)
{
	this->id = id;
	this->idx = idx;
    this->name = name;
	this->barrier = barrier;
}

int Instance::getId() 
{
    return this->id;
}

int Instance::getIndex()
{
	return this->idx;
}

char* Instance::getName() 
{
    return this->name;
}

AbstractLinkedBarrier* Instance::getBarrier()
{
	return this->barrier;
}

void Instance::insert(AbstractLinkedBarrier * barrier) 
{
	if (this->barrier == NULL) 
	{
	    this->barrier = barrier;
		this->lastBarrier = this->barrier;
	}
	else 
	{
	    this->lastBarrier->setNext(barrier);
		this->lastBarrier = barrier;
	}
}

AbstractLinkedBarrier * Instance::getLastPassedBarrier() 
{
    return NULL;
}

AbstractLinkedBarrier * Instance::getLastFightedBarrier()
{
    return NULL;
}

AbstractLinkedBarrier * Instance::last()
{
    return this->lastBarrier;
}

void Instance::clearGlobal()
{
	Mysql *mysql = new Mysql("localhost", 3306, "liveim_test", "root", "jxcoco1128");
	mysql->setEncode("gbk");
	Connection *connection = NULL;
	try 
	{
		connection = mysql->openConnection();

		Statement *stat = connection->createStatement();

		stat->execute("delete from global_instance");
	}
	catch (SQLException e) 
	{
		error("Connection error %d: %s", e.getCode(), e.getMessage());
		return;
	}
	info("global instance cleared");
}

void Instance::createGlobalInstance(int instanceId, const char *instanceName, int preInstanceId, const char *awards, const char *constraints, int level, const char *storyline)
{
	Mysql *mysql = new Mysql("localhost", 3306, "liveim_test", "root", "jxcoco1128");
	mysql->setEncode("gbk");
	Connection *connection = NULL;
	try 
	{
		connection = mysql->openConnection();

		Statement *stat = connection->createStatement();

		std::string sql;
		sql.append("insert into global_instance values(");
		char s[10];
		itoa(instanceId, s, 10);
		sql.append(s).append(", ");
		sql.append("'").append(instanceName).append("', ");
		memset(s, 0, sizeof(s));
		itoa(preInstanceId, s, 10);
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