#ifndef SQUARE_H
#define SQUARE_H

#include <iostream>
#include <cstdlib>
#include <string>
#include "rectangle.h"

using namespace std;

class Square : public Rectangle{
   public:
      Square(float, string, string);
      void Setdimentions(float);
};
#endif
