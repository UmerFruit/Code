#include <iostream>
#include <cstring>
using namespace std;
class Employee
{
private:
    int ID;
    string name;
    string NIC;
    int salary;
    int bonus;

public:
    Employee()
    {
        ID = 0;
        name = "Umer Farooq";
        NIC = "123456789";
        salary = 25000;
        bonus = 0;
    }
    Employee(int ID, string name, string NIC, int salary, int bonus)
    {
        this->ID = ID;
        this->name = name;
        this->NIC = NIC;
        this->salary = salary;
        this->bonus = bonus;
    }
    int getid()
    {
        return ID;
    }
    friend ostream &operator<<(ostream &out, Employee &lol);
};
ostream &operator<<(ostream &out, Employee &lol)
{
    cout << "ID = " << lol.ID << endl;
    cout << "Name = " << lol.name << endl;
    cout << "NIC = " << lol.NIC << endl;
    cout << "Salary = " << lol.salary << endl;
    cout << "Bonus = " << lol.bonus << endl
         << endl;
    return out;
}
