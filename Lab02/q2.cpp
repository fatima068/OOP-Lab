/*Write a C++ program that:
     Reads n strings from the user and stores them in a dynamically allocated array of char*.
     Prints the strings in reverse order using pointer arithmetic.
     Finds and prints the string with the most vowels (a, e, i, o, u).
     Calculates and prints the average length of all the strings.
Note: Use pointer notation wherever possible.
If there are multiple strings with the same number of vowels, print the first one encountered*/

#include <iostream>
#include <cstring>
using namespace std;

int main(){
    int n, size;
    cout << "how many strings do u want to enter: ";
    cin >> n;
    char** arr = new char*[n];
    char temp[50];

    //taking inputs of strings and storing in 2d array
    for (int i = 0; i < n; i++) {
        cout << "Enter string " << i + 1 << ": ";
        cin >> temp;
        size = strlen(temp);
        arr[i] = new char[size + 1];
        strcpy(*(arr + i), temp);
    }

    //print each string in reverse order 
    for (int i = 0; i < n; i++){
        size = strlen(*(arr + i));
        for (int j = size-1; j >= 0; j--){
            cout << *(*(arr + i) + j);
        }
        cout << endl;
    }

    //find and print string with most vowels
    int maxvowel = 0;
    char maxvowelstr[50];
    for (int i = 0; i < n; i++){
        int tempVowelCount = 0;
        size = strlen(*(arr + i));
        for (int j = size-1; j >= 0; j--){
            if (*(*(arr + i) + j) == 'a' || *(*(arr + i) + j) == 'e' || *(*(arr + i) + j) == 'i' || *(*(arr + i) + j) == 'o' || *(*(arr + i) + j) == 'u' || *(*(arr + i) + j) == 'A' || *(*(arr + i) + j) == 'E' || *(*(arr + i) + j) == 'I' || *(*(arr + i) + j) == 'O' || *(*(arr + i) + j) == 'U'){
                tempVowelCount++;
            }
        }
        if (tempVowelCount > maxvowel){
            maxvowel = tempVowelCount;
            strcpy(maxvowelstr, *(arr + i));
        }
    }
    cout << "String: " << maxvowelstr << " vowel count: " << maxvowel;

    // Calculate and print the average length of all the strings
    int totalLength = 0;
    float avg;
    for (int i = 0; i < n; i++){
        totalLength += strlen(*(arr + i));
    }
    avg = totalLength / n;
    cout << endl << "Average length of strings: " << avg;

    //freeing the memory
    for (int i = 0; i < n; i++) {
        delete[] *(arr + i);
    }
    delete[] arr;
}
