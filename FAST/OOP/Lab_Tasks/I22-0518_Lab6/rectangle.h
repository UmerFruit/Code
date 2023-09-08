/*
 * rectangle.h
 *
 *  Created on: Mar 1, 2023
 *      Author: umer
 */

#ifndef RECTANGLE_H_
#define RECTANGLE_H_
#include<iostream>
using namespace std;
class rectangle {

private:
	int length;
	int width;

public:

	int area();
	int getl();
	int getw();
	void setl(int l);
	void setw(int w);
	int scale();
	void display();
	rectangle(int l, int w);
	virtual ~rectangle();
};

#endif /* RECTANGLE_H_ */
