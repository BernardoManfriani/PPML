#include <stdio.h>
#include <stdlib.h>	
#include <time.h>
#include <iostream>
#include <vector>
#include <unistd.h>
#include "Particle.h"
#include "MazeGenerator.h"
#include <algorithm>



Particle::Particle(vector<int> particlePos, MazeGenerator maze){
    maze1 = maze.getMaze();    //initilize the maze
    move(maze);  //move the particle
}

void Particle::move(MazeGenerator maze){
    int iteration = 0;  //counter for the while loop
    srand(time(NULL));
    int direction;
    
    while ((particle[0] != GRID_DIM - 1 || particle[1] != GRID_DIM - 2) && iteration < 10000000){ 

        vector<int> particleTmp = particle;  //save the particle position
        do{
            direction = rand() % 4;  //random direction for the particle
            //cout << "direction: " << direction << endl;
            particle = chooseDirection(direction);  //choose the direction for the particle
        }while(particleTmp == particle);

        particleTmp = particle;  //save the particle position

        //cout << "position of the particle: " << particle[0] << particle[1] << endl;
        //sleep(1);
        cout << "path" << iteration << endl;
        for(int i = 0; i < path.size(); i++){
            cout << "(" << path[i][0] << "," << path[i][1] << ")" << endl;
        }
        sleep(1);
        if (path.size() > 2 && (path[path.size() - 2][0] == particle[0] && path[path.size() - 2][1] == particle[1])){  //if the particle is in the same direction of the previous one
            path.erase(path.end()); //if particle is present in path then erase it  
            cout << "son qui" << particle[0] << particle[1] << endl;
        } else if(path[path.size() - 1][0] == particle[0] && path[path.size() - 1][1] == particle[1]) || (path[path.size() - 2][0] == particle[0] && path[path.size() - 2][1] == particle[1]) ){  //if the particle is in the same direction of the previous one
            path.erase(path.end()); //if particle is present in path then erase it       
            cout << "son qui" << particle[0] << particle[1] << endl;     // CAMBIARE TUTTO QUA DEVO METTERE LA POSIZIONE SUCCESSIVA. 
        } else {
            path.push_back(particle); //add the particle position to the path
            //cout<< particle[0] << particle[1] << " " << path[path.size() - 1][0] << path[path.size() - 1][1] << endl;
            //sleep(1);
        }
        } else {
            path.push_back(particle); //add the particle position to the path
            //cout<< particle[0] << particle[1] << " " << path[path.size() - 1][0] << path[path.size() - 1][1] << endl;
            //sleep(1);
        }

        //path.push_back(particle); //add the particle position to the path
        
        maze1[particle[0]][particle[1]] = 2;  //put the particle in the maze

        /*
        bool isPresent = true;        
        isPresent = find(path.begin(), path.end(), particle) != path.end();    //if particle is present in path then isPresent = true
        if(isPresent)
            path.erase(remove(path.begin(), path.end(), particle), path.end()); //if particle is present in path then erase it
        */    
        


        //maze1.printMaze(maze2);  //Necessario per eventualmente vedere il percorso

        iteration++;
        if(iteration % 500000 == 0){
            maze.printMaze(maze1,0);
            //sleep(3);
            cout << "i = " << iteration << endl;
        }

        // Allora qua devo mettere una roba che poi svuota le celle dove era prima il pallino. Così non si vede il percorso fatto e non sembrano celle occupate. Maybe funziona
    }
    
    if(iteration == 10000000){
        cout << "No solution found" << endl;
        maze.printMaze(maze1, 0);
    }
    else{
        cout << "Solution found" << endl;
        maze.printMaze(maze1, 0);
    }

    
}

void Particle::moveRight() {
    if (maze1[particle[0]][particle[1] + 1] == 0 || maze1[particle[0]][particle[1] + 1] == 2) {
        particle[1] = particle[1] + 1;
    }
}

void Particle::moveDown() {
    if (maze1[particle[0] + 1][particle[1]] == 0 || maze1[particle[0] + 1][particle[1]] == 2) {
        particle[0] = particle[0] + 1;
    }
}

void Particle::moveLeft() {
    if (maze1[particle[0]][particle[1] - 1] == 0 || maze1[particle[0]][particle[1] - 1] == 2) {
        particle[1] = particle[1] - 1;
    }
}

void Particle::moveUp() {
    if (particle[0] > 0 && (maze1[particle[0] - 1][particle[1]] == 0 || maze1[particle[0] - 1][particle[1]] == 2)) {
        particle[0] = particle[0] - 1;
    }
}

vector<int> Particle::chooseDirection(int direction) {
    switch (direction) {
        case 0:
            moveRight();
            break;
        case 1:
            moveDown();
            break;
        case 2:
            moveLeft();
            break;
        case 3:
            moveUp();
            break;
    }
    return particle;
}

vector<vector<int>> Particle::findPath(vector<int> position){ //Backtracking the path of the particle insert in path vector the path of the particle
    
    return path;                            

}

vector<vector<int>> Particle::getPath(){
    return path;
}




