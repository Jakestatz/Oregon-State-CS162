#include <iostream>
#include "prog2class.h"
#include <string>
#include <cstdlib>

using namespace std;

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

Hand::~Hand(){
   cout << "Destructor called!" << endl;
}
Hand::Hand(const Hand& old_hand){
   n_cards = old_hand.n_cards;
   cards = old_hand.cards;
}
Hand& Hand::operator= (const Hand &h){
   n_cards = h.n_cards;
   cards = h.cards;
   return *this;
}

Player::~Player(){
   cout << "Destructor called!" << endl;
}
Player::Player(const Player& old_player){
   hand = old_player.hand;
   name = old_player.name;
}
Player& Player::operator= (const Player &p){
   hand = p.hand;
   name = p.name;
   return *this;
}

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

