#include <simplecpp>
void hilbert(double s, int t, int angle){
    if(t==1){
        right(angle);
        for(int i = 0; i<3; i++){
            forward(s);
            left(angle);
        }
        right(2*angle);
        return;
    }
    right(angle);
    hilbert(s, t-1, -angle);
    forward(s);
    left(angle);
    hilbert(s, t-1, angle);
    forward(s);
    hilbert(s, t-1, angle);
    left(angle);
    forward(s);
    hilbert(s, t-1, -angle);
    right(angle);
    return;
}
main_program{
    double s;
    int t;
    cin >> s >> t;
    turtleSim();
    hilbert(s, t, 90);
    hide();
    wait(20);
}
