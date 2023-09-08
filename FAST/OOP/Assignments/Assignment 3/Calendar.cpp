/*
 * Calender.cpp
 *
 *  Created on: 29-Mar-2023
 *      Author: umerfarooq
 */

#include "Calendar.h"
#include "Date.h"
Calendar::Calendar(int m, int y) : month(m), year(y) {} // default constructor
void Calendar::setter(int m, int y)
{
    month = m;
    year = y;
}
void Calendar::printCalendar()
{
    string months[] = {" ", "January", "February", "March", "April", "May", "June"
                                                                            "July",
                       "August", "September", "October", "November", "December"}; // stores names of months for printing

    // returns which day of week a date will lie on using zeller's rule
    int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    int y = year;
    y -= month < 3;
    int dayOfWeek = (y + y / 4 - y / 100 + y / 400 + t[month - 1] + 1) % 7;

    int daysOFmonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
        daysOFmonth[2] = 29; // check for leap year
    int numdays = daysOFmonth[month];
    cout << endl;
    cout << setw(20) << "Year - " << year;
    int days;

    // Index of the day from 0 to 6
    int current = dayOfWeek;

    days = numdays;

    // Print the current month name
    cout << endl
         << "  ------------" << months[month] << "-------------" << endl;

    // Print the columns
    cout << "  Sun  Mon  Tue  Wed  Thu  Fri  Sat" << endl;

    // Print appropriate spaces
    int k;
    for (k = 0; k < current; k++)
        cout << setw(5) << " ";

    for (int j = 1; j <= days; j++)
    {
        cout << setw(5) << j;
        k++;
        if (k >= 7)
        {
            k = 0;
            cout << endl;
        }
    }
    cout << endl;
}
ostream &operator<<(ostream &os, Calendar &right)
{
    right.printCalendar(); // display using ostream object
    return os;             // operator overloading for cout
}
void cal_for_diff_month(Calendar c)
{
    int month, year;
    cout << "Enter month\n";
    cin >> month;
    while (month < 1 || month > 12)
    {
        cout << "Enter valid month" << endl;
        cin >> month;
    }
    cout << "Enter Year\n"; // input validation
    cin >> year;
    while (year < 0)
    {
        cout << "Enter valid year" << endl;
        cin >> year;
    }
    c.setter(month, year); // set the values for printing the calendar
    cout << c;
}
void dates_diff()
{
    int d1, d2, m1, m2, y1, y2;
    cout << "Enter first date in DD MM YYYY Format(seperated by spaces)\n";
    cin >> d1 >> m1 >> y1; // input 1
    Date date1(d1, m1, y1);
    cout << "Enter Second date in DD MM YYYY Format(seperated by spaces)\n";
    cin >> d2 >> m2 >> y2; // input 2
    Date date2(d2, m2, y2);
    date1 - date2; //- operator overload for Date class
}
void future_date()
{
    int d, m, y;
    cout << "Enter start date in DD MM YYYY Format(seperated by spaces)\n";
    cin >> d >> m >> y; // input for start date
    Date date(d, m, y);
    cout << "Enter months,weeks or days to add" << endl;
    char val[40], temp[40];

    cin.ignore();
    cin.getline(val, 40);
    int i;
    for (i = 0; val[i] != '\0'; i++)
    {
        temp[i] = val[i]; // make copy of string so strtok's changes don't effect the original
    }
    temp[i] = '\0';
    char *n = strtok(temp, " ");
    int num = stoi(n); // converts string to int
    while (num < 0)
    {
        cout << "Enter Valid Number" << endl; // input validation in string
        cin >> num;
    }
    n = strtok(nullptr, "\0");

    if (!strcmp(n, "weeks"))
    {
        Date Date = (date + (num * 7));
        cout << val << " from the start date "; // check unit of conversion
        cout << date;
        cout << " is ";
        cout << Date;
    }
    else if (!strcmp(n, "days"))
    {
        Date Date = (date + num);
        cout << val << " from the start date "; // and convert accordingly
        cout << date;
        cout << " is ";
        cout << Date;
    }
    else if (!strcmp(n, "months"))
    {
        Date Date = (date + (num * 30.4167));
        cout << val << " from the start date "; // and display the result
        cout << date;
        cout << " is ";
        cout << Date;
    }
    else
    {
        cout << "Invalid input, Enter valid unit for conversion" << endl;
    }
}
void past_date()
{
    int d, m, y;
    cout << "Enter start date in DD MM YYYY Format(seperated by spaces)\n";
    cin >> d >> m >> y;
    Date date(d, m, y);
    cout << "Enter months, weeks or days to Subtract" << endl;
    char val[40], temp[40];

    cin.ignore();
    cin.getline(val, 40);
    int i;
    for (i = 0; val[i] != '\0'; i++)
    {
        temp[i] = val[i];
    }
    temp[i] = '\0'; // make copy of string so strtok's changes don't effect the original
    char *n = strtok(temp, " ");
    int num = stoi(n); // converts string to int
    while (num < 0)
    {
        cout << "Enter Valid Number" << endl; // input validation in string
        cin >> num;
    }
    n = strtok(nullptr, "\0");
    if (!strcmp(n, "weeks"))
    {
        Date Date = (date - (num * 7));
        cout << val << " back from the start date "; // check unit of conversion
        cout << date;
        cout << " is ";
        cout << Date;
    }
    else if (!strcmp(n, "days"))
    {
        Date Date = (date - num);
        cout << val << " back from the start date "; // and convert accordingly
        cout << date;
        cout << " is ";
        cout << Date;
    }
    else if (!strcmp(n, "months"))
    {
        Date Date = (date - (num * 30.4167));
        cout << val << " back from the start date "; // and display the result
        cout << date;
        cout << " is ";
        cout << Date;
    }
    else
    {
        cout << "Invalid input,Enter valid unit for conversion" << endl;
    }
}
