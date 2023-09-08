/*
 *  Name : Umer Farooq
 *  Student ID : 22I-0518
 *  Assignment# 2
 */

#include <iostream>
using namespace std;
class Employee2
{
private:
    char *name;
    float hourlyWage;
    float workedHours; // data members
    float extraHours;

public:
    Employee2();
    char *getname(); // member functions
    float gethours();
    float getwage();
    float wageCalculator();
    float getExtra();
    static int count;
};
int Employee2::count = 0;
Employee2::Employee2()
{
    name = new char[25];

    cout << "Please enter employee's name then press Enter : " << endl;
    if (count != 0)
        cin.ignore();

    cin.getline(name, 25);
    cout << "Please enter hourly wage then press Enter : " << endl;
    cin >> hourlyWage; // input
    cout << "Please enter hours worked then press Enter : " << endl;
    cin >> workedHours;
    extraHours = workedHours - 40;
    if (extraHours <= 0)
        extraHours = 0;
    count++;
}

float Employee2::wageCalculator()
{
    float total;
    float overtime = hourlyWage * 1.5;
    if (extraHours == 0)
        total = workedHours * hourlyWage; // calulate utility funtion
    else
        total = 40 * hourlyWage;
    total += (extraHours * overtime);
    return total;
}
float Employee2::getExtra()
{
    return extraHours; // getters
}
float Employee2::gethours()
{
    return workedHours;
}
float Employee2::getwage()
{
    return hourlyWage;
}
char *Employee2::getname()
{
    return name; // geters
}
void printpaycheck(Employee2 E)
{
    cout << "Paycheck for employee " << E.getname() << endl
         << endl;
    cout << "Hours worked : " << E.gethours() << endl;
    cout << "Hourly wage : " << E.getwage() << endl
         << endl;
    if (E.getExtra() > 0)
    {
        cout << "Overtime hours : " << E.getExtra() << endl; // printing function
        cout << "Overtime hourly wage : " << (E.getwage() * 1.5) << endl
             << endl;
    }
    cout << "Total payment : " << E.wageCalculator() << endl;
}
int main()
{
    Employee2 E1;
    printpaycheck(E1);
    Employee2 E2;
    printpaycheck(E2);
}