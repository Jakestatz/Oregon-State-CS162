#include <iostream>
#include <string>
#include "player.h"

using namespace std;

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
