#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <windows.h>
#include <mysql.h>

using namespace std;

#include "log.h"
#include "Account.h"

Account::Account() 
{
	this->id = NULL;
	this->password = NULL;
}

Account::Account(char* id, char* password) 
{
	this->id = id;
	this->password = password;
}

Account::~Account()
{
	printf("destroy Account!\n");
/*
	if (this->xmppIMID != NULL) 
	{
		free(this->xmppIMID);
	}
	if (this->password != NULL)
	{
		free(this->password);
	}
*/
}

/*
bool operator==(const Account &arg)
{
	return this == &arg;
}
*/

bool Account::operator!=(const Account &arg1)
{
	if (strcmp(this->id, arg1.id) != 0) 
	{
		return true;
	}
	if (strcmp(this->password, arg1.password) != 0)
	{
		return true;
	}
	return false;
	
	//return true;
}

char* Account::getId()
{
	return this->id;
}

char* Account::getPassword()
{
	return this->password;
}

void Account::getXMPPIMAccount(char* id, char* password) 
{
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

void Account::create() 
{
	logdebug("Create new account...\n");

	//typedef struct st_mysql
	//{
	//    NET		net;			/* Communication parameters */
	//    unsigned char	*connector_fd;		/* ConnectorFd for SSL */
	//    char		*host,*user,*passwd,*unix_socket,*server_version,*host_info;
	//    char          *info, *db;
	//    struct charset_info_st *charset;
	//    MYSQL_FIELD	*fields;
	//    MEM_ROOT	field_alloc;
	//    my_ulonglong affected_rows;
	//    my_ulonglong insert_id;		/* id if insert on table with NEXTNR */
	//    my_ulonglong extra_info;		/* Not used */
	//    unsigned long thread_id;		/* Id for connection in server */
	//    unsigned long packet_length;
	//    unsigned int	port;
	//    unsigned long client_flag,server_capabilities;
	//    unsigned int	protocol_version;
	//    unsigned int	field_count;
	//    unsigned int 	server_status;
	//    unsigned int  server_language;
	//    unsigned int	warning_count;
	//    struct st_mysql_options options;
	//    enum mysql_status status;
	//    my_bool	free_me;		/* If free in mysql_close */
	//    my_bool	reconnect;		/* set to 1 if automatic reconnect */
	//
	//    /* session-wide random string */
	//    char	        scramble[SCRAMBLE_LENGTH+1];
	//
	//    /*
	//    Set if this is the original connection, not a master or a slave we have
	//    added though mysql_rpl_probe() or mysql_set_master()/ mysql_add_slave()
	//    */
	//    my_bool rpl_pivot;
	//    /*
    //    Pointers to the master, and the next slave connections, points to
    //    itself if lone connection.
	//    */
	//    struct st_mysql* master, *next_slave;
	//
	//    struct st_mysql* last_used_slave; /* needed for round-robin slave pick */
	//    /* needed for send/read/store/use result to work correctly with replication */
	//    struct st_mysql* last_used_con;
	//
	//    LIST  *stmts;                     /* list of all statements */
	//    const struct st_mysql_methods *methods;
	//    void *thd;
	//    /*
	//    Points to boolean flag in MYSQL_RES  or MYSQL_STMT. We set this flag 
    //    from mysql_stmt_close if close had to cancel result set of this object.
	//    */
	//    my_bool *unbuffered_fetch_owner;
	//    /* needed for embedded server - no net buffer to store the 'info' */
	//    char *info_buffer;
	//    void *extension;
	//} MYSQL;
	//
	MYSQL my_connection;
	int res;
	
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

	string sql = "";
	sql = sql + "insert into im_account values(default, '" + this->id;
	sql = sql + "', '";
	sql = sql + this->password;
	sql = sql + "', 'ADA', default, default, default)";
	res = mysql_query(&my_connection, sql.c_str());

	if (! res) 
	{
		printf("Inserted %lu rows\n", (unsigned long) mysql_affected_rows(&my_connection));

		string debug = "Account ";
		debug.append(this->id);
		debug.append(" created!\n");
		logdebug(debug.c_str());
	} 
	else 
	{
		//分别打印出错误代码及详细信息
		fprintf(stderr, "Insert error %d: %s\n", mysql_errno(&my_connection), mysql_error(&my_connection));
	}
	mysql_close(&my_connection);
	printf("Connection closed\n");
}
