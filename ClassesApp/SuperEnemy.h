#pragma once
#include "Enemy.h"
class SuperEnemy : public Enemy
{
private:
	int _superDmg;
public:
	SuperEnemy(string name, int hp, int dmg, int superDmg);

	int getSuperDmg();

	void setSuperDmg(int superDmg);
};

