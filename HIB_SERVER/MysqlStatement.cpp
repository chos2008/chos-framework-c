#include <windows.h>
#include <mysql.h>
#include <log.h>
#include "Mysql.hpp"
#include "Connection.hpp"
#include "MysqlStatement.hpp"
#include "ResultSet.hpp"
#include "MysqlResultSet.hpp"

MysqlStatement::MysqlStatement(Connection *connection) 
{
	this->connection = connection;
}

int MysqlStatement::execute(const char *sql)
{
	void *handle = connection->getConnectionHandle();
	if (handle == NULL) 
	{
		error("NULL");
		return 0;
	}
	Mysql *mysql = (Mysql *) handle;

	// Zero if the statement was successful. Nonzero if an error occurred.
	int error = mysql_query(mysql->getMysql(), sql);
	if (error) 
	{
		int e = mysql_errno(mysql->getMysql());
		if (e) 
		{
			const char* message = mysql_error(mysql->getMysql());
			throw SQLException(e, message);
		}
	}
	unsigned int fs = mysql_field_count(mysql->getMysql());
	return fs;
}

ResultSet* MysqlStatement::getResultSet()
{
	void *handle = connection->getConnectionHandle();
	Mysql *mysql = (Mysql *) handle;

	MYSQL_RES *rs = mysql_store_result(mysql->getMysql());
	if (rs == NULL) 
	{
		int e = mysql_errno(mysql->getMysql());
		if (e) 
		{
			const char* message = mysql_error(mysql->getMysql());
			throw SQLException(e, message);
		}
	}
	return new MysqlResultSet(rs);
}