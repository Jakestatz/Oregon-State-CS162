/***************************************************************************
** File: Animal.cpp
** Author: Jake Statz
** Date: 5/10/2020
** Description: The animals's functions definitions
**************************************************************************/

#include <iostream>
#include "Animal.h"

using namespace std;

Animal::Animal(int cost, int foodx, int babies, int id, int age) {
	this->cost = cost;
	this->foodx = foodx;
	this->babies = babies;
	this->id = id;
	this->age = age;
}

int Animal::get_id() {
	return id;
}

int Animal::get_cost() {
	return cost;
}

int Animal::get_foodx() {
	return foodx;
}

int Animal::get_age() {
	return age;
}

int Animal::get_babies() {
	return babies;
}

void Animal::increase_age() {
	++age;
}

int Animal::revenue(bool bonus) {
	if (age < 6) {
		return 2 * cost / 10;
	}
	return cost / 10;
}

int Animal::sick_cost() {
	if (age < 6) {
		return cost;
	}
	return cost / 2;
}