/***************************************************************************
** File: Pit.h
** Author: Jake Statz
** Date: 05/24/2020
** Description: The pit event and it's function definitions
**************************************************************************/

#ifndef PIT_H
#define PIT_H

#include "Event.h"

class Pit : public Event {
public:
	/********************************************************
	** Function: Constructor
	** Description: constructs the row and column
	** Input: Row and column
	** Pre-Conditions: none
	** Post-Conditions: row and column are initialized
	********************************************************/
	Pit(int r = 0, int c = 0);

	/********************************************************
	** Function: Destructor
	** Description: Deletes the bat
	** Input: none
	** Pre-Conditions: none
	** Post-Conditions: none
	********************************************************/
	~Pit() {}

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
	** Description: Displays that the playerhas fallen into the pit
	** Input: game&
	** Pre-Conditions: none
	** Post-Conditions: Returns if the room kills the player
	********************************************************/
	bool encounter(Game&) override;

	/********************************************************
	** Function: letter()
	** Description: P represents the pit event rooms on the map
	** Input: none
	** Pre-Conditions: none
	** Post-Conditions: Returns the char P
	********************************************************/
	char letter() override;
};
#endif