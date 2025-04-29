#include <iostream>
#include <stdexcept>
using namespace std;

class StackOverflowException : public exception {
public:
    const char* what() const noexcept override {
        return "StackOverflowException - Stack is full";
    }
};

class StackUnderflowException : public exception {
public:
    const char* what() const noexcept override {
        return "StackUnderflowException - Stack is empty";
    }
};

template<typename T, int capacity>
class Stack {
private:
    T data[capacity];
    int topIndex = -1;

public:
    void push(const T& value) {
        if (topIndex >= capacity - 1) {
            throw StackOverflowException();
        }
        data[++topIndex] = value;
        cout << "Pushed value: " << value << endl;
    }

    T pop() {
        if (topIndex < 0) {
            throw StackUnderflowException();
        }
        return data[topIndex--];
    }
};

int main() {
    try {
        Stack<int, 3> intStack;

        intStack.push(10);
        intStack.push(20);
        intStack.push(30);
        cout << "Pop: " << intStack.pop() << endl;
        cout << "Pop: " << intStack.pop() << endl;
        cout << "Pop: " << intStack.pop() << endl;

        cout << "Popping element to test underflow exception" << endl;
        intStack.pop();  

        intStack.push(40);
        intStack.push(50);
        intStack.push(60);

        cout << "Testing stack overflow" << endl;
        intStack.push(70);  
    }
    catch (const StackOverflowException& e) {
        cerr << "Error: " << e.what() << endl;
    }
    catch (const StackUnderflowException& e) {
        cerr << "Error: " << e.what() << endl;
    }
    catch (const exception& e) {
        cerr << "Unknown error: " << e.what() << endl;
    }
}
