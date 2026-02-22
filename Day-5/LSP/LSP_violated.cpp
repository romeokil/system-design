#include<iostream>
#include<vector>
using namespace std;

class Accounts{
    public:
        virtual void deposit(double amount)=0;
        virtual void withdraw(double amount)=0;
};

// Savings Account
class savingAccounts:public Accounts{
    private:
        double balance;
    public:
        savingAccounts(){
            balance=0;
        }
        void deposit(double amount){
            if(amount<=0){
                cout<<"Sorry Negative or 0 balance can't be deposit"<<endl;
            }
            else{
                balance+=amount;
                cout<<"Amount Successfully Deposited "<< amount<<endl;
                cout<<"Available Balance "<<balance<<endl;
            } 
        }
        void withdraw(double amount){
            if(amount>balance){
                cout<<"Sorry Insufficient Balance"<<endl;
            }
            else{
                balance-=amount;
                cout<<"Amount Withdrawn is "<< amount<<endl;
                cout<<"Available Balance is "<<balance<<endl;
            }
        }

};
class currentAccounts:public Accounts{
    private:
        double balance;
    public:
        currentAccounts(){
            balance=0;
        }
        void deposit(double amount){
            if(amount<=0){
                cout<<"Sorry Negative or 0 balance can't be deposit"<<endl;
            }
            else{
                balance+=amount;
                cout<<"Amount Successfully Deposited "<< amount<<endl;
                cout<<"Available Balance "<<balance<<endl;
            }
        }
        void withdraw(double amount){
            if(amount>balance){
                cout<<"Sorry Insufficient Balance"<<endl;
            }
            else{
                balance-=amount;
                cout<<"Amount Withdrawn is "<< amount<<endl;
                cout<<"Available Balance is "<<balance<<endl;
            }
        }
};
// bhai dekho aisa hai ki fixedTermAccounts me toh withdraw ni hona chahiye na ,
// but hmlog esi me implement kr diye hai.
class fixedTermAccounts:public Accounts{
    private:
        double balance;
    public:
        fixedTermAccounts(){
            balance=0;
        }
        void deposit(double amount){
            if(amount<=0){
                cout<<"Sorry Negative or 0 balance can't be deposit"<<endl;
            }
            else {
                balance+=amount;
                cout<<"Amount Successfully Deposited "<< amount<<endl;
                cout<<"Available Balance "<<balance<<endl;
            }
        }
        void withdraw(double amount){
            throw logic_error("Can't withdraw from Fixed Term Account");
        }
};
class BankClients{
    private:
        vector<Accounts*> accounts;
    public:
        BankClients(vector<Accounts*> accounts){
            this->accounts=accounts;
        }
        void processTransactions(){
            for(Accounts* acc:accounts){
                // all accounts allow deposits.
                acc->deposit(1000); 
                // assuming all accounts support withdraw.
                try{
                    acc->withdraw(500);
                }
                catch(const logic_error& e){
                    cout<<"Exception. "<<e.what()<<endl;
                }
            }
        }
};
int main(){

    vector<Accounts*> accounts;
    accounts.push_back(new savingAccounts());
    accounts.push_back(new currentAccounts());
    accounts.push_back(new fixedTermAccounts());

    BankClients* client = new BankClients(accounts);
    client->processTransactions();
    return 0;


}