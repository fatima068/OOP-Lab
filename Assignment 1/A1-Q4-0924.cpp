#include <iostream>
#include <string>
using namespace std;

class PointCard {
private:
    string studentID;
    string studentName;
    string contactInfo;
    string cardID;
    bool feePaid;
    int routeNumber;
    string dropOffStopName;
    bool attendance[31] = {false}; // arrayIndex represents day of the month

public:
    PointCard() {
        studentID = "";
        studentName = "";
        contactInfo = "";
        cardID = "";
        feePaid = false;
        routeNumber = -1;
        dropOffStopName = "";
    }

    PointCard(string studentID, string studentName, string contactInfo, string cardID, bool feePaid, int routeNumber, string dropOffStopName) {
        this->studentID = studentID;
        this->studentName = studentName;
        this->contactInfo = contactInfo;
        this->cardID = cardID;
        this->feePaid = feePaid;
        this->routeNumber = routeNumber;
        this->dropOffStopName = dropOffStopName;
    }

    string getStudentID() const {
        return studentID;
    }

    void markAttendance(int day) {
        if (day >= 1 && day <= 31) {
            attendance[day] = true;
        }
    }

    int getRouteNumber() const {
        return routeNumber;
    }

    bool getFeePaid() const {
        return feePaid;
    }

    void paySemesterFees() {
        feePaid = true;
        cout << "Semester fee paid by " << "card id: " << cardID << " std id: " << studentID << " " << studentName << endl;
    }

    void newSemester() {
        feePaid = false;
    }
};

class Stops {
private:
    string stopName;
    int studentsOnStop;
    string* studentsIDs;

public:
    Stops() {
        stopName = "";
        studentsOnStop = 0;
        studentsIDs = nullptr;
    }

    Stops(string stopName, int studentsOnStop, string* stdIDsArray) {
        this->stopName = stopName;
        this->studentsOnStop = studentsOnStop;
        studentsIDs = new string[studentsOnStop];
        for (int i = 0; i < studentsOnStop; i++) {
            studentsIDs[i] = stdIDsArray[i];
        }
    }

    string getStopName() const {
        return stopName;
    }

    void addStudentToStop(string cardid) {
        string* newStudentIDs = new string[studentsOnStop + 1];
        for (int i = 0; i < studentsOnStop; i++) {
            newStudentIDs[i] = studentsIDs[i];
        }
        newStudentIDs[studentsOnStop] = cardid;
        studentsOnStop++;
        delete[] studentsIDs;
        studentsIDs = newStudentIDs;
    }

    void removeStudentFromStop(string idToRemove) {
        if (studentsOnStop == 0) {
            cout << "Zero students on this stop!" << endl;
            return;
        }
        int indexToDelete = -1;
        for (int i = 0; i < studentsOnStop; i++) {
            if (studentsIDs[i] == idToRemove) {
                indexToDelete = i;
                break;
            }
        }
        if (indexToDelete == -1) {
            cout << "Student does not exist" << endl;
            return;
        }

        string* newStudentIDs = new string[studentsOnStop - 1];
        int j = 0;
        for (int i = 0; i < studentsOnStop; i++) {
            if (i != indexToDelete) {
                newStudentIDs[j] = studentsIDs[i];
                j++;
            }
        }
        delete[] studentsIDs;
        studentsIDs = newStudentIDs;
        studentsOnStop -= 1;
    }

    ~Stops() {
        delete[] studentsIDs;
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
    Stops** stops;
    PointCard** studentsInBus;

public:
    Bus() {
        routeNumber = -1;
        driverName = "";
        driverContact = "";
        capacity = 0;
        seatsRegistered = 0;
        totalStops = 0;
        stops = nullptr;
        studentsInBus = nullptr;
    }

    Bus(int routeNumber, string driverName, string driverContact, int capacity, int seatsRegistered, int totalStops, Stops** stopsArr, PointCard** studentsInBusArr) {
        this->routeNumber = routeNumber;
        this->driverName = driverName;
        this->driverContact = driverContact;
        this->capacity = capacity;
        this->seatsRegistered = seatsRegistered;
        this->totalStops = totalStops;

        stops = new Stops*[totalStops];
        for (int i = 0; i < totalStops; i++) {
            stops[i] = new Stops(*stopsArr[i]);
        }

        studentsInBus = new PointCard*[seatsRegistered];
        for (int i = 0; i < seatsRegistered; i++) {
            studentsInBus[i] = new PointCard(*studentsInBusArr[i]);
        }
    }

    int getRouteNumber() const {
        return routeNumber;
    }

    int getTotalStops() const {
        return totalStops;
    }

    Stops** getBusStopsArray() const {
        return stops;
    }

    int getSeatsRegistered() const {
        return seatsRegistered;
    }

    int getCapacity() const {
        return capacity;
    }

    void addNewStop(Stops* s1) {
        Stops** newStopArray = new Stops*[totalStops + 1];
        for (int i = 0; i < totalStops; i++) {
            newStopArray[i] = stops[i];
        }
        newStopArray[totalStops] = s1;
        totalStops++;
        delete[] stops;
        stops = newStopArray;
    }

    void deleteStop(string stopNameToDelete) {
        if (totalStops == 0) {
            cout << "No stops in bus" << endl;
            return;
        }
        int indexToDelete = -1;
        for (int i = 0; i < totalStops; i++) {
            if (stops[i]->getStopName() == stopNameToDelete) {
                indexToDelete = i;
                break;
            }
        }
        if (indexToDelete == -1) {
            cout << "Stop does not exist" << endl;
            return;
        }

        Stops** newStops = new Stops*[totalStops - 1];
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

    void addStudentToBus(PointCard* s1) {
        PointCard** newStudentsInBus = new PointCard*[seatsRegistered + 1];
        for (int i = 0; i < seatsRegistered; i++) {
            newStudentsInBus[i] = studentsInBus[i];
        }
        newStudentsInBus[seatsRegistered] = s1;
        seatsRegistered++;
        delete[] studentsInBus;
        studentsInBus = newStudentsInBus;
    }

    void removeStudentFromBus(string idToDelete) {
        if (seatsRegistered == 0) {
            cout << "No students in bus" << endl;
            return;
        }
        int indexToDelete = -1;
        for (int i = 0; i < seatsRegistered; i++) {
            if (studentsInBus[i]->getStudentID() == idToDelete) {
                indexToDelete = i;
                break;
            }
        }
        if (indexToDelete == -1) {
            cout << "Student not registered in bus" << endl;
            return;
        }

        PointCard** newStudentsInBus = new PointCard*[seatsRegistered - 1];
        int j = 0;
        for (int i = 0; i < seatsRegistered; i++) {
            if (i != indexToDelete) {
                newStudentsInBus[j] = studentsInBus[i];
                j++;
            }
        }
        delete studentsInBus[indexToDelete];
        delete[] studentsInBus;
        studentsInBus = newStudentsInBus;
        seatsRegistered -= 1;
    }

    ~Bus() {
        for (int i = 0; i < seatsRegistered; i++) {
            delete studentsInBus[i];
        }
        delete[] studentsInBus;
        for (int i = 0; i < totalStops; i++) {
            delete stops[i];
        }
        delete[] stops;
    }
};

class System {
private:
    Bus** allRegisteredBuses;
    PointCard** allRegisteredPointCards;
    int totalStudents, totalBuses;

public:
    System() {
        allRegisteredBuses = nullptr;
        allRegisteredPointCards = nullptr;
        totalStudents = 0;
        totalBuses = 0;
    }

    void registerNewStudent(string studentID, string studentName, string contactInfo, string cardID, bool feePaid, int routeNumber, string dropOffStopName) {
        PointCard* s1 = new PointCard(studentID, studentName, contactInfo, cardID, feePaid, routeNumber, dropOffStopName);

        // Check if the route number is valid
        bool flag = false;
        for (int i = 0; i < totalBuses; i++) {
            if (allRegisteredBuses[i]->getRouteNumber() == routeNumber) {
                flag = true;
                break;
            }
        }
        if (flag == false) {
            cout << "Incorrect route" << endl;
            delete s1;
            return;
        }

        //  is the stop name is valid
        flag = false;
        for (int i = 0; i < totalBuses; i++) {
            Stops** stops = allRegisteredBuses[i]->getBusStopsArray();
            for (int j = 0; j < allRegisteredBuses[i]->getTotalStops(); j++) {
                if (stops[j]->getStopName() == dropOffStopName) {
                    flag = true;
                    break;
                }
            }
        }
        if (flag == false) {
            cout << "Stop does not exist" << endl;
            delete s1;
            return;
        }

        // does the bus have capacity ?? 
        for (int i = 0; i < totalBuses; i++) {
            if (allRegisteredBuses[i]->getRouteNumber() == routeNumber) {
                if (allRegisteredBuses[i]->getSeatsRegistered() < allRegisteredBuses[i]->getCapacity()) {
                    allRegisteredBuses[i]->addStudentToBus(s1);
                    Stops** stops = allRegisteredBuses[i]->getBusStopsArray();
                    for (int j = 0; j < allRegisteredBuses[i]->getTotalStops(); j++) {
                        if (stops[j]->getStopName() == dropOffStopName) {
                            stops[j]->addStudentToStop(cardID);
                            break;
                        }
                    }
                    break;
                } else {
                    cout << "Bus is already full" << endl;
                    delete s1;
                    return;
                }
            }
        }

        PointCard** newAllRegisteredPointCards = new PointCard*[totalStudents + 1];
        for (int i = 0; i < totalStudents; i++) {
            newAllRegisteredPointCards[i] = allRegisteredPointCards[i];
        }
        newAllRegisteredPointCards[totalStudents] = s1;
        totalStudents++;
        delete[] allRegisteredPointCards;
        allRegisteredPointCards = newAllRegisteredPointCards;
    }

    void deleteStudent(string idToDelete) {
        int indexToDelete = -1;
        for (int i = 0; i < totalStudents; i++) {
            if (allRegisteredPointCards[i]->getStudentID() == idToDelete) {
                indexToDelete = i;
                break;
            }
        }
        if (indexToDelete == -1) {
            cout << "Student does not exist" << endl;
            return;
        }
        PointCard** newAllRegisteredPointCards = new PointCard*[totalStudents - 1];
        int j = 0;
        for (int i = 0; i < totalStudents; i++) {
            if (i != indexToDelete) {
                newAllRegisteredPointCards[j] = allRegisteredPointCards[i];
                j++;
            }
        }
        delete allRegisteredPointCards[indexToDelete];
        delete[] allRegisteredPointCards;
        allRegisteredPointCards = newAllRegisteredPointCards;
        totalStudents--;
    }

    void registerNewBus(int routeNumber, string driverName, string driverContact, int capacity, int seatsRegistered, int totalStops, Stops** stops, PointCard** studentsInBus) {
        // now see if the route number already exists
        for (int i = 0; i < totalBuses; i++) {
            if (allRegisteredBuses[i]->getRouteNumber() == routeNumber) {
                cout << "Enter a unique route number" << endl;
                return;
            }
        }
        // if all info is correct, register the bus in ur system
        Bus* b1 = new Bus(routeNumber, driverName, driverContact, capacity, seatsRegistered, totalStops, stops, studentsInBus);
        Bus** newAllRegisteredBuses = new Bus*[totalBuses + 1];
        for (int i = 0; i < totalBuses; i++) {
            newAllRegisteredBuses[i] = allRegisteredBuses[i];
        }
        newAllRegisteredBuses[totalBuses] = b1;
        totalBuses++;
        delete[] allRegisteredBuses;
        allRegisteredBuses = newAllRegisteredBuses;
    }

    void deleteBus(int routeNumToDelete) {
        int indexToDelete = -1;
        for (int i = 0; i < totalBuses; i++) {
            if (allRegisteredBuses[i]->getRouteNumber() == routeNumToDelete) {
                indexToDelete = i;
                break;
            }
        }
        if (indexToDelete == -1) {
            cout << "Route does not exist" << endl;
            return;
        }

        delete allRegisteredBuses[indexToDelete];
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
    }

    void newSemester() {
        for (int i = 0; i < totalStudents; i++) {
            allRegisteredPointCards[i]->newSemester();
        }
    }

    Bus* findBus(int routeNumber) {
        for (int i = 0; i < totalBuses; i++) {
            if (allRegisteredBuses[i]->getRouteNumber() == routeNumber) {
                return allRegisteredBuses[i];
            }
        }
        return nullptr;
    }

    PointCard* findPointCard(const string& cardID) {
        for (int i = 0; i < totalStudents; i++) {
            if (allRegisteredPointCards[i]->getStudentID() == cardID) {
                return allRegisteredPointCards[i];
            }
        }
        return nullptr;
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

    void paySemesterFee(const string& studentID) {
        PointCard* card = findPointCard(studentID);
        if (card) {
            card->paySemesterFees();
        } else {
            cout << "Student not found" << endl;
        }
    }

    ~System() {
        for (int i = 0; i < totalStudents; i++) {
            delete allRegisteredPointCards[i];
        }
        delete[] allRegisteredPointCards;

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
        cout << "Student not registered in this bus" << endl;
        return;
    }

    card.markAttendance(dayOfTheMonth);
    cout << "Attendance marked for " << card.getStudentID() << " on day " << dayOfTheMonth << endl;
}

// first register a bus, then add stops to that bus, then register students

int main() {
    System transportSystem;
    int choice;

    while (1) {
        cout << endl << "\nTransport System Menu:\n1. Register a new student\n2. Register a new bus\n3. Add a stop to a bus\n4. Mark attendance for a student\n5. Pay semester fee for a student\n6. Remove a stop from a bus\n7. Delete a student\n8. Delete a bus\n9. Start a new semester\n10. Exit\nEnter your choice: ";
        cin >> choice;

        if (choice == 10) {
            break;
        }

        switch (choice) {
            case 1: {
                string studentID, studentName, contactInfo, cardID, dropOffStopName;
                bool feePaid;
                int routeNumber;
                cout << "Enter Student ID: ";
                cin >> studentID;
                cout << "Enter Student Name: ";
                cin.ignore();
                getline(cin, studentName);
                cout << "Enter Contact Info: ";
                getline(cin, contactInfo);
                cout << "Enter Card ID: ";
                cin >> cardID;
                cout << "Has the fee been paid? (1 for Yes, 0 for No): ";
                cin >> feePaid;
                cout << "Enter Route Number: ";
                cin >> routeNumber;
                cout << "Enter Drop Off Stop Name: ";
                cin.ignore();
                getline(cin, dropOffStopName);

                transportSystem.registerNewStudent(studentID, studentName, contactInfo, cardID, feePaid, routeNumber, dropOffStopName);
                break;
            }

            case 2: {
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
                cout << "Enter Total Stops: ";
                cin >> totalStops;
                Stops** stopsArr = new Stops*[totalStops];
                for (int i = 0; i < totalStops; i++) {
                    stopsArr[i] = new Stops(); 
                }
                PointCard** studentsArr = new PointCard*[seatsRegistered];
                for (int i = 0; i < seatsRegistered; i++) {
                    studentsArr[i] = new PointCard(); 
                }
                transportSystem.registerNewBus(routeNumber, driverName, driverContact, capacity, seatsRegistered, totalStops, stopsArr, studentsArr);
                for (int i = 0; i < totalStops; i++) {
                    delete stopsArr[i];
                }
                delete[] stopsArr;
                for (int i = 0; i < seatsRegistered; i++) {
                    delete studentsArr[i];
                }
                delete[] studentsArr;
                break;
            }

            case 3: {
                int routeNumber;
                string stopName;
                cout << "Enter Route Number of the Bus: ";
                cin >> routeNumber;
                cout << "Enter Stop Name: ";
                cin.ignore();
                getline(cin, stopName);
                Bus* bus = transportSystem.findBus(routeNumber);
                if (bus) {
                    Stops* newStop = new Stops(stopName, 0, nullptr); // No students added yet
                    bus->addNewStop(newStop);
                    cout << "Stop '" << stopName << "' added to bus with route number " << routeNumber << "." << endl;
                } else {
                    cout << "Bus not found!" << endl;
                }
                break;
            }

            case 4: {
                string studentID;
                int routeNumber;
                cout << "Enter Student ID: ";
                cin >> studentID;
                cout << "Enter Route Number: ";
                cin >> routeNumber;
                Bus* bus = transportSystem.findBus(routeNumber);
                PointCard* card = transportSystem.findPointCard(studentID);
                if (bus && card) {
                    tapCard(*card, *bus);
                } else {
                    cout << "Student or Bus not found!" << endl;
                }
                break;
            }

            case 5: {
                string studentID;
                cout << "Enter Student ID: ";
                cin >> studentID;
                transportSystem.paySemesterFee(studentID);
                break;
            }

            case 6: {
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

            case 7: {
                string studentID;
                cout << "enter student ID: ";
                cin >> studentID;
                transportSystem.deleteStudent(studentID);
                break;
            }

            case 8: {
                int routeNumber;
                cout << "enter route number: ";
                cin >> routeNumber;
                transportSystem.deleteBus(routeNumber);
                break;
            }

            case 9: {
                transportSystem.newSemester();
                cout << "new semester started" << endl;
                break;
            }

            case 10:
                cout << "EXIT";
                break;

            default:
                cout << "invalid choice" << endl;
        }
    }
}