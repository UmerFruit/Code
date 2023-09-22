//---------------------Question # 9---------------------//
#include <iostream>
using namespace std;
class ThermalReactor
{
    int valve;
    float temprature;

public:
    ThermalReactor(int v, float t)
    {
        valve = v;
        temprature = t;
    }
    virtual void print()
    {
        cout << "Valve: " << valve;
        cout << " Temparture:" << temprature << endl;
    }
};

class MagnoxReactor : public ThermalReactor
{
    float maxPower;
    float production;

public:
    MagnoxReactor(int v, float t, float m, float p): ThermalReactor(v, t)
    {
        maxPower = m;
        production = p;
    }

    bool isAtCritical()
    {
        return (maxPower == production);
    }

    void signal()
    {
        cout << "Production cannot be increased" << endl;
    }

    void increaseProd(float factor)
    {
        if ((production + factor) < maxPower)
        {
            production += factor;
            print();
        }
        else
            signal();
    }

    void print()
    {
        ThermalReactor::print();
        cout << "Current production: " << production;
        cout << " Max Power: " << maxPower << endl;
    }
};

void Capacity(ThermalReactor *reactor)
{
    reactor->print();
    dynamic_cast<MagnoxReactor *>(reactor)->increaseProd(10);
}

int main()
{
    MagnoxReactor *MagRec = new MagnoxReactor(4, 1000, 330, 200);
    Capacity(MagRec);
    return 0;
}
/*
Valve: 4
Temparture: 1000
Current production: 200
Max Power: 330
210//
Valve: 4
Temparture: 1000
Current production: 210
Max Power: 330
*/