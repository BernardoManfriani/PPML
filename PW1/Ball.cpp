#include <stdio.h>
#include <stdlib.h>	
#include <time.h>
#include <iostream>
#include <vector>
#include <unistd.h>
#include "Ball.h"
#include "MazeGenerator.h"



Ball::Ball(vector<int> ballPos, MazeGenerator maze){
    maze1 = maze.getMaze();    //inizializzo il maze
    move(maze);
}

void Ball::move(MazeGenerator maze){
    int iteration = 0;  //counter for the while loop
    srand(time(NULL));
    int direction;

    while ((ball[0] != GRID_DIM - 1 || ball[1] != GRID_DIM - 2) && iteration < 10000000){ 
        direction = rand() % 4;
        ball = chooseDirection(direction);
        maze1[ball[0]][ball[1]] = 2;
        //maze1.printMaze(maze2);  //Necessario per eventualmente vedere il percorso

        iteration++;
        if(iteration % 1000000 == 0){
            maze.printMaze(maze1);
            sleep(3);
            cout << "i = " << iteration << endl;
        }

        // Allora qua devo mettere una roba che poi svuota le celle dove era prima il pallino. Così non si vede il percorso fatto e non sembrano celle occupate. Maybe funziona
    }
    
    if(iteration == 10000000){
        cout << "No solution found" << endl;
        maze.printMaze(maze1);
    }
    else{
        cout << "Solution found" << endl;
        maze.printMaze(maze1);
    }

    
}

vector<int> Ball::chooseDirection(int direction){
    switch (direction){
        case 0:
            if (maze1[ball[0]][ball[1] + 1] == 0 || maze1[ball[0]][ball[1] + 1]  == 2){  //right
                ball[1] = ball[1] + 1; 
            }
            break;
        case 1:
            if (maze1[ball[0] + 1][ball[1]] == 0 || maze1[ball[0] + 1][ball[1]]  == 2){  //down
                ball[0] = ball[0] + 1;
            }
            break;
        case 2:
            if (maze1[ball[0]][ball[1] - 1] == 0 || maze1[ball[0]][ball[1] - 1]  == 2){  //left
                ball[1] = ball[1] - 1;
            }
            break;
        case 3:
            if (ball[0] > 0 && (maze1[ball[0] - 1][ball[1]] == 0 || maze1[ball[0] - 1][ball[1]]  == 2)){  //up
                ball[0] = ball[0] - 1;
            }
            break;
        default:
            break;
    }
    
    return ball;
}

