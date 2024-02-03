#ifndef WRAPPER_H_INCLUDED
#define WRAPPER_H_INCLUDED

#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>

#include"User.h"
#include"Merchant.h"


class Wrapper
{
     std::unordered_map<std::string,User> users;
     std::unordered_map<std::string,Merchant> merchant_users;
 public:
     void create_account();
     void create_merchant_account();
     void make_payment();
     void show_all_users();
     void show_transaction_history();
     void show_balance();
};
#endif // WRAPPER_H_INCLUDED
