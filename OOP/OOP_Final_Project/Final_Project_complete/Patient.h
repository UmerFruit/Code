/*
 * Patient.h
 *
 *  Created on: 05-May-2023
 *      Author: umerfarooq
 */

#ifndef PATIENT_H_
#define PATIENT_H_

#include "Headers.h"
#include "getch.h"
#include "EHR.h"
#include "Doctor.h"
#include "IOT.h"
using namespace std;

class Patient
{
	string id;
	string name;
	string username;
	string password;
	string did;
	EHR E;
	IOT I;
	int accreqs[5];
	Doctor *doc;

public:
	Patient(string i, string n, string u, string p, string di);
	Patient() {}
	void writeEHR();
	void login();
	bool user_login();
	void initEHR();
	int rtn();
	void Ehrmenu();
	void IOTMenu();
	IOT &getIOT() { return I; }
	friend ostream &operator<<(ostream &out, Patient &t);
	string &getdid() { return did; }
	string &getId() { return id; }
	string &getName() { return name; }
	string &getPassword() { return password; }
	string &getUsername() { return username; }

	void setdid(const string &did) { this->did = did; }
	void setDoc(Doctor *d) { doc = d; }
	void setId(const string &id) { this->id = id; }
	void setName(const string &name) { this->name = name; }
	void setPassword(const string &password) { this->password = password; }
	void setUsername(const string &username) { this->username = username; }
	
	EHR &getE();
	void setE();
	Doctor *getDoc();
	
	int* getAccreqs();
};

#endif /* PATIENT_H_ */
