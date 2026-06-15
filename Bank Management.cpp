/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class BankAccount
{
private:
    int accountNumber;
    string name;
    double balance;

public:
    void createAccount()
    {
        cout << "Enter Account Number: ";
        cin >> accountNumber;

        cin.ignore();
        cout << "Enter Customer Name: ";
        getline(cin, name);

        cout << "Enter Initial Balance: ";
        cin >> balance;
    }

    void displayAccount()
    {
        cout << "\nAccount Number : " << accountNumber;
        cout << "\nCustomer Name  : " << name;
        cout << "\nBalance        : Rs." << balance << endl;
    }

    int getAccountNumber()
    {
        return accountNumber;
    }

    void deposit(double amount)
    {
        balance += amount;
        cout << "Amount Deposited Successfully!\n";
    }

    void withdraw(double amount)
    {
        if (amount > balance)
        {
            cout << "Insufficient Balance!\n";
        }
        else
        {
            balance -= amount;
            cout << "Withdrawal Successful!\n";
        }
    }

    double getBalance()
    {
        return balance;
    }

    void writeToFile()
    {
        ofstream file("bank.txt", ios::app);
        file << accountNumber << endl;
        file << name << endl;
        file << balance << endl;
        file.close();
    }
};

int main()
{
    BankAccount account;
    int choice;
    double amount;

    do
    {
        cout << "\n===== BANK MANAGEMENT SYSTEM =====\n";
        cout << "1. Create Account\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Check Balance\n";
        cout << "5. Display Account Details\n";
        cout << "6. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            account.createAccount();
            account.writeToFile();
            cout << "Account Created Successfully!\n";
            break;

        case 2:
            cout << "Enter Deposit Amount: ";
            cin >> amount;
            account.deposit(amount);
            break;

        case 3:
            cout << "Enter Withdrawal Amount: ";
            cin >> amount;
            account.withdraw(amount);
            break;

        case 4:
            cout << "Current Balance: Rs."
                 << account.getBalance() << endl;
            break;

        case 5:
            account.displayAccount();
            break;

        case 6:
            cout << "Thank You!\n";
            break;

        default:
            cout << "Invalid Choice!\n";
        }

    } while (choice != 6);

    return 0;
}