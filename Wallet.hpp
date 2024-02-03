#ifndef WALLET_H_INCLUDED
#define WALLET_H_INCLUDED

class Wallet
{
    double balance;
public:
    Wallet():balance(0){}
    virtual void add_money(const double &amount);
    virtual void extract_money(const double &amount);
    virtual double get_balance() const;
};

#endif // WALLET_H_INCLUDED
