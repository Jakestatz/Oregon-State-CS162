/***************************************************************************
** File: Event.h
** Author: Jake Statz
** Date: 05/24/2020
** Description: The event function definitions
**************************************************************************/

#ifndef EVENT_H
#define EVENT_H

class Game;

class Event {
protected:
	int row = 0;				//Location of the event
	int column = 0;				

public:
	/********************************************************
	** Function: Constructor
	** Description: constructs the row and column
	** Input: Row and column
	** Pre-Conditions: none
	** Post-Conditions: row and column are initialized
	********************************************************/
	Event(int r = 0, int c = 0);

	/********************************************************
	** Function: Destructor
	** Description: Deletes the bat
	** Input: none
	** Pre-Conditions: none
	** Post-Conditions: none
	********************************************************/
	virtual ~Event() {}

	/********************************************************
	** Function: percept()
	** Description: Displays the event warning text
	** Input: none
	** Pre-Conditions: none
	** Post-Conditions: text is displayed
	********************************************************/
	virtual void percept() = 0;

	/********************************************************
	** Function: encounter()
	** Description: Displays an event specific message
	** Input: game&
	** Pre-Conditions: none
	** Post-Conditions: returns whether the player died
	********************************************************/
	virtual bool encounter(Game&) = 0;

	/********************************************************
	** Function: letter()
	** Description: Returns the event letter
	** Input: none
	** Pre-Conditions: none
	** Post-Conditions: The letter is then placed on the map
	********************************************************/
	virtual char letter() = 0;
};
#endif
