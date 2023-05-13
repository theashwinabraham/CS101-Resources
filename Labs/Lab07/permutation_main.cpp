#include <simplecpp>
void permutation(int &a, int &b, int &c, int n);

main_program
{
    int a, b, c, n;
    cin >> a >> b >> c >> n;
    permutation(a, b, c, n);
    cout << a << " " << b << " " << c << endl;
}
