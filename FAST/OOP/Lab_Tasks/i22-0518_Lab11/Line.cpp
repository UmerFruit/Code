/*
 * Line.cpp
 *
 *  Created on: 05-Apr-2023
 *      Author: umerfarooq
 */

#include "Line.h"
Line::Line():p1(4,6),p2(2,4) {}

Line::Line(int x1, int y1, int x2, int y2):p1(x1,y1),p2(x2,y2){}

Line::Line(const Point &p1, const Point &p2)
{
	this->p1 = p1;
	this->p2 = p2;
}
float Line::findSlope()
{
	float num = p2.getY() - p1.getY();
	int denom = p2.getX() - p1.getX();
	float slope = num / denom;
	return slope;
}
float Line::findLength()
{
	float distance = sqrt(pow(p2.getX() - p1.getX(), 2) + pow(p2.getY() - p1.getY(), 2));
	return distance;
}
Point &Line::findMidPoint()
{
	int midpointX, midpointY;
	midpointX = (p1.getX() + p2.getX()) / 2;
	midpointY = (p1.getY() + p2.getY()) / 2;
	Point *Midpoint = new Point(midpointX , midpointY);
	return *Midpoint;
}
