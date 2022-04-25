/*
* AUTHOR: ASHWIN ABRAHAM
*/
#include <iostream>

int main(){
    int n;
    std::cin >> n;
    for(int i = 0; i<n; ++i){
        for(int j = 0; j<n; ++j){std::cout << "*" << (j==(n-1)? "":" ");}
        std::cout << std::endl;
        for(int j = 0; j<(n-1); ++j){std::cout << " *";}
        if(i<(n-1)){std::cout << std::endl;}
    }
    return 0;
}
