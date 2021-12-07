#include <iostream>
#include <string>
#include "profdemo.h"

using namespace std;

Date::Date(){
   month = 1;
   day = 1;
   year = 2001;
}

Date::Date(int m, int d, int y){
   month = m;
   day = d;
   year = y;
}

void Date::print1(){
   cout << month << "/" << day << "/" << year << endl;
}
void Date::print2(){
   cout << word(month) << " " << day << "," << year << endl;
}

string Date::word(int month){
   if (month == 1)
      return "January";
   else if (month == 2)
      return "February";
   else if (month == 3)
      return "March";
   else if (month == 4)
      return "April";
   else if (month == 5)
      return "May";
   else if (month == 6)
      return "June";
   else if (month == 7)
      return "July";
   else if (month == 8)
      return "August";
   else if (month == 9)
      return "September";
   else if (month == 10)
      return "October";
   else if (month == 11)
      return "November";
   else if (month == 12)
      return "December";
}
