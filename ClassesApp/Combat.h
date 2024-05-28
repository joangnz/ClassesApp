#pragma once
#include "Header.h"
#include "Characters.h"
#include "Enemy.h"
#include "SuperEnemy.h"
#include "Utility.h"

using namespace std;

class Combat
{
private:
	static int _currentAction;
	static int _attackTime;
	static bool _fighting;
	static bool _turn;
	static bool _attacking;
	static string sprite[];
	static string attackMeter[10][50];
	static string enemy;
public:
	static int getCurrentAction();
	static int getAttackTime();
	static bool getFighting();
	static bool getTurn();
	static bool getAttacking();

	static void initSprite();
	static void initAttackMeter(Characters Player);

	static void setCurrentAction(int action);
	static void setAttackTime(int attackTime);
	static void setFighting(bool fighting);
	static void setTurn(bool turn);
	static void setAttacking(bool attacking);

	static void printScreen(Characters Player, Enemy Enemy);
	static void printSprite(); // Print enemy sprite
	static void printHealthBars(Characters Player, Enemy Enemy);
	static void printAttackMeter();
	static void printAttackMeter(int i, int j); // Prints the attackMeter[i][j]
	static string getAttackMeter(int i, int j); // Gets the attackMeter[i][j]
	static void printActions(int current); // Print possible actions, first one selected by default
	static void printAttack();
	static void printTalk();
	static void printMercy();
	static void printFlee();

	static void selectCurrentAction(int action, Characters& Player, Enemy& Enemy); // Select Action
	static void changeAction(Characters& Player, Enemy& Enemy); // Change action to next/former

	static void start(Characters& Player, Enemy& Enemy);
	static void start(Characters& Player, SuperEnemy& Enemy);
	static void attack(Characters& Player, Enemy& Enemy);
	static void talk(Characters& Player, Enemy& Enemy);
	static void mercy(Characters& Player, Enemy& Enemy);
	static void flee(Characters& Player, Enemy& Enemy);

	static void enemyAttack(Characters& Player, SuperEnemy& Enemy);
	static void move(Characters& Player);

	static void printDialogBox(string type, bool success);
};