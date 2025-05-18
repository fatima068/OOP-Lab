#include <iostream>
using namespace std;
class MyClass {
    int id;
    
    public:
    MyClass (int x) {
        id=x;
        cout << "Object "<< id << " created" << endl;
    }

    ~MyClass() {
        cout << "object " << id << " destructed" << endl;
    }
};

void func() {
    MyClass ob3 (3);
    MyClass ob4 (4);
}

int main() {
    cout << "main starts here" << endl;
    MyClass ob2 (2);
    func();
    MyClass ob5 (5);
    cout << "main ends here" << endl;
}

MyClass ob1(1); // global variable always compiled first, even if it is written at the end like this 