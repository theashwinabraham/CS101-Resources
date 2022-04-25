#include <simplecpp>
main_program{
    int b1, n1, cn1 = 0, b2, n2, cn2 = 0;
    cin >> b1 >> n1 >> b2 >> n2;
    int i = 0;
    while(n1!=0){
        int k = n1%10;
        cn1+=k*pow(b1, i);
        n1 = n1/10;
        i++;
    }
    i = 0;
    while(n2!=0){
        int k = n2%10;
        cn2+=k*pow(b2, i);
        n2 = n2/10;
        i++;
    }
    cout << cn1+cn2;
}
