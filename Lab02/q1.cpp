/*Write a C++ program that reads a group of n numbers from the user and stores them in a dynamically allocated array of type float. Then, the program should:
     Calculate the average of the numbers.
     Find the number closest to the average.
     Print the average and the number closest to it.
     Use pointer notation wherever possible.*/

#include <iostream>
using namespace std;

int main (){
    int size;
    cout << "Enter size of your array: ";
    cin >> size;
    float total = 0, avg, diff, minDiff = 9999.9, numClosest;
    float* arr = new float[size];

    for(int i = 0; i<size; i++){
        cout << "Enter element " << i+1 << ": ";
        cin >> *(arr + i);
        total += *(arr + i);
    }

    avg = total/size;
    for(int i = 0; i<size; i++){
        diff = *(arr + i) - avg;
        if (diff < 0)
            diff *= -1;
        if (diff < minDiff){
            numClosest = *(arr + i);
            minDiff = diff;
        }
    }

    cout << "Average: " << avg << endl;
    cout << "Number closest to avg: " << numClosest << endl;

    delete[] arr;
}
