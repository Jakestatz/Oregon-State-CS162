#ifndef CARD_H
#define CARD_H
#include <iostream>

using namespace std;

class Card {
   private:
      int rank;
      int suit;
   public:
      Card();
      ~Card();
      Card(const Card&);
      Card& operator= (const Card&);
};
#endif
