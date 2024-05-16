#pragma once
#include "Header.h"
#include "Characters.h"
#include "NonPlayables.h"
#include "Utility.h"
#include "Combat.h"

using namespace std;

class Map
{
private:
	static int height, width;
	static string map[30][30];
public:
	static int getHeight(), getWidth();

	static void setHeight(int pHeight), setWidth(int pWidth);
	static void setMap();

	static void initMap(); // Initial config
	static void printMap(Characters Player); // Prints the map
	static void updateMap(NonPlayables Array[]); // Adds the NPCs to the map
	static void move(Characters &Player); // Moves the player
	static void interact(Characters Player, int action);
	static void choose(int action);
	static bool nearbyNPC(Characters Player);
	static void printFightDialog(int current);
	static void printDialogBoxLine();
	static void printEmptyDialogLine();
};

