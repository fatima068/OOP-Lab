#include <iostream>
using namespace std;

class BankAccount {
  string accountNumber;
  string accHolderName;
  float balance;

  public:
  BankAccount(string accountNumber, string accHolderName, float balance) : accountNumber(accountNumber), accHolderName(accHolderName), balance(balance) {}

  void deposit (double amount) {
    balance += amount;
  }  

  void withdraw (double amount) {
    if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "remaining balance: " << balance << endl;
        } else {
            cout << "insufficient funds" << endl;
        }
  }

  void display() const {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder Name: " << accHolderName << endl;
        cout << "Balance: " << balance << endl;
  }
};

int main() {
    BankAccount accounts[3] = {
        BankAccount("111222333", "babar azam", 2500.0),
        BankAccount("444555666", "ikki", 3000.0),
        BankAccount("777888999", "fakhar zaman", 5000.0)
    };

    // Iterate through each account
    for (int i = 0; i < 3; i++) {
        cout << "Initial Account Details:" << endl;
        accounts[i].display();
        cout << endl;

        // Deposit 500.0 rupees
        cout << "Depositing 500.0 rupees..." << endl;
        accounts[i].deposit(500.0);
        cout << "Updated Account Details:" << endl;
        accounts[i].display();
        cout << endl;

        // Withdraw 200.0 rupees
        cout << "Withdrawing 200.0 rupees..." << endl;
        accounts[i].withdraw(200.0);
        cout << "Updated Account Details:" << endl;
        accounts[i].display();
    }
}