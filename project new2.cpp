#include<iostream>
#include<vector>
class Bank{
    private:
    std::vector<std::string> account_numbers={"9981273941","9981273942","9812783943"};
    std::vector<std::string> account_password={"098123","618291","123233"};
    std::vector<long long int> account_amount={10000,800000,102931};
    std::vector<std::string> account_code={"122ks","1kwm2","siwn2"};
    std::vector<std::string> manager_ID={"901202","192092","321982"};
    std::vector<std::string> manager_password={"989ooj9jnbe2","oijep2j3n398","09dj83nbvg28"};
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
        int g=0;
        for(int i=0;i<account_numbers.size();i++){
            if (account_numbers[i]==entered_account_number){
                u=1;
                if (choice==4){
                    index=i;
                    return 1;
                }
                g=check_Account_password(i);
                
                break;
            }
        }
        if(u==0){
            std::cout<<"Invalid Account Number"<<std::endl;
            return 0;
        }
        return g;
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
    // manager Functions
    long long int manager_index;
    bool Manager_password_check(int i){
        std::string entered_password;
        std::cout<<"Enter the password:";
        std::cin>>entered_password;
        if (manager_password[i]==entered_password){
            manager_index=i;
            return 1;
        }else{
            std::cout<<"Invalid Password"<<std::endl;
            return 0;
        }
        

    }
    bool Manager_ID_check(std::string entered_manager_id){
        int u=0;
        int g=0;
        for(int i=0;i<manager_ID.size();i++){
            if(manager_ID[i]==entered_manager_id){
                u=1;
                g=Manager_password_check(i);
                break;
            }
        }
        if (u==0){
            std::cout<<"Invalid ID"<<std::endl;
            return 0;
        }
        return g;
    }
    void new_customer(int n){
        for (int i=0;i<n;i++){
            while(1){
                std::cout<<"Customer "<<i+1<<std::endl;
                int g=0;
                std::string new_customer_account_number,new_customer_account_password,new_customer_account_code;
                long long int new_customer_bank_balance;
                std::cout<<"Enter new customer account number:";
                std::cin>>new_customer_account_number;
                for (int j=0 ;j<account_numbers.size();j++){
                    if (account_numbers[j]==new_customer_account_number){
                        g=1;
                        break;
                    }
                }
                if(g==0){
                    std::cout<<"Enter new customer account password:";
                    std::cin>>new_customer_account_password;
                    std::cout<<"Enter new customer account code:";
                    std::cin>>new_customer_account_code;
                    std::cout<<"Enter new customer account bank balance:";
                    std::cin>>new_customer_bank_balance;
                    account_numbers.push_back(new_customer_account_number);
                    account_code.push_back(new_customer_account_code);
                    account_password.push_back(new_customer_account_password);
                    account_amount.push_back(new_customer_bank_balance);
                    break;
                }else{
                    std::cout<<"Account Number does not exist"<<std::endl;
                }

            }
        }
        std::cout<<"New customers details have been added successfully"<<std::endl;
    }

    void Delete_Account(int n){
        for(int i=0;i<n;i++){
            
            while(1){
                long long int delete_index;
                int u=0;
                std::cout<<"Customer "<<i+1<<std::endl;
                std::string entered_account_number;
                std::cout<<"Enter customer account number:";
                std::cin>>entered_account_number;
                for (int j=0;j<account_numbers.size();j++){
                    if(account_numbers[j]==entered_account_number){
                        u=1;
                        delete_index=j;
                        break;
                    }
                }
                if (u==1){
                    account_numbers.erase(account_numbers.begin()+delete_index);
                    account_password.erase(account_password.begin()+delete_index);
                    account_code.erase(account_code.begin()+delete_index);
                    account_amount.erase(account_amount.begin()+delete_index);
                    std::cout<<"The customer "<<i+1<<" account Details Deletion is successfull"<<std::endl;
                    break;
                }else{
                    std::cout<<"Account Number does not exist"<<std::endl;
                }
            }
        }
    }
};

int main(){
    int option;
    Bank Bank;
    int Type;
    
    std::cout<<"1.Customer\n"<<"2.Manager"<<std::endl;
    std::cout<<"Enter the option:";
    std::cin>>Type;
    if(Type==1){
        std::cout<<"1.Deposit\n"<<"2.Withdraw\n"<<"3.Bank Balance\n"<<"4.Password Change\n"<<"5.Exit"<<std::endl;
        std::cout<<"Enter The option:";
        
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
            if (option>5){
                std::cout<<"Invalid Option"<<std::endl;
            }
            std::cout<<"1.Deposit\n"<<"2.Withdraw\n"<<"3.Bank Balance\n"<<"4.Password Change\n"<<"5.Exit"<<std::endl;
            std::cout<<"Enter The option:";
            std::cin>>option;
            if(option==5){
                std::cout<<"Thank you "<<std::endl;
            }
        }
    }else if(Type ==2){
        std::cout<<"1.Add Customer\n"<<"2.Delete Customer\n"<<"3.Exit"<<std::endl;
        std::cout<<"Enter the option:";
        int option;
        std::cin>>option;
        while(option!=3){
            
            if (option==1 || option==2){
                std::string entered_Manager_ID;
                std::cout<<"Enter Manager ID:";
                std::cin>>entered_Manager_ID;
                if(Bank.Manager_ID_check(entered_Manager_ID)){
                    if(option==1){
                        //enter new customer
                        int num;
                        std::cout<<"Enter number of new customer details to be entered:";
                        std::cin>>num;
                        Bank.new_customer(num);
                    }else if(option==2){
                        //delete customer
                        std::cout<<"Enter total number of account to be deleted:";
                        int num;
                        std::cin>>num;
                        Bank.Delete_Account(num);
                    }
                }
            }
            if(option>3){
                std::cout<<"Invalid Choice"<<std::endl;
            }
            std::cout<<"1.Add Customer\n"<<"2.Delete Customer\n"<<"3.Exit"<<std::endl;
            std::cout<<"Enter the option:";
            std::cin>>option;
            
        }
    }else{
        std::cout<<"Invalid Option"<<std::endl;
    }
}
