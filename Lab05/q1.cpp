/*Create a class called Square with the following attributes:
• sideLength – float variable
• area – float variable
• allareas – static float variable
Create the following methods for your class:
• Constructors (default and parameterized (only takes sideLength as input))
• Function to calculate area, the calculated area should always be added to the allareas variable each time an area is calculated. (assume it’s called only once for each object)
• Getters and Setters for all variables
In your main functions create 3 Squares with different sideLength. Call the area method for each of those Square objects. After each time the area method is called, call that square’s getters for area and allareas to display the updated values.*/

#include <iostream>
using namespace std;

class Square {
    float sideLength;
    float area;
    static float allAreas;

    public:
    Square() {
        sideLength = 0.0;
        area = 0.0;
    }

   Square(float sideLength){
    this->sideLength = sideLength;
    area = 0.0;
   }

   float getSideLength() const {
        return sideLength;
    }

    float getArea() const {
        return area;
    }

    static float getAllAreas() {
        return allAreas;
    }

    void setSideLength(float length) {
        sideLength = length;
    }

    static void setAllAreas (float allareas) {
        Square:: allAreas = allareas;
    }

    void calculateArea() {
        area = sideLength * sideLength;
        allAreas += area;
    }
};

float Square:: allAreas = 0.0;

int main () {
    Square sq1(5.0);
    Square sq2(2.0);
    Square sq3(4.0);

    sq1.calculateArea();
    sq2.calculateArea();
    sq3.calculateArea();

    cout << "Square 1 - Side Length: " << sq1.getSideLength() << ", Area: " << sq1.getArea() << endl;

    cout << "Square 2 - Side Length: " << sq2.getSideLength() << ", Area: " << sq2.getArea() << endl;

    cout << "Square 3 - Side Length: " << sq3.getSideLength() << ", Area: " << sq3.getArea() << endl;
    cout << "Total Areas: " << Square::getAllAreas() << endl << endl;
}
