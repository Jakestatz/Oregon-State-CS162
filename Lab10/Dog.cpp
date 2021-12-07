#include <iostream>
#include <string>
#include "Pet.h"
#include "Dog.h"

using namespace std;

Dog::Dog(){}

Dog::Dog(string name, int weight, string breed):Pet(name, weight), breed(breed){}

string Dog::getbreed(){
   return breed;
}

void Dog::setbreed(string breed){
   breed = breed;
}

string Dog::getLifespan(){
   if (weight < 100){
      return "Approximently 7 years.";
   }
   else{
      return "Approximently 13 years.";
   }
}

