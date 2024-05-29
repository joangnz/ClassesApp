#include "NonPlayables.h"

using namespace std;

int NonPlayables::_npcCount = 0;

// methods
void NonPlayables::speak() {
	switch (_id) {

	default:
		break;
	}
}

// getters
int NonPlayables::getId() {
	return _id;
}

COORD NonPlayables::getCoordinates() {
	return _coordinates;
}

int NonPlayables::getCoordinatesX() {
	return _coordinates.X;
}

int NonPlayables::getCoordinatesY() {
	return _coordinates.Y;
}

char NonPlayables::getChar() {
	return _char;
}

int NonPlayables::getNpcCount() {
	return _npcCount;
}

// setters
void NonPlayables::setId(int id) {
	_id = id;
}

void NonPlayables::setCoordinates(int x, int y) {
	setCoordinatesX(x);
	setCoordinatesY(y);
}

void NonPlayables::setCoordinatesX(int x) {
	_coordinates.X = x;
}

void NonPlayables::setCoordinatesY(int y) {
	_coordinates.Y = y;
}

void NonPlayables::setChar(char character) {
	_char = character;
}

void NonPlayables::setNpcCount(int count) {
	_npcCount = count;
}

// builder
void NonPlayables::buildCharacter(int id, int x, int y) {
	setId(id);
	setCoordinates(x, y);
	setNpcCount(getNpcCount() + 1);
}