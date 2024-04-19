/*
 *  Name : Umer Farooq
 *  Student ID : 22I-0518
 *  Assignment# 2
 */

#include <iostream>
using namespace std;
class Employee
{
private:
    char *name; // name and salary
    double salary;

public:
    Employee();
    char *getName(); // getters
    double getSalary();
    ~Employee();
};
Employee::~Employee()
{
    delete[] name;
    name = 0;
}
Employee::Employee()
{
    name = new char[25];
    cout << "Creating a new employee." << endl;
    cout << "Please specify the salary:" << endl;
    cin >> salary;
    while (salary < 0)
    {
        cout << "Enter non negative value" << endl; // input validation
        cin >> salary;
    }
    cin.ignore();
    cout << "Please type the name: " << endl;
    cin.getline(name, 25); // length of name cannot exceed 25 char
    cout << "New employee has been created." << endl;
}

char *Employee::getName()
{
    return name;
}
double Employee::getSalary()
{
    return salary;
}
int main()
{
    Employee E1;
    cout << "Name : " << E1.getName() << endl;
    cout << "Salary : " << E1.getSalary() << endl; // printing
    cout << "Thank you for testing Class Employee." << endl;
    Employee E2;
    cout << "Name : " << E2.getName() << endl;
    cout << "Salary : " << E2.getSalary() << endl; // printing
    cout << "Thank you for testing Class Employee." << endl;
}