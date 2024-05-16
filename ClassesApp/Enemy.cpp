#include "Enemy.h"

using namespace std;

/*
---------------------------------------------------------------------
Getters
---------------------------------------------------------------------
*/
int Enemy::getHealthPoints() {
	return _healthPoints;
}

int Enemy::getAttackDmg() {
	return _attackDmg;
}

int Enemy::getSuperAttack() {
	return _superAttack;
}

string Enemy::getEnemyName() {
	return _name;
}

/*
---------------------------------------------------------------------
Setters
---------------------------------------------------------------------
*/
void Enemy::setHealthPoints(int hp) {
	_healthPoints = hp;

	if (_healthPoints < 0) {
		_healthPoints = 0;
	}
}

void Enemy::setAttackDmg(int dmg) {
	_attackDmg = dmg;
}

void Enemy::setSuperAttack(int dmg) {
	_superAttack = dmg;
}

void Enemy::setEnemyName(string name) {
	_name = name;
}

/*
---------------------------------------------------------------------
Builders
---------------------------------------------------------------------
*/
// Normal Enemy, no super 
void Enemy::createEnemy(string name, int hp, int dmg) {
	setEnemyName(name);
	setHealthPoints(hp);
	setAttackDmg(dmg);
}

// Special Enemy, include a fourth parameter for the superAttack DMG
void Enemy::createEnemy(string name, int hp, int dmg, int superdmg) {
	setEnemyName(name);
	setHealthPoints(hp);
	setAttackDmg(dmg);
	setSuperAttack(superdmg);
}

/*
---------------------------------------------------------------------
Methods
---------------------------------------------------------------------
*/

//Returns all attributes
void Enemy::getAttributes() {
	cout << getEnemyName() << "\nHP " << getHealthPoints() << "\nDMG "
		<< getAttackDmg() << "\nSuper Attack " << getSuperAttack() << "\n";
}