#include<iostream>
using namespace std;

class Base {
public:
    virtual void show() {
        cout << "Base class function" << endl;
    }
};

class Derived : public Base {
public:
    void show() override {
        cout << "Derived class function" << endl;
    }
};

class ChildDerived : public Derived {
public:
    void show() override {
        cout << "Child Derived class function" << endl;
    }
};

int main() {
    Base* b; // Base class pointer
    
    ChildDerived c; // ChildDerived class object
    
    b = &c; // Assigning address of ChildDerived to Base pointer
    
    b->show(); // Calls ChildDerived function ✅

    // Calling Base class function
    b->Base::show();    // ✅ Base class function

    // Calling Derived class function
    c.Derived::show(); // ✅ Derived class function
}