/***************************************************************************
** File: Functions.h
** Author: Jake Statz
** Date: 5/10/2020
** Description: A supporting function used in most cpp files
**************************************************************************/

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>					//Include Libraries
#include <cstdlib>
#include <string>

using namespace std;

/********************************************************
** Function: range()
** Description: Allows tbe user to have thier inputs checked and are excepted if they fall within a range of acceptable values
** Input: string, min int , max int 
** Pre-Conditions: none
** Post-Conditions: returns the choice that the user chooses, an int between min and max
********************************************************/
int range(string, int, int);
#endif
