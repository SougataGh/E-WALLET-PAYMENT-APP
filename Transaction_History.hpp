#ifndef TRANSACTION_HISTORY_H_INCLUDED
#define TRANSACTION_HISTORY_H_INCLUDED

#include<iostream>
#include<vector>

#include"Transaction.h"

class Transaction_History
{
    std::vector<Transaction> transactions;
public:
    void set_transaction_info(const double &,const std::string &);
    void show_all_transactions();
};
#endif // TRANSACTION_HISTORY_H_INCLUDED
