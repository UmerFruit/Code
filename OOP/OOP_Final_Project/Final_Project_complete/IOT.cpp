/*
 * IOT.cpp
 *
 *  Created on: 10-May-2023
 *      Author: umerfarooq
 */
#include "IOT.h"
#include "RMC2.cpp"
ostream &operator<<(ostream &out, IOT &t)
{
    out << setw(40) << setfill('-') << "" << endl;
    out << "The data for Day " << t.index + 1 << " is as follows :  " << endl;
    out << setw(40) << setfill('-') << "" << endl;
    out << "BMI = " << t.BMI << endl;
    out << "BP = " << t.BP[0] << " - " << t.BP[1] << endl;
    out << "OS = " << t.OS << "%" << endl;
    out << "HeartR = " << t.HeartR << " BPM" << endl;
    out << "T = " << t.T << " ˚C" << endl;
    out << "RespRate = " << t.RespRate << "/MIN" << endl;
    out << "NCR = " << t.NCR << " m/s" << endl;
    out << setw(40) << setfill('-') << "" << endl;
    return out;
}
void IOT::display()
{
    cout << setw(40) << setfill('-') << "" << endl;
    cout << "The data for Day " << index + 1 << " is as follows :  " << endl;
    cout << setw(40) << setfill('-') << "" << endl;
    cout << "BMI = " <<BMI << endl;
    cout << "BP = " << BP[0] << " - " << BP[1] << endl;
    cout << "OS = " << OS << "%" << endl;
    cout << "HeartR = " << HeartR << " BPM" << endl;
    cout << "T = " << T << " ˚C" << endl;
    cout << "RespRate = " << RespRate << "/MIN" << endl;
    cout << "NCR = " << NCR << " m/s" << endl;
    cout << setw(40) << setfill('-') << "" << endl;
   
}
void IOT::write(string name)
{
    srand(time(0));
    string path = "Cloud/IOT/";
    ofstream out(path + name + "_IOT.dat", ios::binary);
    for (int i = 0; i < 90; i++)
    {
        index = i;
        BMI = (rand() % 6 + 18) + ((rand() % 10)) / 10.0;
        BP[0] = rand() % 20 + 100;
        BP[1] = rand() % 20 + 60;
        OS = rand() % 10 + 90;
        HeartR = rand() % 40 + 60;
        T = (rand() % 2 + 37) - ((rand() % 10)) / 10.0;
        RespRate = rand() % 13 + 12;
        NCR = rand() % 10 + 50;
        out.write(reinterpret_cast<char *>(this), sizeof(IOT));
    }
    out.close();
}
void IOT::update(string name)
{
    string path = "Cloud/IOT/";
    static int i = 1;
    srand(time(0));
    ofstream out(path + name + "_IOT.dat", ios::binary | ios::app);
    index = 90 + i++;
    BMI = (rand() % 6 + 18) + ((rand() % 10)) / 10.0;
    BP[0] = rand() % 20 + 100;
    BP[1] = rand() % 20 + 60;
    OS = rand() % 10 + 90;
    HeartR = rand() % 40 + 60;
    T = (rand() % 2 + 37) - ((rand() % 10)) / 10.0;
    RespRate = rand() % 13 + 12;
    NCR = rand() % 10 + 50;
    out.write(reinterpret_cast<char *>(this), sizeof(IOT));

    out.close();
}

void IOT::read(string name, int ind)
{
    string path = "Cloud/IOT/";
    ifstream in(path + name + "_IOT.dat", ios::binary);
    for (int i = 0; i < 90; i++)
    {
        in.read(reinterpret_cast<char *>(this), sizeof(IOT));

        if (this->index == ind)
        {
            break;
        }
    }
    in.close();
}