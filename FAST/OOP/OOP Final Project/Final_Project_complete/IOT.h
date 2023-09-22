/*
 * IOT.h
 *
 *  Created on: 07-May-2023
 *      Author: umerfarooq
 */

#ifndef IOT_H_
#define IOT_H_
#include "Patient.h"
#include <iomanip>
#include "Records.h"
class IOT : public Records
{
	float BMI;		// 18.5 - 24.9
	int BP[2];		// <120 and <80
	int OS;			// 95%-100%
	int HeartR;		// 60-100/min for resting
	float T;		// Temperature 37.5 ke around
	float RespRate; // Respiratory rate 12-25/min for adults
	int NCR;		// nerve conduction rate 50-60 m/s
public:
	void write(string name);
	void update(string name);
	void read(string name, int ind);
	friend ostream &operator<<(ostream &out, IOT &t);
	void display();
};
#endif /* IOT_H_ */
