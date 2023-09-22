/*
 * Complex.h
 *
 *  Created on: Mar 8, 2023
 *      Author: umer
 */

#ifndef COMPLEX_H_
#define COMPLEX_H_

class Complex
{
private:
	double real;
	double imaginary;
public:
	Complex(double=1,double =1);

	Complex(Complex &copy);
	double getImaginary() ;
	void setImaginary(double imaginary);
	double getReal() ;
	void setReal(double real);
	Complex addComplex( double r);
	Complex addComplex(Complex &c1);
	Complex subComplex(double r);
	Complex subComplex(Complex &c1);
	Complex mulComplex(double n);
	Complex mulComplex(Complex &c1);
};

Complex Complex::addComplex( double r)
{
	this->real += r;
	return *this;
}
Complex Complex::addComplex(Complex &c1)
{
	this->real += c1.real;
	this->imaginary += c1.imaginary;
	return *this;
}
Complex Complex::subComplex(double r)
{
	this->real -= r;
	return *this;
}
Complex Complex::subComplex(Complex &c1)
{
	this->real -= c1.real;
	this->imaginary -= c1.imaginary;
	return *this;

}
Complex Complex::mulComplex(double n)
{
	this->real *= n;
	this->imaginary *= n;
	return *this;

}
Complex Complex::mulComplex(Complex &c1)
{
	//(a+bi)(c+di) = (ac−bd) + (ad+bc)i
//	a = real;
//	b = imaginary;
//	c = c1.real;
//	d = c1.imaginary;

	this-> real = (real*c1.real) - (imaginary*c1.imaginary);
	this-> imaginary = (real*c1.imaginary) + (imaginary*c1.real);
	return *this;

}


Complex::Complex(double r, double i):real(r),imaginary(i)
{

}

double Complex::getImaginary(){
	return imaginary;
}

void Complex::setImaginary(double imaginary) {
	this->imaginary = imaginary;
}

double Complex::getReal(){
	return real;
}

void Complex::setReal(double real) {
	this->real = real;
}

Complex::Complex(Complex &copy)
{
	real = copy.real;
	imaginary = copy.imaginary;
}


#endif /* COMPLEX_H_ */
