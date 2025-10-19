#include <iostream>
#include <string>
using namespace std;
 
class System;

// constructor chaining, polymorphism, op overloading, try making friend functions 

class PointCard {
protected:
    string userID; 
    string userName;
    string contactInfo;
    bool feePaid;
    int routeNumber;
    string dropOffStopName;
    char userType; // teacher(T), student(S), staff member(M)
    bool attendance[31] = {false}; // arrayIndex represents day of the month

public:
    PointCard() : userID(""), userName(""), contactInfo(""), feePaid(false), routeNumber(-1), dropOffStopName(""), userType(' ') {}

    PointCard(string userID, string userName, string contactInfo, bool feePaid, int routeNumber, string dropOffStopName, char userType) : userID(userID), userName(userName), contactInfo(contactInfo), feePaid(feePaid), routeNumber(routeNumber), dropOffStopName(dropOffStopName), userType(userType) {}

    void markAttendance(int day) {
        if (day >= 1 && day <= 31) {
            attendance[day] = true;
        }
    }

    bool getFeePaid() const {
        return feePaid;
    }

    int getRouteNumber() const {
        return routeNumber;
    }

    string getUserID() const {
        return userID;
    }

    void paySemesterFees() {
        feePaid = true;
        cout << "Semester fee paid by " << userID << " " << userName << endl;
    }

    virtual void newMonth() {}

    virtual void newSemester() {}

    virtual void display() {
        cout << "User ID: " << userID << ", Name: " << userName << ", Contact Info: " << contactInfo << ", Route Number: " << routeNumber << ", Drop Off Stop: " << dropOffStopName << ", Fee Paid: " << (feePaid ? "Yes" : "No") << endl;
    }

    friend ostream& operator<<(ostream& os, const PointCard& p1) {
        os << "User ID: " << p1.userID << ", Name: " << p1.userName << ", Contact Info: " << p1.contactInfo << ", Route Number: " << p1.routeNumber << ", Drop Off Stop: " << p1.dropOffStopName << ", Fee Paid: " << (p1.feePaid ? "Yes" : "No") << endl;
        return os;
    }

    friend class System;
    friend class Stop;
    friend class Bus;
};

class StudentPointCard : public PointCard {
    float semesterFees;
    
    public:
    StudentPointCard() : semesterFees(0), PointCard() {}

    StudentPointCard(string userID, string userName, string contactInfo, bool feePaid, int routeNumber, string dropOffStopName, float semesterFees) : PointCard(userID, userName, contactInfo, feePaid, routeNumber, dropOffStopName, 'S'), semesterFees(semesterFees) {}

    void display() override {
        cout << "Student Point Card Details" << endl;
        PointCard::display();
        cout << "Semester Fees: " << semesterFees << endl;
    }

    void newMonth() override {}

    void newSemester() override {
        feePaid = false;
    }
};

class TeacherPointCard : public PointCard {
    int seatNumAssigned;
    float monthlyFees;

    public:
    TeacherPointCard() : PointCard(), seatNumAssigned(0), monthlyFees(0) {}

    TeacherPointCard(string userID, string userName, string contactInfo, bool feePaid, int routeNumber, string dropOffStopName, int seatNumAssigned, float monthlyFees) : monthlyFees(monthlyFees), seatNumAssigned(seatNumAssigned), PointCard(userID, userName, contactInfo, feePaid, routeNumber, dropOffStopName, 'T') {}

    void display() override {
        cout << "Teacher Point Card Details" << endl;
        PointCard::display();
        cout << "Seat Number Assigned: " << seatNumAssigned << ", Monthly Fees: " << monthlyFees << endl;
    }

    void newMonth() override {
        feePaid = false;
    }

    void newSemester() override {}
};

class StaffMemberPointCard : public PointCard {
    float monthlyFees;

    public:
    StaffMemberPointCard() : PointCard(), monthlyFees(0) {}

    StaffMemberPointCard(string userID, string userName, string contactInfo, bool feePaid, int routeNumber, string dropOffStopName, float monthlyFees) : monthlyFees(monthlyFees), PointCard(userID, userName, contactInfo, feePaid, routeNumber, dropOffStopName, 'M') {}

    void display() override {
        cout << "Staff Member Point Card Details" << endl;
        PointCard::display();
        cout << "Monthly Fees: " << monthlyFees << endl;
    }

    void newMonth() override {
        feePaid = false;
    }

    void newSemester() override {}
};

// asssume that pickup and dropoff stop is same for everyone
class Stop {
    protected:
    string stopName;
    PointCard** peopleOnStop;
    int totalPeopleOnStop;

    public:
    Stop() : stopName(""), totalPeopleOnStop(0), peopleOnStop(nullptr) {}

    Stop(string stopName) : stopName(stopName), totalPeopleOnStop(0), peopleOnStop(nullptr) {}

    void addPersonToStop(PointCard* c1) {
        PointCard** newPeopleOnStop = new PointCard*[totalPeopleOnStop + 1];
        for (int i = 0; i < totalPeopleOnStop; i++) {
            newPeopleOnStop[i] = peopleOnStop[i];
        }
        newPeopleOnStop[totalPeopleOnStop] = c1;
        totalPeopleOnStop++;
        delete[] peopleOnStop;
        peopleOnStop = newPeopleOnStop;
    }

    void removeStudentFromStop(string idToRemove) {
        if (totalPeopleOnStop == 0) {
            cout << "zero people on this stop" << endl;
            return;
        }
        int indexToDelete = -1;
        for (int i = 0; i < totalPeopleOnStop; i++) {
            if (peopleOnStop[i]->userID == idToRemove) {
                indexToDelete = i;
                break;
            }
        }
        if (indexToDelete == -1) {
            cout << "user does not exist" << endl;
            return;
        }

        PointCard** newPeopleOnStop = new PointCard*[totalPeopleOnStop - 1];
        int j = 0;
        for (int i = 0; i < totalPeopleOnStop; i++) {
            if (i != indexToDelete) {
                newPeopleOnStop[j] = peopleOnStop[i];
                j++;
            }
        }
        delete[] peopleOnStop;
        peopleOnStop = newPeopleOnStop;
        totalPeopleOnStop -= 1;
    }

    friend ostream& operator<<(ostream& os, const Stop& s1) {
        os << "Stop Name: " << s1.stopName << endl;
        os << "Total People on Stop: " << s1.totalPeopleOnStop << endl;
        return os;
    }

    friend class System;
    friend class Bus;

    ~Stop() {
        for (int i = 0; i < totalPeopleOnStop; i++) {
            delete peopleOnStop[i];
        }
        delete[] peopleOnStop;
    }
};

class Bus {
    private:
        int routeNumber;
        string driverName;
        string driverContact;
        int capacity;
        int seatsRegistered;
        int totalStops;
        Stop** stops;
        PointCard** peopleInBus;

        public:
        Bus() : routeNumber(-1), driverName(""), driverContact(""), capacity(0), seatsRegistered(0), totalStops(0), stops(nullptr), peopleInBus(nullptr) {}


        // initially stops in bus are 0, bus register hote we stops add nai hongey. wo alag se function call hoga
        Bus(int routeNumber, string driverName, string driverContact, int capacity, int seatsRegistered) : routeNumber(routeNumber), driverName(driverName), driverContact(driverContact), capacity(capacity), seatsRegistered(seatsRegistered), totalStops(0), stops(nullptr), peopleInBus(nullptr) {}

        int getRouteNumber() const {
            return routeNumber;
        }   

        void addNewStop(Stop* c1) {
            Stop** newStopArray = new Stop*[totalStops + 1];
            for (int i = 0; i < totalStops; i++) {
                newStopArray[i] = stops[i];
            }
            newStopArray[totalStops] = c1;
            totalStops++;
            delete[] stops;
            stops = newStopArray;
        }

        void deleteStop(string stopNameToDelete) {
            if (totalStops == 0) {
                cout << "no stops added to this bus" << endl;
                return;
            }
            int indexToDelete = -1;
            for (int i = 0; i < totalStops; i++) {
                if (stops[i]->stopName == stopNameToDelete) {
                    indexToDelete = i;
                    break;
                }
            }
            if (indexToDelete == -1) {
                cout << "Stop does not exist" << endl;
                return;
            }

            Stop** newStops = new Stop*[totalStops - 1];
            int j = 0;
            for (int i = 0; i < totalStops; i++) {
                if (i != indexToDelete) {
                    newStops[j] = stops[i];
                    j++;
                }
            }
            delete stops[indexToDelete];
            delete[] stops;
            stops = newStops;
            totalStops -= 1; 
        }  

    void addPersonToBus(PointCard* c1) {
        PointCard** newPeopleInBus = new PointCard*[seatsRegistered + 1];
        
        if (peopleInBus != nullptr) {
            for (int i = 0; i < seatsRegistered; i++) {
                newPeopleInBus[i] = peopleInBus[i];
            }
        }
        
        newPeopleInBus[seatsRegistered] = c1;
        seatsRegistered++;
        if (peopleInBus != nullptr) {
            delete[] peopleInBus; }
        peopleInBus = newPeopleInBus;
    }

    void removePersonFromBus(string idToDelete) {
        if (seatsRegistered == 0) {
            cout << "no registered seats in bus to remove" << endl;
            return;
        }
        int indexToDelete = -1;
        for (int i = 0; i < seatsRegistered; i++) {
            if (peopleInBus[i]->userID == idToDelete) {
                indexToDelete = i;
                break;
            }
        }
        if (indexToDelete == -1) {
            cout << "user "<< idToDelete << " is not registered in bus" << endl;
            return;
        }

        PointCard** newPeopleInBus = new PointCard*[seatsRegistered - 1];
        int j = 0;
        for (int i = 0; i < seatsRegistered; i++) {
            if (i != indexToDelete) {
                newPeopleInBus[j] = peopleInBus[i];
                j++;
            }
        }
        delete peopleInBus[indexToDelete];
        delete[] peopleInBus;
        peopleInBus = newPeopleInBus;
        seatsRegistered -= 1;
    } 

    friend ostream& operator<<(ostream& os, const Bus& b1) {
        os << "Route Number: " << b1.routeNumber << endl;
        os << "Driver Name: " << b1.driverName << endl;
        os << "Driver Contact: " << b1.driverContact << endl;
        os << "Capacity: " << b1.capacity << endl;
        os << "Seats Registered: " << b1.seatsRegistered << endl;
        os << "Total Stops: " << b1.totalStops << endl;
        for (int i = 0; i < b1.totalStops; i++) {
            os << *(b1.stops[i]);
        }
        os << "People in Bus: " << endl;
        for (int i = 0; i < b1.seatsRegistered; i++) {
            os << *(b1.peopleInBus[i]);
        }
        return os;
    }

    friend class System;

    ~Bus() {
        for (int i = 0; i < seatsRegistered; i++) {
            delete peopleInBus[i];
        }
        delete[] peopleInBus;
        for (int i = 0; i < totalStops; i++) {
            delete stops[i];
        }
        delete[] stops;
    }
};

class System {
    private:
    PointCard** allRegisteredUsers;
    Bus** allRegisteredBuses;
    int totalUsers, totalBuses;

    public:
    System() : allRegisteredUsers(nullptr), allRegisteredBuses(nullptr), totalUsers(0), totalBuses(0) {}

    void registerNewUser(char userType, string userID, string userName, string contactInfo, bool feePaid, int routeNumber, string dropOffStopName) {
        // Check if the route number is valid
        bool flag = false;
        for (int i = 0; i < totalBuses; i++) {
            if (allRegisteredBuses[i]->routeNumber== routeNumber) {
                flag = true;
                break;
            }
        }
        if (flag == false) {
            cout << "Incorrect route" << endl;
            return;
        }

         //  check if the stop name is valid
        flag = false;
        for (int i = 0; i < totalBuses; i++) {
            for (int j = 0; j < allRegisteredBuses[i]->totalStops; j++) {
                if (allRegisteredBuses[i]->stops[j]->stopName == dropOffStopName) {
                    flag = true;
                    break;
                }
            }
        }
        if (flag == false) {
            cout << "stop does not exist" << endl;
            return;
        }

        PointCard* c1;
        // does the bus have capacity ?? if yes, then take input for child class unique attributes and create a pointer to an object, to add to the bus
        for (int i = 0; i < totalBuses; i++) {
            if (allRegisteredBuses[i]->routeNumber == routeNumber) {
                if (allRegisteredBuses[i]->seatsRegistered < allRegisteredBuses[i]->capacity) { // yahan pe verify hogya ke bus mei capacity hai ya noi   

                    if (userType == 'S' || userType == 's') {
                        float semesterFees;
                        cout << "enter semester fees for student: ";
                        cin >> semesterFees;
                        c1 = new StudentPointCard(userID, userName, contactInfo, feePaid, routeNumber, dropOffStopName, semesterFees);
                        allRegisteredBuses[i]->addPersonToBus(c1);
                        // now add person to the system class array         
                        PointCard** newAllRegisteredUsers = new PointCard*[totalUsers + 1];
                        for (int i = 0; i < totalUsers; i++) {
                            newAllRegisteredUsers[i] = allRegisteredUsers[i];
                        }
                        newAllRegisteredUsers[totalUsers] = c1;
                        totalUsers++;
                        delete[] allRegisteredUsers;
                        allRegisteredUsers = newAllRegisteredUsers;
                        cout << "student " << userID << " registered to route " << routeNumber << endl;
                    }

                    else if (userType == 'T' || userType == 't') {
                        int seatNumAssigned;
                        float monthlyFees;
                        cout << "enter seat number for teacher: ";
                        cin >> seatNumAssigned;
                        cout << "enter monthly fees for teacher: ";
                        cin >> monthlyFees;
                        c1 = new TeacherPointCard(userID, userName, contactInfo, feePaid, routeNumber, dropOffStopName, seatNumAssigned, monthlyFees);
                        allRegisteredBuses[i]->addPersonToBus(c1);
                        // now add person to the system class array         
                        PointCard** newAllRegisteredUsers = new PointCard*[totalUsers + 1];
                        for (int i = 0; i < totalUsers; i++) {
                            newAllRegisteredUsers[i] = allRegisteredUsers[i];
                        }
                        newAllRegisteredUsers[totalUsers] = c1;
                        totalUsers++;
                        delete[] allRegisteredUsers;
                        allRegisteredUsers = newAllRegisteredUsers;
                        cout << "teahcer " << userID << " registered to route " << routeNumber << endl;
                    }

                    else if (userType == 'M' || userType == 'm') {
                        float monthlyFees;
                        cout << "enter monthly fees for staff member: ";
                        cin >> monthlyFees;
                        c1 = new StaffMemberPointCard(userID, userName, contactInfo, feePaid, routeNumber, dropOffStopName, monthlyFees);
                        allRegisteredBuses[i]->addPersonToBus(c1);
                        // now add person to the system class array         
                        PointCard** newAllRegisteredUsers = new PointCard*[totalUsers + 1];
                        for (int i = 0; i < totalUsers; i++) {
                            newAllRegisteredUsers[i] = allRegisteredUsers[i];
                        }
                        newAllRegisteredUsers[totalUsers] = c1;
                        totalUsers++;
                        delete[] allRegisteredUsers;
                        allRegisteredUsers = newAllRegisteredUsers;
                        cout << "staff member " << userID << " registered to route " << routeNumber << endl;
                    }

                } else {
                    cout << "bus does not have capacity" << endl;
                    delete c1;
                    return;
                }
            }
        }
    }

    void newMonth() {
        for (int i =0; i<totalUsers; i++) {
            allRegisteredUsers[i]->newMonth();
        }
    }

    void newSemester() {
        for (int i =0; i<totalUsers; i++) {
            allRegisteredUsers[i]->newSemester();
        }
    }

    void registerNewBus(int routeNumber, string driverName, string driverContact, int capacity, int seatsRegistered) {
        // now see if the route number already exists
        for (int i = 0; i < totalBuses; i++) {
            if (allRegisteredBuses[i]->routeNumber == routeNumber) {
                cout << "Enter a unique route number" << endl;
                return;
            }
        }

        // if all info is correct, register the bus in ur system
        Bus* b1 = new Bus(routeNumber, driverName, driverContact, capacity, seatsRegistered);
        Bus** newAllRegisteredBuses = new Bus*[totalBuses + 1];
        for (int i = 0; i < totalBuses; i++) {
            newAllRegisteredBuses[i] = allRegisteredBuses[i];
        }
        newAllRegisteredBuses[totalBuses] = b1;
        totalBuses++;
        delete[] allRegisteredBuses;
        allRegisteredBuses = newAllRegisteredBuses;
        cout << "Route number " << routeNumber << " registered successfully" << endl;
    }

    void deleteUser(string idToDelete) {
        int indexToDelete = -1;
        for (int i = 0; i < totalUsers; i++) {
            if (allRegisteredUsers[i]->userID == idToDelete) {
                indexToDelete = i;
                break;
            }
        }
        if (indexToDelete == -1) {
            cout << "user does not exist" << endl;
            return;
        }
        PointCard** newallRegisteredUsers = new PointCard*[totalUsers - 1];
        int j = 0;
        for (int i = 0; i < totalUsers; i++) {
            if (i != indexToDelete) {
                newallRegisteredUsers[j] = allRegisteredUsers[i];
                j++;
            }
        }
        delete allRegisteredUsers[indexToDelete];
        delete[] allRegisteredUsers;
        allRegisteredUsers = newallRegisteredUsers;
        totalUsers--;
    }
    
    void deleteBus(int routeNumToDelete) {
        int indexToDelete = -1;
        for (int i = 0; i < totalBuses; i++) {
            if (allRegisteredBuses[i]->routeNumber == routeNumToDelete) {
                indexToDelete = i;
                break;
            }
        }
        if (indexToDelete == -1) {
            cout << "Route does not exist" << endl;
            return;
        }

        cout << "index to delete: " << indexToDelete << endl;

        Bus** newAllRegisteredBuses = new Bus*[totalBuses - 1];
        int j = 0;
        for (int i = 0; i < totalBuses; i++) {
            if (i != indexToDelete) {
                newAllRegisteredBuses[j] = allRegisteredBuses[i];
                j++;
            }
        }
        delete[] allRegisteredBuses;
        allRegisteredBuses = newAllRegisteredBuses;
        totalBuses--;
        cout << "route " << routeNumToDelete << " has been deleted" << endl;
    }

    void removeStopFromBus(int routeNumber, string stopName) {
        Bus* bus = findBus(routeNumber);
        if (bus) {
            bus->deleteStop(stopName);
            cout << "Stop removed: " << stopName << endl;
        } else {
            cout << "Bus not found" << endl;
        }
    }

    void addStopToBus(Stop* stopToAdd, int routeNumber) {
        Bus* b1 = findBus(routeNumber);
        if (b1 == nullptr) {
            cout << "route number not found" << endl;
            return;
        }
        b1->addNewStop(stopToAdd);
        cout << "Stop " << stopToAdd->stopName << " added to route " << routeNumber << endl;
    }

    // tap card (will be global i think ?)

    Bus* findBus(int routeNumber) {
        for (int i = 0; i < totalBuses; i++) {
            if (allRegisteredBuses[i]->routeNumber == routeNumber) {
                return allRegisteredBuses[i];
            }
        }
        return nullptr;
    }


    PointCard* findPointCard(const string& cardID) {
        for (int i = 0; i < totalUsers; i++) {
            if (allRegisteredUsers[i]->userID == cardID) {
                return allRegisteredUsers[i];
            }
        }
        return nullptr;
    }

    void paySemesterFee(const string& id) {
        PointCard* card = findPointCard(id);
        if (card) {
            card->paySemesterFees();
        } else {
            cout << "user not found" << endl;
        }
    }

    void displayAllPoints() const {
        for (int i = 0; i < totalBuses; i++) {
            cout << *allRegisteredBuses[i];
            cout << endl;
        }
    }

    ~System() {
        for (int i = 0; i < totalUsers; i++) {
            delete allRegisteredUsers[i];
        }
        delete[] allRegisteredUsers;

        for (int i = 0; i < totalBuses; i++) {
            delete allRegisteredBuses[i];
        }
        delete[] allRegisteredBuses;
    }
};

static int dayOfTheMonth = 1;

void tapCard(PointCard& card, Bus& bus) {
    if (dayOfTheMonth < 1 || dayOfTheMonth > 31) {
        cout << "Invalid day of the month" << endl;
        return;
    }

    if (!card.getFeePaid()) {
        cout << "Semester fee not paid" << endl;
        return;
    }

    if (card.getRouteNumber() != bus.getRouteNumber()) {
        cout << "user not registered in this bus" << endl;
        return;
    }

    card.markAttendance(dayOfTheMonth);
    cout << "Attendance marked for " << card.getUserID() << " on day " << dayOfTheMonth << endl;
}

int main () {
    System transportSystem;
    int choice;

    while (1) {
        cout << endl << "\nTransport System Menu:\n0. Register a new bus\n1. Add a stop to a bus\n2. Register a new user\n3. Tap card for a user\n4. Pay fee for a user\n5. Remove a stop from a bus\n6. Delete a user\n7. Delete a bus\n8. Start a new semester\n9. Start a new month\n10. Display All Points\n11. Exit\nEnter your choice: ";

        cin >> choice;

        if (choice == 11) {
            cout << "EXIT";
            break;
        }

        switch (choice) {
            
            case 0: { 
                int routeNumber, capacity, seatsRegistered, totalStops;
                string driverName, driverContact;

                cout << "Enter Route Number: ";
                cin >> routeNumber;
                cout << "Enter Driver Name: "; 
                cin.ignore();
                getline(cin, driverName);
                cout << "Enter Driver Contact: ";
                getline(cin, driverContact);
                cout << "Enter Bus Capacity: ";
                cin >> capacity;
                cout << "Enter Seats Registered: ";
                cin >> seatsRegistered;
                transportSystem.registerNewBus(routeNumber, driverName, driverContact, capacity, seatsRegistered);
                break;
            }

            case 1: { 
                string stopName;
                int routeNum;
                cout << "Enter route num to add stop to: ";
                cin >> routeNum;
                cout << "Enter stop name: ";
                cin.ignore();
                getline(cin, stopName);
                Stop* s1 = new Stop(stopName);
                transportSystem.addStopToBus(s1, routeNum);
                break;
            }

            case 2: {
                string studentID, userName, contactInfo, cardID, dropOffStopName;
                char userType;
                bool feePaid;
                int routeNumber;
                cout << "Enter User ID: ";
                cin >> studentID;
                cout << "Enter User Name: ";
                cin.ignore();
                getline(cin, userName);
                cout << "Enter Contact Info: ";
                getline(cin, contactInfo);
                cout << "Enter Card ID: ";
                cin >> cardID;
                cout << "Enter user type (S, T or M): ";
                cin >> userType;
                cout << "Has the fee been paid? (1 for Yes, 0 for No): ";
                cin >> feePaid;
                cout << "Enter Route Number: ";
                cin >> routeNumber;
                cout << "Enter Drop Off Stop Name: ";
                cin.ignore();
                getline(cin, dropOffStopName);

                transportSystem.registerNewUser(userType, studentID, userName, contactInfo, feePaid, routeNumber, dropOffStopName);
                break;
            }

            case 3: {
                string studentID;
                int routeNumber;
                cout << "Enter User ID: ";
                cin >> studentID;
                cout << "Enter Route Number: ";
                cin >> routeNumber;
                Bus* bus = transportSystem.findBus(routeNumber);
                PointCard* card = transportSystem.findPointCard(studentID);
                if (bus && card) {
                    tapCard(*card, *bus);
                } else {
                    cout << "User or Bus not found!" << endl;
                }
                break;
            }

            case 4: { 
                string studentID;
                cout << "Enter User ID: ";
                cin >> studentID;
                transportSystem.paySemesterFee(studentID);
                break;
            }

            case 5: { 
                int routeNumber;
                string stopName;
                cout << "enter route number: ";
                cin >> routeNumber;
                cout << "Enter stop name: ";
                cin.ignore();
                getline(cin, stopName);
                transportSystem.removeStopFromBus(routeNumber, stopName);
                break;
            }

            case 6: { 
                string studentID;
                cout << "enter User ID: ";
                cin >> studentID;
                transportSystem.deleteUser(studentID);
                break;
            }

            case 7: { 
                int routeNumber;
                cout << "enter route number: ";
                cin >> routeNumber;
                transportSystem.deleteBus(routeNumber);
                break;
            }

            case 8: { 
                transportSystem.newSemester();
                cout << "new semester started" << endl;
                break;
            }

            case 9: {
                transportSystem.newMonth();
                cout << "new month started" << endl;
                break;
            }

            case 10: {
                transportSystem.displayAllPoints();
                break;
            }

            default:
                cout << "invalid choice" << endl;
        }
    }
}