#include <simplecpp>
main_program{
    int n, fact = 1;
    cin >> n;
    for(int i = 1; i<n+1; i++){fact*=i;}
    cout << fact;
}
