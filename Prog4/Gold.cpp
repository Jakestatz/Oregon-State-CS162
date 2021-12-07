/***************************************************************************
** File: Gold.cpp
** Author: Jake Statz
** Date: 05/23/2020
** Description: The gold event and it's functions
**************************************************************************/

#include "Gold.h"
#include "Game.h"
#include <iostream>

using namespace std;

Gold::Gold(int r, int c) {
	row = r;
	column = c;
}

void Gold::percept() {
	cout << "You see a glimmer nearby." << endl;
}

bool Gold::encounter(Game& g) {
	cout << "You're basically Scrooge Mcduck now." <<  endl;
	g.get_gold();
	return false;
}

char Gold::letter() {
	return 'G';
}