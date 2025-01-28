/*You are required to write a c++ function swap_string that shifts the last n characters of a string to the front n times. It will take str and int as parameters. And will return the new string after shifting. Note: You have to work with pointers.*/

#include <iostream>
#include <cstring> 
using namespace std;

void swap_string(char str[], int shift);

int main() {
    char temp[200]; 
    int shift;

    cout << "Enter the string: ";
    cin.getline(temp, 200);
    cout << "Enter the number of characters to shift: ";
    cin >> shift;

    swap_string(temp, shift);
    cout << "Shifted string: " << temp << endl;
}

void swap_string(char str[], int shift) {
    if(shift >= strlen(str)) {
        cout << "shift value too large" ;
        return;
    }

    char temp[strlen(str) + 1];
    for (int i = 0; i < shift; i++) {
        temp[i] = str[strlen(str) - shift + i];
    }

    for (int i = 0; i < strlen(str) - shift; i++) {
        temp[shift + i] = str[i];
    }

    temp[strlen(str)] = '\0';
    strcpy(str, temp);
}
