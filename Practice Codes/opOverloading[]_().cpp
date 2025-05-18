#include<iostream>
using namespace std;

class Complex {
private:
    int real, imag;
public:
    Complex(int r = 0, int i = 0) {
        real = r;
        imag = i;
    }

    int operator [] (int index) {
        if (index == 0) return real;
        else if (index == 1) return imag;
        else {
            cout << "Invalid index!" << endl;
            return -1;
        }
    }

    void operator () (int r, int i) {
        real = r;
        imag = i;
    }

    friend ostream& operator << (ostream& out, const Complex& c);
};

ostream& operator << (ostream& out, const Complex& c) {
    out << c.real << " + i" << c.imag;
    return out;
}

int main() {
    Complex c1(3, 5);

    // Accessing using [] Operator
    cout << "Real Part: " << c1[0] << endl;  // Works fine
    cout << "Imaginary Part: " << c1[1] << endl;  // Works fine
    cout << "Invalid Index: " << c1[2] << endl;  // Invalid index

    // Calling object like function using () Operator
    c1(10, 20);  // Works fine
    cout << "After calling object as function: " << c1 << endl;
}