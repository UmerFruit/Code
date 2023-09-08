/*
 *  Name : Umer Farooq
 *  Student ID : 22I-0518
 *  Assignment# 2
 */

#include <iostream>
using namespace std;
class FlightInfo
{
private:
    int FlightNumber;
    char *Destination;
    float Distance;
    float Fuel;

public:
    FlightInfo();
    float getFuel();
    void showInfo();
    void calFuel(float);
    void feedInfo();
    ~FlightInfo();
};
FlightInfo::FlightInfo()
{
    Destination = new char[25]; // default constructor
    feedInfo();
}
float FlightInfo::getFuel()
{
    return Fuel; // getter function
}
void FlightInfo::showInfo()
{
    cout << "Flight Number : " << FlightNumber << endl;
    cout << "Destination : " << Destination << endl; // printing utility funtion
    cout << "Distance : " << Distance << endl;
    cout << "Fuel : " << Fuel << endl;
}
void FlightInfo::calFuel(float d)
{
    if (d <= 1000)
        Fuel = 500;
    else if (d > 1000 && d <= 2000) // calculate fuel as per requirements
        Fuel = 1100;
    else if (d > 2000)
        Fuel = 2200;
}
FlightInfo::~FlightInfo()
{
    delete Destination;
}
void FlightInfo::feedInfo()
{
    cout << "Enter Flight Number : " << endl;
    cin >> FlightNumber;

    cout << "Enter Distance : " << endl;
    cin >> Distance; // user input

    cout << "Enter Destination : " << endl;
    cin.ignore();
    cin.getline(Destination, 25);

    calFuel(Distance);
}

int main()
{
    // FlightInfo f1;
    // f1.showInfo();
    // FlightInfo f2;
    // f2.showInfo();
}