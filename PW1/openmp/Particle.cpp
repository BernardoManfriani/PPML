#include <stdio.h>
#include <stdlib.h>	
#include <time.h>
#include <iostream>
#include <vector>
#include <unistd.h>
#include "Particle.h"
#include "MazeGenerator.h"
#include <algorithm>
#include <chrono>
#include <omp.h>


Particle::Particle(vector<int> particlePos, MazeGenerator maze){
    maze1 = maze.getMaze();    //initilize the maze
    move(maze);                //move the particle
}

void Particle::move(MazeGenerator maze){
    int direction, numThreads, threadID; 
    vector<int> particleTmp = particle;                    //particle position
    bool solutionFound = false;
    //time is to take on the parallel section
    //for(int i = 0; i < 100; i++){
    //int iteration = 0;
    //particle = {1,1};                           //particle position
    //particleTmp = particle;                     //save the particle position

    omp_set_dynamic(0);     // Explicitly disable dynamic teams
    omp_set_num_threads(8); // Use 4 threads for all consecutive parallel regions
    //maze1 = maze.getMaze();
#pragma omp parallel private(numThreads, threadID, direction, particleTmp, maze1, particle)
{        

    srand(time(NULL));
    vector<int> particleT = {1,1};                           //particle position
    vector<vector<int>> pathT;
    numThreads = omp_get_num_threads();
    threadID = omp_get_thread_num();
    maze1 = maze.getMaze();	
    if(threadID == 0){
        maze.printMaze(maze1, 0);                      //print the maze
    }
    auto start = chrono::high_resolution_clock::now();
    for (size_t i = 0; i < 10; i++){
        particleT = {1,1};                           //particle position
        particleTmp = particleT;                     //save the particle position
        while(particleT[0] != GRID_DIM - 1 || particleT[1] != GRID_DIM - 2){ 
            do{
                direction = rand() % 4;                 //random direction for the particle
                particleT = chooseDirection(direction, particleT);  //choose the direction for the particle
            }while(particleTmp == particleT);

            particleTmp = particleT;                     //save the particle position 
            findPath(particleT, pathT);                                 //generate the path

            maze1[particleT[0]][particleT[1]] = 2;        //put the particle in the maze
            if(solutionFound) break;
        }
    }
    solutionFound = true;
    auto finish = chrono::high_resolution_clock::now(); //end time

    chrono::duration<double> elapsed = finish - start;  //elapsed time 
    elapsed = elapsed / 10;                           //avg elapsed time
    if(particleT[0] == GRID_DIM - 1 && particleT[1] == GRID_DIM - 2){
        cout << "Elapsed time: " << elapsed.count() << endl;
        cout << "Solution found" << " thread: " << threadID << endl;
        path.insert(path.end(), pathT.begin(), pathT.end());
        maze.printMaze(maze1, 0);                      //print the maze
    }
    //double finish = omp_get_wtime();
    //double elapsed = finish - start;
    //cout << "Elapsed time: " << elapsed << "  Thread: " << threadID << endl;
}
    
}


vector<int> Particle::moveRight(vector<int> particleT) {
    if (maze1[particleT[0]][particleT[1] + 1] == 0 || maze1[particleT[0]][particleT[1] + 1] == 2) {
        particleT[1] = particleT[1] + 1;
    }
    return particleT;
}

vector<int> Particle::moveDown(vector<int> particleT) {
    if (maze1[particleT[0] + 1][particleT[1]] == 0 || maze1[particleT[0] + 1][particleT[1]] == 2) {
        particleT[0] = particleT[0] + 1;
    }
    return particleT;
}

vector<int> Particle::moveLeft(vector<int> particleT) {
    if (maze1[particleT[0]][particleT[1] - 1] == 0 || maze1[particleT[0]][particleT[1] - 1] == 2) {
        particleT[1] = particleT[1] - 1;
    }
    return particleT;
}

vector<int> Particle::moveUp(vector<int> particleT) {
    if (particleT[0] > 0 && (maze1[particleT[0] - 1][particleT[1]] == 0 || maze1[particleT[0] - 1][particleT[1]] == 2)) {
        particleT[0] = particleT[0] - 1;
    }
    return particleT;
}

vector<int> Particle::chooseDirection(int direction, vector<int> particleT) {
    switch (direction) {
        case 0:
            particleT = moveRight(particleT);
            break;
        case 1:
            particleT = moveDown(particleT);
            break;
        case 2:
            particleT = moveLeft(particleT);
            break;
        case 3:
            particleT = moveUp(particleT);
            break;
    }
    return particleT;
}

void Particle::findPath(vector<int> particleT, vector<vector<int>> pathT){                                                                                        //Backtracking the path of the particle insert in path vector the path of the particle
    if(pathT.size() > 2 && (pathT[pathT.size() - 2][0] == particleT[0] && pathT[pathT.size() - 2][1] == particleT[1])){  //if the particle is in the same direction of the previous one
        pathT.erase(pathT.end()); 
        pathT.erase(pathT.end() - 1);
    } else { 
        pathT.push_back(particleT);
    }

    //bool isPresent = true;        
    
    /*
    isPresent = find(path.begin(), path.end(), particle) != path.end();    //if particle is present in path then isPresent = true
    if(isPresent){
        path.erase(remove(path.begin(), path.end(), particle), path.end()); //if particle is present in path then erase it
        path.push_back(particle); 
    } else {
    path.push_back(particle); 
    }*/                         
}

vector<vector<int>> Particle::getPath(){
    return path;
}



