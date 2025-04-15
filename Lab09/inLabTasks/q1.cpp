#include <iostream>
using namespace std;

class Vehicle {
    protected:
    string model;
    double rate;

    public:
    Vehicle() : model(""), rate(0.0) {}

    Vehicle(string model, double rate) : model(model), rate(rate) {}

    virtual double getDailyRate() = 0;
    virtual void displayDetails() = 0;
};

class Car : public Vehicle {
    public:
    Car() : Vehicle() {}

    Car(string model, double rate) : Vehicle(model, rate) {}

    double getDailyRate() override {
        return rate;
    }

    void displayDetails() override {
        cout << "model: " << model << ", rate: " << rate << endl;
    }
};

class Bike : public Vehicle {
    public:
    Bike() : Vehicle() {}

    Bike(string model, double rate) : Vehicle(model, rate) {}

    double getDailyRate() override {
        return rate;
    }

    void displayDetails() override {
        cout << "model: " << model << ", rate: " << rate << endl;
    }
};

int main() {
    Vehicle* vehicles[2];
    
    vehicles[0] = new Car("mehran", 45.99);
    vehicles[1] = new Bike("bmw", 25.50);

    for (int i = 0; i < 2; i++) {
        vehicles[i]->displayDetails();
        cout << "daily rate: " << vehicles[i]->getDailyRate() << endl << endl;
    }

    delete vehicles[0];
    delete vehicles[1];
}
