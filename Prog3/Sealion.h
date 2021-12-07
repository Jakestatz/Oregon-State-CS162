/***************************************************************************
** File: SeaLion.h
** Author: Jake Statz
** Date: 5/10/2020
** Description: Sea Lion class and supporting functions
**************************************************************************/

#ifndef SEALION_H
#define SEALION_H

#include "Animal.h"
#include <iostream>

using namespace std;

class Sea_Lion : public Animal {
public:

	/********************************************************
	** Function: Constructor for Sea Lions
	** Description: For when a Sea Lion is born
	** Input: none
	** Pre-Conditions: none
	** Post-Conditions: member variables are initialized, age is 0
	********************************************************/
	Sea_Lion();

	/********************************************************
	** Function: Constructor for Sea Lion
	** Description: For when a Sea Lion is bought from the store
	** Input: int age
	** Pre-Conditions: none
	** Post-Conditions: Initializes a Sea Lion, at inputed age
	********************************************************/
	Sea_Lion(int);

	/********************************************************
	** Function: birth()
	** Description: Calls for a new Sea Lion
	** Input: none
	** Pre-Conditions: none
	** Post-Conditions: Calls for a new Sea Lion to be created
	********************************************************/
	Animal* birth() override;

	/********************************************************
	** Function: revenue()
	** Description: Calculates revenue and adds Sea Lion bonus if bool is true
	** Input: bool bonus
	** Pre-Conditions: none
	** Post-Conditions: returns revenue
	********************************************************/
	int revenue(bool bonus = 0) override;
};
#endif