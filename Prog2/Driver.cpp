/******************************************************
** Program: Driver.cpp
** Author: Jake Statz
** Date: 04/26/2020
** Description: The main function the runs the game
** Input: inputs form the user, ie. name and card choices
** Output: The game winner
******************************************************/
#include <iostream>					//Include Libraries
#include <cstdlib>
#include <ctime>
#include "Game.h"
#include "Functions.h"


int main() {
	srand(time(NULL));
	int num = 1;
	while (num != 0) {															//While loop if the player wants to play again
		Game game;
		game.final();
		num = range("Would you like to play again? (1-yes, 0-no): ", 0, 1);		//Tests the inputs range
	}
	return 0;
}