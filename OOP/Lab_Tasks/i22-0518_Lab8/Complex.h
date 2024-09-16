/*
 * Complex.h
 *
 *  Created on: Mar 15, 2023
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
	Complex(double = 1,double = 1);
	Complex(Complex &copy);
	double getImaginary() ;
	void setImaginary(double imaginary);
	double getReal() ;
	void setReal(double real);
	friend Complex addComplex(Complex &c1, Complex &c2);
	friend Complex subComplex(Complex &c1, Complex &c2);
	friend Complex mulComplex(Complex &c1, Complex &c2);

};

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
