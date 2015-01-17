#if ! defined SOCKET_EXCEPTION
#define SOCKET_EXCEPTION
class SocketException 
{

private:
    int code;

	char *message;
public:
	SocketException();

	SocketException(int code);

	SocketException(int code, char* message);
	
	int getCode();
    
	char* getMessage();
};
#endif

