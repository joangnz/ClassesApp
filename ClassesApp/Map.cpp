#include "Map.h"

string Map::map[height][width];
int Map::_npc = -1;

// getters
int Map::getHeight() {
	return height;
}

int Map::getWidth() {
	return width;
}

int Map::getNpc() {
	return _npc;
}

// setters
void Map::setMap() {
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (j == 0 || j == width - 1) {
				map[i][j] = "#";
			}
			else if (i == 0 || i == height - 1) {
				map[i][j] = "#";
			}
			else {
				map[i][j] = " ";
			}
		}
	}
}

void Map::setNpc(int npc) {
	_npc = npc;
}

// methods
void Map::initMap() {
	setMap();
}

void Map::printMap(Characters Player) {
	for (int i = 0; i < getHeight(); i++)
	{
		for (int j = 0; j < getWidth(); j++) {
			if (j == Player.getPositionX() && i == Player.getPositionY())
				cout << "8";

			else cout << map[i][j];
			cout << " ";
		}
		cout << "\n";
	}
}

void Map::updateMap(NonPlayables Array[]) {
	map[Array[0].getCoordinatesX()][Array[0].getCoordinatesY()] = "0";
	map[Array[1].getCoordinatesX()][Array[1].getCoordinatesY()] = "6";
}


void Map::move(Characters& Player) {
	char direction;
	COORD previous = Player.getPosition();
	if (_kbhit) {
		direction = tolower(_getch());

		// TODO CHECK FOR NON PLAYABLES

		switch (direction) {
		case 'w':
			Player.setPositionY(Player.getPositionY() - 1);
			break;
		case 'a':
			Player.setPositionX(Player.getPositionX() - 1);
			break;
		case 's':
			Player.setPositionY(Player.getPositionY() + 1);
			break;
		case 'd':
			Player.setPositionX(Player.getPositionX() + 1);
			break;
		case ' ':
			interact(Player, 1);
			break;
		}

		if (map[Player.getPositionX()][Player.getPositionY()] == "0") {
			Player.setPosition(previous.X, previous.Y);
		}
		else if (map[Player.getPositionX()][Player.getPositionY()] == "6") {
			Player.setPosition(previous.X, previous.Y);
		}
		else if (map[Player.getPositionX()][Player.getPositionY()] == "#") {
			Player.setPosition(previous.X, previous.Y);
		}
	}
}

void Map::interact(Characters Player, int action) {
	bool loop = true;
	char direction;
	int _nearbyNPC = nearbyNPC(Player);

	if (_nearbyNPC != 0) {
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0,0 });

		printFightDialog(action);

		while (loop) {
			Utility::wait(80);
			if (_kbhit()) {
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0,0 });

				direction = tolower((_getch()));
				switch (direction) {
				case 'a':
					action--;
					if (action <= 0) {
						action = 2;
					}
					else if (action >= 3) {
						action = 1;
					}
					printFightDialog(action);
					// set action -1
					// cycle left
					break;
				case 'd':
					action++;
					if (action <= 0) {
						action = 2;
					}
					else if (action >= 3) {
						action = 1;
					}
					printFightDialog(action);
					// set action +1
					// cycle right
					break;
				case ' ':
					choose(action);
					setNpc(_nearbyNPC);
					loop = false;
					break;
				}
			}
		}

	}

}

void Map::choose(int action) {
	if (action == 1) {
		Combat::setFighting(true);
	}
}


int Map::nearbyNPC(Characters Player) {
	if (
		(map[Player.getPositionX() + 1][Player.getPositionY()] == "0")
		|| (map[Player.getPositionX() - 1][Player.getPositionY()] == "0")
		|| (map[Player.getPositionX()][Player.getPositionY() - 1] == "0")
		|| (map[Player.getPositionX()][Player.getPositionY() + 1] == "0")
		)	return 1;
	else if (
		(map[Player.getPositionX() + 1][Player.getPositionY()] == "6")
		|| (map[Player.getPositionX() - 1][Player.getPositionY()] == "6")
		|| (map[Player.getPositionX()][Player.getPositionY() - 1] == "6")
		|| (map[Player.getPositionX()][Player.getPositionY() + 1] == "6")
		) return 2;
	else return 0;
}

void Map::printFightDialog(int current) {
	printDialogBoxLine();
	printEmptyDialogLine();
	cout << "#\t\tDo you want to fight?";
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { (short)(getWidth() * 2 - 2), 2 });
	cout << "#\n";
	printEmptyDialogLine();

	switch (current) {
	case 1:
		cout << "#\t\t\033[0;30;47mYes\t\t\033[1;37;40mNo";
		break;
	case 2:
		cout << "#\t\t\033[1;37;40mYes\t\t\033[0;30;47mNo";
		break;
	}

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { (short)(getWidth() * 2 - 2), 4 });
	cout << "\033[0;34m#\n";

	printDialogBoxLine();

	cout << "\033[1;37m\n"; // reset color
}

void Map::printDialogBoxLine() {
	for (int i = 0; i < getWidth(); i++)
	{
		cout << "\033[0;34m# ";
	} cout << "\n";
}

void Map::printEmptyDialogLine() {
	cout << "# ";
	for (int i = 0; i < getWidth() - 2; i++)
	{
		cout << "  ";
	}
	cout << "#\n";
}