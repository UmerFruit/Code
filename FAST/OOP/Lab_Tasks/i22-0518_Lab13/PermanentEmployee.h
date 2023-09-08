/*
 * PermanentEmployee.h
 *
 *  Created on: 03-May-2023
 *      Author: umerfarooq
 */

#ifndef PERMANENTEMPLOYEE_H_
#define PERMANENTEMPLOYEE_H_

#include "Employee.h"

class PermanentEmployee: public Employee {
	int hourlyIncome;
public:
	PermanentEmployee(int hi,string = "Umer", int = 0);
	int calculate_the_income();
};

PermanentEmployee::PermanentEmployee(int hi,string n,int id):hourlyIncome(hi),Employee(n,id){}
int PermanentEmployee::calculate_the_income()
{
	hourlyIncome = 150;
	return(hourlyIncome*240);
}

#endif /* PERMANENTEMPLOYEE_H_ */
