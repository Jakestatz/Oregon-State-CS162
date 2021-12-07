/***************************************************************************
** File: AI_Fuctions.cpp
** Author: Jake Statz
** Date: 5/23/2020
** Description: The functions for AI mode
**************************************************************************/

#include <iostream>
#include <string>
#include "AI_Functions.h"

using namespace std;

AI::AI() {
	one = false;
	two = false;
	event = 0;
}

char AI::get_event() {
	return event;
}

bool AI::saw() {
	return one;
}

bool AI::is_verified() {
	return two;
}

void AI::update(int row, int column, string adj) {
	if (two) return;
	one = true;
	if (adj == "") {
		two = true;
		return;
	}
	for (unsigned int i = 0; i < p_rows.size(); ++i) {
		if (p_rows[i] == row && p_cols[i] == column) {
			return;
		}
		for (unsigned int j = 0; j < p_rows.size(); ++j) {
			if (next[i].find(adj.at(j)) != string::npos) {
				two = true;
				event = adj.at(j);
				return;
			}
		}
	}
	p_rows.push_back(row);
	p_cols.push_back(column);
	next.push_back(adj);
}

void AI::reset() {
	one = false;
	two = false;
	event = 0;
	p_rows.clear();
	p_cols.clear();
	next.clear();
}
