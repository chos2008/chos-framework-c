/*
 *
 *
 *
 */

#include "../micro.h"

#ifndef XMPP_IM_ACCOUNT
#define XMPP_IM_ACCOUNT

/**
 *
 *
 *
 */
class TK_API XMPPIMAccount {

private:
	char* xmppIMID;
	char* password;


public: 
	
	XMPPIMAccount();

	XMPPIMAccount(char* xmppIMID, char* password);
	
	void getXMPPIMAccount(char* xmppIMID, char* password);

	void create();
};

#endif;