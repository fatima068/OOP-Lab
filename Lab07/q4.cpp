#include <iostream>
using namespace std;

class Student;

class Course {
protected:
    string courseName;
    string courseID;
    string credits;
    string courseInstructor;
    string courseSchedule;

public:
    Course() : courseName(""), courseID(""), credits(""), courseInstructor(""), courseSchedule("") {}

    Course(string courseName, string courseID, string credits, string courseInstructor, string courseSchedule) : courseName(courseName), courseID(courseID), credits(credits), courseInstructor(courseInstructor), courseSchedule(courseSchedule) {}

    void displayCourse() {
        cout << "Course Name: " << courseName << ", Course ID: " << courseID << ", Credits: " << credits << ", Course Instructor: " << courseInstructor << ", Course Schedule: " << courseSchedule << endl;
    }

    void registerStudent(Student& student);

    void calculateGrades();
};

class Person {
protected:
    string userName;
    string id;
    string address;
    string phoneNumber;
    string email;

public:
    Person() : userName(""), id(""), address(""), phoneNumber(""), email("") {}

    Person(string userName, string id, string address, string phoneNumber, string email) : userName(userName), id(id), address(address), phoneNumber(phoneNumber), email(email) {}

    virtual void display() {
        cout << "Person " << userName << ": " << endl;
        cout << "ID: " << id << ", Address: " << address << ", Phone: " << phoneNumber << ", Email: " << email << endl;
    }

    virtual void updateInfo() {
        cout << "updating info" << endl;
    }

    virtual ~Person() {}
};

class Student : public Person {
protected:
    Course* coursesEnrolled;
    float GPA;
    int enrollmentYear;
    int numCourses;

public:
    Student() : coursesEnrolled(nullptr), GPA(0), enrollmentYear(0), numCourses(0), Person() {}

    Student(string userName, string id, string address, string phoneNumber, string email, Course* coursesEnrolled, float GPA, int enrollmentYear, int numCourses) 
        : Person(userName, id, address, phoneNumber, email), coursesEnrolled(coursesEnrolled), GPA(GPA), enrollmentYear(enrollmentYear), numCourses(numCourses) {}

    string getUserName() {
        return userName;
    }

    void display() override {
        Person::display();
        cout << "Courses Enrolled: ";
        for (int i = 0; i < numCourses; i++) {
            coursesEnrolled[i].displayCourse();
        }
        cout << endl;
        cout << "GPA: " << GPA << ", Enrollment Year: " << enrollmentYear << endl;
    }

    void addCourse(Course& course) {
        Course* newCourses = new Course[numCourses + 1];
        for (int i = 0; i < numCourses; i++) {
            newCourses[i] = coursesEnrolled[i];
        }
        newCourses[numCourses] = course;
        delete[] coursesEnrolled;
        coursesEnrolled = newCourses;
        numCourses++;
    }

    void updateInfo() override {
        int choice = 0;
        while (choice != 8) {
            cout << "1. Update Courses\n2. Update GPA\n3. Update Enrollment Year\n4.Update Name\n5.update address\n6.update phone number\n7.update email\n8. Exit" << endl;
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    cout << "Enter the number of courses: ";
                    cin >> numCourses;
                    coursesEnrolled = new Course[numCourses];
                    for (int i = 0; i < numCourses; i++) {
                        string name, id, credits, instructor, schedule;
                        cout << "Enter course " << i+1 << " name: ";
                        cin >> name;
                        cout << "Enter course " << i+1 << " ID: ";
                        cin >> id;
                        cout << "Enter course " << i+1 << " credits: ";
                        cin >> credits;
                        cout << "Enter course " << i+1 << " instructor: ";
                        cin >> instructor;
                        cout << "Enter course " << i+1 << " schedule: ";
                        cin >> schedule;
                        coursesEnrolled[i] = Course(name, id, credits, instructor, schedule);
                    }
                    break;

                case 2:
                    cout << "Enter new GPA: ";
                    cin >> GPA;
                    break;

                case 3:
                    cout << "Enter new enrollment year: ";
                    cin >> enrollmentYear;
                    break;

                case 4:
                    cout << "Enter new name: ";
                    cin >> userName;
                    break;

                case 5:
                    cout << "Enter new address: ";
                    cin >> address;
                    break;

                case 6:
                    cout << "Enter new phone number: ";
                    cin >> phoneNumber;
                    break;

                case 7:
                    cout << "Enter new email: ";
                    cin >> email;
                    break;

                case 8:
                    cout << "Exit" << endl;
                    break;

                default:
                    cout << "Invalid choice" << endl;
                    break;
            }
        }
    }

    ~Student() override {
        delete[] coursesEnrolled;
    }
};

class Professor : public Person {
protected:
    string department;
    Course* coursesTaught;
    float salary;
    int numCourses;

public:
    Professor() : coursesTaught(nullptr), salary(0), numCourses(0), Person() {}

    Professor(string userName, string id, string address, string phoneNumber, string email, string department, Course* coursesTaught, float salary, int numCourses) 
        : Person(userName, id, address, phoneNumber, email), department(department), coursesTaught(coursesTaught), salary(salary), numCourses(numCourses) {}

    void display() override {
        Person::display();
        cout << "Department: " << department << ", salary: " << salary << endl;
        cout << "Courses Taught: ";
        for (int i = 0; i < numCourses; i++) {
            coursesTaught[i].displayCourse();
        }
        cout << endl;
    }

    void updateInfo() override {
        int choice = 0;
        while (choice != 8) {
            cout << "1. Update Courses\n2. Update Salary\n3. Update Department\n4.Update Name\n5.update address\n6.update phone number\n7.update email\n8. Exit" << endl;
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    cout << "Enter the number of courses: ";
                    cin >> numCourses;
                    coursesTaught = new Course[numCourses];
                    for (int i = 0; i < numCourses; i++) {
                        string name, id, credits, instructor, schedule;
                        cout << "Enter course " << i+1 << " name: ";
                        cin >> name;
                        cout << "Enter course " << i+1 << " ID: ";
                        cin >> id;
                        cout << "Enter course " << i+1 << " credits: ";
                        cin >> credits;
                        cout << "Enter course " << i+1 << " instructor: ";
                        cin >> instructor;
                        cout << "Enter course " << i+1 << " schedule: ";
                        cin >> schedule;
                        coursesTaught[i] = Course(name, id, credits, instructor, schedule);
                    }
                    break;

                case 2:
                    cout << "Enter new salary: ";
                    cin >> salary;
                    break;

                case 3:
                    cout << "Enter new department: ";
                    cin >> department;
                    break;

                case 4:
                    cout << "Enter new name: ";
                    cin >> userName;
                    break;

                case 5:
                    cout << "Enter new address: ";
                    cin >> address;
                    break;

                case 6:
                    cout << "Enter new phone number: ";
                    cin >> phoneNumber;
                    break;

                case 7:
                    cout << "Enter new email: ";
                    cin >> email;
                    break;

                case 8:
                    cout << "Exit" << endl;
                    break;

                default:
                    cout << "Invalid choice" << endl;
                    break;
            }
        }
    }

    ~Professor() override {
        delete[] coursesTaught;
    }
};

class Staff : public Person {
protected:
    string department;
    string position;
    string salary;

public:
    Staff() : department(""), position(""), salary(""), Person() {}

    Staff(string userName, string id, string address, string phoneNumber, string email, string department, string position, string salary) 
        : Person(userName, id, address, phoneNumber, email), department(department), position(position), salary(salary) {}

    void display() override {
        Person::display();
        cout << "Department: " << department << ", Position: " << position << ", Salary: " << salary << endl;
    }

    void updateInfo() override {
        int choice = 0;
        while (choice != 8) {
            cout << "1. Update department\n2. Update Salary\n3. Update position\n4.Update Name\n5.update address\n6.update phone number\n7.update email\n8. Exit" << endl;
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    cout << "Enter new department: ";
                    cin >> department;
                    break;

                case 2:
                    cout << "Enter new salary: ";
                    cin >> salary;
                    break;

                case 3:
                    cout << "Enter new position: ";
                    cin >> position;
                    break;

                case 4:
                    cout << "Enter new name: ";
                    cin >> userName;
                    break;

                case 5:
                    cout << "Enter new address: ";
                    cin >> address;
                    break;

                case 6:
                    cout << "Enter new phone number: ";
                    cin >> phoneNumber;
                    break;

                case 7:
                    cout << "Enter new email: ";
                    cin >> email;
                    break;

                case 8:
                    cout << "Exit" << endl;
                    break;

                default:
                    cout << "Invalid choice" << endl;
                    break;
            }
        }
    }
};

void Course::registerStudent(Student& student) {
        student.addCourse(*this);
        cout << "Student" << student.getUserName() << " registered for the course: " << courseName << endl;
}

void Course::calculateGrades() {
    cout << "Grades calculated for the course: " << courseName << endl;
}

int main() {
    Course course1("Mathematics", "M101", "3", "sir shahid", "Mon 10:00 AM");
    Course course2("Physics", "P101", "4", "mr brunner", "Tue 2:00 PM");
    Student student("percy jackson", "k0924", "karachi", "264565446542", "percy@halfblood.com", nullptr, 3.5, 2021, 0);
    course1.registerStudent(student);
    course2.registerStudent(student);
    student.display();
    Professor professor("mr brunner", "p0998", "karachi", "366543454", "brunner@yancy.com", "Mathematics", nullptr, 75000, 0);
    professor.updateInfo();
    professor.display();
    Staff staff("tantalus", "9909", "lahore", "345345345", "tantalus@halfblood.com", "Administration", "Manager", "50000");
    staff.updateInfo();
    staff.display();
    course1.calculateGrades();
}