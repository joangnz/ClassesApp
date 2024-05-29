#pragma once
#include "Enemy.h"
class SuperEnemy : public Enemy
{
private:
	int _superDmg;
public:
	int getSuperDmg();

	void setSuperDmg(int superDmg);

	SuperEnemy(string name, int hp, int dmg, int superDmg);
};

