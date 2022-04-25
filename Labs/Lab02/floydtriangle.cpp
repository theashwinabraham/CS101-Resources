#include <simplecpp>
main_program{
    int i = 0; //num to be printed
    int j = 1; //line number
    int n;
    cin >> n;
    repeat(n){
        repeat(j){
            i++;
            cout << i; //printing i
            if(i==j*(j+1)/2){ //checking if i is the last num on the line
                cout << endl; //going to new line
                j++; //incrementing line number
            }
            else{cout << " ";} //printing space between the nums
        }
    }
}
