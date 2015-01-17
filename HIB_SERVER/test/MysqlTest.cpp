#include <stdlib.h>
#include <stdio.h>
#include <log.h>
#include "../Mysql.hpp"
#include "../MysqlConnection.h"
#include "../Connection.hpp"
#include "../LinkedLibrary.h"

void main() 
{
	// localhost root jxcoco1128 database 3306
	Mysql *mysql = new Mysql("localhost", 3306, "liveim_test", "root", "jxcoco1128");
	debug("mysql &%ld\n", mysql);
	mysql->setEncode("gbk");
	Connection *connection = NULL;
	try 
	{
		connection = mysql->openConnection();
	}
	catch (SQLException e) 
	{
		error("Connection error %d: %s", e.getCode(), e.getMessage());
	}
	
	delete mysql;
	mysql = NULL;
	delete connection;
}