#include "Npc.h"
#if ! defined MOBILE_NPC
#define MOBILE_NPC
class MobileNpc : public Npc
{
private: 

public:
	void move();
};
#endif;