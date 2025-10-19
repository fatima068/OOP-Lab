#include <iostream>
#include <string>
using namespace std;

class HauntedHouse;
class Visitor;

class Ghost {
    protected:
    string workerName;
    int scareLevel;

    public:
    Ghost() : workerName(""), scareLevel(0) {}

    Ghost(string workerName, int scareLevel) : workerName(workerName), scareLevel(scareLevel) {
        while (scareLevel > 10 || scareLevel < 1) {
            cout << "enter scare level between 1 and 10" << endl;
            cin >> scareLevel;
        }
        this->scareLevel = scareLevel;
    }

    string getWorkerName() const {
        return workerName;
    }

    int getScareLevel() const {
        return scareLevel;
    }

    virtual void performHaunting() {
        cout << "upgraded ghost haunting now" << endl;
    }

    Ghost operator+ (const Ghost& g1) {
        string newWokrerName = workerName + g1.getWorkerName();
        int newScareLevel = scareLevel + g1.getScareLevel();
        if (newScareLevel > 10)
            newScareLevel = 10;
        Ghost newGhost = Ghost(newWokrerName, newScareLevel);
        return newGhost;
    }
    
    friend void operator<<(ostream& COUT, Ghost& g1) {
        COUT << "WorkerName: " << g1.getWorkerName() << ", scareLevel: " << g1.getScareLevel() << endl;
    }

    Ghost upgradeGhost(Ghost g1) {
        cout << "upgrading ghost: ";
        cout << *this;
        cout << " & ghost: ";
        cout << g1;
        Ghost newGhost = *this + g1;
        return newGhost;
    }
};


class Poltergeist : virtual public Ghost {
    public:
    Poltergeist(string name, int scareLevel) : Ghost(name, scareLevel) {}

    Poltergeist() : Ghost() {}

    void performHaunting() override {
        cout << "poltergeist " << workerName << " is moving objects..." << endl;
    }
};

class Banshee : public Ghost {
    public:
    Banshee(string name, int scareLevel) : Ghost(name, scareLevel) {}

    Banshee() : Ghost() {}

    void performHaunting() override {
        cout << "banshee " << workerName << " is screaming loudly..." << endl;
    }
};

class ShadowGhost : virtual public Ghost {
    public:
    ShadowGhost(string name, int scareLevel) : Ghost(name, scareLevel) {}

    ShadowGhost() : Ghost() {}

    void performHaunting() override {
        cout << "shadow ghost " << workerName << " is whispering creepily..." << endl;
    }
};

class ShadowPoltergeist : public ShadowGhost, public Poltergeist {
    public:
    ShadowPoltergeist(string name, int scareLevel) : ShadowGhost(name, scareLevel), Poltergeist(name, scareLevel), Ghost(name, scareLevel) {}

    ShadowPoltergeist() : ShadowGhost(), Poltergeist(), Ghost() {}

    void performHaunting() override {
        cout << "shadow poltergeist " << workerName << " is whispering creepily and moving objects..." << endl;
    }
};


class Visitor {
    private:
    string visitorName;
    int bravery;
    
    public:
    Visitor() {
        visitorName = "";
        bravery = 0;
    }
    
    Visitor(string visitorName, int bravery) : visitorName(visitorName), bravery(bravery) {
        while (bravery > 10 || bravery < 1) {
            cout << "enter scare level between 1 and 10" << endl;
            cin >> bravery;
        }
        this->bravery = bravery;
    }
    
    void hauntVisitor(Ghost& g1) {
        g1.performHaunting();
        if ((g1.getScareLevel() - bravery)<=1 && (g1.getScareLevel() - bravery)>=-1 ) {
            cout << "visitor " << visitorName << " gets a shaky voice " << endl;
        }
        else if ((g1.getScareLevel() - bravery) < -1) {
            cout << "visitor " << visitorName << " laughs and taunts the ghost" << endl;
        }
        else cout << "visitor " << visitorName << " screams and runs away" << endl;
    }
    
    friend void Visit(Visitor visitors[], int numVisitors, HauntedHouse& house);
};

class HauntedHouse {
    private:
    string houseName;
    Ghost** ghosts;
    int numGhosts;

    public:
    HauntedHouse() {
        houseName = "";
        numGhosts = 0;
        ghosts = nullptr;
    }

    HauntedHouse(string houseName, int numGhosts, Ghost** arr) : houseName(houseName), numGhosts(numGhosts) {

        for (int i =0; i<numGhosts; i++) {
            ghosts = new Ghost*[numGhosts];
        }
        for (int i =0; i<numGhosts; i++) {
            ghosts[i] = arr[i];
        }
    }

    friend void Visit(Visitor visitors[], int numVisitors, HauntedHouse& house);

    ~HauntedHouse() {
        delete[] ghosts;
    }
};

void Visit (Visitor visitors[], int numVisitors, HauntedHouse& house) {
    for (int i = 0; i<numVisitors; i++) {
        cout << endl << endl << "visitor " << visitors[i].visitorName << " visiting haunted house " << house.houseName << endl;
        for (int j=0; j<house.numGhosts; j++) {
            visitors[i].hauntVisitor(*house.ghosts[j]);
        }
    }
}

int main () {
    Poltergeist g1("Frank", 3);
    Banshee g2("Leo", 7);
    ShadowGhost g3("Nico", 9);
    ShadowPoltergeist g4("Hazel", 5);
    Ghost upgraded = g1.upgradeGhost(g3);
    cout << "upgraded ghost: ";
    cout << upgraded;
    Ghost *ghosts[] = {&g1, &g2, &g3, &g4, &upgraded};
    HauntedHouse h1 ("Mount Olympus", 5, ghosts);
    HauntedHouse h2("Hecate's Mansion", 5, ghosts);


    Visitor v1("Grover", 2);  
    Visitor v2("Percy", 6);  
    Visitor v3("Annabeth", 9);  
    Visitor visitors[] = {v1, v2, v3};

    Visit(visitors, 3, h1);
    Visit(visitors, 3, h2);
}