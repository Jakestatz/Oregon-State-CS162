#include <iostream>  
#include "shape.h"
#include "square.h"

using namespace std;

Square::Square(float d, string n, string c) : Rectangle(d, d, n, c){}

void Square::Setdimentions(float d){
   Setwidth(d);
   Setheight(d);
}
