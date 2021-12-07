/******************************************************
** Program: Functions.cpp
** Author: Jake Statz
** Date: 04/26/2020
** Description: The Function range defintion
** Input: user input
** Output: A valid input
******************************************************/
#include <iostream>						//Include Libraries
#include <cstdlib>
#include <string>
#include "Functions.h"

using namespace std;

int range(string sent, int x, int y) {
	int num = x - 1;
	string str;
	while (true) {
		while (true) {
			cout << sent;																//Outputs the sentence
			getline(cin, str);															//Gets user input
			if (str == "" || str.find_first_not_of("0123456789") != string::npos) {		//Built in string function
				cout << "Invalid input." << endl;
			}
			else {
				break;
			}
		}
		num = stoi(str);
		if (num < x || num > y) {
			cout << "Invalid input." << endl;
		}
		else {
			return num;
		}
	}
}