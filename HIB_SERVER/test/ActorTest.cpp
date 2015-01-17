#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "../gs/Actor.h"

class SubActorPrivateInheritFromActor : private Actor
{
public:
	SubActorPrivateInheritFromActor(char *name) : Actor(name) 
	{
		//printf("name£º %s\n", this->name); // error C2248: 'name' : cannot access private member declared in class 'Actor'
		printf("name£º %s\n", this->getName());
	}
};

class SubActorProtectedInheritFromActor : protected Actor
{
public:
	SubActorProtectedInheritFromActor(char *name) : Actor(name)
	{
		//printf("name£º %s\n", this->name); // error C2248: 'name' : cannot access private member declared in class 'Actor'
		printf("name£º %s\n", this->getName());
	}
};

class SubActorPublicInheritFromActor : public Actor
{
public:
	SubActorPublicInheritFromActor(char *name) : Actor(name)
	{
		//printf("name£º %s\n", this->name); // error C2248: 'name' : cannot access private member declared in class 'Actor'
		printf("name£º %s\n", this->getName());
	}
};

void main()
{
	char *name = "ºÚ°µÆÆ»µÉñ";
	Actor actor(name);
	printf("Actor name: %s\n", actor.getName());
	assert (strcmp(actor.getName(), name) == 0);

	SubActorPrivateInheritFromActor actor1(name);
	//printf("Actor name: %s\n", actor1.getName()); // error C2248: 'getName' : cannot access public member declared in class 'Actor'
	//assert (strcmp(actor1.getName(), name) == 0); // error C2248: 'getName' : cannot access public member declared in class 'Actor'

	SubActorProtectedInheritFromActor actor2(name);
	//printf("Actor name: %s\n", actor2.getName()); // error C2248: 'getName' : cannot access public member declared in class 'Actor'
	//assert (strcmp(actor2.getName(), name) == 0); // error C2248: 'getName' : cannot access public member declared in class 'Actor'

	SubActorPublicInheritFromActor actor3(name);
	printf("Actor name: %s\n", actor3.getName());
	assert (strcmp(actor3.getName(), name) == 0);
}