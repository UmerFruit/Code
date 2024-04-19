/*
 * Laptop.h
 *
 *  Created on: 03-May-2023
 *      Author: umerfarooq
 */

#ifndef LAPTOP_H_
#define LAPTOP_H_

#include "Computer.h"

class Laptop: public Computer {
string color,processor;
int size;
int weight;
public:
	Laptop(string c= "red",string pr= "i7",int s= 15,string cn = "IBM",int p = 100000,int w = 2);
	void show();
};
Laptop::Laptop(string c,string pr,int s,string cn,int p ,int w):Computer(cn,p)
{
	color = c;
	processor = pr;
	size = s;
	weight = w;
}
void Laptop::show()
{
	Computer::show();
	cout<<"Color : "<<color<<endl;
	cout<<"Processor : "<<processor<<endl;
	cout<<"Monitor Size : "<<size<<endl;
	cout<<"Wieght : "<<weight<<endl;
}
#endif /* LAPTOP_H_ */
