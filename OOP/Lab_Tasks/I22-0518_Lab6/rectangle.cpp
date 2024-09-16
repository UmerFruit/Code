/*
 * rectangle.cpp
 *
 *  Created on: Mar 1, 2023
 *      Author: umer
 */

#include "rectangle.h"

rectangle::rectangle(int l, int w) {
	// TODO Auto-generated constructor stub
	length=l;
	width=w;
}

int rectangle::area()
{
	return (length)*width;
}
int rectangle::getl()
{
	return length;
}
int rectangle::getw()
{
	return width;
}
void rectangle::setl(int l)
{
	length=l;
}
void rectangle::setw(int w)
{
	width=w;
}
int rectangle::scale()
{
	length++;
	width++;
	return (length+width);
}
void rectangle::display()
{

	cout<<"Lenght: "<<length<<endl;
	cout<<"Width: "<<width<<endl;
	cout<<"Area: "<<area()<<endl;
}


rectangle::~rectangle() {
	// TODO Auto-generated destructor stub
}
//int main()
//{
//	rectangle r1(5,3);
//	r1.display();
//	cout<<"Scale = "<<r1.scale();
//}

