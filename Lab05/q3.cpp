/*Create a class called ValidateString. The purpose of this class will be check if the given characters in a string are alphabet only. Numbers and symbols will mean that the string is invalid. By using a parameterized constructor, create multiple objects for your class that accept different strings. Create a constant function that checks whether the string variable is valid or not. 
What happens if you do not make your function constant? Add a comment right above your function explaining why we make a function constant.*/

#include <iostream>
#include <string>
using namespace std;

class ValidateString {
private:
    string str;

public:
    ValidateString(const string& s) : str(s) {}

    // Function is constant so the sata stored in string cannot be changed during the execution of the program
    bool isValid() const {
        int length = str.length();
        for (int i=0; i<length; i++) {
            char ch = str.at(i);
            if (!((ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122))) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    ValidateString str1("fatima");
    ValidateString str2("5april");
    ValidateString str3("ello;)");

    if (str1.isValid()) {
        cout << "str1 is valid" << endl;
    } else {
        cout << "str1 is invalid" << endl;
    }

    if (str2.isValid()) {
        cout << "str2 is valid" << endl;
    } else {
        cout << "str2 is invalid" << endl;
    }

    if (str3.isValid()) {
        cout << "str3 is valid" << endl;
    } else {
        cout << "str3 is invalid" << endl;
    }
}