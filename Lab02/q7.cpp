/*You are tasked with building a simple product management system for an online store.

Create a function that allows the addition of a new product to the system. The function should take parameters such as product name, price, quantity, and any other relevant details.

Implement a function that takes a product ID as input and displays detailed information about the product including its name, price, quantity in stock, and any other relevant details.

Design a function that enables the update of product information. It should take a product ID as well as the new details (e.g., updated price, quantity, etc.) and modify the existing product's information accordingly.

Create a function that removes a product from the system based on its product ID. Ensure that the inventory is updated after the removal.
*/

#include <iostream>
#include <cstring>
using namespace std;

struct Product{
    char productName[50];
    int productID;
    float price;
    int qty;
};

void addProduct(char productName[50], int productID, float price, int qty, int& index, Product system[]);
void productInfo(Product system[], int& index);
void updateInfo(int productID, float newprice, int newqty, int& index, Product system[]);
void removeProduct(int productID, int& index, Product system[]);


int main (){
    Product system[50];
    char productName[50];
    int productID, qty, index = 0, n;
    float price;

    //adding a product to system
    cout << "How many products do u want to add? ";
    cin >> n;
    for(int i = 0; i<n; i++){
        cout << "\n\nInformation about product " << i+1 << ": " << endl;
        cout << "Product ID: ";
        cin >> productID;
        cout <<"Product Name: ";
        cin.ignore();
        cin.getline (productName, 50);
        cout << "Price: ";
        cin >> price;
        cout << "Quantity in Stock: ";
        cin >> qty;
        addProduct(productName, productID, price, qty, index, system);
    }
   
    //finding a product
    productInfo(system, index);

    //updating information
    float newprice;     int newqty;
    cout << "\nEnter product ID to update: ";
    cin >> productID;
    cout << "Enter new price: ";
    cin >> newprice;
    cout << "Enter new quantity: ";
    cin >> newqty;
    updateInfo(productID, newprice, newqty, index, system);

    //removing a product
    cout << "\nEnter product ID to remove: ";
    cin >> productID;
    removeProduct(productID, index, system);
}

void addProduct(char productName[50], int productID, float price, int qty, int& index, Product system[]){
    system[index].productID = productID;
    strcpy(system[index].productName, productName);
    system[index].price = price;
    system[index].qty = qty;
    index++;
    cout << "product added ";
}

void productInfo(Product system[], int& index){
    int id;
    cout << "\n\nEnter id of product to search: ";
    cin >> id;
    for (int i = 0; i<=index; i++){
        if (id == system[i].productID){
            cout << "Product ID: " << system[i].productID << endl;
            cout << "Product Name: " << system[i].productName << endl;
            cout << "Price: Rs " << system[i].price << endl;
            cout << "Quantity in Stock: " << system[i].qty << endl;
            return;
        }
    }
    cout << "product not found";
}

void updateInfo(int productID, float newprice, int newqty, int& index, Product system[]){
    for (int i = 0; i < index; i++) {
        if (system[i].productID == productID) {
            system[i].price = newprice;
            system[i].qty = newqty;
            cout << "product information updated\n";
            return;
        }
    }
    cout << "Product not found.\n";
}

void removeProduct(int productID, int& index, Product system[]){
    int indexRemoved;
    for (int i = 0; i < index; i++) {
        if (system[i].productID == productID) {
            indexRemoved = i;
            break;
        }
    }
    
    for (int i = indexRemoved; i < index - 1; i++) {
        system[i] = system[i + 1]; 
    }
    index--;
    cout << "Product removed\n";
    return;
    cout << "Product not found.\n";
}

