/*
* AUTHOR: ASHWIN ABRAHAM
*/
#include <iostream>
using namespace std;

int main(){
    int i = 0; //num to be printed
    int j = 1; //line number
    int n;
    cin >> n;
    for(int p = 0; p<n; ++p){
        for(int q = 0; q<n; ++q){
            i++;
            cout << i; //printing i
            if(i==j*(j+1)/2){ //checking if i is the last num on the line
                cout << endl; //going to new line
                j++; //incrementing line number
            }
            else{cout << " ";} //printing space between the nums
        }
    }
    return 0;
}
