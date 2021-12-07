/***************************************************************************
** File: Wumpus.cpp
** Author: Jake Statz		
** Date: 05/23/2020
** Description: The fucntions that make up the wumpus event
**************************************************************************/

#include "Wumpus.h"
#include "Game.h"
#include <iostream>

using namespace std;

Wumpus::Wumpus(int r, int c) {
	row = r;
	column = c;
}

void Wumpus::percept() {
	cout << "You smell a terrible stench." << endl;
}

bool Wumpus::encounter(Game& g) {
	cout << "The wumpus overpowers you." << endl;
	return true;
}

char Wumpus::letter() {
	return 'W';
}