#include "Combat.h"

using namespace std;

int Combat::_currentAction = 0;
int Combat::_attackTime = 10;
bool Combat::_fighting = false;
bool Combat::_turn = true;
bool Combat::_attacking = true;
string Combat::sprite[10];
string Combat::attackMeter[10][50];
int attackMeterWidth = 50, attackMeterHeight = 10;

int Combat::getCurrentAction() {
	return _currentAction;
}

int Combat::getAttackTime() {
	return _attackTime;
}

bool Combat::getFighting() {
	return _fighting;
}

bool Combat::getTurn() {
	return _turn;
}

bool Combat::getAttacking() {
	return _attacking;
}

void Combat::initSprite() {
	sprite[0] = " ##########         ";
	sprite[1] = " #        ##      # ";
	sprite[2] = "#  #  #     ###  # #";
	sprite[3] = "# # ## #       ##  #";
	sprite[4] = "#  ####            #";
	sprite[5] = "#                  #";
	sprite[6] = "#                  #";
	sprite[7] = " #  ##  ####  ##  # ";
	sprite[8] = " # ### ##  # ### ## ";
	sprite[9] = "  #   #     #   #   ";
}

void Combat::initAttackMeter(Characters Player) {
	for (int i = 0; i < attackMeterHeight; i++)
	{
		for (int j = 0; j < attackMeterWidth; j++)
		{
			if (i == 0 || i == attackMeterHeight - 1 || j == 0 || j == attackMeterWidth - 1)
				attackMeter[i][j] = "#";
			else if (
				j < attackMeterWidth / 2 - Player.getAtk() / 3 - 3 ||
				j > attackMeterWidth / 2 + Player.getAtk() / 3 + 3
				) {
				attackMeter[i][j] = " ";
			}
			else if (
				j < attackMeterWidth / 2 - Player.getAtk() / 3 ||
				j > attackMeterWidth / 2 + Player.getAtk() / 3
				) {
				attackMeter[i][j] = "|";
			}
			else attackMeter[i][j] = ".";
		}
	}
}


void Combat::setCurrentAction(int action) {
	_currentAction = action;
}

void Combat::setAttackTime(int attackTime) {
	_attackTime = attackTime;
}

void Combat::setFighting(bool fighting) {
	_fighting = fighting;
}

void Combat::setTurn(bool turn) {
	_turn = turn;
}

void Combat::setAttacking(bool attacking) {
	_attacking = attacking;
}

void Combat::printScreen(Characters Player, Enemy Enemy) {
	system("cls");

	cout << "\t\t\t\t\t\t\t\t   _____ ____  __  __ ____       _______ \n";
	cout << "\t\t\t\t\t\t\t\t  / ____/ __ \\|  \\/  |  _ \\   /\\|__   __|\n";
	cout << "\t\t\t\t\t\t\t\t | |   | |  | | \\  / | |_) | /  \\  | |   \n";
	cout << "\t\t\t\t\t\t\t\t | |   | |  | | |\\/| |  _ < / /\\ \\ | |   \n";
	cout << "\t\t\t\t\t\t\t\t | |___| |__| | |  | | |_) / ____ \\| |   \n";
	cout << "\t\t\t\t\t\t\t\t  \\_____\\____/|_|  |_|____/_/    \\_\\_|   \n";

	cout << "\n\n";

	printSprite();

	printHealthBars(Player, Enemy);

	printActions(getCurrentAction() + 1);

}

void Combat::printSprite() {
	for (int i = 0; i < sizeof(sprite) / sizeof(string); i++)
	{
		cout << "\t\t\t\t\t\t\t\t\t" << sprite[i] << "\n";
	}

}

void Combat::printHealthBars(Characters Player, Enemy Enemy) {
	int enemyMaxHP = 10;

	cout << "\t\t\t\t\t\t\tDoggo: ";

  	for (int i = 0; i < enemyMaxHP; i++)
	{
		if (Enemy.getHealthPoints() / 10 >= i) {
			cout << "\033[0;30;47m \033[1;37;40m";
		}
		else {
			cout << ".";
		}
	}

	cout << "\t\tPlayer: ";
	for (int i = 0; i < Player.getMaxHP(); i++)
	{
		if (Player.getHP() >= i) {
			cout << "\033[0;30;47m \033[1;37;40m";
		}
		else {
			cout << ".";
		}
	}
	cout << "\n\n";

}

void Combat::printAttackMeter() {
	for (int i = 0; i < attackMeterHeight; i++)
	{
		cout << "\t\t\t\t";
		for (int j = 0; j < attackMeterWidth; j++)
		{
			if (attackMeter[i][j] == ".") {
				cout << "\033[0;30;47m";
			}
			cout << attackMeter[i][j] << " \033[1;37;40m";
		}
		cout << "\n";
	}

	system("pause");
}

void Combat::printAttackMeter(int i, int j) {
	if (attackMeter[i][j] == ".") {
		cout << "\033[0;30;47m ";
	}
	else {
		cout << "\033[1;37;40m" << attackMeter[i][j];
	}
}

string Combat::getAttackMeter(int i, int j) {
	return attackMeter[i][j];
}

void Combat::printActions(int current) {
	switch (current) {
	case 1:
		printAttack();
		break;
	case 2:
		printTalk();
		break;
	case 3:
		printMercy();
		break;
	case 4:
		printFlee();
		break;
	}
}

void Combat::printAttack() {
	cout << "\033[0;30;47m";

	cout << "\t\t\t\t\t\t\t\t  ______ _____ _____ _    _ _______ \n";
	cout << "\t\t\t\t\t\t\t\t |  ____|_   _/ ____| |  | |__   __|\n";
	cout << "\t\t\t\t\t\t\t\t | |__    | || |  __| |__| |  | |   \n";
	cout << "\t\t\t\t\t\t\t\t |  __|   | || | |_ |  __  |  | |   \n";
	cout << "\t\t\t\t\t\t\t\t | |     _| || |__| | |  | |  | |   \n";
	cout << "\t\t\t\t\t\t\t\t |_|    |_____\\_____|_|  |_|  |_|   \n";

	cout << "\033[1;37;40m";
}

void Combat::printTalk() {
	cout << "\033[0;30;47m";


	cout << "\t\t\t\t\t\t\t\t  _______       _      _  __ \n";
	cout << "\t\t\t\t\t\t\t\t |__   __|/\\   | |    | |/ / \n";
	cout << "\t\t\t\t\t\t\t\t    | |  /  \\  | |    | ' /  \n";
	cout << "\t\t\t\t\t\t\t\t    | | / /\\ \\ | |    |  <   \n";
	cout << "\t\t\t\t\t\t\t\t    | |/ ____ \\| |____| . \\  \n";
	cout << "\t\t\t\t\t\t\t\t    |_/_/    \\_\\______|_|\\_\\ \n";

	cout << "\033[1;37;40m";
}

void Combat::printMercy() {
	cout << "\033[0;30;47m";

	cout << "\t\t\t\t\t\t\t\t  __  __ ______ _____   _______     __\n";
	cout << "\t\t\t\t\t\t\t\t |  \\/  |  ____|  __ \\ / ____\\ \\   / /\n";
	cout << "\t\t\t\t\t\t\t\t | \\  / | |__  | |__) | |     \\ \\_/ / \n";
	cout << "\t\t\t\t\t\t\t\t | |\\/| |  __| |  _  /| |      \\   /  \n";
	cout << "\t\t\t\t\t\t\t\t | |  | | |____| | \\ \\| |____   | |   \n";
	cout << "\t\t\t\t\t\t\t\t |_|  |_|______|_|  \\_\\\\_____|  |_|   \n";

	cout << "\033[1;37;40m";
}

void Combat::printFlee() {
	cout << "\033[0;30;47m";

	cout << "\t\t\t\t\t\t\t\t  ______ _      ______ ______ \n";
	cout << "\t\t\t\t\t\t\t\t |  ____| |    |  ____|  ____|\n";
	cout << "\t\t\t\t\t\t\t\t | |__  | |    | |__  | |__   \n";
	cout << "\t\t\t\t\t\t\t\t |  __| | |    |  __| |  __|  \n";
	cout << "\t\t\t\t\t\t\t\t | |    | |____| |____| |____ \n";
	cout << "\t\t\t\t\t\t\t\t |_|    |______|______|______|\n";

	cout << "\033[1;37;40m";
}

void Combat::selectCurrentAction(int action, Characters& Player, Enemy& Enemy) {
	switch (action + 1) {
	case 1:
		attack(Player, Enemy);
		break;
	case 2:
		talk(Player, Enemy);
		break;
	case 3:
		mercy(Player, Enemy);
		break;
	case 4:
		flee(Player, Enemy);
		break;
	}
}

void Combat::changeAction(Characters& Player, Enemy& Enemy) {
	char dir;
	while (true) {
		Utility::wait(80);
		if (_kbhit()) {
			dir = tolower(_getch());
			break;
		}
	}

	if (dir == 'd') {
		_currentAction + 1 > 3 ? _currentAction = 0 : (_currentAction++);
	}
	else if (dir == 'a') {
		_currentAction - 1 < 0 ? _currentAction = 3 : _currentAction--;
	}
	else if (dir == ' ') {
		selectCurrentAction(_currentAction, Player, Enemy);
		setTurn(false);
	}

}

void Combat::start(Characters& Player, Enemy& Enemy) {
	// BGM.wav must be in folder ClassesApp\ClassesApp\
	// can be changed by any .wav file as long as the name is still "BGM.wav"

	PlaySound(TEXT("BGM.wav"), NULL, SND_FILENAME | SND_ASYNC);

	initSprite();
	initAttackMeter(Player);
	setFighting(true);
	while (getFighting()) {
		do {
			printScreen(Player, Enemy);
			changeAction(Player, Enemy);
		} while (getTurn());
		
		// Enemy attacks
		int chance = rand() % 5 + 1;
		if (chance == 5) {
			cout << "Doggo throws a super attack!";
			Utility::wait(1500);
			Player.setHP(Player.getHP() - Enemy.getSuperAttack() - Player.getDef() * 2);
		}
		else {
			if (Player.getAgi() < chance * 20) {
				cout << "Doggo attacks you!";
				Utility::wait(1500);
				Player.setHP(Player.getHP() - (Enemy.getAttackDmg() - Player.getDef()*4/10));
				Player.setAgi(Player.getAgi() - 1);
			}
			else {
				cout << "You dodged the attack!";
			}
		}

		if (Player.getHP() < 0) {
			setFighting(false);
		}
		else {
			setTurn(true);
		}

		if (Player.getAgi() < 5) {
			Player.setAgi(Player.getDefaultAgi());
		}

		if (Player.getHP() <= 0) setFighting(false);
		else if (Enemy.getHealthPoints() <= 0) setFighting(false);

	}

	cout << "\n\n";
}


void Combat::attack(Characters& Player, Enemy& Enemy) {
	system("pause");
	setAttacking(true);
	int moment = 1;
	int damage = 0;

	do {
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0,30 });

		for (int i = 0; i < attackMeterHeight; i++)
		{
			cout << "\t\t\t\t";

			for (int j = 0; j < attackMeterWidth; j++)
			{
				if (j == moment) {
					cout << "\033[0;34;44m" << getAttackMeter(i, j);
				}
				else {
					printAttackMeter(i, j);
				}
				cout << " \033[1;37;40m";
			}
			cout << "\n";
		}

		moment++;

		Utility::wait(20 + Player.getAgi() * 0.6);

		if (_kbhit()) {
			char in = _getch();
			int chance = rand() % 100 + 1;

			switch (in) {
			case ' ':
				if (chance < Player.getAtkCh()) {
					if (attackMeter[5][moment]._Equal(".")) {
						Enemy.setHealthPoints(Enemy.getHealthPoints() - Player.getAtk());
						cout << "\n\t\t\t\tCritical!\n";
					}
					else if (attackMeter[5][moment]._Equal("|")) {
						Enemy.setHealthPoints(Enemy.getHealthPoints() - Player.getAtk() - 5);
						cout << "\n\t\t\t\tGood hit!\n";
					}
					else {
						Enemy.setHealthPoints(Enemy.getHealthPoints() - Player.getAtk() - 10);
						cout << "\n\t\t\t\tDo better!\n";
					}

					if (Enemy.getHealthPoints() < 0) { Enemy.setHealthPoints(0); }
				}
				else {
					cout << "\n\t\t\t\tAttack failed!\n";
				}

				setAttacking(false);
				break;
			default: break;
			}
		}

		if (moment > attackMeterWidth-2) {
			setAttacking(false);
		}

	} while (getAttacking());
	setAttacking(false);
	system("pause");
}

void Combat::talk(Characters& Player, Enemy& Enemy) {
	if (rand() % 100 + 1 > 90) {
		printDialogBox("talk", true);

		setFighting(false);
	}
	else {

		printDialogBox("talk", false);
	}
}

void Combat::mercy(Characters& Player, Enemy& Enemy) {
	if (Enemy.getHealthPoints() < Enemy.getHealthPoints() * 30 / 100) {

		printDialogBox("mercy", true);

		setFighting(false);
	}
	else {
		printDialogBox("mercy", false);
	}
}

void Combat::flee(Characters& Player, Enemy& Enemy) {
	double fleeChance = rand() % 35 + 1, luckChance = rand() % 30 + 1;

	if (Player.getAgi() + luckChance > fleeChance + Enemy.getAttackDmg()) {
		printDialogBox("flee", true);

		setFighting(false);
	}
	else {
		printDialogBox("flee", false);
	}
}

// UNFINISHED CONTENT, DEFINITELY MUST ADD THIS TO MAKE THE GAME COMPLETE
// COULD IT BE THE SUPER ATTACK INSTEAD OF THE NORMAL ATTACK??
// MAYBE, IT LOOKS INTERESTING
// REMEMBER TO ADD HERITAGE JOAN
void Combat::enemyAttack(Characters& Player, Enemy& Enemy) {
	int size = 10;
	int moment = 0;
	string initBox[10][10];
	string combatBox[10][10];
	string attackHitbox[8] =
	{" ","8"," ","8"," "," ","8","8"};

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (i == 0 || i == 9 || j == 0 || j == 9) {
				combatBox[i][j] = "#";
				initBox[i][j] = "#";
			}
			else {
				combatBox[i][j] = " ";
				initBox[i][j] = " ";
			}
		}
	}
	 // WHILE ATTACK REPRINT THE COMBAT BOX WITH THE CHARACTER
	while (moment < size) {

		// SET CURSOR AND PRINT COMBAT BOX
		


		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				// if i == moment print attackHitbox.j
				if (i == Player.getCombatPosX() && j == Player.getCombatPosY())
					cout << "O";
				else cout << combatBox[i][j]; // NOT FINISHED
			}
		}

		// if combatBox[Player.getPosition] = AttackSprite then take damage
		if (combatBox[Player.getCombatPosX()][Player.getCombatPosY()]._Equal("@")) {
			// need a formula
			Player.setHP(Player.getHP() - 3);
		}

	}

}

void Combat::printDialogBox(string type, bool success) {
	string messages[4][2] = {
		{"Woof! Woofbye! Barking dogs never bite.","Where are you going! Don't woof away!"}, // flee t/f
		{"Awoo... I'm sorry I barked at you first...","We're not wover yet, woof!"}, // mercy t/f
		{"I guess you're not wrong... I'll go piss somewhere...","That's cat shit! I wof't believe it!"}, // talk t/f
		{"WHAT HOW DID WOO GET HERE","WOO'VE LIKE MEGA MESSED UP"} // shouldn't have gotten here t/f
	};
	int x, y;

	cout << "\n\n\t\t\t\t";
	if (type._Equal("flee")) {
		x = 0;
		if (success) {
			y = 0;
		}
		else {
			y = 1;
		}
	}
	else if (type._Equal("mercy")) {
		x = 1;
		if (success) {
			y = 0;
		}
		else {
			y = 1;
		}
	}
	else if (type._Equal("talk")) {
		x = 2;
		if (success) {
			y = 0;
		}
		else {
			y = 1;
		}
	}
	else {
		x = 3, y = rand() % 2; // if this throws you've somehow chosen a 5th option
		// could make this an achievement
	}

	cout << messages[x][y] << "\n";
	system("pause");
}