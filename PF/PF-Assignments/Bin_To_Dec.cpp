/* 
    Name = Umer farooq
    Student ID= 22I-0518
   	Assignment #4
*/
#include<iostream>
#include <cmath>
using namespace std;

int bin_convert(unsigned long long num);
int main()
{   
    unsigned long long num, binary=0;
   
    cout<<"Enter your number in binary : ";
    cin>>num;                           //input
    
    binary = bin_convert(num);          //storing the return value
    
    int count=0;
    while(binary==-100)                 //if user enters negative or non 1 or 0 digit error code -100
    {
        
        cout<<"Enter again."<<endl;
        cin>>num;                       //ask to re-enter till valid value is given
        
        
        binary = bin_convert(num);      //call the function again to check if value is valid
        count++;
        if(count==25)
        {   
            cout<<"\nOverflow error"<<endl;
            return 0;
        }
       
    }

    cout<<binary<<" in the decimal system."<<endl;      //prints the decimal value returned by the function

    
    

}
int bin_convert(unsigned long long num) 
{   int i,k,j;                              //counters
    unsigned int numdig,dig,bin=0;          
    unsigned long long temp,reverse;
    
    cout<<endl;
    temp=num;
    numdig=0;
    while(temp>0)                           //calculating the number of digits in the number
    {   
        temp=temp/10;
        numdig++;
    }
    
    temp=num;
    cout<<"The binary number ";            //start the sentence to print the digits of the binary next
    i=0;    
    while(i<numdig)
    {   
        dig=temp%10;
        if(dig==0 || dig == 1)          //check if digit is 1 or 0 only
        {
            
            bin = bin + dig * pow(2,i);     //calculate the decimal value by multiplying with powers of 2
        
        }
        else                                //if any digit is not 0 or 1 then ask to reenter value
        {
            cout<<"\rNumber must only consist of 1 and 0 and must be positive"<<endl;
            return -100;                        

        }
        temp=temp/10;
        i++;
    }
    temp=num;

    reverse=0;
    k=1;
    while(k<=numdig)          //the number gets reversed while printing the digits so print the reverse
    {
        int r=temp%10;
        reverse=reverse*10 + r; //so the original number is displayed instead of its reverse
        temp=temp/10;
        k++;
    }
    j=1;
    while(j<=numdig)            //after re- reversing the number we print it digit by digit
    {
        dig=reverse%10;
        reverse=reverse/10;
        cout<<dig<<" ";
        j++;
    }
    cout<<"is written as ";         //then next portion of the sentence which prints the decimal value
    return bin;
}