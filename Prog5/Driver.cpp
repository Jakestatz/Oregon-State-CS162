/***************************************************************************
** File: Driver.cpp
** Author: Jake Statz
** Date: 6/07/2020
** Description: Contains the funtions that run the program
**************************************************************************/

#include "Linked_List.hpp"
#include "Functions.h"

/********************************************************
** Function: test_unsigned()
** Description: Takes input and tests the list
** Input: A list
** Pre-Conditions: none
** Post-Conditions: Tests the list and diplays the result
********************************************************/
void test_unsigned();

/********************************************************
** Function: test_signed()
** Description: Takes input and tests the list
** Input: none
** Pre-Conditions: none
** Post-Conditions: Tests the list and diplays the result
********************************************************/
void test_signed();

/********************************************************
** Function: main()
** Description: Takes user input and runs tests on lists
** Input: none
** Pre-Conditions: none
** Post-Conditions: Returns the results
********************************************************/
int main() {
    do {
        if (get_input("Do you want your list to be signed or unsigned? (s or u): ", 's', 'u')) {
            test_signed();
        }
        else {
            test_unsigned();
        }
    } while (get_input("Test again? (y or n): ", 'y', 'n'));
    return 0;
}

void test_unsigned() {
    Linked_List<unsigned int> list;
    do {
        list.push_back(get_unsigned_int("Enter a positive number: "));
    } while (get_input("Would you like to add another number? (y or n): ", 'y', 'n'));
    if (get_input("Would you like to sort ascending or descending? (a or d): ", 'a', 'd')) {
        list.sort_ascending();
    }
    else {
        list.sort_descending();
    }
    cout << "Your linked list is: ";
    list.print();
    unsigned int num_primes = list.num_primes();
    cout << "You have " << num_primes << " prime number" << (num_primes == 1 ? "" : "s") << " in your list." << endl;
}

void test_signed() {
    Linked_List<int> list;
    do {
        list.push_back(get_int("Enter a number: "));
    } while (get_input("Would you like to add another number? (y or n): ", 'y', 'n'));
    if (get_input("Sort ascending or descending? (a or d): ", 'a', 'd')) {
        list.sort_ascending();
    }
    else {
        list.sort_descending();
    }
    cout << "Your linked list is: ";
    list.print();
    unsigned int primes = list.num_primes();
    cout << "You have " << primes << " prime number" << (primes == 1 ? "" : "s") << " in your list." << endl;
}
