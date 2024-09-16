/*
 * student.cpp
 *
 *  Created on: Mar 1, 2023
 *      Author: umer
 */

#include "student.h"

using namespace std;
student::student() {
	// TODO Auto-generated constructor stub
	name="umer";
	rollnumber= "22I-0518";
	age=18;
	cgpa=2;
	cout<<"default constructor"<<endl;

}
student::student(string n,string r,int a,double gpa) {
	// TODO Auto-generated constructor stub
	name=n;
	rollnumber=r;
	age=a;
	cgpa=gpa;
	cout<<"Parameterized constructor"<<endl;

}


void student::setname(string n)
{
	name=n;
}
void student::setrolln(string r)
{
	rollnumber=r;
}
void student::setage(int a)
{
	age=a;
}
void student::setgpa(double gpa)
{
	cgpa=gpa;
}

string student::getname()
{
	return name;
}
string student::getrolln()
{
	return rollnumber;
}
int student::getage()
{
	return age;
}
double student::getgpa()
{
	return cgpa;
}

student::~student() {
	// TODO Auto-generated destructor stub
}
//int main()
//{
//	student s1;
//	student s2("umer","i22-0518",18,2.2);
//	s1.setage(60);
//	s1.setgpa(3.66);
//	s1.setname("insaan");
//	s1.setrolln("0518");
//	cout<<"Name: "<<s1.getname()<<endl;
//	cout<<"Age: "<<s1.getage()<<endl;
//	cout<<"Roll number : "<<s1.getrolln()<<endl;
//	cout<<"GPA: "<<s1.getgpa()<<endl;
//}
