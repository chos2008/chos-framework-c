typedef struct sp_hdr_domain_item {
    char* field_name;
	char* field_value;
} sp_hdr_domain_item, *lp_sp_hdr_domain_item;

typedef struct sp_hdr_domain {
	lp_sp_hdr_domain_item first;
	struct sp_hdr_domain *next;
} sp_hdr_domain, *lp_sp_hdr_domain;

typedef struct {
	unsigned short int pdu;
	lp_sp_hdr_domain hdr_domain;
} sp, *lp_sp;