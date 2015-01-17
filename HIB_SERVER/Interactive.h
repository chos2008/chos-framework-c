#if ! defined INTERACTIVE
#define INTERACTIVE
class Interactive 
{
private:
	char * command;

public:
	Interactive();

	void run();

	void shift();

	void shift(char *command);
};
#endif;