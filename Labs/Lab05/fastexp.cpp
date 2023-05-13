/*
* AUTHOR: ASHWIN ABRAHAM
*/
#include <iostream>
using namespace std;

int main(){
    long long unsigned int x, n, k, prod = 1;
    cin >> x >> n >> k;
    x%=k;
    long long unsigned int p = x;
    while(n!=0){
        long long unsigned int a = n%2;
        if(a!=0){
            prod*=p;
            prod%=k;
        }
        p*=p;
        p%=k;
        n/=2;
    }
    cout << prod%k;
    return 0;
}
