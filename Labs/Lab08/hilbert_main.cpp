#include <simplecpp>
void hilbert(double s, int t, int angle);
main_program
{
    double s;
    int t;
    cin >> s >> t;
    turtleSim();
    hilbert(s, t, 90);
    hide();
    wait(2);
}