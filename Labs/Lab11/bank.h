#include <iostream>
struct Transaction{
    int user_id;
    bool is_deposit;
    int amount;
    int balance;
    void print(){
        if(is_deposit){std::cout << user_id << " deposit " << amount << " " << balance << std::endl;}
        else{std::cout << user_id << " withdraw " << amount << " " << balance << std::endl;}
        return;
    }
};
struct User{
    int id;
    int balance;
    int n_deposits;
    int n_withdrawals;
    Transaction transaction_history[3];
    int deposit(int amount){
        balance+=amount;
        ++n_deposits;
        for(int i = 2; i>0; --i){
            transaction_history[i] = transaction_history[i-1];
        }
        transaction_history[0] = {id, true, amount, balance};
        return 0;
    }
    int withdraw(int amount){
        if(amount > balance){return -1;}
        balance-=amount;
        ++n_withdrawals;
        for(int i = 2; i>0; --i){
            transaction_history[i] = transaction_history[i-1];
        }
        transaction_history[0] = {id, false, amount, balance};
        return 0;
    }
    void print_history(){
        int n_to_print = (3<(n_deposits+n_withdrawals))? 3:(n_deposits+n_withdrawals);
        for(int i = 0; i < n_to_print; ++i){
            transaction_history[i].print();
        }
        return;
    }
};
struct Request{
    int user_id;
    bool is_deposit;
    int amount;
    void print(){
        if(is_deposit){std::cout << user_id << " deposit " << amount << std::endl;}
        else{std::cout << user_id << " withdraw " << amount << std::endl;}
        return;
    }
};
struct Bank{
    int n_users = 0;
    User users[10];
    int n_reqs = 0;
    Request reqs[10];
    int add_user(int init_bal){
        if(n_users==10){return -1;}
        users[n_users] = {n_users, init_bal, 0, 0};
        ++n_users;
        return 0;
    }
    void add_request(int user_id, bool is_deposit, int amount){
        if(n_reqs==10){return;}
        reqs[n_reqs] = {user_id, is_deposit, amount};
        ++n_reqs;
        return;
    }
    int get_balance(int user_id){
        return users[user_id].balance;
    }
    int get_num_deposits(int user_id){
        return users[user_id].n_deposits;
    }
    int get_num_withdrawals(int user_id){
        return users[user_id].n_withdrawals;
    }
    void deposit(int user_id, int amount){
        users[user_id].deposit(amount);
        return;
    }
    void withdraw(int user_id, int amount){
        users[user_id].withdraw(amount);
        return;
    }
    void print_user_history(int user_id){
        users[user_id].print_history();
        return;
    }
};
