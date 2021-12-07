#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>
#include <cstdlib>
#include <string>
#include "shape.h"

using namespace std;

class Rectangle : public Shape{
   private:
      float height;
      float width;
   public:
      Rectangle(float, float, string, string);
      float Height();
      float Width();
      void Setheight(float);
      void Setwidth(float);
      bool operator< (const Rectangle&);
      float Area()const;
};
#endif
