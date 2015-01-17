#include "ResultSet.hpp"

#ifndef STATEMENT
#define STATEMENT
class Statement
{
public:
	/*
	Statement(const MysqlConnection *connection);
	*/
	virtual int execute(const char *sql) = 0;
	
	virtual ResultSet* getResultSet() = 0;
	
};
#endif;