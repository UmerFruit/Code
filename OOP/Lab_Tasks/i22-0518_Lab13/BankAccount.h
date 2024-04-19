/*
 * BankAccount.h
 *
 *  Created on: 03-May-2023
 *      Author: umerfarooq
 */

#ifndef BANKACCOUNT_H_
#define BANKACCOUNT_H_
#include <iostream>
using namespace std;
class BankAccount {
protected:
int accID;
int balance;
public:
	BankAccount(int = 0,int = 1);
	int balanceInquiry();
};
BankAccount::BankAccount(int a,int b):balance(a),accID(b) {}
int BankAccount::balanceInquiry() 
{
	return balance;
}
#endif /* BANKACCOUNT_H_ */
