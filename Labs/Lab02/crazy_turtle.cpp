#include <simplecpp>
main_program{
    turtleSim(); //creates a turtle and a canvas
    int tick = 1;
    repeat(360){ //drawing the diagram
        forward(59*sine(2*tick) + 29*sine(5*tick) + 13*sine(12*tick) + 2.1*sine(23*tick) + 1.7*sine(40*tick) - 59*sine(2*(tick-1)) - 29*sine(5*(tick-1)) - 13*sine(12*(tick-1)) - 2.1*sine(23*(tick-1)) - 1.7*sine(40*(tick-1)));
        right(90);
        penUp();
        forward(59*cosine(2*tick) + 29*cosine(5*tick) + 13*cosine(12*tick) + 2.1*cosine(23*tick) + 1.7*cosine(40*tick) - 59*cosine(2*(tick-1)) - 29*cosine(5*(tick-1)) - 13*cosine(12*(tick-1)) - 2.1*cosine(23*(tick-1)) - 1.7*cosine(40*(tick-1)));
        left(90);
        penDown();
        tick++;
    }
    left(90);
    penUp();
    forward(59+29-13+2.1+1.7);
    right(180);
    wait(10);
}
