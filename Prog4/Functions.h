/***************************************************************************
** File: helper_functions.h
** Author: Jake Statz
** Date: 05/24/2020
** Description: The other function definitions
**************************************************************************/

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>

using namespace std;

/********************************************************
** Function: get_range()
** Description: Gets the users intput and tests it range
** Input: prompt, min, max
** Pre-Conditions: none
** Post-Conditions: Returns the input and if it is valid
********************************************************/
int get_range(string, int, int);

/********************************************************
** Function: get_input_move()
** Description: Reads the users move
** Input: prompt
** Pre-Conditions: none
** Post-Conditions: Returns the move
********************************************************/
char get_input_move(string, bool);
#endif