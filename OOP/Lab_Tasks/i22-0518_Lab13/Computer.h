/*
 * Computer.h
 *
 *  Created on: 03-May-2023
 *      Author: umerfarooq
 */

#ifndef COMPUTER_H_
#define COMPUTER_H_
#include <iostream>
#include <cstring>
using namespace std;
class Computer {
protected:
string companyname;
int price;
public:
	Computer(string = "IBM",int = 1000000);
	void show();
};
Computer::Computer(string cn,int p)
{
	companyname = cn;
	price = p;
}
void Computer::show()
{
	cout<<"Company Name: "<<companyname<<endl;
	cout<<"Price: "<<price<<endl;
}
#endif /* COMPUTER_H_ */
