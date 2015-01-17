#include <windows.h>
#include <mysql.h>
#include "ResultSet.hpp"

#ifndef MYSQL_RESULTSET
#define MYSQL_RESULTSET

class MysqlResultSet : public ResultSet 
{
private:
	MYSQL_RES *rs;

	MYSQL_ROW row;

public: 
	MysqlResultSet(MYSQL_RES *resultset);

	virtual unsigned long getRowSize();

	virtual int next();

	virtual char* get(int columnIndex);
};
#endif