#include <iostream>
#include <fstream>
#include <cstdlib>
#include "student_db.h"
#include <string.h>

using namespace std;

int main(){
  string str;
  int num, option;
  fstream f;
  f.open("inputs.txt");
  getline(f, str);
  num = atoi(str.c_str());
  student* profile = create_student_db(num); 
  get_student_db_info(profile, num, f);
  cout << "How do you want to sort the data? (1-Last Name, 2-ID Number)";
  cin >> option;
  if (option == 1){
     sort_name(profile, num);
  }
  else if (option == 2){
     sort_id(profile, num);
  }
  fstream out;
  out.open("Output.txt", ios::app|ios::out);
  print(profile, num, out); 
  delete_student_db_info(profile);
  return 0;
}
