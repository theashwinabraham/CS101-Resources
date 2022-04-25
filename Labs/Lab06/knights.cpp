#include <simplecpp>
int is_in_board(int i, int j, int k){
    if(i>=0 && i<k && j>=0 && j<k){return 1;}
    return 0;
}
int knights(int k){
    int num = 0;
    for(int i = 0; i<k; i++){
        for(int j = 0; j<k; j++){
            num+=is_in_board(i+2, j-1, k)+is_in_board(i+2, j+1, k)+is_in_board(i-2, j-1, k)+is_in_board(i-2, j+1, k);
            num+=is_in_board(i+1, j+2, k)+is_in_board(i-1, j+2, k)+is_in_board(i+1, j-2, k)+is_in_board(i-1, j-2, k);
        }
    }
    return k*k*(k*k-1)/2 - num/2;
}
