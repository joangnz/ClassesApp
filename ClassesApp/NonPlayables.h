#pragma once
#include "Header.h"

using namespace std;

class NonPlayables
{
private:
	int _id;
	COORD _coordinates;
	char _char;
	static int _npcCount;

public:
	// methods
	void speak();

	// getters
	int getId();
	COORD getCoordinates();
	int getCoordinatesX();
	int getCoordinatesY();
	char getChar();
	static int getNpcCount();

	// setters
	void setId(int id);
	void setCoordinates(int x, int y);
	void setCoordinatesX(int x);
	void setCoordinatesY(int y);
	void setChar(char character);
	static void setNpcCount(int count);

	// builder
	void buildCharacter(int id, int x, int y);
};

