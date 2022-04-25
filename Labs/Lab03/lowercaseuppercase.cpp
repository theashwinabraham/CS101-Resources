#include <simplecpp>
main_program{
    char c;
    cin >> c;
    int x = c; //converting char into int of its ASCII value
    if(65<=x && x<=90){cout << "uppercase";} //ASCII values of uppercase alphabets are between 65 and 90
    else if(97<=x && x<=122){cout << "lowercase";} //ASCII values of lowercase alphabets are between 97 and 122
    else{cout << "this is not alphabet";} //other ASCII values do not represent alphabets
}
