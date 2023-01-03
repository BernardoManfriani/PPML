#include <iostream>
#include <stdlib.h>	//for rand()
#include <time.h>	//for time()
#include <vector>

using namespace std; //for omitting std::

const int GRID_DIM = 101;

// void printMaze(int maze[GRID_DIM][GRID_DIM]);
// void generateMaze(int maze[GRID_DIM][GRID_DIM]);

class Maze{
    public:
        Maze(vector<vector<int>> matrix){
            maze = matrix;
            
            printMaze(generateMaze(maze));
        }
        
        void printMaze(vector<vector<int>> maze){
            for(int i = 0; i < GRID_DIM; i++){
                for(int j = 0; j < GRID_DIM; j++){
                    if (maze[i][j] == 1){
                        cout << "#";
                    }
                    else{
                        cout << " ";
                    }
                }
                cout << endl;
            }
        }

        vector<vector<int>> getMaze(){
            return generateMaze(maze);
        }

    private:
        vector<vector<int>> maze;
        //std::vector<std::vector<int>> maze(GRID_DIM, std::vector<int>(GRID_DIM, 0));
        //int maze[GRID_DIM][GRID_DIM];

        vector<vector<int>> generateMaze(vector<vector<int>> maze){ 
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
            srand(time(NULL));                              //seed random number generator
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
            return maze;
        }
    
};


int main(){
    vector<vector<int>> matrix(GRID_DIM, std::vector<int>(GRID_DIM, 0));
    Maze maze1(matrix);
    maze1.printMaze(maze1.getMaze());
    //maze1.printMaze(maze1.getMaze()); 
}



