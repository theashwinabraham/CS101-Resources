/*
* AUTHOR: ASHWIN ABRAHAM
*/
#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    for(int i = 0; i<n; ++i){ //printing the first line
        cout << "*";
    }
    cout << "\n";
    int i = n-2;
    for(int p = 0; p<(n-2); ++p){ //printing the intermediate lines
        for(int q = 0; q<i; ++q){
            cout << " "; //adding spaces
        }
        cout << "*" << endl; //printing *
        i--;
    }
    for(int j = 0; j<n; ++j){
        cout << "*"; //printing the last line
    }
    return 0;
}
