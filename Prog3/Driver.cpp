/******************************************************
** Program: Driver.cpp
** Author: Jake Statz
** Date: 5/10/2020
** Description: The main function that runs the game
** Input: Inputs form the user, ie. food and animal sale choices
** Output: When the player runs out of money and how many months they lasted
******************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Animal.h"
#include "Bear.h"
#include "Sealion.h"
#include "Tiger.h"
#include "Zoo.h"
#include "Functions.h"

using namespace std;

int main() {
	srand(time(NULL));
	int num = 1;
	while (num != 0) {
		Zoo z;
		z.play();
		num = range("Want to play again? 1-yes, 0-no: ", 0, 1);
	}
	return 0;
}