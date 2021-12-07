#include <iosteam>
#include "deck.h"

using namespace std;

Game::~Game(){
   cout << "Destructor called!" << endl;
}
Game::Game(const Game& old_game){
   cards = old_game.cards;
   players = old_game.players;
}
Game& Game::operator= (const Game &g){
   cards = g.cards;
   players = g.players;
   return *this;
}
