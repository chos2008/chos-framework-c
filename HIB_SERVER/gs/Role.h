#include "Skill.h"

#ifndef ROLE
#define ROLE

class Role 
{
private:

	// 天赋技能，角色与生俱来的自然有的天生技能，如天生神力。
	vector<Skill> defaultSkills;

	// 后天获得开启的技能
	vector<Skill> skills;

public:

	vector<Skill> getDefaultSkills();

	vector<Skill> getSkills();
};

#endif