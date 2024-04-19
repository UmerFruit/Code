/*
 * Money.h
 *
 *  Created on: 29-Mar-2023
 *      Author: umerfarooq
 */

#ifndef MONEY_H_
#define MONEY_H_
#include <iostream>
using namespace std;
class Money {
private:
	int dollars;
	int cents;
public:
	Money();
	Money(int dollar, int cents);
	Money operator+(const Money &obj);
	Money operator-(const Money &obj);
	const Money operator=(const Money &obj);
	void operator++ ();
	Money operator++ (int);
	void operator-- ();
	Money operator-- (int);
	void operator*= (const Money& right);
	bool operator!= (const Money& right);
	bool operator > (const Money& right);
	friend ostream& operator<< (ostream &os,Money& right);
	friend istream& operator>> (istream & in,Money& right);
	~Money();
};

#endif /* MONEY_H_ */
