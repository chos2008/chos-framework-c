#if ! defined USER_DATA
#define USER_DATA
class UserData {

private:
    char *userId;

	char *password;

	char *lastLoginTime;

public:

	UserData(char *userId, char *password);

	UserData(char *userId, char *password, char *lastLoginTime);

};
#endif;