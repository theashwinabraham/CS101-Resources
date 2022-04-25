/*
* AUTHOR: ASHWIN ABRAHAM
*/
#include <iostream>
using namespace std;

void print_coordinates(int n){
    int orientation = 0, x = 0, y = 0;
    char input;
    for(int i = 0; i<n; i++){
        cin >> input;
        if(input=='L'){orientation++; orientation%=4; continue;}
        switch(orientation){
            case 0: x++; break;
            case 1: y++; break;
            case 2: x--; break;
            case 3: y--; break;
        }
    }
    cout << x << " " << y;
}
