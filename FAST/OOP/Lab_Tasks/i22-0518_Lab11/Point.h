/*
 * Point.h
 *
 *  Created on: 05-Apr-2023
 *      Author: umerfarooq
 */

#ifndef POINT_H_
#define POINT_H_
#include <iostream>
#include <cmath>
using namespace std;
class Point {
private:
	int X;
	int Y;
public:
	Point();
	Point(int , int);
	Point(const Point &p);
	int getX() const;
	int getY() const;
};

#endif /* POINT_H_ */
