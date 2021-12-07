#include <iostream>
#include "deck.h"

using namespace std;

Deck::~Deck(){
   cout << "Destructor called!" << endl;
}
Deck::Deck(const Deck& old_deck){
   n_cards = old_deck.n_cards;
   cards = old_deck.cards;
}
Deck& Deck::operator= (const Deck &d){
   n_cards = d.n_cards;
   cards = d.cards;
   return *this;
}
