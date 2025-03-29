#include <iostream>
#include <string>
using namespace std;

class Product {
    protected:
    string productID;
    double price;
    string category;

    public:
    Product(string productID, double price, string category) : productID(productID), price(price), category(category) {}

    Product() : productID(""), price(0), category("") {}

    string getProductID() const {
        return productID;
    }

    virtual double calculatePrice() const {
        return price;
    }

    void applyDiscount(double discount) {
        price -= price * discount/100;
    }

    void applyDiscount () {
        cout << "buy one get one free discount applied" << endl;
    }

    virtual void displayDetails() const {
        cout << "Product ID: " << productID << ", Price: $" << price << ", Category: " << category << endl;
    }
    
    virtual ~Product() {}
};

class Electronics : public Product {
    const float taxRate;

    public:
    Electronics(string productID, double price, string category) : Product(productID, price, category), taxRate(15) {}

    Electronics() : Product("", 0, ""), taxRate(15) {}

    double calculatePrice() const override {
        return price + price * taxRate/100;
    }
    
};

class Clothing : public Product {
    const float taxRate;

    public:
    Clothing(string productID, double price, string category) : Product(productID, price, category), taxRate(5) {}

    Clothing() : Product("", 0, ""), taxRate(5) {}

    double calculatePrice() const override {
        return price + price * taxRate/100;
    }
};

class ShoppingCart {   
    string cartID; 
    Product *productsInCart;
    int numberOfProducts;

    public:
    ShoppingCart() : productsInCart(nullptr), numberOfProducts(0), cartID("") {}

    ShoppingCart(int numberOfProducts, Product *productsInCart, string cartID) : productsInCart(productsInCart), numberOfProducts(numberOfProducts), cartID(cartID) {}

    void displayCart() const {
        cout << "Cart ID: " << cartID << endl;
        for (int i = 0; i < numberOfProducts; i++) {
            productsInCart[i].displayDetails();
        }
    }

    friend ShoppingCart operator+ (const ShoppingCart& c1, const ShoppingCart& c2) {
        ShoppingCart returnCart;
        returnCart.numberOfProducts = c1.numberOfProducts + c2.numberOfProducts;
        returnCart.productsInCart = new Product[returnCart.numberOfProducts];
        for (int i = 0; i < c1.numberOfProducts; i++) {
            returnCart.productsInCart[i] = c1.productsInCart[i];
        }
        for (int i = 0; i < c2.numberOfProducts; i++) {
            returnCart.productsInCart[c1.numberOfProducts + i] = c2.productsInCart[i];
        }
        returnCart.cartID = c1.cartID + " + " + c2.cartID;
        return returnCart;
    }

    friend void operator- (ShoppingCart& c1, const Product& p1) {
        // remove p1 from c1
        for (int i = 0; i < c1.numberOfProducts; i++) {
            if (c1.productsInCart[i].getProductID() == p1.getProductID()) {
                for (int j = i; j < c1.numberOfProducts - 1; j++) {
                    c1.productsInCart[j] = c1.productsInCart[j + 1];
                }
            }
        }
        cout << p1.getProductID() << " removed from cart" << c1.cartID << endl;
        c1.numberOfProducts--;
    }

    friend void operator/ (ShoppingCart& c1, const int& numberOfUsers) {
    // calculate total price of items in cart and divide it by numberOfUsers
        double totalPrice = 0;
        for (int i = 0; i < c1.numberOfProducts; i++) {
            totalPrice += c1.productsInCart[i].calculatePrice();
        }
        cout << "Total price of items in cart " << c1.cartID << " is $" << totalPrice << endl;
        cout << "Each user will pay $" << totalPrice / numberOfUsers << endl;
    }

    friend void operator* (ShoppingCart& c1, const double& discount) {
        for (int i = 0; i < c1.numberOfProducts; i++) {
            c1.productsInCart[i].applyDiscount(discount);
        }
        cout << "Discount applied: " << discount << "% to cart " << c1.cartID << endl;
    }

    ~ShoppingCart() {
        delete[] productsInCart;
    }
};

int main() {
    Product p1("123", 100, "Electronics");
    Product p2("456", 200, "Clothing");
    Product p3("789", 300, "Electronics");

    Product *productsInCart1 = new Product[2];  
    productsInCart1[0] = p1;
    productsInCart1[1] = p2;
    ShoppingCart cart1(2, productsInCart1, "cart1");

    Product *productsInCart2 = new Product[2];
    productsInCart2[0] = p3;
    productsInCart2[1] = p1;
    ShoppingCart cart2(2, productsInCart2, "cart2");  

    cart1.displayCart();
    cout << endl;
    cart2.displayCart();
    cout << endl;

    cout << "+ overloading" << endl;
    ShoppingCart cart3 = cart2 + cart1;  // operator+
    cart3.displayCart();

    cout << endl << "- overloading" << endl;
    cart1 - p1;          // operator-
    cart1.displayCart();

    cout << endl << "* overloading" << endl;
    cart2 * 0.5;           // operator*
    cart2.displayCart();

    cout << endl << "/ overloading" << endl;
    cart2 / 2;           // operator/
    
}