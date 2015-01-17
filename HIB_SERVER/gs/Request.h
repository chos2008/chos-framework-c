#include <iostream>
#include <map>

#if ! defined REQUEST
#define REQUEST

#if ! defined REQUEST_EXCEPTION
#define REQUEST_EXCEPTION
class RequestException 
{
private:
	char* message;

public:
	RequestException();

	RequestException(char* message);

	char* getMessage();
};
#endif;

class Request 
{
private:
	char *command;
	std::map<char*, char*> paramMap;

public:
	Request(char* command);

	Request(char* command, std::map<char*, char*> paramMap);

	void setParameter(char* param, char* value);

	char* getParameterValue(char* param);

};

#endif