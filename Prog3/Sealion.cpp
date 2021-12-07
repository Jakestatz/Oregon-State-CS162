/***************************************************************************
** File: SeaLion.cpp
** Author: Jake Statz
** Date: 5/10/2020
** Description: The Sealions's functions definitions
**************************************************************************/

#include <iostream>
#include <cstdlib>
#include "Animal.h"
#include "Sealion.h"

using namespace std;

Sea_Lion::Sea_Lion() : Animal(800, 1, 1, 0) {}

Sea_Lion::Sea_Lion(int age) : Animal(800, 1, 1, 0, age) {}

Animal* Sea_Lion::birth() {
	return new Sea_Lion;
}

int Sea_Lion::revenue(bool bonus) {
	int rev = 2 * Animal::revenue(bonus);
	if (bonus) {
		rev += rand() % 251 + 150;
	}
	return rev;
}