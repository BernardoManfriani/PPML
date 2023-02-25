#include<stdio.h>
#include<stdlib.h>
#include<time.h> //for time()
#include<vector>
#include<iostream>
#include"MazeGenerator.h"
#include"Particle.h"
#include<unistd.h>
#include<omp.h>
#include <ctime>
#include <ratio>
#include <chrono>


using namespace std;
//using namespace std::chrono;

//main function

int main(){
    vector<vector<int>> matrix(GRID_DIM, vector<int>(GRID_DIM, 0)); //matrix initialization
    MazeGenerator maze1(matrix);   //maze initialization

    vector<vector<int>> maze2 = maze1.getMaze(); //inserisco in una matrice il maze generato dalla classe
 
    //maze1.printMaze(maze2, 0); //print maze

    //vector<int> particlePosition{1,1};   //particle initialization
    Particle particle({1,1}, maze1);       //particle initialization

    vector<vector<int>> path = particle.getPath();  //path initialization

    //cout << path[0].size() << endl;
    //print path
    /*
    for(int i = 0; i < path.size(); i++){
            cout << "(" << path[i][0] << "," << path[i][1] << ")" << endl;
        //cout << endl;
    }
    */
        
    //print maze with path
    /*
    for(int i = 0; i < path.size(); i++){
        maze2[path[i][0]][path[i][1]] = 2;
    }*/
        
    //maze1.printMaze(maze2, 0);
        
        
    //per ogni punto senza vicini elimino il punto 
    // for(int i = 0; i < GRID_DIM - 1; i++){
    //     for(int j = 0 ; j < GRID_DIM - 1; j++){
    //         if (i > 0 && j > 0 && maze2[i][j] == 2){
    //             if((maze2[i + 1][j] == 0 || maze2[i + 1][j] == 1) && (maze2[i - 1][j] == 0 || maze2[i - 1][j] == 1) && (maze2[i][j + 1] == 0 || maze2[i][j + 1] == 1) && (maze2[i][j - 1] == 0 || maze2[i][j - 1] == 1)){
    //                     maze2[i][j] = 0;
    //             }
    //         }
    //     }
    // }

    return 0;
    
}