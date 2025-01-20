/* Q1: Write a C++ program to check whether a given number is prime or not. Allow
the user to input a number and display whether it's prime or not? */

#include <iostream>
using namespace std;

int main(){
    int n, count = 0;
    cout << "Enter number to check: ";
    cin >> n;
    for (int i = 2; i < n; i++){
        if (n%i == 0){
            count++;
        }
    }
    if (count == 0)
        cout << "Prime Number";
    else
        cout << "Not a prime number";
}
