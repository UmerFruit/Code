/*
 * CurrentAccount.h
 *
 *  Created on: 03-May-2023
 *      Author: umerfarooq
 */

#ifndef CURRENTACCOUNT_H_
#define CURRENTACCOUNT_H_

#include "BankAccount.h"

class CurrentAccount: public BankAccount {
public:
	CurrentAccount(int = 0,int = 1);
	void amountWithdrawn(int amount);
	void amountDeposit(int amount);
};
CurrentAccount::CurrentAccount(int b,int id):BankAccount(b,id) {}
void CurrentAccount::amountWithdrawn(int amount)
{
	if((balance-amount) < 5000)
	{
		cout<<"Error, balance must not decrease from 5000"<<endl;
	}
	else balance -= amount;
}
void CurrentAccount::amountDeposit(int amount)
{
	balance += amount;
}

#endif /* CURRENTACCOUNT_H_ */
