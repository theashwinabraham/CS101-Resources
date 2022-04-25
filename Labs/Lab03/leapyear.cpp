#include <simplecpp>
main_program{
    int x;
    cin >> x;
    if(x%400==0){cout << "Yes";} //if a year is divisible by 400 it is a leap year
    else if(x%4==0 && x%100!=0){cout << "Yes";} //if a year is divisible by 4 but not by 100 it is a leap year
    else{cout << "No";} //years that satisfy neither of the above conditions are not leap years
}
