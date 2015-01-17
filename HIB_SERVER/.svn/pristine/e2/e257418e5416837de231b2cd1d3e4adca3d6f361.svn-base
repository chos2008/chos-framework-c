#include <stdio.h>
#include "../linux/ServerSocket.h"

int main() {
	ServerSocket* socket = new ServerSocket();
	socket->bind(8888);

	try
	{
		socket->bind(8888);	
	}
	catch (SocketException e)
	{
		printf("Fail to bind socket: %s\n", e.getMessage());
		return 1;
	}
	
	return 0;
}

