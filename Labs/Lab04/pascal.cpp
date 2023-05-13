/*
* AUTHOR: ASHWIN ABRAHAM
*/
#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    cout << 1;
    if(n>1){cout << endl;}
    for(int i = 1; i<n; i++){
        cout << 1 << " ";
        for(int j = 1; j<i; j++){
            int q = 1;
            for(int k = 0; k<j; k++){
                q*=(i-k);
            }
            for(int k = 1; k<j+1; k++){
                q/=k;
            }
            cout << q << " ";
        }
        cout << 1;
        if(i!=n-1){cout << endl;}
    }
    return 0;
}
