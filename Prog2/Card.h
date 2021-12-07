/******************************************************
** Program: Card.h
** Author: Jake Statz
** Date: 04/26/2020
** Description: Declares the Card class and it's supporting functions
** Input:
** Output:
******************************************************/
#ifndef CARD_H
#define CARD_H

#include <iostream>						//Include Libraries
#include <cstdlib>
#include <string>

using namespace std;

class Card {
private:
	int suit; // Represents the suit of a card (0-3)
	int rank; // Represents the rank of a card (0-12)

public:
	void update(int, int);				//Allows the cards to have their suits and ranks changed
	Card(int s = 0, int r = 0);			//Sets the card's suit and rank
	void set_s(int);					//Sets the card's suit
	void set_r(int);					//Sets the cars's rank
	int get_s() const;					//Gets the card's suit
	int get_r() const;					//Gets the card's rank
	bool matches(const Card&) const;	//Checks if the card matches the card on top of the deck
	void print() const;					//Prints the cards
	
};
#endif