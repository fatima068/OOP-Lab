#include <iostream>
using namespace std;

class Car{
    private:
    int carID;
    string model;
    int year;
    bool isRented;

    public:
    Car(){
        carID = 0;
        model = "";
        year = 0;
        isRented = false;
    }

    Car(int carID, string model, int year, bool isRented){
        this->carID = carID ;                
        this->model = model;            
        this->year =  year;            
        this->isRented = isRented;                
    }

    int getID() {
        return carID;
    }

    void rentCar(){
        if(isRented == false){
            isRented = true;
            cout << carID << " has been rented by you" << endl;
            return;
        }
        cout << carID << " not available for rent" << endl;
    }

    void returnCar() {
        isRented =false;
        cout << carID << " is returned " << endl;
    }

    bool isVintage(){
        if (year < 2000)
            return true;
        return false;
    }
};

int main() {

    Car car1(998, "Corolla", 1999, false);
    Car car2(924, "Civic", 2023, true);
    Car car3(103, "Mehran", 1967, false);

    cout << "vintage cars:  " << endl ;
    if (car1.isVintage()) {
        cout << car1.getID() << ": vintage" << endl;
    } else {
        cout << car1.getID() << ": not vintage" << endl;
    }


    if (car2.isVintage()) {
        cout << car2.getID() << ": vintage" << endl;
    } else {
        cout << car2.getID() << ": not vintage" << endl;
    }

    if (car3.isVintage()) {
        cout << car3.getID() << ": vintage" << endl;
    } else {
        cout << car3.getID() << ": not vintage" << endl;
    }

    cout << endl;
    
    car1.rentCar();
    car2.rentCar();    
}
