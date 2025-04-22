#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string name, email, summary;
    int yearsOfExperience;

    cout << "enter name: ";
    getline(cin, name);
    cout << "enter email: ";
    getline(cin, email);
    cout << "enter years of experience: ";
    cin >> yearsOfExperience;
    cin.ignore(); 
    cout << "enter summary: ";
    getline(cin, summary);

    ofstream outFile("resume.txt", ios::trunc);
    if (!outFile) {
        cerr << "error in resume.txt" << endl;
        return 1;
    }
    outFile << "name: " << name << endl;
    outFile << "email: " << email << endl;
    outFile << "years of experience: " << yearsOfExperience << endl;
    outFile << "summary: " << summary << endl;
    outFile.close();
    cout << "data added successfully" << endl << endl;

    cout << "reading data from file" << endl;
    ifstream inFile("resume.txt");
    if (!inFile) {
        cerr << "error in resume.txt " << endl;
        return 1;
    }
    string line;
    while (getline(inFile, line)) {
        cout << line << endl;
    }
    inFile.close();
}