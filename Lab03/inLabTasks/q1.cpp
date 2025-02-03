/*Create a class called time that has separate int member data for hours, minutes, and seconds. One constructor display it, in 11:59:59 format. The final member function should add two objects of type time passed as should initialize this data to 0, and another should initialize it to fixed values. Another member function should arguments. A main() program should create two initialized time objects (should they be const?) and one that isn’t initialized. Then it should add the two initialized values together, leaving the result in the third time variable. Finally it should display the value of this third variable. Make appropriate member functions const.*/

#include <iostream>
using namespace std;

class Time {
    private:
        int hours;
        int minutes;
        int seconds;

    public:
        Time(){
            hours = 0; 
            minutes = 0; 
            seconds = 0;
        } 

        Time(int h, int m, int s){
            hours = h; 
            minutes = m; 
            seconds = s;
        }

        void display() const {
            cout << hours << ":" << minutes << ":" << seconds;
        }

        Time addTime(Time t1, Time t2){
            Time t3;
            t3.seconds = t1.seconds + t2.seconds;
            t3.minutes = t1.minutes + t2.minutes;
            t3.hours = t1.hours + t2.hours;

            if(t3.seconds > 59){
                t3.seconds -= 60;
                t3.minutes += 1;
            }
            if(t3.minutes > 59){
                t3.minutes -= 60;
                t3.hours += 1;
            }
            if(t3.hours > 23){
                t3.hours -= 24;
            }
            return t3;
        }

};

int main() {
    const Time t1(5, 45, 30); 
    const Time t2(6, 20, 45); 
    Time t3 = t3.addTime(t1, t2);               

    cout << "Sum: ";
    t3.display();
}
