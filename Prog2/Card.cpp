/******************************************************
** Program: Card.cpp
** Author: Jake Statz
** Date: 04/26/2020
** Description: The Card function definitions
** Input:
** Output:
******************************************************/
#include <iostream>
#include <cstdlib>
#include <string>
#include "Card.h"

using namespace std;

Card::Card(int s, int r) {
	suit = s;
	rank = r;
}

bool Card::matches(const Card& c) const {
	return (suit == c.suit || rank == c.rank);
}

void Card::set_s(int s) {
	suit = s;
}

void Card::set_r(int r) {
	rank = r;
}

int Card::get_s() const {
	return suit;
}

int Card::get_r() const {
	return rank;
}

void Card::update(int s, int r) {
	suit = s;
	rank = r;
}

void Card::print() const {
	string suits[] = { "Hearts", "Clubs", "Spades", "Diamonds" };
	string ranks[] = { "Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King" };
	cout << ranks[rank] << " of " << suits[suit] << endl;
}
