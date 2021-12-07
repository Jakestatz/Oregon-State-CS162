#include "./vector.hpp"
#include <vector>
#include <iostream>

//We do not want to include either statement. We wouldn't be able to compare our vector template to the Standard
//using namespace std;
//using std::vector;
using std::cout;
using std::endl;

int main (){
   vector<int> v;   //Our vector class
   std::vector<int> stdv; //Standard vector

   //Compare operation of our vector to std
   v.push_back(23);
   stdv.push_back(23);
   vector<int> v2(v);

   cout << "Our vector size: " << v.size() << endl;
   cout << "STL vector size: " << stdv.size() << endl;
   cout << "Copied vector size: " << v2.size() << endl;

   v.push_back(20);
   v.push_back(18);
   v2=v;

   cout << "Vector 1: ";
   v.print();
   cout << "Copied vector: ";
   v2.print();

   cout << "Copied vector[1]: " << v2[1] << endl;;

   return 0;
}
