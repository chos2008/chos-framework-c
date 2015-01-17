#include "Actor.h"

Actor::Actor(char *name)
{
	this->name = name;
}

char* Actor::getName()
{
	return this->name;
}