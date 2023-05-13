#include <iostream>
#include "boolean.h"
using namespace std;

int main(){
    int expr_size;
    int symbols_size;
    cin >> expr_size >> symbols_size;
    char expr[expr_size];
    char symbols[symbols_size];

    for(int i=0; i<expr_size; i++){
        cin >> expr[i];
    }

    for(int i=0; i<symbols_size; i++){
        cin >> symbols[i];
    }

    BooleanExpr b;
    b.read_expr(expr, expr_size, symbols, symbols_size);
    b.print_truth_table();
}