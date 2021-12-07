#include <iostream>
#include <string>
#include "Pet.h"
#include "Dog.h"

using namespace std;

int main(){
   string name, breed;
   int height, weight, num;

   Pet pet;
   Dog *dog;

   cout << "What is the name of the pet? ";
   cin >> name;
   pet.setname(name);
   cout << "What is the weight of the pet? ";
   cin >> weight;
   pet.setweight(weight);
   cout << pet.getLifespan() << endl;

   cout << "What is the number of dogs? ";
   cin >> num;

   Dog *dogs = new Dog[num];
   for (int x = 0; x < num; x++){
      cout << "What is the name of the dog? ";
      cin >> name;
      cout << "What is the weight of the dog? ";
      cin >> weight;
      cout << "What is breed of the dog? ";
      cin >> breed;
      dogs[x].setname(name);
      dogs[x].setweight(weight);
      dogs[x].setbreed(breed);
   }
   for (int y = 0; y < num; y++){
      cout << "Dog's lifespan: " << dogs[y].getLifespan() << endl;
   }
   delete []dogs;
   
}
