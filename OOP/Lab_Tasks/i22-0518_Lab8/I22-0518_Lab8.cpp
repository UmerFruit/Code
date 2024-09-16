//============================================================================
// Name        : Lab8.cpp
// Author      : Umer Farooq
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "IntegerList.h"
#include "Facebook.h"
#include "Complex.h"
int* GenderCount(Facebook [],int);
Complex addComplex(Complex &c1, Complex &c2);
Complex subComplex(Complex &c1, Complex &c2);
Complex mulComplex(Complex &c1, Complex &c2);

int main()
{



	//tast 2
//	Facebook arr[5];
//	int *count = GenderCount(arr,5);
	//task 1
//	IntegerList L2(5);
//	IntegerList L(L2);
//	for(int i=0;i<5;i++)
//	{
//		cout<<L.getElement(i);
//		L.setElement(i,i);
//	}
//	for(int i=0;i<5;i++)
//	{
//		cout<<"\n"<<L.getElement(i);
//	}
	return 0;
}
Complex addComplex(Complex &c1, Complex &c2)
{
	Complex temp;
	temp.real = c1.real + c2.real;
	temp.imaginary = c1.imaginary + c2.imaginary;
	return temp;
}
Complex subComplex(Complex &c1, Complex &c2)
{
	Complex temp;
	temp.real = c1.real - c2.real;
	temp.imaginary = c1.imaginary - c2.imaginary;
	return temp;
}
Complex mulComplex(Complex &c1, Complex &c2)
{
	//  (a+bi)(c+di) = (ac−bd) + (ad+bc)i
	//	a = real;
	//	b = imaginary;
	//	c = c1.real;
	//	d = c1.imaginary;
	Complex temp;
	temp.real = (c1.real*c2.real) - (c1.imaginary*c2.imaginary);
	temp.imaginary = (c1.real*c2.imaginary) + (c1.imaginary*c2.real);
	return temp;
}
int* GenderCount(Facebook arr[],int size)
{
	int* count = new int[2];			//first element males and second element female
	count[0] = 0;
	count[1] = 0;
	for(int i=0;i<size;i++)
	{
		if(arr[i].getGender() == 'M')
		{
			count[0]++;
		}
		else
		{
			count[1]++;
		}
	}
	return count;
}

