/*1. Write a program that finds the second highest number in a float type array of 20 elements using pointer.*/

#include <iostream>
using namespace std;

int main(){

    //declaring array of 20 elements using dma 
    float* arrPtr = new float[20];
    for (int i = 0; i < 20; i++){
        cout << "Enter element " << i + 1 << ": ";
        cin >> *(arrPtr + i);
    }

    //find second highest number in the array
    float highest = -1.0 , secondhighest = -1.0;
    for (int i = 0; i < 20; i++){

        //if a new highest number is found
            if (*(arrPtr + i) > highest){
                secondhighest = highest;
                highest = *(arrPtr + i);
            }

        //if a new second highest is found
            if (*(arrPtr + i) > secondhighest && *(arrPtr + i) < highest){
                secondhighest = *(arrPtr + i);
            }
    }

    cout << "Highest: " << highest << endl;
    cout << "Second highest: " << secondhighest << endl;

    delete[] arrPtr;
}