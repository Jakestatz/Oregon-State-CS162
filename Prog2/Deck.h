/******************************************************
** Program: Deck.h
** Author: Jake Statz
** Date: 04/26/2020
** Description: Declares the Deck class and it's supporting functions
** Input:
** Output:
******************************************************/
#ifndef DECK_H
#define DECK_H

#include <iostream>					//Include Libraries
#include <cstdlib>
#include <string>
#include "Card.h"

using namespace std;

class Deck {
private:
	Card cards[52];					//The array of cards
	int n_cards;					//The number of cards in the deck
	void swapc(Card&, Card&);		//swaps two cards in the array

public:
	Deck();							//Constructor
	Card* get_cards();				//Gets the array of cards
	int get_size() const;			//Gets the size of the array of cards
	Card& draw();					//Draws the top cards off of the deck
	void print() const;				//Prints the card
	void shuffle();					//Shuffles all 52 cards in the deck
};
#endif
