/*
 * point.cpp
 *
 *  Created on: Mar 1, 2023
 *      Author: umer
 */

#include "point.h"

point::point() {
	// TODO Auto-generated constructor stub
	x=0;
	y=0;
}

point::~point() {
	// TODO Auto-generated destructor stub
}
point::point(int a,int b) {
	// TODO Auto-generated constructor stub
	x=a;
	y=b;

}
void point::setx(int a)
{
	x=a;
}
void point::sety(int b)
{
	y=b;
}
int point::getx()
{
	return x;
}
int point::gety()
{
	return y;
}
void point::plane()
{
	cout<<"("<<x<<","<<y<<")"<<endl;
}
int main()
{
	point p1;
	point p2(5,5);
	p1.plane();
	p2.plane();

}

