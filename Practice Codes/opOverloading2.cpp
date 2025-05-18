#include<iostream>
using namespace std;

class Complex {
public:
    int real, imag;

    Complex(int r = 0, int i = 0) {
        real = r;
        imag = i;
    }

    Complex operator + (const Complex& obj) {
        Complex temp;
        temp.real = real + obj.real;
        temp.imag = imag + obj.imag;
        return temp;
    }

    Complex operator - (const Complex& obj) {
        Complex temp;
        temp.real = real - obj.real;
        temp.imag = imag - obj.imag;
        return temp;
    }

    Complex operator * (const Complex& obj) {
        Complex temp;
        temp.real = (real * obj.real) - (imag * obj.imag);
        temp.imag = (real * obj.imag) + (imag * obj.real);
        return temp;
    }

    bool operator == (const Complex& obj) {
        return (real == obj.real && imag == obj.imag);
    }

    // Overloading Pre-increment ++c
    Complex operator ++ () {
        ++real;
        ++imag;
        return *this;
    }

    // Overloading Post-increment c++
    Complex operator ++ (int) {
        Complex temp = *this;
        real++;
        imag++;
        return temp;
    }

    friend ostream& operator << (ostream& out, const Complex& c);
    friend istream& operator >> (istream& in, Complex& c);
};

ostream& operator << (ostream& out, const Complex& c) {
    out << c.real << " + i" << c.imag;
    return out;
}

istream& operator >> (istream& in, Complex& c) {
    cout << "Enter real part: ";
    in >> c.real;
    cout << "Enter imaginary part: ";
    in >> c.imag;
    return in;
}

int main() {
    Complex c1, c2, c3;

    cin >> c1; // Overloading >> 
    cin >> c2;

    c3 = c1 + c2; // Overloading +
    cout << "Addition: " << c3 << endl;

    c3 = c1 - c2; // Overloading -
    cout << "Subtraction: " << c3 << endl;

    c3 = c1 * c2; // Overloading *
    cout << "Multiplication: " << c3 << endl;

    if (c1 == c2) // Overloading ==
        cout << "Both are equal!" << endl;
    else
        cout << "Both are not equal!" << endl;

    ++c1;  // Overloading Pre-increment ++c
    cout << "After Pre-increment: " << c1 << endl;

    c1++; // Overloading Post-increment c++
    cout << "After Post-increment: " << c1 << endl;
}