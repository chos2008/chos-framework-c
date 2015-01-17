struct hhtcp 
{
    unsigned int length;
    unsigned short int major;
    unsigned short int minor;
};

struct dhtcp
{
    unsigned short int length;
    unsigned short int opcode;
    unsigned short int response;
    unsigned short int reserved;
    unsigned short int f1;
    unsigned short int rr;
    unsigned int trans_id;
    char* op_data;
};

struct ahtcp
{
    unsigned short int length;
    unsigned int sig_time;
    unsigned int sig_expire;
    unsigned short int key_name;
    unsigned short int signature;
};