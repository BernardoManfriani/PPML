#include<stdio.h>
#include<stdlib.h>
#include<time.h> //for time()
#include<vector>
#include<iostream>
#include"MazeGenerator.h"
#include"Ball.h"
#include<unistd.h>

using namespace std;

//main function

int main(){
    vector<vector<int>> matrix(GRID_DIM, vector<int>(GRID_DIM, 0)); //matrix initialization
    MazeGenerator maze1(matrix);   //maze initialization

    vector<vector<int>> maze2 = maze1.getMaze(); //inserisco in una matrice il maze generato dalla classe
 
    maze1.printMaze(maze2);    //print maze

    //vector<int> ballPosition{1,1};   //ball initialization
    Ball ball({1,1}, maze1);    //ball initialization

    
    return 0;
    
}