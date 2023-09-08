/*
 * Instructor.cpp
 *
 *  Created on: 05-Apr-2023
 *      Author: umerfarooq
 */

#include "Instructor.h"

Instructor::Instructor()
{
	fname[0] = '\0';
	lname[0] = '\0';
	officenum[0] = '\0';
	designation[0] = '\0';
}
Instructor::Instructor (string lastname,string firstname,string officenumber,string designation)
{
	fname = firstname;
	lname = lastname;
	officenum = officenumber;
	this->designation = designation;
}
void Instructor::set(string lastname,string firstname,string officenumber,string designation)
{
	fname = firstname;
	lname = lastname;
	officenum = officenumber;
	this->designation = designation;
}
void Instructor::print()
{
	cout<<"First name : "<<fname<<endl;
	cout<<"Last name : "<<lname <<endl;
	cout<<"Office number : "<< officenum<<endl;
	cout<<"Designation : "<< designation<<endl;
}
