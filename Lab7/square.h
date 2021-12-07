#ifndef SQUARE_H
#define SQUARE_H

#include <iostream>
#include <cstdlib>
#include <string>
#include "rectangle.h"

using namespace std;

class Square : public Rectangle{
   public:
      Square();
      Square(int);
};
#endif
