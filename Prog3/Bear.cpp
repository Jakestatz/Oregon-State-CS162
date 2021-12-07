/***************************************************************************
** File: Bear.cpp
** Author: Jake Statz
** Date: 5/10/2020
** Description: The Bears's functions definitions
**************************************************************************/

#include <iostream>
#include "Animal.h"
#include "Bear.h"

using namespace std;

Bear::Bear() : Animal(6000, 3, 2, 2) {}

Bear::Bear(int age) : Animal(6000, 3, 2, 2, age) {}

Animal* Bear::birth() {
	return new Bear();
}