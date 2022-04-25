//this program works on other compilers but takes very long to accept an input in Simple CodeBlocks
#include <simplecpp>
main_program{
    int n;
    cin >> n;
    repeat(n){ //printing the first line
        cout << "*";
    }
    cout << "\n";
    int i = n-2;
    repeat(n-2){ //printing the intermediate lines
        repeat(i){
            cout << " "; //adding spaces
        }
        cout << "*" << endl; //printing *
        i--;
    }
    repeat(n){
        cout << "*"; //printing the last line
    }
}
