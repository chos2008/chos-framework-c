#if ! defined __INSTANCE_WITH_XOBJECT 
#define __INSTANCE_WITH_XOBJECT 
class InstanceWithXObject 
{
private:
	int id;
	int idx;
	char *name;

	int* drops;

public:
	InstanceWithXObject(int id, int idx, char* name);

	InstanceWithXObject(int id, int idx, char* name, int* drops);
};
#endif;