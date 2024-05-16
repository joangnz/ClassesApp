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
	void speak();

	int getId();
	COORD getCoordinates();
	int getCoordinatesX();
	int getCoordinatesY();
	char getChar();
	static int getNpcCount();

	void setId(int id);
	void setCoordinates(int x, int y);
	void setCoordinatesX(int x);
	void setCoordinatesY(int y);
	void setChar(char character);
	static void setNpcCount(int count);

	void buildCharacter(int id, int x, int y);
};

