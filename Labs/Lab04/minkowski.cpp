#include <simplecpp>
main_program{
    int n, p;
    double S = 0;
    cin >> n >> p;
    for(int i = 0; i<n; i++){
        double u, v;
        cin >> u >> v;
        S+=pow(abs(u-v), p);
    }
    cout << fixed;
    cout.precision(2);
    cout << pow(S, 1.0/p);
}
