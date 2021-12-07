/***************************************************************************
** File: Functions.cpp
** Author: Jake Statz
** Date: 05/23/2020
** Description: A function for checking input range and one more reading player movement
**************************************************************************/

#include "Functions.h"
#include <iostream>
#include <string>

using namespace std;

int get_range(string sent, int min, int max) {
	int num = min - 1;
	string input;
	while (true) {
		while (true) {
			cout << sent;
			getline(cin, input);
			if (input == "" || input.find_first_not_of("0123456789") != string::npos) {
				cout << "Invalid input." << endl;
			}
			else {
				break;
			}
		}
		num = stoi(input);
		if (num < min || num > max) {
			cout << "Invalid input." << endl;
		}
		else {
			return num;
		}
	}
}

char get_input_move(string sent, bool space) {
	char input;
	cout << sent;
	while (true) {
		system("stty raw;stty -echo");
		input = getchar();
		system("stty cooked;stty echo");
		if (input == ' ' || input == 'w' || input == 'a' || input == 's' || input == 'd' || (space && input == ' ')) {
			cout << endl;
			return input;
		}
	}
}