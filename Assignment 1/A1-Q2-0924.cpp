#include <iostream>
#include <string>
using namespace std;

class Robot {
    private:
    string name;
    int hits;
    
    public:
    Robot (){
        name = "";
        hits = 0;
    }

    Robot (string n){
        name = n;
        hits = 0;
    }

    string getName() const {
        return name;
    }

    int getHits() const {
        return hits;
    }

    void hitBall(int &ballX, int &ballY, const string &direction){
        hits++;
        if (direction == "up"){
            ballY += 1;
            return;
        }
        if (direction == "down"){
            ballY -= 1;
            return;
        }
        if (direction == "left"){
            ballX -= 1;
            return;
        }
        if (direction == "right"){
            ballX += 1;
            return;
        }
    }

    ~Robot(){}
};

struct ballPos {
    int x;
    int y;
};

class BallPosition{
    private:
    int x;
    int y;

    public:
    BallPosition(){
        x=0;
        y=0;
    }

    BallPosition(int startX, int startY){
        x = startX;
        y = startY;
    }

    int getX() const {
        return x;
    }

    int getY() const {
        return y;
    }

    void resetX()  {
        x = 0;
    }

    void resetY()  {
        y = 0;
    }

    ballPos getPosition () const {
        return {x, y};
    }

    void move(int dx, int dy){
        x += dx;
        y += dy;
    }

    ~BallPosition(){}
};

class Goal {
    private:
    int x;
    int y;

    public:
    Goal(){
        x = 3;
        y = 3;
    }

    bool isGoalReached(int &ballX, int &ballY) const {
        if (ballX == x && ballY == y){
            return true;
        }
        return false;
    }

    ~Goal(){}
};

class Team {
    private:
    string teamName;
    Robot* robot;

    public:
    Team() {
        teamName = "";
        robot = nullptr;
    }

    Team (string n, Robot r1){
        teamName = n;
        robot = new Robot(r1);
    }

    string getName() const {
        return teamName;
    }

    Robot* getRobot() const {
        return robot;
    }

    ~Team(){
        delete robot;
    }
};

class Game{
    private:
    Team* teamOne;
    Team* teamTwo;
    BallPosition* ball;
    Goal* goal;

    public: 
    Game(Team* t1, Team* t2){
        teamOne = t1;
        teamTwo = t2;
        ball = new BallPosition();
        goal = new Goal();
    }

    //returns num of hits
    int play(Team *team){
        string direction;
        int x, y;
        ballPos currentBallPos;

        while(true){
            cout << team->getName() << endl;

            cout << "Enter direction to hit: " ;
            cin >> direction;

            x = ball->getX();
            y = ball->getY();

            team->getRobot()->hitBall(x, y, direction);

            ball->move(x - ball->getX(), y - ball->getY());

            currentBallPos = ball->getPosition();
            cout << "current ball position is: " << currentBallPos.x << ", " << currentBallPos.y << endl;

            x = currentBallPos.x;
            y = currentBallPos.y;
            
            if (goal->isGoalReached(x, y) == true){
                ball->resetX();
                ball->resetY();
                return team->getRobot()->getHits();
            }
        }
    }

    void declareWinner(int hits1, int hits2){
        if (hits1 < hits2)
            cout << teamOne->getName() << " WINS WITH " << teamOne->getRobot()->getHits() << " HITS!! " << endl;
        else if (hits1 > hits2)
            cout << teamTwo->getName() << " WINS WITH " << teamTwo->getRobot()->getHits() << " HITS!! " << endl;
        else 
            cout << "ITS A TIE" << endl;
    }

    void startGame(){
        int t1score = play(teamOne);
        int t2score = play(teamTwo);
        declareWinner(t1score, t2score);
    }

    ~Game(){
        delete ball;
        delete goal;
        delete teamOne;
        delete teamTwo;
    }
};

int main (){
    Robot robot1("AlphaBot");
    Robot robot2("BetaBot");
    Team team1("Team A", robot1);
    Team team2("Team B", robot2);
    Game game(&team1, &team2);
    game.startGame();
}