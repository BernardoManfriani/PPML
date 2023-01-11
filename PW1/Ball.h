#ifndef BALL_H
#define BALL_H

#include <vector>
#include <iostream>
#include <stdlib.h>	//for rand()
#include <time.h>	//for time()
#include "MazeGenerator.h"

using namespace std;

class Ball{
    public : 
        Ball(vector<int> ball, MazeGenerator maze);
        //void printBall(vector<int> ball);
        void move(MazeGenerator maze);
        vector<int> chooseDirection(int direction);

    private :
        vector<int> ball = {1,1};
        vector<vector<int>> maze1;
};


#endif