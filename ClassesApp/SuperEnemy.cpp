#include "SuperEnemy.h"

// getters
int SuperEnemy::getSuperDmg() {
	return _superDmg;
}

// setters
void SuperEnemy::setSuperDmg(int superDmg) {
	_superDmg = superDmg;
}

// builder
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