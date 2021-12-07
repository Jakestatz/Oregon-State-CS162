/***************************************************************************
** File: Zoo.h
** Author: Jake Statz
** Date: 5/10/2020
** Description: Zoo class and supporting functions
**************************************************************************/

#ifndef ZOO_H
#define ZOO_H

#include <iostream>
#include "Animal.h"
#include "Bear.h"
#include "Sealion.h"
#include "Tiger.h"

using namespace std;

class Zoo {
private:
	int bank; 
	Animal** animals; 
	int total_animals; 
	int num_animals[3]; 
	int num_adults[3];
	int num_months;
	int sick_prob; 
	int food_cost; 

	/********************************************************
	** Function: increase()
	** Description: Deep copies to increase the size of the animal arry
	** Input: none
	** Pre-Conditions: none
	** Post-Conditions: The data is copied to a new array of one unit longer
	********************************************************/
	void increase();

	/********************************************************
	** Function: decrease()
	** Description: Removes an animal at the given point in the array
	** Input: int num
	** Pre-Conditions: There is an array of animals
	** Post-Conditions: The inputed animals is taken from the array
	********************************************************/
	void decrease(int);

	/********************************************************
	** Function: turn()
	** Description: The players turn while playing the game. Allows for player action
	** Input: User
	** Pre-Conditions: none
	** Post-Conditions: User input errors and if the game is lost
	********************************************************/
	bool turn();

	/********************************************************
	** Function: new_age()
	** Description: Changes the age of the animals
	** Input: none
	** Pre-Conditions: none
	** Post-Conditions: The months is also changed so the player can keep track of their progress
	********************************************************/
	void new_age();

	/********************************************************
	** Function: income()
	** Description: Increases the amount in the players bank by the calculated income
	** Input: none
	** Pre-Conditions: none
	** Post-Conditions: Income and players bank acount
	********************************************************/
	void income(bool);

	/********************************************************
	** Function: special_event()
	** Description: Each month a new special event is choosen
	** Input: bool bonus
	** Pre-Conditions: none
	** Post-Conditions: Events are birth, sickness, attendence boost, or nothing
	********************************************************/
	bool special_event(bool&);

	/********************************************************
	** Function: sick()
	** Description: A random animal gets sick and need to be curred with medicine 
	** Input: none
	** Pre-Conditions: none
	** Post-Conditions: If the player doesnt have enough money in his bank then the animal dies.
	********************************************************/
	bool sick();

	/********************************************************
	** Function: birth()
	** Description: Chooses a random adult animal to give birth 
	** Input: none
	** Pre-Conditions: none
	** Post-Conditions: Depending on the animal a certain number of babies will be born.
	********************************************************/
	bool birth();

	/********************************************************
	** Function: food()
	** Description: Uses the food multiplier to find the cost of food and takes it from the bank
	** Input: none
	** Pre-Conditions: none
	** Post-Conditions: will determine if the game is over becuase the player can't feed their animals
	********************************************************/
	bool food();

	/********************************************************
	** Function: get_input()
	** Description: Takes the users input
	** Input: none
	** Pre-Conditions: none
	** Post-Conditions: allows the game to select options
	********************************************************/
	bool get_input();

	/********************************************************
	** Function: add_animal()
	** Description: Adds the animal to the animal array
	** Input: none
	** Pre-Conditions: none
	** Post-Conditions: The zoo has a new animal
	********************************************************/
	void add_animal(Animal*);

	/********************************************************
	** Function: buy_animal()
	** Description: The user can choose which animal they would like to buy
	** Input: none
	** Pre-Conditions: none
	** Post-Conditions: Allows the user to spend their ectra money
	********************************************************/
	bool buy_animal();

	/********************************************************
	** Function: display()
	** Description: Displays the option each month
	** Input: none
	** Pre-Conditions: none
	** Post-Conditions: Prints out the collected data
	********************************************************/
	void display();

	/********************************************************
	** Function: lose()
	** Description: Determines if the loss condition is met
	** Input: none
	** Pre-Conditions: none
	** Post-Conditions: Prints out when the game is over.
	********************************************************/
	void lose();

public:

	/********************************************************
	** Function: Constructor for the zoo
	** Description: Create a new zoo when the game begins
	** Input: 
	** Pre-Conditions: none
	** Post-Conditions: Member variables get initialized
	********************************************************/
	Zoo();

	/********************************************************
	** Function: Copy constructor for zoo
	** Description: Deep copy
	** Input: old zoo
	** Pre-Conditions: none
	** Post-Conditions: Memeber variables get initialized
	********************************************************/
	Zoo(const Zoo&);

	/********************************************************
	** Function: Operator overload for zoo
	** Description: Deep copy
	** Input: old zoo
	** Pre-Conditions: none
	** Post-Conditions: a deep copy is performed
	********************************************************/
	Zoo& operator=(const Zoo&);

	/********************************************************
	** Function: Zoo destructor
	** Description: Uninisiaizes memory
	** Input: none
	** Pre-Conditions: none
	** Post-Conditions: Frees memory
	********************************************************/
	~Zoo();

	/********************************************************
	** Function: play()
	** Description: Starts the game
	** Input: none
	** Pre-Conditions: none
	** Post-Conditions: Plays the game
	********************************************************/
	void play();
};
#endif