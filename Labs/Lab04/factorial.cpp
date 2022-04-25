/*
* AUTHOR: ASHWIN ABRAHAM
*/
#include <iostream>
using namespace std;

int main(){
    int n, fact = 1;
    cin >> n;
    for(int i = 1; i<n+1; i++){fact*=i;}
    cout << fact;
    return 0;
}
