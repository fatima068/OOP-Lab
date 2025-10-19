#include <iostream>
#include <string>
using namespace std;

class Student;

class Skill{
    private:
    int skillID;
    string skillName;
    string description;
    
    public:
    Skill(){
        skillID = 0;
        skillName = "";
        description = "";
    }

    Skill(int id, string n, string d){
        skillID = id;
        skillName = n;
        description = d;
    }

    int getSkillID(){
        return skillID;
    }
    
    void showSkillDetails () const {
        cout << "Skill ID: " << skillID << "\nSkill Name: " << skillName << "\nDescription: " << description << endl;
    }

    void updateSkillDescription (string newDescription){
        description = newDescription;
        cout << "description updated for " << skillName << endl;
    }
    
    ~Skill(){}
};

class Sport{
    private:
    int sportID;
    string name;
    string description;
    int numOfSkills;
    int maxSkills;
    Skill* requiredSkills;

    public:
    Sport(){
        sportID = 0;
        name = "";
        description = "";
        numOfSkills = 0;
        maxSkills = 0;
        requiredSkills = nullptr;
    }

    Sport(int id, string n, string d, int max){
        sportID = id;
        name = n;
        description = d;
        numOfSkills = 0;
        maxSkills = max;
        requiredSkills = new Skill[maxSkills];
    }

    string getName() const {
        return name;
    }

    int getID() const {
        return sportID;
    }

    string getDescription() const {
        return description;
    }

    void addSkill(Skill s){
        if(numOfSkills < maxSkills){
            requiredSkills[numOfSkills] = Skill(s);
            numOfSkills++;
            cout << "Skill added " << endl;
            return;
        }
        cout <<"max num of required skills reachd" << endl;
    }

    void removeSkill(Skill s){
        int indexToRemove = -1;
        for (int i=0; i<maxSkills; i++){
            if (requiredSkills[i].getSkillID() == s.getSkillID()){
                indexToRemove = i;
                break;
            }
        }
        if (indexToRemove == -1){
            cout << "skill to remove not found" << endl;
            return;
        }
        for (int i=indexToRemove+1; i<numOfSkills; i++){
            requiredSkills[i-1] = requiredSkills[i];
        }
        numOfSkills--;
        cout << "skill removed" << endl;
    }

    ~Sport() {
        delete[] requiredSkills;
    }
};

class Mentor{
    private:
    int mentorID;
    string name;
    Sport* sportExpertise[5];
    int maxLearners;
    int* assignedLearners; //stores learner id numbers

    public:
    Mentor() {
        mentorID = 0;
        name = "";
        for (int i=0; i<5; i++){
            sportExpertise[i] = nullptr;
        }
        maxLearners=0;
        assignedLearners = nullptr;
    }

    Mentor(int id, string n, int l){
        mentorID = id;
        name = n;
        maxLearners = l;
        for (int i = 0; i < 5; i++)
            sportExpertise[i] = nullptr;
        assignedLearners = new int[maxLearners];
        for (int i = 0; i<maxLearners; i++){
            assignedLearners[i]=0;
        }
    }

    int getMentorID() {
        return mentorID;
    }

    string getMentorName() {
        return name;
    }

    void displaySportsExpertise(){
        for (int i = 0; i<5; i++){
            if(sportExpertise[i] != nullptr){
                cout << "Sport expertise " << i+1 << ": " << sportExpertise[i]->getID() << " " << sportExpertise[i]->getName() << ": " << sportExpertise[i]->getDescription() << endl;
            }
        } 
    }

    void viewLearners() const {
        for (int i = 0; i<maxLearners; i++){
            if (assignedLearners[i] != 0){
                cout << "Learner ID: " << assignedLearners[i] << endl;
            }
        }
    }

    void provideGuidance(){
        if (assignedLearners[0] == 0) {
            cout << "No learners assigned yet." << endl;
            return;
        }
        cout << "providinf guidance " << endl;        
        for (int i = 0; i < maxLearners; i++) {
            if (assignedLearners[i] != 0){
                cout << "- Student ID: " << assignedLearners[i] << ":\n";
                for (int j = 0; j < 5; j++) {
                    if (sportExpertise[j] != nullptr) {
                        cout << "  -> Improve skills in " << sportExpertise[j]->getName() << endl;
                    }
                }
            }
        }
    }

    void removeLearner(Student& s);
    void assignLearner(Student& s);

    ~Mentor() {
        for (int i = 0; i < 5; i++) {
            sportExpertise[i] = nullptr;
        }
        delete[] assignedLearners;
    }
};


class Student{
    private:
    int studentID;
    string name;
    int age;
    int maxSportInterests;
    int currentInterests;
    Sport* sportsInterests;
    Mentor* mentorAssigned;
    
    public:
    Student(){
        studentID = 0;
        name = "";
        age = 0;
        maxSportInterests = 5;
        currentInterests = 0;
        sportsInterests = nullptr;
        mentorAssigned = nullptr;
    }

    Student(int id, string n, int a, int numInt){
        studentID = id;
        name = n;
        age = a;
        maxSportInterests = numInt;
        mentorAssigned = nullptr;
        sportsInterests = new Sport[maxSportInterests];
    }
    
    int getStudentID(){
        return studentID;
    }

    void registerForMentorship(Mentor& m){
        mentorAssigned = &m;
        m.assignLearner(*this);
    }

    void viewMentorDetails () const {
        if(mentorAssigned == nullptr){
            cout << "no mentor assigned " << endl;
            return;
        }
        cout << "Mentor ID: " << mentorAssigned->getMentorID() << "\nMentor name : " << mentorAssigned->getMentorName() << endl;
        mentorAssigned->displaySportsExpertise();
           
    }
    
    void updateSportsInterests (Sport& s){
        if(currentInterests < maxSportInterests){
            sportsInterests[currentInterests] = s;
            currentInterests++;
            return;
        }
        cout << "max num of interests added" << endl;
    }

    ~Student() {
        delete[] sportsInterests;
        mentorAssigned = nullptr;
    }
};


void Mentor::removeLearner(Student& s) {
    for (int i = 0; i < maxLearners; i++) {
        if (assignedLearners[i] == s.getStudentID()) {
            assignedLearners[i] = 0; 
            cout << "Learner with ID " << s.getStudentID() << " removed" << endl;
            return;
        }
    }
    cout << "Learner not found" << endl;
}

void Mentor::assignLearner(Student& s) {
    for (int i = 0; i < maxLearners; i++) {
        if (assignedLearners[i] == 0) {
            assignedLearners[i] = s.getStudentID(); 
            cout << "Student with ID " << s.getStudentID() << " assigned to mentor" << endl;
            return;
        }
    }
    cout << "Mentor has reached max number of learners" << endl;
}

int main() {
    Skill skill1(1, "Shooting", "Improves shooting accuracy");
    Skill skill2(2, "Dribbling", "Improves ball control while moving");
    Skill skill3(3, "Passing", "Improves accuracy and speed of passing");

    Sport sport1(1, "Basketball", "A team sport involving shooting a ball into a hoop", 3);
    sport1.addSkill(skill1);
    sport1.addSkill(skill2);
    sport1.addSkill(skill3);

    Mentor mentor1(1, "mickey arthur", 3); 
    
    Student student1(101, "babar", 20, 3);
    Student student2(102, "fakhar", 22, 3);
    Student student3(103, "haris", 21, 3);

    student1.registerForMentorship(mentor1);
    student2.registerForMentorship(mentor1);
    // student3.registerForMentorship(mentor1);

    mentor1.assignLearner(student3);
    mentor1.assignLearner(student1);
    mentor1.assignLearner(student2);

    cout << "\nMentor " << mentor1.getMentorName() << " has the following learners:" << endl;
    mentor1.viewLearners();

    cout << "\nMentor providing guidance to learners:" << endl;
    mentor1.provideGuidance();

    mentor1.removeLearner(student1);

    cout << "\nMentor " << mentor1.getMentorName() << " has the following learners after removal:" << endl;
    mentor1.viewLearners();
}
