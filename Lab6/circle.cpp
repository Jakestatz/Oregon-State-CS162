#include <iostream>
#include "shape.h"
#include "circle.h"

using namespace std;

Circle::Circle(float r, string n, string c) : Shape(n, c){
	radius = r;
}

float Circle::Radius(){
	return radius;
}

void Circle::Setradius(float r){
	radius = r;
}

float Circle::Area(float num1){
	return ((num1*num1) * 3.14);
}
