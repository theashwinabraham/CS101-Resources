/*
* AUTHOR: ASHWIN ABRAHAM
*/
#include <cmath>

bool is_armstrong(int n){
    int x = n, k = 0, sum = 0;
    for(; n>0; k++){n/=10;}
    n = x;
    while(n>0){
        int a = n%10;
        n/=10;
        int p = round(pow(a, k));
        sum+=p;
    }
    return sum==x;
}
int armstrong(int n){
    int ct = 0, i = 1;
    for(; ct < n; i++){if(is_armstrong(i)){ct++;}}
    return i-1;
}
