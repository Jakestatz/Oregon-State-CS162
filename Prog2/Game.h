/******************************************************
** Program: Game.h
** Author: Jake Statz
** Date: 04/26/2020
** Description: Declares the Game class and it's supporting functions
** Input:
** Output:
******************************************************/
#ifndef GAME_H
#define GAME_H

#include <iostream>				//Include Libraries
#include <cstdlib>
#include <string>
#include "Card.h"
#include "Player.h"
#include "Deck.h"

using namespace std;

class Game {
private:
	Deck cards;				
	Player players[2];		//The array of the two players
	Card card;				//The current top card
	void game_winner();		//Declares the winner

public:
	Game();					//Constructor
	void final();			//Calls the game winning function
};
#endif