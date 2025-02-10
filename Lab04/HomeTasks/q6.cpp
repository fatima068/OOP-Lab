#include <iostream>
using namespace std;

class BankAccount {
    private:
    int accountNumber;
    string ownerName;
    double balance;

    public:
    BankAccount(){
        accountNumber = 0;
        ownerName = "";
        balance = 0.0;
    }

    BankAccount(int accountNumber, string ownerName, double balance){
        this->accountNumber = accountNumber;
        this->ownerName = ownerName;
        this->balance = balance;
    }

    // Deposit money into their account.
    void depositMoney(double amount){
        balance += amount;
        cout << "money successfully deposited to account of " << ownerName << endl << endl;
    }

    void withdrawMoney (double amount) {
        if (balance >= amount){
            balance -= amount;
            cout << "money withdrawn successfully by " << ownerName << endl << endl;
            return;
        }
        cout << "insufficient balance to withdraw money " << endl << endl; 
    }

    void displayDetails () const {
        cout << "account number: " << accountNumber << "\nOwners name: " << ownerName << "\ncurrent balance: " << balance << endl << endl ;
    }
};

int main() {
    BankAccount a1(1001, "fakhar zaman", 500.0);
    a1.displayDetails();

    a1.depositMoney(200.0);
    a1.displayDetails();

    a1.withdrawMoney(100.0);
    a1.displayDetails();

    a1.withdrawMoney(700.0);
    a1.displayDetails();
}