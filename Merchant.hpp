#ifndef MERCHANT_H_INCLUDED
#define MERCHANT_H_INCLUDED

#include<iostream>
#include<string>

#include"User.h"
#include"Reward_Cashback.h"

class Merchant : public User,public Reward_Cashback
{
public:
    void set_user(const std::string&,const std::string&,const std::string&);
    inline double get_criteria_amount() const;
};
#endif // MERCHANT_H_INCLUDED
