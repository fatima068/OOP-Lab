#include <iostream>
#include <string>
#include <cmath>
#include <exception>
using namespace std;

class NegativeNumberException : public exception {
    public:
    virtual const char* what() const noexcept override {
        return "input must be non negative";
    }
};

class InvalidTypeException : public exception {
    public:
    virtual const char* what() const noexcept override {
        return "invalid data type";
    }
};

template <typename T>
void sqRoot(T num) {
    if (num < 0) {
        throw NegativeNumberException();
    }
    cout << "sqRoot is: " << pow(num, 0.5) << endl;
}

template<>
void sqRoot<string>(string num) {
    throw InvalidTypeException();
}

int main() {
    string a;
    int b;
    float c;

    try {
        cout << "enter positive integer to test with: ";
        cin >> b;
        sqRoot(b);
        cout << "enter negative integer to test with: ";
        cin >> b;
        sqRoot(b);
        cout << "enter float to test with: ";
        cin >> c;
        sqRoot(c);
        cout << "enter enter string to test with: ";
        cin >> a;
        sqRoot(a);
    }
    catch (const exception& e){
        cerr << "error: " << e.what() << endl;
    }
}
