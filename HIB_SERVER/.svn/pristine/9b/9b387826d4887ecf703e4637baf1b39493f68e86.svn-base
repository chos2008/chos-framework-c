
#if ! defined MODULE
#define MODULE 
class Module 
{
private: 
	char *moduleName;

	void *handle;

public:
	Module(const char *name, void *handle);

	char * getModuleName();

	void * getHandle();

	void load();

	virtual void start();
};

#endif;
