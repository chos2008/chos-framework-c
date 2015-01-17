#include "Module.hpp"

#if ! defined __METHOD_MODULE
#define __METHOD_MODULE 
class MethodModule : public Module
{
public:
	MethodModule(char *name, void *handle);

	void start();
};

#endif;
