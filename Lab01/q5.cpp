/*Design Event Management System in C++ to facilitate the organization of events. The program should empower the user to seamlessly manage event details, including the event name, date, venue, and organizer. Incorporate key features such as the ability to add events, display comprehensive details of all events, and perform event searches based on specific dates. To enhance flexibility and scalability, leverage dynamic memory allocation for storing event details.
1. Prompt the user to input the total number of events they wish to manage.
2. Dynamically allocate memory to store event details for the specified number of events.
3. For each event, prompt the user to input:
     Event Name
     Date
     Venue
     Organizer
4. Display all events that match the provided date, including their complete details.
5. Allow the user to search for events based on a specific date.*/

#include <iostream>
#include <string>
using namespace std;

typedef struct {
    string name;
    string date;
    string venue;
    string organizer;
}Event;

void addEvents(Event* events, int count);
void displayEvents(const Event* events, int count);
void searchEvents(const Event* events, int count, string date);

int main() 
{
    int numEvents;
    string searchDate;

    cout << "Enter the total number of events you want to manage: ";
    cin >> numEvents;
    cin.ignore();
    Event* events = new Event[numEvents];
    addEvents(events, numEvents);

    cout << "\nAll Events Details:\n";
    displayEvents(events, numEvents);

    cout << "\nEnter a date to search for events (format DD-MM-YYYY): ";
    getline(cin, searchDate);
    cout << "\nEvents on " << searchDate << ":\n";
    searchEvents(events, numEvents, searchDate);

    delete[] events;
}

void addEvents(Event* events, int count) 
{
    for (int i = 0; i < count; ++i) 
    {
        cout << "\nEnter details for event " << (i + 1) << ":\n";
        cout << "Event Name: ";
        getline(cin, events[i].name);
        cout << "Date (format DD-MM-YYYY): ";
        getline(cin, events[i].date);
        cout << "Venue: ";
        getline(cin, events[i].venue);
        cout << "Organizer: ";
        getline(cin, events[i].organizer);
    }
}

void displayEvents(const Event* events, int count) 
{
    for (int i = 0; i < count; ++i) 
    {
        cout << "\nEvent " << (i + 1) << ":\n";
        cout << "Name: " << events[i].name << "\n";
        cout << "Date: " << events[i].date << "\n";
        cout << "Venue: " << events[i].venue << "\n";
        cout << "Organizer: " << events[i].organizer << "\n";
    }
}

void searchEvents(const Event* events, int count, string date) 
{
    bool found = false;
    for (int i = 0; i < count; ++i) 
    {
        if (events[i].date == date) 
        {
            found = true;
            cout << "\nEvent " << (i + 1) << ":\n";
            cout << "Name: " << events[i].name << "\n";
            cout << "Venue: " << events[i].venue << "\n";
            cout << "Organizer: " << events[i].organizer << "\n";
        }
    }
    if (found == false) 
    {
        cout << "No events found on the specified date." << endl;
    }
}
