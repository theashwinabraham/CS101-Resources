/*
* AUTHOR: ASHWIN ABRAHAM
*/
#include <iostream>

int main(){
    int n;
    std::cin >> n;
    int arr[n];
    for(int i = 0; i<n; i++){
        std::cin >> arr[i];
    }
    int i;
    for(i = n-1; i>0; i--){
        if(arr[i]>arr[i-1]){break;}
    }
    if(i==0){
        for(int j = 0; j<n; j++){
            std::cout << arr[n-1-j] << (j==(n-1)? "":" ");
        }
        return 0;
    }
    for(int j = 0; j<i-1; j++){std::cout << arr[j] << " ";}
    for(int j = n-1; j>=i; j--){
        if(arr[i-1]<arr[j]){
            std::cout << arr[j] << " ";
            arr[j] = arr[i-1];
            break;
        }
    }
    for(int j = n-1; j>=i; j--){std::cout << arr[j] << (j==i? "":" ");}
    return 0;
}
