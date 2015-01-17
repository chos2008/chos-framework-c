/*
 *
 *
 * @author ada
 * @version 1.0
 * @since 1.0
 */
#ifdef _WIN32
#include <windows.h>
#define socket_t SOCKET
#else
#define socket_t int
#endif