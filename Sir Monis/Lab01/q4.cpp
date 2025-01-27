/*Write a program that prompts the user to enter the weight of a person in kilograms and outputs the equivalent weight in pounds. Output both the weights rounded to two decimal places. (Note that 1 kilogram = 2.2 pounds.) Format your output with two decimal places.*/

#include <iostream>
#include <iomanip>
using namespace std;

int main (){
    float kg, pound;
    cout << "Enter weight in kg: ";
    cin >> kg;
    pound = kg * 2.2;
    cout << fixed << setprecision(2) << "pounds: " << pound;
}