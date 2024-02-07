#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>

#include"User.h"
#include"Merchant.h"
#include"Wrapper.h"
#include"Admin.h"

void Wrapper::create_account()
{
    std::string user_name,ph_no,passcode;
    std::cout<<"ENTER YOUR USER NAME : ";
    getline(std::cin,user_name);
    std::cout<<"ENTER YOUR PHONE NUMBER : ";
    std::cin>>ph_no;
    std::cout<<"SET YOUR PASSCODE : ";
    std::cin>>passcode;
    User user;
    user.set_user(user_name,ph_no,passcode);
    users.insert({ph_no,user});
}
void Wrapper::create_merchant_account()
{
    std::string user_name,ph_no,passcode;
    std::cout<<"ENTER YOUR USER NAME : ";
    getline(std::cin,user_name);
    std::cout<<"ENTER YOUR PHONE NUMBER : ";
    std::cin>>ph_no;
    std::cout<<"SET YOUR PASSCODE : ";
    std::cin>>passcode;
    Merchant m_user;
    m_user.set_user(user_name,ph_no,passcode);
    merchant_users.insert({ph_no,m_user});
    std::cout<<"YOUR MERCHANT ACCOUNT CREATED SUCESSFULY.....\n\n";
}
void Wrapper::make_payment()
{
    if(users.size()==0)
    {
        std::cout<<"NO ACCOUNT BEEN CRETAED YET : ";
        return;
    }
    std::string sender_ph_no,sender_passcode;
    std::cout<<"ENTER YOUR PHONE NUMBER : ";
    std::cin>>sender_ph_no;
    if(users.find(sender_ph_no)==users.end())
    {
        std::cout<<"NO ACCOUNT EXIST ON THIS NUMBER....\n\n";
        return;
    }
    std::cout<<"ENTER YOUR PASSCODE : ";
    std::cin>>sender_passcode;
    if(users[sender_ph_no].get_passcode()!=sender_passcode)
    {
        std::cout<<"INVALID PASSCODE.....\n\n";
        return;
    }
    std::cout<<"ENTER THE PHONE NUMBER OF THE RECEIVER : ";
    std::string receiver_ph_no;
    if(users.find(receiver_ph_no)!=users.end())
    {
        std::cout<<"ENTER THE AMOUNT YOU WANT TO PAY : ";
        double amount;
        std::cin>>amount;
        User &sender=users[sender_ph_no];
        User &receiver=users[receiver_ph_no];
        sender.extract_money(amount);
        receiver.add_money(amount);
        std::cout<<"\nRS . "<<amount<<" HAS BEEN DEBITED FROM YOUR ACCOUNT SUCESSFULLY.....\n\n";
        std::string info="TO - ";
        info+=receiver.get_user_name();
        sender.set_transaction_info(-amount,info);
        info="FROM - ";
        info+=sender.get_user_name();
        receiver.set_transaction_info(amount,info);
        return;
    }
    if(merchant_users.find(receiver_ph_no)!=merchant_users.end())
    {
        std::cout<<"ENTER THE AMOUNT YOU WANT TO PAY : ";
        double amount;
        std::cin>>amount;
        User &sender=users[sender_ph_no];
        Merchant &receiver=merchant_users[receiver_ph_no];
        sender.extract_money(amount);
        receiver.add_money(amount);
        std::cout<<"\nRS . "<<amount<<" HAS BEEN DEBITED FROM YOUR ACCOUNT SUCESSFULLY.....\n\n";
        std::string info="TO - ";
        info+=receiver.get_user_name();
        sender.set_transaction_info(-amount,info);
        info="FROM - ";
        info+=sender.get_user_name();
        receiver.set_transaction_info(amount,info);
        return;
    }
    std::cout<<"NO SUCH USER EXIST.....SORRY.......\n\n";
}
void Wrapper::show_all_users()
{
    Admin adm;
    std::cout<<"ENTER YOUR USER NAME & PASSWORD :\n";
    std::string str1,str2;
    std::cin>>str1>>str2;
    if(adm.get_user_name()!=str1||adm.get_password()!=str2)
    {
        std::cout<<"\nINVALID CREDENTIAL.....ADMIN LOGIN UNSUCESSFUL.....\n\n";
        return;
    }
    if(users.size()==0&&merchant_users.size()==0){
        std::cout<<"\nNO ACCOUNT CREATED......\n\n";
        return;
    }
    std::cout<<"\nLIST OF ALL USERS :\n\n";
    for(auto &x:users)
    {
        std::cout<<x.second<<std::endl;
    }
    for(auto &x:merchant_users)
    {
        std::cout<<x.second<<std::endl;
    }
}
void Wrapper::show_transaction_history()
{
    std::string ph_no,pcode;
    std::cout<<"ENTER YOUR PHONE NUMBER : ";
    std::cin>>ph_no;
    if(users.size()!=0 && users.find(ph_no)!=users.end())
    {
        std::cout<<"ENTER YOUR PASSCODE : ";
        std::cin>>pcode;
        User &user=users[ph_no];
        if(user.get_passcode()!=pcode)
        {
            std::cout<<"\nINCORRECT PASSCODE...CAN'T PROCEED FURTHUR.....\n\n";
            return;
        }
        std::cout<<"\nYOUR TRANSACTION HISTORY :\n\n";
        user.show_all_transactions();
        return;
    }
    if(merchant_users.size()!=0&&merchant_users.find(ph_no)!=merchant_users.end())
    {
        std::cout<<"ENTER YOUR PASSCODE : ";
        std::cin>>pcode;
        Merchant &m_user=merchant_users[ph_no];
        if(m_user.get_passcode()!=pcode)
        {
            std::cout<<"\nINCORRECT PASSCODE...CAN'T PROCEED FURTHUR.....\n\n";
            return;
        }
        std::cout<<"\nYOUR TRANSACTION HISTORY :\n\n";
        m_user.show_all_transactions();
        return;
    }
    std::cout<<"\nNO RECORDS FOUND.....SORRY.......\n\n";
}
void Wrapper::show_balance()
{
    if(users.size()==0&&merchant_users.size()==0)
{
    std::cout<<"NO ACCOUNT CREATED YET....\n\n";
    return;
}
std::string ph_no,pcode;
std::cout<<"ENTER YOUR PHONE NUMBER : ";
std::cin>>ph_no;
if(users.size()!=0&&users.find(ph_no)!=users.end())
{
    std::cout<<"ENTER YOUR PASSCODE : ";
    std::cin>>pcode;
    User &user=users[ph_no];
    if(user.get_passcode()!=pcode)
    {
        std::cout<<"INCORRECT PASSWORD.....\n\n";
        return;
    }
    /// std::cout<<"USER BALANCE : "<<std::endl;
    user.get_balance();
}
if(merchant_users.size()!=0&&merchant_users.find(ph_no)!=merchant_users.end())
{
    std::cout<<"ENTER YOUR PASSCODE : ";
    std::cin>>pcode;
    Merchant &m_user=merchant_users[ph_no];
    if(m_user.get_passcode()!=pcode)
    {
       std::cout<<"INCORRECT PASSWORD.....\n\n";
       return;
    }
    /// std::cout<<"M_USER BALANCE : "<<std::endl;
    m_user.get_balance();
}
}
