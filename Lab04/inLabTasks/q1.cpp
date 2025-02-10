#include <iostream>
using namespace std;

class Student {
    private:
    int studentID;
    string name;
    int age;
    char grade;

    public:
    Student(){
        grade = 'N';
    }

    Student(int studentID, string name, int age, char grade){
        this->studentID = studentID;
        this->name = name;
        this->age = age;
        this->grade = grade;
    }

    string getName() {
        return name;
    }

    void promoteStudent() {
        if (grade > 65){
            grade = grade - 1;
        }
    }

    bool isEligibleForScholarship() {
        if (grade == 'A'){
            return true;
        }
        return false;
    }

    void displayDetails() {
        cout << "student id: " << studentID << "\nStudent name: " << name << "\nage: " << age << "\ngrade: " << grade << endl << endl;
    }
};

int main() {
    Student s1(998, "haris", 24, 'A');
    Student s2(924, "babar", 28, 'B');
    Student s3(980, "fakhar", 32, 'C');

    cout << "student details: " << endl;
    s1.displayDetails();
    s2.displayDetails();
    s3.displayDetails();

    cout << "\npromoting students:" << endl;
    s2.promoteStudent();
    s3.promoteStudent();
    s2.displayDetails();
    s3.displayDetails();

    cout << "\nscholarship eligibility:\n";
    if (s1.isEligibleForScholarship()) 
        cout <<  s1.getName() << ": eligible\n";
    else 
        cout <<  s1.getName() << ": not eligible\n";

    if (s2.isEligibleForScholarship()) 
        cout <<  s2.getName() << ": eligible\n";
    else 
        cout <<  s2.getName() << ": not eligible\n";

    if (s3.isEligibleForScholarship()) 
        cout <<  s3.getName() << ": eligible\n";
    else 
        cout <<  s3.getName() << ": not eligible\n";
}