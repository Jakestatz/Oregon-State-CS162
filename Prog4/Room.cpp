/***************************************************************************
** File: Room.cpp
** Author: Jake Statz
** Date: 05/23/2030
** Description: The room functions 
**************************************************************************/

#include <iostream>
#include "Room.h"

Room::Room() {
	event_chance = false;
	event = nullptr;
}

Room::~Room() {
	if (event_chance) {
		delete event;
	}
}

Event* Room::get_event() {
	return event;
}

void Room::set_event(Event* e) {
	event_chance = true;
	event = e;
}

bool Room::has_event() {
	return event_chance;
}

Event* Room::remove_event() {
	event_chance = false;
	Event* temp = event;
	event = nullptr;
	return temp;
}