#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <log.h>
#include "../Mysql.h"
#include "../Statement.h"
#include "../ResultSet.hpp"
using namespace std;

int testExecute(const char* sql) 
{
	// localhost root jxcoco1128 database 3306
	Mysql *mysql = new Mysql("localhost", 3306, "liveim_test", "root", "jxcoco1128");
	mysql->setEncode("gbk");
	MysqlConnection *connection = NULL;
	try 
	{
		connection = mysql->openConnection();
	}
	catch (SQLException e) 
	{
		error("Connection error %d: %s", e.getCode(), e.getMessage());
	}

	Statement *statement = connection->createStatement();

	
	int resultable = statement->execute(sql);
	if (resultable) 
	{
		debug("this is a select statement, select %d field", resultable);
	}
	else 
	{
		debug("this is not a select statement");
	}

	delete connection;
	connection = NULL;
	delete mysql;
	mysql = NULL;
	return resultable;
}

void testInsert()
{
	string sql = "";
	sql = sql + "insert into im_account values(default, '" + "abcd2222";
	sql = sql + "', '";
	sql = sql + "jxcoco1128";
	sql = sql + "', 'ADA', default, default, default)";
	testExecute(sql.c_str());
}

void testSelect() 
{
	string sql = "select * from im_account";
	testExecute(sql.c_str());
}

void testgetResultSet() 
{
	// localhost root jxcoco1128 database 3306
	Mysql *mysql = new Mysql("localhost", 3306, "liveim_test", "root", "jxcoco1128");
	mysql->setEncode("gbk");
	MysqlConnection *connection = NULL;
	try 
	{
		connection = mysql->openConnection();
	}
	catch (SQLException e) 
	{
		error("Connection error %d: %s", e.getCode(), e.getMessage());
	}
	Statement *statement = connection->createStatement();

	string sql = "select * from im_account";
	int resultable = statement->execute(sql.c_str());
	if (resultable) 
	{
		debug("this is a select statement, select %d field", resultable);
	}
	else 
	{
		debug("this is not a select statement");
	}
	ResultSet *rs = statement->getResultSet();
	while (rs->next()) 
	{
		char *idx = rs->get(0);
		char *name = rs->get(1);
		char *level = rs->get(2);
		char *instance_idx = rs->get(3);
		int _idx = atoi(idx);
		printf("%s\t%s\t%s\t%s\n", idx, name, level, instance_idx);
	}
}

void main() 
{
	//testInsert();
	testSelect();
	//testgetResultSet();
}