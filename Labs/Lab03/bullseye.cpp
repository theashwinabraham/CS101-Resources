/*
* AUTHOR: ASHWIN ABRAHAM
*/
#include <simplecpp>

int main(){
    initCanvas();
    int k = 0;
    Circle c; // initialising circle c
    repeat(5){
        c.reset(250, 250, 180-40*k); //starting from outside, moving in
        if(k==4){c.setColor(COLOR("red"));} //innermost circle is red
        else if(k%2==1){c.setColor(COLOR("yellow"));} //others alternate between yellow
        else{c.setColor(COLOR("black"));} // and black
        c.setFill(true); //fill interior of circle
        c.imprint(); //imprint on canvas
        k++;
    }
    wait(5);
    return 0;
}
