#include<iostream>
using namespace std;
class BankAccount{
    private:
    double balance;
    public:
    BankAccount(){
        this->balance=0;
    }
    void printbalance(){
        cout<<"Balance of account is: "<<this->balance<<endl;
    }
    BankAccount(double balance){
        this->balance=balance;        
    }
    BankAccount(BankAccount &obj){
        this->balance=obj.balance;
    }
    void deductbalance(double deduct){
        this->balance-=deduct;
    }
};
int main()
{
   BankAccount account1;
   account1.printbalance();
   BankAccount account2(1000);
   account2.printbalance();
   BankAccount account3=account2;
   account3.deductbalance(200); //Account 3 balance deduction
   account3.printbalance(); //Print Account 3 balance
   account2.printbalance(); //Again print Account 2 balance to ensure it is not effected

    return 0;
}
