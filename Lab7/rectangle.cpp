#include <iostream>
#include "rectangle.h"

using namespace std;

Rectangle::Rectangle(){
   set_name("Rectangle1");
   set_color("Yellow");
   height = 0;
   width = 0;
   invalid_argument = ("Invalid constructor argument");
}

Rectangle::Rectangle(int square){
   set_name("Square1");
   set_color("Brown");
   height = square;
   width = square;
}

float Rectangle::get_width(){
   return width;
}

float Rectangle::get_height(){
   return height;
}

void Rectangle::set_width(float a){
   width = a;
}

void Rectangle::set_height(float a){
   height = a;
}

float Rectangle::area(){
   if (width*height == 0){
      throw invalid_argument;
   }
   return width * height;
}
