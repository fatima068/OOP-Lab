#include <iostream>
using namespace std;

class Activity {
    public:
    Activity() {}

    virtual double calculateCaloriesBurned() = 0;
};

class Running : public Activity {
    double distance, time;

    public:
    Running() : distance(0.0), time(0.0), Activity() {}

    Running(double distance, double time) : distance(distance), time(time), Activity() {}

    double calculateCaloriesBurned() override {
        return (3 * (distance/time)); // 3 calories burned for every km/min
    }
};

class Cycling : public Activity {
    double speed, time;

    public:
    Cycling() : speed(0.0), time(0.0), Activity() {}

    Cycling(double speed, double time) : speed(speed), time(time), Activity() {}

    double calculateCaloriesBurned() override {
        return (3 * speed);
    }
};

int main () {
    Running r1(55, 10);
    Cycling c1(30, 45);

    cout << "running calories burned: " << r1.calculateCaloriesBurned() << endl;
    cout << "cycling calories burned: " << c1.calculateCaloriesBurned() << endl;
}
