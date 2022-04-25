#include <iostream>
#include "bank.h"

int main(){
    int n; // num_users
    std::cin >> n;

    // add users and read their initial balance
    Bank bank;
    for(int i=0; i<n; i++){
        int init_bal;
        std::cin >> init_bal;
        if((bank.add_user(init_bal)) == -1){
            std::cout << "Error: Max users reached" << std::endl;
        }
    }

    // bank collect requests from users
    int m; // num_reqs
    std::cin >> m;
    for(int i=0; i<m; i++){
        int user_id;
        bool is_deposit;
        int amount;
        std::cin >> user_id >> is_deposit >> amount;
        bank.add_request(user_id, is_deposit, amount);
    }
    // bank.print_requests();

    // process requests
    for(int i=0; i<bank.n_reqs; i++){
        Request req = bank.reqs[i];
        if(req.is_deposit){
            if(bank.users[req.user_id].deposit(req.amount) == -1){
                std::cout << "Error: User " << req.user_id << ": Deposit failed" << std::endl;
            }
        }else{
            if(bank.users[req.user_id].withdraw(req.amount) == -1){
                std::cout << "Error: User " << req.user_id << ": Withdraw failed" << std::endl;
            }
        }
    }

    // statements
    std::cout << "Final balances and statement:" << std::endl;
    for(int i=0; i<bank.n_users; i++){
        std::cout << "User " << i << ": " << "Balance = " << bank.get_balance(i) << ", num_deposits = " << bank.get_num_deposits(i) << ", num_withdrawals = " << bank.get_num_withdrawals(i) << std::endl;
        bank.print_user_history(i);
    }
    return 0;

}