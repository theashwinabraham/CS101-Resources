#include <simplecpp>
main_program{
    int n;
    int d = 5; //specified in instructions
    cin >> n; //Inputting size of central square
    turtleSim();
    repeat(4){
        right(90);
        forward(n); //drawing central square
        forward(d/2); //advancing forward by d/2 to draw vertex squares
        repeat(3){
            left(90);
            forward(d); //drawing vertex squares
        }
        left(90);
        forward(d/2); //going back to original position to continue drawing central square
    }
    wait(5);
}
