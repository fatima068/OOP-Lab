#include <iostream>
#include <string>
using namespace std;

class Account {
    protected:
    string accountNumber;
    string accountHolderName;
    double balance;

    public:
    Account() : accountNumber(""), accountHolderName(""), balance(0) {}

    Account(string accountNumber, string accountHolderName, double balance) : accountNumber(accountNumber), accountHolderName(accountHolderName), balance(balance) {}

    virtual void deposit(double amount) {
        balance += amount;
    }

    virtual void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
        }
        else {
            cout << "insufficient balance" << endl;
        }
    }

    friend ostream& operator<< (ostream& output, const Account& b1) {
        output << "Account Number: " << b1.accountNumber << ", Account Holder Name: " << b1.accountHolderName << ", Balance: " << b1.balance << endl << endl;
        return output;
    } 

    Account operator+ (const Account& a1) {
        Account temp;
        temp.accountNumber = a1.accountNumber + " + " + accountNumber;
        temp.balance = a1.balance + balance;
        temp.accountHolderName = a1.accountHolderName + " + " + accountHolderName;
        return temp;
    } 

    Account& operator=(double amount) {
        if (amount > 0 && this->balance >= amount) {
            this->balance -= amount;
            cout << "Transferred $" << amount << " from account " << this->accountNumber << endl;
        }
        else {
            cout << " insufficient balance " << endl;
        }
        return *this;
    }

    Account& operator==(double amount) {
        this->balance += amount;
        return *this;
    }

    bool operator> (const Account& a1) {
        if (balance > a1.balance) {
            return true;
        }
        else {
            return false;
        }
    }
};

int main() {
    Account a1("a01", "shafique rehman", 5000);
    Account a2("a02", "talha", 3000);

    cout << "initial balance :\n";
    cout << a1;
    cout << a2;

    cout << "total balance(after addition) :\n";
    Account a3 = a1 + a2;
    cout << a3;

    cout << "after transfer :";
    a1 = 2000;
    a2 == 2000;
    
    cout << a1;
    cout << a2;

    if (a1 > a2) {
        cout << "shafique has more balance than talha" << endl;
    }
    else {
        cout << "shafique has less balance than talha" << endl;
    }

    cout << endl << "final account details :" << endl;
    cout << a1;
    cout << a2;
}
