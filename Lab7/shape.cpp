#include <iostream>
#include <string>
#include "shape.h"

using namespace std;

Shape::Shape(){
   try {
      name = "name";
      color = "color";
   }
   catch (int a) {
      cout << "Error\n";
   }
}

string Shape::get_name(){
   return name;
}
string Shape::get_color(){
   return color;
}
void Shape::set_name(string n){
   name = n;
}
void Shape::set_color(string c){
   color = c;
}
bool Shape::operator< (Shape &a){
  if (this->area() < a.area()){
     return true;
  }
  else{
     return false;
  }
}
