/***************************************************************************
** File: Wumpus.h
** Author: Jake Statz
** Date: 05/24/2020
** Description: The wumpus event function definitions
**************************************************************************/

#ifndef WUMPUS_H
#define WUMPUS_H

#include "Event.h"

class Wumpus : public Event {
public:
	/********************************************************
	** Function: Constructor
	** Description: constructs the row and column
	** Input: Row and column
	** Pre-Conditions: none
	** Post-Conditions: row and column are initialized
	********************************************************/
	Wumpus(int r = 0, int c = 0);

	/********************************************************
	** Function: Destructor
	** Description: Deletes the bat
	** Input: none
	** Pre-Conditions: none
	** Post-Conditions: none
	********************************************************/
	~Wumpus() {}

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
	** Description: Displays that the player has encountered a wumpus
	** Input: game&
	** Pre-Conditions: none
	** Post-Conditions: Returns if the room kills the player
	********************************************************/
	bool encounter(Game&) override;

	/********************************************************
	** Function: letter()
	** Description: W represents the wumpus event rooms on the map
	** Input: none
	** Pre-Conditions: none
	** Post-Conditions: Returns the char W
	********************************************************/
	char letter() override;

};
#endif