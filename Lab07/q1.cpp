#include <iostream>
#include <string>
using namespace std;

class BankAccount {
    protected:
    string accID;
    double accBalance;
    string accHolder;
    string accCategory;
    string* transactionLog;
    int logCount;

    void logTransaction(const string& transaction) {
        string* newLog = new string[logCount + 1];
        for (int i = 0; i < logCount; ++i) {
            newLog[i] = transactionLog[i];
        }
        newLog[logCount] = transaction;
        logCount++;
        delete[] transactionLog;
        transactionLog = newLog;
    }

    public:
    BankAccount(string id, double bal, string holder, string category = "") : accID(id), accBalance(bal), accHolder(holder), accCategory(category), logCount(0), transactionLog(nullptr) {}

    void addFunds(double amount) {
        if (amount > 0) {
            accBalance += amount;
            logTransaction("Added funds: " + to_string(amount));
            cout << amount << " added to account." << endl;
        } else {
            cout << "Invalid amount." << endl;
        }
    }

    virtual void removeFunds(double amount) {
        if (amount > 0 && amount <= accBalance) {
            accBalance -= amount;
            logTransaction("Removed funds: " + to_string(amount));
            cout << amount << " removed from account." << endl;
        } else {
            cout << "Cannot remove funds. Insufficient balance." << endl;
        }
    }

    virtual void computeInterest() {}

    void displayTransactions() const {
        cout << "Transaction history for Account " << accID << ":" << endl;
        for (int i = 0; i < logCount; ++i) {
            cout << transactionLog[i] << endl;
        }
        cout << "Remaining Balance: " << accBalance << endl;
    }

    void showAccountDetails() const {
        cout << "Account ID: " << accID << endl;
        cout << "Account Holder: " << accHolder << endl;
        cout << "Account Type: " << (accCategory.empty() ? "General" : accCategory) << endl;
        cout << "Current Balance: $" << accBalance << endl;
    }

    ~BankAccount() {
        delete[] transactionLog;
    }
};

class Savings : public BankAccount {
    private:
    double rate;
    double minBalance;

    public:
    Savings(string id, double bal, string holder, double r, double min) : BankAccount(id, bal, holder, "Savings"), rate(r), minBalance(min) {}

    void computeInterest() override {
        double interest = accBalance * rate / 100;
        accBalance += interest;
        logTransaction("Interest credited: " + to_string(interest));
        cout << "Interest added: " << interest << endl;
    }

    void removeFunds(double amount) override {
        if (accBalance - amount >= minBalance) {
            BankAccount::removeFunds(amount);
        } else {
            cout << "Cannot withdraw. Minimum balance must be maintained." << endl;
        }
    }
};

class FixedDeposit : public BankAccount {
    private:
    string endDate;
    double fixedRate;

    public:
    FixedDeposit(string id, double bal, string holder, string date, double rate) : BankAccount(id, bal, holder, "Fixed Deposit"), endDate(date), fixedRate(rate) {}

    void computeInterest() override {
        double interest = accBalance * fixedRate / 100;
        accBalance += interest;
        logTransaction("Fixed interest credited: " + to_string(interest));
        cout << "Fixed interest added: " << interest << endl;
    }

    void removeFunds(double amount) override {
        cout << "Cannot withdraw. Funds are locked until " << endDate << "." << endl;
    }
};

class Checking : public BankAccount {
    public:
    Checking(string id, double bal, string holder) : BankAccount(id, bal, holder, "Checking") {}

    void removeFunds(double amount) override {
        if (amount > 0 && amount <= accBalance) {
            accBalance -= amount;
            logTransaction("Withdrawn: " + to_string(amount));
            cout << amount << " withdrawn." << endl;
        } else {
            cout << "Insufficient balance." << endl;
        }
    }
};

int main() {
    Savings savingsAcc("SA123", 1000, "ikrash", 5.0, 500);
    savingsAcc.addFunds(500);
    savingsAcc.computeInterest();
    savingsAcc.removeFunds(200);
    savingsAcc.displayTransactions();
    cout << endl;

    FixedDeposit fixedAcc("FD456", 5000, "Babar", "2025-12-31", 7.5);
    fixedAcc.computeInterest();
    fixedAcc.removeFunds(1000);
    fixedAcc.displayTransactions();
    cout << endl;

    Checking checkingAcc("CA789", 2000, "Fakhar");
    checkingAcc.removeFunds(500);
    checkingAcc.displayTransactions();
}
