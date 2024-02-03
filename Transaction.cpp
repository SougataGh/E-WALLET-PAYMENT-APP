#include<iostream>

#include"Transaction.h"

void Transaction::set_transaction(const double &amount,const std::string &info)
{
    this->amount=amount;
    this->info=info;
}
void Transaction::show_transaction() const
{
    std::cout<<this->amount<<" : "<<this->info<<std::endl;
}
