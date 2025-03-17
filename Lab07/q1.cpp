#include <iostream>
#include <string>
using namespace std;

class Account {
protected:
    string accountNumber;
    double balance;
    string accountHolderName;
    string accountType;
    string* transactionHistory; 
    int transactionCount;

    void addTransaction(const string& transaction) {
        string* newTransactionHistory = new string[transactionCount + 1];
        for (int i = 0; i < transactionCount; ++i) {
            newTransactionHistory[i] = transactionHistory[i];
        }
        newTransactionHistory[transactionCount] = transaction;
        transactionCount++;
        delete[] transactionHistory; 
        transactionHistory = newTransactionHistory; 
    }

public:
    Account(string accNumber, double bal, string holderName, string accType = "")
        : accountNumber(accNumber), balance(bal), accountHolderName(holderName), accountType(accType), transactionCount(0), transactionHistory(nullptr) {}

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            addTransaction("Deposited " + to_string(amount));
            cout << amount << " deposited successfully." << endl;
        } else {
            cout << "Invalid deposit amount." << endl;
        }
    }

    virtual void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            addTransaction("Withdraw: " + to_string(amount));
            cout << amount << " withdrawn successfully." << endl;
        } else {
            cout << "Insufficient funds" << endl;
        }
    }

    virtual void calculateInterest() {}

    void printStatement() const {
        cout << "Statement for Account " << accountNumber << ":" << endl;
        for (int i = 0; i < transactionCount; ++i) {
            cout << transactionHistory[i] << endl;
        }
        cout << "Current Balance: " << balance << endl;
    }

    void getAccountInfo() const {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder: " << accountHolderName << endl;
        cout << "Account Type: " << (accountType.empty() ? "Generic" : accountType) << endl;
        cout << "Current Balance: $" << balance << endl;
    }

    ~Account() {
        delete[] transactionHistory; 
    }
};

class SavingsAccount : public Account {
private:
    double interestRate;
    double minimumBalance;

public:
    SavingsAccount(string accNumber, double bal, string holderName, double intRate, double minBal)
        : Account(accNumber, bal, holderName, "Savings"), interestRate(intRate), minimumBalance(minBal) {}

    void calculateInterest() override {
        double interest = balance * interestRate / 100;
        balance += interest;
        addTransaction("Interest added: " + to_string(interest));
        cout << "Interest calculated and added: " << interest << endl;
    }

    void withdraw(double amount) override {
        if (balance - amount >= minimumBalance) {
            Account::withdraw(amount);
        } else {
            cout << "Withdrawal denied. Minimum balance requirement not met." << endl;
        }
    }
};

class FixedDepositAccount : public Account {
private:
    string maturityDate;
    double fixedInterestRate;

public:
    FixedDepositAccount(string accNumber, double bal, string holderName, string matDate, double fixedIntRate)
        : Account(accNumber, bal, holderName, "Fixed Deposit"), maturityDate(matDate), fixedInterestRate(fixedIntRate) {}

    void calculateInterest() override {
        double interest = balance * fixedInterestRate / 100;
        balance += interest;
        addTransaction("Fixed interest added: " + to_string(interest));
        cout << "Fixed interest calculated and added: " << interest << endl;
    }

    void withdraw(double amount) override {
        cout << "Withdrawal denied. Fixed Deposit account cannot withdraw before maturity date: " << maturityDate << endl;
    }
};

class CheckingAccount : public Account {
public:
    CheckingAccount(string accNumber, double bal, string holderName)
        : Account(accNumber, bal, holderName, "Checking") {}

    void withdraw(double amount) override {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            addTransaction("Withdraw: " + to_string(amount));
            cout << amount << " withdrawn successfully." << endl;
        } else {
            cout << "Insufficient funds" << endl;
        }
    }
};

int main() {
    SavingsAccount savings("123456", 1000, "Fatima", 5.0, 500);
    savings.deposit(500);
    savings.calculateInterest();
    savings.withdraw(200);
    savings.printStatement();
    cout<< endl;

    FixedDepositAccount fixedDeposit("654321", 5000, "Percy", "2025-12-31", 7.5);
    fixedDeposit.calculateInterest();
    fixedDeposit.withdraw(1000);
    fixedDeposit.printStatement();
    cout<< endl;

    CheckingAccount checking("987654", 2000, "Ali Sethi");
    checking.withdraw(500);
    checking.printStatement();
}
