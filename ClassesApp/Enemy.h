#pragma once
#include "Header.h"

using namespace std;

class Enemy
{
private:
	int _healthPoints = 0;
	int _attackDmg = 0;
	int _superAttack = 0;
	string _name = "unnamed";

public:
	// getters
	int getHealthPoints();
	int getAttackDmg();
	int getSuperAttack();
	string getEnemyName();

	// setters
	void setHealthPoints(int hp);
	void setAttackDmg(int dmg);
	void setSuperAttack(int dmg);
	void setEnemyName(string name);

	// builders
	void createEnemy(string name, int hp, int dmg);
	void createEnemy(string name, int hp, int dmg, int superdmg);

	// methods
	void getAttributes();
};