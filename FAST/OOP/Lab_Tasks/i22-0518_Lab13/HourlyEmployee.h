/*
 * HourlyEmployee.h
 *
 *  Created on: 03-May-2023
 *      Author: umerfarooq
 */

#ifndef HOURLYEMPLOYEE_H_
#define HOURLYEMPLOYEE_H_

#include "Employee.h"

class HourlyEmployee: public Employee {
int hourlyIncome;
public:
	HourlyEmployee(int ,string = "Umer", int = 0);
	int calculate_the_hourly_income(int hours);
};

HourlyEmployee::HourlyEmployee(int hi,string n,int id):hourlyIncome(hi),Employee(n,id) {}
int HourlyEmployee::calculate_the_hourly_income(int hours)
{
	hourlyIncome = 150;
	return (hours*hourlyIncome);
}


#endif /* HOURLYEMPLOYEE_H_ */
