#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Student {
    int id;
    string name;
    float gpa;

    Student() : id(0), name(""), gpa(0.0f) {}
    
    Student(int i, string n, float g) : id(i), name(n), gpa(g) {}
};

int main() {
    ofstream outFile("students.txt", ios::out);
    if (!outFile) {
        cerr << "error in student.txt" << endl;
        return 0;
    }

    for (int i = 0; i < 5; i++) {
        cout << "Enter information for Student " << i + 1 << ":" << endl;
        cout << "Name: ";
        string name; int id; float gpa;
        cin.ignore(); 
        getline(cin, name);
        cout << "ID: ";
        cin >> id;
        cout << "GPA: ";
        cin >> gpa;
        Student s = Student(id, name, gpa);

        outFile << s.id << " " << s.name << " " << s.gpa << endl;
    }
    outFile.close();

    ofstream appFile("students.txt", ios::app);
    if (!appFile) {
        cerr << "error in student.txt" << endl;
        return 0;
    }

    cout << "\ninformation for one more student to append:" << endl;
    cout << "Name: ";
    cin.ignore();
    string name;
    getline(cin, name);
    cout << "ID: ";
    int id;
    cin >> id;
    cout << "GPA: ";
    float gpa;
    cin >> gpa;

    Student s(id, name, gpa);
    appFile << s.id << " " << s.name << " " << s.gpa << endl;
    appFile.close();

    ifstream inFile("students.txt");
    if (!inFile) {
        cerr << "error in student.txt" << endl;
        return 1;
    }

    cout << endl << "displaying all records " << endl;
    cout << "ID    Name    GPA    " << endl;
    string line;
    while (getline(inFile, line)) {
        cout << line << endl;
    }
    inFile.close();
}