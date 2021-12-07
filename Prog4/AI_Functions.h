/***************************************************************************
** File: AI_Functions.h
** Author: Jake Statz
** Date: 02/29/2020
** Description: The function defintions for the AI component
**************************************************************************/

#ifndef AI_FUNCTIONS
#define AI_FUNCTIONS

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class AI {
private:
	vector<int> p_rows;		//Event postition
	vector<int> p_cols;
	vector<string> next;
	bool one;				//Is the rooom new?
	bool two;				//Is it a new event?
	char event;				//Which event
public:
	/********************************************************
	** Function: Constructor
	** Description: constructs the row and column
	** Input: Row and column
	** Pre-Conditions: none
	** Post-Conditions: row and column are initialized
	********************************************************/
	AI();

	/********************************************************
	** Function: saw
	** Description: Checks if the room has been seen yet
	** Input: none
	** Pre-Conditions: none
	** Post-Conditions: Return true or false
	********************************************************/
	bool saw();

	/********************************************************
	** Function: is_verified
	** Description: Double checks room event
	** Input: none
	** Pre-Conditions: none
	** Post-Conditions: Returns true or false
	********************************************************/
	bool is_verified();

	/********************************************************
	** Function: get_event
	** Description: Returns the type of event
	** Input: none
	** Pre-Conditions: none
	** Post-Conditions: Returns the event type
	********************************************************/
	char get_event();

	/********************************************************
	** Function: update
	** Description: updates the position
	** Input: row, column, string
	** Pre-Conditions: none
	** Post-Conditions: The update
	********************************************************/
	void update(int, int, string);

	/********************************************************
	** Function: reset
	** Description: Resets the AI
	** Input: none
	** Pre-Conditions: none
	** Post-Conditions: Resets
	********************************************************/
	void reset();
};
#endif