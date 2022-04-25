/*
* AUTHOR: ASHWIN ABRAHAM
*/
#include <iostream>
using namespace std;

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    if(b*b>4*a*c){cout << "real and distinct";} //condition for real and distinct roots
    else if(b*b<4*a*c){cout << "complex";} //condition for complex roots
    else{cout << "real and same";} //when equality occurs, the roots are real and identical
    return 0;
}
