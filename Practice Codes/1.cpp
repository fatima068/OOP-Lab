#include <iostream>
using namespace std;

int main() {
    int intValue = 42;
    double doubleValue = 3.14;
    char charValue = 'A';

    // Void pointer can point to any type
    void* ptr;

    // Point to an integer
    ptr = &intValue; // value/address assign hojayega, but dereference karte waqt masla ayega 
    cout << "Integer value: " << *(static_cast<int*>(ptr)) << endl; // thats why we do static cast of void pointer when accessing it 

    // Point to a double
    ptr = &doubleValue;
    cout << "Double value: " << *(static_cast<double*>(ptr)) << endl;

    // Point to a char
    ptr = &charValue;
    cout << "Char value: " << *(static_cast<char*>(ptr)) << endl;
}