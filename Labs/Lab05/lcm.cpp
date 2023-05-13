/*
* AUTHOR: ASHWIN ABRAHAM
*/
#include <iostream>
using namespace std;

int main(){
    int a, b;
    cin >> a >> b;
    int k = 1;
    while(true){
        if(a*k%b==0){break;}
        k++;
    }
    cout << a*k;
}
