/*
 * Fraction.cpp
 *
 *  Created on: 26-Mar-2023
 *      Author: umerfarooq
 */

#include "Fraction.h"

Fraction::Fraction() : numer(0), denom(1) {}
Fraction::Fraction(int n) : numer(n), denom(1) {} // constructors
Fraction::Fraction(Fraction &f)
{
	numer = f.numer;
	denom = f.denom;
}
void Fraction::display()
{
	cout << "Numerator = " << numer << endl;
	cout << "Denominator = " << denom << endl;
}
Fraction::Fraction(int n, int d)
{
	if (d != 0)
	{
		numer = n;
		denom = d;
		normalize(); // constructors
	}
}
int Fraction::GCD(int num1, int num2) // cal gcd
{
	if (num2 == 0)
	{
		return num1;
	}
	else
	{
		return GCD(num2, num1 % num2);
	}
}
void Fraction::normalize()
{
	if (denom < 0)
	{
		denom = ~denom + 1;
	}
	int gcd = GCD(numer, denom); // normalize
	numer /= gcd;
	denom /= gcd;
}
void Fraction::store(int n, int d)
{
	if (d != 0)
	{
		numer = n;
		denom = d; // store in normalized state
		normalize();
	}
}
Fraction &Fraction::operator+(Fraction &f)
{
	Fraction *temp = new Fraction;
	temp->numer = (numer * f.denom) + (denom * f.numer);
	temp->denom = denom * f.denom; // take hcf and calculate
	temp->normalize();
	return *temp;
}
Fraction &Fraction::operator-(Fraction &f)
{
	Fraction *temp = new Fraction;
	temp->numer = (numer * f.denom) - (denom * f.numer);
	temp->denom = denom * f.denom;
	temp->normalize();
	return *temp;
}
Fraction &Fraction::operator*(Fraction &f)
{
	Fraction *temp = new Fraction;
	temp->numer = numer * f.numer;
	temp->denom = denom * f.denom;
	temp->normalize();
	return *temp;
}
Fraction &Fraction::operator/(Fraction &f)
{
	Fraction *temp = new Fraction;
	temp->numer = numer * f.denom;
	temp->denom = denom * f.numer;
	temp->normalize();
	return *temp;
}
Fraction &Fraction::operator+=(Fraction &f)
{
	numer = (numer * f.denom) + (denom * f.numer);
	denom = denom * f.denom;
	normalize();
	return *this;
}
Fraction &Fraction::operator-=(Fraction &f)
{
	numer = (numer * f.denom) - (denom * f.numer);
	denom = denom * f.denom;
	normalize();
	return *this;
}
Fraction &Fraction::operator*=(Fraction &f)
{
	numer = numer * f.numer;
	denom = denom * f.denom;
	normalize();
	return *this;
}
Fraction &Fraction::operator/=(Fraction &f)
{
	numer = numer * f.denom;
	denom = denom * f.numer;
	normalize();
	return *this;
}
Fraction &Fraction::operator<<(int s)
{
	numer <<= s;
	return *this;
}
Fraction &Fraction::operator>>(int s)
{
	numer >>= s;
	return *this;
}
bool Fraction::operator==(Fraction &f)
{
	float n1 = numer / denom, n2 = f.numer / f.denom;
	if (n1 == n2)
		return true;
	else
		return false;
}
bool Fraction::operator!=(Fraction &f)
{
	return !(*this == f);
}
bool Fraction::operator<(Fraction &f)
{
	float n1 = float(numer) / denom, n2 = float(f.numer) / f.denom;
	if (n1 < n2)
		return true;
	else
		return false;
}
bool Fraction::operator>(Fraction &f)
{
	float n1 = float(numer) / denom, n2 = float(f.numer) / f.denom;
	if (n1 > n2)
		return true;
	else
		return false;
}
bool Fraction::operator>=(Fraction &f)
{
	float n1 = float(numer) / denom, n2 = float(f.numer) / f.denom;
	if (n1 >= n2)
		return true;
	else
		return false;
}
bool Fraction::operator<=(Fraction &f)
{
	float n1 = float(numer) / denom, n2 = float(f.numer) / f.denom;
	if (n1 <= n2)
		return true;
	else
		return false;
}
int Fraction::operator[](int n)
{
	if (n == 0)
		return numer;
	else if (n == 1)
		return denom;
	else
		return -1;
}
Fraction &Fraction::operator++()
{
	numer++;
	denom++; // prefix inc
	return *this;
}
Fraction &Fraction::operator++(int)
{
	Fraction *temp = new Fraction;
	temp->numer = numer;
	temp->denom = denom; // postfix inc
	numer++;			 // return temp to return orignal value
	denom++;
	return *temp;
}
Fraction &Fraction::operator--()
{
	numer--; // prefix dec
	denom--;
	return *this;
}
Fraction &Fraction::operator--(int)
{
	Fraction *temp = new Fraction;
	temp->numer = numer;
	temp->denom = denom; // postfix inc
	numer--;			 // return temp to return orignal value
	denom--;
	return *temp;
}
int Fraction::operator()(int n)
{
	if (n == 0)
		return denom;
	else if (n == 1)
		return numer;
	else
		return -1;
}
bool Fraction::operator&&(Fraction &f)
{
	return (numer && f.numer);
}
bool Fraction::operator||(Fraction &f)
{
	return (denom || f.denom);
}
Fraction &Fraction::operator&(int n)
{
	numer = numer & n;
	denom = denom & n;
	return *this;
}
int &Fraction::operator->()
{
	return numer;
}

int Fraction::getDenominator() const
{
	return denom;
}

int Fraction::getNumerator() const
{
	return numer;
}

Fraction &Fraction::operator->*(Fraction *f)
{
	Fraction *F = &(*this * *f);
	return *F;
}