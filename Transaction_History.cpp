#include<iostream>
#include<vector>

#include"Transaction.h"
#include"Transaction_History.h"

void Transaction_History::set_transaction_info(const double &amount,const std::string &info)
{
    Transaction transaction;
    transaction.set_transaction(amount,info);
    transactions.push_back(transaction);
}
void Transaction_History::show_all_transactions()
{
    if(transactions.size()==0)
    {
        std::cout<<"NO TRANSACTIONS BEEN HAPPENED YET.....\n\n";
        return;
    }
    for(auto &transaction:transactions)
    {
        transaction.show_transaction();
        std::cout<<std::endl;
    }
}
