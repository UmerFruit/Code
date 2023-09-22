/*
 * Desktop.h
 *
 *  Created on: 03-May-2023
 *      Author: umerfarooq
 */

#ifndef DESKTOP_H_
#define DESKTOP_H_

#include "Computer.h"

class Desktop: public Computer {
string color,processor;
int monitorsize;
public:
	Desktop(string = "red",string = "i7",int = 15,string cn = "IBM",int p = 100000);
	void show();

};
Desktop::Desktop(string c,string pr,int ms,string cn,int p):Computer(cn,p){

	color = c;
	processor = pr;
	monitorsize = ms;
}
void Desktop::show()
{
	Computer::show();
	cout<<"Color : "<<color<<endl;
	cout<<"Processor : "<<processor<<endl;
	cout<<"Monitor Size : "<<monitorsize<<endl;
}
#endif /* DESKTOP_H_ */
