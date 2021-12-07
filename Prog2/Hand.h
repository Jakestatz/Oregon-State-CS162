/******************************************************
** Program: Hand.h
** Author: Jake Statz
** Date: 04/26/2020
** Description: Declares the Hand class and it's supporting functions
** Input: 
** Output:
******************************************************/
#ifndef HAND_H
#define HAND_H

#include <iostream>			//Include Libraries
#include <cstdlib>
#include <string>
#include "Card.h"

using namespace std;

class Hand {				//Declare the Hand class
private:
	Card* cards;			//Allocates memory
	int n_cards;			//Number of cards in the hand.
	int size;				//The size of of the hand, for deap copy
	void increase();		//Increases the size of the array

public:
	Hand();							//Constructor
	Hand(const Hand&);				//Copy Constructor
	Hand& operator= (const Hand&);  //Assignment operator overload
	~Hand();						//Deconstructor
	Card& play_card(int);			//Allows the user to play a card
	Card* get_cards();				//Gets the array of cards
	int get_size() const;			//Gets the number of cards in the players hand
	void get_card(const Card&);		//Adds a card to the player/computers hand when needed
	void print() const;				//Prints the player hand on screen
};
#endif