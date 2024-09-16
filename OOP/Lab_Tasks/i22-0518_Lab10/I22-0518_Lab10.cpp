#include "Money.cpp"
#include <iostream>
using namespace std;

int main()
{
    Money m1(5,3),m2(2,5);
    Money m3;
    m3 = m1++;
    cout<<m3;
    cout<<m1;
    cin>>m3;
    cout<<m3;
}