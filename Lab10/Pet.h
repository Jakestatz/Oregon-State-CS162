#ifndef PET_H
#define PET_H

#include <iostream>
#include <string>

using namespace std;

class Pet{
   protected:
      string name;
      int weight;

   public:
      Pet();
      Pet(string, int);
      string getname();
      int getweight();
      void setname(string);
      void setweight(int);
      string getLifespan();
};
#endif
