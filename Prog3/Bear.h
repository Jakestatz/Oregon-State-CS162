/***************************************************************************
** File: Bear.h
** Author: Jake Statz
** Date: 5/10/2020
** Description: Bear class and supporting functions
**************************************************************************/

#ifndef BEAR_H
#define BEAR_H

#include <iostream>
#include "Animal.h"															//Include libraires

using namespace std;

class Bear : public Animal {
public:
	/********************************************************
	** Function: Constructor for bears
	** Description: For when a bear is born
	** Input: none
	** Pre-Conditions: none
	** Post-Conditions: Initializes a bear, age 0.
	********************************************************/
	Bear();

	/********************************************************
	** Function: Constructor for bears
	** Description: For when a bear is bought from the store
	** Input: int age
	** Pre-Conditions: none
	** Post-Conditions: Initializes a bear, at inputed age
	********************************************************/
	Bear(int);

	/********************************************************
	** Function: birth()
	** Description: Calls for a new bear
	** Input: none
	** Pre-Conditions: none
	** Post-Conditions: Calls for a new bear to be created
	********************************************************/
	Animal* birth() override;
};
#endif