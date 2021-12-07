/***************************************************************************
** File: Bat.cpp
** Author: Jake Statz
** Date: 05/23/2020
** Description: The bat event and functions
**************************************************************************/

#include "Bat.h"
#include "Game.h"
#include <cstdlib>
#include <iostream>

using namespace std;

Bat::Bat(int r, int c) {
	row = r;
	column = c;
}

void Bat::percept() {
	cout << "You hear wings flapping." << endl;
}

bool Bat::encounter(Game& g) {
	cout << "You are transported by a super bat!" << endl;
	int r = rand() % g.get_size();
	int c = rand() % g.get_size();
	g.move_player(r, c);
	if (g.get_cave()[r][c].has_event()) {
		return g.get_cave()[r][c].get_event()->encounter(g);
	}
	return false;
}

char Bat::letter() {
	return 'B';
}