/*Write a program in C++ to calculate and print the Electricity bill of a given customer.
 The customer id, name and unit consumed by the user should be taken from the keyboard and display the total amount to pay to the customer. The charges are as follow: 
 ....
If bill exceeds Rs. 18000 then a surcharge of 15% will be charged on top of the bill. 
Test Input: 
    1001 //Customer ID 
    James //Customer Name 
    800 //Units Consumed 
Expected Output: 
    Customer ID :1001 
    Customer Name: James 
    Units Consumed :800 
    Amount Charges @Rs. 35.90 per unit: 28720 
    Surcharge Amount: 4308 
    Net Amount Paid by the Customer: 33028.00*/

    #include <iostream>
using namespace std;

int main (){
    //taking inputs
    string id, name;
    float units;
    cout << "Enter customer id: ";
    cin >> id;
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter units consumed: ";
    cin >> units;

    //determining cost per unit
    float unitCost;
    if (units >= 0 && units <= 199){
        unitCost = 16.20;
    }
    if (units >= 200 && units < 300){
        unitCost = 20.10;
    }
    if (units >= 300 && units < 500){
        unitCost = 27.10;
    }
    if (units >= 500){
        unitCost = 35.90;
    }

    //calculating bill and applying surcharge
    float bill, surcharge = 0.0, totalBill;
    bill = unitCost * units;
    if (bill > 18000){
        surcharge = 0.15 * bill;
    }
    totalBill = bill + surcharge;

    //printing the final bill
    cout << "Customer ID: " << id << endl;
    cout << "Customer Name: " << name << endl;
    cout << "Units Consumed: " << units << endl;
    cout << "Amount Charges @ Rs  " << unitCost << " per unit: " << bill << endl;
    cout << "Surcharge Amount: " << surcharge << endl;
    cout << "Net Amount: " << totalBill << endl;
}
