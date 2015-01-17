#include "Statement.h"

#ifndef CONNECTION
#define CONNECTION
class Connection 
{
protected:
	void *handle;

public:

	~Connection();
	
	void* getConnectionHandle();

	virtual Statement * createStatement() = 0;
};
#endif