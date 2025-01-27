/*2. Write a program that calculates the sum of all the elements in array using pointers*/

#include <iostream>
using namespace std;

int main (){

    //declaring array of num of elements input by user using dma and taking input from user 
    int size;
    cout << "Enter number of elements: ";
    cin >> size;

    int* arrPtr = new int[size];
    for (int i = 0; i < size; i++){
        cout << "Enter integer " << i + 1 << ": ";
        cin >> *(arrPtr + i);
    }

    //calculate the sum
    int total = 0;
    for (int i = 0; i < size; i++){
        total += *(arrPtr + i);
    }

    cout << "The sum is: " << total;
}