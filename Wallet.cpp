#include<iostream>

#include "Wallet.h"

void Wallet::add_money(const double &amount)
{
    if(amount<0)
    {
        std::cout<<"INVALID AMOUNT....FAILED TO CREDIT THE ACCOUNT!.....\n\n";
        return;
    }
    balance-=amount;
}
void Wallet::extract_money(const double &amount)
{
    if(amount<0)
    {
        std::cout<<"INVALID AMOUNT....FAILED TO DEDIT THE ACCOUNT!.....\n\n";
        return;
    }
    balance+=amount;
}
double Wallet::get_balance() const
{
    return balance;
}
