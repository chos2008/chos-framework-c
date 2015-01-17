#include <stdlib.h>

#include "Actor.h"

#ifndef __DEFENDER
#define __DEFENDER
class Defender : public Actor 
{
private:
	int level;

    /* health point */
    int hp;

    /* �������� �����ر�˵����<code>def</code>����ָ��������� */
	int def;

	/* �������� �����ر�˵����<code>atk</code>����ָ�������� */
	int atk;

	/* �˺��� ���ι�����ɵ��˺� */
    int baseDps;

public:
	Defender() : Actor(NULL)
	{
	
	}

	Defender(char *name, int level) : Actor(name)
	{
	    this->level = level;
	}

	int getLevel()
	{
	    return level;
	}

	int getDef()
	{
	    return this->def;
	}

	int getAtk()
	{
	    return this->atk;
	}

    /**
	 * ��Ч����ֵ,Ҳ�������Ϊ���������.
	 *
	 * EHP��һ�з��������Ե��ۺ�����,���з��������Եļ�ֵ���������EHP.
	 */
	int getEhp() {
	    return 0;
	}

	/**
	 * EDPS��Ч�˺�ֵ,Ҳ�������Ϊ�������.
	 *
	 * EDPS��һ�й��������Ե��ۺ�����,���й��������Եļ�ֵ���������EDPS.
	 *
	 *
	 * EDPS ��ͬ�� DPS ?
	 *
	 *
	 * DPS(Demage Per Second) ÿ���˺��������˺�ֵ
	 *
	 * �����˺�ֵ= ���������˺���������+max��1��װ�������˺��˺����������� 
	 */
	int dps() {
		return baseDps + atk / baseDps;
	}
};
#endif