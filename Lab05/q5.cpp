/*Keeping in mind our previous car example, write a class that represents a car, and use aggregation and composition to combine different components like engine, wheels, headlights and steering to create the car object.  

Hint: create the individual classes first before performing the composition. Remember that for aggregation, you will need pointers You’ll be needing constructors and setters to set these values in case of aggregation. Same hint applies to other questions.*/

#include <iostream>
using namespace std;

class Engine {
public:
    void start() {
        cout << "car engine started" << endl;
    }
};

class Wheels {
public:
    void rotate() {
        cout << "Wheels being rotated" << endl;
    }
};

class Headlights {
public:
    void turnOn() {
        cout << "headlights turned on" << endl;
    }

    void turnOff() {
        cout << "headlights turned off" << endl;
    }
};

class Steering {
public:
    void turnLeft() {
        cout << "turning car to left" << endl;
    }

    void turnRight() {
        cout << "turning car to right" << endl;
    }
};

class Car {
    private:
    Engine engine;
    Wheels wheels[4];       
    Headlights* headlights;
    Steering* steering;      
    
    public:
    Car(Headlights* hl, Steering* st) : headlights(hl), steering(st) {
        cout << "car object created" << endl;
    }
    
    void setHeadlights(Headlights* hl) {
        headlights = hl;
    }
    
    void setSteering(Steering* st) {
        steering = st;
    }
    
    void drive() {
        engine.start();
        for (int i = 0; i < 4; i++) {
            wheels[i].rotate();
        }
        headlights->turnOn();
        steering->turnLeft();
        steering->turnRight();
    }

    ~Car() {
        cout << "car object destroyed" << endl;
    }
};

int main() {
    Headlights hl;
    Steering s1;
    Car myCar(&hl, &s1);
    myCar.drive();
}