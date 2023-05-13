/*
* AUTHOR: ASHWIN ABRAHAM
*/
#include <iostream>

int det(int* ptr, int n){
    if(n==1){
        return *ptr;
    }
    int Det = 0;
    for(int i = 0; i<n; i++){
        int subarr[n-1][n-1];
        for(int p = 1; p<n; p++){
            for(int q = 0; q<n; q++){
                if(q!=i){
                    subarr[p-1][(q>i)? q-1:q] = *(ptr + n*p + q);
                }
            }
        }
        Det+= (i%2==0? 1:-1)*(*(ptr+i))*det(&(subarr[0][0]), n-1);
    }
    return Det;
}

int main(){
    int n;
    std::cin >> n;
    int arr[n][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j<n; j++){
            std::cin >> arr[i][j];
        }
    }
    std::cout << det(&(arr[0][0]), n);
    return 0;
}
