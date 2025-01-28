/*You are required to write a C++ program that will creates a function named unique that will take array as input.The array may contain the duplicates values but you have to process on the array and have to return the array which must contain only unique values not duplicates.*/

#include <iostream>
using namespace std;

int* unique(int* arr, int size, int& ansSize);

int main(){
    int size, ansSize;
    cout << "Enter size of array: ";
    cin >> size;
    int* arr = new int[size];

    int* ans = unique(arr, size, ansSize);
    for (int i = 0; i < ansSize; i++) {
        cout << ans[i] << "  ";
    }

    delete[] ans;
    delete[] arr;
}

int* unique(int* arr, int size, int& ansSize){
    int uniqueIndex = 0, duplicateCount = 0;
    for (int i = 0; i < size; i++) {
        cout << "Enter the element " << i+1 << ": ";
        cin >> arr[i];
    }

    for(int i = 0; i<size; i++){
        for (int j = i+1; j<size; j++){
            if (arr[i] == arr[j] && arr[i] != -1){
                arr[j] = -1;
                duplicateCount++;
            }
        }
    }
    
    ansSize = size - duplicateCount;
    int* uniqueArr = new int[size - duplicateCount];
    for(int i = 0; i<size; i++){
        if (arr[i] != -1){
            uniqueArr[uniqueIndex] = arr[i];
            uniqueIndex++;
        }
    }
    return uniqueArr;
}