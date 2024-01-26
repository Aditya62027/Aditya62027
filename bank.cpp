#include <iostream>
#include <vector>
using namespace std;
class BankAccount
{
private:
    string name;
    int accountNum;
    double balance;

public:
    BankAccount(string n, int ac, double bal)
    {
        name = n;
        accountNum = ac;
        balance = bal;
    }
    string getName()
    {
        return name;
    }
    int getAccountNum()
    {
        return accountNum;
    }

    double getbalance()
    {
        return balance;
    }

    void Deposit(double amount)
    {
        balance = balance + amount;
    }

    void Withdraw(double amount)
    {
        if (balance >= amount)
        {
            balance = balance - amount;
            cout << "\t\t Withdraw Successfully..." << endl;
        }
        else
        {
            cout << "\t\t Insufficient Balance....." << endl;
        }
    }
};

class BankManagement
{
private:
    vector<BankAccount> accounts;

public:
    void AddAccount(string name, int accountNum, double balance)
    {
        accounts.push_back(BankAccount(name, accountNum, balance));
    }
    void ShowallAccounts()
    {
        cout << "\t\tAll Accounts Holders " << endl;
        for (int i = 0; i < accounts.size(); i++)
        {
            cout << "Name :" << accounts[i].getName() << " Account Number :" << accounts[i].getAccountNum() << " Balance :" << accounts[i].getbalance() << endl;
        }
    }
    void searchAccount(int account)
    {
        cout << "\t\t Account Holder " << endl;
        for (int i = 0; i < accounts.size(); i++)
        {
            if (accounts[i].getAccountNum() == account)
            {
                cout << "Name :" << accounts[i].getName() << " Account Number :" << accounts[i].getAccountNum() << " Balance :" << accounts[i].getbalance() << endl;
            }
        }
    }
    BankAccount *findAccount(int accountNum)
    {
        for (int i = 0; i < accounts.size(); i++)
        {
            if (accounts[i].getAccountNum() == accountNum)
            {
                return &accounts[i];
            }
        }
    }
};

main()
{
    BankManagement bank;
    int choice;
    char option;
    do
    {
        system("cls");
        cout << "\t\t :: Bank Management System" << endl;
        cout << "\t\t Main Menu" << endl;
        cout << "\t\t 1. Create New Account" << endl;
        cout << "\t\t 2. Show all Accounts" << endl;
        cout << "\t\t 3. Search Account" << endl;
        cout << "\t\t 4. Deposit Money" << endl;
        cout << "\t\t 5. Withdraw Money" << endl;
        cout << "\t\t 6. Exit" << endl;
        cout << "\t\t ---------------- " << endl;
        cout << "\t\t Enter Your Choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            string name;
            int accountNum;
            double balance;
            cout << "\t\t Enter Name :";
            cin >> name;
            cout << "\t\t Enter Account Number : ";
            cin >> accountNum;
            cout << "\t\t Enter Initial Balance : ";
            cin >> balance;
            bank.AddAccount(name, accountNum, balance);
            cout << "\t\t Account Created Successfully... " << endl;

            break;
        }
        case 2:
        {
            bank.ShowallAccounts();
            break;
        }
        case 3:
        {
            int accountNum;
            cout << "Enter Account Number : ";
            cin >> accountNum;
            bank.searchAccount(accountNum);
            break;
        }

        case 4:
        {
            int accountNum;
            double amount;
            cout << "\t\t Enter Account Number to Deposit Money : ";
            cin >> accountNum;
            BankAccount *account = bank.findAccount(accountNum);
            if (account != NULL)
            {
                cout << "\t\t Enter Amount to Deposit : ";
                cin >> amount;
                account->Deposit(amount);
                cout << "\t\t" << amount << "Deposit Successfully...." << endl;
            }
            else
            {
                cout << "\t\t Account Not Found...." << endl;
            }
            break;
        }

        case 5:
        {
            int accountNum;
            double amount;
            cout << "\t\t Enter Account Number to Withdraw Money : ";
            cin >> accountNum;
            BankAccount *account = bank.findAccount(accountNum);
            if (account != NULL)
            {
                cout << "\t\t Enter Amount to Withdraw : ";
                cin >> amount;
                account->Withdraw(amount);
            }
            else
            {
                cout << "\t\t Account Not Found...." << endl;
            }
            break;
        }
        case 6:
        {
            exit(1);
        }
        }
        cout << "\t\t Do You Want to Continue or Exit [Yes/No] ?? ";
        cin >> option;
    } while (option == 'y' || option == 'Y');
};