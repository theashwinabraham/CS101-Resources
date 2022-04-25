#include <simplecpp>
main_program{
    int a, b, c;
    a = 1; //initialise 1st level (print 1 *)
    b = 1; //initialise 2nd level (print 2 *s)
    int n;
    cin >> n;
    repeat(n){ //print n lines
        repeat(a){
            cout << "*"; //print * required number of times
        }
        cout << endl; //go to next line
        c = a + b; //Fibonacci recursive relation
        a = b; //move arr[1] to arr[0]
        b = c; //move arr[2] to arr[1]
    }
}
