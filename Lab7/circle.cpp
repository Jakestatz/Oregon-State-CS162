#include <iostream>
#include "circle.h"

using namespace std;

Circle::Circle(){
   set_name("Circle1");
   set_color("Blue");
   radius = 0;
}

float Circle::get_radius(){
   return radius;
}

void Circle::set_radius(float r){
   radius = r;
}

float Circle::area(){
   return 3.141 * (radius * radius);
}
