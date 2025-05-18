#include <iostream>
using namespace std;

// Function with default arguments
// Note: Default arguments must be rightmost
void displayNumbers(int a, int b = 20, int c = 30) {
    cout << "a = " << a << ", b = " << b << ", c = " << c << endl;
}

int main() {
    // Calling with all arguments provided
    displayNumbers(1, 2, 3);  // Output: a = 1, b = 2, c = 3
    
    // Calling with two arguments - 'c' uses default value
    displayNumbers(4, 5);     // Output: a = 4, b = 5, c = 30
    
    // Calling with one argument - 'b' and 'c' use default values
    displayNumbers(7);        // Output: a = 7, b = 20, c = 30
    
    // This would be invalid - can't skip arguments in the middle
    // displayNumbers(8, , 9); // Compilation error
}