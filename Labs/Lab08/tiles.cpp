/*
* AUTHOR: ASHWIN ABRAHAM
*/
int min_tiles(int w, int h){
    if(w*h == 0){return 0;}
    if(w%2 == 1 || h%2 == 1){return (h%2)*(w-w%2) + (w%2)*(h-h%2) +(w%2)*(h%2) + min_tiles(w-w%2, h-h%2);}
    return min_tiles(w/2, h/2);
}
