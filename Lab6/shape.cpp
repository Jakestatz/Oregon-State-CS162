#include <iostream>
#include "shape.h"

using namespace std;

float Shape::Area(float num1, float num2){
   return (num1*num2);
}

Shape::Shape(string n, string c){
   name = n;
   color = c;
}

string Shape::Name(){
   return name;
}

string Shape::Color(){
   return color;
}

void Shape::Setname(string n){
   name = n;
}

void Shape::Setcolor(string c){
   color = c;
}
