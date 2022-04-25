#include <iostream>
int binary_search(int arr[], int lbound, int ubound, int l, int r){
    if(ubound-lbound == 1){return (arr[lbound]<=r)&&(arr[lbound]>=l);}
    if(arr[(ubound+lbound)/2]>r){return binary_search(arr, lbound, (ubound+lbound)/2, l, r);}
    if(arr[(ubound+lbound)/2]<l){return binary_search(arr, (ubound+lbound)/2, ubound, l, r);}
    return binary_search(arr, lbound, (ubound+lbound)/2, l, r) + binary_search(arr, (ubound+lbound)/2, ubound, l, r);
}
int main(){
    int n = 1000, l = 0, r = 1998;
    std::cin >> n >> l >> r;
    int arr[n];
    for(int i = 0; i < n; i++){
        std::cin >> arr[i];
    }
    int num_pairs = 0;
    for(int i = 0; i<n-1; i++){
        num_pairs+=binary_search(arr, i+1, n, l-arr[i], r-arr[i]);
    }
    std::cout << num_pairs;
    return 0;
}
