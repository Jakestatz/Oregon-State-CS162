#ifndef PROFDEMO_H
#define PROFDEMO_H

#include <iostream>
#include <string>

using namespace std;

class Date {

   private:
      int month;
      int day;
      int year;

   public:
      Date();
      Date(int, int, int);
      string word(int);
      void print1();
      void print2();
};
#endif
