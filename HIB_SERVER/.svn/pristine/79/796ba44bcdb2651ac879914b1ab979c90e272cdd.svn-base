#include <stdlib.h>
#include <stdio.h>
#include <windows.h>

#include <string>
using namespace std;

#include <mysql.h>
#include "log.h"
#include "XMPPIMAccount.h"

XMPPIMAccount::XMPPIMAccount() {
	
}

XMPPIMAccount::XMPPIMAccount(char* xmppIMID, char* password) {
	this->xmppIMID = xmppIMID;
	this->password = password;
}


void XMPPIMAccount::getXMPPIMAccount(char* xmppIMID, char* password) {
	/*
	MYSQL   my_connection;
	int   res;

	mysql_init(&my_connection);  

	//mysql_real_connect(&mysql,host,user,passwd,dbname,0,NULL,0)   ==   NULL)
	if (mysql_real_connect(&my_connection, "localhost", "root", "jxcoco1128", "test", 3306, NULL, CLIENT_FOUND_ROWS)) {
		printf("Connection success\n");
		res = mysql_query(&my_connection, "select * from test");
		if (!res) {
			printf("Inserted %lu rows\n", (unsigned long) mysql_affected_rows(&my_connection));
			//里头的函数返回受表中影响的行数
			MYSQL_RES *result = mysql_store_result(&my_connection);

			if (result != NULL) {
				MYSQL_ROW row; 
				while ((row = mysql_fetch_row(result)) != NULL) {
					printf("%s, %s\n", row[0], row[1]);
				}
			}
		} else {
			//分别打印出错误代码及详细信息
			fprintf(stderr, "Insert error %d: %s\n", mysql_errno(&my_connection), mysql_error(&my_connection));
		}
		mysql_close(&my_connection);
	} else {
		fprintf(stderr, "Connection failed\n");
		if (mysql_errno(&my_connection)) {
			fprintf(stderr,   "Connection   error   %d:   %s\n ",mysql_errno(&my_connection),mysql_error(&my_connection));
		}
	}
	*/
}

void XMPPIMAccount::create() 
{
    ///*
	printf("method: create...\n");
	
	MYSQL   my_connection;
	int   res;
	
	mysql_init(&my_connection);  
	
	//mysql_real_connect(&mysql,host,user,passwd,dbname,0,NULL,0)   ==   NULL)/
	MYSQL *mysql = mysql_real_connect(&my_connection, "localhost", "root", "jxcoco1128", "liveim_test", 3306, NULL, CLIENT_FOUND_ROWS);
	
	if (mysql == NULL) 
	{
		printf("Connection success\n");
		
		
		//char* sql = "";
		//strcat(sql, "insert into im_account values(default, '");
		//strcat(sql, this->xmppIMID);
		//strcat(sql, "', '");
		//strcat(sql, this->password);
		//strcat(sql, "', 'ADA', default, default, default)");
		//res = mysql_query(&my_connection, sql);


		//res = mysql_query(&my_connection, 
		//	"insert into im_account values(default, '" + this->xmppIMID + "', '" + this->password + "', 'ADA', default, default, default)");
		
		string sql = "";
		sql = sql + "insert into im_account values(default, '" + this->xmppIMID;
		sql = sql + "', '";
		sql = sql + this->password;
		sql = sql + "', 'ADA', default, default, default)";
		res = mysql_query(&my_connection, sql.c_str());
		
		if (!res) {
			printf("Inserted %lu rows\n", (unsigned long) mysql_affected_rows(&my_connection));
			//里头的函数返回受表中影响的行数/
		} else {
			//分别打印出错误代码及详细信息
			fprintf(stderr, "Insert error %d: %s\n", mysql_errno(&my_connection), mysql_error(&my_connection));
		}
		mysql_close(&my_connection);
	} else {
		fprintf(stderr, "Connection failed\n");
		if (mysql_errno(&my_connection)) {
			fprintf(stderr,   "Connection   error   %d:   %s\n ",mysql_errno(&my_connection),mysql_error(&my_connection));
		}
	}
	logdebug("Create new account...\n");
	//*/
}
