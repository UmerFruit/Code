/*
 * Date.h
 *
 *  Created on: 29-Mar-2023
 *      Author: umerfarooq
 */

#ifndef DATE_H_
#define DATE_H_
#include <iostream>
using namespace std;
class Date
{

private:
    int year;
    int month;
    int day;

public:
    // Constructors
    Date();
    Date(int days);
    Date(int year, int month, int day);

    // Getters
    int getYear() const;
    int getMonth() const;
    int getDay() const;

    // Date difference functions
    void operator-(Date &d);
    Date &operator+(int);
    Date &operator-(int days);
    int diffInDays(const Date &d) const;
    // utility functions
    bool isleap(int year) const;
    bool isleap() const;
    int daysInMonth(int i, int) const;
    void display();
    friend ostream &operator<<(ostream &os, Date &right);
};
#endif /* DATE_H_ */
