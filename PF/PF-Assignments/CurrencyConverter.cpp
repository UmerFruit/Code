§/* 
    Name = Umer farooq
    Student ID= 22I-0518
   	Assignment #4	
*/
#include<iostream>
using namespace std;
bool exchange(int);
int main()
{   int n,a,b,c;
    for(int i=0;i<=20;i++)
    {
    cout<<"Enter PKR input : ";                 
    cin>>n;                         //input number to check
    cout<<endl;
    if(n>0)
    {
        bool check = exchange(n);       //possible or not to convert
        if(check == 1)                   
        {
            cout<<"Possible"<<endl;
        }
        else
        {
            cout<<"Not Possible"<<endl;
        }
    }
    else
    {
        while(n<0)
        {
            cout<<"Enter valid positive number : "<<endl;
            cin>>n;
        }
        bool check = exchange(n);       //possible or not to convert
        if(check == 1)                   
        {
            cout<<"Possible"<<endl;
        }
        else
        {
            cout<<"Not Possible"<<endl;
        }
    }}
}
bool exchange(int num)
{
    int temp;
    if((num % 20 == 0) || (num % 9 == 0) || (num % 6 == 0))    
    {
        return 1;                       //if num is divisible by any of these conversion is possible
    }
    else
    {   
        temp = num-6;
        if(temp>6)              //if num - 6 is divisible by any of these conversion is possible
        {
            if((temp % 20 == 0) || (temp % 9 == 0) || (temp % 6 == 0))
            {
                return 1;
            }
        }
        temp= num-9;
        if(temp>6)           //if num - 9 is divisible by any of these conversion is possible
        {
            if((temp % 20 == 0) || (temp % 9 == 0) || (temp % 6 == 0))
            {
                return 1;
            }
        }
        temp = num -20;
        if(temp>6)        //if num - 20 is divisible by any of these conversion is possible
        {
            if((temp % 20 == 0) || (temp % 9 == 0) || (temp % 6 == 0))
            {
                return 1;
            }
        }
        else            //if none of these are possible then conversion is impossible
        {
            return 0;
        }
    }
}