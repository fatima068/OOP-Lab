/*Q4. You are testing how file pointers work in a file while reading and writing.
Requirements:
1. Write the sentence "C++ is a powerful programming language." to a file named info.txt using ofstream in ios::out mode.
2. Reopen the file using fstream with both ios::in | ios::out modes.
3. Display the initial position of get pointer using tellg() and put pointer using tellp().
4. Use seekg(6) to move the read pointer to the word "powerful" and read the word from there.
5. Use seekp(6) to move the write pointer to the same position, and overwrite "powerful" with "dynamic" (same length).
6. Use tellg() and tellp() again to show the new pointer positions.
7. Display the updated content of the file.*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
    ofstream outFile("info.txt", ios::out);
    if(!outFile) {
        cout << "Error opening file for writing." << endl;
        return 1;
    }
    outFile << "C++ is a powerful programming language." << endl;
    outFile.close();


    fstream file ("info.txt", ios::in | ios::out);

    if(!file) {
        cout << "Error opening file for reading and writing." << endl;
        return 1;
    }

    cout << "Initial position of get pointer: " << file.tellg() << endl;
    cout << "Initial position of put pointer: " << file.tellp() << endl;

    file.seekg(9);
    string word;
    file >> word;
    cout << "Word at position 6: " << word << endl;

    file.seekp(9);
    file << "dynamic ";
    file.flush();
    cout << "New position of get pointer: " << file.tellg() << endl;
    cout << "New position of put pointer: " << file.tellp() << endl;

    file.seekg(0);
    string updatedContent;
    string line;
    while (getline(file, line)) {
        updatedContent += line + "\n";
    }
    cout << "Updated content of the file: " << updatedContent;

    file.close();
}