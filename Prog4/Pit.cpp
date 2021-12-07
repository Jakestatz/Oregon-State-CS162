/***************************************************************************
** File: Pit.cpp
** Author: Jake Statz
** Date: 05/23/2020
** Description: The fucntions that make up the pit event
**************************************************************************/

#include "Pit.h"
#include "Game.h"
#include <iostream>

using namespace std;

Pit::Pit(int r, int c) {
	row = r;
	column = c;
}

void Pit::percept() {
	cout << "You feel a breeze." << endl;
}

bool Pit::encounter(Game& g) {
	cout << "You fell into a pit" << endl;
	return true;
}

char Pit::letter() {
	return 'P';
}