/**
 *
 * @author a.da
 * @since 1.0
 * 
 */
#include "Connection.hpp"
#include "Mysql.hpp"
#include "Statement.h"

#ifndef MYSQL_CONNECTION
#define MYSQL_CONNECTION

class Mysql;

class MysqlConnection : public Connection 
{
private:
	//Mysql *mysql;

public:
	MysqlConnection(const Mysql *mysql);

	~MysqlConnection();

	Statement * createStatement();
	
};
#endif