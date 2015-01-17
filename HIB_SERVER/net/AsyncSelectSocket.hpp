#include <string>
using namespace std;

#include "socket/Socket.h"

#if ! defined ASYNC_SELECT_SOCKET
#define ASYNC_SELECT_SOCKET 

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

class AsyncSelectSocket 
{

public:
    AsyncSelectSocket();

	~AsyncSelectSocket();

	/**
	 * Bound to the specified port. A port of <code>0</code> creates a  
     * socket on any free port.
     * 
     * As the bound local address not specificed, it will default accepting
     * connections on any/all local addresses.
     */
	void bind(int port) throw (SocketException);

	/**
	 *
	 *
	 *
	 *
	 *
	 *
	 *
	 */
	void bind(int port, int backlog) throw (SocketException);

	/**
	 *
	 *
	 *
	 *
	 *
	 *
	 */
	void bind(string bindAddress) throw (SocketException);

	/**
	 *
	 *
	 *
	 *
	 *
	 *
	 *
	 */
	void bind(string bindAddress, int backlog) throw (SocketException);

	/**
	 *
	 *
	 *
	 *
	 *
	 *
	 *
	 */
	void bind(int port, string bindAddress) throw (SocketException);

	/**
	 *
	 *
	 *
	 *
	 *
	 *
	 *
	 */
	void bind(int port, string bindAddress, int backlog) throw (SocketException);

	void bind(int port, char* bindAddress, int backlog) throw (SocketException);

	void listen() throw (SocketException);

	void listen(int backlog) throw (SocketException);

	/**
	 *
	 *
	 *
	 *
	 *
	 */
	void close() throw (SocketException);
};

#endif