#include <iostream>
#include <string>
using namespace std;

string hashFunction(string password) {
    int hash = 5381; 
    for (char c : password) {
        hash = hash * 33 + c; 
    } 
    return to_string(hash); 
}

class User {
    protected:
    string name; 
    string ID;
    int numOfPermissions;
    string* listOfPermissions; 
    string email;
    string hashedPassword;

    public:
    User(string name, string ID, int numOfPermissions, string* listOfPermissions, string email, string password) : name(name), ID(ID), numOfPermissions(numOfPermissions), email(email), hashedPassword(hashFunction(password)) {
        this->listOfPermissions = new string[numOfPermissions];
        for (int i=0; i<numOfPermissions; i++) {
            this->listOfPermissions[i] = listOfPermissions[i];
        }
    }

    User() : name(""), ID(""), numOfPermissions(0), listOfPermissions(nullptr), email(""), hashedPassword("") {}

    string getName() const {
        return name;
    }

    bool authenticatePassword(string password) {
        if (hashFunction(password) == hashedPassword) {
            cout << "valid password" << endl;
            return 1;
        }
        cout << "passwords do not match " << endl ;
        return 0;
    }

    virtual void display() {
        cout << "Name: " << name << ", ID: " << ID << ", email: " << email << ", list of permissions: " << endl;
        cout << "permissions: " << endl;
        for (int i=0; i<numOfPermissions; i++) {
            cout << i+1 << ". " << listOfPermissions[i] << endl;
        }
        cout << endl;
    }

    bool accessLab() {
        for (int i=0; i<numOfPermissions; i++) {
            if (listOfPermissions[i] == "full_lab_access") {
                cout << "lab access granted" << endl;
                return 1;
            }
        }
        cout << "cannpt access lab " << endl;
        return 0;
    }

    virtual ~User() {
        delete[] listOfPermissions;
    }
}; 

class Student : virtual public User{
    protected:
    int numOfAssignments;
    bool *assignmentsList; // index contains 1 if assigned, o if it has been submitted

    public:
    Student(string name, string ID, int numOfPermissions, string* listOfPermissions, string email, string password, int numOfAssignments, bool *assignmentsList) : User(name, ID, numOfPermissions, listOfPermissions, email, password), numOfAssignments(numOfAssignments) {
        this->assignmentsList = new bool[numOfAssignments];
        for (int i=0; i<numOfAssignments; i++) {
            this->assignmentsList[i] = assignmentsList[i];
        }
    }

    Student() : numOfAssignments(0), assignmentsList(nullptr), User() {}

    void display() override {
        cout << "Name: " << name << ", ID: " << ID << ", email: " << email << ", list of permissions: " << endl;
        cout << "permissions: " << endl;
        for (int i=0; i<numOfPermissions; i++) {
            cout << i+1 << ". " << listOfPermissions[i] << endl;
        }
        cout << "list of assignments: ";
        for (int i=0; i<numOfAssignments; i++) {
            if (assignmentsList[i] == 0){
                cout << i+1 << ". submitted" << endl; 
            }
            else cout << i+1 << ". assigned" << endl;
        }
        cout << endl;
    }

    void giveAssignment() {
        bool *newList = new bool[numOfAssignments + 1];
        for (int i = 0; i < numOfAssignments; i++) {
            newList[i] = assignmentsList[i];
        }
        newList[numOfAssignments] = 1;
        delete[] assignmentsList;
        assignmentsList = newList;
        numOfAssignments++;
    }

    void submitAssignment(int assignmentNumber) {
        assignmentsList[assignmentNumber-1] = 0;
    }

    ~Student() override {
        delete[] assignmentsList;
    }
};

class TA : public Student{
    protected:
    Student *students; // max 10
    int numStudents;
    string *projectsAssigned;
    int numProjects;

    public:
    TA() : numStudents(0), numProjects(0), students(nullptr), projectsAssigned(nullptr), Student(), User() {}

    TA(string name, string ID, int numOfPermissions, string* listOfPermissions, string email, string password, int numOfAssignments, bool *assignmentsList, Student *students, int numStudents, string *projectsAssigned, int numProjects) : Student(name, ID, numOfPermissions, listOfPermissions, email, password, numOfAssignments, assignmentsList), User(name, ID, numOfPermissions, listOfPermissions, email, password), numStudents(numStudents), numProjects(numProjects) {
        while (numStudents<0 || numStudents>10) {
            cout << "num students should be between 0 and 10: " << endl;
            cin >> numStudents;
        }
        while (numProjects<0 || numProjects>2) {
            cout << "num projects should be between 0 and 2: " << endl;
            cin >> numProjects;
        }
        this->numProjects = numProjects;
        this->numStudents = numStudents;
        this->students = new Student[numStudents];
        this->projectsAssigned = new string[numProjects];
        for (int i = 0; i<numProjects; i++) {
            this->projectsAssigned[i] = projectsAssigned[i];
        }
        for (int i = 0; i<numStudents; i++) {
            this->students[i] = students[i];
        }
    }

    void viewCurrentProjects() const {
        cout << "Current projects for TA " << name << ": " <<endl;
        for (int i=0; i<numProjects; i++) {
            cout << i+1 << ". " << projectsAssigned[i] << endl;
        }
    }

    bool assignProject(string projectName) {
        if (numProjects == 2) {
            cout << "cannot add new project" << endl;
            return false;
        }
        string* newProjects = new string[numProjects+1];
        for (int i =0; i<numProjects; i++) {
            newProjects[i] = projectsAssigned[i];
        }
        newProjects[numProjects] = projectName;
        numProjects++;
        delete[] projectsAssigned;
        projectsAssigned = newProjects;
        cout << "new project assigned successfully" << endl;
        return true;
    }

    void display() override {
        cout << "Name: " << name << ", ID: " << ID << ", email: " << email << ", list of permissions: " << endl;
        cout << "permissions: " << endl;
        for (int i=0; i<numOfPermissions; i++) {
            cout << i+1 << ". " << listOfPermissions[i] << endl;
        }
        cout << "list of assignments: -";
        for (int i=0; i<numOfAssignments; i++) {
            if (assignmentsList[i] == 0){
                cout << i+1 << ". submitted" << endl; 
            }
            else cout << i+1 << ". assigned" << endl;
        }
        cout<< "students assigned: -" << endl;
        for (int i = 0; i<numStudents; i++) {
            students[i].display(); 
        }
        cout << "Projects assigned: -" << endl;
        for (int i = 0; i < numProjects; i++) {
            cout << i+1 << ". " << projectsAssigned[i] << endl;
        }
        cout << endl;
    }

    void assignNewStudent (Student& s1) {
        // check 10 se kam students hain, do dma to assign new student 
        if (numStudents == 10) {
            cout << "cannot assign more students to ta " << name << endl; 
            return;
        }
        Student *newStudents = new Student[numStudents + 1];
        for (int i=0; i<numStudents; i++) {
            newStudents[i] = students[i];
        }
        newStudents[numStudents] = s1;
        numStudents++;
        delete[] students;
        students = newStudents;
    }

    ~TA() {
        delete[] students;
        delete[] projectsAssigned;
    }
};

class Professor : public User {
    protected:
    int numOfTAs;
    TA *allTAs;

    public:
    Professor(string name, string ID, int numOfPermissions, string* listOfPermissions, string email, string password, int numOfTAs, TA *allTAs) : User(name, ID, numOfPermissions, listOfPermissions, email, password), numOfTAs(numOfTAs) {
        this->allTAs = new TA[numOfTAs];
        for (int i=0; i<numOfTAs; i++) {
            this->allTAs[i] = allTAs[i];
        }
    }

    Professor() : numOfTAs(0), allTAs(nullptr), User() {}

    void display() override {
        cout << "Name: " << name << ", ID: " << ID << ", email: " << email << ", list of permissions: " << endl;
        cout << "permissions: " << endl;
        for (int i=0; i<numOfPermissions; i++) {
            cout << i+1 << ". " << listOfPermissions[i] << endl;
        }
        cout << "TAs working on projects: " << endl;
        for (int i=0; i<numOfTAs; i++) {
            cout << i+1 << ". ";
            allTAs[i].display();
            cout << endl;
        }
    }

    void workWithTA(TA& ta, string project) {
        bool flag = 0;
        // TA ke andar function hoga bool assignProject() ka, which will return 0 if project cannot be assigned, and return 1 if project assigned successfully
        // also check ke TA pehle se exist na karta ho in the array
        for (int i=0; i<numOfTAs; i++) {
            if (allTAs[i].getName() == ta.getName()) {
                // TA has been found, already working with him, do nothing 
                cout << "already working with TA" << endl;
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            if (ta.assignProject(project)) {
                TA *newTAs = new TA[numOfTAs+1];
                for (int i=0; i<numOfTAs; i++) {
                    newTAs[i] = allTAs[i];
                }
                newTAs[numOfTAs] = ta;
                numOfTAs++;
                delete[] allTAs;
                allTAs = newTAs;
                cout << "Working with TA " << ta.getName() << endl;
            }
            else cout << "TA does not have more capacity" << endl;
        }
    }

    ~Professor() {
        delete[] allTAs;
    }
};

void authenticateAndPerformAction(User* user, string action) {
    string password;
    cout << "Enter password for user " << user->getName() << ": ";
    cin >> password;

    if (!user->authenticatePassword(password)) {
        cout << "Authentication failed. Access denied." << endl;
        return;
    }

    if (action == "access_lab") {
        if (user->accessLab()) {
            cout << "Action 'access_lab' performed successfully." << endl;
        } else {
            cout << "Action 'access_lab' failed. Insufficient permissions." << endl;
        }
    } 
    
    else if (action == "view_projects") {
        TA* ta = dynamic_cast<TA*>(user);
        Professor* professor = dynamic_cast<Professor*>(user);

        if (ta) {
            ta->viewCurrentProjects();
        } else if (professor) {
            professor->display(); // Professor can view all TAs and their projects
        } else {
            cout << "Action 'view_projects' failed. Only TAs and Professors can perform this action." << endl;
        }
    } 
    
    else if (action == "assign_project") {
        Professor* professor = dynamic_cast<Professor*>(user);
        if (professor) {
            string projectName;
            cout << "Enter project name to assign: ";
            cin >> projectName;

            TA* ta = new TA(); // Create a dummy TA for demonstration
            professor->workWithTA(*ta, projectName);
        } else {
            cout << "Action 'assign_project' failed. Only Professors can perform this action." << endl;
        }
    } 
    
    else if (action == "give_assignment") {
        Student* student = dynamic_cast<Student*>(user);
        if (student) {
            student->giveAssignment();
            cout << "Assignment given successfully." << endl;
        } else {
            cout << "Action 'give_assignment' failed. Only Students can perform this action." << endl;
        }
    } 
    
    else if (action == "submit_assignment") {
        Student* student = dynamic_cast<Student*>(user);
        if (student) {
            int assignmentNumber;
            cout << "Enter assignment number to submit: ";
            cin >> assignmentNumber;
            student->submitAssignment(assignmentNumber);
            cout << "Assignment submitted successfully." << endl;
        } else {
            cout << "Action 'submit_assignment' failed. Only Students can perform this action." << endl;
        }
    } 
    
    else {
        cout << "unknown action" << endl;
    }
}

int main() {
    string userPermissions[] = {"read", "write"};
    string taPermissions[] = {"full_lab_access"};
    string professorPermissions[] = {"full_lab_access", "manage_tas"};

    bool nicoAssignments[] = {1, 0, 1, 1, 0, 1}; // 1 means assigned, 0 is submitted assignment 
    bool hazelAssignments[] = {0, 0, 1, 0, 1, 1};
    string hazelProjects[] = {"oop", "dld"};

    Student student1("nico", "s0998", 2, userPermissions, "nico@nu.edu.pk", "password123", 6, nicoAssignments);

    Student studentArr[] = {student1};

    TA ta1("hazel", "t0924", 1, taPermissions, "hazel@nu.edu.pk", "password456", 6, hazelAssignments, studentArr, 1, hazelProjects, 2);

    TA* taArray = new TA[1]{ta1};
    Professor professor1("mr brunner", "p111", 2, professorPermissions, "smith@example.com", "password789", 1, taArray);

    cout << "Displaying Student:" << endl;
    student1.display();

    cout << "Displaying TA:" << endl;
    ta1.display();

    cout << "Displaying Professor:" << endl;
    professor1.display();

    authenticateAndPerformAction(&student1, "submit_assignment");
    authenticateAndPerformAction(&ta1, "view_projects");
    authenticateAndPerformAction(&professor1, "assign_project");

    delete[] taArray;
}