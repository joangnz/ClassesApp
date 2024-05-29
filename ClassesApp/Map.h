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
	static const int height = 30, width = 30;
	static string map[height][width];
	static int _npc;
public:

	// getters
	static int getHeight(), getWidth();
	static int getNpc();

	// setters
	static void setMap();
	static void setNpc(int npc);

	// methods
	static void initMap(); // Initial config
	static void printMap(Characters Player); // Prints the map
	static void updateMap(NonPlayables Array[]); // Adds the NPCs to the map
	static void move(Characters& Player); // Moves the player
	static void interact(Characters Player, int action);
	static void choose(int action);
	static int nearbyNPC(Characters Player);
	static void printFightDialog(int current);
	static void printDialogBoxLine();
	static void printEmptyDialogLine();
};

