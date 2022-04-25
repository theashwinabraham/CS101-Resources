/*
* AUTHOR: ASHWIN ABRAHAM
*/
#include <iostream>
#include <cstdlib>

void swap(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}

void quicksort(int arr[], int end, int begin = 0){
    if((end-begin)<=1) return;
    int pivot = begin+rand()%(end-begin), num_less = 0;
    for(int i = begin; i<end; ++i){
        if(arr[i]<arr[pivot]){
            swap(arr[i], arr[begin+num_less]);
            if(begin+num_less==pivot){pivot = i;}
            ++num_less;
        }
    }
    swap(arr[begin+num_less], arr[pivot]);
    quicksort(arr, begin+num_less, begin);
    quicksort(arr, end, begin+num_less+1);
}

int main(){
    srand(time(NULL)); rand();
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
