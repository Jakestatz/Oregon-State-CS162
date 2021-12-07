/***************************************************************************
** File: Game.h
** Author: Jake Statz
** Date: 05/24/2020
** Description: The game function definitions
**************************************************************************/

#ifndef GAME_H
#define GAME_H

#include "Room.h"
#include "AI_Functions.h"
#include <string>
#include <vector>

using namespace std;

class Game {
private:
	int size;				//Map size
	int arrows;				//Arrows
	bool debug;				//Debug mode
	bool gold;				//If the player has gold
	bool shooting;			//If the player is shooting an arrow
	int gold_row;
	int gold_col;
	int player_row;
	int player_col;
	int rope_row;
	int rope_col;
	int original_wumpus_row;
	int original_wumpus_col;
	int wumpus_row;
	int wumpus_col;

	vector< vector<Room> > cave; //The cave
	vector< vector<AI> > ai_data; //For AI

	/********************************************************
	** Function: init
	** Description: initializes member variables
	** Input: size, debug mode
	** Pre-Conditions: none
	** Post-Conditions: member variables are initialized
	********************************************************/
	void init(int, bool);

	/********************************************************
	** Function: place_wumpus
	** Description: Places the wumpuses
	** Input: none
	** Pre-Conditions: none
	** Post-Conditions: Places the event
	********************************************************/
	void place_wumpus();

	/********************************************************
	** Function: place_pits
	** Description: Places Pits
	** Input: none
	** Pre-Conditions: none
	** Post-Conditions: Places the event
	********************************************************/
	void place_pits();

	/********************************************************
	** Function: place_bats
	** Description: Places bats
	** Input: none
	** Pre-Conditions: none
	** Post-Conditions: Places the event
	********************************************************/
	void place_bats();

	/********************************************************
	** Function: place_gold
	** Description: Places gold
	** Input: none
	** Pre-Conditions: none
	** Post-Conditions: Places the event
	********************************************************/
	void place_gold();

	/********************************************************
	** Function: room_events
	** Description: Sets the rooms that will have events
	** Input: none
	** Pre-Conditions: none
	** Post-Conditions: Sets the rooms
	********************************************************/
	void room_events();

	/********************************************************
	** Function: clean
	** Description: Clears the board
	** Input: none
	** Pre-Conditions: None
	** Post-Conditions: Clears the map
	********************************************************/
	void clean();

	/********************************************************
	** Function: display
	** Description: Displays the map
	** Input: none
	** Pre-Conditions: none
	** Post-Conditions: Displays it for the user to see
	********************************************************/
	void display();

	/********************************************************
	** Function: shoot_arrow
	** Description: gets direction from user and shoots an arrow
	** Input: user input
	** Pre-Conditions: none
	** Post-Conditions: an arrow is shot, wumpus moves, stays, or is killed
	********************************************************/
	void shoot_arrow(bool ai);

	/********************************************************
	** Function: AI_get_shoot_direction
	** Description: chooses a direction to shoot
	** Input: none
	** Pre-Conditions: none
	** Post-Conditions: returns direction to shoot
	********************************************************/
	char AI_get_shoot_direction();

	/********************************************************
	** Function: get_input
	** Description: gets input from the user for direction to move/shoot an arrow
	** Input: user input
	** Pre-Conditions: none
	** Post-Conditions: returns whether or not the user has chosen to shoot an arrow
	********************************************************/
	bool get_input();

	/********************************************************
	** Function: AI_get_input
	** Description: updates adjacent rooms in the ai_data vector
	** Input: adjacent rooms, bad directions and moved
	** Pre-Conditions: none
	** Post-Conditions: values are updated, returns whether or not ai wants to shoot an arrow
	********************************************************/
	bool update_AI_data(string, string&, bool&);

	/********************************************************
	** Function: AI_get_input
	** Description: gets input from the ai for direction to move/shoot an arrow
	** Input: adjacent rooms
	** Pre-Conditions: none
	** Post-Conditions: returns whether or not the ai has chosen to shoot an arrow
	********************************************************/
	bool AI_get_input(string);

	/********************************************************
	** Function: AI_exit
	** Description: returns to rope, avoiding obstacles
	** Input: bad directions
	** Pre-Conditions: none
	** Post-Conditions: moves toward rope hopefully, return false if unsuccessful
	********************************************************/
	bool AI_exit(string);

	/********************************************************
	** Function: search_adjacent
	** Description: calls percept functions on adjacent rooms with events
	** Input: none
	** Pre-Conditions: none
	** Post-Conditions: messages are displayed, returns list of abbreviations of events
	********************************************************/
	string search_adjacent();

	/********************************************************
	** Function: turn
	** Description: prompts for input and displays things for a turn
	** Input: none
	** Pre-Conditions: none
	** Post-Conditions: return whether or not the game should end
	********************************************************/
	bool turn(bool);

	/********************************************************
	** Function: move_wumpus
	** Description: 75% that the wumpus is moved to one of the adjacent rooms
	** Input: none
	** Pre-Conditions: none
	** Post-Conditions: 75% that the wumpus is moved to one of the adjacent rooms
	********************************************************/
	void move_wumpus();

public:
	/********************************************************
	** Function: Game default constructor
	** Description: initializes member variables to default values
	** Input: none
	** Pre-Conditions: none
	** Post-Conditions: member variables are initialized
	********************************************************/
	Game();

	/********************************************************
	** Function: Game alternate constructor
	** Description: initializes member variables
	** Input: size, debug mode
	** Pre-Conditions: inputs are valid
	** Post-Conditions: member variables are initialized
	********************************************************/
	Game(int, bool);

	/********************************************************
	** Function: get_size
	** Description: returns the size
	** Input: none
	** Pre-Conditions: none
	** Post-Conditions: returns the size
	********************************************************/
	int get_size();

	/********************************************************
	** Function: move_player
	** Description: moves the player
	** Input: new row, new column
	** Pre-Conditions: none
	** Post-Conditions: player is moved to the specified position
	********************************************************/
	void move_player(int, int);


	/********************************************************
	** Function: get_cave
	** Description: returns the cave
	** Input: none
	** Pre-Conditions: none
	** Post-Conditions: returns the cave
	********************************************************/
	vector< vector<Room> >& get_cave();

	/********************************************************
	** Function: get_gold
	** Description: updates the gold member variable
	** Input: none
	** Pre-Conditions: none
	** Post-Conditions: gold is true
	********************************************************/
	void get_gold();

	/********************************************************
	** Function: play
	** Description: plays the game
	** Input: none
	** Pre-Conditions: none
	** Post-Conditions: the user has chosen to quit
	********************************************************/
	void play();
};
#endif