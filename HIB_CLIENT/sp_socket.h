typedef struct sp_socket {
	unsigned int socket;

} sp_socket, *lp_sp_socket;

sp_socket __sp_socket(int af, int type, int protocol);