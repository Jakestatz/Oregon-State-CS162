#include <iostream>

struct student {
   int ID_Number;
   string Student_First_Name;
   string Student_Last_Name;
   string Major;
};
student* create_student_db(int ); 
void get_student_db_info(student *, int, fstream &); 
void delete_student_db_info(student *);
