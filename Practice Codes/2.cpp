#include <iostream>
using namespace std;

// A generic function to print the value pointed to by a void pointer
void printValue(void* ptr, char type) {
    switch (type) {
        case 'i': // Integer
            cout << "Integer value: " << *(static_cast<int*>(ptr)) << endl;
            break;
        case 'd': // Double
            cout << "Double value: " << *(static_cast<double*>(ptr)) << endl;
            break;
        case 'c': // Char
            cout << "Char value: " << *(static_cast<char*>(ptr)) << endl;
            break;
        default:
            cout << "Unknown type!" << endl;
    }
}

int main() {
    int intValue = 42;
    double doubleValue = 3.14;
    char charValue = 'A';

    // Print values using the generic function
    printValue(&intValue, 'i');
    printValue(&doubleValue, 'd');
    printValue(&charValue, 'c');
}