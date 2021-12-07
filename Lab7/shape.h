#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class Shape {
   private:
      string name;
      string color;
   public:
      Shape();
      string get_name();
      string get_color();
      void set_name(string);
      void set_color(string);
      virtual float area()=0;
      bool operator< (Shape &);
};
#endif
