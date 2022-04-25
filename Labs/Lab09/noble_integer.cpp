#include <iostream>
int main(){
    int n;
    std::cin >> n;
    int arr[n];
    for(int i = 0; i<n; i++){
        std::cin >> arr[i];
    }
    bool is_noble = false;
    for(int i = 0; i<n; i++){
        int count = 0;
        for(int j = 0; j<n; j++){
            if(arr[j]>arr[i]){count++;}
        }
        if(count==arr[i]){is_noble = true; break;}
    }
    std::cout << is_noble;
    return 0;
}
