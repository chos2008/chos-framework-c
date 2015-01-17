#include <windows.h>
#include <mysql.h>

#include "Connection.hpp"
#include "SQLException.hpp"

#ifndef __MYSQL
#define __MYSQL

class Mysql 
{
private:
	char* host; 

	int port;
	
	char* database;
	
	char* username;
	
	char* password;

	char* charset;

	/**
	 * struct MYSQL defined in mysql.h: 
	 * 
	 * typedef struct st_mysql
	 * {
	 *     NET		net;			// Communication parameters 
     *     unsigned char	*connector_fd;		// ConnectorFd for SSL 
	 *     char		*host,*user,*passwd,*unix_socket,*server_version,*host_info;
     *     char          *info, *db;
	 *     struct charset_info_st *charset;
	 *     MYSQL_FIELD	*fields;
	 *     MEM_ROOT	field_alloc;
	 *     my_ulonglong affected_rows;
	 *     my_ulonglong insert_id;		// id if insert on table with NEXTNR 
	 *     my_ulonglong extra_info;		// Not used 
	 *     unsigned long thread_id;		// Id for connection in server 
	 *     unsigned long packet_length;
	 *     unsigned int	port;
	 *     unsigned long client_flag,server_capabilities;
	 *     unsigned int	protocol_version;
	 *     unsigned int	field_count;
	 *     unsigned int 	server_status;
	 *     unsigned int  server_language;
	 *     unsigned int	warning_count;
	 *     struct st_mysql_options options;
	 *     enum mysql_status status;
	 *     my_bool	free_me;		/* If free in mysql_close 
	 *     my_bool	reconnect;		/* set to 1 if automatic reconnect 
	 * 
	 *     // session-wide random string 
	 *     char	        scramble[SCRAMBLE_LENGTH+1];
	 * 
	 *  
	 *     // Set if this is the original connection, not a master or a slave we have
	 *     // added though mysql_rpl_probe() or mysql_set_master()/ mysql_add_slave()
	 * 
	 *     my_bool rpl_pivot;
	 * 
	 *     // Pointers to the master, and the next slave connections, points to
	 *     // itself if lone connection.
	 * 
	 *     struct st_mysql* master, *next_slave;
	 * 
	 *     struct st_mysql* last_used_slave; // needed for round-robin slave pick 
	 *     // needed for send/read/store/use result to work correctly with replication 
	 *     struct st_mysql* last_used_con;
	 * 
	 *     LIST  *stmts;                     // list of all statements 
	 *     const struct st_mysql_methods *methods;
	 *     void *thd;
	 *  
	 *     // Points to boolean flag in MYSQL_RES  or MYSQL_STMT. We set this flag 
	 *     // from mysql_stmt_close if close had to cancel result set of this object.
	 *  
	 *     my_bool *unbuffered_fetch_owner;
	 *     // needed for embedded server - no net buffer to store the 'info' 
	 *     char *info_buffer;
	 *     void *extension;
	 * } MYSQL;
     */
	MYSQL *mysql;

public:
	Mysql() throw (SQLException);

	Mysql(char* host, int port, 
			 char* database, 
			 char* username, char* password) throw (SQLException);
	~Mysql();

	void init() throw (SQLException);

	void setEncode(char *charset);

	Connection* openConnection();

	MYSQL * getMysql();
	
	void close();
};
//#else
//#error CMYSQL setting conflicts
#endif