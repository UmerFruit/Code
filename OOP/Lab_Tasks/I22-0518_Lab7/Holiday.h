/*
 * Holiday.h
 *
 *  Created on: Mar 8, 2023
 *      Author: umer
 */

#ifndef HOLIDAY_H_
#define HOLIDAY_H_
#include <iostream>
#include <string>
using namespace std;
class Holiday
{
private:

	string name;
	int day;
	string month;

public:
	Holiday();
	Holiday(string &n, int d, string &m);
	Holiday(Holiday & copy);
	int getDay() ;
	void setDay(int day);
	string& getMonth() ;
	void setMonth(string &month);
	string& getName() ;
	void setName(string &name);
	bool inSameMonth (Holiday &a, Holiday &b);
	double avgDate(Holiday arr[], int size);
};

double Holiday::avgDate(Holiday arr[], int size)
{
	int sum=0;
	for(int i=0;i<size;i++)
	{
		sum += arr[i].day;
	}
	double avg= static_cast<double>(sum)/size;
	return avg;
}

bool Holiday::inSameMonth (Holiday &a, Holiday &b)
{
	if(a.month == b.month)
		return true;
	else
		return false;
}

Holiday::Holiday()
{
	this-> day = 0;
	this-> month = "";
	this-> name = "";
}
Holiday::Holiday(string &n, int d, string &m):name(n),day(d),month(m)
{

}

int Holiday::getDay() {
	return day;
}

void Holiday::setDay(int day) {
	if(day<0 || day>31)
	{
		cout<<"error. enter day in range"<<endl;
	}
	else
	{
		this->day = day;
	}
}

string& Holiday::getMonth() {

	return month;
}

void Holiday::setMonth(string &month) {

	int i=0;
	while(name[i] != '\0')
	{
		i++;
	}
	if(i>10)
	{
		cout<<"name too long. try again"<<endl;
	}
	this->month = month;
}

string& Holiday::getName() {
	return name;
}

void Holiday::setName(string &name) {
	int i=0;
	while(name[i] != '\0')
	{
		i++;
	}
	if(i>50)
	{
		cout<<"name too long. try again"<<endl;
	}
	else
	{
		this->name = name;
	}
}

Holiday::Holiday(Holiday & copy)
{
	name = copy.name;
	day = copy.day;
	month = copy.month;
}

#endif /* HOLIDAY_H_ */
