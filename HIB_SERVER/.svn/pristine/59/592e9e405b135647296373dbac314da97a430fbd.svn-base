#include <map>
#include <string>
#include <windows.h>
#include <mysql.h>

#include "log.h"
#include "ResourceLoader.hpp"
#include "gs/UserData.hpp"

using namespace std;

void ResourceLoader::load() {
	std::map<char *, UserData> userData;

	MYSQL my_connection;
	
	mysql_init(&my_connection);
	
	const char *database = "liveim_test";
	
	//mysql_real_connect(&mysql,host,user,passwd,dbname,0,NULL,0)   ==   NULL)/
	if (! mysql_real_connect(&my_connection, "127.0.0.1", "root", "jxcoco1128", database, 3306, NULL, CLIENT_FOUND_ROWS)) {
		fprintf(stderr, "Connect %s failed\n", database);
		if (mysql_errno(&my_connection)) 
		{
			fprintf(stderr, "Connection error %d: %s\n", mysql_errno(&my_connection), mysql_error(&my_connection));
		}
		return;
	}

	printf("Connection %s success\n", database);
		
	string sql = "select * from im_account";/*
	sql = sql + "insert into im_account values(default, '" + this->id;
	sql = sql + "', '";
	sql = sql + this->password;
	sql = sql + "', 'ADA', default, default, default)";*/

	// Zero if the statement was successful. Nonzero if an error occurred.
	int res = mysql_query(&my_connection, sql.c_str());

	if (! res) 
	{
		unsigned int field_count = mysql_field_count(&my_connection);
		printf("%lu fields\n", field_count);
		
		MYSQL_RES *result = mysql_store_result(&my_connection);
		if (result != NULL) {
		    MYSQL_ROW row;
			while ((row = mysql_fetch_row(result)) != NULL) {
				char *userId = row[1];

				char *lastLoginTime = row[5];// last_login_time with sql date type
				UserData *plUserData = new UserData(userId, row[2], lastLoginTime);
				userData.insert(std::pair<char *, UserData>(userId, *plUserData));
			}
		}
	} 
	else 
	{
		//分别打印出错误代码及详细信息
		fprintf(stderr, "Insert error %d: %s\n", mysql_errno(&my_connection), mysql_error(&my_connection));
	}
	mysql_close(&my_connection);
	printf("Connection closed\n");

	


}