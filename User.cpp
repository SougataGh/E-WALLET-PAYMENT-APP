#include<iostream>
#include<vector>
#include<string>

#include"Wallet.h"
#include"Transaction_History.h"
#include"User.h"

void User::set_user(const std::string &user_name,const std::string &ph_no,const std::string &passcode)
{
    this->user_name=user_name;
    this->ph_no=ph_no;
    this->passcode=passcode;
    std::cout<<"ENTER THE INITIAL AMOUNT YOU WANT TO CREDITED IN YOUR ACCOUNT : ";
    double amount;
    std::cin>>amount;
    this->add_money(amount);
    this->set_transaction_info(amount,"-INITIAL BALANCE");
}
std::ostream& operator<<(std::ostream& out,User &user)
{
    out<<"USER's NAME : "<<user.user_name<<std::endl;
    out<<"USER's PHONE NUMBER : "<<user.ph_no<<std::endl;
    out<<"USER's PASSCODE : "<<user.passcode<<std::endl;
    out<<"USER's CURRENT BALANCE : "<<user.get_balance()<<std::endl;
    return out;
}
std::string User::get_user_name() const
{
    return this->user_name;
}
std::string User::get_passcode() const
{
    return this->passcode;
}
std::string User::get_ph_no() const
{
    return this->ph_no;
}
