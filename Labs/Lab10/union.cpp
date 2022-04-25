#include <iostream>
int main(){
    int N, M;
    std::cin >> N >> M;
    char arrA[N], arrB[M];
    for(int i = 0; i<N; i++){
        std::cin >> arrA[i];
    }
    for(int i = 0; i<M; i++){
        std::cin >> arrB[i];
    }
    char un[M+N];
    for(int i = 0; i<M+N; i++){
        un[i] = 0;
    }
    int kA = 0, kB = 0;
    for(int i = 0; i<M+N; i++){
        if(kA < N && kB < M){
            char el_A = arrA[kA];
            char el_B = arrB[kB];
            if(el_A <= el_B){
                un[i] = el_A;
                kA++;
            }
            if(el_B <= el_A){
                un[i] = el_B;
                kB++;
            }
        }
        else if(kA >= N && kB < M){
            un[i] = arrB[kB];
            kB++;
        }
        else if(kA < N && kB>= M){
            un[i] = arrA[kA];
            kA++;
        }
    }
    char comp = 0;
    int num_unique = 0;
    for(int i = 0; i<M+N; i++){
        if(comp < un[i]){
            comp = un[i];
            num_unique++;
        }
    }
    char actual_union[num_unique];
    comp = 0;
    int k = 0;
    for(int i = 0; i<M+N; i++){
        if(comp < un[i]){
            actual_union[k] = un[i];
            comp = un[i];
            k++;
        }
    }
    for(int i = 0; i<num_unique; i++){
        std::cout << actual_union[i] << ((i==(num_unique-1))? "":" ");
    }
    return 0;
}
