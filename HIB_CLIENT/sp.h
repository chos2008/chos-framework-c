typedef struct sp_hdr_domain_item {
    char* field_name;
	char* field_value;
} sp_hdr_domain_item, *lp_sp_hdr_domain_item;

typedef struct sp_hdr_domain {
	lp_sp_hdr_domain_item first;
	struct sp_hdr_domain *next;
} sp_hdr_domain, *lp_sp_hdr_domain;


// <code>sp</code> struct defines a transfer packet struct for communication 
// between peers.
// <code>sp.pdu</code> protocol data unit defines the command code, it allocates 
// 1 byte; 
// <code>sp</code> default provides 2 types of command: 
// <code>PDU_INIT_SESSION</code>
// <code>PDU_DESTROY_SESSION</code>
//
// <code>PDU_INIT_SESSION</code> be used for initialiing a session between 
// communication peers
// <code>PDU_DESTROY_SESSION</code> be used for destroys the session between 
// communication peers
//
// <code>sp.hdr_domain</code> defines the parameters for protocol data unit <code>
// sp.pdu</code>, it allocates a none-limited bytes
// 
#define PDU_INIT_SESSION = 0x00;
#define PDU_DESTROY_SESSION = 0x01;

typedef struct {
	unsigned short int pdu;
	lp_sp_hdr_domain hdr_domain;
} sp, *lp_sp;