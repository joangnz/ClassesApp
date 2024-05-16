#pragma once
#include "Header.h"
#include "Characters.h"
#include "Utility.h"

using namespace std;

class Selection
{
private:
	static int _page;
public:

	// Getters
	static int getPage();

	// Setters
	static void setPage(int page);
	// Methods
	static void printPage(int page);
	static void nextPage();
	static bool checkSelect(Characters& Player);
};
