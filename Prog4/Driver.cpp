/******************************************************
** Program: Driver.cpp
** Author: Jake Statz
** Date: 05/23/2020
** Description: The driver functions that build the game
** Input: User input
** Output: win/loss
******************************************************/

#include <cstdlib>
#include <ctime>
#include <cstring>
#include "Game.h"
#include "Functions.h"

using namespace std;

void arguments(int, char**, int&, bool&);

/********************************************************
** Function: main()
** Description: Starts the game
** Input: Command line arguments
** Pre-Conditions: none
** Post-Conditions: Game it created
********************************************************/
int main(int argc, char** argv) {
	srand(time(NULL));
	int s;
	bool board;
	arguments(argc, argv, s, board);
	Game game(s, board);
	for (int i = 0; i < 50; ++i) cout << "\n";
	game.play();

	return 0;
}

/********************************************************
** Function: arguments()
** Description: Makes sure that the comand line arguments are exceptable
** Input: CLA, size and num
** Pre-Conditions: none
** Post-Conditions: Quits or continues the game
********************************************************/
void arguments(int argc, char** argv, int& size, bool& num) {
	if (argc != 3) {
		cout << "Please restart, wrong number of arguments." << endl;
		size = get_range("Enter a board size between 3 and 20: ", 3, 20);
		num = get_range("Run in debug mode? (1-yes, 0-no): ", 0, 1);
	}
	else {
		if (atoi(argv[1]) < 4) {
			cout << "Please restart, wrong number of arguments." << endl;
			size = get_range("Enter a board size between 3 and 20: ", 3, 20);
		}
		else {
			size = atoi(argv[1]);
		}

		if (strcmp(argv[2], "true") == 0) {
			num = true;
		}
		else if (strcmp(argv[2], "false") == 0) {
			num = false;
		}
		else {
			cout << "Invalid argument for debug mode" << endl;
			num = get_range("Run in debug mode? (1-yes, 0-no): ", 0, 1);
		}
	}
}