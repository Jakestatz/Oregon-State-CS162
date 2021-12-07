/******************************************************
** Program: wizard_catalog
** Author: Jake Statz
** Date: 4/12/20
** Description: .cpp file containing the main function
** Input: 2 text files, and choices for how the data should be sorted
** Output: a txt file or data displayed on screen
******************************************************/
#include <iostream>
#include <cstdlib>
#include <string>
#include <stdio.h>
#include <cmath>					//declare libraries
#include <fstream>
#include <array>
#include "Program1.hpp"

using namespace std;

int main(int argc, char* argv[]) {
	ifstream myfile;
	bool idnum=false;
	string id, password, spellbooks, wizards, str;
	int count = 0, ids, iswiz = 0, op = 1, dis, wiznum, booknum, snum, totalspells;
	while (wizards != "wizards.txt") {
		cout << "Enter the correct wizard list: ";
		cin >> wizards;
	}
	while (spellbooks != "spellbooks.txt") {
		cout << "Enter the correct spell book catalog: ";
		cin >> spellbooks;
	}

	myfile.open(wizards);
	getline(myfile, str);
	wiznum = stoi(str);
	wizard* profiles = create_wizards(wiznum);
	getwizard(profiles, wiznum, myfile);
	myfile.close();
	myfile.open(spellbooks);
	getline(myfile, str);
	booknum = stoi(str);
	spellbook* books = create_spellbooks(booknum);
	get_spellbook_data(books, booknum, myfile);
	myfile.close();
	while (iswiz == 0) {									//user enters their password
		if (count == 3) {
			cout << "To many attemps!" << endl;
			exit(1);
		}
		while (idnum != true) {
			cout << "Enter your id number: ";
			cin >> id;
			idnum = isNumber(id);
		}
		ids = stoi(id);
		cout << "Enter your password: ";
		cin >> password;
		idnum = false;
		iswiz = is_wizard(ids, password, profiles, wiznum);
		count += 1;
	}
	cout << "\n" << endl;
	profiled(iswiz, profiles);						//prints wizard profile
	while (op != 4) {								//diffent option call diffent functions
		op = option();
		if (op == 4) {
			return 0;
		}
		dis = display();
		if (op == 1) {
			page_number(books, booknum, dis);
		}
		if (op == 2) {
			effect(books, booknum, dis);
		}
		if (op == 3) {
			succ_rate(books, booknum, dis);
		}
		if (op == 4) {
			return 0;
		}
	}
	delete_info(&profiles, wiznum, &books, booknum);
}