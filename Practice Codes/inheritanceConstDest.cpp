#include <iostream>
using namespace std;

class gparent {
    public:
    gparent() {
        cout << "gparent const" << endl;
    }

    virtual ~gparent() {
        cout << "gparent dest" << endl;
    }
};

class parent : public gparent {
    public:
    parent() {
        cout << "parent const" << endl;
    }

    ~parent() {
        cout << "parent dest" << endl;
    }
};

class mid1 : public virtual parent{
    public:
    mid1() {
        cout << "mid1 const" << endl;
    }

    ~mid1() {
        cout << "mid1 dest" << endl;
    }
};

class mid2 : public virtual parent {
    public:
    mid2() {
        cout << "mid2 const" << endl;
    }

    ~mid2() {
        cout << "mid2 dest" << endl;
    }
};

class childest : public mid2, public mid1 {
    public:
    childest() {
        cout << "childest const" << endl;
    }

    ~childest() {
        cout << "childest dest" << endl;
    }
};

int main () {
    gparent *c1 = new childest();
    delete c1;
}