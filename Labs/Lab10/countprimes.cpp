#include <iostream>
bool is_prime(int x, int primes[], int num_primes){
    if(num_primes==0){return true;}
    for(int i = 0; i<num_primes; i++){
        if(x%primes[i]==0){return false;}
    }
    return true;
}
int main(){
    int n;
    std::cin >> n;
    int primes[n], num_primes = 0;
    for(int i = 2; i<=n; i++){
        if(is_prime(i, primes, num_primes)){
            primes[num_primes] = i;
            num_primes++;
        }
    }
    std::cout << num_primes;
    return 0;
}
