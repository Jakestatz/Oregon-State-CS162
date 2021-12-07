#include <iostream>
#include "card.h"

using namespace std;

Card::Card(){
   suit=0;
   rank=0;
}
Card::~Card(){
   cout << "Destructor called!" << endl;
}
Card::Card(const Card& old_card){
   rank = old_card.rank;
   suit = old_card.suit;
}
Card& Card::operator= (const Card &c){
   rank = c.rank;
   suit = c.suit;
   return *this;
}
