#include <iostream>
using namespace std;

int main(){
    int n, a, b, c;
    std::cin >> n >> a >> b >> c;
    for(int i = 0; i<n; ++i){
        int x;
        std::cin >> x;
        std::cout << a*x*x + b*x + c << std::endl;
    }
    return 0;
}
