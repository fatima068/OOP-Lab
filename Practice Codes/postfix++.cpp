#include <iostream>
using namespace std;

class Postfix{
    int i;

    public:
    Postfix(): i(0) {}

    void operator ++(int) { 
        i++; 
    }
    
    void Display() { 
        cout << "i=" << i << endl; 
    }
};

int main(){
    Postfix obj;
    obj.Display();
    obj++;
    //you can also write obj.operator ++(4);
    obj.Display();
}