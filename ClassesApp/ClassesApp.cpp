#include "Classes.h"
/*
TRY CHANGING THE CONSTANT PRINTS TO ONLY PRINT WHEN THE PLAYER MOVES,
AND IF POSSIBLE, ONLY CHANGING WHAT'S AROUND THE PLAYER

THIS WILL GIVE BETTER VISUAL OPTIMIZATION AND PROBABLY BETTER PERFORMANCE
*/

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

	Enemy Doggo;

	Doggo.createEnemy("Doggo", 100, 2, 4);

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

	// Add Combat Sequence
	system("cls");
	Combat::start(Player, Doggo);

	PlaySound(NULL, NULL, SND_FILENAME | SND_ASYNC); // STOP MUSIC

	system("cls");
	if (Player.getHP() <= 0) cout << "You've died.";
	else cout << "You won.";
	cout << "Game Over.\n\n";
}