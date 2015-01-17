/*
 *
 *
 * @author ada
 * @version 1.0
 * @since 1.0
 */
#ifndef SQL_EXCEPTION
#define SQL_EXCEPTION
class SQLException 
{
private:
	int code;

	char* message;

public:
	SQLException(int code);

	SQLException(char *message);

	SQLException(int code, const char* message);

	int getCode();

	char* getMessage();
};
#endif