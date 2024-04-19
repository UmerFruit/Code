/*
 * Money.cpp
 *
 *  Created on: 29-Mar-2023
 *      Author: umerfarooq
 */

#include "Money.h"

Money::Money():dollars(0),cents(0) {}
Money::Money(int dollar, int cents)
{
	this->dollars = dollar;
	while(cents>100)
	{
		dollars++;
		cents %= 100;
	}
	this->cents = cents;
}
Money Money::operator+(const Money &obj)
{
	Money* temp = new Money;
	temp->dollars = this->dollars + obj.dollars;
	temp->cents = this->cents + obj.cents;
	if(temp->cents>100)
	{
		temp->dollars++;
		temp->cents %= 100;
	}
	return *temp;
}
Money Money::operator-(const Money &obj)
{
	Money* temp = new Money;
	temp->dollars = this->dollars - obj.dollars;
	temp->cents = this->cents - obj.cents;
	if(temp->cents<0)
	{
		temp->dollars--;
		temp->cents += 100 ;
	}
	return *temp;
}
const Money Money::operator=(const Money &obj)
{
	this->dollars = obj.dollars;
	this->cents = obj.cents;
	return *this;
}
void Money::operator++ ()
{
	this->dollars++;
	this->cents++;
}
Money Money::operator++ (int)
{
	Money* temp = new Money;
	temp->dollars = this->dollars++;
	temp->cents = this->cents++;
	return *temp;
}
void Money::operator-- ()
{
	this->dollars--;
	this->cents--;
}
Money Money::operator-- (int)
{
	Money* temp = new Money;
	temp->dollars = this->dollars--;
	temp->cents = this->cents--;
	return *temp;
}
void Money::operator*= (const Money& right)
{
	this->dollars *= right.dollars;
	this->cents*= right.cents;
}
bool Money::operator!= (const Money& right)
{
	if((this->dollars == right.dollars) && (this->cents == right.cents))
	{
		return false;
	}
	else
	{
		return true;
	}
}
bool Money::operator > (const Money& right)
{
	if((this->dollars > right.dollars) && (this->cents > right.cents))
	{
		return true;
	}
	else
	{
		return false;
	}
}
istream& operator>> (istream & in,Money& right)
{
	cout<<"Enter Dollars"<<endl;
	in>>right.dollars;
	cout<<"Enter Cents"<<endl;
	in>>right.cents;
	return in;
}
ostream& operator<< (ostream &os,Money& right)
{
	os<<"Dollars = "<<right.dollars<<endl;
	os<<"Cents = "<<right.cents<<endl;
	return os;
}

Money::~Money() 
{
	//party karo yahan (iftaar wali obv because ramadan)
}

