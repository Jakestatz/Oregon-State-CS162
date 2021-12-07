/***************************************************************************
** File: Functions.h
** Author: Jake Statz
** Date: 6/07/2020
** Description: Functions that help with error handeling and user input
**************************************************************************/

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>

using namespace std;

/********************************************************
** Function: get_unsigned_int()
** Description: Checks if the input is a valid unassigned int
** Input: str
** Pre-Conditions: none
** Post-Conditions: Returns the unassigned int if valid
********************************************************/
unsigned int get_unsigned_int(string);

/********************************************************
** Function: get_int()
** Description: Checks if the input is a valid int
** Input: str
** Pre-Conditions: none
** Post-Conditions: Returns the int if valid
********************************************************/
int get_int(string);

/********************************************************
** Function: get_input()
** Description: Checks if the user inputted the right thing
** Input: str
** Pre-Conditions: none
** Post-Conditions: Returns the character input as a bool
********************************************************/
bool get_input(string, char, char);
#endif