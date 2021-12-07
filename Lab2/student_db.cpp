#include <iostream>
#include "student_db.h"
#include <string>
#include <cstdlib>
#include <fstream>

using namespace std;

student* create_student_db(int num){
   student* profile;
   profile = new student[num];
   return profile;
}

void get_student_db_info(student* profile, int num, fstream &f){
   string str;
   //f.seekg(1);
   for (int x = 0; x < num; x++){
      getline(f, str, ' ');
      profile[x].ID_Number = atoi(str.c_str());
      getline(f, str, ' ');
      profile[x].Student_First_Name = str;
      getline(f, str, ' ');
      profile[x].Student_Last_Name = str;
      getline(f, str);
      profile[x].Major = str;
   }
}
void sort_name(student* profile, int num){
   string last, first, major;
   int id;
   for (int i = 0; i < num; i++){
      for (int j = 0; j < num-1; j++){
	 if (profile[j].Student_Last_Name > profile[j+1].Student_Last_Name){

	    last = profile[j].Student_Last_Name;
	    profile[j].Student_Last_Name = profile[j+1].Student_Last_Name;
	    profile[j+1].Student_Last_Name = last;

	    first = profile[j].Student_First_Name;
	    profile[j].Student_First_Name = profile[j+1].Student_First_Name;
	    profile[j+1].Student_First_Name = first;

	    id = profile[j].ID_Number;
	    profile[j].ID_Number = profile[j+1].ID_Number;
	    profile[j+1].ID_Number = id;

	    major = profile[j].Major;
	    profile[j].Major = profile[j+1].Major;
	    profile[j+1].Major = major;
	 }
      }
   }
}
void sort_id(student* profile, int num){
   string last, first, major;
   int id;
   for (int i = 0; i < num; i++){
      for (int j = 0; j < num; j++){
	 if (profile[i].ID_Number < profile[j].ID_Number){

	    last = profile[i].Student_Last_Name;
       	    profile[i].Student_Last_Name = profile[j].Student_Last_Name;
            profile[j].Student_Last_Name = last;
        
            first = profile[i].Student_First_Name;
            profile[i].Student_First_Name = profile[j].Student_First_Name;
            profile[j].Student_First_Name = first;
      
            id = profile[i].ID_Number;
            profile[i].ID_Number = profile[j].ID_Number;
            profile[j].ID_Number = id;
        
            major = profile[i].Major;
            profile[i].Major = profile[j].Major;
            profile[j].Major = major;
	 }
      }
   }
}
void print(student* profile, int num, fstream& out){
   for (int x = 0; x < num; x++){
   	out << profile[x].ID_Number;
   	out << profile[x].Student_First_Name;
   	out << profile[x].Student_Last_Name;
   	out << profile[x].Major << endl;
   }
}
void delete_student_db_info(student * profile){
   delete[] profile;
}
