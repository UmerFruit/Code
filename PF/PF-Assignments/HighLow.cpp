/* 
    Name = Umer farooq
    Student ID= 22I-0518
   	Assignment #4	
*/
#include<iostream>
using namespace std;
bool highLow(long);
int main()
{
    long num;
    cout<<"Enter number for alternating digits : ";     //input
    cin>>num;
    if(num>0)                           //input validation
    {
        if(highLow(num))                      //if function returns true digits are alternating
        {
            cout<<num<<" is alternating."<<endl;
        }
        else                                   //else
        {
            cout<<num<<" is not alternating."<<endl;
        }
    }
    else                            
    {
        while(num<0)
        {
            cout<<"Enter Positive number\nEnter Again"<<endl;
            cin>>num;
        }
        if(highLow(num))                      //if function returns true digits are alternating
        {
            cout<<num<<" is alternating."<<endl;
        }
        else                                   //else
        {
            cout<<num<<" is not alternating."<<endl;
        }
    }
    
}
bool highLow(long num)
{ 
    long temp=num,numdig,dig;
    bool lastdig,d2,check;
    for(numdig=0;temp>0;numdig++)     //check the number of digits
    {
        temp=temp/10;
    }
    if(numdig == 1)             //if the number of digits is one then always return true
    {
        return true;
    }
    temp=num;
    dig= temp%10;
    lastdig=(dig>=5 && dig<=9);         //check the last digit and use it as a reference point
    temp /= 10;
    
        for(int i=1;i<numdig;i++)       
        {       
            dig = temp%10;
            d2=(dig>=5 && dig<=9);      //check the second digit
            if(d2)                      //if it is high
            {
                if(lastdig)                  //check if last digit was high as well
                {
                    return false;           //two highs in a row
                }
                lastdig= !lastdig;          //if not, set the new last digit to high 
            }
            else                        //if it is low
            {
                if(!lastdig)            //check if last digit was low as well
                {
                    return false;       //two lows in a row
                }
                lastdig=!lastdig;       //if not, set the new last digit to low
            }
            temp /= 10;                 //divide by 10 to get rid of the last digit each iteration
        }
        return true;              //if loop is exited without returning false,the digits must be alternating
}                       
    
