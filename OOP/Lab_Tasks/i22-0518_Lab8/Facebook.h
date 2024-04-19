/*
 * Facebook.h
 *
 *  Created on: Mar 15, 2023
 *      Author: umer
 */

#ifndef FACEBOOK_H_
#define FACEBOOK_H_
#include <string>
using namespace std;
class Facebook
{
private:
	string name;
	string email;
	char gender;
	char* contact;
public:
	~Facebook();
	Facebook();
	Facebook(string , string , char , char[]);
	void updatecontact(int , char);
	char* getContact();
	void setContact(char *contact);
	const string getEmail();
	void setEmail(const string &email);
	char getGender();
	void setGender(char gender);
	string getName();
	void setName(const string &name);
};
Facebook::~Facebook()
{
	delete [] contact;
}
Facebook::Facebook()
{
	email = "BearVsNinja@gmail.com";
	name = "iphone 8";
	gender = 'F';
	contact = new char [12];
	contact = "05384793";

}
Facebook::Facebook(string n, string em, char g, char con[] )
{
	contact = new char [12];
	name = n;
	email = em;
	gender = g;
	contact = con;
}
void Facebook::updatecontact(int a, char v)
{
	contact[a] = v;
}
char* Facebook::getContact() {
	return contact;
}

void Facebook::setContact(char *contact) {
	this->contact = contact;
}

const string Facebook::getEmail() {
	return email;
}

void Facebook::setEmail(const string &email) {
	this->email = email;
}

char Facebook::getGender() {
	return gender;
}

void Facebook::setGender(char gender) {
	this->gender = gender;
}

string Facebook::getName() {
	return name;
}

void Facebook::setName(const string &name) {
	this->name = name;
}

#endif /* FACEBOOK_H_ */
