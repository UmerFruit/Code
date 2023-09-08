/*
 * App.h
 *
 *  Created on: 14-May-2023
 *      Author: umerfarooq
 */

#ifndef APP_H_
#define APP_H_

class App
{
protected:
	Doctor *Dlist;
	Patient *Plist;

public:
	virtual void viewDlist()
	{
		cout << "viewDlist of parent class" << endl;
	}
	virtual void viewPlist()
	{
		cout << "viewPlist of parent class" << endl;
	}
};

#endif /* APP_H_ */
