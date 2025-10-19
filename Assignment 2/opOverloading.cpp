#include <iostream>
using namespace std;

class TestClass {
    private:
    int age;
    string name;
    public:
    TestClass(int age, string name) : age(age), name(name) {}

    string GetName() const {
        return name;
    }

    int GetAge() const {
        return age;
    }
};

void operator<<(ostream& COUT, TestClass& obj) {
    COUT << "NAME: " << obj.GetName() << ", AGE: " << obj.GetAge() << endl;
}

int main () {
    TestClass obj1 = TestClass(18, "fatima");
    TestClass obj2 = TestClass(19, "ikki");
    cout << obj1;
}