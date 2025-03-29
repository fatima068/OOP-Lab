#include <iostream>
#include <string>
using namespace std;

class BankAccount{
    protected:
    string accountNumber;
    double balance;
    
    public:
    BankAccount(string accountNumber, double balance) : accountNumber(accountNumber), balance(balance) {}

    virtual double calculateInterest() {
        return 0.0;
    }

    virtual void deposit(double amount, string type) {
        balance += amount;
    }

    virtual void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            cout << "withdrawal successful" << endl;
        }
        else {
            cout << "insufficient balance" << endl;
        }
    }

    double operator+(const BankAccount& other) {
        return balance + other.balance;
    }

    double operator-(const BankAccount& other) {
        return balance - other.balance;
    }

    double operator*(double rate) const {
        return this->balance * rate;
    }

    double operator/(int numberOfInstallments) {
        return balance / numberOfInstallments;
    }

    void displayBalance() const {
        cout << "account number: " << accountNumber << " balance: $" << balance << endl;
    }

    virtual ~BankAccount() {}
};
    
class SavingsAccount : public BankAccount {
    public:
    SavingsAccount(string accountNumber, double balance) : BankAccount(accountNumber, balance) {}

    double calculateInterest() override {
        return balance * 0.05;
    }

    void deposit (double amount, string type) {
        if (type == "cash") {
            balance += amount;
            cout << "deposit via cash to savings account successful" << endl;
        }
        else if (type == "check") {
            balance += amount;
            cout << "deposit via check to savings account successful" << endl;
        }
        else if (type == "online transfer") {
            balance += amount;
            cout << "deposit via online transfer to savings account successful" << endl;
        }
        else {
            cout << "insufficient balance or invalid deposit type" << endl;
        }
    }

    void withdraw(double amount) override {
        if (balance >= amount && balance >= 500) {
            balance -= amount;
            cout << "withdrawal successful" << endl;
        }
        else {
            cout << "insufficient balance" << endl;
        }
    }
};

class CurrentAccount : public BankAccount {
    public:
    CurrentAccount(string accountNumber, double balance) : BankAccount(accountNumber, balance) {}

    double calculateInterest() override {
        return 0.0;
    }
    
    void deposit (double amount, string type) {
        if (type == "cash") {
            balance += amount;
            cout << "deposit via cash to current account successful" << endl;
        }
        else if (type == "check") {
            balance += amount;
            cout << "deposit via check to current account successful" << endl;
        }
        else if (type == "online transfer") {
            balance += amount;
            cout << "deposit via online transfer to current account successful" << endl;
        }
        else {
            cout << "insufficient balance or invalid deposit type" << endl;
        }
    }

    void withdraw(double amount) override {
        if ((balance - amount) >= -1000.0) {
            balance -= amount;
            cout << "Withdrew $" << amount << " from current account." << endl;
        }
        else {
            cout << "overdraft limit is $1000." << endl;
        }
    }
};

int main() {
    SavingsAccount* savings = new SavingsAccount("SAV001", 1000.0);
    CurrentAccount* current = new CurrentAccount("CUR001", 2000.0);
    
    cout << "\nInitial Balances:" << endl;
    savings->displayBalance();
    current->displayBalance();
    
    cout << "\nDeposit Operations:" << endl;
    savings->deposit(200.0, "cash");
    savings->deposit(300.0, "check");
    savings->deposit(150.0, "online transfer");
    
    current->deposit(500.0, "cash");
    current->deposit(600.0, "check");
    current->deposit(250.0, "online transfer");
    
    cout << "\nWithdrawal Operations:" << endl;
    savings->withdraw(800.0);  
    savings->withdraw(400.0);  
    
    current->withdraw(3000.0);
    current->withdraw(1.0);    
    
    cout << "\nBalances After Transactions:" << endl;
    savings->displayBalance();
    current->displayBalance();
    
    cout << "\nOperator Overloading Demonstrations:" << endl;
    double total = *savings + *current;
    cout << "Combined balance of both accounts: $" << total << endl;
    
    double difference = *current - *savings;
    cout << "Difference between current and savings: $" << difference << endl;
    
    double interest = *savings * 0.05;
    cout << "Interest on savings account: $" << interest << endl;
    
    try {
        double installment = *current / 4;
        cout << "Current account balance split into 4 installments: $" << installment << " each" << endl;
    } 
    catch (const invalid_argument& e) {
        cout << "Error: " << e.what() << endl;
    }
    
    cout << "\nFinal Balances with Interest:" << endl;
    cout << "Savings account interest: $" << savings->calculateInterest() << endl;
    cout << "Current account interest: $" << current->calculateInterest() << endl;
    savings->displayBalance();
    current->displayBalance();

    delete savings;
    delete current;
}
