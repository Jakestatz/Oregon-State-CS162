#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int get_pos_int(int &, int);
bool prime(int num);
void swap(int&, int&);

int main(){
  int a;
  get_pos_int(a, 25);
  vector<int> copy;
  vector<int> oned;
  srand(time(0));
	
  for (int i=0; i < a; ++i)
     oned.push_back(rand() % 101);
  for (int i=0; i < a; ++i)
     cout << oned[i] << " ";
  cout << endl;
  for (int i=0; i < a; ++i){
     copy.push_back(oned[i]);
  }
   int index;
   for (int i=0; i < a-1; ++i){
      index = i;
      for (int j=i+1; j < a; ++j){
	 if (copy[j] < copy[index]) index = j;
      }
      swap(copy[index], copy[i]);
   }
   for (auto a : copy)
      cout << a << " ";
   cout << " " << endl;
   for (auto i : oned){
      if (prime(i)==true) cout << i << " ";
   }
   cout << " " << endl;
   return 0;
}

int get_pos_int(int &a, int upper){
  int repeat = 1;
  cout << "Enter a number: ";
  cin >> a;
  while (repeat==1){
     if (a <= upper && a > 0) {
	repeat = 0;
	return a;
     } 
     else {
	cout << "Enter a number: ";
	cin >> a;
     }
  }
}

void swap(int &a, int &b){
   int temp = a;
   a = b;
   b = temp;
}

bool prime(int num){
   if (num <= 1) {
      return false;
   } 
   else {
      for (int i = 2; i < num; i++){
	 if (num % i == 0){
	    return false;
	 }
      }
   }
  return true;
}
