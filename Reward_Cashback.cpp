#include<iostream>
#include<unordered_map>
#include<vector>

#include"Reward_Cashback.h"
#include"User.h"

void Reward_Cashback::set_received_money(const double &amount,User &user)
{
    this->received_money.insert({user.get_user_name(),amount});
}
void Reward_Cashback::claim_reward(User &user,const double &amount)
{
    std::string name=user.get_user_name();
    if(received_money.find(name)==received_money.end())
    {
        std::cout<<"USER DOESN'T EXIST.....";
        return;
    }
    double x=received_money[name];
    if((x)/(this->criteria_amount)>=1)
    {
        std::cout<<"GET CASHBACK FOR PAYMENT (>=) "<<this->criteria_amount<<" RS.\n\n";
        return;
    }
    user.add_money(amount);
}
