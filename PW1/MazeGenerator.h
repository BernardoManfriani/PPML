#ifndef MAZE_GENERATOR_H
#define MAZE_GENERATOR_H    

//#include "MazeGenerator.h"
#include <vector>
#include <iostream>
#include <stdlib.h>	//for rand()
#include <time.h>	//for time()

using namespace std;

const int GRID_DIM = 101;

class MazeGenerator{
    public :
        MazeGenerator(vector<vector<int>> matrix);
        void printMaze(vector<vector<int>> maze);
        void printMazeDot(vector<vector<int>> maze);
        void printMazeMatrix(vector<vector<int>> maze);
        vector<vector<int>> getMaze();

    private : 
        //std::vector<std::vector<int>> maze(GRID_DIM, std::vector<int>(GRID_DIM, 0));
        //int maze[GRID_DIM][GRID_DIM];
        vector<vector<int>> maze;
        vector<vector<int>> generateMaze(vector<vector<int>> maze);
        vector<vector<int>> generateBoard(vector<vector<int>> maze);
        vector<vector<int>> generateInternalWalls(vector<vector<int>> maze);
        vector<vector<int>> generateRandomWalls(vector<vector<int>> maze);
};

#endif