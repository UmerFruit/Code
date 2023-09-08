/*
 * Instructor.h
 *
 *  Created on: 05-Apr-2023
 *      Author: umerfarooq
 */

#ifndef INSTRUCTOR_H_
#define INSTRUCTOR_H_
#include <iostream>
#include<cstring>
using namespace std;
class Instructor {
private:
	string fname;
	string lname;
	string officenum;
	string designation;
public:
	Instructor();
	Instructor (string lastname,string firstname,string officenumber,string designation);
	void set(string lastname,string firstname,string officenumber,string designation);
	void print();
};

#endif /* INSTRUCTOR_H_ */
