#include <stdlib.h>
#include <stdexcept>
#include <iostream>

using std::out_of_range;

template <class T>

class vector {
   private:
      T *v;
      int s, c;
   public:
      vector(){
	 s=0;
	 v=NULL;
	 c=0;
      }

      ~vector(){
	 delete [] v;
      }

      vector(vector<T> &other){
	 s = other.size();
	 c = s;
	 v = new T[s];
	 for (int i=0; i < s; ++i) v[i] = other.at(i);
      }

      int size() {
	 return s;
      }

      void push_back(T ele) {
	 T *temp;
         temp = new T[++s];
         for(int i=0; i<s-1; i++)
	    temp[i]=v[i];
	 delete [] v;
	 v=temp;
	 v[s-1]=ele;
      }
      
      void operator=(vector<T> &other){
	 delete [] v;
	 v = new T[other.size()];
	 for (int i = 0; i < other.size(); ++i) v[i] = other.at(i);
	 s = other.size();
      }
	  
      void print(){
	 for (int i = 0; i < s; ++i) std::cout << at(i) << ", ";
	 std::cout << std::endl;
      }
		
      T at(int a){
	 if (a >= 0 && a < s) return v[a];
	 throw out_of_range("Out of range");
      }
		      
      T operator[](int a){
	 return v[a];
      }
      
      void resize(int a){
	 c = a;
	 T *temp;
	 temp = new T[s];
	 for (int i=1; i <= s; ++i) temp[i] = v[i];
	 delete [] v;
	 s = c;
	 v = new T[s];
	 for (int i=1; i <= s; ++i) v[i] = temp[i];					         
      }
};
