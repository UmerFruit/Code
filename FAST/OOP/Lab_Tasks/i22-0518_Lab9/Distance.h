/*
 * Distance.h
 *
 *  Created on: Mar 22, 2023
 *      Author: umer
 */

#ifndef DISTANCE_H_
#define DISTANCE_H_
#include <iostream>
using namespace std;
class Distance
{
public:
	float getFeet() const;
	bool setFeet(float feet);
	float getInches() const;
	bool setInches(float inches);
	Distance operator+(const Distance &obj);
	Distance(float = 0, float = 0);
	Distance operator-(const Distance &obj);
	const Distance operator = (const Distance &obj);
	void print();
private:
	float feet;
	float inches;
};
Distance::Distance(float f, float i)
{
	inches = i;
	feet = f;
	while(this->inches >= 12)
	{
		this-> inches = static_cast<int>(inches)%12;
		feet++;
	}
}
float Distance::getFeet() const {
	return feet;
}

bool Distance::setFeet(float feet) {
	if(feet>0)
	{
		this->feet = feet;
		return true;
	}
	else
	{
		return false;
	}
}

float Distance::getInches() const {
	return inches;
}

bool Distance::setInches(float inches) {
	if(inches>0)
	{
		this->inches = inches;

		while(this->inches >= 12)
		{
			this-> inches = static_cast<int>(inches)%12;
			feet++;
		}
		return true;
	}
	else
	{
		return false;
	}
}
Distance Distance::operator+(const Distance &obj)
{
	Distance temp;
	temp.feet = this-> feet + obj.feet;
	temp.inches = this-> inches + obj.inches;
	if(temp.inches>=12)
	{
		temp.inches = static_cast<int>(temp.inches)%12;
		temp.feet++;
	}
	return temp;

}
Distance Distance::operator -(const Distance &obj)
{
	Distance temp;
	temp.feet = this-> feet - obj.feet;
	temp.inches = this-> inches - obj.inches;
	if(temp.inches<0)
	{
		temp.inches = 12 + temp.inches;
		temp.feet--;
	}
	return temp;

}
const Distance Distance::operator = (const Distance &obj)
{
	feet = obj.feet;
	inches = obj.inches;
	return *this;
}
void Distance::print(){
	cout<<feet<<endl;
	cout<<inches<<endl;
}


#endif /* DISTANCE_H_ */
