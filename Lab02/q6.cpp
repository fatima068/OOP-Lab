/*You are tasked with implementing a simple Student Registration System in C++. Define two structures, Register and Student, where Register contains attributes courseId and courseName, and Student inherits from Register while having additional attributes such as studentId, firstName, lastName, cellNo, and email. Your goal is to create an array of Student structures to store information for five students. Write a C++ program that accomplishes the following tasks:
•	Implement the Register and Student structures.
•	Inherit the Register structure in the Student structure.
•	Create an array of Student structures to store information for 5 students.
•	Take input for each student, including their courseId, courseName, studentId, firstName, lastName, cellNo and  email.
•	Display the information for all 5 students.
*/

#include <iostream>
using namespace std;

struct Register{
    int courseID;
    char courseName[50];
};

struct Student:Register{
    int studentId;
    char firstName[15];
    char lastName[15];
    char cellNo[10];
    char email[30];
};

int main (){
    Student studentArr[5];
    cout << "Enter information for all 5 students" << endl;

    //entering data 
    for (int i = 0; i<5; i++){
        cout << "\nStudent " << i + 1 << ":\n";
        
        cout <<"Enter course id: ";
        cin >> studentArr[i].courseID;
        cout <<"Enter course name: ";
        cin >> studentArr[i].courseName;
        cout <<"Enter student id: ";
        cin >> studentArr[i].studentId;
        cout <<"Enter first name: ";
        cin >> studentArr[i].firstName;
        cout <<"Enter last name: ";
        cin >> studentArr[i].lastName; 
        cout << "Enter cell number: ";
        cin >> studentArr[i].cellNo;
        cout << "Enter email: ";
        cin >> studentArr[i].email;
    }

    //printing data
    cout << "\n\n----Displaying All Student Information----";
    for (int i = 0; i < 5; i++) {
        cout << "\nStudent " << i + 1 << ":\n";
        cout << "Course ID: " << studentArr[i].courseID << endl;
        cout << "Course Name: " << studentArr[i].courseName << endl;
        cout << "Student ID: " << studentArr[i].studentId << endl;
        cout << "First Name: " << studentArr[i].firstName << endl;
        cout << "Last Name: " << studentArr[i].lastName << endl;
        cout << "Cell Number: " << studentArr[i].cellNo << endl;
        cout << "Email: " << studentArr[i].email << endl;
    }
}