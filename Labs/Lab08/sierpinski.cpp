#include <simplecpp>
void sierpinski(double s, int t){
    if(t == 1){
        for(int i = 0; i<3; i++){
            forward(s);
            left(120);
        }
        return;
    }
    sierpinski(s/2, t-1);
    forward(s/2);
    sierpinski(s/2, t-1);
    left(180);
    forward(s/2);
    right(120);
    forward(s/2);
    right(60);
    sierpinski(s/2, t-1);
    right(120);
    forward(s/2);
    left(120);
    return;
}
main_program{
    double s;
    int t;
    cin >> s >> t;
    turtleSim();
    sierpinski(s, t);
    hide();
    wait(2);
}
