#include<iostream>
#include<vector>
class Bank{
    private:
    std::vector<std::string> account_numbers={"9981273941","9981273942","9812783943"};
    std::vector<std::string> account_password={"098123","618291","123233"};
    std::vector<long long int> account_amount={10000,800000,102931};
    std::vector<std::string> account_code={"122ks","1kwm2","siwn2"};

    public:
    long long int index;
    bool check_Account_password(long long int i){
        std::string entered_password;
        std::cout<<"Enter Password:";
        std::cin>>entered_password;
        if (account_password[i]==entered_password){
            index=i;
            return 1;
        }else{
            std::cout<<"Invalid Password"<<std::endl;
            return 0;
        }

    }
    bool check_Account_Number(std::string entered_account_number,int choice){
        int u=0;
        for(int i=0;i<account_numbers.size();i++){
            if (account_numbers[i]==entered_account_number){
                u=1;
                if (choice==4){
                    index=i;
                    return 1;
                }
                check_Account_password(i);
                break;
            }
        }
        if(u==0){
            std::cout<<"Invalid Account Number"<<std::endl;
            return 0;
        }
        return 1;
    }
    void Deposit(long long int entered_amount){
        long long int new_amount=account_amount[index]+entered_amount;
        account_amount[index]=new_amount;
        std::cout<<account_amount[index]<<std::endl;
       
        std::cout<<"The Deposital is successfull"<<std::endl;
    }

    void Withdrawal(long long int entered_amount){
        if(account_amount[index]-entered_amount>5000){
            long long int new_amount=account_amount[index]-entered_amount;
            account_amount[index]=new_amount;
            
            std::cout<<"The Withdrawal is successfull"<<std::endl;
        }else{
            std::cout<<"Insufficient Funds"<<std::endl;
        }
    }

    void Check_Balance(){
        std::cout<<"The remaining Amount:"<<account_amount[index]<<std::endl;
    }

    void password_change(){
        std::cout<<"Enter the code:";
        std::string entered_code;
        std::cin>>entered_code;
        if (account_code[index]==entered_code){
            std::string new_password;
            std::cout<<"Enter the new password:";
            std::cin>>new_password;
            account_password[index]=new_password;
            
            std::cout<<"The password is changed successfully"<<std::endl;
        }else{
            std::cout<<"Invalid Code"<<std::endl;
        }
        
    }
};

int main(){
    int option;
    std::cout<<"1.Deposit\n"<<"2.Withdraw\n"<<"3.Bank Balance\n"<<"4.Password Change\n"<<"5.Exit"<<std::endl;
    std::cout<<"Enter The option:";
    Bank Bank;
    std::cin>>option;
    while (option!=5)
    {
        if (option==1 || option==2 ||option==3){
        std::string entered_account_number;
        std::cout<<"Enter Account Number:";
        std::cin>>entered_account_number;
        if(Bank.check_Account_Number(entered_account_number,option)){
            if(option==1){
                //deposit
                long long int amount;
                std::cout<<"Enter the amount to be deposited:";
                std::cin>>amount;
                Bank.Deposit(amount);
            }else if(option==2){
                //withdrawal
                long long int amount;
                std::cout<<"Enter the amount to be withdrawed:";
                std::cin>>amount;
                Bank.Withdrawal(amount);
            }else if (option==3){
                //check balance
                Bank.Check_Balance();

            }
        }
        }else if (option==4){
            std::string entered_account_number;
            std::cout<<"Enter Account Number:";
            std::cin>>entered_account_number;
            if(Bank.check_Account_Number(entered_account_number,option)){
                Bank.password_change();
            }
            
        }
        std::cout<<"1.Deposit\n"<<"2.Withdraw\n"<<"3.Bank Balance\n"<<"4.Password Change\n"<<"5.Exit"<<std::endl;
        std::cout<<"Enter The option:";
        std::cin>>option;
        if(option==5){
            std::cout<<"Thank you "<<std::endl;
        }
    }
}