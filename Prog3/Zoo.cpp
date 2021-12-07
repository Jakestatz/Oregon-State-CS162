/***************************************************************************
** File: Zoo.cpp
** Author: Jake Statz
** Date: 5/10/2020
** Description: The Zoo's functions definitions
**************************************************************************/

#include <iostream>
#include "Zoo.h"
#include "Functions.h"

using namespace std;

Zoo::Zoo() {
	bank = 100000;					//Game starts with $100,000
	total_animals = 0;
	sick_prob = 2;
	food_cost = 80;
	animals = new Animal * [0];
	for (int x = 0; x < 3; ++x) {
		num_animals[x] = 0;				//Player starts with zero animals
		num_adults[x] = 0;
	}
	num_months = 0;
}

Zoo::Zoo(const Zoo& z) {						//Copy constructor
	bank = z.bank;
	total_animals = z.total_animals;
	sick_prob = z.sick_prob;
	food_cost = z.food_cost;
	for (int x = 0; x < 3; ++x) {
		num_animals[x] = z.num_animals[x];
		num_adults[x] = z.num_adults[x];
	}
	animals = new Animal* [total_animals];
	for (int y = 0; y < total_animals; ++y) {
		*(animals[y]) = *(z.animals[y]);
	}
	num_months = z.num_months;
}

Zoo& Zoo::operator=(const Zoo& z) {					//Opperator overload
	if (&z != this) {
		for (int x = 0; x < total_animals; ++x) {
			delete animals[x];
		}
		delete[] animals;
		bank = z.bank;
		total_animals = z.total_animals;
		sick_prob = z.sick_prob;
		food_cost = z.food_cost;
		for (int y = 0; y < 3; ++y) {
			num_animals[y] = z.num_animals[y];
			num_adults[y] = z.num_adults[y];
		}
		animals = new Animal * [total_animals];
		for (int i = 0; i < total_animals; ++i) {
			*(animals[i]) = *(z.animals[i]);
		}
		num_months = z.num_months;
	}
	return *this;
}

void Zoo::increase() {
	++total_animals;
	Animal** temp = new Animal * [total_animals];
	for (int x = 0; x < total_animals - 1; ++x) {
		temp[x] = animals[x];
	}
	delete[] animals;
	animals = temp;
}

void Zoo::decrease(int num) {
	--total_animals;
	--num_animals[animals[num]->get_id()];
	if (animals[num]->get_age() >= 48) {
		--num_adults[animals[num]->get_id()];
	}
	delete animals[num];
	Animal** temp = new Animal * [total_animals];
	for (int x = 0; x < num; ++x) {
		temp[x] = animals[x];
	}
	for (int y = num; y < total_animals; ++y) {
		temp[y] = animals[y + 1];
	}
	delete[] animals;
	animals = temp;
}

void Zoo::add_animal(Animal* a) {
	increase();
	animals[total_animals - 1] = a;
}

bool Zoo::turn() {
	new_age();
	bool bonus = false;
	if (special_event(bonus)) {
		return true;
	}
	income(bonus);
	if (get_input()) {
		return true;
	}
	if (food()) {
		return true;
	}
	return bank <= 0;
}

bool Zoo::special_event(bool& bonus) {
	int choice = rand() % 24;
	if (choice < sick_prob * 3) {
		return sick();
	}
	else if (choice < 8 + 2 * sick_prob) {
		return birth();          
	}
	else if (choice < 16 + sick_prob) {
		cout << "Zoo attendence has increaced! Your Sea Lions generate extra revenue!" << endl;
		bonus = true;
	}
	return false; 
}

void Zoo::new_age() {
	++num_months;
	for (int x = 0; x < total_animals; ++x) {
		animals[x]->increase_age();
		if (animals[x]->get_age() == 48) {
			++num_adults[animals[x]->get_id()];
		}
	}
}

bool Zoo::birth() {
	bool possible[] = { false, false, false };
	for (int x = 0; x < 3; ++x) {
		if (num_animals[x] >= 2) {
			possible[x] = true;
		}
	}
	if (!possible[0] && !possible[1] && !possible[2]) {
		return false;
	}
	int num;
	do {
		num = rand() % total_animals;
	} while (!possible[animals[num]->get_id()]);
	string animal_names[] = { "Sea Lion", "Tiger", "Bear" };
	for (int i = 0; i < animals[num]->get_babies(); ++i) {
		add_animal(animals[num]->birth());
		++num_animals[animals[num]->get_id()];
	}
	cout << "A " << animal_names[animals[num]->get_id()] << " gave birth to " << animals[num]->get_babies() << (animals[num]->get_babies() > 1 ? " babies!" : " baby!") << endl;
	return false;
}

bool Zoo::sick() {
	if (total_animals == 0) {
		return false;
	}
	int num = rand() % total_animals;
	string animal_names[] = { "Sea Lion", "Tiger", "Bear" };
	cout << "A " << animal_names[animals[num]->get_id()] << " got sick!" << endl;
	int cost = animals[num]->sick_cost();
	if (cost >= bank) {
		cout << "You couldn't afford the medication, so it died." << endl;
		decrease(num);
		return false;
	}
	else {
		bank -= cost;
		if (bank == 0) {
			return true;
		}
	}
	return false;
}

void Zoo::income(bool bonus) {
	for (int x = 0; x < total_animals; ++x) {
		bank += animals[x]->revenue(bonus);
	}
}

bool Zoo::food() {
	for (int i = 0; i < total_animals; ++i) {
		bank -= animals[i]->get_foodx() * food_cost * sick_prob / 2; 
	}
	int mult = rand() % 41 + 80;
	food_cost = food_cost * mult / 100;
	return bank <= 0;
}

bool Zoo::buy_animal() {
	cout << "What type of animal would you like to buy? \n  1. Sea Lions ($800 each)\n  2. Tigers ($15000 each)\n  3. Bears ($6000 each)" << endl;
	int num1 = range("Enter an option (1-3): ", 1, 3) - 1;
	int num2 = range("How many? (1-2): ", 1, 2);
	for (int i = 0; i < num2; ++i) {
		
		if (num1 == 0) {
			bank -= 800;
			add_animal(new Sea_Lion(48));
		}
		else if (num1 == 1) {
			bank -= 15000;
			add_animal(new Tiger(48));
		}
		else if (num1 == 2) {
			bank -= 6000;
			add_animal(new Bear(48));
		}
		++num_animals[num1];
		++num_adults[num1];
	}
	return bank <= 0;
}

bool Zoo::get_input() {
	display();
	int choice = range("Enter an option (1-4): ", 1, 4);
	if (choice == 2) {
		if (buy_animal())
			return true;
	}
	else if (choice == 3) {
		cout << "Choose a food type:\n  1. " << "Premium Food" << " (Cost $" << food_cost * 2 << ")";
		cout << "\n  2. " << "Regular Food" << " (Cost: $" << food_cost << ")";
		cout << "\n  3. " << "Cheap Food" << " (Cost: $" << food_cost / 2 << ")" << endl;
		int r = range("Enter an option (1-3): ", 1, 3);
		sick_prob = (r == 3 ? 4 : (r));
	}
	else if (choice == 4) {
		return true;
	}
	return false;
}

void Zoo::play() {
	if (get_input()) {
		return;
	}
	while (!turn());
	if (bank <= 0) {
		lose();
	}
}

void Zoo::display() {
	string month[] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
	cout << month[num_months % 12] << ", " << num_months / 12 + 2020 << endl;
	cout << "You have " << "$" << bank << endl;
	string foodtypes[] = { "Premium", "Regular", "Cheap" };
	cout << "Current food type: " << foodtypes[sick_prob / 2] << " ($" << food_cost * sick_prob / 2 << ")" << endl;
	cout << "You have " << num_animals[0] << " Sea Lions and " << num_animals[0] - num_adults[0] << (num_animals[0] - num_adults[0] == 1 ? " is a baby." : " are babies.") << endl;
	cout << "You have " << num_animals[1] << " Tigers and " << num_animals[1] - num_adults[1] << (num_animals[1] - num_adults[1] == 1 ? " is a baby." : " are babies.") << endl;
	cout << "You have " << num_animals[2] << " Bears and " << num_animals[2] - num_adults[2] << (num_animals[2] - num_adults[2] == 1 ? " is a baby." : " are babies.") << endl;
	cout << "  1. Continue\n  2. Buy animals\n  3. Change food type\n  4. Quit game" << endl;
}

void Zoo::lose() {
	cout << "GAME OVER. You ran out of money. Your zoo lasted " << num_months << " months." << endl;
}

Zoo::~Zoo() {										//deconstructor
	for (int x = 0; x < total_animals; ++x) {
		delete animals[x];
	}
	delete[] animals;
}
