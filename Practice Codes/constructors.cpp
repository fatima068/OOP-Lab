#include <iostream>
using namespace std;

class Parent {
    public:
    Parent() {
        cout << "parent class constructor" << endl;
    }

    ~Parent(){
        cout << "parent class destructor" << endl;
    }
};

class Child: public Parent {
    public:
    Child() : Parent() {
        cout << "child class constructor" << endl;
    }
    ~Child() {
        cout << "child class destructor"<< endl;
    }
};

int main () {
    cout << endl << "creating child object:" << endl;
    Child c1;

    cout << endl << "Creating parent obj:" << endl;
    Parent p1;

    cout << endl << "ending program now:" << endl;
}