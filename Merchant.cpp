#include<iostream>
#include<string>

#include"Merchant.h"
#include"User.h"
#include"Reward_Cashback.h"

void Merchant::set_user(const std::string &user_name,const std::string &ph_no,const std::string &passcode)
{
    User::set_user(user_name,ph_no,passcode);
    std::cout<<"ENTER THE CREDITED MONEY FOR WHICH YOU WANT TO GIVE CASHBACK : ";
    double amount;
    std::cin>>amount;
    this->criteria_amount=amount;
}
double Merchant::get_criteria_amount() const
{
    return this->criteria_amount;
}
