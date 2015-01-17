#include "StdAfx.h"
#include <stdlib.h>
#include <winsock2.h>
#include "D:\usr\srv\mysql51\include\mysql.h"
/*
 * ע��Ŷ�����������mysql.h�ľ��Ե�ַ��
 * һ����mysql�µ�includeĿ¼�£���ϸ������������
 */

int main(int argc, char *argv[]) {
	MYSQL   my_connection;
	int   res;

	mysql_init(&my_connection);  

	/*mysql_real_connect(&mysql,host,user,passwd,dbname,0,NULL,0)   ==   NULL)*/
	if (mysql_real_connect(&my_connection, "localhost", "root", "jxcoco1128", "test", 3306, NULL, CLIENT_FOUND_ROWS)) {
        printf("Connection success\n");
        res = mysql_query(&my_connection, "select * from test");
        if (!res) {
            printf("Inserted %lu rows\n", (unsigned long) mysql_affected_rows(&my_connection));
            /*��ͷ�ĺ��������ܱ���Ӱ�������*/

			MYSQL_RES *result = mysql_store_result(&my_connection);

			if (result != NULL) {
				MYSQL_ROW row; 
				while ((row = mysql_fetch_row(result)) != NULL) {
					printf("%s, %s\n", row[0], row[1]);
				}
			}
        } else {
            //�ֱ��ӡ��������뼰��ϸ��Ϣ
            fprintf(stderr, "Insert error %d: %s\n", mysql_errno(&my_connection), mysql_error(&my_connection));
        }
        mysql_close(&my_connection);
	} else {
        fprintf(stderr, "Connection failed\n");
        if (mysql_errno(&my_connection)) {
            fprintf(stderr,   "Connection   error   %d:   %s\n ",mysql_errno(&my_connection),mysql_error(&my_connection));
        }
	}
    return EXIT_SUCCESS;
}
///////////////////////////////////////////// 