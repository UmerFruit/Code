/*
 * Point.cpp
 *
 *  Created on: 05-Apr-2023
 *      Author: umerfarooq
 */

#include "Point.h"

Point::Point():X(0),Y(0) {}
Point::Point(int x, int y):X(x),Y(y) {}

Point::Point(const Point &p)
{
	this->X = p.X;
	this->Y = p.Y;
}
int Point::getX() const
{
	return this->X;
}
int Point::getY() const
{
	return this->Y;
}

