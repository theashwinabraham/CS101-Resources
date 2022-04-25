/*
* AUTHOR: ASHWIN ABRAHAM
*/
#include <iostream>
#include <cmath>

int main(){
    int n;
    std::cin >> n;
    int x[n];
    int y[n];
    for(int i = 0; i<n; i++){
        std::cin >> x[i];
    }
    for(int i = 0; i<n; i++){
        std::cin >> y[i];
    }
    int sum_x = 0, sum_y = 0, sum_xy = 0, sum_x2 = 0, sum_y2 = 0;
    for(int i = 0; i<n; i++){
        sum_x+=x[i];
        sum_y+=y[i];
        sum_xy+=(x[i]*y[i]);
        sum_x2+=(x[i]*x[i]);
        sum_y2+=(y[i]*y[i]);
    }
    int D_x = n*sum_x2 - (sum_x)*(sum_x);
    int D_y = n*sum_y2 - (sum_y)*(sum_y);
    if(D_x==0 || D_y==0){std::cout << -1; return 0;}
    double D = sqrt(D_x)*sqrt(D_y);
    double N = n*sum_xy - sum_x*sum_y;
    double correlation = N/D;
    std::cout << std::fixed;
    std::cout.precision(2);
    std::cout << correlation;
    return 0;
}
