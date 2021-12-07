/***************************************************************************
** File: Bat.h
** Author: Jake Statz
** Date: 05/24/2020
** Description: The bat event definitions
**************************************************************************/

#ifndef BAT_H
#define BAT_H

#include "Event.h"

class Bat : public Event {
public:
	/********************************************************
	** Function: Constructor
	** Description: constructs the row and column
	** Input: Row and column
	** Pre-Conditions: none
	** Post-Conditions: row and column are initialized
	********************************************************/
	Bat(int r = 0, int c = 0);

	/********************************************************
	** Function: Destructor
	** Description: Deletes the bat 
	** Input: none
	** Pre-Conditions: none
	** Post-Conditions: none
	********************************************************/
	~Bat() {}

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
	** Description: Displays that the player is being moved and then moves the player
	** Input: game&
	** Pre-Conditions: none
	** Post-Conditions: Returns if the new room kills the player 
	********************************************************/
	bool encounter(Game&) override;

	/********************************************************
	** Function: letter()
	** Description: B represents the bat event rooms on the map
	** Input: none
	** Pre-Conditions: none
	** Post-Conditions: Returns the char B
	********************************************************/
	char letter() override;
};
#endif