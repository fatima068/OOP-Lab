#include <iostream>
using namespace std;

class parent1 {
    public:
    parent1() {
        cout << "parent1 class constructor" << endl;
    }
    ~parent1(){
        cout << "parent1 class destructor" << endl;
    }
};
class parent2 {
    public:
    parent2() {
        cout << "parent2 class constructor" << endl;
    }
    ~parent2(){
        cout << "parent2 class destructor" << endl;
    }
};
class Child: public parent2, public parent1 { // parent 2 pehle inherit hua hai
    public:
    Child() : parent1() {
        cout << "child class constructor" << endl;
    }
    ~Child() {
        cout << "child class destructor"<< endl;
    }
};

int main () {
    cout << endl << "creating child object:" << endl;
    Child c1;
    cout << endl << "ending program now:" << endl;
} 

// #include <iostream>
// using namespace std;

// class parent1 {
//     public:
//     parent1() {
//         cout << "parent1 class constructor" << endl;
//     }
//     ~parent1(){
//         cout << "parent1 class destructor" << endl;
//     }
// };
// class parent2 {
//     public:
//     parent2() {
//         cout << "parent2 class constructor" << endl;
//     }
//     ~parent2(){
//         cout << "parent2 class destructor" << endl;
//     }
// };
// class Child: public parent1, public parent2 { // parent 1 pehle inherit hua hai
//     public:
//     Child() : parent1() {
//         cout << "child class constructor" << endl;
//     }
//     ~Child() {
//         cout << "child class destructor"<< endl;
//     }
// };

// int main () {
//     cout << endl << "creating child object:" << endl;
//     Child c1;
//     cout << endl << "ending program now:" << endl;
// } 