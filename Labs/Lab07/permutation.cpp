/*
* AUTHOR: ASHWIN ABRAHAM
*/
#include <vector>
using namespace std;

int fact(int n){
    if(n==0){return 1;}
    return n*fact(n-1);
}

void permute(vector<int> &v, int k){
    vector<int> u = v;
    int num = v.size();
    for(unsigned int i = 0; i<v.size(); i++){
        v[i] = u[k/fact(num-1)];
        for(unsigned int j = k/fact(num-1); j<u.size()-1; j++){u[j] = u[j+1];}
        u.pop_back();
        k%=fact(num-1);
        num--;
    }
    return;
}

void permutation(int &a, int &b, int &c, int n){
    vector<int> v = {a, b, c};
    permute(v, n-1);
    a = v[0];
    b = v[1];
    c = v[2];
    return;
}
