/*
 *  Name : Umer Farooq
 *  Student ID : 22I-0518
 *  Assignment# 2
 */

#include <iostream>
using namespace std;
class Address
{
private:
    int houseN;
    int street;
    int apartmentNumber;
    char *city;
    char *state;
    int postalCode;

public:
    Address();
    Address(int, int, int, char *, char *, int);
    Address(int, int, char *, char *, int);
    bool compareTo(Address);
    void print();
    int getpostal();
};
int Address::getpostal()
{
    return postalCode; // getter
}
bool Address::compareTo(Address A)
{
    if (postalCode > A.getpostal()) // returns bool acc to comparison by int
        return true;
    else
        return false;
}
void Address::print()
{
    cout << "Street : " << street << endl;
    cout << "City : " << city << "\tState : " << state << "\tPostal Code : " << postalCode << endl; // print
}
Address::Address()
{
    city = new char[15];
    state = new char[15];
    char c;
    cout << "Enter house number,street number,city,state,postal code" << endl;
    cin >> houseN >> street;
    cin.ignore();
    cin.getline(city, 15);
    cin.getline(state, 15); // constructor with user input
    cin >> postalCode;
    cout << "Do you have an apartment number (y/n)?" << endl;
    cin >> c;
    if (c == 'y')
    {
        cout << "Enter apartment number" << endl;
        cin >> apartmentNumber;
    }
}
Address::Address(int h, int s, int an, char *c, char *st, int pc) : houseN(h), street(s), apartmentNumber(an), city(c), state(st), postalCode(pc)
{
    // parameterized construtor with apartment number
}
Address::Address(int h, int s, char *c, char *st, int pc) : houseN(h), street(s), city(c), state(st), postalCode(pc)
{
    // parameterized construtor without apartment number
}

int main()
{
    // char* l = new char [10];
    // char* g= new char [10];
    // cout<<"enter 1st str: ";
    // cin>>l;
    // cout<<"enter 2nd str: ";
    // cin>>g;
    // Address a3;
    // Address a1(5,10,6,l,g,10005);
    // Address a2(6,12,l,g,10001);
    // cout<<a1.compareTo(a2)<<endl;
    // a1.print();
    // a2.print();
    // cout<<"lol = "<<a3.compareTo(a1)<<endl<<endl;
    // a3.print();
}