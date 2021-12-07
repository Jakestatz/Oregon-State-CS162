#include <iostream>
#include <string>
#include "profdemo.h"

using namespace std;

int main(){
   int month, day, year;
   cout << "Enter month: ";
   cin >> month;
   cout << "Enter day: ";
   cin >> day;
   cout << "Enter year: ";
   cin >> year;
   Date one;
   Date two(month, day, year);
   one.print1();
   one.print2();
   two.print1();
   two.print2();
}
