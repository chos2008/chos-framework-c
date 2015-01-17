#include "Connection.hpp"
#include "Statement.h"
#include "ResultSet.hpp"

#ifndef MYSQL_STATEMENT
#define MYSQL_STATEMENT
class MysqlStatement : public Statement
{
private: 
	Connection * connection;

public:

	MysqlStatement(Connection *connection);

	virtual int execute(const char *sql);

	virtual ResultSet* getResultSet();
};
#endif