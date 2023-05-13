/*
* AUTHOR: ASHWIN ABRAHAM
*/
#include <iostream>
using namespace std;

int main(){
    int n;
    float x, s = 1, t = 1;
    cin >> x >> n;
    for(int i = 1; i<n+1; i++){
        t*=(-x*x)/(2*i*(2*i-1));
        s+=t;
    }
    cout << fixed;
    cout.precision(2);
    cout << x*s;
    return 0;
}
