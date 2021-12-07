#include <iostream>
#include <string>

using namespace std;

class Card {
   private:
      int rank;
      int suit;
   public:
      ~Card();
      Card(const Card&);
      Card& operator= (const Card&);
};

class Deck {
   private: 
      Card cards[52];
      int n_cards;
   public:
      ~Deck();
      Deck(const Deck&);
      Deck& operator= (const Deck&);
}

class Hand {
   private:
      Card* cards;
      int n_cards;
   public:
      ~Hand();
      Hand(const Hand&);
      Hand& operator= (const Hand&);
}

class Player {
   private:
      Hand hand;
      string name;
   public:
      ~Player();
      Player(const Player&);
      Player& operator= (const Player&);
}

class Game {
   private:
      Deck cards;
      Player players[2];
   public:
      ~Game();
      Game(const Game&);
      Game& operator= (const Game&);
}
