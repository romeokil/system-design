#include <iostream>
#include<vector>
using namespace std;

class depositsonlyAccounts
{
private:
    double balance;

public:
    depositsonlyAccounts()
    {
        balance = 0;
    }
    virtual void deposit(double amount)=0;
};
class WithdrawlAccounts : public depositsonlyAccounts
{
private:
    double balance;

public:
    WithdrawlAccounts()
    {
        balance = 0;
    }
    virtual void withdraw(double amount)=0;
};
class savingsAccounts:public WithdrawlAccounts{
    private:
        double balance;
    public:
        savingsAccounts(){
            balance=0;
        }
        void deposit(double amount)
    {
        if (amount <= 0)
        {
            cout << "Sorry Negative or 0 balance can't be deposit" << endl;
            cout << endl;
        }
        else
        {
            balance += amount;
            cout << "Amount Successfully Deposited " << amount << endl;
            cout << "Available Balance " << balance << endl;
            cout << endl;
        }
    }
    void withdraw(double amount)
    {
        if (amount > balance)
        {
            cout << "Sorry Insufficient Balance" << endl;
            cout << endl;
        }
        else
        {
            balance -= amount;
            cout << "Amount Withdrawn is " << amount << endl;
            cout << "Available Balance is " << balance << endl;
            cout << endl;
        }
    }
};
class currentAccounts:public WithdrawlAccounts{
    private:
        double balance;
    public:
        currentAccounts(){
            balance=0;
        }
        void deposit(double amount)
    {
        if (amount <= 0)
        {
            cout << "Sorry Negative or 0 balance can't be deposit" << endl;
            cout << endl;
        }
        else
        {
            balance += amount;
            cout << "Amount Successfully Deposited " << amount << endl;
            cout << "Available Balance " << balance << endl;
            cout << endl;
        }
    }
    void withdraw(double amount)
    {
        if (amount > balance)
        {
            cout << "Sorry Insufficient Balance" << endl;
            cout << endl;
        }
        else
        {
            balance -= amount;
            cout << "Amount Withdrawn is " << amount << endl;
            cout << "Available Balance is " << balance << endl;
            cout << endl;
        }
    }
};
class fixedTermAccounts:public depositsonlyAccounts{
    private:
        double balance;
    public:
        fixedTermAccounts(){
            balance=0;
        }
        void deposit(double amount)
    {
        if (amount <= 0)
        {
            cout << "Sorry Negative or 0 balance can't be deposit" << endl;
            cout << endl;
        }
        else
        {
            balance += amount;
            cout << "Amount Successfully Deposited " << amount << endl;
            cout << "Available Balance " << balance << endl;
            cout << endl;
        }
    }
};
class BankClient{
    private:
        vector<depositsonlyAccounts*> depositonlyaccounts;
        vector<WithdrawlAccounts*> Withdrawlaccounts;
    public:
        BankClient(vector<depositsonlyAccounts*> depositonlyaccounts,vector<WithdrawlAccounts*> Withdrawlaccounts){
            this->depositonlyaccounts=depositonlyaccounts;
            this->Withdrawlaccounts=Withdrawlaccounts;
        }
        void processTransactions(){
            for(WithdrawlAccounts* acc:Withdrawlaccounts){
                acc->deposit(1000);
                acc->withdraw(500);
            }
            for(depositsonlyAccounts* acc:depositonlyaccounts){
                acc->deposit(1000);
            }
        }
};
int main()
{   
    vector<WithdrawlAccounts*> Withdrawlaccounts;

    Withdrawlaccounts.push_back(new savingsAccounts());
    Withdrawlaccounts.push_back(new currentAccounts());

    vector<depositsonlyAccounts*> depositonlyaccounts;
    depositonlyaccounts.push_back(new fixedTermAccounts());

    BankClient* client= new BankClient(depositonlyaccounts,Withdrawlaccounts);
    client->processTransactions();

    return 0;
}