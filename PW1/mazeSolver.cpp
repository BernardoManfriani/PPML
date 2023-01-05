#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<vector>
#include<iostream>
#include "MazeGenerator.h"

using namespace std;

//main function

int main(){
    vector<vector<int>> matrix(GRID_DIM, std::vector<int>(GRID_DIM, 0));
    MazeGenerator maze1(matrix);
    //maze1.printMazeDot(maze1.getMaze());
    vector<vector<int>> maze2 = maze1.getMaze();
    //print matrix
    //maze1.printMazeMatrix(maze1.getMaze());
    
    maze2[1][2] = 2;
    maze1.printMaze(maze2);
}