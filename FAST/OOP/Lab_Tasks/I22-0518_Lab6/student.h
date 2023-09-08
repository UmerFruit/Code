/*
 * student.h
 *
 *  Created on: Mar 1, 2023
 *      Author: umer
 */

#ifndef STUDENT_H_
#define STUDENT_H_

#include <iostream>
#include <string>

using namespace std;

class student {

private:
	string name;
	string rollnumber;
	int age;
	double cgpa;
public:
	student();
	student(string n,string r,int a,double gpa);
	void setname(string n);
	void setrolln(string r);
	void setage(int a);
	void setgpa(double gpa);

	string getname();
	string getrolln();
	int getage();
	double getgpa();

	virtual ~student();
};

#endif /* STUDENT_H_ */
