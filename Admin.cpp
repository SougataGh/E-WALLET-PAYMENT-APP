#include<iostream>

#include"Admin.h"

std::string Admin::get_user_name() const
{
    return this->user_name;
}
std::string Admin::get_ph_no() const
{
    return this->ph_no;
}
std::string Admin::get_password() const
{
    return this->password;
}
