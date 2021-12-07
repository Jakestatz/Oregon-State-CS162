#include <iostream>
#include "hand.h"
#include "card.h"

using namespace std;

Hand::Hand(){
   n_cards = 0;
   cards = NULL;
}
Hand::~Hand(){
   delete [] cards;
   cout << "Destructor called!" << endl;
}
Hand::Hand(const Hand& old_hand){
   n_cards = old_hand.n_cards;
   cards = new Card[n_cards];
   for (int x=0; x<n_cards; x++){
      cards[x] = old_hand.cards[x];
   }
}
Hand& Hand::operator= (const Hand &h){
   n_cards = h.n_cards;
   cards = new Card[n_cards];
   for (int x=0; x<n_cards; x++){
      cards[x] = h.cards[x];
   }
   return *this;
}

