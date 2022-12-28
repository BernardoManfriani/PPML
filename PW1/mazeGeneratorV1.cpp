#include <iostream>
#include <stdio.h>
#include <stdlib.h>	//for rand()

const int GRID_DIM = 101;

void printMaze(int maze[GRID_DIM][GRID_DIM]);
void generateMaze(int maze[GRID_DIM][GRID_DIM]);

int main(){
    int maze[GRID_DIM][GRID_DIM];
    generateMaze(maze);
    printMaze(maze);
}

//----FUNCTION--------------------------------------------

void printMaze(int maze[GRID_DIM][GRID_DIM]){
    for(int i = 0; i < GRID_DIM; i++){
        for(int j = 0; j < GRID_DIM; j++){
            if(maze[i][j] == 1){
                printf("#");
            }
            else{
                printf(" ");
            }
        }
        printf("\n");
    }
}

void generateMaze(int maze[GRID_DIM][GRID_DIM]){
    for(int i = 0; i < GRID_DIM; i++){              //generate border and start and end
        for(int j = 0; j < GRID_DIM; j++){          
            if((i == 0 || i == GRID_DIM - 1 || j == 0 || j == GRID_DIM - 1)){
                maze[i][j] = 1;
            }
            else{
                maze[i][j] = 0;
            }
            if(((i == 0 && j == 1) || (i == GRID_DIM-1 && j == GRID_DIM-2))){
                maze[i][j] = 0;
            }
        }
    }
    
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

    for(int i = 1; i < GRID_DIM - 1; i++){         //generate random walls
        for(int j = 4; j < GRID_DIM - 1; j=j+5){
            if(rand() % 2 == 0 && j != GRID_DIM - 2){
                maze[i][j] = 0;
                maze[i][j + 1] = 0;
                maze[i][j + 2] = 0;
            }

        }
    }
    
    for(int i = 4; i < GRID_DIM - 1; i=i+5){       //generate random walls
        for(int j = 1; j < GRID_DIM - 1; j++){
            if(rand() % 2 == 0 && i != GRID_DIM - 2){
                maze[i][j] = 0;
                maze[i + 1][j] = 0;
                maze[i + 2][j] = 0;
            }

        }
    }
}


