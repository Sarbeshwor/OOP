#include <iostream>
#include <cstring>


using namespace std;
class Bank{
    private:
        int balance;
        char *name;
        char *accounNnumber;

    public:
        Bank(){
            balance = 0;
            name = nullptr;
            accounNnumber = nullptr;
        }
        Bank( int a ,const char * nam, const char *acnumber){
            balance = a;
            // nam = name;
            acnumber = accounNnumber;
            name = (char *)malloc(strlen(nam) + 1);
            strcpy(name, nam);
        }
        ~Bank(){
            free(name);
        }
        void addaccount(char *acnum, char * acname){
            name = (char *)malloc(strlen(acname) + 1);
            strcpy(name, acname);
            accounNnumber = (char *)malloc(strlen(acnum) + 1);
            strcpy(name, acnum);
        }
        int amountdetail(){
            int balan = balance;
            return balan;
        }
        int deposit( char *acnum, int amount){
            
            balance = balance + amount;
            
        }
        int withdraw(int amount){
            balance = balance - amount;
        }

        // void setName(const char *nam)
        // {
        //     free(name);
        //     name = (char *)malloc(strlen(nam) + 1);
        //     strcpy(name, nam);
        // }
};

class BankAccount{
    private:
        Bank accounts[100];
        int totalac;

    public:
        BankAccount(){
            totalac = 0;
        }
    void addAccount(const Bank & b){
        accounts[totalac] = b;
        totalac++;
    }
    // void deposit(const BankAccount & B){

    // }
    void displayallaccount()
    {
        for (int i = 0; i < totalac; i++)
        {
            cout << "Registered Accounts :" << endl;
            cout<< "Account Number: "<< accounts[i].
        }
        
    }
};
int main()
{
    Bank bank;
    // Add new bank accounts
    bank.addAccount("12345", "John Doe");
    bank.addAccount("67890", "Jane Smith");
    // Perform transactions
    bank.deposit("12345", 1000.0);
    bank.deposit("67890", 500.0);
    // Display account details
    bank.displayAllAccounts();
    // Perform transactions
    bank.withdraw("12345", 200.0);
    bank.withdraw("67890", 500.0);
    // Display account details after transaction
    bank.displayAllAccounts();
    // Remove an account
    bank.removeAccount("67890");
    // Display account details after removal
    bank.displayAllAccounts();
    // Add more accounts
    bank.addAccount("24680", "Sarah Adams");
    bank.addAccount("13579", "Michael Lee");
    // Perform transactions on the newly added accounts
    bank.deposit("24680", 1500.0);
    bank.deposit("13579", 200.0);
    bank.withdraw("13579", 100.0);
    bank.withdraw("24680", 300.0);
    // Display all accounts
    bank.displayAllAccounts();
    return 0;
}
