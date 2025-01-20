/*Design a C++ program to manage student marks. Allow the user to input
marks for students in three subjects (Mathematics, English, and Science). The
program should calculate the total marks, average marks, and display the grade
for each student. The user can specify the number of students and then input
the marks for each subject for each student. Finally, display the marks, total,
average, and grade for each student. Assume a grading system with the
following criteria:
90 or above: Grade A
80-89: Grade B
70-79: Grade C
60-69: Grade D
Below 60: Grade F*/

#include <iostream>
using namespace std;

int main(){
    int n, m1, m2, m3, avg, total;
    cout << "Enter number of students: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        total = 0;
        cout << "\nEnter numbers for Maths: ";
        cin >> m1;
        total = total + m1;
        cout << "Enter numbers for English: ";
        cin >> m2;
        total = total + m2;
        cout << "Enter numbers for Science: ";
        cin >> m3;
        total = total + m3;  
        cout << "\n --STUDENT "  << (i + 1) << endl;
        cout << "Maths marks: " << m1 << endl;
        cout << "English marks: " << m2 << endl;
        cout << "Science marks: " << m3 << endl;
        cout << "total marks: " << total << endl;
        avg = total/3;
        cout << "average marks: " << avg << endl;
        avg >= 90? cout << "Grade A": avg >= 80 && avg < 90? cout << "Grade B":avg >= 70 && avg < 80? cout << "Grade C" :avg >= 60 && avg < 70? cout << "Grade D": cout << "Grade F";;;;
    }
}