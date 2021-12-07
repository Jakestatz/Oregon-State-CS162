#include <iostream>
#include "card.h"

using namespace std;

class Hand {
   private:
      Card* cards;
      int n_cards;
   public:
      Hand();
      ~Hand();
      Hand(const Hand&);
      Hand& operator= (const Hand&);
};
