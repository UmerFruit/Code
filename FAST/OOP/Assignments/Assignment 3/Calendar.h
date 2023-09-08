/*
 * Calender.h
 *
 *  Created on: 29-Mar-2023
 *      Author: umerfarooq
 */

#ifndef CALENDAR_H_
#define CALENDAR_H_
#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;
class Calendar
{
private:
    int month, year; // data members

public:
    // Constructor
    Calendar(int = 1, int = 1970);
    // setter
    void setter(int, int);
    // print utility function
    void printCalendar();
    // ostream overload
    friend ostream &operator<<(ostream &os, Date &right);
};

#endif /* CALENDER_H_ */
