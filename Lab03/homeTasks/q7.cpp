/*Create a class for a stationary shop. The stationary shop maintains a list for all the items that it sells (hint: array of strings), and another list with the prices of the items (hint: array of prices). Create a menu-driven program to:
    1. Allow the shop owner to add the items and their prices.
    2. Fetch the list of items
    3. Edit the prices of the items
    4. View all the items and their prices
Create a receipt that the shopkeeper can share with their customers. The receipt can only be created after the shopkeeper inputs the items and their amounts bought by the customer.*/

#include <iostream>
#include <iomanip>
using namespace std;

class StationaryShop{
    private:
    string items[100];
    float price[100];
    static int currentEmptyIndex;
    
    public:
    StationaryShop(){
        for (int i = 0; i<100; i++){
            items[i] = "";
            price[i] = 0.00;
        }
    }

    string getItem(int index){
        return items[index];
    }

    float getPrice(int index){
        return price[index];
    }

    void addItems(string item, float p){
        if (currentEmptyIndex >= 100){
            cout << "no more space for new items";
            return;
        }
        items[currentEmptyIndex] = item;
        price[currentEmptyIndex] = p;
        currentEmptyIndex++;
    }

    void displayItems(){
        cout << "List of all items: " << endl; 
        for (int i=0; i<currentEmptyIndex; i++){
            cout << i + 1 << ". " << items[i] << "  $" << fixed << setprecision(2) << price[i] << endl;
        }
    }

    void editPrice(string itemToEdit, float newPrice){
        bool found = false;
        for (int i=0; i<currentEmptyIndex; i++){
            if (items[i] == itemToEdit){
                price[i] = newPrice;
                cout << "price edited" << endl;
                found = true;
                break;
            }
        }
        if (found == false){
            cout << "Item not found" << endl;
        }
    }

    void displayAll() const {
        cout << "List of all items with prices: " << endl; 
        for (int i=0; i<currentEmptyIndex; i++){
            cout << i + 1 << ". " << items[i] << "  $" << fixed << setprecision(2) << price[i] << endl;
        }
    }
};

int StationaryShop::currentEmptyIndex = 0;

int main(){
    StationaryShop s1;
    int userInput = 0;
    string item, receiptItems[100];
    float p, total = 0.0, itemTotal[100], itemPrice[100], grandTotal = 0.0;
    int quantity, serialNum, receiptIndex = 0;
    do {
        cout << endl << "MENU: " << endl;
        cout << "1. Add Item to inventory" << endl;
        cout << "2. View All Items with Prices" << endl;
        cout << "3. Generate Receipt" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> userInput;

        switch (userInput)
        {
            case 1:
                cout << "Enter item to add: ";
                cin >> item;
                cout << "Enter price of item to add: ";
                cin >> p;
                s1.addItems(item, p);
                break;
            case 2:
                s1.displayAll();
                break;
            case 3:
                cout << endl << "RECEIPT GENERATION: " << endl;
                s1.displayItems();
                cout << endl << "Enter serial number of item purchased, or enter 0 to exit: ";

                while (1) {
                    cout << "Item serial number: ";
                    cin >> serialNum;
                    if (serialNum == 0) 
                        break;
                    cout << "Enter quantity: ";
                    cin >> quantity;
                    itemPrice[receiptIndex] = s1.getPrice(serialNum-1);
                    itemTotal[receiptIndex] = quantity * s1.getPrice(serialNum-1);
                    receiptItems[receiptIndex] = s1.getItem(serialNum-1);
                    receiptIndex++;
                }
                
                cout << endl << "FINAL RECEIPT" << endl;
                cout << left << setw(20) << "Item" << setw(10) << "Qty" << setw(10) << "Price" << setw(10) << "Total" << endl;
                for (int i = 0; i<receiptIndex; i++){
                    cout << left << setw(20) << receiptItems[i] << setw(10) << quantity << "$" << setw(9) << fixed << setprecision(2) << itemPrice[i] << "$" << setw(9) << fixed << setprecision(2) << itemTotal[i] << endl;
                    grandTotal += itemTotal[i];
                }
                cout << endl << "GRAND TOTAL: " << grandTotal << endl;
                break;
            case 4:
                cout << "Exiting inventory";
                break;
            default:
                break;
        }
    } while (userInput != 4);
}