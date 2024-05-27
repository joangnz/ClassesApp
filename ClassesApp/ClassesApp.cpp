#include "Classes.h"

using namespace std;

int main()
{
	srand(time(NULL));
	bool choosing = true;
	NonPlayables nonPlayablesArray[3];

	Characters Player;

	NonPlayables Zero;
	Zero.buildCharacter(1, 20, 20);

	nonPlayablesArray[0] = Zero;

	Enemy Doggo("Doggo", 100, 2);

	SuperEnemy Doggy("Doggy", 100, 2, 4);

	Selection::printPage(Selection::getPage());

	system("pause");
	system("cls");

	while (choosing)
	{
		Selection::nextPage(); // Goes to the next page

		for (int i = 0; i < 5; i++) // Waits 5 seconds checking for input every time
		{
			if (Selection::checkSelect(Player)) {
				i = 5;
				break;
			}
		}

		if (Player.getChosen())
		{
			choosing = false;
			Player.createCharacter(Player.getID());
			Player.setPosition(15, 15);
		}
	}

	system("cls");

	Map::initMap();
	Map::updateMap(nonPlayablesArray);
	Map::printMap(Player);
	while (!Combat::getFighting())
	{
		Map::move(Player);
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0,0 });
		Map::printMap(Player);
	}

	system("cls");

	// if superFight then fight doggy, else fight doggo
	if (true) {
		Combat::start(Player, Doggy);
	}
	else {
		Combat::start(Player, Doggo);
	}

	PlaySound(NULL, NULL, SND_FILENAME | SND_ASYNC); // STOP MUSIC

	system("cls");
	if (Player.getHP() <= 0) cout << "You've died.";
	else cout << "You won.\n";
	cout << "Game Over.\n\n";
}