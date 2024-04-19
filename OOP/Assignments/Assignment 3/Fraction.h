/*
 * Fraction.h
 *
 *  Created on: 26-Mar-2023
 *      Author: umerfarooq
 */

#ifndef FRACTION_H_
#define FRACTION_H_
#include <iostream>
using namespace std;
class Fraction
{
private:
	int numer;
	int denom;

public:
	// constructors
	Fraction();
	Fraction(int);
	Fraction(int, int);
	Fraction(Fraction &);
	// utility functions
	void display();
	void normalize();
	int GCD(int, int);
	void store(int, int);
	// operator overloads
	Fraction &operator+(Fraction &);
	Fraction &operator-(Fraction &);
	Fraction &operator*(Fraction &);
	Fraction &operator/(Fraction &);
	Fraction &operator+=(Fraction &);
	Fraction &operator-=(Fraction &);
	Fraction &operator*=(Fraction &);
	Fraction &operator/=(Fraction &);
	Fraction &operator<<(int);
	Fraction &operator>>(int);
	Fraction &operator++();
	Fraction &operator++(int);
	Fraction &operator--();
	Fraction &operator--(int);
	Fraction &operator&(int);
	Fraction &operator->*(Fraction *f);
	bool operator==(Fraction &);
	bool operator!=(Fraction &);
	bool operator<(Fraction &);
	bool operator>(Fraction &);
	bool operator>=(Fraction &);
	bool operator<=(Fraction &);
	bool operator&&(Fraction &);
	bool operator||(Fraction &);
	int operator[](int);
	int operator()(int);
	int &operator->();
	int getDenominator() const;
	int getNumerator() const;
};

#endif /* FRACTION_H_ */
