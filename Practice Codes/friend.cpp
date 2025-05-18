#include <iostream>
using namespace std;

class frnd{
    //if u do friend class lonely tou mutual friendship hojayegi
};

class lonely {
    friend class frnd;
};

// in this, lonely has no access to friend but frnd has all access to lonely ke prvt members and all functions etc