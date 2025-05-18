#include <iostream>
#include <string>
#include <exception>
using namespace std;

class InvalidInputException : public exception {
public:
    const char* what() const noexcept override {
        return "non integer input";
    }
};

int main() {
    try {
        cout << "Enter an integer (or 'q' to quit): ";
        string input;
        cin >> input;
        if (input == "q" || input == "Q") {
            exit(0);
        }

        bool isNumber = true;
        for (char c : input) { // // Check if input is a valid integer
            if (!isdigit(c) && c != '-' && c != '+') {
                isNumber = false;
                break;
            }
        }

        if (!isNumber) { // if number is not integer we throw the exception we wrote
            throw InvalidInputException();
        }
        cout << "You entered a valid integer: " << input << endl;
    } 
    catch (const InvalidInputException& e) { // catch the exception that we throw on line 31
        cout << "ERROR: " << e.what() << endl; 
    }
    catch (...) {
        cout << "ERROR: Unknown exception occurred!" << endl;
    }
}