#include <iosteam>
#include "deck.h"
#include "player.h"

using namespace std;

class Game {
   private:
      Deck cards;
      Player players[2];
   public:
      ~Game();
      Game(const Game&);
      Game& operator= (const Game&);
};
