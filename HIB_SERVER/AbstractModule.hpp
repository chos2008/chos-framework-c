
#if ! defined ABSTRACT_MODULE
#define ABSTRACT_MODULE 
class AbstractModule 
{
private: 
	char *moduleName;

public:
	AbstractModule(const char *name);

	void load();

	void start();
};

class ModuleManager 
{
public:
	void loadModule(AbstractModule &module);
};
#endif;
