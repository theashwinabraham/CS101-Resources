#include <simplecpp>
main_program{
    double x = 0;
    int n;
    cin >> n;
    for(int i = 0; i<n; i++){x = sqrt(2+x);}
    cout << fixed;
    cout.precision(2);
    cout << x;
}
