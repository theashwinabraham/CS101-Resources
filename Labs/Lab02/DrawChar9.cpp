/*
* AUTHOR: ASHWIN ABRAHAM
*/
#include <simplecpp>

int main(){
    float s; //size variable
    cin >> s; //entering size
    turtleSim(); //creating a Turtle and a Canvas
    forward(s); //drawing lower part of 9
    left(90);
    forward(s);
    right(90);
    repeat(4){ //drawing square
        left(90);
        forward(s);
    }
    wait(5);
    return 0;
}
