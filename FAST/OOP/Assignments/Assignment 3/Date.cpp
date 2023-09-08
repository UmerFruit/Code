/*
 * Date.cpp
 *
 *  Created on: 29-Mar-2023
 *      Author: umerfarooq
 */

#include "Date.h"

Date::Date() : day(1), month(1), year(1970) {}
Date::Date(int day, int month, int year)
{
	while (year < 0)
	{
		cout << "Invalid year.Enter again.";
		cin >> year;
	}
	this->year = year;
	while (month > 12 || month < 0)
	{
		cout << "Invalid months.Enter again.";
		cin >> month;
	}
	this->month = month;
	while (day > daysInMonth(month, year) || day < 0)
	{
		cout << "Invalid days. Enter again" << endl;
		cin >> day;
	}
	this->day = day;
}
void Date::display()
{
	string months[] = {" ", "January", "February", "March",
					   "April", "May", "June",
					   "July", "August", "September",
					   "October", "November", "December"}; // stores names of months for printing
	// returns which day of week a date will lie on using zeller's rule
	int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
	int year = this->year;
	year -= month < 3;
	int dayOfWeek = (year + year / 4 - year / 100 + year / 400 + t[month - 1] + day) % 7;
	switch (dayOfWeek) // print day of week accordingly
	{
	case 0:
		cout << "Sunday, ";
		break;
	case 1:
		cout << "Monday, ";
		break;
	case 2:
		cout << "Tuesday, ";
		break;
	case 3:
		cout << "Wednesday, ";
		break;
	case 4:
		cout << "Thursday, ";
		break;
	case 5:
		cout << "Friday, ";
		break;
	case 6:
		cout << "Saturday, ";
		break;
	}

	cout << day << " ";

	if (month == 1) // print value of month accordingly
		cout << months[1];
	else if (month == 2)
		cout << months[2];
	else if (month == 3)
		cout << months[3];
	else if (month == 4)
		cout << months[4];
	else if (month == 5)
		cout << months[5];
	else if (month == 6)
		cout << months[6];
	else if (month == 7)
		cout << months[7];
	else if (month == 8)
		cout << months[8];
	else if (month == 9)
		cout << months[9];
	else if (month == 10)
		cout << months[10];
	else if (month == 11)
		cout << months[11];
	else if (month == 12)
		cout << months[12];

	cout << " " << this->year;
}
Date::Date(int days)
{
	int day = 0;
	int month = 0;
	int year = 0;
	if (isleap(year))
	{
		if (month < 3)
			day++;
	}
	for (int i = 0; i < days; i++)
	{
		// decrement the day value
		day++;

		// if the day value becomes zero, move to the previous month
		if (day > daysInMonth(month + 1, year))
		{
			// decrement the month value
			month++;

			// if month becomes zero, move to the previous year
			if (month > 12)
			{
				// decrement the year value and set the month to December
				year++;
				month = 1;
			}

			// set the day value to the last day of the previous month
			day = 1;
		}
	}
	this->year = year;
	this->month = month;
	this->day = day;
}

int Date::getYear() const { return year; }
int Date::getMonth() const { return month; } // getters
int Date::getDay() const { return day; }

void Date::operator-(Date &obj)
{
	int days = diffInDays(obj); // calculate difference in days
	Date sub = days;
	int months = sub.year * 12 + sub.month; // and print the difference

	int weeks = days / 7;
	cout << months << " months, " << sub.day << " days, "
		 << "OR " << weeks << " weeks, " << days % 7 << " days." << endl;
}
Date &Date::operator+(int days)
{
	int day = this->day;
	int month = this->month;
	int year = this->year;
	if (isleap(year))
	{
		if (month < 3)
			day++;
	}
	for (int i = 0; i < days; i++)
	{
		// decrement the day value
		day++;

		// if the day value becomes zero, move to the previous month
		if (day > daysInMonth(month, year))
		{
			// decrement the month value
			month++;

			// if month becomes zero, move to the previous year
			if (month > 12)
			{
				// decrement the year value and set the month to December
				year++;
				month = 1;
			}

			// set the day value to the last day of the previous month
			day = 1;
		}
	}
	Date *temp = new Date(day, month, year);
	return *temp;
}
Date &Date::operator-(int days)
{
	int day = this->day;
	int month = this->month;
	int year = this->year;
	for (int i = 0; i < days; i++)
	{
		// decrement the day value
		day--;

		// if the day value becomes zero, move to the previous month
		if (day == 0)
		{
			// decrement the month value
			month--;

			// if month becomes zero, move to the previous year
			if (month == 0)
			{
				// decrement the year value and set the month to December
				year--;
				month = 12;
			}

			// set the day value to the last day of the previous month
			day = daysInMonth(month, year);
		}
	}
	Date *temp = new Date(day, month, year);
	return *temp;
}

int Date::diffInDays(const Date &obj) const
{
	Date obj1 = *this;
	Date obj2 = obj;
	int years, months, days;
	if (obj1.year > obj2.year || (obj1.year == obj2.year && obj1.month > obj2.month) || (obj1.year == obj2.year && obj1.month == obj2.month && obj1.day > obj2.day))
	{
		// swap obj1 and obj2 to ensure obj1 is always the earlier date
		Date temp = obj1;
		obj1 = obj2;
		obj2 = temp;
	}
	// calculate the difference in years
	years = obj2.year - obj1.year;

	// calculate the difference in months
	if (obj2.month >= obj1.month)
	{
		months = obj2.month - obj1.month;
	}
	else
	{
		years--;
		months = 12 - (obj1.month - obj2.month);
	}

	// calculate the difference in days
	if (obj2.day >= obj1.day)
	{
		days = obj2.day - obj1.day;
	}
	else
	{
		months--;
		days = daysInMonth(obj2.month, obj2.year) - obj1.day + obj2.day;
	}

	// calculate total number of days
	int totalDays = years * 365 + (years + 3) / 4 - (years + 99) / 100 + (years + 399) / 400 + months * 30 + (months + 1) / 2 + days;

	return totalDays;
}
bool Date::isleap() const
{
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		return true;
	else
		return false;
}
bool Date::isleap(int year) const
{
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		return true;
	else
		return false;
}
int Date::daysInMonth(int i, int year) const
{
	int daysOFmonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (isleap(year))
		daysOFmonth[2] = 29;

	return daysOFmonth[i];
}
ostream &operator<<(ostream &os, Date &right)
{
	right.display(); // display using ostream object
	return os;		 // operator overloading for cout
}