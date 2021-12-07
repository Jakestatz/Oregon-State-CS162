#include <iostream>
#include <string>
#include "Pet.h"

using namespace std;

Pet::Pet(){}

Pet::Pet(string name, int weight){
   name = name;
   weight = weight;
}

string Pet::getname(){
   return name;
}

int Pet::getweight(){
   return weight;
}

void Pet::setname(string name){
   name = name;
}

void Pet::setweight(int weight){
   this-> weight = weight;
}

string Pet::getLifespan(){
   return "unknown lifespan";
}
