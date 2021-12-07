#include <iostream>
#include <cstdlib>
#include "mult_div.h"

using namespace std;

int main(int argc, char *argv[]){
   int rows=0, cols=0;
   rows=atoi(argv[1]);
   cols=atoi(argv[2]);
   mult_div_values **table = create_table(rows, cols);
   set_mult_values(table, rows, cols);
   set_div_values(table, rows, cols);
   print_mult_table(table, rows, cols);
   print_div_table(table, rows, cols);
   delete_table(table, rows, cols);
}
