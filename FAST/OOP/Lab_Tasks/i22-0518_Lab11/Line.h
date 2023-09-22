/*
 * Line.h
 *
 *  Created on: 05-Apr-2023
 *      Author: umerfarooq
 */

#ifndef LINE_H_
#define LINE_H_
#include "Point.h"
using namespace std;
class Line {
private:
	Point p1;
	Point p2;
public:
	Line();
	Line(int x1, int y1, int x2, int y2);
	Line(const Point &p1, const Point &p2);
	float findSlope();
	float findLength();
	Point& findMidPoint();
};

#endif /* LINE_H_ */
