#include <iostream>
using namespace std;

class PaymentMethod {
    public:
    PaymentMethod() {}

    virtual void processPayment(double amount) = 0;
};

class CreditCard : public PaymentMethod {
    string cardNumber;

    public:
    CreditCard() : PaymentMethod(), cardNumber("") {}

    CreditCard(string n) : PaymentMethod(), cardNumber(n) {}

    void processPayment(double amount) override {
        cout << "payment of rs " << amount << " processed through card number " << cardNumber << endl;
    }
};

class DigitalWallet : public PaymentMethod {
    double balance;

    public:
    DigitalWallet() : balance(0.0), PaymentMethod() {}

    DigitalWallet(double balance) : PaymentMethod(), balance(balance) {}

    void processPayment(double amount) override {
        if (amount > balance) {
            cout << "cannot process payment, insufficient funds" << endl;
            return;
        }
        balance -= amount;
        cout << "new balance: " << balance << endl;
    }
};

int main() {
    CreditCard card1("3298748924723");
    DigitalWallet wallet1(5000.0);

    cout << " Credit Card payment:" << endl;
    card1.processPayment(1000.0); 
    cout << endl;

    cout << " Digital Wallet payment:" << endl;
    wallet1.processPayment(2000.0); 
    wallet1.processPayment(4000.0);  
    wallet1.processPayment(1000.0);  
}
