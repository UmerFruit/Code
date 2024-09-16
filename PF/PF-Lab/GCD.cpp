#include<iostream>
using namespace std;
int main()
{
	int gcd,i=1,num1,num2;
	cout<<"Enter first number :"<<endl;
	cin>>num1;
	cout<<"Enter second number :"<<endl;
	cin>>num2;
	
	while(i<=num1 && i<=num2)
	{
		if(num1%i==0)
		{
			if(num2%i==0)
			{
				gcd=i;
			}
		}
		i++;
	}
	cout<<"GCD = "<<gcd<<endl;


}
