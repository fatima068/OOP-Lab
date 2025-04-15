#include <iostream>
#include <string>
using namespace std;

class SmartDevice {
    public:
    SmartDevice() {}

    virtual void turnOn() = 0;

    virtual void turnOff() = 0;

    virtual string getStatus() = 0;

    virtual ~SmartDevice() {} 
};

class LightBulb : public SmartDevice {
    private:
    bool isOn;
    int brightness;

    public:
    LightBulb(bool isOn, int bright) : isOn(isOn) {
        while (bright > 100 || bright < 0) {
            cout << "Enter brightness between 0 and 100: ";
            cin >> bright;
        }
        this->brightness = bright;
    }  

    LightBulb() : SmartDevice(), isOn(false), brightness(0) {}

    void turnOn() override {
        isOn = true;
    }

    void turnOff() override {
        isOn = false;
    }

    string getStatus() override {
        if (isOn) {
            string retVal = "Light is on, brightness " + brightness;
            return retVal;
        } else {
            return "Light is OFF";
        }
    }
};

class Thermostat : public SmartDevice {
private:
    bool isOn;
    double temperature;

public:
    Thermostat(bool isOn, double temp) : isOn(isOn) {
        while (temp < -10.0 || temp > 40.0) {
            cout << "Enter temperature between -10 and 40: ";
            cin >> temp;
        }
        this->temperature = temp;
    }

    Thermostat() : SmartDevice(), isOn(false), temperature(0.0) {}  

    void turnOn() override {
        isOn = true;
    }

    void turnOff() override {
        isOn = false;
    }

    string getStatus() override {
        if (isOn) {
            return "Thermostat is on, temperature: " + to_string(temperature);
        } else {
            return "Thermostat is off";
        }
    }

    void setTemperature(double newTemp) {
        if (newTemp >= -10.0 && newTemp <= 40.0) {
            temperature = newTemp;
        }
    }
};

int main() {
    LightBulb bulb(true, 50); 
    Thermostat t1(false, 90);  

    cout << "Light Bulb: " << endl;
    cout << bulb.getStatus() << endl;  
    
    bulb.turnOn();
    cout << bulb.getStatus() << endl;  
    
    bulb.turnOff();
    cout << bulb.getStatus() << endl << endl;  

    cout << "Testing Thermostat: " << endl;
    cout << t1.getStatus() << endl; 
    
    t1.turnOff();
    cout << t1.getStatus() << endl;  
    
    t1.turnOn();
    t1.setTemperature(19.0);
    cout << t1.getStatus() << endl; 
}