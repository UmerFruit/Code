/*
 * SavingsAccount.h
 *
 *  Created on: 03-May-2023
 *      Author: umerfarooq
 */

#ifndef SAVINGSACCOUNT_H_
#define SAVINGSACCOUNT_H_

#include "BankAccount.h"

class SavingsAccount: public BankAccount {
public:
	SavingsAccount(int = 0,int = 1);
	void amountWithdrawn(int amount);
	void amountDeposit(int amount);
};
SavingsAccount::SavingsAccount(int b,int id):BankAccount(b,id) {}

void SavingsAccount::amountWithdrawn(int amount)
{
	if((balance-amount) < 10000)
	{
		cout<<"Error, balance must not decrease from 10000"<<endl;
	}
	else balance -= amount;
}
void SavingsAccount::amountDeposit(int amount)
{
	balance += amount;
}
#endif /* SAVINGSACCOUNT_H_ */
