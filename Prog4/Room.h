/***************************************************************************
** File: Room.h
** Author: Jake Statz
** Date: 05/24/2020
** Description: The room function definitions
**************************************************************************/

#ifndef ROOM_H
#define ROOM_H

#include "Event.h"

class Room {
private:
	bool event_chance;
	Event* event;
public:
	/********************************************************
	** Function: Constructor
	** Description: constructs the row and column
	** Input: Row and column
	** Pre-Conditions: none
	** Post-Conditions: row and column are initialized
	********************************************************/
	Room();

	/********************************************************
	** Function: Destructor
	** Description: Deletes the bat
	** Input: none
	** Pre-Conditions: none
	** Post-Conditions: none
	********************************************************/
	~Room();

	/********************************************************
	** Function: has_event()
	** Description: Returns if the room has an event
	** Input: none
	** Pre-Conditions: none
	** Post-Conditions: True or false
	********************************************************/
	bool has_event();

	/********************************************************
	** Function: get_event()
	** Description: Returns the specific event the room has
	** Input: none
	** Pre-Conditions: The room must have an event in the first place
	** Post-Conditions: Return the event
	********************************************************/
	Event* get_event();

	/********************************************************
	** Function: set_event()
	** Description: Sets the room's event
	** Input: none
	** Pre-Conditions: none
	** Post-Conditions: Event is set
	********************************************************/
	void set_event(Event*);

	/********************************************************
	** Function: remove_event()
	** Description: Removes the event so it isn't triggered again
	** Input: none
	** Pre-Conditions: The room has an event
	** Post-Conditions: Removes event
	********************************************************/
	Event* remove_event();
};
#endif