#include <iostream>
using namespace std;

class User {
    private:
    int userID;
    string name;
    string contactNum;
    string license;
    bool isRegistered;
    int vehicleRented;

    public:
    User() {
        userID = 0;
        name = "";
        contactNum = "";
        license = "";
        isRegistered = false;
        vehicleRented = 0;
    }

    void setVehicleRented(int id){
        vehicleRented = id;
    }

    int getUserID() const {
        return userID;
    }

    string getLicense() const {
        return license;
    }

    void registerUser(int userID, string name, string contactNum, string license){
        this->userID = userID;
        this->name = name;
        this->contactNum = contactNum;
        this->license = license;
        this->isRegistered = true;
    }

    void updateDetails() {
        int choice = 0;
        while(choice !=4){
            cout << "\nSELECT OPTION TO UPDATE" << endl;
            cout << "1. name\n2. contact number\n3. license type\n4. quit" << endl;
            cin >> choice;
            switch (choice){
                case 1:
                    cin.ignore();
                    cout << "enter new name: ";
                    getline(cin, name);
                    break;
                case 2:
                    cin.ignore();
                    cout << "enter new contact number: ";
                    getline(cin, contactNum);
                    break;
                case 3:
                    cin.ignore();
                    cout <<"enter updated license type: ";
                    getline(cin, license);
                    break;
                case 4:
                    cout << "exit";
                    break;
            }
        }
    }
};

class Vehicle {
    private:
    int vehicleID;
    string model;
    string name;
    string eligibility;
    double rentPricePerDay;
    bool rentalStatus;
    int rentedBy;

    public:
    Vehicle() {
        vehicleID = 0;
        model = "";
        name = "";
        eligibility = "";
        rentPricePerDay = 0.0;
        rentalStatus = false;
        rentedBy = 0;
    }

    int getVehicleID () const {
        return vehicleID;
    }

    void registerVehicle (int vehicleID, string model, string name, string eligibility, double rentPricePerDay){
        this->vehicleID = vehicleID;
        this->model = model;
        this->name = name;
        this->eligibility = eligibility;
        this->rentPricePerDay = rentPricePerDay;
        cout << "registeration successful" << endl;
    }

    void rentVehicle(User &user){
        if (rentalStatus == false && user.getLicense() == eligibility){
            rentalStatus = true;
            rentedBy = user.getUserID();
            user.setVehicleRented(vehicleID);
            cout << "Vehicle " << vehicleID << " rented by user " << user.getUserID() << endl;
            return;
        }
        if (rentalStatus == true)
            cout << "vehicle already rented by " << rentedBy << endl;
        if (eligibility != user.getLicense())
            cout << "licnse does not meet requirement" << endl;
    }

    void returnVehicle (User &user){
        rentalStatus = false;
        rentedBy = 0;
        user.setVehicleRented(0);
        cout << "vehicle " << vehicleID << " renturned by " << user.getUserID() << endl;
    }

    void displayVehicle() const {
        cout << "\nVehicle ID: " << vehicleID << "\nVehicle name: " <<  name << "\nmodel: " << model << "\neligibility: " << eligibility << "\nrent per day: " << rentPricePerDay <<"\ncurrent rental status: ";
         if (rentalStatus == false)     
            cout << "available " << endl;
         if (rentalStatus == true)     
            cout << "not available " << endl;     
    }
};

class RentalSystem {
    private:
    User** users;
    Vehicle** vehicles;
    int numUsers;
    int numVehicles;

    public:
    RentalSystem() {
        numUsers = 0;
        users = nullptr;
        numVehicles = 0;
        vehicles = nullptr;
    }

    void menu () {
        int choice = 0;
        User** newUsers = nullptr;
        Vehicle** vehicles = nullptr;
        int userid, vehicleID; 
        double rent;
        string name, contact, license, model, eligibility;
        
        while (choice != 8){
            cout << endl << endl <<"SELECT AN OPTION: " << endl;
            cout << "1. register new user\n2. update existing user's details\n3. register new vehicle\n4. delete vehicle from system\n5. rent vehicle\n6. return vehicle\n7. display all vehicles\n8. exit system" << endl;
            cin >> choice;
            switch (choice) {
                case 1: {
                    User** newUsers = new User*[numUsers+1];
                    for (int i = 0; i<numUsers; i++){
                        newUsers[i] = users[i];
                    }
                    cout << "Enter user id: ";
                    cin >> userid;
                    cout << "Enter user name: ";
                    cin >> name;
                    cout << "Enter user contact: ";
                    cin >> contact;
                    cout << "Enter user license: ";
                    cin >> license;
                    newUsers[numUsers] = new User(); 
                    newUsers[numUsers]->registerUser(userid, name, contact, license);
                    for (int i = 0; i < numUsers; i++) {
                        delete users[i];
                    }
                    delete[] users;  
                    users = newUsers;  
                    numUsers++;
                    break; 
                }

                case 2: {
                int searchID, index = -1;
                cout << "Enter id of user to update: ";
                cin >> searchID;
                    for (int i=0; i<numUsers; i++){
                        if (users[i]->getUserID() == searchID){
                            index = i;
                            break;
                        }
                    }
                    if (index == -1 ){
                        cout << "User not found" << endl;
                        continue;
                    }
                    users[index]->updateDetails();
                    break;
                }

                case 3: {
                    Vehicle** newVehicles = new Vehicle*[numVehicles+1];
                    for (int i = 0; i<numVehicles; i++){
                        newVehicles[i] = vehicles[i];
                    }
                    cout << "Enter vehicle id: ";
                    cin >> vehicleID;
                    cout << "Enter vehicle name: ";
                    cin >> name;
                    cout << "Enter vehicle model: ";
                    cin >> model;
                    cout << "Enter vehicle eligibilty: ";
                    cin >> eligibility;
                    cout << "Enter vehicle rent per day: ";
                    cin >> rent;
                    newVehicles[numVehicles] = new Vehicle(); 
                    newVehicles[numVehicles]->registerVehicle(vehicleID, model, name, eligibility, rent);
                    for (int i = 0; i < numVehicles; i++) {
                        delete vehicles[i];
                    }
                    delete[] vehicles;  
                    vehicles = newVehicles;  
                    numVehicles++;
                    break; 
                }

                case 4: {
                    cout << "Enter vehicle id: ";
                    cin >> vehicleID;
                    int index = -1;
                    for (int i = 0; i < numVehicles; i++) {
                        if (vehicles[i]->getVehicleID() == vehicleID) {
                            index = i;
                            break;
                        }
                    }                
                    if (index == -1) {
                        cout << "Vehicle not found." << endl;
                        break;
                    }

                    delete vehicles[index];
                    for (int i = index; i < numVehicles - 1; i++) {
                        vehicles[i] = vehicles[i + 1];
                    }
                    numVehicles--;
                    cout << "Vehicle " << vehicleID << " deleted successfully." << endl;
                    break; 
                }

                case 5:{
                    int index = -1;
                    cout << "enter id of user: ";
                    cin >> userid;
                    for (int i = 0; i<numUsers; i++){
                        if (users[i]->getUserID() == userid){
                            index = i;
                            break;
                        }
                    }
                    if (index == -1) {
                        cout << "User not found" << endl;
                        continue;
                    }
                    cout << "enter id of vehicle: ";
                    cin >> vehicleID;
                    for (int i = 0; i<numVehicles; i++){
                        if (vehicles[i]->getVehicleID() == vehicleID){
                            vehicles[i]->rentVehicle(*users[index]);
                        }
                    }
                    break;
                }

                case 6: {
                    int index = -1;
                    cout << "enter id of user: ";
                    cin >> userid;
                    for (int i = 0; i<numUsers; i++){
                        if (users[i]->getUserID() == userid){
                            index = i;
                            break;
                        }
                    }
                    if (index == -1) {
                        cout << "User not found" << endl;
                        continue;
                    }
                    cout << "enter id of vehicle: ";
                    cin >> vehicleID;
                    for (int i = 0; i<numVehicles; i++){
                        if (vehicles[i]->getVehicleID() == vehicleID){
                            vehicles[i]->returnVehicle(*users[index]);
                        }
                    }
                    break;
                }

                case 7:
                    cout << endl << "Displaying all vehicles: ";
                    for (int i = 0; i<numVehicles; i++){
                        vehicles[i]->displayVehicle();
                    }
                    break;

                case 8:
                    cout << "EXIT" ;
                    break;
            }
        }
    }

    ~RentalSystem() {
        for (int i=0; i<numUsers; i++){
            delete users[i];
        }
        delete[] users;
        for (int i=0; i<numVehicles; i++){
            delete vehicles[i];
        }
        delete[] vehicles;
    }
};

int main () {
    RentalSystem system;
    system.menu();
}