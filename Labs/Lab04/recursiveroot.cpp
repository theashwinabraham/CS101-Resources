/*
* AUTHOR: ASHWIN ABRAHAM
*/
#include <iostream>
#include <cmath>
using namespace std;

int main(){
    double x = 0;
    int n;
    cin >> n;
    for(int i = 0; i<n; i++){x = sqrt(2+x);}
    cout << fixed;
    cout.precision(2);
    cout << x;
    return 0;
}
