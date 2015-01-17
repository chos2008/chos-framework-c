#include <stdlib.h>

#include "Actor.h"

#ifndef __ATTACKER
#define __ATTACKER
class Attacker : public Actor
{
private:
	int level;

    /* health point */
    int hp;

    /* 防御力， 如无特别说明，<code>def</code>都特指物理防御力 */
	int def;

    /* 攻击力， 如无特别说明，<code>atk</code>都特指物理攻击力 */
	int atk;

    /* 伤害， 单次攻击造成的伤害 */
    int baseDps;

public:
    Attacker() : Actor(NULL)
	{
	
	}

	Attacker(char *name, int level) : Actor(name)
	{
	    this->level = level;
	}

	int getLevel() 
	{
	    return level;
	}

	int getAtk() {
	    return atk;
	}

	int getDef() 
	{
	    return def;
	}

    /**
	 * 有效生命值,也可以理解为抗打击能力.
	 *
	 * EHP是一切防御类属性的综合体现,所有防御类属性的价值都在于提高EHP.
	 */
	int getEhp() {
	    return 0;
	}

    /**
	 * EDPS有效伤害值,也可以理解为打击能力.
	 *
	 * EDPS是一切攻击类属性的综合体现,所有攻击类属性的价值都在于提高EDPS.
	 *
	 *
	 * EDPS 等同于 DPS ?
	 *
	 *
	 * DPS(Demage Per Second) 每秒伤害，最终伤害值
	 *
	 * 最终伤害值= 人物属性伤害（除法）+max（1，装备属性伤害伤害（减法）） 
	 */
	int dps() {
		return baseDps + atk / baseDps;
	}
};
#endif