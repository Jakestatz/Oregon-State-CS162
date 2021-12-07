#include "shape.h"
#include "rectangle.h"
#include "circle.h"
#include "square.h"
#include <iostream>

using namespace std;

void print_shape_info(Shape &);

int main() {
  Shape *shape [3];
  Rectangle rectangle;
  Circle circle;
  Square square(5); 

  rectangle.set_height(2);
  rectangle.set_width(8);
  circle.set_radius(5);
  
  shape[0] = &rectangle;
  shape[1] = &circle;
  shape[2] = &square;
  print_shape_info((*shape[0]));
  print_shape_info((*shape[1]));
  print_shape_info((*shape[2]));


  return 0;
}

void print_shape_info(Shape &s){
   cout << "Name: " << s.get_name() << endl;
   cout << "Color: " << s.get_color() << endl;
   cout << "Area: " << s.area() << endl << endl;
}
