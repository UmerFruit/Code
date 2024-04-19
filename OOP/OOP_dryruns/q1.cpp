//---------------------Question # 1---------------------//
#include <iostream>
using namespace std;
class Vehicle
{
public:
    Vehicle()
    {
        cout << "Vehicle() called.\n";
    }
    ~Vehicle()
    {
        cout << "~Vehicle() called.\n";
    }
    virtual void Print()
    {
        cout << "Test\n";
    }
};
class MotorCycle : public Vehicle
{
public:
    MotorCycle()
    {
        cout << "MotorCycle() called.\n";
    }
    ~MotorCycle()
    {
        cout << "~MotorCycle() called.\n";
    }
};
class Car : public Vehicle
{
public:
    Car()
    {
        cout << "Car() called.\n";
    }
    ~Car()
    {
        cout << "~Car() called.\n";
    }
    virtual void Print()
    {
        cout << "Check\n";
    }
};
int main()
{
    Vehicle *vehicles[3];
    vehicles[0] = new MotorCycle;
    vehicles[1] = new Car;
    vehicles[2] = new Vehicle;
    for (int i = 0; i < 3; i++)
        vehicles[i]->Print();
    for (int i = 0; i < 3; i++)
        delete vehicles[i];
}