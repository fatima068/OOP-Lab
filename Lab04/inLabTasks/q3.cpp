#include <iostream>
using namespace std;

class Account{
    private:
    string accountNumber;
    string accountHolderName;
    double balance;

    public:
    Account(){
        accountHolderName = "";
        accountNumber = "";
        balance = 0.0;
    }

    Account(string accountNumber, string accountHolderName, double balance){
        this->accountNumber = accountNumber;
        this->accountHolderName = accountHolderName;
        this->balance = balance;
    }

    string getName() const {
        return accountHolderName;
    }

    void deposit(double amount){
        balance += amount;
        cout <<"successfully depositef" << endl;
        cout << "new balance: " << balance << endl;
    }

    void withdraw(double amount){
        if (amount<=balance){
            balance -= amount;
            cout << "remianing balance: " << balance;
            return;
        }
        cout <<"insufiicient funds " << endl;
    }

    void checkBalance () {
        cout << "current balance: " << balance;
    }
};

int main() {
    Account a1("2297039", "Babar", 500.0);
    Account a2("2240170", "Shan", 1000.0);
    Account a3("2189652", "Asif", 50.0);

    cout << "\nPerforming Transactions: " << endl;
    
    cout << "\nDepositing into " << a1.getName() << "'s account" << endl;
    a1.deposit(200);

    cout << "\nWithdrawing from " << a2.getName() << "'s account" << endl;
    a2.withdraw(300);
    cout << endl; 

    cout << "\nWithdrawing from " << a3.getName() << "'s account" << endl;
    a3.withdraw(100);
    cout << endl;

    cout << "\n all account balances" << endl;
    
    cout << a1.getName() << ": ";
    a1.checkBalance();
    cout << endl;

    cout << a2.getName() << ": ";
    a2.checkBalance();
    cout << endl;

    cout << a3.getName() << ": ";
    a3.checkBalance();
    cout << endl;
}
