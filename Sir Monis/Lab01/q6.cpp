/*Write a program that reads a student name followed by five test scores. The program should output the 
student’s name, the five test scores, and the average test score. Output the average test score with two 
decimal places. */

#include <iostream>
#include <iomanip>
using namespace std;

int main (){
    string name; 
    int score[5], total = 0;
    float avg;
    cout << "Enter student name: ";
    cin >> name;

    for (int i = 0; i < 5; i++){
        cout << "Enter score " << i+1 << ": ";
        cin >> score[i];
        total += score[i];
    }
    
    avg = total/5.0;
    cout << name << " " << score[0] << " " << score[1] << " " << score[2] << " " << score[3] << " " << score[4] << endl;
    cout << "Avg: " << fixed << setprecision(2) << avg;
}