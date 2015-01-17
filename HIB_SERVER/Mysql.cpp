#include <stdio.h>
#include <string.h>
#include <log.h>
#include "SQLException.hpp"
#include "Mysql.hpp"
#include "Connection.hpp"
#include "MysqlConnection.h"

Mysql::Mysql() throw (SQLException)
{
	this->init();
}

Mysql::Mysql(char* host, int port, 
			 char* database, 
			 char* username, char* password) throw (SQLException)
{
	this->host = host;
	this->port = port;
	this->database = database;
	this->username = username;
	this->password = password;
	this->charset = NULL;
	this->init();
}

Mysql::~Mysql()
{
	this->close();
	free(this->mysql);
	this->mysql = NULL;
}

void Mysql::init() throw (SQLException) 
{
	this->mysql = (MYSQL *) malloc(sizeof(MYSQL));
	memset(this->mysql, 0, sizeof(MYSQL));

	MYSQL *p_mysql = mysql_init(this->mysql);
	if (p_mysql == NULL) 
	{
		int e = mysql_errno(this->mysql);
		if (e) 
		{
			const char* message = mysql_error(this->mysql);
			error("Connection error %d: %s", e, message);
			throw SQLException(e, message);
		}
	}
}

void Mysql::setEncode(char *charset)
{
	this->charset = charset;
}

/**
 * localhost root jxcoco1128 database 3306
 */
Connection* Mysql::openConnection()
{
	MYSQL *mysql = mysql_real_connect(this->mysql, 
		this->host, 
		this->username, 
		this->password, 
		this->database, 
		this->port, 
		NULL, 
		CLIENT_FOUND_ROWS);
	if (! mysql) 
	{
		error("Connect %s failed", this->database);
		int e = mysql_errno(this->mysql);
		if (e) 
		{
			const char* message = mysql_error(this->mysql);
			throw SQLException(e, message);
		}
	}
	debug("%s Connected", this->database);

	if (this->charset != NULL) 
	{
		const char* set = "set names ";
		int sz = strlen(set) + strlen(this->charset) + 1;
		char *cs = (char *) malloc(sz);
		if (cs == NULL) 
		{
			error("malloc fail");
			return NULL;
		}
		memset(cs, 0, sz);
		strcat(cs, set);
		strcat(cs, this->charset);

		debug("set charset %s(%s)", this->charset, cs);
		//s.append("").append(this->charset);
		int error = mysql_query(this->mysql, cs);
		
		if (error) 
		{
			error = mysql_errno(this->mysql);
			if (error) 
			{
				const char* message = mysql_error(this->mysql);
				throw SQLException(error, message);
			}
		}
		free(cs);
		cs = NULL;
	}
	return new MysqlConnection(this);
}

void Mysql::close()
{
	mysql_close(this->mysql);
	debug("closed");
}

MYSQL * Mysql::getMysql()
{
	return this->mysql;
}