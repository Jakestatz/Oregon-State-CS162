/******************************************************
** Program: Player.h
** Author: Jake Statz
** Date: 04/26/2020
** Description: Declares the Player class and it's supporting functions
** Input:
** Output:
******************************************************/
#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>					//Include Libraries
#include <cstdlib>
#include <string>
#include "Card.h"
#include "Hand.h"
#include "Deck.h"

using namespace std;

class Player {
private:
	Hand hand; 
	string name;							//Players name
	bool comp;								//Checks whether the player is a human or computer
	int play_hum(Deck&, const Card&);		//Lets the player choose or draw a card
	int play_comp(Deck&, const Card&);		//Lets the computer choose or draw a card
	void change_suit(int);					//When an 8 is drawn, the player/computer and change the suit
	int choose_card(Deck&, const Card&);	//Pulls a card form the player or computer deck depending on what turn it is.

public:
	Player();								//Constructor for computer
	Player(string);							//Constructor for player using thier name
	string get_name() const;				//Gets the players name
	Hand& get_hand();						//Grabs the players hand 
	bool turn(Deck&, Card&);				//Plays either the computers or players turn
};
#endif
