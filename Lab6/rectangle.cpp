#include <iostream>
#include "shape.h"
#include "rectangle.h"

using namespace std;

Rectangle::Rectangle(float w, float h, string n, string c) : Shape (n, c){
	width = w;
	height = h;
}

float Rectangle::Width(){
	return width;
}

float Rectangle::Height(){
	return height;
} 

void Rectangle::Setwidth(float w){
	width = w;
}

void Rectangle::Setheight(float h){
	height = h;
}
float Rectangle::Area()const{
   return width*height;
}
bool Rectangle::operator< (const Rectangle& a){
   if (this -> Area() < a.Area()) return true;
   else return false;
}

