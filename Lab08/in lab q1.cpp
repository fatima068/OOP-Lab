#include <iostream>
#include <string>
using namespace std;

class MaintenanceTool;
class User;

class Device {
    protected:
    string deviceID;
    string deviceType;
    double powerRating;
    bool status;

    public:
    Device() : deviceID(""), deviceType(""), powerRating(0), status(false) {}

    Device(string id, string type, double rating) : deviceID(id), deviceType(type), powerRating(rating), status(false) {}

    virtual void turnOn() {
        status = true;
    }

    virtual void turnOff() {
        status = false;
    }

    virtual double calculatePowerUsage(int hours) {}

    friend void viewAccessibleDevices(Device* devices[], int deviceCount, const User& user );
};

class Light : public Device {
    public:
    Light() : Device() {}

    Light(string id, string type, double rating) : Device(id, type, rating) {}

    double calculatePowerUsage(int hours) override {
        return powerRating * hours;
    }

    void turnOn() override {
        status = true;
    }

    void turnOff() override {
        status = false;
    }
};

class Fan : public Device {
    private:
    double speedFactor;

    public:
    Fan() : Device(), speedFactor(0) {}

    Fan(string id, string type, double rating, double speed) : Device(id, type, rating), speedFactor(speed) {}

    double calculatePowerUsage(int hours) override {
        return powerRating * hours * speedFactor;
    }

    void turnOn() override {
        status = true;
    }

    void turnOff() override {
        status = false;
    }
};

class AC : public Device {
    private:
    double currentTemperature;
    double desiredTemperature;

    public:
    AC() : Device(), currentTemperature(0), desiredTemperature(0) {}

    AC(string id, string type, double rating, double currentTemp, double desiredTemp) : Device(id, type, rating), currentTemperature(currentTemp), desiredTemperature(desiredTemp) {}

    double calculatePowerUsage(int hours) override {
        return (powerRating * hours * (1 - (currentTemperature - desiredTemperature) / 100));
    }

    void turnOn() override {
        status = true;
        if (currentTemperature != desiredTemperature) {
            currentTemperature = desiredTemperature;
        }
    }

    void turnOff() override {
        status = false;
        currentTemperature = 0;
        desiredTemperature = 0;
    }
};

class SecuritySystem : public Device {
    private:
    bool securityStatus;
    double fixedPowerConsumption;

    public:
    SecuritySystem() : Device(), securityStatus(false) {}

    SecuritySystem(string id, string type, double rating, bool status) : Device(id, type, rating), securityStatus(status) {}

    double calculatePowerUsage(int hours) override {
        if (securityStatus == 1) {
            return fixedPowerConsumption;
        }
        else {
            return 0;
        }
    }

    void turnOn() override {
        securityStatus = true;
    }

    void turnOff() override {
        securityStatus = false;
    }



    friend class MaintenanceTool;
};

class User {
    string userID;
    string userRole;
    int accessLevel;

    public:
    User() : userID(""), userRole(""), accessLevel(0) {}

    User(string id, string role, int level) : userID(id), userRole(role), accessLevel(level) {}

    friend void viewAccessibleDevices(Device* devices[], int deviceCount, const User& user );

};

class MaintenanceTool {

};

void viewAccessibleDevices(Device* devices[], int deviceCount, const User& user) {
    cout << "Accessible Devices for User " << user.userID << ":\n";
    for (int i = 0; i < deviceCount; ++i) {
        if (devices[i]->deviceType == "SecuritySystem") {
            if (user.accessLevel == 1) {
                cout << "Device ID: " << devices[i]->deviceID << ", Type: " << devices[i]->deviceType << "\n";
            }
        }
        else {
            cout << "Device ID: " << devices[i]->deviceID << ", Type: " << devices[i]->deviceType << "\n";
        }
    }
}

int main() {
    Device* devices[] = {new Light("L1", "Light", 100), new Fan("F1", "Fan", 150, 1.5), new AC("A1", "AC", 200, 25, 20)};
    User user("U1", "Admin", 1);
    viewAccessibleDevices(devices, 3, user);
    return 0;
}

