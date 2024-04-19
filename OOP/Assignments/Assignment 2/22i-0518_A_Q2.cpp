/*
 *  Name : Umer Farooq
 *  Student ID : 22I-0518
 *  Assignment# 2
 */

#include <iostream>
using namespace std;
class Car
{
private:
    float fuel_e; // fuel efficiency
    float fuel_l; // fuel level

public:
    Car(float);
    float getFuelLevel();
    void tank(float);
    void drive(float);
};
Car::Car(float E)
{
    fuel_e = E;
    fuel_l = 0; // fuel level initally at zero
}
float Car::getFuelLevel()
{
    return fuel_l;
}
void Car::tank(float L)
{
    fuel_l = L;
}
void Car::drive(float D)
{
    fuel_l = fuel_l - (D / fuel_e);
}

int main()
{
    Car myBeemer(29);
    cout << myBeemer.getFuelLevel() << endl;
    myBeemer.tank(20);
    cout << myBeemer.getFuelLevel() << endl;
    myBeemer.drive(100);
    cout << myBeemer.getFuelLevel() << endl;
}