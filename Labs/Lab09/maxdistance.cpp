/*
* AUTHOR: ASHWIN ABRAHAM
*/
#include <iostream>

int main(){
    int n;
    std::cin >> n;
    int arr[n], first[n], last[n];
    for(int i = 0; i<n; i++){
        std::cin >> arr[i];
        first[i] = -1;
        last[i] = -1;
    }
    for(int i = 0; i<n; i++){
        if(first[arr[i]]==-1){first[arr[i]] = i;}
        last[arr[i]] = i;
    }
    int max_dist = 0;
    for(int i = 0; i<n; i++){
        if(last[i]-first[i]>max_dist){max_dist = last[i] - first[i];}
    }
    std::cout << max_dist;
    return 0;
}
