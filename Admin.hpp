#ifndef ADMIN_H_INCLUDED
#define ADMIN_H_INCLUDED

#include<iostream>

class Admin
{
    std::string user_name="GhoshSougata";
    std::string password="Sougata@123";
    std::string ph_no="9932441962";
public:
    std::string get_user_name() const;
    std::string get_password() const;
    std::string get_ph_no() const;
};

#endif // ADMIN_H_INCLUDED
