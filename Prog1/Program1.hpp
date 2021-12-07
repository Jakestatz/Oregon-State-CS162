/******************************************************
** Program: wizard_catalog
** Author: Jake Statz
** Date: 4/12/20
** Description: .hpp file containing structs and fucntion prototypes
** Input: 2 text files, and choices for how the data should be sorted
** Output: a txt file or data displayed on screen
******************************************************/
#ifndef PROGRAM1_HPP
#define PROGRAM1_HPP

#include <string>
#include <fstream>
#include <iostream>         //declare libraries
#include <cstdlib>

using namespace std;

struct wizard {                 //declare wizard struct
    string name;
    int id;
    string password;
    string position_title;
    float beard_length;
};
struct spell {                  //declare spell struct
    string name;
    float success_rate;
    string effect;
};
struct spellbook {              //declare spellbook struct
    string title;
    string author;
    int num_pages;
    int edition;
    int num_spells;
    float avg_success_rate;
    spell* s;
};

//Function Prototypes
char** create_cstring(int, int);
void delete_cstring(char**, int);
spellbook* create_spellbooks(int);
int getwizard(wizard*, int, ifstream&);
void get_spellbook_data(spellbook*, int, ifstream&);
spell* create_spells(int);
void get_spell_data(spell*, int, ifstream&);
void delete_info(wizard**, int, spellbook**, int);
bool isNumber(string);
int is_wizard(int, string, wizard*, int);
void profiled(int, wizard*);
wizard* create_wizards(int);
void page_number(spellbook*, int, int);
void effect(spellbook*, int, int);
void succ_rate(spellbook*, int, int);
int option();
int display();

#endif
