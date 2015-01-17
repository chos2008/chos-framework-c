#include <log.h>
#include "MysqlConnection.h"
#include "MysqlStatement.hpp"

MysqlConnection::MysqlConnection(const Mysql *mysql)
{
	this->handle = (Mysql *) mysql;
	debug("handle &%ld\n", this->handle);
}

MysqlConnection::~MysqlConnection()
{
	debug("destroy MysqlConnection");
}

Statement * MysqlConnection::createStatement()
{
	return new MysqlStatement(this);
}
