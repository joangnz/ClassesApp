#pragma once
#include "Header.h"

using namespace std;

class Characters
{
private:
	// Character Attributes
	int _id = -1; // Character ID, ranging from 0 to 3
	int _maxHP = -1; // Character Maximum Health Points
	int _hp = -1; // Character Health Points
	int _atk = -1; // Character Atk
	int _def = -1; // Character Defense
	int _agi = -1; // Character Agility
	int _defaultAgi = -1; // Character Default Agility
	int _atkCh = -1; // Character Attack Success Chance
	string _characterName = "";
	bool _chosen = false;
	COORD _position;
	COORD _combatPos;

public:

	// Getters
	int getID();
	int getMaxHP();
	int getHP();
	int getAtk();
	int getDef();
	int getAgi();
	int getDefaultAgi();
	int getAtkCh();
	string getName();
	bool getChosen();
	COORD getPosition();
	int getPositionX();
	int getPositionY();
	COORD getCombatPos();
	int getCombatPosX();
	int getCombatPosY();

	// Setters
	void setID(int id);
	void setMaxHP(int maxHp);
	void setHP(int hp);
	void setAtk(int atk);
	void setDef(int def);
	void setAgi(int agi);
	void setDefaultAgi(int defaultAgi);
	void setAtkCh(int atkCh);
	void setName(string name);
	void setChosen(bool chosen);
	void setPositionX(int x);
	void setPositionY(int y);
	void setPosition(int x, int y);
	void setCombatPosX(int x);
	void setCombatPosY(int y);
	void setCombatPos(int x, int y);

	// Builders
	void createCharacter(int id);
};