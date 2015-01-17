/*
 *
 *
 * @author ada
 * @version 1.0
 * @since 1.0
 */
#if ! defined PTHREAD_MODULE
#define PTHREAD_MODULE 

class PThreadModule 
{
private: 
	char *moduleName;

	void *(*lpStartAddress) (void *);

	void * arg;

public:
	PThreadModule(const char *name, void *(*lpStartAddress) (void *));

	PThreadModule(const char *name, void *(*lpStartAddress) (void *), void * arg);

	void init();

	void start();

	void destroy();
};
#endif
