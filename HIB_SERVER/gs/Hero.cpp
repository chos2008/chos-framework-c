#include <string>
#include <log.h>

#include "Hero.h"

#include "../SQLException.hpp"
#include "../Mysql.hpp"
#include "../Connection.hpp"
#include "../Statement.h"
#include "../ResultSet.hpp"

void Hero::clearGlobal()
{
	Mysql *mysql = new Mysql("localhost", 3306, "liveim_test", "root", "jxcoco1128");
	mysql->setEncode("gbk");
	Connection *connection = NULL;
	try 
	{
		connection = mysql->openConnection();

		Statement *stat = connection->createStatement();

		stat->execute("delete from global_hero");
	}
	catch (SQLException e) 
	{
		error("Connection error %d: %s", e.getCode(), e.getMessage());
		return;
	}
	info("global barrier cleared");
}

void Hero::createGlobalCharacter(int idx, const char *characterName, int atk, int def, int blood, int intellect, int quality, int male, const char *comment)
{
	Mysql *mysql = new Mysql("localhost", 3306, "liveim_test", "root", "jxcoco1128");
	mysql->setEncode("gbk");
	Connection *connection = NULL;
	try 
	{
		connection = mysql->openConnection();

		Statement *stat = connection->createStatement();

		std::string sql;
		sql.append("insert into global_hero values(");
		char s[10];
		itoa(idx, s, 10);
		sql.append(s).append(", ");
		sql.append("'").append(characterName).append("', ");
		memset(s, 0, sizeof(s));
		itoa(quality, s, 10);
		sql.append(s).append(", ");
		memset(s, 0, sizeof(s));
		itoa(male, s, 10);
		sql.append(s).append(", ");
		sql.append("'").append(comment).append("')");
		info("sql: %s", sql.c_str());
		stat->execute(sql.c_str());
	}
	catch (SQLException e) 
	{
		error("Connection error %d: %s", e.getCode(), e.getMessage());
		return;
	}
}