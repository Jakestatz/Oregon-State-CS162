/***************************************************************************
** File: Tiger.h
** Author: Jake Statz
** Date: 5/10/2020
** Description: Tiger class and supporting functions
**************************************************************************/

#ifndef TIGER_H
#define TIGER_H

#include <iostream>
#include "Animal.h"

using namespace std;

class Tiger : public Animal {
public:

	/********************************************************
	** Function: Constructor for Tiger
	** Description: For when a Tiger is born
	** Input: none
	** Pre-Conditions: none
	** Post-Conditions: member variables are initialized, age is 0
	********************************************************/
	Tiger();

	/********************************************************
	** Function: Constructor for Tiger
	** Description: For when a Tiger is bought from the store
	** Input: int age
	** Pre-Conditions: none
	** Post-Conditions: Initializes a Tiger, at inputed age
	********************************************************/
	Tiger(int);

	/********************************************************
	** Function: birth()
	** Description: Calls for a new Tiger
	** Input: none
	** Pre-Conditions: none
	** Post-Conditions: Calls for a new Tiger to be created
	********************************************************/
	Animal* birth() override;
};
#endif