#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class Shape{
   private:
      string name;
      string color;
   public:
      float Area(float, float);
      Shape(string, string);
      string Name();
      string Color();
      void Setname(string);
      void Setcolor(string);
      bool operator< (Shape &);
};
#endif
