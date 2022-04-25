/*
* AUTHOR: ASHWIN ABRAHAM
*/
#include <simplecpp>

int main(){
    initCanvas();
    Circle c(200, 200, 50); //initialising circle
    int c1 = getClick();
    int c2 = getClick();
    int x1 = c1/65536; //getting x, y coordinates of click
    int y1 = c1%65536;
    int x2 = c2/65536; //getting x, y coordinates of click
    int y2 = c2%65536;
    Line l(x1, y1, x2, y2); //drawing line through clicked points
    float ang = atan2(y2-y1, x2-x1);
    Rectangle s(200, 200, 100, 100); //drawing square circumscribing the circle
    s.rotate(ang); //rotating square so that it is parallel to line
    wait(5);
    return 0;
}
