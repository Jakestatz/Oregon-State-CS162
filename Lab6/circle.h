#ifndef CIRCLE_H
#define CIRCLE_H

#include <iostream>
#include <cstdlib>
#include <string>
#include "shape.h"

using namespace std;

class Circle : public Shape{
   private: 
      float radius;
   public:
      Circle(float,string,string);
      float Radius();
      void Setradius(float);
      float Area(float);  
};
#endif
