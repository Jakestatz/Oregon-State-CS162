/***************************************************************************
** File: Functions.cpp
** Author: Jake Statz
** Date: 6/07/2020
** Description: Functions that help with error handeling and user input
**************************************************************************/

#include <iostream>
#include <string>
#include "Functions.h"

using namespace std;

unsigned int get_unsigned_int(string str) {
	string input;
	while (true) {
		cout << str;
		try {
			getline(cin, input);
			if (input.find_first_not_of("0123456789") != string::npos) throw 0;
			return stoul(input);
		}
		catch (...) {
			cout << "Invalid input." << endl;
		}
	}
}

int get_int(string str) {
	string input;
	while (true) {
		cout << str;
		try {
			getline(cin, input);
			if (input.find_first_not_of("0123456789") != string::npos && input.length() != 0 && input.at(0) != '-') throw 0;
			return stoi(input);
		}
		catch (...) {
			cout << "Invalid input." << endl;
		}
	}
}

bool get_input(string str, char t, char f) {
	string input;
	while (true) {
		cout << str;
		getline(cin, input);
		if (input.length() == 1 && input.at(0) == t) {
			return true;
		}
		else if (input.length() == 1 && input.at(0) == f) {
			return false;
		}
		cout << "Invalid input." << endl;
	}
}