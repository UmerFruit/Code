/*
 * Course.h
 *
 *  Created on: 05-Apr-2023
 *      Author: umerfarooq
 */

#ifndef COURSE_H_
#define COURSE_H_
#include "Instructor.h"
#include "Textbook.h"
class Course {
private:
	Instructor teacher;
	Textbook book;
public:
	Course(Instructor , Textbook);
	void print();
};

#endif /* COURSE_H_ */
