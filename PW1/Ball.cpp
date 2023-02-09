#include <stdio.h>
#include <stdlib.h>	
#include <time.h>
#include <iostream>
#include <vector>
#include <unistd.h>
#include "Ball.h"
#include "MazeGenerator.h"
#include <algorithm>



Ball::Ball(vector<int> ballPos, MazeGenerator maze){
    maze1 = maze.getMaze();    //inizializzo il maze
    move(maze);  //faccio muovere il pallino
}

void Ball::move(MazeGenerator maze){
    int iteration = 0;  //counter for the while loop
    srand(time(NULL));
    int direction;

    while ((ball[0] != GRID_DIM - 1 || ball[1] != GRID_DIM - 2) && iteration < 10000000){ 
        direction = rand() % 4;  //random direction for the ball
        //vector<int> tmp;  //tmp is the ball position before the move
        //tmp = ball;  //tmp is the ball position before the move
        ball = chooseDirection(direction);  //choose the direction for the ball
        
        /*
        //se tmp non è contenuto in path allora push_back
        bool isPresent = true;
        isPresent = std::find(path.begin(), path.end(), ball) != path.end();    //se ball è presente in path allora isPresent = true
        if(isPresent)
            path.erase(std::remove(path.begin(), path.end(), tmp), path.end()); //se tmp è presente in path allora lo elimino
            path.erase(std::remove(path.begin(), path.end(), ball), path.end()); //se ball è presente in path allora lo elimino
        if(!isPresent)                                                          //se ball non è presente in path allora isPresent = false*/
            path.push_back(ball);                                               //quindi push_back ball in path    

        

        maze1[ball[0]][ball[1]] = 2;  //put the ball in the maze
        //maze1.printMaze(maze2);  //Necessario per eventualmente vedere il percorso

        iteration++;
        if(iteration % 500000 == 0){
            maze.printMaze(maze1);
            //sleep(3);
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
                //path.push_back(ball[0]);
            }
            break;
        case 1:
            if (maze1[ball[0] + 1][ball[1]] == 0 || maze1[ball[0] + 1][ball[1]]  == 2){  //down
                ball[0] = ball[0] + 1;
                //path.push_back(ball[0]);
            }
            break;
        case 2:
            if (maze1[ball[0]][ball[1] - 1] == 0 || maze1[ball[0]][ball[1] - 1]  == 2){  //left
                ball[1] = ball[1] - 1;
                //path.push_back(ball[0]);
            }
            break;
        case 3:
            if (ball[0] > 0 && (maze1[ball[0] - 1][ball[1]] == 0 || maze1[ball[0] - 1][ball[1]]  == 2)){  //up
                ball[0] = ball[0] - 1;
                //path.push_back(ball[0]);
            }
            break;
        default:
            direction = rand() % 4;
            ball = chooseDirection(direction);
    }
    
    return ball;
}

vector<vector<int>> Ball::findPath(vector<int> position){ //Backtracking the path of the ball insert in path vector the path of the ball
    
    return path;                            

}

vector<vector<int>> Ball::getPath(){
    return path;
}




