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
 
    //maze1.printMaze(maze2);    //print maze

    //vector<int> ballPosition{1,1};   //ball initialization
    Ball ball({1,1}, maze1);    //ball initialization

    vector<vector<int>> path = ball.getPath();  //path initialization

    //cout << path[0].size() << endl;
    //print path
    /*
    for(int i = 0; i < path.size(); i++){
            cout << "(" << path[i][0] << "," << path[i][1] << ")" << endl;
        //cout << endl;
    }
    */
    
    //print maze with path
    for(int i = 0; i < path.size(); i++){
        maze2[path[i][0]][path[i][1]] = 2;
    }
    
    maze1.printMaze(maze2);
    
    return 0;
    
}