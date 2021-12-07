#include <iostream>
#include "card.h"

using namespace std;

class Deck {
   private: 
      Card cards[52];
      int n_cards;
   public:
      ~Deck();
      Deck(const Deck&);
      Deck& operator= (const Deck&);
};
