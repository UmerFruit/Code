/*
 * Employee.h
 *
 *  Created on: 03-May-2023
 *      Author: umerfarooq
 */

#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_
#include <iostream>
#include <cstring>
using namespace std;
class Employee {
protected:
string name;
int empID;
public:
	Employee(string = "Umer", int = 0);
};
Employee::Employee(string n,int id):name(n),empID(id) {}

#endif /* EMPLOYEE_H_ */
