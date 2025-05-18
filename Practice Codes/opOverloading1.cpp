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
    int getReal() const { return real; }
    int getImag() const { return imag; }
    void setReal(int r) { real = r; }
    void setImag(int i) { imag = i; }
};

// Overloading << operator (Outside the class)
ostream& operator << (ostream& out, const Complex& c) {
    out << c.getReal() << " + i" << c.getImag();
    return out;
}

// Overloading >> operator (Outside the class)
istream& operator >> (istream& in, Complex& c) {
    int r, i;
    cout << "Enter real part: ";
    in >> r;
    cout << "Enter imaginary part: ";
    in >> i;
    c.setReal(r);
    c.setImag(i);
    return in;
}

int main() {
    Complex c1;

    cin >> c1;   // Works perfectly
    cout << c1;  // Works perfectly
}