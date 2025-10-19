#include <iostream>
#include <string>
using namespace std;

class Vehicle {
protected:
    string vehicleID;
    float speed;    // in km/h
    float capacity; // in kg
    static int totalDeliveries;

public:
    Vehicle(string id, float speed, float capacity) : vehicleID(id), speed(speed), capacity(capacity) {
        totalDeliveries++;
    }

    Vehicle() : vehicleID(""), speed(0.0), capacity(0.0) {}

    virtual void move() {
        cout << vehicleID << " is moving" << endl;
    }

    virtual void calculateRoute(float distance) {
        cout << vehicleID << " is calculating route for " << distance << " km" << endl;
    }

    virtual float estimateTime(float distance) {
        return distance / speed; 
    }

    virtual void deliver(int packageID) {
        cout << vehicleID << ": basic delivery for package " << packageID << endl;
    }

    virtual void deliver(int packageID, string urgency) {
        cout << vehicleID << ": urgent delivery for package " << packageID << endl;
    }

    virtual void command(const string& cmd, int packageID) {
        if (cmd == "deliver") {
            deliver(packageID);
        } 
        else {
            cout << "unknown command: " << cmd << endl;
        }
    }

    virtual void command(const string& cmd, int packageID, string urgency) {
        if (cmd == "deliver") {
            deliver(packageID, urgency);
        } 
        else {
            cout << "unknown command: " << cmd << endl;
        }
    }

    static int getTotalDeliveries() {
        return totalDeliveries;
    }

    friend bool AIconflictResolution(const Vehicle& a, const Vehicle& b, float distance, float weight);

    bool operator==(const Vehicle& other) {
        return (speed == other.speed) && (capacity == other.capacity);
    }

    virtual void displayInfo() {}

    virtual ~Vehicle() {
        totalDeliveries--;
    }
};

int Vehicle::totalDeliveries = 0;

bool AIconflictResolution(const Vehicle& a, const Vehicle& b, float distance, float weight) {
    if (weight <= a.capacity && weight <= b.capacity) {
        return a.speed > b.speed;
    }
    return a.capacity >= b.capacity;
}

class RamzanDrone : public Vehicle {
public:
    RamzanDrone(string id, float speed, float capacity) : Vehicle(id, speed, capacity) {}

    RamzanDrone() : Vehicle("", 0.0, 0.0) {}

    void move() override {
        cout << vehicleID << ": flying with speed " << speed << " km/h" << endl;
    }

    void calculateRoute(float distance) override {
        cout << vehicleID << ": calculating aerial route for " << distance << " km" << std::endl;
    }

    void deliver(int packageID, string urgency) override {
        if (urgency == "iftar") {
            cout << vehicleID << ": high speed Iftar delivery for package " 
                 << packageID << endl;
        } 
        else if (urgency == "sehri") {
            cout << vehicleID << ": time-sensitive sehri delivery for package " << packageID << endl;
        } 
        else {
            Vehicle::deliver(packageID, urgency);
        }
    }

    void deliver(int packageID) override {
        cout << vehicleID << ": basic delivery for package " << packageID << endl;
    }

    void command(const string& cmd, int packageID, string urgency) override {
        if (cmd == "deliver") {
            if (urgency == "urgent") {
                cout << vehicleID << ": high- speed iftar delivery for package " << packageID << endl;
                deliver(packageID, "iftar");
            } 
            else {
                deliver(packageID, urgency);
            }
        } 
        else {
            Vehicle::command(cmd, packageID, urgency);
        }
    }

    void command(const string& cmd, int packageID) override {
        if (cmd == "deliver") {
            deliver(packageID);
        } 
        else {
            Vehicle::command(cmd, packageID);
        }
    }

    void displayInfo() override {
        cout << vehicleID << " , Speed: " << speed << " km/h" << " , Capacity: " << capacity << " kg" << endl;
    }
};

class RamzanTimeShip : public Vehicle {
public:
    RamzanTimeShip(string id, float speed, float capacity) : Vehicle(id, speed, capacity) {}

    RamzanTimeShip() : Vehicle("", 0.0, 0.0) {}

    void move() override {
        cout << vehicleID << ": traveling through time at " << speed << " km/h" << endl;
    }

    void calculateRoute(float distance) override {
        cout << vehicleID << ": verifying history for " << distance << " km delivery" << endl;
    }

    void deliver(int packageID, string urgency) override {
        if (urgency == "sehri") {
            cout << vehicleID << ": time-sensitive sehri delivery for package " << packageID << endl;
        } 
        else if (urgency == "iftar") {
            cout << vehicleID << ": high speed iftar delivery for package " << packageID << endl;
        } 
        else {
            Vehicle::deliver(packageID, urgency);
        }
    }

    void deliver(int packageID) override {
        cout << vehicleID << ": basic delivery for package " << packageID << endl;
    }

    void command(const string& cmd, int packageID, string urgency) override {
        if (cmd == "deliver") {
            if (urgency == "urgent") {
                cout << vehicleID << ": Verifying historical sensitivity before transport" << endl;
            }
            deliver(packageID, urgency);
        } 
        else {
            Vehicle::command(cmd, packageID, urgency);
        }
    }

    void command(const string& cmd, int packageID) override {
        if (cmd == "deliver") {
            deliver(packageID);
        } 
        else {
            Vehicle::command(cmd, packageID);
        }
    }

    void displayInfo() override {
        cout << vehicleID << " , Speed: " << speed << " km/h" << " , Capacity: " << capacity << " kg" << endl;
    }
};

class RamzanHyperPod : public Vehicle {
public:
    RamzanHyperPod(string id, float speed, float capacity) : Vehicle(id, speed, capacity) {}

    RamzanHyperPod() : Vehicle("", 0.0, 0.0) {}

    void move() override {
        cout << vehicleID << ": traveling through underground tunnels at " << speed << " km/h" << endl;
    }

    void calculateRoute(float distance) override {
        cout << vehicleID << ": checking underground network for " << distance << " km" << endl;
    }

    void deliver(int packageID) override {
        cout << vehicleID << ": bulk delivery for package " << packageID << endl;
    }

    void command(const string& cmd, int packageID, string urgency) override {
        if (cmd == "deliver") {
            deliver(packageID);
        } 
        else {
            Vehicle::command(cmd, packageID, urgency);
        }
    }

    void command(const string& cmd, int packageID) override {
        if (cmd == "deliver") {
            deliver(packageID);
        } 
        else {
            Vehicle::command(cmd, packageID);
        }
    }

    void displayInfo() override {
        cout << vehicleID << " , Speed: " << speed << " km/h" << " , Capacity: " << capacity << " kg" << endl;
    }
}; 

int main() {
    RamzanDrone drone("drone001", 120.0, 5.0 );
    RamzanTimeShip timeship("ship001", 80.0, 50.0);
    RamzanHyperPod pod("pod001", 200.0, 100.0);

    cout << endl << "Operator Control Panel (testing basic commands)" << endl;
    drone.command("deliver", 1001);
    timeship.command("deliver", 1002);
    pod.command("deliver", 1003);
    
    cout << endl << "Operator Control Panel (testing urgent commands)" << endl;
    drone.command("deliver", 1004, "urgent");
    timeship.command("deliver", 1005, "urgent");
    pod.command("deliver", 1006, "urgent");

    cout << endl << "Vehicle Information" << endl;
    Vehicle* vehicles[] = {&drone, &timeship, &pod};
    
    for (Vehicle* v : vehicles) {
        v->displayInfo();
        v->move();
        v->calculateRoute(15.5);
        cout << "time required: " << v->estimateTime(15.5) << " hours" << endl;
        
        v->deliver(101);
        v->deliver(102, "iftar");
        v->deliver(103, "sehri");
        cout << endl;
    }

    cout << endl << "Delivery Comparison (conflict resolution)" << endl;
    if (AIconflictResolution(drone, timeship, 10.0, 4.0)) {
        cout << "Drone is better for this delivery\n";
    } else {
        cout << "TimeShip is better for this delivery\n";
    }

    cout << endl << "Operator overloading (comparing two vehicles)" << endl;
    RamzanDrone drone2("DR-2", 120.0, 5.0);
    if (drone == drone2) {
        cout << "both vehicles are the same " << endl;
    }

    cout << endl << "Total active deliveries: " << Vehicle::getTotalDeliveries() << endl;
}