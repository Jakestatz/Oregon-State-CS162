#include <iostream>
#include "hand.h"
#include <string>

using namespace std;

class Player {
   private:
      Hand hand;
      string name;
   public:
      ~Player();
      Player(const Player&);
      Player& operator= (const Player&);
};
