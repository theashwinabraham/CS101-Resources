#include <iostream>
void quicksort(int arr[], int n){
    if(n<2){return;}
    if(n==2){
        if(arr[0]>arr[1]){
            int temp = arr[1];
            arr[1] = arr[0];
            arr[0] = temp;
        }
        return;
    }
    int num_leq = 0, num_g = 0;
    for(int i = 1; i<n; i++){
        if(arr[i]<=arr[0]){
            num_leq++;
        }
        else{num_g++;}
    }
    int leq[num_leq], g[num_g];
    int kleq = 0, kg = 0;
    for(int i = 1; i<n; i++){
        if(arr[i]<=arr[0]){
            leq[kleq] = arr[i];
            kleq++;
        }
        else{
            g[kg] = arr[i];
            kg++;
        }
    }
    quicksort(leq, num_leq);
    quicksort(g, num_g);
    arr[num_leq] = arr[0];
    for(int i = 0; i<num_leq; i++){
        arr[i] = leq[i];
    }
    for(int i = 0; i<num_g; i++){
        arr[num_leq+1+i] = g[i];
    }
    return;
}
int main(){
    int n;
    std::cin >> n;
    int arr[n];
    for(int i = 0; i<n; i++){
        std::cin >> arr[i];
    }
    quicksort(arr, n);
    for(int i = 0; i<n; i++){
        std::cout << arr[i] << (i==(n-1)? "":" ");
    }
    return 0;
}
