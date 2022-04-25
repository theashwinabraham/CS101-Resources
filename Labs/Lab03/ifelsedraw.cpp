#include <simplecpp>
main_program{
    int n;
    cin >> n;
    turtleSim();
    if(n%2==0){
        repeat(3){ //Draws equilateral triangle of side length 100
            forward(100);
            left(120);
        }
    }
    else{
        repeat(4){ //Draws square of side length 100
            forward(100);
            left(90);
        }
    }
    wait(5);
}
