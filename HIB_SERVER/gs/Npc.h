#include "Actor.h"

#if ! defined __NPC
#define __NPC
class Npc : public Actor 
{
public:
	Npc(char *name);
};
#endif;