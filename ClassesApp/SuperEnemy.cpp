#include "SuperEnemy.h"

SuperEnemy::SuperEnemy(
	string name,
	int hp,
	int dmg,
	int superDmg) : Enemy(
		name,
		hp,
		dmg)
{
	_superDmg = superDmg;
}

int SuperEnemy::getSuperDmg() {
	return _superDmg;
}

void SuperEnemy::setSuperDmg(int superDmg) {
	_superDmg = superDmg;
}