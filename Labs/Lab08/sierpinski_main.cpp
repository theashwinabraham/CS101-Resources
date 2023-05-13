#include <simplecpp>
void sierpinski(double s, int t);
main_program
{
    double s;
    int t;
    cin >> s >> t;
    turtleSim();
    sierpinski(s, t);
    hide();
    wait(2);
}