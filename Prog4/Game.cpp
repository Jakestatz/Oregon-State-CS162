/***************************************************************************
** File: Game.cpp
** Author: Jake Statz
** Date: 05/23/2020
** Description: The functions that define and run the game
**************************************************************************/

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include "Game.h"
#include "Event.h"
#include "Bat.h"
#include "Gold.h"
#include "Pit.h"
#include "Wumpus.h"
#include "Room.h"
#include "Functions.h"
#include "AI_Functions.h"

using namespace std;

Game::Game() {
	size = 0;
	debug = false;
	gold = false;
	gold_row = gold_col = player_row = player_col = rope_row = rope_col = original_wumpus_row = original_wumpus_col = wumpus_row = wumpus_col = 0;
	arrows = 0;
	shooting = false;
	
}

Game::Game(int s, bool num) {
	init(s, num);
	room_events();
}

void Game::init(int s, bool num) {					
	shooting = false;
	size = s;
	arrows = 3;
	debug = num;
	gold = false;
	for (int x = 0; x < s; ++x) {
		cave.push_back(vector<Room>());
		ai_data.push_back(vector<AI>());
		for (int y = 0; y < s; ++y) {
			ai_data[x].push_back(AI());
			cave[x].push_back(Room());
		}
	}
}

void Game::move_player(int r, int c) {
	player_row = r;
	player_col = c;
}

vector<vector<Room>>& Game::get_cave() {
	return cave;
}

int Game::get_size() {
	return size;
}

void Game::get_gold() {
	gold = true;
	delete cave[gold_row][gold_col].remove_event();
}

void Game::place_wumpus() {
	do {
		original_wumpus_row = wumpus_row = rand() % size;
		original_wumpus_col = wumpus_col = rand() % size;
	} while (wumpus_row == player_row && wumpus_col == player_col);
	cave[wumpus_row][wumpus_col].set_event(new Wumpus(wumpus_row, wumpus_col));
}

void Game::place_bats() {
	int r, c;
	for (int i = 0; i < 2; ++i) {
		do {
			r = rand() % size;
			c = rand() % size;
		} while (cave[r][c].has_event() || (r == player_row && c == player_col));
		cave[r][c].set_event(new Bat(r, c));
	}
}

void Game::place_pits() {
	int r, c;
	for (int i = 0; i < 2; ++i) {
		do {
			r = rand() % size;
			c = rand() % size;
		} while (cave[r][c].has_event() || (r == player_row && c == player_col));
		cave[r][c].set_event(new Pit(r, c));
	}
}

void Game::place_gold() {
	do {
		gold_row = rand() % size;
		gold_col = rand() % size;
	} while (cave[gold_row][gold_col].has_event() || (gold_row == player_row && gold_col == player_col));
	cave[gold_row][gold_col].set_event(new Gold(gold_row, gold_col));
}

void Game::room_events() {
	player_row = rope_row = rand() % size;			//Player and exit rooms
	player_col = rope_col = rand() % size;
	place_wumpus();									//Wumpus rooms
	place_bats();									//Bat rooms
	place_pits();									//Pit rooms
	place_gold();									//Gold room

}

bool Game::get_input() {
	char d = get_input_move("Which direction would you like to move? (w, a, s, d), or press space to shoot an arrow: ", true);
	if (d == ' ') {
		return true;
	}
	int r = player_row + (d == 'w' ? -1 : (d == 's' ? 1 : 0));
	int c = player_col + (d == 'a' ? -1 : (d == 'd' ? 1 : 0));
	if (r < size && c < size && r >= 0 && c >= 0) {
		player_row = r;
		player_col = c;
	}
	return false;
}

string Game::search_adjacent() {
	vector<int> next;
	string s = "";
	for (int i = 0; i < 4; ++i) next.push_back(i);
	std::random_shuffle(next.begin(), next.end());
	for (int d : next) {
		int r = player_row + (d < 2 ? d % 2 : -d % 2);
		int c = player_col + (d < 2 ? 1 - d % 2 : d % 2 - 1);
		if (r < size && c < size && r >= 0 && c >= 0) {
			if (cave[r][c].has_event()) {
				cave[r][c].get_event()->percept();
				s += cave[r][c].get_event()->letter();
			}
		}
	}
	return s;
}

void Game::shoot_arrow(bool AI) {
	if (arrows == 0) {
		cout << "Quiver is empty." << endl;
		return;
	}
	--arrows;
	char d = AI ? AI_get_shoot_direction() : get_input_move("Which direction would you like to shoot?(w, a, s, d)", false);
	if (!cave[wumpus_row][wumpus_col].has_event()) return;
	for (int i = 1; i <= 3; ++i) {
		int r = player_row + (d == 'w' ? -i : (d == 's' ? i : 0));
		int c = player_col + (d == 'a' ? -i : (d == 'd' ? i : 0));
		if (r >= size || c >= size || r < 0 || c < 0) {
			break;
		}
		if (wumpus_row == r && wumpus_col == c) {
			cout << "You shot the Wumpus." << endl;
			delete cave[r][c].remove_event();
			return;
		}
	}
	cout << "You missed" << endl;
	move_wumpus();
}

bool Game::AI_exit(string num) {
	if (player_row < rope_row && num.find('s') == string::npos) {
		++player_row;
	}
	else if (player_row > rope_row&& num.find('w') == string::npos) {
		--player_row;
	}
	else if (player_col < rope_col && num.find('d') == string::npos) {
		++player_col;
	}
	else if (player_col > rope_col&& num.find('a') == string::npos) {
		--player_col;
	}
	else {
		return false;
	}
	return true;
}

bool Game::update_AI_data(string adj, string& bad_dirs, bool& moved) {
	char dirs[] = { 'd', 'w', 'a', 's' };
	for (int i = 0; i < 4; ++i) {
		int r = player_row + (i < 2 ? i % 2 : -i % 2);
		int c = player_col + (i < 2 ? 1 - i % 2 : i % 2 - 1);
		if (r < size && c < size && r >= 0 && c >= 0) {
			ai_data[r][c].update(player_row, player_col, adj);
			if (ai_data[r][c].is_verified()) {
				if (ai_data[r][c].get_event() == 'G') {
					player_row = r;
					player_col = c;
					moved = true;
					return false;
				}
				if (ai_data[r][c].get_event() == 'W') {
					return true;
				}
				if (ai_data[r][c].get_event() != 0) {
					bad_dirs += dirs[i];
				}
			}
		}
	}
	return false;
}

bool Game::AI_get_input(string adj) {
	get_input_move("Press space to continue...", true);
	string bad_dirs = "";
	bool moved = false;
	if (update_AI_data(adj, bad_dirs, moved)) return true;
	if (moved) return false;

	if (gold) {
		if (AI_exit(bad_dirs)) return false;
	}
	int d, r, c;
	do {
		d = rand() % 4;
		r = player_row + (d < 2 ? d % 2 : -d % 2);
		c = player_col + (d < 2 ? 1 - d % 2 : d % 2 - 1);
	} while (r >= size || c >= size || r < 0 || c < 0);
	player_row = r;
	player_col = c;
	return false;
}

char Game::AI_get_shoot_direction() {
	for (int i = 0; i < 4; ++i) {
		int r = player_row + (i < 2 ? i % 2 : -i % 2);
		int c = player_col + (i < 2 ? 1 - i % 2 : i % 2 - 1);
		if (r < size && c < size && r >= 0 && c >= 0) {
			if (ai_data[r][c].get_event() == 'W') {
				char dirs[] = { 'd', 'w', 'a', 's' };
				return (dirs[i]);
			}
		}
	}
	return 0;
}

bool Game::turn(bool AI) {
	if (shooting) {
		shoot_arrow(AI);
		shooting = false;
	}
	if (cave[player_row][player_col].has_event()) {
		if (cave[player_row][player_col].get_event()->encounter(*this)) return true;
	}
	if (gold && player_row == rope_row && player_col == rope_col) {
		cout << "YOU WIN!" << endl;
		return true;
	}
	string adj = search_adjacent();
	display();
	shooting = AI ? AI_get_input(adj) : get_input();
	return false;
}

void Game::move_wumpus() {
	if (rand() % 4 == 0) return;
	int d, r, c, tries = 0;
	do {
		++tries;
		d = rand() % 4;
		r = wumpus_row + (d < 2 ? d % 2 : -d % 2);
		c = wumpus_col + (d < 2 ? 1 - d % 2 : d % 2 - 1);
	} while (tries < 8 && (r >= size || c >= size || r < 0 || c < 0 || cave[r][c].has_event() || (r == rope_row && c == rope_col) || (r == player_row && c == player_col)));
	cave[r][c].set_event(cave[wumpus_row][wumpus_col].remove_event());
	wumpus_row = r;
	wumpus_col = c;
}

void Game::display() {
	cout << "You have " << arrows <<  " arrows." << endl;
	for (int x = 0; x < size * 4 + 1; ++x) {
		for (int y = 0; y < size * 4 + 1; ++y) { 
			cout << (y % 4 == 0 ? (x % 4 == 0 ? '+' : '|') : (x % 4 == 0 ? '-' : (y % 2 == 0 && x % 2 == 0 ? (x / 4 == player_row && y / 4 == player_col ? '*' : (debug ? (cave[x / 4][y / 4].has_event() ? (cave[x / 4][y / 4].get_event()->letter()) : (x / 4 == rope_row && y / 4 == rope_col) ? 'R' : ' ') : ' ')) : ' ')));
		}
		cout << endl;
	}
}

void Game::play() {
	bool AI = get_range("Do you want the AI to play? (1-yes, 0-no): ", 0, 1);
	while (true) {
		if (turn(AI)) {
			if (!get_range("Play again? (1-yes, 0-no): ", 0, 1)) return;
			AI = get_range("Do you want the AI to play? (1-yes, 0-no): ", 0, 1);
			if (get_range("Would you like the same board size? (1-yes, 0-no): ", 0, 1)) {
				clean();
			}
			else {
				int s = get_range("Enter the size of the grid (between 3 and 20): ", 3, 20);
				bool num = get_range("Run in debug mode? (1-yes, 0-no): ", 0, 1);
				cave.clear();
				ai_data.clear();
				init(s, num);
				room_events();
			}
		}
	}
}

void Game::clean() {
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			ai_data[i][j].reset();
		}
	}
	arrows = 3;
	if (cave[wumpus_row][wumpus_col].has_event()) {
		cave[original_wumpus_row][original_wumpus_col].set_event(cave[wumpus_row][wumpus_col].remove_event());
	}
	else {
		cave[original_wumpus_row][original_wumpus_col].set_event(new Wumpus(original_wumpus_row, original_wumpus_col));
	}
	wumpus_row = original_wumpus_row;
	wumpus_col = original_wumpus_col;
	if (gold) {
		cave[gold_row][gold_col].set_event(new Gold(gold_row, gold_col));
		gold = false;
	}
	player_row = rope_row;
	player_col = rope_col;
}