/*
Name: Maleek Hussain Ali
Roll number: 22i-1526
Section: SE(B)
*/

#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int main()
{
    int x,n,max=0, min=0;
    cout << "\nEnter value of x: ";
    cin >> x;
    cout << "\nEnter value of n: ";
    cin >> n;
    for(int i = -x; i <= x; i++)  //The loop calculates maximum and minimum value
    {
        if((pow(i, n)-pow(i, n-1)) > max)
        {
            max = (pow(i, n)-(pow(i, n-1)));
        }
        if((pow(i, n)-pow(i, n-1)) < min)
        {
            min = (pow(i, n)-(pow(i, n-1)));
        }
    }
    for(int j=max; j>=min; j--)     //the loop plots the graph, scale of y axis is made using max and min
    {
        cout << setw(4) << j;
        for(int i = -(x); i <= x; i++)
        {
            if(j == (pow(i, n)-(pow(i, n-1))))
            {
                cout << setw(4) << '.';
            }
            else
            {
                cout << setw(4) << " ";
            }
        }
        cout << endl;
    }
    cout << endl << setw(4) << " ";    // scale of x axis
    for(int i = -(x); i <= x; i++)
    {
        cout << setw(4) << i;
    }
    cout<<endl;
}