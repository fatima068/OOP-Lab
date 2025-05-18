#include <iostream>
using namespace std;

// Function to process data and return a void pointer
void* processData(void* data, char type) {
    if (data == nullptr) {
        cerr << "Error: Null pointer passed to function." << endl;
        return nullptr;
    }

    switch (type) {
        case 'i': { // Integer
            int* intData = static_cast<int*>(data);
            int* result = new int(*intData * 2); // Double the value
            return result;
        }
        case 'd': { // Double
            double* doubleData = static_cast<double*>(data);
            double* result = new double(*doubleData * 2); // Double the value
            return result;
        }
        case 'f': { // Float
            float* floatData = static_cast<float*>(data);
            float* result = new float(*floatData * 2); // Double the value
            return result;
        }
        default:
            cerr << "Error: Unknown data type." << endl;
            return nullptr;
    }
}

int main() {
    void* result;
    // Example with integer
    int intValue = 10;
    result = processData(&intValue, 'i');
    if (result != nullptr) {
        cout << "Integer result: " << *(static_cast<int*>(result)) << endl;
        // delete static_cast<int*>(result); // Free dynamically allocated memory
    }

    // Example with double
    double doubleValue = 3.14;
    result = processData(&doubleValue, 'd');
    if (result != nullptr) {
        cout << "Double result: " << *(static_cast<double*>(result)) << endl;
       // delete static_cast<double*>(result); // Free dynamically allocated memory
    }

    // Example with float
    float floatValue = 5.5f;
    result = processData(&floatValue, 'f');
    if (result != nullptr) {
        cout << "Float result: " << *(static_cast<float*>(result)) << endl;
        // delete static_cast<float*>(result); // Free dynamically allocated memory
    }

    // void pointer delete karte huey u typecast it to the datatype of the last value it stores
    delete static_cast<float*>(result);
}