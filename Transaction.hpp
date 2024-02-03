#ifndef TRANSACTION_H_INCLUDED
#define TRANSACTION_H_INCLUDED

#include<iostream>
class Transaction
{
protected:

    double amount;
    std::string info;
public:
    Transaction():amount(0),info(""){}
     void set_transaction(const double &,const std::string &);
     inline void show_transaction() const;
};

#endif // TRANSACTION_H_INCLUDED
