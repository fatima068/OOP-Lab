/*Create a class called calendar. The calendar should have 12 arrays for each month of the year, and a variable that stores information about the current year. The user is allowed to store their tasks to do against each day. Assume only one entry is needed per day. 

Create the following methods for your class:
     Add a task. This function accepts three parameters: task details, date and month. It should add
      a task on the day specified.
     Remove a task. Accepts the date and month as a parameter to remove the task from.
     Show tasks. This method should go through all of your months and print all the tasks allocated.

Your task is to create one calendar object, then hardcode 5-6 tasks for your calendar. Then demonstrate how you’ll remove a task, and display the updated task list.*/

#include <iostream>
using namespace std;

class Calendar {
    private:
        string jan[31];
        string feb[29];
        string mar[31];
        string apr[30];
        string may[31];
        string jun[30];
        string jul[31];
        string aug[31];
        string sep[30];
        string oct[31];
        string nov[30];
        string dec[31];
        int currentYear;

    public:
        Calendar(){
            for (int i = 0; i < 31; i++) 
                jan[i] = "";
            for (int i = 0; i < 29; i++)
                feb[i] = "";
            for (int i = 0; i < 31; i++)
                mar[i] = "";
            for (int i = 0; i < 30; i++)
                apr[i] = "";
            for (int i = 0; i < 31; i++)
                may[i] = "";
            for (int i = 0; i < 30; i++)
                jun[i] = "";
            for (int i = 0; i < 31; i++)
                jul[i] = "";
            for (int i = 0; i < 31; i++)
                aug[i] = "";
            for (int i = 0; i < 30; i++)
                sep[i] = "";
            for (int i = 0; i < 31; i++)
                oct[i] = "";
            for (int i = 0; i < 30; i++)
                nov[i] = "";
            for (int i = 0; i < 31; i++)
                dec[i] = "";
        }

        void addTask(string task, int date, int month){
            switch (month){
                case 1:
                    jan[date-1] = task;
                    break;
                case 2:
                    feb[date-1] = task;
                    break;
                case 3:
                    mar[date-1] = task;
                    break;
                case 4:
                    apr[date-1] = task;
                    break;
                case 5:
                    may[date-1] = task;
                    break;
                case 6:
                    jun[date-1] = task;
                    break;
                case 7:
                    jul[date-1] = task;
                    break;
                case 8:
                    aug[date-1] = task;
                    break;
                case 9:
                    sep[date-1] = task;
                    break;
                case 10:
                    oct[date-1] = task;
                    break;
                case 11:
                    nov[date-1] = task;
                    break;
                case 12:
                    dec[date-1] = task;
                    break;
                default:
                    cout << "Invalud date entered";
                    break;
            }
        }

        void removeTask(int date, int month){
            switch (month){
                case 1:
                    jan[date-1] = "";
                    break;
                case 2:
                    feb[date-1] = "";
                    break;
                case 3:
                    mar[date-1] = "";
                    break;
                case 4:
                    apr[date-1] = "";
                    break;
                case 5:
                    may[date-1] = "";
                    break;
                case 6:
                    jun[date-1] = "";
                    break;
                case 7:
                    jul[date-1] = "";
                    break;
                case 8:
                    aug[date-1] = "";
                    break;
                case 9:
                    sep[date-1] = "";
                    break;
                case 10:
                    oct[date-1] = "";
                    break;
                case 11:
                    nov[date-1] = "";
                    break;
                case 12:
                    dec[date-1] = "";
                    break;
                default:
                    cout << "Invalid date entered";
                    break;
            }
        }

        void showTasks(){
            for (int i = 0; i < 31; i++) { 
                if (jan[i] != "") cout << "January " << i + 1 << ": " << jan[i] << endl; 
            }

            for (int i = 0; i < 29; i++) { 
                if (feb[i] != "") cout << "February " << i + 1 << ": " << feb[i] << endl; 
            }

            for (int i = 0; i < 31; i++) { 
                if (mar[i] != "") cout << "March " << i + 1 << ": " << mar[i] << endl; 
            }
            for (int i = 0; i < 30; i++) { 
                if (apr[i] != "") cout << "April " << i + 1 << ": " << apr[i] << endl; 
            }
            for (int i = 0; i < 31; i++) { 
                if (may[i] != "") cout << "May " << i + 1 << ": " << may[i] << endl; 
            }
            for (int i = 0; i < 30; i++) { 
                if (jun[i] != "") cout << "June " << i + 1 << ": " << jun[i] << endl; 
            }
            for (int i = 0; i < 31; i++) { 
                if (jul[i] != "") cout << "July " << i + 1 << ": " << jul[i] << endl; 
            }
            for (int i = 0; i < 31; i++) { 
                if (aug[i] != "") cout << "August " << i + 1 << ": " << aug[i] << endl; 
            }
            for (int i = 0; i < 30; i++) { 
                if (sep[i] != "") cout << "September " << i + 1 << ": " << sep[i] << endl; 
            }
            for (int i = 0; i < 31; i++) { 
                if (oct[i] != "") cout << "October " << i + 1 << ": " << oct[i] << endl; 
            }
            for (int i = 0; i < 30; i++) { 
                if (nov[i] != "") cout << "November " << i + 1 << ": " << nov[i] << endl; 
            }
            for (int i = 0; i < 31; i++) { 
                if (dec[i] != "") cout << "December " << i + 1 << ": " << dec[i] << endl; 
            }
    }
};


int main(){
    Calendar c1;

    c1.addTask("oop assignment 1", 5, 1);  
    c1.addTask("quiz 1", 14, 2);     
    c1.addTask("quiz 2", 23, 3);     
    c1.addTask("birthday", 10, 7);      
    c1.addTask("shopping", 20, 8);       
    c1.addTask("go to uni", 5, 12);          

    cout << "Tasks in list: " << endl;
    c1.showTasks();

    c1.removeTask(23, 3);

    cout << "Tasks after removal: " << endl;
    c1.showTasks();
}
