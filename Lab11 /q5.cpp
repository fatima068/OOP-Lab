#include <iostream>
#include <string>
#include <exception>
using namespace std; 

class InsufficientFundsException : public exception {
    public:
    virtual const char* what() const noexcept override {
        return "insufficient funds exception";
    }
};

template <typename T>
class BankAccount {
    private: 
    T balance;

    public:
    BankAccount(T balance) : balance(balance) {
        cout << "bank acc created with balance: " << balance << endl;
    }

    void withdraw(T amount) {
        if (amount > balance) {
            cout << "defecit: " << amount - balance << endl;
            throw InsufficientFundsException();
        }
        cout << "new balance: " << balance - amount << endl;
    }
};

int main () {
    BankAccount b1(500.50);
    int withdrawAmount;
    try {
        cout << "enter amount to withdraw: ";
        cin >> withdrawAmount;
        b1.withdraw(withdrawAmount);
    }
    catch (const exception& e) {
        cerr << "error: " << e.what() << endl;
    }
}
