#include "sp_socket.h"
#include <Winsock2.h>
#pragma comment(lib,"ws2_32")

sp_socket __sp_socket(int af, int type, int protocol) {
	sp_socket spsocket;
	SOCKET isocket = socket(af, type, protocol);
	spsocket.socket = isocket;
	return spsocket;
}
