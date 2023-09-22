/* 
    Name = Umer farooq
    Student ID= 22I-0518
   	Assignment #3	
*/
#include<iostream>
#include<cstdlib>
#include<time.h>
using namespace std;
int main()
{
	float num;
		srand(time(0));				//seed for the random function
		for(int i=1;i<=5;i++)		//loop runs 5 times
		{
		cout<<"Enter Any number between 1 and 30"<<endl;
		cin>>num;											//input number
		if(num>=1 && num<=30)								//input validation
		{
			cout<<"\033[1;"<<(rand()%8)+30<<"m";			//random color is chosen for the output
			for(int j=1;j<=num;j++)							//loop runs n times to print n asterisks
			{
				cout<<"*";
			}
			cout<<"\033[0m";								//resets output settings to default
			cout<<endl;
		}
		else
		{
			i--;
			cout<<"Enter valid input(1-30)"<<endl;			//input validation and runs the loop again
			continue;							
		}
		}
}
