/***************************************************************************
** File: Gold.h
** Author: Jake Statz
** Date: 05/24/2020
** Description: The gold event and it's function defintions
**************************************************************************/

#ifndef GOLD_H
#define GOLD_H

#include "Event.h"

class Gold : public Event {
public:
	/********************************************************
	** Function: Constructor
	** Description: constructs the row and column
	** Input: Row and column
	** Pre-Conditions: none
	** Post-Conditions: row and column are initialized
	********************************************************/
	Gold(int r = 0, int c = 0);

	/********************************************************
	** Function: Destructor
	** Description: Deletes the bat
	** Input: none
	** Pre-Conditions: none
	** Post-Conditions: none
	********************************************************/
	~Gold() {}

	/********************************************************
	** Function: percept()
	** Description: Displays the event warning text
	** Input: none
	** Pre-Conditions: none
	** Post-Conditions: text is displayed
	********************************************************/
	void percept() override;

	/********************************************************
	** Function: encounter()
	** Description: Determines if the player has found gold
	** Input: game&
	** Pre-Conditions: none
	** Post-Conditions: returns false
	********************************************************/
	bool encounter(Game&) override;

	/********************************************************
	** Function: letter()
	** Description: G represents the gold event rooms on the map
	** Input: none
	** Pre-Conditions: none
	** Post-Conditions: Returns the char G
	********************************************************/
	char letter() override;
};
#endif