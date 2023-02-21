#ifndef PARTICLE_H
#define PARTICLE_H

#include <vector>
#include <iostream>
#include <stdlib.h>	//for rand()
#include <time.h>	//for time()
#include "MazeGenerator.h"

using namespace std;

class Particle{
    public : 
        Particle(vector<int> particle, MazeGenerator maze);
        //void printParticle(vector<int> particle);
        void move(MazeGenerator maze);
        vector<int> chooseDirection(int direction);
        void moveRight();
        void moveDown();
        void moveLeft();
        void moveUp();
        vector<vector<int>> getPath();
         //find path
        
        

    private :
        vector<int> particle;
        vector<vector<int>> maze1;
        vector<vector<int>> path; 
        void findPath();
};


#endif