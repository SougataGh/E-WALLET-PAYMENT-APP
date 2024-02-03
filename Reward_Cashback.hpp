#ifndef REWARD_CASHBACK_H_INCLUDED
#define REWARD_CASHBACK_H_INCLUDED

#include<iostream>
#include<unordered_map>
#include"User.h"

class Reward_Cashback
{
protected:

    double criteria_amount;
    std::unordered_map<std::string,double> received_money;
public:
    virtual void set_received_money(const double &,User &);
    virtual void claim_reward(User &,const double&);
};
#endif // REWARD_CASHBACK_H_INCLUDED
