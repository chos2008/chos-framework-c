#include <windows.h>
#include <mysql.h>
#include <log.h>
#include "MysqlResultSet.hpp"

MysqlResultSet::MysqlResultSet(MYSQL_RES *resultset)
{
	this->rs = resultset;
	
}

unsigned long MysqlResultSet::getRowSize()
{
	my_ulonglong rows = mysql_num_rows(rs);
	debug("%lu rows select\n", rows);
	return (unsigned long) rows;
}

int MysqlResultSet::next()
{
	if (this->rs != NULL) 
	{
		this->row = mysql_fetch_row(this->rs);
		return this->row == NULL ? 0 : 1;;
	}
	return 0;
}

char* MysqlResultSet::get(int columnIndex)
{
	return this->row[columnIndex];
}
