#include <simplecpp>
int perfect(int n){
    int sum = 0;
    for(int i = 1; i<n; i++){
        if(n%i==0){sum+=i;}
    }
    if(sum==n){return 1;}
    return 0;
}
