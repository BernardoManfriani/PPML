#include<stdio.h>
#include<stdlib.h>
#include<time.h> //for time()
#include<vector>
#include<iostream>
#include"MazeGenerator.h"
#include<unistd.h>

using namespace std;

//main function

int main(){
    vector<vector<int>> matrix(GRID_DIM, std::vector<int>(GRID_DIM, 0));
    MazeGenerator maze1(matrix);
    //maze1.printMazeDot(maze1.getMaze());
    vector<vector<int>> maze2 = maze1.getMaze();
    //print matrix
    //maze1.printMazeMatrix(maze1.getMaze());
    
    //maze2[1][2] = 2;
    maze1.printMaze(maze2);

    vector<int> ball = {1,1};  //ball position

    int i = 0;  //counter
    srand(time(NULL));
    while ((ball[0] != GRID_DIM - 1 || ball[1] != GRID_DIM - 2) && i < 10000000){ 
        int direction = rand() % 4;
        switch (direction){
        case 0:
            if (maze2[ball[0]][ball[1] + 1] == 0 || maze2[ball[0]][ball[1] + 1]  == 2){  //right
                ball[1] = ball[1] + 1; 
                //cout << "right" << endl;
            }
            break;
        case 1:
            if (maze2[ball[0] + 1][ball[1]] == 0 || maze2[ball[0] + 1][ball[1]]  == 2){  //down
                ball[0] = ball[0] + 1;
                //cout << "down" << endl;
            }
            break;
        case 2:
            if (maze2[ball[0]][ball[1] - 1] == 0 || maze2[ball[0]][ball[1] - 1]  == 2){  //left
                ball[1] = ball[1] - 1;
                //cout << "left" << endl;
            }
            break;
        case 3:
            if (ball[0] > 0 && (maze2[ball[0] - 1][ball[1]] == 0 || maze2[ball[0] - 1][ball[1]]  == 2)){  //up
                ball[0] = ball[0] - 1;
                //cout << "up" << endl;
            }
            break;
        default:
            break;
        }
        maze2[ball[0]][ball[1]] = 2;
        //maze1.printMaze(maze2);
        i++;

        if(i % 1000000 == 0){
            maze1.printMaze(maze2);
            sleep(3);
            cout << "i = " << i << endl;
        }

        // Allora qua devo mettere una roba che poi svuota le celle dove era prima il pallino. Così non si vede il percorso fatto e non sembrano celle occupate. Maybe funziona
    }

    
    if(i == 10000000){
        cout << "No solution found" << endl;
        maze1.printMaze(maze2);
    }
    else{
        cout << "Solution found" << endl;
        maze1.printMaze(maze2);
    }
    
    
}