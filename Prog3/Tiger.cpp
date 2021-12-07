/***************************************************************************
** File: Tiger.cpp
** Author: Jake Statz
** Date: 5/10/2020
** Description: The Tigers's functions definitions
**************************************************************************/

#include "Animal.h"										//Include libraries
#include "Tiger.h"
#include <iostream>

using namespace std;

Tiger::Tiger() : Animal(15000, 5, 3, 1) {}

Tiger::Tiger(int age) : Animal(15000, 5, 3, 1, age) {}

Animal* Tiger::birth() {
	return new Tiger;
}