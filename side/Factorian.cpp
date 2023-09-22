/*
	16-December-2022
	Made By Umer Farooq
	Factorian is a number that is equal to the sum of the factorial of its digits
	Example: 145 = 1! + 4! + 5!
*/
#include <iostream>

using namespace std;

int sumstore(int num);
int factorial (int num);
int numdig(int num);

int main()
{
    int num;
    long long m=1000000;
    for(num=1;num<=m;num++)
    {
        int sum= sumstore(num);
        if(sum== num)
        {
            cout<<num<<endl;
        }
    }
    return 0;
}
int factorial (int num)
{
    int fac=1;
    for(int i=1;i<=num;i++)
    {
        fac *= i;
    }
    return fac;
}
int numdig(int num)
{
    int numdig=0;
    while(num)
    {
        num /= 10;
        numdig++;
    }
    return numdig;
}
int sumstore(int num)
{
    int numdigits= numdig(num);
    int digits[numdigits],sum=0;
    for(int i=0;i<numdigits;i++)
    {
        digits[i]=num%10;
        num /= 10;
        sum += factorial(digits[i]);
    }
    return sum;
}