#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>
#include <cstdlib>
#include <string>
#include "shape.h"

using namespace std;

class Rectangle : public Shape {
   private:
      float width;
      float height;
      string invalid_argument;
   
   public:
      Rectangle();
      Rectangle(int);
      float get_width();
      float get_height();
      void set_width(float);
      void set_height(float);
      float area();
};
#endif
