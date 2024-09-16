/*
 *  Name : Umer Farooq
 *  Student ID : 22I-0518
 *  Assignment# 2
 */

#include <iostream>
using namespace std;
class Account
{
private:
    float balance;

public:
    Account(float = 0);
    void deposit(float);
    bool withdraw(float);
    float inquire();
};
Account::Account(float I)
{
    balance = I;
}
void Account::deposit(float d)
{
    balance += d;
}
bool Account::withdraw(float w)
{
    if (w > inquire())
    {
        balance -= 5;
        cout << "Error.Not Enough Money. $5 subtracted as fine" << endl; // withdraw check and penalty
        return false;
    }

    else
        balance -= w;
    return true;
}
float Account::inquire()
{
    return balance;
}
int main()
{
    Account a1(50);
    Account a2;
    cout<<a1.inquire()<<endl;
    cout<<a2.inquire()<<endl;
    a1.deposit(5000);
    cout<<a1.inquire()<<endl;
    a1.withdraw(1000);
    cout<<a1.inquire()<<endl;
    a1.withdraw(5000);
    cout<<a1.inquire()<<endl;
}