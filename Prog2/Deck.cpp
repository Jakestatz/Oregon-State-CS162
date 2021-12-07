/******************************************************
** Program: Deck.cpp
** Author: Jake Statz
** Date: 04/26/2020
** Description: The Deck function definitions
** Input:
** Output:
******************************************************/
#include <iostream>				//Include Libraries
#include <cstdlib>
#include <ctime>
#include <string>
#include "Deck.h"
#include "Card.h"

using namespace std;

Deck::Deck() {
	n_cards = 52;
	for (int x = 0; x < 4; x++) {
		for (int y = 0; y < 13; y++) {
			cards[x * 13 + y] = Card(x, y);
		}
	}
	shuffle();
}

Card* Deck::get_cards() {
	return cards;
}

int Deck::get_size() const {
	return n_cards;
}

void Deck::shuffle() {
	for (int x = 0; x < 52; x++) {
		swap(cards[x], cards[rand() % 52]);
	}
}

Card& Deck::draw() {
	n_cards--;
	return cards[n_cards];
}

void Deck::swapc(Card& c1, Card& c2) {
	Card temp = c1;
	c1 = c2;
	c2 = temp;
}

void Deck::print() const {
	for (int x = 0; x < 52; x++) {
		cards[x].print();
		cout << endl;
	}
}