#include "Callable.h"

#if ! defined PREPARED_STATEMENT_CALLABLE
#define PREPARED_STATEMENT_CALLABLE
class PreparedStatementCallable : public Callable 
{
private:
	char *statement;

public:
	PreparedStatementCallable(char *statement);

	void setParameter(int i, int value);

	void call();
};
#endif;