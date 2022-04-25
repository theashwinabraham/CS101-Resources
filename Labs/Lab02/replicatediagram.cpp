#include <simplecpp>
main_program{
    turtleSim();
    repeat(3){ //draws an equilateral triangle
        forward(100);
        left(120); //exterior angle of an equilateral triangle is 120 degrees
    }
    right(90);
    forward(150); //draws the rectangle
    left(90);     //draws the rectangle
    forward(100); //draws the rectangle
    left(90);     //draws the rectangle
    forward(150); //draws the rectangle
    wait(5);
}
