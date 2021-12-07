/******************************************************
** Program: Player.cpp
** Author: Jake Statz
** Date: 04/26/2020
** Description: The Player function definitions
** Input: 
** Output:
******************************************************/
#include <iostream>					//Include Libraries
#include <cstdlib>
#include <string>
#include "Player.h"
#include "Functions.h"

using namespace std;

Hand& Player::get_hand() {		//returns the players hand
	return hand;
}

Player::Player() {					//Names the computer "Computer"
	name = "Computer";
	comp = true;
}

string Player::get_name() const {	//Gets the Player's name from an input
	return name;
}

Player::Player(string n) {
	name = n;
	comp = false;
}

void Player::change_suit(int num) {										//When an 8 is played the player has the option to change the suit
	if (comp) {
		int count[] = { 0, 0, 0, 0 };
		int suit = 0;
		for (int x = 0; x < hand.get_size(); x++) {
			count[hand.get_cards()[x].get_s()] ++;
		}
		for (int i = 1; i < 4; i++) {
			if (count[0] < count[i]) {
				count[0] = count[i];
				suit = i;
			}
		}
		hand.get_cards()[num].set_s(suit);
	}
	else {
		for (int y = 0; y < 4; y++) {
			string suits[] = { "Hearts", "Clubs", "Spades", "Diamonds" };
			cout << y + 1 << ". " << suits[y] << endl;
		}
		hand.get_cards()[num].set_s(range("What is the new suit?: ", 1, 4) - 1);
	}
}

int Player::play_hum(Deck& deck, const Card& c) {														//The players turn
	while (true) {
		cout << "Play or draw a card" << endl;
		hand.print();
		int num = range("Choose an option: ", 1, hand.get_size() + 1) - 1;
		cout << endl;
		if (num == hand.get_size()) {
			hand.get_card(deck.draw());
			if (deck.get_size() == 0) {
				cout << "Last card drawn!" << endl;
				return -1;
			}
		}
		else if (hand.get_cards()[num].matches(c) || hand.get_cards()[num].get_r() == 7) {
			return num;
		}
		else {
			cout << "That card isn't the same rank or suit. Choose again.\n" << endl;
		}

	}
}

bool Player::turn(Deck& deck, Card& card) {
	cout << name << "'s turn\t" << endl;
	cout << "The top card is: ";
	card.print();
	cout << endl;
	int num = choose_card(deck, card);
	if (num == -1) {
		return true;
	}
	if (hand.get_cards()[num].get_r() == 7) {
		change_suit(num);
	}
	card = hand.play_card(num);
	if (hand.get_size() == 0) {
		cout << name << " is out of cards!" << endl;
		return true;
	}
	return false;
}

int Player::play_comp(Deck& deck, const Card& c) {									//Computers turn
	for (int x = 0; x < hand.get_size(); x++) {
		if (hand.get_cards()[x].matches(c)) {
			return x;
		}
	}
	for (int y = 0; y < hand.get_size(); y++) {
		if (hand.get_cards()[y].get_r() == 7) {
			return y;
		}
	}
	while (true) {
		hand.get_card(deck.draw());
		if (deck.get_size() == 0) {
			cout << "Computer drew the last card" << endl;
			return -1;
		}
		if (hand.get_cards()[hand.get_size() - 1].get_r() == 7) {
			return hand.get_size() - 1;
		}
	}
}

int Player::choose_card(Deck& deck, const Card& c) {
	if (comp == true) {
		play_comp(deck, c);
	}
	else {
		return play_hum(deck, c);
	}
}