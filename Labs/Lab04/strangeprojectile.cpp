/*
* AUTHOR: ASHWIN ABRAHAM
*/
#include <simplecpp>

int main(){
    initCanvas();
    int click = getClick();
    Circle c(click/65536, click%65536, 10);
    c.penDown();
    int y = click%65536, p = -1, q = -1;
    float vx = 1, vy = -1;
    cout << vy << endl;
    int i = 1;
    while(i<=6){
        c.move(vx, vy);
        vy+=0.1;
        if(c.getY()>y){
            if(i<2){
                vy = -1;
                i++;
            }
            else{
                vy = p+q;
                p = q;
                q = vy;
                i++;
            }
            cout << vy << endl;
        }
    }
    wait(10);
    return 0;
}
