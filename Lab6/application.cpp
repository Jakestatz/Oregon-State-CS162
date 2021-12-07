#include <iostream>
#include "rectangle.h"
#include "circle.h"
#include "square.h"
#include "shape.h"

using namespace std;

int main(){
   Rectangle rectangle(7, 6, "rec1", "blue");
   cout << "Rectangle";
   cout << "Name: " << rectangle.Name() << endl;
   cout << "Color: " << rectangle.Color() << endl;
   cout << "Height: " << rectangle.Height() << endl;
   cout << "Width: " << rectangle.Width() << endl;
   cout << "Area: " << rectangle.Area() << "\n" << endl;
   
   rectangle.Setname("rec2");
   rectangle.Setcolor("green");
   rectangle.Setheight(3);
   rectangle.Setwidth(4);

   cout << "Rectangle";
   cout << "Name: " << rectangle.Name() << endl;
   cout << "Color: " << rectangle.Color() << endl;
   cout << "Height: " << rectangle.Height() << endl;
   cout << "Width: " << rectangle.Width() << endl;
   cout << "Area: " << rectangle.Area() << "\n" << endl;
   
   Circle circle(7, "circ1", "red");
   cout << "Circle";
   cout << "Name: " << circle.Name() << endl;
   cout << "Color: " << circle.Color() << endl;
   cout << "Radius: " << circle.Radius() << endl;
   cout << "Area: " << circle.Area(circle.Radius()) << "\n" << endl;
   
   circle.Setname("circ2");
   circle.Setcolor("purple");
   circle.Setradius(3);

   cout << "Circle";
   cout << "Name: " << circle.Name() << endl;
   cout << "Color: " << circle.Color() << endl;
   cout << "Radius: " << circle.Radius() << endl;
   cout << "Area: " << circle.Area(circle.Radius()) << "\n" << endl;
   
   Square square(2,"sq1","yellow");
   cout << "Square";
   cout << "Name: " << square.Name() << endl;
   cout << "Color: " << square.Color() << endl;
   cout << "Height: " << square.Height() << endl;
   cout << "Width: " << square.Width() << endl;
   cout << "Area: " << square.Area() << "\n" << endl;
   
   square.Setname("sq2");
   square.Setcolor("aqua");
   square.Setdimentions(6);
   
   cout << "Square";
   cout << "Name: " << square.Name() << endl;
   cout << "Color: " << square.Color() << endl;
   cout << "Height: " << square.Height() << endl;
   cout << "Width: " << square.Width() << endl;
   cout << "Area: " << square.Area() << "\n" << endl;

   if (rectangle < square){
      cout << "The first rectangle is larger than the first" << endl;
   }
   else{
      cout << "The second rectangle is larger that the first" <<endl;
   }
return 0;
}
