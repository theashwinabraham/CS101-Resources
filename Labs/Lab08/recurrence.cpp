/*
* AUTHOR: ASHWIN ABRAHAM
*/
int W(int n){
    return n<3? 1:(W(n-1)+W(n-2)+W(n-3));
}
