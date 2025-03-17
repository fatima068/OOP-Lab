#include <iostream>
#include <string>
#include <cmath>
using namespace std;

double pi = 3.14159;

class Shape {
protected:
    string position;
    string color;
    int borderThickness;

public:
    Shape(string pos, string col, int border = 0) : position(pos), color(col), borderThickness(border) {}

    virtual void draw() {
        cout << "Drawing a shape at position " << position 
             << " with color " << color 
             << " and border thickness " << borderThickness << endl;
    }

    virtual double calculateArea() {} 
    virtual double calculatePerimeter() {}
    virtual ~Shape() {}
};

class Circle : public Shape {
private:
    double radius;
    string centerPosition;

public:
    Circle(string pos, string col, double r, int border = 0) : Shape(pos, col, border), radius(r), centerPosition(pos) {}

    void draw() override {
        cout << "Drawing a circle at center position " << centerPosition 
             << " with color " << color 
             << ", border thickness " << borderThickness 
             << ", and radius " << radius << endl;
    }

    double calculateArea() override {
        return pi * radius * radius;
    }

    double calculatePerimeter() override {
        return 2 * pi * radius;
    }
};

class Rectangle : public Shape {
private:
    double width;
    double height;
    string topLeftPosition;

public:
    Rectangle(string pos, string col, double w, double h, int border = 0) : Shape(pos, col, border), width(w), height(h), topLeftPosition(pos) {}

    void draw() override {
        cout << "Drawing a rectangle at top-left position " << topLeftPosition 
             << " with color " << color 
             << ", border thickness " << borderThickness 
             << ", width " << width << ", and height " << height << endl;
    }

    double calculateArea() override {
        return width * height;
    }

    double calculatePerimeter() override {
        return  (2 * width) + (2 * height);
    }
};

class Triangle : public Shape {
private:
    double side1, side2, side3;

public:
    Triangle(string pos, string col, double s1, double s2, double s3, int border = 0) : Shape(pos, col, border), side1(s1), side2(s2), side3(s3) {}

    void draw() override {
        cout << "Drawing a triangle at position " << position 
             << " with color " << color 
             << ", border thickness " << borderThickness 
             << ", and sides " << side1 << ", " << side2 << ", " << side3 << endl;
    }

    double calculateArea() override {
        double s = (side1 + side2 + side3) / 2;
        return sqrt(s * (s - side1) * (s - side2) * (s - side3));
    }

    double calculatePerimeter() override {
        return side1 + side2 + side3;
    }
};

class Polygon : public Shape {
private:
    int numSides;
    double* sides; 

public:
    Polygon(string pos, string col, int numSides, double* sides, int border = 0) : Shape(pos, col, border), numSides(numSides) {
        this->sides = new double[numSides];
        for (int i = 0; i < numSides; i++) {
            this->sides[i] = sides[i];
        }
    }

    void draw() override {
        cout << "Drawing a polygon at position " << position 
             << " with color " << color 
             << ", border thickness " << borderThickness 
             << ", and " << numSides << " sides of lengths: ";
        for (int i = 0; i < numSides; i++) {
            cout << sides[i] << " ";
        }
        cout << endl;
    }

    double calculateArea() override {
        double perimeter = calculatePerimeter();
        double apothem = sides[0] / (2 * tan(pi / numSides));
        return (perimeter * apothem) / 2;
    }

    double calculatePerimeter() override {
        double perimeter = 0;
        for (int i = 0; i < numSides; i++) {
            perimeter += sides[i];
        }
        return perimeter;
    }

    ~Polygon() {
        delete[] sides; 
    }
};

int main() {
    Circle circle("100,100", "Red", 10.0);
    Rectangle rectangle("200,200", "Blue", 15.0, 10.0);
    Triangle triangle("300,300", "Green", 3.0, 4.0, 5.0);

    double polygonSides[] = {5.0, 5.0, 5.0, 5.0}; 
    Polygon polygon("400,400", "Yellow", 4, polygonSides);

    Shape* shapes[] = {&circle, &rectangle, &triangle, &polygon};

    for (int i = 0; i < 4; i++) {
        shapes[i]->draw();
        cout << "Area: " << shapes[i]->calculateArea() << endl;
        cout << "Perimeter: " << shapes[i]->calculatePerimeter() << endl;
        cout << endl;
    }
}
