#include <iostream>
#include <cstdlib>
#include <string>
#include "hand.h"

using namespace std;

int main(){
   Hand h1;
   Hand h2(h1);
   Hand h3;
   h3 = h2;
}
