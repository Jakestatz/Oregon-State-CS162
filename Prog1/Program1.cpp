/******************************************************
** Program: wizard_catalog
** Author: Jake Statz
** Date: 4/12/20
** Description: .cpp file containing functions called in main
** Input: 2 text files, and choices for how the data should be sorted
** Output: a txt file or data displayed on screen
******************************************************/
#include <iostream>
#include <cstdlib>
#include <string>					//declare libraries
#include <cmath>
#include <fstream>
#include <functional>
#include "Program1.hpp"

using namespace std;

char** create_cstring(int row, int col) {
	char** a;
	a = new char* [row];
	for (int i = 0; i < row; i++) {
		a[i] = new char[col];
	}
	return a;
}

void delete_cstring(char** arg_list, int rows) {
	for (int i = 0; i < rows; i++) {
		delete[] arg_list[i];
	}
	delete[] arg_list;
	arg_list = NULL;
}

bool isNumber(string id){					//determines if the string input is all numbers
	for (int i = 0; i < id.length(); i++)
		if (isdigit(id[i]) == false)
			return false;					//the string will later be turned into an int
	return true;
}
int getwizard(wizard* profile, int num, ifstream &f) { //pulls the wizard data from the txt file
	string str;	
	for (int x = 0; x < num; x++) {					//repeats until file ends
		getline(f, str, ' ');
		profile[x].name = str;
		getline(f, str, ' ');
		profile[x].id = atoi(str.c_str());
		getline(f, str, ' ');
		profile[x].password = str;
		getline(f, str, ' ');
		profile[x].position_title = str;
		getline(f, str);
		profile[x].beard_length = atof(str.c_str());
	}	
}

int is_wizard(int id, string password, wizard* profile, int lines) { //sees if the inputed password is contained in the txt file's passwords
	for (int x = 0; x < lines; x++)
		if (id == profile[x].id) {
			if (password == profile[x].password) {
				return x;
				break;									//stops if it is found
			}
		}
	return 0;						//while return 0 if it is not found
}

spellbook* create_spellbooks(int num) { //creates spellbook array
	spellbook* books;
	books = new spellbook[num];
	return books;
}

wizard* create_wizards(int num) {  //creates wizard array
	wizard* profiles;
	profiles = new wizard[num];
	return profiles;
}

void get_spellbook_data(spellbook* books, int num, ifstream& f) {  //pulls data from the txt file into the spellbook struct
	string str;
	for (int x = 0; x < num; x++) {						//repeats until the end on the file
		getline(f, str, ' ');
		books[x].title = str;
		getline(f, str, ' ');
		books[x].author = str;
		getline(f, str, ' ');
		books[x].num_pages = atoi(str.c_str());
		getline(f, str, ' ');
		books[x].edition = atoi(str.c_str());
		getline(f, str);
		books[x].num_spells = atoi(str.c_str());
		books[x].s = create_spells(books[x].num_spells);
		get_spell_data(books[x].s, books[x].num_spells, f);
	}
}

spell* create_spells(int num) {						//creates spells array
	spell* spells;
	spells = new spell[num];
	return spells;
}
void get_spell_data(spell* s, int num, ifstream& f) { //gets the txt spell data and puts it in the nested struct s
	string str;
	for (int x = 0; x < num; x++) {
		getline(f, str, ' ');
		s[x].name = str;
		getline(f, str, ' ');
		s[x].success_rate = atof(str.c_str());
		getline(f, str);
		s[x].effect = str.c_str();
	}
}
int option() {					//shows users their sorting options and takes their input
	int choice;
	cout << "Which option would you like to choose?" << endl;
	cout << "Sort spellbooks by number of pages(Press 1): " << endl;
	cout << "Group spells by their effect(Press 2): " << endl;
	cout << "Sort spellbooks by average success rate(Press 3): " << endl;
	cout << "Quit(Press 4): " << endl;
	cin >> choice;
	cout << "\n" << endl;
	return choice;
 }
int display() {					//shows users their display options and takes their input
	int dischoise;
	cout << "How would you like the information displayed ?" << endl;
	cout << "Print to screen(Press 1)" << endl;
	cout << "Print to file(Press 2)" << endl;
	cin >> dischoise;
	cout << "\n" << endl;
	return dischoise;
}
void profiled(int num, wizard* profile) {							//prints out the wizards profile
	cout << "Welcome " << profile[num].name << endl;
	cout << "ID: " << profile[num].id << endl;
	cout << "Status: " << profile[num].position_title << endl;
	cout << "Beard Length: " << profile[num].beard_length << endl;
	cout << "\n" << endl;
}
void page_number(spellbook* books, int num, int dis) {			//sorts books by number of pages
	int temp;
	string semp;
	fstream out;
	out.open("Output.txt", ios::app | ios::out);
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num - 1; j++) {
			if (books[j].num_pages > books[j + 1].num_pages) {

				temp = books[j].num_pages;
				books[j].num_pages = books[j + 1].num_pages;
				books[j + 1].num_pages = temp;

				semp = books[j].title;
				books[j].title = books[j + 1].title;
				books[j + 1].title = semp;
			}
		}
		if (dis == 1) {													//prints out based on display option
			cout << books[i].title << " " << books[i].num_pages << "\n";
		}
		if (dis == 2) {
			out << books[i].title << " " << books[i].num_pages << "\n";
		}
	}
	out.close();
}
void effect(spellbook* books, int num, int dis) {			//sorts spells by their effect
	string semp, temp;
	fstream out;
	int totspells = 0;
	for (int x = 0; x < num; x++) {
		totspells += books[x].num_spells;
	}
	spell* spells = create_spells(totspells);
	int x = 0;
		for (int v = 0; v < num; v++) {
			for (int c = 0; c < books[v].num_spells; c++ ) {
				spells[x].name = books[v].s[c].name;
				spells[x].effect = books[v].s[c].effect;
				x += 1;
			}
		}
	out.open("Output.txt", ios::app | ios::out);
	for (int i = 0; i < totspells; i++) {
		for (int j = 0; j < totspells-1; j++) {
			if (spells[j].effect > spells[j + 1].effect) {

				temp = spells[j].effect;
				spells[j].effect = spells[j + 1].effect;
				spells[j + 1].effect = temp;

				semp = spells[j].name;
				spells[j].name = spells[j + 1].name;
				spells[j + 1].name = semp;
			}
		}
	}
	for (int i = 0; i < totspells; i++) {
		if (dis == 1) {
			cout << spells[i].effect << ' ' << spells[i].name << endl;	//prints out based on display option
		}
		if (dis == 2) {
			out << spells[i].effect << ' ' << spells[i].name << endl;
		}
	}
	out.close();
		delete[] spells;
}

void succ_rate(spellbook* books, int num, int dis) {                      //sorts books by their spells's average success rate
	float avg = 0;
	for (int x = 0; x < num; x++) {
		for (int y = 0; y < books[x].num_spells; y++) {
			avg += books[x].s[y].success_rate;
		}
		books[x].avg_success_rate = avg / books[x].num_spells;
		avg = 0;
	}
	float temp;
	string semp;
	fstream out;
	out.open("Output.txt", ios::app | ios::out);
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num - 1; j++) {
			if (books[j].avg_success_rate > books[j + 1].avg_success_rate) {

				temp = books[j].avg_success_rate;
				books[j].avg_success_rate = books[j + 1].avg_success_rate;
				books[j + 1].avg_success_rate = temp;

				semp = books[j].title;
				books[j].title = books[j + 1].title;
				books[j + 1].title = semp;
			}
		}
		if (dis == 1) {
			cout << books[i].title << ' ' << books[i].avg_success_rate << endl;				//prints out based on display option
		}
		if (dis == 2) {
			out << books[i].title << ' ' << books[i].avg_success_rate << endl;
		}
	}
 
	out.close();
}
void delete_info(wizard** profile, int num, spellbook**books, int num2) { //deletes wizard and books array
	for (int x = 0; x < num; x++) {
		delete[] profile[x];
	}
	for (int y = 0; y < num2; y++) {
		delete[] books[y];
	}
	delete[] profile;
	delete[] books;
}
