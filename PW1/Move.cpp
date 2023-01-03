#include <stdio.h>
#include <stdlib.h>	

class Ball{
    public: 
        int index;
        int xPos;
        int yPos;
        void move(int direction);
        void chooseDirection();

    Ball(int index, int xPos, int yPos){
        this->index = index;
        this->xPos = xPos;
        this->yPos = yPos;
    }

    void move(int direction){
        switch(direction){  //0 = up, 1 = right, 2 = down, 3 = left
            case 0:
                this->yPos--;
                break;
            case 1:
                this->xPos++;
                break;
            case 2:
                this->yPos++;
                break;
            case 3:
                this->xPos--;
                break;
        }
    }

    void chooseDirection(){
        int direction = rand() % 4;
        this->move(direction);
    }

    
}

int main(){
    Ball ball(0, 0, 0);
    ball.move(1);
    printf("%d, %d", ball.xPos, ball.yPos);
}