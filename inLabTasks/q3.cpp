#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream chap1("chapter1.txt");
    if (!chap1) {
        cerr << "error in chapter1.txt" << endl;
        return 0;
    }
    ifstream chap2("chapter2.txt");
    if (!chap2) {
        cerr << "error in chapter2.txt" << endl;
        return 1;
    }
    ofstream book("book.txt");
    if (!book) {
        cerr << "error in book.txt" << endl;
        return 1;
    }

    string line;
    while (getline(chap1, line)) {
        book << line << endl;
    }
    book << endl;
    while (getline(chap2, line)) {
        book << line << endl;
    }
    book.close();
    chap1.close();
    chap2.close();
    cout << "data written successfully";
}