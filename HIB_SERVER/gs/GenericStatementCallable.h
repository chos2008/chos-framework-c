#include "Callable.h"

#if ! defined GENERIC_STATEMENT_CALLABLE
#define GENERIC_STATEMENT_CALLABLE
class GenericStatementCallable : public Callable 
{
private:
	char *statement;

public:
	GenericStatementCallable(char *statement);

	void call();
};
#endif;