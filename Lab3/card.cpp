#include <iostream>
#include "card.h"

using namespace std;

void Card::Card (){
   suit = 3;
   rank = 4;
}
char Card::suits (void){
   if (suit == 1){
      return 'H';
   }
   else if (suit == 2){
      return 'S';
   }
   else if (suit == 3){
      return 'C';
   }
   else if (suit == 4){
      return 'D';
   }
  }
