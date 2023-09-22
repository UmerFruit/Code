/*
 * Doctor.h
 *
 *  Created on: 05-May-2023
 *      Author: umerfarooq
 */

#ifndef DOCTOR_H_
#define DOCTOR_H_
#include "Headers.h"
#include "getch.h"
class Doctor
{
	string id;
	string name;
	string username;
	string password;
	string spec;
	int appreqs[10];

public:
	Doctor() {}
	Doctor(string, string, string, string, string);
	friend ostream &operator<<(ostream &out, Doctor &t);
	void login();
	int rtn();
	bool dr_login();
	string &getId() { return id; }
	string &getName() { return name; }
	string &getPassword() { return password; }
	string &getUsername() { return username; }
	string &getSpec();
	int *getAppreqs();
};
#endif /* DOCTOR_H_ */
