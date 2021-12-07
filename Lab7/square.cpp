#include <iostream>  
#include "square.h"

using namespace std;

Square::Square(){
   set_width(0);
   set_height(get_width());
}

Square::Square(int d){
   set_width(d);
   set_height(d);
}
