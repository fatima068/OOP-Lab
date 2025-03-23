#include <iostream>
#include <string>
using namespace std;

class Currency {
protected:
    string currencyCode;
    string currencySymbol;
    float exchangeRate; 
    float amount;

public:
    Currency(float amount, string currencyCode, string currencySymbol, float exchangeRate) : amount(amount), currencyCode(currencyCode), currencySymbol(currencySymbol), exchangeRate(exchangeRate) {}

    virtual void convertToBase() {
        amount = amount * exchangeRate; 
    }

    virtual void display() {
        cout << "displaying currency" << endl;
    }

    virtual void convertTo(Currency& c1) {
        // converting to 
        cout << "converting " << amount << currencyCode << " to " << c1.currencyCode << endl;
        // convertToBase(); 
        amount = amount / c1.exchangeRate; 
        currencyCode = c1.currencyCode;
        currencySymbol = c1.currencySymbol;
        exchangeRate = c1.exchangeRate;
    }
};

class Dollar : public Currency {
public:
    Dollar(float amt) : Currency(amt, "USD", "$", 1.0) {} 

    void convertToBase() override {
        cout << "dollar is already the base curency " << endl << endl;
    }

    void display() override {
        cout << "Currency details (dollar): " << endl;
        cout << "Amount: " << amount << "\ncurrency code: " << currencyCode << "\ncurrency symbol: " << currencySymbol << "\nexchange rate: " << exchangeRate << endl << endl;
    }
};

class Euro : public Currency {
public:
    Euro(float amt) : Currency(amt, "EUR", "€", 0.85) {} 

    void convertToBase() override {
        cout << amount << " Rupee to base currency (USD): " << amount/exchangeRate << endl << endl;
    }

    void display() override {
        cout << "Currency details (euro): " << endl;
        cout << "Amount: " << amount << "\ncurrency code: " << currencyCode << "\ncurrency symbol: " << currencySymbol << "\nexchange rate: " << exchangeRate << endl << endl;
    }
};

class Rupee : public Currency {
public:
    Rupee(float amt) : Currency(amt, "PKR", "Rs", 300) {} 

    void convertToBase() override {
        cout << amount << " Rupee to base currency (USD): " << amount/exchangeRate << endl << endl;
    }

    void display() override {
        cout << "Currency details (rupee): " << endl;
        cout << "Amount: " << amount << "\ncurrency code: " << currencyCode << "\ncurrency symbol: " << currencySymbol << "\nexchange rate: " << exchangeRate << endl << endl;
    }
};

int main() {
    Dollar usd(30);
    Euro eur(50);
    Rupee pkr(3000);

    usd.display();
    usd.convertToBase();

    eur.display();
    eur.convertToBase(); 

    pkr.display();
    pkr.convertToBase(); 
    
    usd.convertTo(eur);
    usd.display();

    usd.convertTo(pkr);
    usd.display();
}