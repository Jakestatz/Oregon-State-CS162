#include <iostream>
#include "student_db.h"
#include <string.h>
#include <cstdlib>

using namespace std;


student* create_student_db(int num){
   student* table = new student[num];
   return table;
}
void get_student_db_info(student * table, int num, fstream &f); {
   

}
void delete_student_db_info(student *);
