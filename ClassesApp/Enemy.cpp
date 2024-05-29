#include "Enemy.h"

using namespace std;

// getters
int Enemy::getHealthPoints() {
	return _healthPoints;
}

int Enemy::getAttackDmg() {
	return _attackDmg;
}

string Enemy::getEnemyName() {
	return _name;
}

// setters
void Enemy::setHealthPoints(int hp) {
	_healthPoints = hp;

	if (_healthPoints < 0) {
		_healthPoints = 0;
	}
}

void Enemy::setAttackDmg(int dmg) {
	_attackDmg = dmg;
}

void Enemy::setEnemyName(string name) {
	_name = name;
}

// builder
Enemy::Enemy(string name, int hp, int dmg) {
	_name = name;
	_healthPoints = hp;
	_attackDmg = dmg;
}