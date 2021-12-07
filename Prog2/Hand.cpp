/******************************************************
** Program: Hand.cpp
** Author: Jake Statz
** Date: 04/26/2020
** Description: The Hand function definitions
** Input:
** Output:
******************************************************/
#include <iostream>				//Include Libraries
#include <cstdlib>
#include <string>
#include "Hand.h"
#include "Card.h"

using namespace std;

Hand::Hand() {
	n_cards = 0;
	size = 8;
	cards = new Card[size];
}

Hand::Hand(const Hand& h) {
	n_cards = h.n_cards;
	size = h.size;
	cards = new Card[size];
	for (int x = 0; x < size; x++) {
		cards[x] = h.cards[x];
	}
}

Hand& Hand::operator= (const Hand& h) {
	if (&h != this) {
		delete[] cards;
		n_cards = h.n_cards;
		size = h.size;
		cards = new Card[size];
		for (int x = 0; x < size; x++) {
			cards[x] = h.cards[x];
		}
	}
	return *this;
}

Hand::~Hand() {
	delete[] cards;
}

void Hand::increase() {
	size *= 2;
	Card* temp = new Card[size];
	for (int x = 0; x < n_cards; x++) {
		temp[x] = cards[x];
	}
	delete[] cards;
	cards = temp;
}

void Hand::get_card(const Card& c) {
	if (n_cards + 1 >= size) {
		increase();
	}
	cards[n_cards] = c;
	n_cards++;
}

Card& Hand::play_card(int index) {
	Card temp = cards[index];
	for (int x = index + 1; x < n_cards; x++) {
		cards[x - 1] = cards[x];
	}
	n_cards--;
	cards[n_cards] = temp;
	return cards[n_cards];
}

Card* Hand::get_cards() {
	return cards;
}

int Hand::get_size() const {
	return n_cards;
}

void Hand::print() const {
	for (int x = 0; x < n_cards; x++) {
		cout << x + 1 << ". ";
		cards[x].print();
	}
	cout << n_cards + 1 << ". Draw another card" << endl;
}