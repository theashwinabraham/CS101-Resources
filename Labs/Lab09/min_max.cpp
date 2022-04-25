#include <iostream>
bool is_ext(int a, int b, int c){
    return ((b>a)&&(b>c))||((a>b)&&(c>b));
}
int main(){
    int n;
    std::cin >> n;
    if(n<4){std::cout << 0; return 0;}
    int a[n];
    for(int i = 0; i<n; i++){
        std::cin >> a[i];
    }
    int max_dec = 0;
    for(int i = 0; i<n; i++){
        int dec = 0;
        if(i<2){
            dec = is_ext(a[0], a[1], a[2]) + i*is_ext(a[1], a[2], a[3]);
        }
        else if(i>=(n-2)){
            dec = is_ext(a[n-3], a[n-2], a[n-1]) + (n-1-i)*is_ext(a[n-4], a[n-3], a[n-2]);
        }
        else{
            int p = is_ext(a[i-2], a[i-1], a[i]) + is_ext(a[i-1], a[i], a[i+1]) + is_ext(a[i], a[i+1], a[i+2]);
            int other[4] = {a[i-2], a[i-1], a[i+1], a[i+2]};
            for(int j = 0; j<4; j++){
                if(dec<(p-(is_ext(a[i-2], a[i-1], other[j]) + is_ext(a[i-1], other[j], a[i+1]) + is_ext(other[j], a[i+1], a[i+2])))){
                    dec = (p-(is_ext(a[i-2], a[i-1], other[j]) + is_ext(a[i-1], other[j], a[i+1]) + is_ext(other[j], a[i+1], a[i+2])));
                }
            }
        }
        if(max_dec < dec){max_dec = dec;}
    }
    int ridge_val = 0;
    for(int i = 1; i<n-1; i++){
        ridge_val+=is_ext(a[i-1], a[i], a[i+1]);
    }
    std::cout << ridge_val - max_dec;
    return 0;
}
