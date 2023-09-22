/*
 * point.h
 *
 *  Created on: Mar 1, 2023
 *      Author: umer
 */

#ifndef POINT_H_
#define POINT_H_
#include <iostream>
using namespace std;

class point {
private:
	int x;
	int y;
public:
	point();
	point(int a,int b);
	void setx(int a);
	void sety(int b);
	int getx();
	int gety();
	void plane();
	virtual ~point();
};

#endif /* POINT_H_ */
