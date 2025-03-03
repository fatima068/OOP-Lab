/*Write a program that uses composition to implement a game engine. A game engine is madeup of several components. For example:
a) Graphics rendering engine
b) Input handler
c) Physics engine
You don’t have to write the logicforhow these individual components work.*/

#include <iostream>
using namespace std;

class GraphicsRenderer {
public:
    void render() {
        cout << "graphics renderer running now" << endl;
    }
};

class InputHandler {
public:
    void handleInput() {
        cout << "input handler running now" << endl;
    }
};

class PhysicsEngine {
public:
    void runPhyEngine() {
        cout << "physics engine running now" << endl;
    }
};

class GameEngine {
    private:
    GraphicsRenderer graphicsRenderer;  
    InputHandler inputHandler;          
    PhysicsEngine physicsEngine;        
    
    public:
    GameEngine() {
        cout << "game engine created" << endl;
    }
    
    void run() {
        cout << "game engine running" << endl;
        inputHandler.handleInput();
        physicsEngine.runPhyEngine();
        graphicsRenderer.render();
    }

    ~GameEngine() {
        cout << "game engine destroyed" << endl;
    }
};

int main() {
    GameEngine gameEngine;
    gameEngine.run();
}