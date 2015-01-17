#include "UserData.hpp";

#if ! defined SESSION
#define SESSION
class Session {

private:

	char* sessionId;

	UserData* userData;

public:

	Session(char *sessionId, UserData* userData);

};
#endif;