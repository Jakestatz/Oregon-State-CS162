#include "mult_div.h"
#include <iostream>
#include <cstdlib>

using namespace std;

bool is_valid_dimensions(char *m, char *n){
   int rows=atoi(m);
      int cols=atoi(n);
         while (rows<=0){
	       cout << "How many rows: ";
	             cin >> rows;
		        }
	    while (cols<=0){
	          cout << "How many columns: ";
		        cin >> cols;
			   }
	       return true;
}

mult_div_values** create_table(int m, int n){
   mult_div_values** table = new mult_div_values*[m];
   for (int x=0; x<n; x++){
         table[x] = new mult_div_values[n];	
      }
   return table;
}
void set_mult_values(mult_div_values **table, int m, int n){
   for(int i = 1; i <= m; i++){
      	for (int j= 1; j <= n; j++){
			table[i-1][j-1].mult = i*j;
		}
      }
}

void set_div_values(mult_div_values **table, int m, int n){
    for(int i = 1; i <= m; i++){
           for (int j = 1; j <= n; j++){
	   	  table[i-1][j-1].div =(float)i / (float)j;
		         }
	       }
}

void print_mult_table(mult_div_values **table, int m, int n){
   cout << "Multiplcation Table" << endl;
      for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
	    	 cout << table[i][j].mult << "\t";
		       }
	          cout << endl;
		     }
}

void print_div_table(mult_div_values **table, int m, int n){
   cout << "Division Table" << endl;
      for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
	             cout << table[i][j].div << "\t";
		           }
	          cout << endl;
		     }
}
void delete_table(mult_div_values **table, int m, int n){
   for (int i = 0; i < m; i++){
         delete[] table[i];
      }
   delete[] table;
}
