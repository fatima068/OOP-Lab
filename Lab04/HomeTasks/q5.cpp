#include <iostream>
using namespace std;

class Employee {
    private:
    int employeeID;
    string name;
    string department;
    double salary;

    public:
    Employee(){
        employeeID = 0;
        name = "";
        department = "";
        salary = 0.0;
    }

    Employee(int employeeID, string name, string department, double salary){
        this->employeeID = employeeID;
        this->name = name;
        this->department = department;
        this->salary = salary;
    }

    string getName () const {
        return name;
    }

    void giveBonus (double amount){
        salary += amount;
        cout << "bonus given to " << name << endl << endl; 
    }

    bool isManager() const {
        if (department == "management")
            return true;
        return false;
    }

    void displayDetails () const {
        cout << "ID: " << employeeID << "\nName: " << name << "\nDepartment: " << department << "\nSalary: " << salary << endl << endl;
    }
};

int main() {
    Employee e1(101, "babar", "Management", 55000.0);
    Employee e2(102, "fakhar", "Engineering", 45000.0);
    e1.displayDetails();
    
    if (e1.isManager()) {
        cout << e1.getName() << " is a manager." << endl;
    } else {
        cout << e1.getName() << " is not a manager." << endl;
    }

    if (e2.isManager()) {
        cout << e2.getName() << " is a manager." << endl;
    } else {
        cout << e2.getName() << " is not a manager." << endl;
    }

    e1.giveBonus(5000.0);
    e1.displayDetails();
    e2.displayDetails();
}