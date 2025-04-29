#include <iostream>
using namespace std;

class InvalidValueExcrption : public std::exception {
    public:
    const char* what() const noexcept override {
        return "Error: Invalid Value Exception - Age cannot be negative or exceed 120";
    }
};

void validateAge(int age) {
    if (age < 0 || age > 120){
        throw InvalidValueExcrption();
    }
}

int main() {
    int age;
    cout << "enter age: ";
    cin >> age;
    try {
        validateAge(age);
        cout << "age is: " << age;
    }
    catch(const InvalidValueExcrption& e) {
        cerr << e.what() << endl;
    }
}
