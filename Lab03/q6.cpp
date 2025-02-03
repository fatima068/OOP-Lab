/*Create a class called Smartphone with the following attributes:
    -> Company
    -> Model
    -> Display Resolution
    -> RAM
    -> ROM
    -> Storage

Create getter and setter methods for your attributes. A smartphone has some specific actions that it can perform.
For example:
    -> Make a phone call
    -> Send a message
    -> Connect to the wifi
    -> Browse the internet

Create different smartphone objects. Set their attributes using the setter functions and display their attributes after using the getter functions to fetch the attributes.*/

#include <iostream>
#include <string>
using namespace std;

class Smartphone{
    private:
        string company;
        string model;
        int displayResolution;
        int RAM;
        int ROM;
        int storage;

    public:
        void setCompany(const string& comp) {
            company = comp;
        }      
        void setModel(const string& mod) {
            model = mod;
        }
        void setDisplayResolution(int resolution) {
            displayResolution = resolution;
        }
        void setRam(int ram) {
            RAM = ram;
        }
        void setRom(int rom) {
            ROM = rom;
        }
        void setStorage(int size) {
            storage = size;
        }


        string getCompany() const {
            return company;
        }
        string getModel() const {
            return model;
        }
        int getDisplayResolution() const {
            return displayResolution;
        }
        int getRam() const {
            return RAM;
        }
        int getRom() const {
            return ROM;
        }
        int getStorage() const {
            return storage;
        }


        void makeCall() const {
            cout << "Phone call" << endl;
        }

        void sendMessage() const {
            cout << "Sending message." << endl;
        }

        void connectToWifi() const {
            cout << "Connecting Wi-Fi" << endl;
        }

        void browseInternet() const {
            cout << "Browsing internet" << endl;
        }
};

int main(){
    Smartphone phone1, phone2;

    phone1.setCompany("Lenovo");
    phone1.setModel("M10 FHD");
    phone1.setDisplayResolution(1080);
    phone1.setRam(4);
    phone1.setRom(64);
    phone1.setStorage(64);

    phone2.setCompany("Redmi");
    phone2.setModel("Note 9");
    phone2.setDisplayResolution(720);
    phone2.setRam(6);
    phone2.setRom(128);
    phone2.setStorage(128);

    cout << "Phone 1 Details:" << endl;
    cout << "Company: " << phone1.getCompany() << endl;
    cout << "Model: " << phone1.getModel() << endl;
    cout << "Display Resolution: " << phone1.getDisplayResolution() << endl;
    cout << "RAM: " << phone1.getRam() << endl;
    cout << "ROM: " << phone1.getRom() << endl;
    cout << "Storage: " << phone1.getStorage() << endl;
    
    phone1.makeCall();
    phone1.sendMessage();
    phone1.connectToWifi();
    phone1.browseInternet();

    cout << endl;

    cout << "Phone 2 Details:" << endl;
    cout << "Company: " << phone2.getCompany() << endl;
    cout << "Model: " << phone2.getModel() << endl;
    cout << "Display Resolution: " << phone2.getDisplayResolution() << endl;
    cout << "RAM: " << phone2.getRam() << endl;
    cout << "ROM: " << phone2.getRom() << endl;
    cout << "Storage: " << phone2.getStorage() << endl;

    phone2.makeCall();
    phone2.sendMessage();
    phone2.connectToWifi();
    phone2.browseInternet();
}