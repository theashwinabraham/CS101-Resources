#include <iostream>
#include "my_clock.h"
using namespace std;
int main()
{
    int hours, minutes, seconds;
    cin >> seconds;
    MyClock clock1(seconds);

    cin >> minutes >> seconds;
    MyClock clock2(minutes, seconds);

    cin >> hours >> minutes >> seconds;
    MyClock clock3(hours, minutes, seconds);
    
    cin >> hours >> minutes >> seconds;
    MyClock clock4(hours, minutes, seconds);

    int compare1 = clock1 < clock2;
    int compare2 = clock3 < clock4;


    clock1.currentTime();
    clock2.currentTime();
    clock3.currentTime();
    clock4.currentTime();

    cout << compare1 << endl;
    cout << compare2 << endl;

    cout << "Calling Destructor:" << endl;
    return 0;
}