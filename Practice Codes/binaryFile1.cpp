#include <fstream>
#include <iostream>
using namespace std;

int main() {
    fstream file("data.bin", ios::binary | ios::in | ios:: out); // necessary to specify all 3 to perform both read and write on a bin file
    if (!file) {
        cout << "file opening error";
        return 1;
    }

    int num = 54;
    double pi = 3.142;
    char str[7] = "hello!"; // Match original size
    
    cout << "Writing data...." << endl;
    file.write((char*)(&num), sizeof(num));
    file.write((char*)(&pi), sizeof(pi));
    file.write(str, sizeof(str));
    // at this point, the file pointer is at the end of the file so bring it to the start
    file.seekg(0);

    cout << "reading data..." << endl;
    int i;
    double d;
    char c[7];
    file.read((char*)(&i), sizeof(i)); // char works but reinterpret cast is safer in cpp 
    file.read((char*)(&d), sizeof(d));
    file.read(c, sizeof(c));
    
    cout << "i: " << i << endl;  // 42
    cout << "d: " << d << endl;   // 3.14159
    cout << "c: " << c << endl;  // "Binary"
    file.close();
}