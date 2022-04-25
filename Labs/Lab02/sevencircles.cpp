/*
* AUTHOR: ASHWIN ABRAHAM
*/
#include <simplecpp>

int main(){
    turtleSim();
    repeat(360){ //draws the central circle
        forward(PI/9); //radius = 20, so forward = 20*pi/180
        left(1);
    }
    repeat(6){
        repeat(60){ //moves the turtle on the central circle by 60 degrees
            forward(PI/9);
            left(1);
        }
        repeat(360){ //draws the lateral circles
            forward(PI/9); //radius = 20, so forward = 20*pi/180
            right(1);
        }
    }
    wait(5);
    return 0;
}
