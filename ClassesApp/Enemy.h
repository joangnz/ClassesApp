#pragma once
#include "Header.h"

using namespace std;

class Enemy
{
private:
	int _healthPoints = 0;
	int _attackDmg = 0;
	string _name = "unnamed";

public:
	// getters
	int getHealthPoints();
	int getAttackDmg();
	string getEnemyName();

	// setters
	void setHealthPoints(int hp);
	void setAttackDmg(int dmg);
	void setEnemyName(string name);

	// builders
	Enemy(string name, int hp, int dmg);
};