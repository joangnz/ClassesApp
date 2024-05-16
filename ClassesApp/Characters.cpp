#include "Characters.h"

using namespace std;

/*
---------------------------------------------------------------------
Getters
---------------------------------------------------------------------
*/
int Characters::getID() {
	return _id;
}

int Characters::getMaxHP() {
	return _maxHP;
}

int Characters::getHP() {
	return _hp;
}

int Characters::getAtk() {
	return _atk;
}

int Characters::getDef() {
	return _def;
}

int Characters::getAgi() {
	return _agi;
}

int Characters::getDefaultAgi() {
	return _defaultAgi;
}

int Characters::getAtkCh() {
	return _atkCh;
}

string Characters::getName() {
	return _characterName;
}

bool Characters::getChosen() {
	return _chosen;
}

COORD Characters::getPosition() {
	return _position;
}

int Characters::getPositionX() {
	return _position.X;
}

int Characters::getPositionY() {
	return _position.Y;
}

COORD Characters::getCombatPos() {
	return _combatPos;
}

int Characters::getCombatPosX() {
	return _combatPos.X;
}

int Characters::getCombatPosY() {
	return _combatPos.Y;
}

/*
---------------------------------------------------------------------
Setters
---------------------------------------------------------------------
*/
void Characters::setID(int id) {
	_id = id;
}

void Characters::setMaxHP(int maxHp) {
	_maxHP = maxHp;
}

void Characters::setHP(int hp) {
	_hp = hp;
}

void Characters::setAtk(int atk) {
	_atk = atk;
}

void Characters::setDef(int def) {
	_def = def;
}

void Characters::setAgi(int agi) {
	_agi = agi;
}

void Characters::setDefaultAgi(int defaultAgi) {
	_defaultAgi = defaultAgi;
}

void Characters::setAtkCh(int atkCh) {
	_atkCh = atkCh;
}

void Characters::setName(string name) {
	_characterName = name;
}

void Characters::setChosen(bool chosen) {
	_chosen = chosen;
}

void Characters::setPositionX(int x) {
	_position.X = x;
}

void Characters::setPositionY(int y) {
	_position.Y = y;
}

void Characters::setPosition(int x, int y) {
	setPositionX(x);
	setPositionY(y);
}

void Characters::setCombatPosX(int x) {
	_combatPos.X = x;
}

void Characters::setCombatPosY(int y) {
	_combatPos.Y = y;
}

void Characters::setCombatPos(int x, int y) {
	setCombatPosY(y);
	setCombatPosX(x);
}

/*
---------------------------------------------------------------------
Builders
---------------------------------------------------------------------
*/

void Characters::createCharacter(int id) {
	switch (id) {
	case 0:
		setMaxHP(20);
		setHP(20);
		setAtk(10);
		setDef(5);
		setAgi(10);
		setDefaultAgi(10);
		setAtkCh(95);
		setName("Frisk");
		setPosition(0, 0);
		setCombatPos(4, 4);
		break;
	case 1:
		setMaxHP(20);
		setHP(20);
		setAtk(20);
		setDef(0);
		setAgi(20);
		setDefaultAgi(20);
		setAtkCh(95);
		setName("Chara");
		setPosition(0, 0);
		setCombatPos(4, 4);
		break;
	case 2:
		setMaxHP(5);
		setHP(5);
		setAtk(20);
		setDef(0);
		setAgi(100);
		setDefaultAgi(100);
		setAtkCh(95);
		setName("Sans");
		setPosition(0, 0);
		setCombatPos(4, 4);
		break;
	}
}