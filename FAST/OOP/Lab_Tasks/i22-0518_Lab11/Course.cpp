/*
 * Course.cpp
 *
 *  Created on: 05-Apr-2023
 *      Author: umerfarooq
 */

#include "Course.h"

Course::Course(Instructor i, Textbook t):teacher(i),book(t) {}
void Course::print()
{
    teacher.print();
    book.print();
}

