#ifndef DOG_H
#define DOG_H

#include <iostream>
#include <string>

using namespace std;

class Dog:public Pet{
   private:
      string breed;

   public:
      Dog();
      Dog(string, int, string);
      string getbreed();
      void setbreed(string);
      string getLifespan();
};
#endif
