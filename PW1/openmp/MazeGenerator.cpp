#include <iostream>
#include <stdlib.h>	//for rand()
#include <time.h>	//for time()
#include <vector>
#include "MazeGenerator.h"

using namespace std; //for omitting std::


MazeGenerator::MazeGenerator(vector<vector<int>> matrix){
    maze = matrix;
    maze = generateMaze(maze);
    //printMazeDot(generateMaze(maze));
}

void MazeGenerator::printMaze(vector<vector<int>> maze, int type){
    switch (type){
    case 0:
        printFancyMaze(maze);
        break;
    case 1:
        printMazeDot(maze);
        break;
    case 2:
        printMazeMatrix(maze);
        break;
    default:
        break;
    }

}

void MazeGenerator::printMazeDot(vector<vector<int>> maze){
        for(int i = 0; i < GRID_DIM; i++){
            for(int j = 0; j < GRID_DIM; j++){
                if(i == 0 && j == 1){
                    cout << "S";    //for the start
                    j++;
                }else if(i == GRID_DIM - 1 && j == GRID_DIM - 2){
                    cout << "E";    //for the end
                    j++;
                }
                if (maze[i][j] == 1){
                    cout << "#";    
                }else{
                    cout << " ";
                }
            }
            cout << endl;
        }
    }
void MazeGenerator::printMazeMatrix(vector<vector<int>> maze){
    for(int i = 0; i < GRID_DIM; i++){
        for(int j = 0; j < GRID_DIM; j++){
            cout << maze[i][j] << " ";
        }
        cout << endl;
    }
}
void MazeGenerator::printFancyMaze(vector<vector<int>> maze){     //PROBLEMA: HA SENSO PASSARE UNA MATRICE COME PARAMETRO? NON POSSO USARE LA MATRICE CHE HO DEFINITO NELLA CLASSE? 
    for(int i = 0; i < GRID_DIM; i++){
        for(int j = 0; j < GRID_DIM; j++){
            if(i == 0 && j == 1){
                cout << "S";    //for the start
                j++;
            }else if(i == GRID_DIM - 1 && j == GRID_DIM - 2){
                cout << "E";    //for the end
                j++;
            }
            if (maze[i][j] == 1){
                if (i > 0 && i < GRID_DIM - 1 && maze[i+1][j] == 1){
                    cout << "|";      //for the vertical walls
                }else{
                    if(i == GRID_DIM - 1){
                        cout << "‾";  //for the last line
                    }else{
                        cout << "_";  //for the first line and the other
                    }
                }
            }else if(maze[i][j] == 0){
                 cout << " ";        //for the empty space
            }else if(maze[i][j] == 2){  //for the path 
                    cout << "•";
            }                        
        }
        cout << endl;
    }
}

        
vector<vector<int>> MazeGenerator::getMaze(){ //returns maze
            return maze;
}



vector<vector<int>> MazeGenerator::generateBoard(vector<vector<int>> maze){
    for(int i = 0; i < GRID_DIM; i++){              //function that generate border and start and end
        for(int j = 0; j < GRID_DIM; j++){          
            if((i == 0 || i == GRID_DIM - 1 || j == 0 || j == GRID_DIM - 1)){
                    maze[i][j] = 1;
            }else{
                maze[i][j] = 0;
            }
            if(((i == 0 && j == 1) || (i == GRID_DIM-1 && j == GRID_DIM-2))){
                maze[i][j] = 0;
            }
        }
    }
    return maze;
}

vector<vector<int>> MazeGenerator::generateInternalWalls(vector<vector<int>> maze){
    for(int i = 1; i < GRID_DIM - 1; i++){          //generate internal walls
        for(int j = 1; j < GRID_DIM - 1; j++){
            if(i % 4 == 0){
            maze[i][j] = 1;
            }
            if(j % 4 == 0){
                maze[i][j] = 1;
            }
        }
    }
    return maze;
}

vector<vector<int>> MazeGenerator::generateRandomWalls(vector<vector<int>> maze){
    srand(7634567);                              //seed random number generator

    for(int i = 1; i < GRID_DIM - 1; i++){          //generate random horizontal walls
        for(int j = 4; j < GRID_DIM - 1; j=j+5){
            if(rand() % 2 == 0 && j != GRID_DIM - 2){
                maze[i][j] = 0;
                maze[i][j + 1] = 0;
                maze[i][j + 2] = 0;
            }

        }
    }
            
    for(int i = 4; i < GRID_DIM - 1; i=i+5){       //generate random vertical walls
        for(int j = 1; j < GRID_DIM - 1; j++){
            if(rand() % 2 == 0 && i != GRID_DIM - 2){
                maze[i][j] = 0;
                maze[i + 1][j] = 0;
                maze[i + 2][j] = 0;
            }

        }
    }
    return maze;
}
        
vector<vector<int>> MazeGenerator::generateMaze(vector<vector<int>> maze){ 
    maze = generateBoard(maze);
    maze = generateInternalWalls(maze);
    maze = generateRandomWalls(maze);
    return maze;
}



