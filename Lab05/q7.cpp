/*Implement a restaurant ordering system that holds information about the restaurant’s menus, menu items, orders, and payments. Identify the relationship between the five entities mentioned. Keep in mind the following information as well:
a) Menu Items hold two things: food name and food price.
b) Menu is a class that holds an array of menu items. You can have different functions to add and remove items, or  display the entire menu.
c) Restaurant ordering system has one menu.
d) Any staff member can place an order to the system on behalf of a customer. The order class consists of one or more menu items and a payment.
e) Payment is a class that holds the amount of money that a customer needs to pay.This is generated when the order is placed.*/

#include <iostream>
using namespace std;

class MenuItems {
    private:
    string itemName;
    float itemPrice;

    public:
    MenuItems(string name, float price) : itemName(name), itemPrice(price) {
    }

    MenuItems() {
        itemName = "";
        itemPrice = 0.0;
    }

    string getItemName() const {
        return itemName;
    }
    float getItemPrice() const {
        return itemPrice;
    }

    void setItemName(const string& name) {
        itemName = name;
    }
    void setItemPrice(float price) {
        itemPrice = price;
    }

    void display() const {
        cout << "Item: " << itemName << ", Price: " << itemPrice << endl;
    }
};

class Menu {
    private:
    MenuItems items[10]; // Assuming max 10 items added
    int itemCount;
    
    public:
    Menu() : itemCount(0) {}

    int getItemCount() const {
        return itemCount;
    }

    void addItem(const MenuItems& item) {
        if (itemCount < 10) {
            items[itemCount] = item;
            itemCount++;
            cout << "item added: " << item.getItemName() << endl;
        } else {
            cout << "cannot add more items." << endl;
        }
    }

    void removeItem(const string& itemName) {
        bool found = false;
        for (int i = 0; i < itemCount; i++) {
            if (items[i].getItemName() == itemName) {
                for (int j = i; j < itemCount - 1; j++) {
                    items[j] = items[j + 1];
                }
                itemCount--;
                found = true;
                cout << "item removed: " << itemName << endl;
                break;
            }
        }
        if (!found) {
            cout << "ntem not found " << endl;
        }
    }

    void displayMenu() const {
        if (itemCount == 0) {
            cout << " menu is empty." << endl;
        } else {
            cout << "Menu Items:" << endl;
            for (int i = 0; i < itemCount; i++) {
                items[i].display();
            }
        }
    }
};

class Payment {
    private:
    float amount;
    
    public:
    Payment(float amount = 0.0) : amount(amount) {}

    float getAmount() const {
        return amount;
    }

    void setAmount(float amount) {
        this->amount = amount;
    }

    void displayPaymentDetails() const {
        cout << "Payment Amount: " << amount << endl;
    }
};

class Order {
    private:
    MenuItems items[10];      
    int itemCount;                   
    Payment payment;                 

    public:
    Order() : itemCount(0), payment(0.0) {}

    void addItem(const MenuItems& item) {
        if (itemCount < 10) {
            items[itemCount] = item;
            itemCount++;
            cout << "item added to order: " << item.getItemName() << endl;
        } else {
            cout << "cannot add more items to the order" << endl;
        }
    }

    void calculatePayment() {
        float total = 0.0;
        for (int i = 0; i < itemCount; i++) {
            total += items[i].getItemPrice();
        }
        payment.setAmount(total);
        cout << "total payment calculated: " << total << endl;
    }

    void displayOrder() const {
        cout << "Order Details:" << endl;
        for (int i = 0; i < itemCount; i++) {
            items[i].display();
        }
        payment.displayPaymentDetails();
    }
};

int main() {
    Menu menu;
    Order order;
    menu.addItem(MenuItems("biryani", 220.00));
    menu.addItem(MenuItems("pasta", 600.50));
    menu.addItem(MenuItems("nihari", 350.0));
    menu.displayMenu();
    order.calculatePayment();
    order.displayOrder();
}