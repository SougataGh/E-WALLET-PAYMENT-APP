#include <iostream>
#include<vector>
#include<unordered_map>
#include<string>

#include "Admin.h"
#include "Transaction.h"
#include "User.h"
#include "Wallet.h"
#include "Wrapper.h"

int main()
{
   Wrapper wp;
    while(1)
    {
        system("cls");
        std::cout<<"\n\t\t\t\t\t\t\t-----------------------------------------------";
        std::cout<<"\n\t\t\t\t\t\t\t\t1) CREATE AN USER ACCOUNT : ";
        std::cout<<"\n\t\t\t\t\t\t\t\t2) CREATE AN MERCHANT ACCOUNT : ";
        std::cout<<"\n\t\t\t\t\t\t\t\t3) MAKE PAYMENT (NORMAL USERS ONLY) : ";
        std::cout<<"\n\t\t\t\t\t\t\t\t4) SHOW ALL USERS (ADMIN ONLY) : ";
        std::cout<<"\n\t\t\t\t\t\t\t\t5) YOUR TRANSACTION HISTORY : ";
        std::cout<<"\n\t\t\t\t\t\t\t\t6) YOUR BALANCE : ";
        std::cout<<"\n\t\t\t\t\t\t\t\t7) EXIT ";
        std::cout<<"\n\t\t\t\t\t\t\t-----------------------------------------------";
        std::cout<<std::endl;
        std::cout<<"\nENTER YOUR CHOICE : ";
        int ch;std::cin>>ch;
        switch(ch)
        {
        case 1:
            std::cin.ignore();
            wp.create_account();break;
        case 2:
            std::cin.ignore();
            wp.create_merchant_account();break;
        case 3:
            std::cin.ignore();
            wp.make_payment();break;
        case 4:
            std::cin.ignore();
            wp.show_all_users();break;
        case 5:
            std::cin.ignore();
            wp.show_transaction_history();break;
        case 6:
            wp.show_balance();break;
        case 7:
            exit(0);break;
        default:
            std::cout<<"INVALID CHOICE !......\n";
        }
        std::cout<<"TYPE [YES] IF YOU WANT TO CONTINUE ELSE TYPE [NO]\n: ";
        std::string str;
        std::cin>>str;
        if(str=="no"||str=="No"||str=="NO"){
            break;
        }
    }
    return 0;
}
