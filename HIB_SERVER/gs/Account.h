/* class @Account@ declares for account in game server
 * 
 * 
 * 
 * @author a.da
 * @since 1.0
 */


#ifndef GAME_ACCOUNT
#define GAME_ACCOUNT

/**
 *
 *
 *
 */
class Account {

private:
	char* id;

	char* password;


public: 
	
	Account();

	Account(char* id, char* password);
	
	~Account();

	//bool operator==(const Account &arg);

	bool operator!=(const Account &arg1);

	// The operator!= overloading can not be declared like this!
	// It should be:
	// bool operator!=(const Account &arg1);
	// like.
	//bool operator!=(const Account *arg1);

	char* getId();

	char* getPassword();

	void getXMPPIMAccount(char* id, char* password);

	void create();
};

#endif;