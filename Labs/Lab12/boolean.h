/*
* AUTHOR: ASHWIN ABRAHAM
*/
#include <iostream>

const int MAX_SYMBOLS = 5; //useless
const int MAX_EXPR_SIZE = 20;

struct Symbol{ //useless
    char name;
    bool value;
};

struct Char{
    char expr;
    int sym_num;
    int op_num;
};

class BooleanExpr{
    private:
        int symbol_cnt;
        int expr_len;
        Symbol symbols[MAX_SYMBOLS]; //useless
        char expr[MAX_EXPR_SIZE];//useless

        Char Expr[MAX_EXPR_SIZE];

        BooleanExpr(int Symbol_cnt, int Expr_len, Char* pass_Expr): symbol_cnt(Symbol_cnt), expr_len(Expr_len){
            for(int i = 0; i<Expr_len; ++i){
                Expr[i] = pass_Expr[i];
            }
            return;
        }

        bool get_bool(unsigned int symbolvals, bool notsremoved){
            if(!notsremoved){
                Char pass_expr[MAX_EXPR_SIZE];
                for(int i = 0; i<expr_len; ++i){
                    pass_expr[i] = Expr[i];
                }
                for(int i = 0; i<expr_len; ++i){
                    if(pass_expr[i].expr == '!'){
                        if(pass_expr[i+1].expr == '!'){
                            pass_expr[i].expr = '\0';
                            pass_expr[i+1].expr = '\0';
                            pass_expr[i].op_num = -1;
                            pass_expr[i+1].op_num = -1;
                        }
                        else{
                            symbolvals = (symbolvals^(1<<(symbol_cnt - pass_expr[i+1].sym_num - 1)));
                            pass_expr[i].expr = '\0';
                            pass_expr[i].op_num = -1;
                        }
                    }
                }
                Char pass_Expr[MAX_EXPR_SIZE];
                int Expr_len = 0;
                for(int i = 0; i<expr_len; ++i){
                    if(pass_expr[i].op_num >=0 || pass_expr[i].sym_num >=0){
                        pass_Expr[Expr_len] = pass_expr[i];
                        ++Expr_len;
                    }
                }
                return BooleanExpr(symbol_cnt, Expr_len, pass_Expr).get_bool(symbolvals, true);
            }
            if(expr_len == 1){
                return (symbolvals&1);
            }
            if(Expr[1].expr == '+'){
                bool x = ((symbolvals>>(symbol_cnt-1))&1)&&((symbolvals>>(symbol_cnt-2))&1);
                if(x != ((symbolvals>>(symbol_cnt-2))&1)){symbolvals = symbolvals^(1<<(symbol_cnt-2));}
                return BooleanExpr(symbol_cnt-1, expr_len-2, &Expr[0]+2).get_bool(symbolvals, true);
            }
            bool x = ((symbolvals>>(symbol_cnt-1))&1)||((symbolvals>>(symbol_cnt-2))&1);
            if(x != ((symbolvals>>(symbol_cnt-2))&1)){symbolvals = symbolvals^(1<<(symbol_cnt-2));}
            return BooleanExpr(symbol_cnt-1, expr_len-2, &Expr[0]+2).get_bool(symbolvals, true);
        }

    public:
        BooleanExpr(): symbol_cnt(0), expr_len(0){return;}

        void read_expr(char* pass_Expr, int expr_size, char* Symbols, int symbols_size){
            expr_len = expr_size;
            symbol_cnt = symbols_size;
            /*for(int i = 0; i<symbols_size; ++i){
                symbols[i].name = Symbols[i];
            }*/
            int k_sym = 0, k_op = 0;
            for(int i = 0; i<expr_size; ++i){
                Expr[i].expr = pass_Expr[i];
                if(pass_Expr[i]=='!' || pass_Expr[i]=='+' || pass_Expr[i]=='*'){
                    Expr[i].sym_num = -1;
                    Expr[i].op_num = k_op;
                    ++k_op;
                }
                else{
                    Expr[i].sym_num = k_sym;
                    Expr[i].op_num = -1;
                    ++k_sym;
                }
            }
            return;
        }

        void print_truth_table(){
            for(int i = 0; i<expr_len; ++i){
                if(Expr[i].sym_num>=0){std::cout << Expr[i].expr << " ";}
            }
            std::cout << "-> (";
            for(int i = 0; i<expr_len; ++i){
                std::cout << Expr[i].expr;
            }
            std::cout << ")" << std::endl;
            unsigned int symbolvals_max = (1<<symbol_cnt);
            for(unsigned int symbolvals = 0; symbolvals < symbolvals_max; ++symbolvals){
                for(int i = (symbol_cnt-1); i>=0; --i){
                    std::cout << ((symbolvals>>i)&1) << " ";
                }
                std::cout << "-> " << get_bool(symbolvals, false);
                if(symbolvals<(symbolvals_max-1)){std::cout << std::endl;}
            }
            return;
        }
};
