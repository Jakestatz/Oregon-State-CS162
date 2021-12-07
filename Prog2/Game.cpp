/******************************************************
** Program: Game.cpp
** Author: Jake Statz
** Date: 04/26/2020
** Description: The Game function definitions
** Input:
** Output:
******************************************************/
#include <iostream>				//Include Libraries
#include <cstdlib>
#include <string>
#include "Game.h"
#include "Card.h"
#include "Player.h"
#include "Deck.h"

using namespace std;

Game::Game() {
	string name;
	cout << "Enter your name: ";
	getline(cin, name);
	cout << endl;
	players[0] = Player(name);
	for (int x = 0; x < 7; x++) {
		players[1].get_hand().get_card(cards.draw());
		players[0].get_hand().get_card(cards.draw());
	}
	card = cards.draw();
}

void Game::final() {
	while (true) {
		if (players[0].turn(cards, card)) {
			game_winner();
			return;
		}
		if (players[1].turn(cards, card)) {
			game_winner();
			return;
		}
	}
}

void Game::game_winner() {
	if (players[0].get_hand().get_size() < players[1].get_hand().get_size()) {
		cout << players[0].get_name() << " wins!" << endl;
		return;
	}
	cout << players[1].get_name() << " wins!" << endl;
}
