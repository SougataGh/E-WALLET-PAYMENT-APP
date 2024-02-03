#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED

#include<iostream>

#include"Wallet.h"
#include"Transaction_History.h"

class User : public Wallet,public Transaction_History
{
protected:

    std::string user_name;
    std::string ph_no;
    std::string passcode;
public:
    virtual void set_user(const std::string &,const std::string &,const std::string &);
    inline virtual std::string get_user_name() const;
    inline virtual std::string get_ph_no() const;
    inline 
virtual std::string get_passcode() const;
    friend std::ostream& operator<<(std::ostream&,User&);
};

#endif // USER_H_INCLUDED
