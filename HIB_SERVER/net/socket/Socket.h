/*
 *
 * @author ada
 * @version 1.0
 * @since 1.0
 */
#include <windows.h>
#include "../../csocket.h"
#include "SocketInputStream.hpp"
#include "SocketOutputStream.hpp"
/**
 *
 *
 *
 *
 */

#if ! defined __SOCKET
#define __SOCKET

class _declspec(dllexport) Socket
{

private:

	void startup() throw (SocketException);

protected:

	// SOCKET, Socket implementations. Pls refer the relate sock specifications 
	// for about more information.
	// The socket implementations SOCKET is implemented under WIN platform.
	//
	// The new type to be used in all
	// instances which refer to sockets.
	// 
	// typedef unsigned int    u_int;
	// typedef u_int           SOCKET;
	socket_t socket;

	unsigned int nonblocking;

	sockaddr_in addr;

	unsigned int closed;

	// The input stream for the socket {@link LightSocket}
	SocketInputStream inputStream;

	// The output stream for the socket {@link LightSocket}
	SocketOutputStream outputStream;

	/**
	 * af  µØÖ·¼Ò×å(Address families).
	 * 
	 * #define AF_UNIX         1               // local to host (pipes, portals) 
	 * #define AF_INET         2               // internetwork: UDP, TCP, etc. 
	 * #define AF_IMPLINK      3               // arpanet imp addresses 
	 * #define AF_PUP          4               // pup protocols: e.g. BSP 
	 * #define AF_CHAOS        5               // mit CHAOS protocols 
	 * #define AF_NS           6               // XEROX NS protocols 
	 * #define AF_IPX          AF_NS           // IPX protocols: IPX, SPX, etc. 
	 * #define AF_ISO          7               // ISO protocols 
	 * #define AF_OSI          AF_ISO          // OSI is ISO 
	 * #define AF_ECMA         8               // european computer manufacturers 
	 * #define AF_DATAKIT      9               // datakit protocols 
	 * #define AF_CCITT        10              // CCITT protocols, X.25 etc 
	 * #define AF_SNA          11              // IBM SNA 
	 * #define AF_DECnet       12              // DECnet 
	 * #define AF_DLI          13              // Direct data link interface 
	 * #define AF_LAT          14              // LAT 
	 * #define AF_HYLINK       15              // NSC Hyperchannel 
	 * #define AF_APPLETALK    16              // AppleTalk 
	 * #define AF_NETBIOS      17              // NetBios-style addresses 
	 * #define AF_VOICEVIEW    18              // VoiceView 
	 * #define AF_FIREFOX      19              // Protocols from Firefox 
	 * #define AF_UNKNOWN1     20              // Somebody is using this! 
	 * #define AF_BAN          21              // Banyan 
	 * #define AF_ATM          22              // Native ATM Services 
	 * #define AF_INET6        23              // Internetwork Version 6 
     * 
	 * The possible values for the address family are defined in the 
	 * winsock.h winsock2.h header file.
     * 
	 * On the Windows SDK released for Windows Vista and later, the 
	 * organization of header files has changed and the possible values 
	 * for the address family are defined in the Ws2def.h header file. 
	 * Note that the Ws2def.h header file is automatically included in 
	 * Winsock2.h, and should never be used directly.
	/*virtual*/ void init(int af, int type, int protocol) throw (SocketException);

public: 

	static const int CLOSED;

	Socket();

	Socket(socket_t socket);

	~Socket();

	/**
	 *
	 *
	 *
	 *
	 *
	 */
	socket_t getPlainSocket();

	SocketInputStream* getInputStream();

	SocketOutputStream* getOutputStream();

	int getNonBlocking();

	char* getInetAddressAsString();

	sockaddr_in getInetAddress();

	int getPort();

	/**
	 * int setsockopt(
	 *     _In_  SOCKET s,
	 *     _In_  int level,
	 *     _In_  int optname,
	 *     _In_  const char *optval,
	 *     _In_  int optlen
	 * );
	 *
	 * and the function to retrieve a socket option: 
	 * int getsockopt(
	 *     _In_     SOCKET s,
	 *     _In_     int level,
	 *     _In_     int optname,
	 *     _Out_    char *optval,
	 *     _Inout_  int *optlen
	 * );
	 *
	 * This section describes Winsock Socket Options for various editions of Windows operating 
	 * systems. Use the getsockopt and setsockopt functions for more getting and setting socket 
	 * options. To enumerate protocols and discover supported properties for each installed 
	 * protocol, use the WSAEnumProtocols function.
	 * Some socket options require more explanation than these tables can convey; such options 
	 * contain links to additional pages.
	 * 
	 * IPPROTO_IP
	 *     Socket options applicable at the IPv4 level. For more information, see the IPPROTO_IP 
	 *     Socket Options.
	 * IPPROTO_IPV6
	 *     Socket options applicable at the IPv6 level. For more information, see the IPPROTO_IPV6 
	 *     Socket Options.
	 * IPPROTO_RM
	 *     Socket options applicable at the reliable multicast level. For more information, see 
	 *     the IPPROTO_RM Socket Options.
	 * IPPROTO_TCP
	 *     Socket options applicable at the TCP level. For more information, see the IPPROTO_TCP 
	 *     Socket Options.
	 * IPPROTO_UDP
	 *     Socket options applicable at the UDP level. For more information, see the IPPROTO_UDP 
	 *     Socket Options.
	 * NSPROTO_IPX
	 *     Socket options applicable at the IPX level. For more information, see the NSPROTO_IPX 
	 *     Socket Options.
	 * SOL_APPLETALK
	 *     Socket options applicable at the AppleTalk level. For more information, see the 
	 *     SOL_APPLETALK Socket Options.
	 * SOL_IRLMP
	 *     Socket options applicable at the InfraRed Link Management Protocol level. For more information, 
	 *     see the SOL_IRLMP Socket Options.
	 * SOL_SOCKET
	 *     Socket options applicable at the socket level. For more information, see the SOL_SOCKET Socket 
	 *     Options.
	 * 
	 * Remarks
	 * 
	 * All SO_* socket options apply equally to IPv4 and IPv6 (except SO_BROADCAST, since broadcast is 
	 * not implemented in IPv6).
	 */
	void setSocketOption(int level, int optionName, const char *optionValue, int optionLength) throw (SocketException);

	void setReadTimeOut(int timeout) throw (SocketException);

	void setWriteTimeOut(int timeout) throw (SocketException);
	
	void setNonBlocking() throw (SocketException);

	/**
	 *
	 *
	 *
	 *
	 *
	 */
	void close() throw (SocketException);

	int isClose();
};

#endif