/*
* AUTHOR: ASHWIN ABRAHAM
*/
#include <simplecpp>

int main(){
    turtleSim();
    left(42); //so that finally the turtle point slightly northeast (42 = 90-(30+(360/20)))
    repeat(20){ //design has 20 vertices
        forward(30); //arbitrary
        repeat(231){ //assumed that on average each circular arc subtended 240 degrees
            forward(0.075); //but since after each arm the turtle should have rotated right by 18 degrees (360/20)
            left(1); //both circles can't subtend the same angle, but their angles must differ by 18 degrees
        }            //so I made the outer circle 240-9 degrees and the inner one 240+9 degrees
        forward(30);
        repeat(249){
            forward(0.075); //number chosen so that inner circles touch
            right(1);
        }
    }
    wait(5);
    return 0;
}
